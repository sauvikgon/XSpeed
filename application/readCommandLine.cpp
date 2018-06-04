/*
 * readCommandLine.cpp
 *
 *  Created on: 28-Oct-2016
 *      Author: hazel
 */

#include <application/readCommandLine.h>

namespace po = boost::program_options;

void readCommandLine(int argc, char *argv[], userOptions& user_options,
		hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters) {

	std::pair<int, polytope::ptr> forbidden_set; //(locID1,Polytope1)}

	bool isConfigFileAssigned = false, isModelParsed = false;

	po::options_description desc("XSpeed options");
	po::variables_map vm;

	if (argc == 1) { //No argument:: When Running directly from the Eclipse Editor
		std::cout << "Missing arguments!\n";
		throw(new exception());
	}

	desc.add_options()
	("help", "produce help message")
	("model", po::value<int>()->default_value(0), "set model for reachability analysis\n"
					"1.  Bouncing Ball Model: Variables{x,v}\n"
					"2.  Timed Bouncing Ball Model: Variables{x,v,t}\n"
					"3.  28-Dimensional Helicopter Controller Model: Variables{x1..x28}\n"
					"4.  Five dimensional Benchmark Model: Variables{x1..x5} \n"
					"5.  Navigation Benchmark Model-NAV01 (3 X 3): Variables{x1,x2,v1,v2}\n"
					"6.  Navigation Benchmark Model-NAV02 (3 X 3): Variables{x1,x2,v1,v2}\n"
					"7.  Navigation Benchmark Model-NAV03 (3 X 3): Variables{x1,x2,v1,v2}\n"
					"8.  Navigation Benchmark Model-NAV04 (5 X 5): Variables{x1,x2,v1,v2}\n"
					"9.  Navigation Benchmark Model-NAV05 (9 X 9): Variables{x1,x2,v1,v2}\n"
					"10. Circle with only ONE location model: Variables{x,y} \n"
					"11. Circle with TWO locations model: Variables{x,y} \n"
					"12. Circle with FOUR locations model: Variables{x,y} \n"
					"13. Oscillator model without any filters: Variables{x,y}\n"
					"14. Testing Model: Variables{depends on the model in test}\n")
	("engine,e", po::value<std::string>()->default_value("supp"), "set the running engine (default supp): \n - supp : Reachability Computation using Support Functions Algorithm \n - simu : Trajectory Simulation\n")
	("simu-algo",po::value<int>()->default_value(1), "Set the Simulation algorithm\n"
				"1 -- Sequential Algorithm (Set to default)\n"
				"2 -- A-GJH, Adaptation of Gerard J. Holzmann Algorithm\n")
	("simu-init-points",po::value<int>()->default_value(1), "(default 1) Sets the number of initial points "
                "chosen for sampling the initial states, counted per initial set.") //Todo:: If one, takes the center of the bounding box.")
	("directions", po::value<int>()->default_value(1), "Set the directions for template polyhedra:\n"
					"1. Box Directions (Set to default)\n"
					"2. Octagonal Directions \n"
					"n. 'n' uniform Directions \n")
	("time-horizon", po::value<double>(), "Set the local time horizon of flowpipe computation.")
	("time-step", po::value<double>(), "Set the sampling time of flowpipe computation.")
	("algo,a",po::value<int>()->default_value(1), "Set the algorithm\n"
			"1 -- Sequential Algorithm (Set to default)\n"
			"2 -- ParSup, Parallel Sampling of Template Directions (Parallellism in PostC) \n"
			"3 -- Time-sliced Parallel Algorithm (Parallellism in PostC)\n"
			"4 -- A-GJH, Adaptation of Gerard J. Holzmann Algorithm (Parallel exploration of symbolic states)\n"
			"5 -- TP-BFS, Task-parallel Algorithm (Parallel exploration of symbolic states)\n"
			"6 -- Lazy Evaluation Algorithm, PostC in GPU\n"
			"7 -- AsyncBFS, Asynchronous Parallel BFS Algorithm (Parallel exploration of symbolic states)\n"
			"8 -- Sequential algorithm (Forward approximation model)\n")
	("number-of-streams", po::value<int>()->default_value(1), "Set the number of GPU-streams (Set to 1 by default).")
	("time-slice", po::value<int>(), "Set the number of Time Slice or partitions for the Time-sliced Algorithm")
	("depth", po::value<int>(), "Set the depth of HA exploration for Bounded Model Checking (0 for only postC)")
	("aggregate", po::value<std::string>()->default_value("thull"), "Set-aggregation (default thull): \n - thull : template hull \n - none : consider each convex set as successor sets for the next depth")

	//("internal", "called internally when running hyst-xspeed model")
	("forbidden,F", po::value<std::string>(), "forbidden location_ID and forbidden set/region within that location") //better to be handled by hyst
	("include-path,I", po::value<std::string>(), "include file path")
	("model-file,m", po::value<std::string>(), "include model file")
	("config-file,c", po::value<std::string>(), "include configuration file")
	("output-file,o", po::value<std::string>(), "output file name for redirecting the outputs")
	("output-variable,v", po::value<std::string>(), "projecting variables for e.g., 'x,v' for Bouncing Ball") //better to be handled by hyst
	("output-format", po::value<std::string>()->default_value("GEN"), "The type of output format, either GEN or INTV. GEN prints the vertices of the reach set and INTV prints the global bounds on the output variables (Set to GEN by default)")
;

	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	std::vector<std::string> output_vars(3); //stores the output/plotting variables

	// string with commandline options except model and cfg file names
	const char *stFileNameWithPath;

	std::string input;
	for (int i = 1; i < argc; i++) {

		if (std::string(argv[i]).find("-o") != string::npos || std::string(argv[i]).find("--output-file") != string::npos || std::string(argv[i]).find("-m") != string::npos || std::string(argv[i]).find("-c") != string::npos ||
				std::string(argv[i]).find("--model-file") != string::npos || std::string(argv[i]).find("--config-file") != string::npos )
			i++;
		else {
			if (std::string(argv[i]).find("-F") != string::npos){
				//std::cout<<"argv[i] = " <<argv[i]<<std::endl;
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
	if (argc > 1) { // Boost Options to be filled-up
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
		if (vm.count("model")) { //Compulsory Options but set to 0 by default
			user_options.set_model(vm["model"].as<int>());
			if (user_options.get_model() < 0 || user_options.get_model() > 20) {
				std::cout << "Invalid Model specified\n";
				throw(new exception());
			}
		}

		// ********************** Setting for Output file **********************************
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
		stFileNameWithPath = fileWithPath.c_str();//Required for recursive Call
		// ********************** Setting for Output file Done **********************************

		if (vm.count("forbidden") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			user_options.set_forbidden_set(vm["forbidden"].as<std::string>());
		}

		if (vm.count("model-file") && vm.count("config-file")
				&& (user_options.get_model()!=0) ) { // model=0 default to no model specified
			std::cout << "Invalid inputs (Either a model file or a pre-loaded model to be specified, but not both.)\n";
			throw(new exception());
		}

		if (vm.count("model-file") && vm.count("config-file")
					&& ((user_options.get_model()==0))) { // model=0 default to no model specified
				std::cout << "Translating user model to XSpeed format using Hyst model translator\n";
				std::string cmdStr, replacingFile, SingleSpace = " ", projLocation,
						java_exeFile, forbidden_string;
			replacingFile = "./user_model.cpp";
			//replacingFile = "../src/Hybrid_Model_Parameters_Design/user_model/user_model.cpp";
			java_exeFile = "java -jar";
			cmdStr.append(java_exeFile);
			cmdStr.append(SingleSpace);
			cmdStr.append("../Hyst-XSpeed.jar -t xspeed \"\" -o");
			cmdStr.append(SingleSpace);
			cmdStr.append(replacingFile);
			cmdStr.append(" -i ");
			cmdStr.append(user_options.get_modelFile()); //cmdStr.append(modelFile);
			cmdStr.append(" ");
			cmdStr.append(user_options.get_configFile()); //cmdStr.append(configFile);
			const char *st;
			st = cmdStr.c_str();
			system(st); //calling hyst interface to generate the XSpeed model file


			system("g++ -c -I/usr/local/include/ -I/home/rajarshi/workspace/xspeed/ user_model.cpp -o user_model.o");
			system("g++ -L/usr/local/lib/ user_model.o -lxspeed -lgsl -lgslcblas -lppl -lgmp -lboost_timer -lboost_chrono -lboost_system -lboost_program_options -pthread -lgomp -lglpk -lsundials_cvode -lsundials_nvecserial -lnlopt -lmodels -o ./xspeed");

			std::cout << "Model Parsed Successfully!! Calling XSpeed ... " << std::endl;

			string cmdStr1="";
			cmdStr1.append("./xspeed --model=15 -o"); //Recursive call has model file, config file and model=15 and the rest of the parameters(if available)
			cmdStr1.append(SingleSpace);
			cmdStr1.append(stFileNameWithPath);
			cmdStr1.append(SingleSpace);
			cmdStr1.append(input);

			system(cmdStr1.c_str());
			exit(0);
		}
		if (user_options.get_model() == 15) { //This condition specifies Recursive call of XSpeed
			user_model(Hybrid_Automata, init_state, reach_parameters,user_options);
			unsigned int x1,x2;
			x1 = user_options.get_first_plot_dimension();
			x2 = user_options.get_second_plot_dimension();

			if (!user_options.get_forbidden_set().empty()){
				string_to_poly(user_options.get_forbidden_set(), forbidden_set);
				forbidden_set.second->print2file("./bad_poly", x1, x2);
			}
			isModelParsed = true;
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
		} else if (user_options.get_model() != 15) {
			std::cout << "Missing value for parameter \"depth\"\n";
			throw(new exception());
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
			if (boost::iequals(user_options.getSetAggregation(),"none")==false) {
				if (boost::iequals(user_options.getSetAggregation(),"thull")==false){
					std::cout << "Invalid aggregation option specified. Expected \"none\" or \"thull\".\n";
					throw(new exception());
				}
			}
		}
		if ((user_options.get_model() == 3 || user_options.get_model() == 4) && user_options.get_bfs_level() != 0){
			std::cout << "Invalid depth. Only depth 0 permitted on continuous models.\n";
			throw(new exception());
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

		if (vm.count("time-horizon") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_timeHorizon(vm["time-horizon"].as<double>());
			if (user_options.get_timeHorizon() <= 0) { //for 0 or negative time-bound
				std::cout << "Invalid time-horizon option specified. A positive non-zero value expected.\n";
				throw(new exception());
			}
		} else if (user_options.get_model() != 15) {
			std::cout << "Missing value for parameter \"time-horizon\"\n";
			throw(new exception());
		}
		if (vm.count("time-step") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_timeStep(vm["time-step"].as<double>());
			if (user_options.get_timeStep() <= 0) {
				std::cout << "Invalid time-step option specified. A positive non-zero time-step expected.\n";
				throw(new exception());
			}
		} // else if (isConfigFileAssigned == false) {
		else if (user_options.get_model() != 15) {
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
		} else if (user_options.get_model() != 15) {
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
		if (user_options.get_algorithm() == 6) { //if gpu enabled then
			if (vm.count("number-of-streams")) { //Compulsory Options but set 1 by default
				int no_streams = vm["number-of-streams"].as<int>(); //default value ==1
				if (no_streams >= 1) {
					//number_of_streams = no_streams; //Number of GPU-Streams selected
					user_options.setStreamSize(no_streams);
				} else {
					std::cout << "Invalid number_of_streams option specified. An integral value larger of equal to 1 expected.\n";
					throw(new exception());
				}
			}
		}

	} //ALL COMMAND-LINE OPTIONS are set completely

	if (!isModelParsed && user_options.get_model() != 15) { //all command line options has been supplied
		load_model(init_state, Hybrid_Automata, user_options, reach_parameters, forbidden_set);

		if(output_vars[0].empty() && output_vars[1].empty())
		{
			std::cout<<"Output variables not specified. Two variables of the system expected.\n"<<std::endl;
			throw(new exception());
		}

		unsigned int x1, x2;
		try{
			x1 = Hybrid_Automata.get_index(output_vars[0]);
			x2 = Hybrid_Automata.get_index(output_vars[1]);
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
		if (!user_options.get_forbidden_set().empty())
			forbidden_set.second->print2file("./bad_poly", x1, x2);
	}
	//return 1;
}
