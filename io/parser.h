#ifndef  __PARSER_H
#define  __PARSER_H

#include "core/HybridAutomata/Hybrid_Automata.h"
#include "core/symbolic_states/initial_state.h"
#include "flowParser/flow_yacc.tab.h"
#include "linExpParser/linexp.tab.h"

/**
 * Parser implementation of .mdl file.
 * .mdl is the XSpeed representation of
 * SpaceEx model file in .xml format.
 *
 * These files are obtained by a model
 * transformation in Hyst XSpeed printer.
 *
 * @author: Rajarshi
 */

class parser
{
	string model_file;
	hybrid_automata ha;
	initial_state::ptr ini;

public:
	parser(string m_file){
		this->model_file = m_file;
	}
	~parser(){};
	/* creates a hybrid automaton model from parsing */
	void parse();

	/* returns the parsed ha*/
	hybrid_automata getHa();

	/* returns the parsed initial state */
	initial_state::ptr getInitState();

	/* parses the ha locatios and a list of locations.*/
	void parse_loc(fstream& file, location::ptr loc);

	/* parses the variable names and creates the
 	 * var_to_id list.
 	 */
	void parse_vars(fstream& file);

	/* parses a list of linear inequality expressions string to 
   * create a polytope.
   */
	void gen_polytope(string str, polytope::ptr inv);

	/* parses a list of linear equality expressions string to
   * create a reset map
   */
	void gen_reset(string r_str, math::matrix<double>& R, std::vector<double>& w);

	/* parses a list of consecutive ode to create the flow matrix */
	void gen_flow(fstream& file, Dynamics& D);

	/* parses transition parameters and creates a transition obj */
	void parse_transition(fstream& file, transition::ptr& t);

	/* parses the initial condition string */
	void parse_initial(fstream& file, polytope::ptr& p, int& init_locId);
};

#endif
