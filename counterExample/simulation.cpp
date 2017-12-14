/*
 * simulation.cpp
 *
 *  Created on: 12-Feb-2016
 *      Author: Rajarshi
 */

#include "counterExample/simulation.h"
#include <fstream>
#include <iomanip>
#include "../core_system/continuous/Polytope/Polytope.h"

simulation::simulation() {
	// TODO Auto-generated constructor stub

}

simulation::~simulation() {
	// TODO Auto-generated destructor stub
}

/* Private function to check function return values */

static int check_flag(void *flagvalue, const char *funcname, int opt);

static int f(realtype t, N_Vector y, N_Vector ydot, void *f_data)
{
	Dynamics* D = (Dynamics *)(f_data);
	math::matrix<double> A;

	if(D->isEmptyMatrixA)
	{
		assert(!D->isEmptyC); // The assumption is that this function is called with non-zero dynamics.
		unsigned int dim = D->C.size();
		A = math::matrix<double>(D->C.size(),D->C.size());
		for(unsigned int i=0;i<dim;i++)
			for(unsigned int j=0;j<dim;j++)
				A(i,j)=0;
	}
	else
		A = math::matrix<double>(D->MatrixA);

	std::vector<double> C(A.size1());

	assert(A.size1() == A.size2());
	C = D->C;

	double sum;
	// Input set not included in the dynamics.

	for(unsigned int i=0;i<A.size1();i++){
		sum=0;
		for(unsigned int j=0;j<A.size2();j++){
			sum += A(i,j)*NV_Ith_S(y,j);
		}
		NV_Ith_S(ydot,i) = sum + C[i];
	}
	return 0;
}

std::vector<double> lin_interpolate(std::vector<double> x_l2, std::vector<double> x_l1, double factor)
{
	assert(x_l1.size() == x_l2.size());
	std::vector<double> res(x_l1.size());
	for(unsigned int i=0;i<x_l1.size();i++)
		res[i] = factor*x_l2[i] + x_l1[i]*(1-factor);
	return res;
}
std::vector<double> simulation::simulate(std::vector<double> x, double time)
{
	int flag;
	realtype T0 = 0;
	realtype Tfinal = time;
	realtype t=0;
	N=time/time_step;
	Dynamics *data = &D;

	N_Vector u = NULL;

	if(data->isEmptyMatrixA && data->isEmptyC) // zero dynamics
		return x; // return same initial point

	assert(x.size() == dimension);
	u = N_VNew_Serial(dimension);

	for(unsigned int i=0;i<dimension;i++)
		NV_Ith_S(u,i) = x[i];

	void *cvode_mem;
	cvode_mem = NULL;
	/* Call CVodeCreate to create the solver memory and specify the
	 * Backward Differentiation Formula and the use of a Newton iteration */

	cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);

	if( check_flag((void *)cvode_mem, "CVodeCreate", 0))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	/** Input user data */
	CVodeSetUserData(cvode_mem, (void *)data);
	/* Call CVodeInit to initialize the integrator memory and specify the
	* user's right hand side function in u'=f(t,u), the inital time T0, and
	* the initial dependent variable vector u. */

	flag = CVodeInit(cvode_mem, f, T0, u);

	if(check_flag(&flag, "CVodeInit", 1)){
		throw std::runtime_error("CVODE failed\n");
	}

	flag = CVDense(cvode_mem, dimension);
	if (check_flag(&flag, "CVDense", 1))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	 /* Call CVodeSStolerances to specify the scalar relative tolerance
	  * and scalar absolute tolerance */
	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	/* In loop over output points: call CVode, print results, test for errors */

	std::vector<double> last(dimension);

	trace_point simpoint;
	simpoint.first = 0;
	simpoint.second = x;
	sim_trace.push_back(simpoint); // adding the starting simpoint in the sim_trace data-structure.

	for(unsigned int k=1;k<=N;k++) {
		double tout = (k*Tfinal)/N;
		// remember this point in the last vector
		for(unsigned int i=0;i<dimension;i++)
			last[i] = NV_Ith_S(u,i);
		trace_point simpoint;
		simpoint.first = tout;
		simpoint.second = last;
		sim_trace.push_back(simpoint); // adding the simpoint in the sim_trace data-structure.

		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
		if(check_flag(&flag, "CVode", 1)) break;
	}

	std::vector<double> res(dimension);
	for(unsigned int i=0;i<dimension;i++)
	{
		res[i] = NV_Ith_S(u,i);
	}
	N_VDestroy_Serial(u); /* Free u vector */
	CVodeFree(&cvode_mem); /* Free integrator memory */

	return res;
}

