/*
 * dump_abstfractCE_list.cpp
 *
 *  Created on: 29-Aug-2016
 *      Author: rajarshi
 */

#include <utilities/dumpAbstractCEList.h>
#include <fstream>

void dump_abstractCE_list(std::list<abstractCE::ptr> ce_list)
{
	std::ofstream dumpfile;
	dumpfile.open("./trace_dump.o");
	abstractCE::ptr ce;
	std::list<symbolic_states::ptr> absCE;
	for (std::list<abstractCE::ptr>::iterator it = ce_list.begin(); it!=ce_list.end();it++) {
		ce = *(it);
		absCE = ce->get_CE_sym_states();

		for(std::list<symbolic_states::ptr>::const_iterator it1 = absCE.begin(); it1!=absCE.end(); it1++){
			discrete_set d = (*it1)->getDiscreteSet();
			dumpfile << *(d.getDiscreteElements().begin()) << " ";
		}
		dumpfile << "\n";
	}
	dumpfile.close();
};

