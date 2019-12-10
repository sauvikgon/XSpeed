/*
 * abstractCE.h
 *
 *  Created on: 12-Jan-2016
 *      Author: rajarshi
 */

#ifndef ABSTRACTCE_H_
#define ABSTRACTCE_H_


#include <list>
#include <boost/shared_ptr.hpp>
#include "nlopt.hpp"
#include "counterExample/abstract_symbolic_state.h"
#include "counterExample/concreteCE.h"
#include "nlpFunctions.h"
#include <fstream>
#include <string>
#include "../core/continuous/ConvexSet/supportFunctionProvider.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/HybridAutomata/Transition.h"
#include "../core/symbolic_states/symbolic_states.h"
#include "core/math/lp_solver/lp_solver.h"


/**
 * This class is a data structure to store the abstract counter-example generated
 * by XSpeed when given an unsafe symbolic state. An abstract counter example
 * is an ordered list of symbolic states starting from an initial and ending in an
 * unsafe region.
 *
 * @author: Rajarshi
 */

extern unsigned int N;
extern unsigned int dim;
extern hybrid_automata::ptr HA;
extern std::vector<int> locIdList;
extern std::list<transition::ptr> transList;
extern polytope::ptr bad_poly;
extern std::list<refinement_point> ref_pts; // a list of invariant violating points to refine the search and obtain a valid trajectory
extern std::vector<std::vector<double> > X0; // list of start points of the trajectory segments. Used only in the NLP-LP mixed program
extern std::list<symbolic_states::ptr> ce_sym_states; // list of CE abstract sym states. Used only in the NLP-LP mixed problem

class abstractCE
{
public:
	typedef boost::shared_ptr<abstractCE> ptr;
	typedef boost::shared_ptr<const abstractCE> const_ptr;
	/**empty constructor */
	abstractCE() {
	}
	;
	/* another constructor */
	abstractCE(std::list<symbolic_states::ptr> s_states,
			std::list<transition::ptr> ts, hybrid_automata::ptr h, polytope::ptr fpoly);
	/* destructor */
	~abstractCE() {
	}
	;
	std::list<symbolic_states::ptr> get_CE_sym_states() const {
		return sym_states;
	}
	std::list<transition::ptr> get_CE_transitions() const {
		return trans;
	}

	symbolic_states::const_ptr get_first_symbolic_state() const;

	/**
	 * The semantics assumes that the last abstract_symbolic_state in the list contains the
	 * unsafe polytope
	 */
	symbolic_states::const_ptr get_last_symbolic_state() const;

	/**
	 * Returns the forbidden polytope
	 */
	polytope::ptr get_forbidden_poly(){
		return forbid_poly;
	}
	/**
	 * Returns the i-th symbolic state from the CE
	 */
	symbolic_states::const_ptr get_symbolic_state(unsigned int i) const;

	const unsigned int get_length() const {
		return length;
	}

	void set_length(unsigned int len) {
		length = len;
	}

	void set_sym_states(std::list<symbolic_states::ptr> sym);

	void set_transitions(std::list<transition::ptr> transitions) {
		trans = transitions;
	}
	/**
	 * Sets the reference to the hybrid automaton to which this CE refers.
	 */
	void set_automaton(hybrid_automata::ptr h){
		H = h;
	}
	/**
	 * Sets the forbidden polytope of this abstract counter example
	 */
	void set_forbid_poly(polytope::ptr fpoly){
		forbid_poly = fpoly;
	}
	hybrid_automata::ptr get_automaton(){
		return H;
	}
	/**
	 * returns a validated counterexample trace, a trace that satisfies the HA constraints
	 * @algo_type: mention the splicing algorithm:
	 * 	1 specifies to call splicing with FC
	 * 	2 specifies to call splicing with no FC
	 *	3 specifies to call LP-NLP mixed procedure for splicing.
	 */
	concreteCE::ptr get_validated_CE(double tolerance, unsigned int alg_type);

	/**
	 * Plot the counter example projected along dimensions passed
	 * as parameters
	 */
	void plot(unsigned int i, unsigned int j);

	/**
	 * Filter function to filter abstract CEs, not the one specified in the parameter.
	 * The specified abstract CE is given by the list of location ids
	 * An empty template will not filter any ce.
	 * Returns true when the CE matches the filter template in the argument. False otherwise.
	 */
	bool filter(std::vector<unsigned int> template_sequence);

	/**
	 * Returns an instance of the concrete counter-examples, if it exists, by searching the abstract paths in
	 * the argument. The path-filter argument restricts the search in a unique path.
	 */
	static concreteCE::ptr search_concreteCE(double tolerance, std::list<abstractCE::ptr> paths, std::vector<unsigned int> path_filter,unsigned int algo_type);


private:
	/**
	 * The first symbolic state is the initial symbolic state and the last one
	 * is the unsafe symbolic state
	 */
	std::list<symbolic_states::ptr> sym_states;

	/**
	 * The list of transitions taken from the initial symbolic_state to the
	 * final symbolic_state.
	 */
	std::list<transition::ptr> trans;
	/**
	 * length shows how many locations are present in the abstract counter
	 * example.
	 */
	unsigned int length;

	/**
	 * The reference to the automaton to which this is an abstract counter example
	 */
	hybrid_automata::ptr H;
	/**
	 * The reference to the forbidden polytope given by the user
	 */
	polytope::ptr forbid_poly;

	/**
	 * Returns an instance of a concrete counter-example from the abstract one, using NLP with flowpipe given constraints
	 */
	concreteCE::ptr gen_concreteCE(double tolerance, const std::list<refinement_point>& refinements);

	/**
	 * Returns an instance of the concrete counter-example, if it exists, using mixed NLP-LP problem
	 */
	concreteCE::ptr gen_concreteCE_NLP_LP(double tolerance, const std::list<refinement_point>& refinements);

	lp_solver construct_LP(unsigned int lpDim, std::vector<double> &t, math::matrix<double> lp_coeff, std::vector<double> lp_col);

	void construct_bound_constraints(math::matrix<double> &coeff_mat, std::vector<double> &col, std::vector<double> lb, std::vector<double> ub, unsigned int dim);

	concreteCE::ptr gen_concreteCE_NLP_LP_softconstr(double tolerance, const std::list<refinement_point>& refinements);
	lp_solver construct_LP_softconstr(unsigned int lpDim, std::vector<double> &t, math::matrix<double> lp_coeff, std::vector<double> lp_col);

	/**
	 * Returns an instance of the concrete counter-example, if it exists, using NLP and HA given constraints
	 */
	concreteCE::ptr gen_concreteCE_NLP_HA(double tolerance, const std::list<refinement_point>& refinements);

	concreteCE::ptr gen_concreteCE_iterative(double tolerance, const std::list<refinement_point>& refinements);

	lp_solver build_lp(std::vector<double> dwell_times);
};


std::vector<double> simulate_trajectory(const std::vector<double>& x0,
		Dynamics& D, const double& time, double& distance, polytope::ptr I, std::vector<double>&);

#endif /* ABSTRACTCE_H_ */