/**
 * Bounded simulation. Simulation bounded within a polytope.
 * Sets status to false if invariant violated. Otherwise,
 * status is set to true.
 * If the Inv is violated with distance < tol, tolerate the
 * violation.
 */

bound_sim simulation::bounded_simulation(std::vector<double> x, double time, polytope::ptr I, bool& status, double tol)
{
	int flag;
	realtype T0 = 0;
	realtype Tfinal = time;
	realtype t=0;
	Dynamics *data = &D;
	bound_sim b;
	N_Vector u = NULL;
	N = Tfinal/time_step;

	if(data->isEmptyMatrixA && data->isEmptyC){ // zero dynamics
		bound_sim b;
		b.v=x;
		b.cross_over_time = time; // The point remains inside the invariant for the entire time horizon
		return b; // return the initial point, time horizon

	}

	assert(x.size() == dimension);
	u = N_VNew_Serial(dimension);

	double dist = math::abs(I->point_distance(x));
	if(dist > tol ){
		//throw std::runtime_error("bounded simulation: initial point outside invariant. NLP problem constrains not set correctly\n");
		bound_sim b;
		b.v = x;
		b.cross_over_time = 0;
		status = false;
		return b;
	}
	// Add the starting point to the sim_trace otherwise here
	trace_point simpoint;
	simpoint.first = 0;
	simpoint.second = x;
	sim_trace.push_back(simpoint); // adding the starting simpoint in the sim_trace data-structure.

	for(unsigned int i=0;i<dimension;i++)
		NV_Ith_S(u,i) = x[i];

	void *cvode_mem;
	cvode_mem = NULL;
	// Call CVodeCreate to create the solver memory and specify the
	// Backward Differentiation Formula and the use of a Newton iteration

	cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);

	if( check_flag((void *)cvode_mem, "CVodeCreate", 0))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	// Input user data
	CVodeSetUserData(cvode_mem, (void *)data);

	// Call CVodeInit to initialize the integrator memory and specify the
	//ser's right hand side function in u'=f(t,u), the inital time T0, and
	// the initial dependent variable vector u.

	flag = CVodeInit(cvode_mem, f, T0, u);

	if(check_flag(&flag, "CVodeInit", 1)){
		throw std::runtime_error("CVODE failed\n");
	}

	flag = CVDense(cvode_mem, dimension);
	if (check_flag(&flag, "CVDense", 1))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	std::vector<double> v(dimension),prev_v(dimension);
	prev_v = x;

	for(unsigned int k=1;k<=N;k++) {
		double tout = (k*Tfinal)/N;
		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
		if(check_flag(&flag, "CVode", 1)) break;
		// check polytope satisfaction
		for(unsigned int i=0;i<dimension;i++)
			v[i] = NV_Ith_S(u,i);

		double dist = I->point_distance(v);
		if(math::abs(dist) > tol) {
//				std::cout << "time:" << t << " ";
			std::cout << "DISTANCE TO INV= " << std::setprecision(10) << dist << std::endl;
			std::cout << "tol = " << std::setprecision(10) << tol << std::endl;
			status = false;
			break;
		}
		else{
			trace_point simpoint;
			simpoint.first = tout;
			simpoint.second = v;
			sim_trace.push_back(simpoint); // adding the simpoint in the sim_trace data-structure.
			prev_v = v;
		}
	}
	b.v = v;
	b.cross_over_time = t;

	N_VDestroy_Serial(u);
	CVodeFree(&cvode_mem);
	return b;
}

