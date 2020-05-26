
//**************** Hybrid Automata Definition ***********************
#include <application/macroDefinitions.h>
#include <application/plotterUtility.h>
#include <boost/program_options/config.hpp>
#include "boost/program_options.hpp"
#include <boost/config.hpp>
#include <boost/program_options/detail/config_file.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/algorithm/string.hpp>
#include <io/ioUtility.h>
#include <io/loadModel.h>
#include "../io/parser.h"
// *********** Command Line Boost Program Options ********
#include "counterExample/concreteCE.h"

#include "reachabilityCaller.h"
#include "application/reachabilityCaller.h"

#ifndef APPLICATION_READCOMMANDLINE_H_
#define APPLICATION_READCOMMANDLINE_H_

void readCommandLine(int argc, char *argv[], userOptions& user_options,
		hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters,
		std::pair<int, polytope::ptr>& forbidden_set);

#endif /* APPLICATION_READCOMMANDLINE_H_ */

