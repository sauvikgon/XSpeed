/*
 * concreteCE.cpp
 *
 *  Created on: 20-Jan-2016
 *      Author: rajarshi
 */

#include <counterExample/concreteCE.h>
#include <cassert>

concreteCE::concreteCE() {
	// TODO Auto-generated constructor stub

}

concreteCE::~concreteCE() {
	// TODO Auto-generated destructor stub
}

const concreteCE::traj_segment concreteCE::get_segment(unsigned int i) const {
	assert(i < T.size());
	std::list<traj_segment>::const_iterator it = T.begin();
	for (unsigned int k = 0; k != i; k++) {
		it++;
	}
	return *it;

}
const concreteCE::trans_id concreteCE::getTransitionId(unsigned int i) const {
	assert(i < jumps.size());
	std::list<trans_id>::const_iterator it = jumps.begin();
	for (unsigned int k = 0; k != i; k++) {
		it++;
	}
	return *it;
}
void concreteCE::plot_ce(std::string filename, unsigned int x1, unsigned int x2)
{
	traj_segment seg;
	unsigned int locId;
	sample simulation_sample;
	simulation::ptr sim;
	std::cout << "Inside concrete trace plotter, no. of trajectory segs:" << T.size() << std::endl;
	double time_step = 0.1;
	//debug
	//printing the trace start point in a different file for plotting with distinguishible symbol
	std::ofstream myfile;
	myfile.open("./start_pts");
	//--
	for(trajectory::iterator it = T.begin(); it!=T.end();it++){
		seg = *it;
		locId = seg.first;
		simulation_sample = seg.second;
		sim = simulation::ptr(new simulation(simulation_sample.first.size(),time_step,ha->getLocation(locId)->getSystem_Dynamics()));
		sim->set_outfile(filename);
		sim->set_out_dimension(x1, x2);
		std::cout << "simulation: start point:" << std::endl;
	//	for(unsigned int i=0;i<sim->get_system_dimension();i++)
		myfile << simulation_sample.first[2] << " " << simulation_sample.first[0];

	//  std::cout << "simulation: dwell time:" << simulation_sample.second;
		sim->simulate(simulation_sample.first, simulation_sample.second);
	}
	myfile.close();
}
