
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
extern void flow_parser(Dynamics& D);

/* parses the variable names and creates the
 * var_to_id list.
 */
void parser::parse_vars(fstream& file)
{
	// read lines until End is read
	string var;
	
	unsigned int dim=0; // dim in ha starts from 0.

	while(getline(file,var)){
		if(var.compare("#End")==0)
			break;
		if(var.compare("")==0)
			continue;
		//std::cout << "Inserting variable " << var << " id= " << loc_id << std::endl;
		ha.insert_to_map(var,dim++);
	}
	ha.setDimension(dim);
}

/* parses the ha locations.*/

void parser::parse_loc(fstream& file, location::ptr loc){
	string line;
	
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
			std::cout << "Setting location name:" << *tok_iter << std::endl;
			loc->setName(*tok_iter);
		}
		else if((*tok_iter).compare("LocId")==0){
			tok_iter++;
			std::cout << "Setting location Id:" << *tok_iter << std::endl;
			unsigned int locId = std::stoi(*tok_iter);
			loc->setLocId(locId);
		}
		else if((*tok_iter).compare("Inv")==0){
			tok_iter++;
			std::cout << "Setting inv to:" << *tok_iter << std::endl;
			string inv_str = *tok_iter;
			polytope::ptr inv = polytope::ptr(new polytope()); 
			gen_polytope(inv_str,inv);
			loc->setInvariant(inv);
			if(!inv->getIsEmpty())
				loc->setInvariantExist(true);
		}
		else if((*tok_iter).compare("Flow")==0){
			Dynamics D;
			D.isEmptyMatrixA = true;
			D.isEmptyMatrixB = true;
			D.isEmptyC = true;

			int dim = ha.getDimension();
			D.MatrixA.resize(dim,dim);
			gen_flow(file, D);
			//debug
			std::cout << "The generated A matrix:\n";
			std::cout << D.MatrixA << std::endl;
			std::cout << "The constant vector:\n";
			for(unsigned int i=0;i<D.C.size();i++)
				std::cout << D.C[i] << "\n";
			//--
			loc->setSystem_Dynamics(D);
			
		}
		else if((*tok_iter).compare("Transitions")==0){
		}
		ha.addLocation(loc);
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
			else{
				std::cout << "Error in model file. Expected #Variables or #Location\n";
				std::cout << "Line seen: " << line << std::endl;
			}
		}
		mdlFile.close();
	}
	ha.addMapped_Locations_List(locs_list); // added locs list to ha
	std::cout << "Model parsing complete.\n";
	
	exit(0);
}

/* parses a list of linear inequality expressions string to 
 * create a polytope.
 */
void parser::gen_polytope(string str, polytope::ptr inv){
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
		std::cout << "String sent to bison for parsing:" << line << std::endl;
		line+="\n"; // To bypass flex issue - not able to detect eos 		
		yy_buffer_state* my_string_buffer = yy_scan_string(line.c_str());
		flow_parser(D); // calls bison parser.
		yy_delete_buffer(my_string_buffer);
	}
	
}


