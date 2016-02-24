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
void concreteCE::plot_ce(std::string filename)
{
	traj_segment seg;
	unsigned int locId;
	sample simulation_sample;
	simulation::ptr sim;
	std::cout << "Inside concrete trace plotter, no. of trajectory segs:" << T.size() << std::endl;
	unsigned int num_samples = 1000;
	for(trajectory::iterator it = T.begin(); it!=T.end();it++){
		seg = *it;
		locId = seg.first;
		simulation_sample = seg.second;
		sim = simulation::ptr(new simulation(simulation_sample.first.size(),num_samples,ha->getLocation(locId).getSystem_Dynamics()));
		sim->set_outfile(filename);
		sim->set_out_dimension(0);
		std::cout << "simulation: first:" << simulation_sample.second;
		for(unsigned int i=0;i<sim->get_system_dimension();i++)
			std::cout << simulation_sample.first[i] << " ";
		std::cout << "simulation: second:" << simulation_sample.second;
		sim->simulate(simulation_sample.first, simulation_sample.second);
	}
}
