/*
 * themeSelector.cpp
 *
 *  Created on: 12-Aug-2020
 *      Author: rajarshi
 */

#include <application/themeSelector.h>


themeSelector::themeSelector() {
	// TODO Auto-generated constructor stub
}
void themeSelector::setUserOps(userOptions& op) {
	this->userOps = op;
}

void themeSelector::setHa(hybrid_automata& ha){
	this->ha = ha;
}

void themeSelector::setInit(std::list<initial_state::ptr>& init){
	this->init = init;
}

void themeSelector::setReachParams(ReachabilityParameters& params) {
	this->reach_params= params;
}

void themeSelector::setForbidden(forbidden_states& forbidden) {
	this->forbidden = forbidden;
}

userOptions& themeSelector::getUserOps(){
	return this->userOps;
}
hybrid_automata& themeSelector::getHa() {
	return this->ha;
}
std::list<initial_state::ptr>& themeSelector::getInit() {
	return this->init;
}
ReachabilityParameters& themeSelector::getReachParams(){
	return this->reach_params;
}
forbidden_states& themeSelector::getForbidden(){
	return this->forbidden;
}

void themeSelector::selectReach()
{
	std::list<symbolic_states::ptr> symbolic_states;
	std::list<abstractCE::ptr> ce_candidates; //object of class counter_example

	boost::timer::cpu_timer timer, plottime;
	unsigned int number_of_times = 1;	//For reporting average time
	unsigned int lp_solver_type = 1;	// choose the glpk solver
	timer.start();
	init_cpu_usage(); //initializing the CPU Usage utility to start recording usages
	for (unsigned int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result
		// Calls the reachability computation routine.
		reachabilityCaller(ha, init, reach_params, userOps, lp_solver_type, forbidden, symbolic_states, ce_candidates);
	}
	timer.stop();
	double cpu_usage = getCurrent_ProcessCPU_usage();
	long mem_usage = getCurrentProcess_PhysicalMemoryUsed();
	print_statistics(timer,cpu_usage,mem_usage, number_of_times, "Reachability Analysis and CE Search");


	// Choosing from the output format and showing results

	if(ha.ymap_size()!=0){
		//transform the sfm to output directions before plotting
		std::list<symbolic_states::ptr>::iterator it =  symbolic_states.begin();
		for(;it!=symbolic_states.end(); it++){
			symbolic_states::ptr symbStatePtr = *it;
			transformTemplatePoly(ha, symbStatePtr->getContinuousSetptr());
		}
	}

/*	plottime.start();
	show(symbolic_states, userOps);
	plottime.stop();
	print_statistics(plottime,"Plotting");

	// printing the first initial polytope in the init_poly file
	polytope::ptr init_poly = (*init.begin())->getInitialSet();
	init_poly->print2file("./init_poly",userOps.get_first_plot_dimension(),userOps.get_second_plot_dimension());
	*/

}
void themeSelector::selectSim(){
	std::cout << "Running simulation engine ... \n";
	assert(forbidden.size() > 0);
	simulationCaller(ha, init, reach_params, forbidden[0], userOps);
}
void themeSelector::selectFal(){
	//todo: call the path-oriented falsification routine.
}

void themeSelector::select(){

	// ----Selects trajectory simulation
	if (boost::algorithm::iequals(userOps.getEngine(),"simu")==true) {
		selectSim();
		return;
	}

	// Select reachability with CE generation
	if(boost::algorithm::iequals(userOps.getEngine(),"reach")==true){
		selectReach();
		return;
	}

	//select falsification
	if(boost::algorithm::iequals(userOps.getEngine(),"fal")==true){
		selectFal();
		return;
	}

	// ----Section for Running Exp-Graph. This code is put only for experimental task.
	int	 runExpGraph_WoFC = 0;	// To run Exp-Graph Algorithm, that is, Explore the Graph, we should assign a valid loc-id in the forbidden set (and not -1, unlike FC algo)
	if (runExpGraph_WoFC) {
		bool found_CE = runWoFC_counter_example(ha, init, forbidden[0], userOps);

		if (found_CE) {
			string cmdStr1;
			//cmdStr1.append("graph -TX -BC -W 0.008 out.txt -s -m 3 bad_poly -s -m 2 init_poly");
			//cmdStr1.append("graph -TX -BC -W 0.008 out.txt");
			system(cmdStr1.c_str());
		}
		return;
	}
	//End of Section Exp-Graph.

}
themeSelector::~themeSelector() {
	// TODO Auto-generated destructor stub
}