std::vector<double> simulation::metric_simulate(std::vector<double> x, double time,
		double& distance, polytope::ptr I, std::vector<double>& grad)
{
	int flag;
	realtype T0 = 0;
	realtype Tfinal = time;
	realtype t=0;
	Dynamics *data = &D;
	N=Tfinal/time_step;

	N_Vector u = NULL;

	if(data->isEmptyMatrixA && data->isEmptyC) // zero dynamics
		return x; // return same initial point

	assert(x.size() == dimension);
	u = N_VNew_Serial(dimension);

	assert(grad.size() == dimension);
	// initialize

	for(unsigned int i=0;i<dimension;i++){
		NV_Ith_S(u,i) = x[i];
		grad[i] = 0;
	}
	void *cvode_mem;
	cvode_mem = NULL;
	// Call CVodeCreate to create the solver memory and specify the
	// Backward Differentiation Formula and the use of a Newton iteration

	cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);

	if( check_flag((void *)cvode_mem, "CVodeCreate", 0))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	// Input user data
	CVodeSetUserData(cvode_mem, (void *)data);

	// Call CVodeInit to initialize the integrator memory and specify the
	//ser's right hand side function in u'=f(t,u), the inital time T0, and
	// the initial dependent variable vector u.

	flag = CVodeInit(cvode_mem, f, T0, u);

	if(check_flag(&flag, "CVodeInit", 1)){
		throw std::runtime_error("CVODE failed\n");
	}

	flag = CVDense(cvode_mem, dimension);
	if (check_flag(&flag, "CVDense", 1))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1))
	{
		throw std::runtime_error("CVODE failed\n");
	}

	//printing simulation trace in a file for debug purpose, in the plot_dim dimension

	std::vector<double> v(dimension);

	math::matrix<double> expAt;
	std::vector<double> g(dimension);
	distance=0;
	for(unsigned int k=1;k<=N;k++) {
		double tout = (k*Tfinal)/N;
		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
		if(check_flag(&flag, "CVode", 1)) break;
		// check polytope satisfaction
		for(unsigned int i=0;i<dimension;i++)
			v[i] = NV_Ith_S(u,i);

		trace_point simpoint;
		simpoint.first = tout;
		simpoint.second = v;
		sim_trace.push_back(simpoint); // adding the simpoint in the sim_trace data-structure.

		distance += I->point_distance(v);
	}
	N_VDestroy_Serial(u);
	CVodeFree(&cvode_mem);
	return v;
}

/**
 * Computes the simulation trace inside the location of a ha, from the given start point and for the give time duration.
 * Returns the set of new start points which are valid for starting new simulation from the new location of the ha.
 */
