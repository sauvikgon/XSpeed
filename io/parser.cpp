
#include "parser.h"
#include <fstream>

#include <boost/tokenizer.hpp>
#include <stdio.h>
using namespace boost;

// defined externally
struct yy_buffer_state
{
	FILE *yy_input_file;

	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	int yy_buf_size;
	int yy_n_chars;
	int yy_is_our_buffer;
	int yy_is_interactive;
	int yy_at_bol;

  int yy_bs_lineno; /**< The line count. */
  int yy_bs_column; /**< The column count. */
	int yy_fill_buffer;
	int yy_buffer_status;
};
	
extern yy_buffer_state* yy_scan_string ( const char *yy_str  );
extern void yy_delete_buffer ( yy_buffer_state* b  );

extern yy_buffer_state* linexp_scan_string ( const char *yy_str  );
extern void linexp_delete_buffer ( yy_buffer_state* b  );

extern void flow_parser(Dynamics& D);
extern void linexp_parser(polytope::ptr& p);

/* parses the variable names and creates the
 * var_to_id list.
 */
void parser::parse_vars(fstream& file)
{
	// read lines until End is read
	string var;
	
	unsigned int dim=0; // dim in ha starts from 0.
	unsigned int m=0; // the number of inputs in the ha.

	while(getline(file,var)){
		if(var.compare("#End")==0)
			break;
		if(var.compare("")==0)
			continue;
		//std::cout << "Inserting variable " << var << " id= " << loc_id << std::endl;
		if(var[0]=='u' || var[0]=='U') // input variable
		{
			//std::cout << "adding " << var << "to umap" << std::endl;
			ha.insert_to_input_map(var,m++);
		}
		else
			ha.insert_to_map(var,dim++);
	}
	ha.setDimension(dim);
}

/* parses the ha locations.*/

void parser::parse_loc(fstream& file, location::ptr loc){
	string line;
	Dynamics D;

	while(getline(file,line)){
		if(line.compare("#End")==0)
			break;
	
		// if empty line, then continue
		if(line.compare("")==0)
			continue;

		char_separator<char> sep(":");
		tokenizer<char_separator<char> > tokens(line,sep);
		tokenizer<char_separator<char> >::iterator tok_iter=tokens.begin();

		if((*tok_iter).compare("Locname")==0){
			tok_iter++;
			//std::cout << "Setting location name:" << *tok_iter << std::endl;
			loc->setName(*tok_iter);
		}
		else if((*tok_iter).compare("LocId")==0){
			tok_iter++;
			//std::cout << "Setting location Id:" << *tok_iter << std::endl;
			unsigned int locId = std::stoi(*tok_iter);
			loc->setLocId(locId);
		}
		else if((*tok_iter).compare("Inv")==0){
			tok_iter++;
			//std::cout << "Setting inv to:" << *tok_iter << std::endl;
			string inv_str = *tok_iter;
			polytope::ptr inv;
			if(inv_str.compare("true")==0)
				inv = polytope::ptr(new polytope()); // universe
			else
			{	
				inv = polytope::ptr(new polytope()); //universe
				//todo: initialise inv
				if(!inv->getIsEmpty())
					loc->setInvariantExist(true);
			}
			// todo: Get U from Inv string.
			D.U = polytope::ptr(new polytope(true)); // empty input U
			loc->setInvariant(inv);
		}
		else if((*tok_iter).compare("Flow")==0){
			
			D.isEmptyMatrixA = true;
			D.isEmptyMatrixB = true;
			D.isEmptyC = true;

			int dim = ha.getDimension();
			D.MatrixA.resize(dim,dim);
			D.MatrixA.clear(); // all elements set to 0
			
			if(ha.umap_size()!=0)
				D.MatrixB.resize(dim,ha.umap_size());
			D.MatrixB.clear(); // all elements set to 0
			
			gen_flow(file, D);
			//debug
			/*	
			std::cout << "The generated A matrix:\n";
			std::cout << D.MatrixA << std::endl;
			std::cout << "The generated B matrix:\n";
			std::cout << D.MatrixB << std::endl;
			std::cout << "The constant vector:\n";
			for(unsigned int i=0;i<D.C.size();i++)
				std::cout << D.C[i] << "\n";
			*/
			//--

			/* Setting the constants in dynamics to input when U is empty */
			
			if(D.isEmptyMatrixB && !D.isEmptyC){
				D.MatrixA.matrix_Identity(dim,D.MatrixB); // dim X dim Identity Mat
				D.isEmptyMatrixB = false;
			}
			unsigned int row = dim*2;
			unsigned int col = dim;
			math::matrix<double> UMatrix(row, col);
			UMatrix.clear();
			for(unsigned int i=0,j=0;i<row-1;i+=2,j++){
				UMatrix(i,j)=1;
				UMatrix(i+1,j)=-1;	
			}
			std::vector<double> Ubound(row,0);
			for(unsigned int i=0;i<row-1;i+=2){
				Ubound[i] = D.C[i];
				Ubound[i+1] = -D.C[i];
			}
			D.U = polytope::ptr(new polytope(UMatrix, Ubound, 1));
			loc->setSystem_Dynamics(D);
			
		}
		else if((*tok_iter).compare("Transitions")==0){
			transition::ptr t = transition::ptr(new transition());
			parse_transition(file,t);
			loc->add_Out_Going_Transition(t);
		}
	}
	
}

