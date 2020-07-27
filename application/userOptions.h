/*
 * userOptions.h
 *
 *  Created on: 09-May-2016
 *      Author: rajarshi
 */

#ifndef USEROPTIONS_H_
#define USEROPTIONS_H_

#include <cstring>
#include <iostream>

class userOptions {
	std::string model_filename; // filename of the automata model .xml file
	std::string config_filename; // filename of the configuration file .cfg
	std::string forbidden_state; // the string of forbidden states description
	std::string out_filename; // The output filename
	std::string output_format_type; // the string of output format description

	std::string set_aggregation; // The aggregation options thull(default), none
	std::string Engine; // The Engine options supp(default), simu
	std::string ce_procedure; // the algorithm choice for searching a counterexample

	unsigned int simu_algo;	//Algorithm choice for running Trajectory Simulation
	unsigned int simu_init_points; //Number of start-points for Simulation Algorithm

	unsigned int output_var_X; // first  dimension for plotting
	unsigned int output_var_Y; // second dimension for plotting
	unsigned int output_var_Z; // third dimension for plotting

	unsigned int model; // name of the pre-defined model to run for reachability.
	unsigned int direction_template; // template used for approximating support functions

	double time_horizon; // time horizon for reachability

	double time_step; // the time step of the support function algorithm
	unsigned int level; // the breadth level in bfs to stop reachability

	unsigned int algo;	//Common arg for all types of Algorithm
	unsigned int total_slice_size;	//total number of partition-size or number of slices
	unsigned int stream_size;	//total number of streams selected for GPU streaming
	bool ce_flag; // This flag is set to true if --CE option is given by the user.
	std::string ce_path; 	// A counter-example to forbidden state will be searched in the specified path, which is a comma separated list of location ids.

public:
	userOptions();
	virtual ~userOptions();

	std::string get_modelFile();
	void set_modelFile(std::string modefile);
	std::string get_configFile();
	void set_configFile(std::string configfile);
	unsigned int get_first_plot_dimension();
	void set_first_plot_dimension(unsigned int outdim);
	unsigned int get_second_plot_dimension();
	void set_second_plot_dimension(unsigned int outdim);
	unsigned int get_third_plot_dimension();
	void set_third_plot_dimension(unsigned int outdim);

	double get_timeStep();
	void set_timeStep(double t);
	double get_timeHorizon();
	void set_timeHorizon(double timeHorizon);
	unsigned int get_model();
	void set_model(unsigned int m);
	unsigned int get_directionTemplate();
	void set_directionTemplate(unsigned int d);
	unsigned int get_bfs_level();
	void set_bfs_level(unsigned int l);
	std::string get_forbidden_set();
	void set_forbidden_set(std::string);

	unsigned int get_algorithm();	//returns the selected Algorithm
	void set_algorithm(unsigned int alg);	//assigns the Algorithm selected by the user

	unsigned int get_simu_algo();	//returns the selected simulation Algorithm
	void set_simu_algo(unsigned int alg);	//assigns the simulation Algorithm selected by the user

	unsigned int getStreamSize() const;
	void setStreamSize(unsigned int streamSize);
	unsigned int getTotalSliceSize() const;
	void setTotalSliceSize(unsigned int totalSliceSize);
	const std::string& getOutputFormatType() const;
	void setOutputFormatType(const std::string& outputFormatType);
	const std::string& getOutFilename() const;
	void setOutFilename(const std::string& outFilename);
	const std::string& getSetAggregation() const;
	void setSetAggregation(const std::string& engine);
	const std::string& getEngine() const;
	void setEngine(const std::string& engine);

	void setCEProc(const std::string& ceproc);
	std::string& getCEProc();

	unsigned int get_simu_init_points();
	void set_simu_init_points(unsigned int sampling_points);

	/* This is the path to search for a concrete trajectory to a specified forbidden state */
	std::string get_ce_path();
	void set_ce_path(std::string path);

	/* This is the flag to trigger a search to a counter-example trajectory to a specified forbidden state */
	void set_ce_flag(bool value);
	bool get_ce_flag();

};

#endif /* USEROPTIONS_H_ */