std::vector<sim_start_point> simulation::simulateHaLocation(sim_start_point start_point, double start_time, double tot_time, hybrid_automata& ha)
{
	int flag;
	realtype t=start_time, T0 = 0;
	realtype Tfinal = tot_time - start_time;
	N = Tfinal/time_step;
	double tout1 = start_time;  //New Start Time for new simulation

	Dynamics Dyn = start_point.locptr->getSystem_Dynamics();

	std::vector<double> x = start_point.start_point;

	// Check if zero dynamics. No need to simulate then.
	if (Dyn.isEmptyMatrixA && Dyn.isEmptyC) {
		std::cout << "A location with empty dynamics reached\n";
		std::vector<sim_start_point> emptylist;
		return emptylist;
	}

	std::vector<sim_start_point> new_start_points;

	//List of intersected polytope
	std::list<eligibleTransition> etrans_list;


	location::ptr loc = start_point.locptr;
	polytope::ptr inv = loc->getInvariant();

	//Computing guard-invariant intersection and bloating the set with time-step

	std::list<transition::ptr> outgoingtrans;
	outgoingtrans = loc->getOut_Going_Transitions();
	for (std::list<transition::ptr>::iterator it = outgoingtrans.begin();
			it != outgoingtrans.end(); it++) {

		eligibleTransition trans;
		polytope::ptr g = (*it)->getGaurd();
		polytope::ptr inv_g_intersection = inv->GetPolytope_Intersection(g);
		std::vector<double> poly_bounds = inv_g_intersection->getColumnVector();

		for (unsigned int i = 0; i < inv_g_intersection->getColumnVector().size(); i++) {
			poly_bounds[i] = poly_bounds[i] + this->time_step; // minkowski sum for bloating the guard \cap invariant set. Does not solve the purpose rightly
		}

		inv_g_intersection->setColumnVector(poly_bounds);

		trans.inv_g_intersection = inv_g_intersection;
		trans.trans = *it;

		etrans_list.push_back(trans);
	}

	double tol_inv = 1e-10;

	dimension = x.size();
	//cout << "Iteration Remaining" << N << "\n";

	reltol = 1e-8;
	abstol = 1e-8;

	assert(x.size() == dimension);

	N_Vector u = N_VNew_Serial(dimension);

	double dist = math::abs(inv->point_distance(x));
	if (dist > tol_inv) {
		std::vector<sim_start_point> emptylist;
		return emptylist;
	};

	for (unsigned int i = 0; i < dimension; i++)
		NV_Ith_S(u,i) = x[i];

	void *cvode_mem;
	cvode_mem = NULL;

	// Call CVodeCreate to create the solver memory and specify the
	// Backward Differentiation Formula and the use of a Newton iteration
	cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);
	if (check_flag((void *) cvode_mem, "CVodeCreate", 0)) {
		throw std::runtime_error("CVODE failed\n");
	}

	// Input user data
	CVodeSetUserData(cvode_mem, (void *) &Dyn);

	// Call CVodeInit to initialize the integrator memory and specify the
	// user's right hand side function in u'=f(t,u), the inital time T0, and
	// the initial dependent variable vector u.
	flag = CVodeInit(cvode_mem, f, T0, u);

	if (check_flag(&flag, "CVodeInit", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}
	flag = CVDense(cvode_mem, dimension);
	if (check_flag(&flag, "CVDense", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}
	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}


	std::vector<double> v(dimension);
	v = x;

	// add the initial point to to the trace:
	trace_point simpoint;
	simpoint.first = 0;
	simpoint.second = x;
	sim_trace.push_back(simpoint); // adding the simpoint in the sim_trace data-structure.
	//-------------------

	for (unsigned int k = 1; k <= N; k++) {

		double tout = k * (Tfinal / N);
		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
		if (check_flag(&flag, "CVode", 1)){
			cout<<"Start time = "<< t <<"  Total Time = "<<Tfinal<<" Value of tout = "<<tout<<endl;
			break;
		}

		for (unsigned int i = 0; i < dimension; i++)
			v[i] = NV_Ith_S(u, i);

		for (std::list<eligibleTransition>::iterator it = etrans_list.begin();
				it != etrans_list.end(); it++) {
			polytope::ptr p = it->inv_g_intersection;
			double dist = p->point_distance(v);

			if (dist == 0) { //just intersected the guard
				sim_start_point w;
				int locID = it->trans->getDestination_Location_Id();
				location::ptr loc = ha.getLocation(locID);

				w.locptr = loc;
				w.cross_over_time = tout1 + tout;

				//Now assignment operation of the transition to be performed
				std::vector<double> mapped_point;

				mapped_point = it->trans->applyTransitionMap(v);
				w.start_point = mapped_point;
				polytope::ptr new_inv = w.locptr->getInvariant();

				double dist1 = new_inv->point_distance(w.start_point);
				if (dist1==0) // the new point is within the invariant of the new location
				{
					// In the urgent semantics, only the first guard intersecting point is added for further simulation
					new_start_points.push_back(w);
					break;
				}
			}
		} // end of for loop

		// Add the point to the sim_trace because it does not intersect with the guard yet
		if(new_start_points.size()>0) // stop simulation since the next simulation point is found.
			break;
		else{
			trace_point simpoint;
			simpoint.first = tout;
			simpoint.second = v;
			sim_trace.push_back(simpoint);
		}

		//Checking validity of the trace
		double dist = inv->point_distance(v);

		if (math::abs(dist) > tol_inv)
			break;
	}

	N_VDestroy_Serial(u);
	CVodeFree(&cvode_mem);
	return new_start_points;
}

/**
 * Routine to print the simulation trace to a output file.
 */
void simulation::print_trace_to_outfile(std::string s){
	std::ofstream myoutfile;
	myoutfile.open(s.c_str());
	for(std::list<trace_point>::const_iterator it = sim_trace.begin(); it!=sim_trace.end(); it++)
	{
		myoutfile << (*it).second[this->x1] << "  " << (*it).second[this->x2] << "\n";
	}
	myoutfile.close();
}

/*
//Golbal Simulation of Hybrid automaton

/**
 * Returns a set of random simulation start points from the given initial set (hyperbox)
 */

