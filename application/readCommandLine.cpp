
#include <application/readCommandLine.h>

namespace po = boost::program_options;

void readCommandLine(int argc, char *argv[], userOptions& user_options,
		hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters,
		std::vector<forbidden>& forbidden_states) {

	bool isConfigFileAssigned = false;

	po::options_description desc("XSpeed options");
	po::variables_map vm;

	if (argc == 1) { //No argument
		std::cout << "Missing arguments!\n";
		exit(0);
	}

	desc.add_options()
	("help", "produce help message")
	("model", po::value<int>()->default_value(0), "set model for reachability analysis\n"
					"1.  Bouncing Ball: Variables{x,v}\n"
					"2.  Timed Bouncing Ball: Variables{x,v,t}\n"
					"3.  A continuous system of five dimensions: Variables{x1..x5} \n"
					"4.  Navigation (3 X 3) grid: Variables{x1,x2,v1,v2}\n"
					"5.  Navigation (5 X 5) grid: Variables{x1,x2,v1,v2}\n"
					"6.  Oscillator : Variables{x,y}\n")
	("engine,e", po::value<std::string>()->default_value("supp"), "set the running engine (default supp): \n - supp : Reachability Computation using Support Functions Algorithm \n - simu : Trajectory Simulation\n")
	("simu-algo",po::value<int>()->default_value(1), "Set the Simulation algorithm\n"
				"1 -- Sequential Algorithm (Set to default)\n"
				"2 -- A-GJH, Adaptation of Gerard J. Holzmann Algorithm\n")
	("simu-init-points",po::value<int>()->default_value(1), "(default 1) Sets the number of initial points "
                "chosen for sampling the initial states, counted per initial set.") //Todo:: If one, takes the center of the bounding box.")
	("directions", po::value<int>()->default_value(1), "Set the directions for template polyhedra:\n"
					"1. Box template (Set to default)\n"
					"2. Octagonal template \n"
					"n. uniformly oriented n directions \n")
	("time-horizon", po::value<double>(), "Set the local time horizon of flowpipe computation.")
	("time-step", po::value<double>(), "Set the sampling time of flowpipe computation.")
	("algo,a",po::value<int>()->default_value(4), "Set the algorithm\n"
			"1 -- Sequential SF Algorithm\n"
			"2 -- ParSup, Parallel Sampling of Template Directions (Parallellism in PostC) \n"
			"3 -- Time-sliced Parallel Algorithm (Parallellism in PostC)\n"
			"4 -- Sequential FB Interpolation (default) \n"
			"5 -- TP-BFS, Task-parallel Algorithm (Parallel exploration of symbolic states)\n"
			"6 -- Lazy Evaluation Algorithm, PostC in GPU\n"
			"7 -- AsyncBFS, Asynchronous Parallel BFS Algorithm (Parallel exploration of symbolic states)\n"
			"8 -- A-GJH, Adaptation of Gerard J. Holzmann Algorithm (Parallel exploration of symbolic states)\n")

	("time-slice", po::value<int>(), "Set the number of Time Slice or partitions for the Time-sliced Algorithm")
	("depth", po::value<int>(), "Set the depth of HA exploration for Bounded Model Checking")
	("aggregate", po::value<std::string>()->default_value("thull"), "Set-aggregation (default thull): \n - thull : template hull \n - chull : convex hull \n - none : no set aggregation (precise but costly)")

	("forbidden,F", po::value<std::string>(), "forbidden location_ID and forbidden set/region within that location")
	("CE",po::value<std::string>(), "Search for counter-example to forbidden-region together with state-space exploration:\n - (all): search in all flowpipe feasible paths "
			"\n - (first): search for counter-example until the first-one (if any) is found."
			"\n - search only in the path given as a comma separated list of locations: e.g. 1,2,3 \n")
	("include-path,I", po::value<std::string>(), "include file path")
	("model-file,m", po::value<std::string>(), "include model file")
	("config-file,c", po::value<std::string>(), "include configuration file")
	("output-file,o", po::value<std::string>(), "output file name for redirecting the outputs")
	("output-variable,v", po::value<std::string>(), "variables for plotting. E.g., 'x,v' for Bouncing Ball") 
	("output-format", po::value<std::string>()->default_value("GEN"), "The type of output format, either GEN or INTV. GEN prints the vertices of the reach set and INTV prints the global bounds on the output variables (Set to GEN by default)")
;

	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	std::vector<std::string> output_vars(3); //stores the plotting variables

	std::string input;
	for (int i = 1; i < argc; i++) {

		if (std::string(argv[i]).find("-o") != string::npos || std::string(argv[i]).find("--output-file") != string::npos || std::string(argv[i]).find("-m") != string::npos || std::string(argv[i]).find("-c") != string::npos ||
				std::string(argv[i]).find("--model-file") != string::npos || std::string(argv[i]).find("--config-file") != string::npos )
			i++;
		else {
			if (std::string(argv[i]).find("-F") != string::npos){
				input.append(argv[i]);	//-F
				input.append(" ");
				i++; //move next arg ie options for -F
				input.append("\""); //starting quote
				input.append(argv[i]);
				input.append("\" "); //ending quote
			}else{
				input.append(argv[i]);
				input.append(" ");
			}
		}
	}
	//--------
	if (argc > 1) { // Options to be filled-up
		if (vm.count("help")) {
			cout << desc << "\n";
			exit(0);
		}

		// Setting the model and the cfg file

		std::string include_path = "", model_filename = "",
				config_filename = ""; //default set to empty
		if (vm.count("include-path")) {
			include_path = vm["include-path"].as<std::string>();
		}

		if (vm.count("config-file")) {
			user_options.set_configFile(vm["config-file"].as<std::string>());
		}
		if (vm.count("model-file")) {
			user_options.set_modelFile(vm["model-file"].as<std::string>());
		}
		
		// ***********Setting for Output file ****
		std::string fileName, fullPath, fileWithPath, forbidStr;
		if (vm.count("include-path")) {
			fullPath = vm["include-path"].as<std::string>();
		} else {
			fullPath = "./"; //default file path
		}
		fileWithPath.append(fullPath);
		if (vm.count("output-format")) {
			user_options.setOutputFormatType(vm["output-format"].as<std::string>());
		}

		if (vm.count("output-file")) {
			fileName = vm["output-file"].as<std::string>();
			user_options.setOutFilename(fileName);

		} else {
			fileName = "out.txt";
			user_options.setOutFilename(fileName);
		}
		fileWithPath.append(fileName);
		// ******** Setting for Output file Done *************

		if (vm.count("forbidden") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			user_options.set_forbidden_set(vm["forbidden"].as<std::string>());
		}

		if (vm.count("model-file") && vm.count("config-file")
				&& (user_options.get_model()!=0) ) { // model=0 default to no model specified
			std::cout << "Invalid input. Either a model file or a pre-loaded model to be specified, but not both.\n";
			throw(new exception());
		}
		
		if (vm.count("model-file") && vm.count("config-file")
					&& ((user_options.get_model()==0))) { // model=0 means no pre-built model specified
			string cmd_str = "java -jar Model-Translator.jar -t XSpeed \"\" -i " + vm["model-file"].as<std::string>() + " " + vm["config-file"].as<std::string>() + " -o input_model.mdl"; 
			system(cmd_str.c_str());
			parser _parser("input_model.mdl");
			_parser.parse();
			//system("rm input_model.mdl"); // remove the mdl file
		
			Hybrid_Automata = _parser.getHa(); // assign the parsed ha
			init_state.push_back(_parser.getInitState()); // assign the parsed init
			forbidden_states = _parser.getForbidden(); //assign the forbidden states
			isConfigFileAssigned = false;// to continue taking the params from cmdline
		}

		if (vm.count("directions") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			user_options.set_directionTemplate(vm["directions"].as<int>());
			if (user_options.get_directionTemplate() <= 0) {
				std::cout << "Invalid Directions option specified. Expected 1 for BOX, 2 for OCT, N for uniform directions.\n";
				throw(new exception());
			}
		}
		if (vm.count("depth") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_bfs_level(vm["depth"].as<int>());
			if (user_options.get_bfs_level() < 0) {
				std::cout<< "Invalid bfs level specified. A zero or a positive integer is expected.\n";
				throw(new exception());
			}
		}
		if (vm.count("engine")) { //Compulsory Options but set to thull by default
			user_options.setEngine((vm["engine"].as<std::string>()));
			if (boost::iequals(user_options.getEngine(),"simu")==false) {
				if (boost::iequals(user_options.getEngine(),"supp")==false){
					std::cout << "Invalid engine option specified. Expected \"supp\" or \"simu\".\n";
					throw(new exception());
				}
			}
		}
		//Simulation Algorithm Preference
		if (vm.count("simu-algo")) {
			user_options.set_simu_algo(vm["simu-algo"].as<int>());
			if (user_options.get_simu_algo()< 0 || user_options.get_simu_algo() > 2) {
				std::cout << "Invalid Simulation algorithm (--simu-algo) option specified.\n";
				throw(new exception());
			}
		}
		//Simulation initial choice for the number of sampling-start-points
		if (vm.count("simu-init-points")) {
			user_options.set_simu_init_points(vm["simu-init-points"].as<int>());
		}

		if (vm.count("aggregate")) { //Compulsory Options but set to thull by default
			user_options.setSetAggregation((vm["aggregate"].as<std::string>()));
			string optionVal = user_options.getSetAggregation();

			if ( boost::iequals(optionVal,"none")==false && boost::iequals(optionVal,"thull")==false && boost::iequals(optionVal,"chull")==false){
					std::cout << "Invalid aggregation option specified. Expected \"none\",\"thull\" or \"chull\".\n";
					throw(new exception());
				}
		}
		
		if (vm.count("output-variable")) {
			std::string VarStr;
			VarStr = vm["output-variable"].as<std::string>();

			typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
			boost::char_separator<char> sep(", ");
			tokenizer tokens(VarStr, sep);
			int index = 0;
			for (tokenizer::iterator tok_iter = tokens.begin();
					tok_iter != tokens.end(); ++tok_iter) {
				output_vars[index] = (std::string) (*tok_iter);
				index++;
			}
		}
		if (vm.count("forbidden") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			user_options.set_forbidden_set(vm["forbidden"].as<std::string>());
		}
		if(vm.count("CE") && isConfigFileAssigned == false) {
			user_options.set_ce_path(vm["CE"].as<std::string>());
			user_options.set_ce_flag(true);
		}
		if (vm.count("time-horizon") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_timeHorizon(vm["time-horizon"].as<double>());
			if (user_options.get_timeHorizon() <= 0) { //for 0 or negative time-bound
				std::cout << "Invalid time-horizon option specified. A positive non-zero value expected.\n";
				throw(new exception());
			}
		} 
		else{
				std::cout << "Missing value for parameter \"time-horizon\"\n";
				throw(new exception());
		}

		if (vm.count("time-step") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_timeStep(vm["time-step"].as<double>());
			if (user_options.get_timeStep() <= 0) {
				std::cout << "Invalid time-step option specified. A positive non-zero time-step expected.\n";
				throw(new exception());
			}
		}
		else {
			std::cout << "Missing value for parameter \"time-step\". \n";
			throw(new exception());
		}
		//Algorithm Preference
		if (vm.count("algo")) {
			user_options.set_algorithm(vm["algo"].as<int>());
			if (user_options.get_algorithm()< 0|| user_options.get_algorithm() > MAX_ALGO) {
				std::cout << "Invalid algorithm option specified.\n";
				throw(new exception());
			}
		} else {
			std::cout << "Missing value for parameter \"algo\". \n";
			throw(new exception());
		}

		if (user_options.get_algorithm() == 3) { //this argument will be set only if algorithm==time-slice or PAR_ITER
			if (vm.count("time-slice")) { //Compulsory Options if algorithm-type==Time-Slice(4)
				int partition_size = vm["time-slice"].as<int>();
				if (partition_size > 0) {
					user_options.setTotalSliceSize(partition_size);
				} else { //for 0 or negative time-slice
					std::cout << "Invalid time-slice option specified\n. A positive integer value expected.\n";
					throw(new exception());
				}
			} else {
				std::cout << "Missing value for parameter \"time-slice\" \n";
				throw(new exception());
			}
		}
		if (vm["model"].as<int>()!=0) { //Compulsory Options but set to 0 by default
			user_options.set_model(vm["model"].as<int>());
			load_ha_model(init_state, Hybrid_Automata, reach_parameters, user_options);
		}

	} //ALL COMMAND-LINE OPTIONS are set completely

			
	if(output_vars[0].empty() && output_vars[1].empty())
	{
		std::cout<<"Output variables not specified. Two variables of the system expected.\n"<<std::endl;
		throw(new exception());
	}
 
	int x1, x2;
	try{
		if(Hybrid_Automata.ymap_size()!=0){
			unsigned int m = Hybrid_Automata.ymap_size();
			x1 = Hybrid_Automata.get_y_index(output_vars[0]);
			if(x1==-1) // string not present in ymap.
			{
				x1 = Hybrid_Automata.get_index(output_vars[0]);
				Hybrid_Automata.insert_to_output_map(output_vars[0],m);
				location::ptr loc = Hybrid_Automata.getInitialLocation();
				Dynamics& D = loc->getSystemDynamics();
				unsigned int sysDim = Hybrid_Automata.map_size();
				math::matrix<double> rowMat(1,sysDim);
				rowMat.clear();
				rowMat(0,x1)=1;
				D.MatrixT.matrix_join(rowMat,D.MatrixT);
				x1=m; m++;
			}
			x2 = Hybrid_Automata.get_y_index(output_vars[1]);
			if(x2==-1) // string not present in ymap.
			{
				x2 = Hybrid_Automata.get_index(output_vars[1]);
				Hybrid_Automata.insert_to_output_map(output_vars[1],m);
				location::ptr loc = Hybrid_Automata.getInitialLocation();
				Dynamics& D = loc->getSystemDynamics();
				unsigned int sysDim = Hybrid_Automata.map_size();
				math::matrix<double> rowMat(1,sysDim);
				rowMat.clear();
				rowMat(0,x2)=1;
				D.MatrixT.matrix_join(rowMat,D.MatrixT);
				x2=m;
			}
		}
		else{
			x1 = Hybrid_Automata.get_index(output_vars[0]);
			x2 = Hybrid_Automata.get_index(output_vars[1]);
		}
	}catch(const std::out_of_range& oor)
	{
		std::cerr << "Output variables not defined in the model: " << oor.what() << '\n';
		std::cerr << "Please use two output variables from the following list of model variables\n";
		Hybrid_Automata.print_var_index_map();
		exit(0);
	}

	user_options.set_first_plot_dimension(x1);
	user_options.set_second_plot_dimension(x2);
	if (!(output_vars[2].empty())) {
		unsigned int x3 = Hybrid_Automata.get_index(output_vars[2]);
		user_options.set_third_plot_dimension(x3);
	}

	/* Set the reachability options given by the user */
	set_params(Hybrid_Automata, init_state, user_options, reach_parameters, forbidden_states);

	if (!user_options.get_forbidden_set().empty()){
		assert(forbidden_states.size()!=0);
		try{
			forbidden forbidden_set;
			forbidden_set = forbidden_states[0]; // the first symb state
			forbidden_set.second->print2file("./bad_poly", x1, x2);
		} catch(...){
			std::cout << "Cannot print the forbidden polytope because it is unbounded in the print dimensions or may be empty\n";
		}
	}

}