/* The master parsing method */
void parser::parse()
{
	std::cout << "Parsing model ... \n";
	fstream mdlFile;
	std::map<int, location::ptr> locs_list;
	
	mdlFile.open(this->model_file,ios::in);
	string line;
	
	if(mdlFile.is_open())
	{
		while(getline(mdlFile,line))
		{
			if(line.compare("#Variables") == 0){
				parse_vars(mdlFile);
			}			
			else if(line.compare("#Location") == 0){
				location::ptr loc = location::ptr(new location());
				parse_loc(mdlFile,loc);
				int locId = loc->getLocId();
				std::pair<int, location::ptr> element;
				element.first = locId;
				element.second = loc;
				locs_list.insert(element); // initialized loc added to the list.
			}
			else if(line.compare("")==0) continue; // empty line.

			else if(line.compare("#Init")==0){
			
				polytope::ptr p = polytope::ptr(new polytope());
				p->setIsEmpty(false);
				p->setIsUniverse(true);
				
				int init_locId = 1; // default initial location
				parse_initial(mdlFile, p, init_locId);
				
				// define the initial_state symbolic state
				initial_state::ptr ini_ptr = initial_state::ptr(new initial_state(init_locId, p));
		
				this->ini = ini_ptr;
			}
			else{
				std::cout << "Error in model file. Expected #Variables, #Location, #Init or #forbidden\n";
				std::cout << "Line seen: " << line << std::endl;
			}
		}
		mdlFile.close();
	}
	ha.addMapped_Locations_List(locs_list); // added locs list to ha
	ha.setInitialLoc(ini->getLocationId());
	std::cout << "Model parsing complete.\n";
	
}

/* parses a list of linear inequality expressions string to 
 * create a polytope.
 */
void parser::gen_polytope(string str, polytope::ptr inv){
	char_separator<char> sep("&;");
	tokenizer<char_separator<char> > tokens(str,sep);
	tokenizer<char_separator<char> >::iterator tok_iter=tokens.begin();

	for(;tok_iter!=tokens.end();tok_iter++){
		string constr_str = *tok_iter;
		std::cout << "constraint string=" << constr_str << std::endl;
	}
}

/* parses a list of linear equality expressions string to
 * create a reset map
 */
void parser::gen_reset(string r_str, math::matrix<double>& R, std::vector<double>& w){
}

/* parses a list of consecutive odes to create the dynamics */
void parser::gen_flow(fstream& file, Dynamics& D){
	string line;	
	while(getline(file,line)){
		if(line.compare("#End")==0)
			return;	
	
		// if empty line, then continue
		if(line.compare("")==0)
			continue;
		// parse the line
		//std::cout << "String sent to bison for parsing:" << line << std::endl;
		line+="\n"; // To bypass flex issue - not able to detect eos 		
		yy_buffer_state* my_string_buffer = yy_scan_string(line.c_str());
		flow_parser(D); // calls bison parser.
		yy_delete_buffer(my_string_buffer);
	}
	
}

/* parses transition parameters and creates a transition obj */
void parser::parse_transition(fstream& file, transition::ptr& t)
{
	string line;	
	while(getline(file,line)){
		if(line.compare("#End")==0)
			return;
		// if empty line, then continue
		if(line.compare("")==0)
			continue;
	}	
}
/* parses the initial condition string */
void parser::parse_initial(fstream& file, polytope::ptr& p, int& init_locId)
{
		string init_str;
		do{
			getline(file,init_str);
		}while(init_str.compare("")==0); // consume white lines
	
		typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
		boost::char_separator<char> sep("&;");
		tokenizer tokens(init_str, sep);

		std::list<std::string> all_args;				
		for (tokenizer::iterator tok_iter = tokens.begin();
				tok_iter != tokens.end(); ++tok_iter) {
			all_args.push_back((std::string) *tok_iter);
		}
		
		string tokString;
		tokenizer::iterator tok_iter;
		for(std::list<std::string>::iterator iter = all_args.begin(); iter!=all_args.end();iter++){
			tokString = *iter;	
			/* check if setting location id*/
				
			if(tokString.find("loc")!=std::string::npos){
				
				boost::char_separator<char> sep1("=");
				tokens = tokenizer(tokString, sep1);
				tok_iter = tokens.begin();
				string s(*tok_iter);
				assert(s.compare("loc")==0);
				
				tok_iter++;
				init_locId = std::atoi((*tok_iter).c_str());
				continue;
			}
			
			/*---end of loc id setting -----*/
	
			tokString+="\n"; // To bypass flex issue - not able to detect eos 		
			yy_buffer_state* my_string_buffer = linexp_scan_string(tokString.c_str());
			linexp_parser(p); // calls bison parser			
			linexp_delete_buffer(my_string_buffer);
	}
}
/* returns the parsed ha*/
hybrid_automata parser::getHa()
{
	return this->ha;
}

/* returns the parsed initial state */
initial_state::ptr parser::getInitState()
{
	return this->ini;
}