/*
std::vector<sim_start_point> simulation::get_random_starts(polytope::ptr initialset, double gtime, hybrid_automata& ha) {

	int i, j, rowSize, columnSize, boundSize, randnumber;
	math::matrix<double> Matrix;


	Matrix = initialset->getCoeffMatrix();
	rowSize = Matrix.size1();
	columnSize = Matrix.size2();
	boundSize = initialset->getColumnVector().size();

	double coefficient[rowSize][columnSize], bound[boundSize];
	for (i = 0; i < rowSize; i++) //Assign Coefficient Matrix
			{
		for (j = 0; j < columnSize; j++) {
			coefficient[i][j] = Matrix(i, j);
		}
	}

	for (i = 0; i < boundSize; i++) //Assign bound Matrix
			{
		bound[i] = initialset->getColumnVector()[i];
	}
	int countmatrix[columnSize];
	for (i = 0; i < columnSize; i++) {
		countmatrix[i] = 0;
	}
	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < columnSize; j++) {
			if (coefficient[i][j] != 0) {
				countmatrix[j] = countmatrix[j] + 1;
			}
		}
	}

	double A[boundSize][3];
	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < columnSize; j++) {
			if (coefficient[i][j] != 0) {
				A[i][0] = coefficient[i][j];
			}
		}
		A[i][1] = bound[i];
		A[i][2] = 1;
	}
	for (i = 0; i < boundSize; i++) {
		for (j = 0; j < 3; j++) {
			if (A[i][0] < 0) {
				A[i][0] = A[i][0] * (-1);
				A[i][1] = A[i][1] * (-1);
				A[i][2] = 0;
			}
		}
	}
	cout << "Enter number of random points" << endl;
	cin >> randnumber;
	//randnumber=5;
	double random[randnumber][columnSize], Minf, Maxf, randarray[randnumber];
	int count = 0;
	for (i = 0; i < columnSize; i++) {
		if (countmatrix[i] == 2) {
			if (A[count][2] == 0 && A[count + 1][2] == 1) {
				Minf = A[count][1];
				Maxf = A[count + 1][1];
			}
			if (A[count][2] == 1 && A[count + 1][2] == 0) {
				Minf = A[count + 1][1];
				Maxf = A[count][1];
			}
			count = count + 2;
			randassign(Minf, Maxf, randarray, randnumber, i);
		}
		for (j = 0; j < randnumber; j++) {
			random[j][i] = randarray[j];
		}
	}
	for (i = 0; i < randnumber; i++) {
		for (j = 0; j < columnSize; j++) {
			cout << random[i][j] << " ";
		}
		cout << endl;
	}
	std::vector<double> v(columnSize);
	std::vector<waitingList_sim> newLoctionList;
	for (i = 0; i < randnumber; i++) {
		for (j = 0; j < columnSize; j++) {
			v[j] = random[i][j];
			//cout << v[j] << " ";
		}
		waitingList_sim w;
		w.newLoc = loc;
		w.time_NewPoint.cross_over_time = 0;
		w.time_NewPoint.v = v;
		w.gtime = gtime;
		newLoctionList.push_back(w);
	}
	return newLoctionList;
}
*/

/* Check function return value...
     opt == 0 means SUNDIALS function allocates memory so check if
              returned NULL pointer
     opt == 1 means SUNDIALS function returns a flag so check if
              flag >= 0
     opt == 2 means function allocates memory so check if returned
              NULL pointer */

static int check_flag(void *flagvalue, const char* funcname, int opt)
{
  int *errflag;

  /* Check if SUNDIALS function returned NULL pointer - no memory allocated */

  if (opt == 0 && flagvalue == NULL) {
    fprintf(stderr, "\nSUNDIALS_ERROR: %s() failed - returned NULL pointer\n\n",
            funcname);
    return(1); }

  /* Check if flag < 0 */

  else if (opt == 1) {
    errflag = (int *) flagvalue;
    if (*errflag < 0) {
      fprintf(stderr, "\nSUNDIALS_ERROR: %s() failed with flag = %d\n\n",
              funcname, *errflag);
      return(1);
    }
  }

  /* Check if function returned NULL pointer - no memory allocated */

  else if (opt == 2 && flagvalue == NULL) {
    fprintf(stderr, "\nMEMORY_ERROR: %s() failed - returned NULL pointer\n\n",
            funcname);
    return(1);
  }

  return(0);
}
