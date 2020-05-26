/*
 * simulation.cpp
 *
 *  Created on: 12-Feb-2016
 *      Author: Rajarshi
 */

#include <utilities/dbgMsgLogger.h>
#include "counterExample/simulation.h"
#include <fstream>
#include <iomanip>
#include "core/continuous/polytope/polytope.h"



simulation::simulation() {
	// TODO Auto-generated constructor stub
}

simulation::~simulation() {
	// TODO Auto-generated destructor stub
}

/* Private function to check function return values */

static int check_flag(void *flagvalue, const char *funcname, int opt);

static int jtv (realtype t, N_Vector y, N_Vector fy, SUNMatrix Jac,
                void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);

static int f(realtype t, N_Vector y, N_Vector ydot, void *f_data) {
	Dynamics* D = (Dynamics *) (f_data);
	math::matrix<double> A;

	if (D->isEmptyMatrixA) {
		assert(!D->isEmptyC); // The assumption is that this function is called with non-zero dynamics.
		unsigned int dim = D->C.size();
		A = math::matrix<double>(D->C.size(), D->C.size());
		for (unsigned int i = 0; i < dim; i++)
			for (unsigned int j = 0; j < dim; j++)
				A(i, j) = 0;
	} else
		A = math::matrix<double>(D->MatrixA);

	std::vector<double> C(A.size1());

	assert(A.size1() == A.size2());
	C = D->C;

	double sum;
	// Input set not included in the dynamics.

	for (unsigned int i = 0; i < A.size1(); i++) {
		sum = 0;
		for (unsigned int j = 0; j < A.size2(); j++) {
			sum += A(i, j) * NV_Ith_S(y,j) ;
		}
		NV_Ith_S(ydot,i) = sum + C[i];
	}
	return 0;
}

std::vector<double> lin_interpolate(std::vector<double> x_l2,
		std::vector<double> x_l1, double factor) {
	assert(x_l1.size() == x_l2.size());
	std::vector<double> res(x_l1.size());
	for (unsigned int i = 0; i < x_l1.size(); i++)
		res[i] = factor * x_l2[i] + x_l1[i] * (1 - factor);
	return res;
}
std::vector<double> simulation::simulate(std::vector<double> x, double time) {

	int flag;
	realtype T0 = 0;
	realtype Tfinal = time;
	realtype t = 0;
	N = time / time_step;
	Dynamics *data = &D;

	N_Vector u = NULL;

	if (data->isEmptyMatrixA && data->isEmptyC) // zero dynamics
		return x; // return same initial point

	assert(x.size() == dimension);
	u = N_VNew_Serial(dimension);

	for (unsigned int i = 0; i < dimension; i++)
		NV_Ith_S(u,i) = x[i];

	void *cvode_mem;
	cvode_mem = NULL;
	/* Call CVodeCreate to create the solver memory and specify the
	 * Backward Differentiation Formula and the use of a Newton iteration */

	cvode_mem = CVodeCreate(CV_BDF);

	if (check_flag((void *) cvode_mem, "CVodeCreate", 0)) {
		throw std::runtime_error("CVODE failed\n");
	}

	/** Input user data */
	CVodeSetUserData(cvode_mem, (void *) data);
	/* Call CVodeInit to initialize the integrator memory and specify the
	 * user's right hand side function in u'=f(t,u), the inital time T0, and
	 * the initial dependent variable vector u. */

	flag = CVodeInit(cvode_mem, f, T0, u);

	if (check_flag(&flag, "CVodeInit", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}

	/* Call CVodeSStolerances to specify the scalar relative tolerance
	 * and scalar absolute tolerance */
	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}

	// Create Matrix Object.
	// ---------------------------------------------------------------------------
	// Need to create a dense matrix for the dense solver.
	SUNMatrix A = SUNDenseMatrix(dimension, dimension);
	if(check_flag((void *)A, "SUNDenseMatrix", 0)){
		throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 9. Create Linear Solver Object.
	// ---------------------------------------------------------------------------
	// Dense linear solver object instead of the iterative one in the original
	// simple example.
	SUNLinearSolver LS = SUNDenseLinearSolver(u, A) ;
	if(check_flag((void *)LS, "SUNDenseLinearSolver", 0)){
	  throw std::runtime_error("In simulation::simulate, SUNDenseLinearSolver: CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 10. Set linear solver optional inputs.

	// 11. Attach linear solver module.
	// ---------------------------------------------------------------------------
	// Call CVDlsSetLinearSolver to attach the matrix and linear solver this
	// function is different for direct solvers.
	flag = CVDlsSetLinearSolver(cvode_mem, LS, A);
	if(check_flag(&flag, "CVDlsSetLinearSolver", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 12. Set linear solver interface optional inputs.
	// ---------------------------------------------------------------------------
	// Sets the jacobian-times-vector function.
	flag = CVDlsSetJacFn(cvode_mem, jtv);
	if(check_flag(&flag, "CVDlsSetJacFn", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}
	/* In loop over output points: call CVode, print results, test for errors */

	std::vector<double> last(dimension);

	trace_point simpoint;
	simpoint.first = 0;
	simpoint.second = x;
	sim_trace.push_back(simpoint); // adding the starting simpoint in the sim_trace data-structure.

	for (unsigned int k = 1; k <= N; k++) {
		double tout = (k * Tfinal) / N;
		// remember this point in the last vector
		for (unsigned int i = 0; i < dimension; i++)
			last[i] = NV_Ith_S(u,i) ;
		trace_point simpoint;
		simpoint.first = tout;
		simpoint.second = last;
		sim_trace.push_back(simpoint); // adding the simpoint in the sim_trace data-structure.

		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
		if (check_flag(&flag, "CVode", 1))
			break;
	}

	std::vector<double> res(dimension);
	for (unsigned int i = 0; i < dimension; i++) {
		res[i] = NV_Ith_S(u,i) ;
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

bound_sim simulation::bounded_simulation(std::vector<double> x, double time,
		polytope::ptr I, bool& status, double tol) {

	int flag;
	realtype T0 = 0;
	realtype Tfinal = time;
	realtype t = 0;
	Dynamics *data = &D;
	bound_sim b;
	N_Vector u = NULL;
	N = Tfinal / time_step;

	if (data->isEmptyMatrixA && data->isEmptyC) { // zero dynamics
		bound_sim b;
		b.v = x;
		b.cross_over_time = time; // The point remains inside the invariant for the entire time horizon
		return b; // return the initial point, time horizon

	}

	assert(x.size() == dimension);
	u = N_VNew_Serial(dimension);

	double dist = math::abs(I->point_distance(x));
	if (dist > tol) {
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

	for (unsigned int i = 0; i < dimension; i++)
		NV_Ith_S(u,i) = x[i];

	void *cvode_mem;
	cvode_mem = NULL;
	// Call CVodeCreate to create the solver memory and specify the
	// Backward Differentiation Formula and the use of a Newton iteration

	cvode_mem = CVodeCreate(CV_BDF);

	if (check_flag((void *) cvode_mem, "CVodeCreate", 0)) {
		throw std::runtime_error("CVODE failed\n");
	}

	// Input user data
	CVodeSetUserData(cvode_mem, (void *) data);

	// Call CVodeInit to initialize the integrator memory and specify the
	//ser's right hand side function in u'=f(t,u), the inital time T0, and
	// the initial dependent variable vector u.

	flag = CVodeInit(cvode_mem, f, T0, u);

	if (check_flag(&flag, "CVodeInit", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}

	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}

	// Create Matrix Object.
	// ---------------------------------------------------------------------------
	// Need to create a dense matrix for the dense solver.
	SUNMatrix A = SUNDenseMatrix(dimension, dimension);
	if(check_flag((void *)A, "SUNDenseMatrix", 0)){
		throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 9. Create Linear Solver Object.
	// ---------------------------------------------------------------------------
	// Dense linear solver object instead of the iterative one in the original
	// simple example.
	SUNLinearSolver LS = SUNDenseLinearSolver(u, A) ;
	if(check_flag((void *)LS, "SUNDenseLinearSolver", 0)){
	  throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 10. Set linear solver optional inputs.

	// 11. Attach linear solver module.
	// ---------------------------------------------------------------------------
	// Call CVDlsSetLinearSolver to attach the matrix and linear solver this
	// function is different for direct solvers.
	flag = CVDlsSetLinearSolver(cvode_mem, LS, A);
	if(check_flag(&flag, "CVDlsSetLinearSolver", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 12. Set linear solver interface optional inputs.
	// ---------------------------------------------------------------------------
	// Sets the jacobian-times-vector function.
	flag = CVDlsSetJacFn(cvode_mem, jtv);
	if(check_flag(&flag, "CVDlsSetJacFn", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}

	std::vector<double> v(dimension), prev_v(dimension);
	prev_v = x;

	for (unsigned int k = 1; k <= N; k++) {
		double tout = (k * Tfinal) / N;
		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
		if (check_flag(&flag, "CVode", 1))
			break;
		// check polytope satisfaction
		for (unsigned int i = 0; i < dimension; i++)
			v[i] = NV_Ith_S(u,i) ;

		double dist = I->point_distance(v);
		if (math::abs(dist) > tol) {
//				std::cout << "time:" << t << " ";
			std::cout << "DISTANCE TO INV= " << std::setprecision(10) << dist
					<< std::endl;
			//std::cout << "tol = " << std::setprecision(10) << tol << std::endl;
			/*
			std::cout << "Violating trajectory start point:\n";
			for(unsigned int j=0;j<dimension;j++)
				std::cout << x[j] << " ";
			std::cout << std::endl;
			*/
			status = false;
			trace_point simpoint;
			simpoint.first = tout;
			simpoint.second = v;
			sim_trace.push_back(simpoint); // adding the simpoint in the sim_trace data-structure.
			break;
		} else {
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

std::vector<double> simulation::metric_simulate(std::vector<double> x,
		double time, double& distance, polytope::ptr I,
		std::vector<double>& grad) {

	int flag;
	realtype T0 = 0;
	realtype Tfinal = time;
	realtype t = 0;
	Dynamics *data = &D;
	N = Tfinal / time_step;

	N_Vector u = NULL;

	if (data->isEmptyMatrixA && data->isEmptyC) // zero dynamics
		return x; // return same initial point

	assert(x.size() == dimension);
	u = N_VNew_Serial(dimension);

	assert(grad.size() == dimension);
	// initialize

	for (unsigned int i = 0; i < dimension; i++) {
		NV_Ith_S(u,i) = x[i];
		grad[i] = 0;
	}
	void *cvode_mem;
	cvode_mem = NULL;
	// Call CVodeCreate to create the solver memory and specify the
	// Backward Differentiation Formula and the use of a Newton iteration

	cvode_mem = CVodeCreate(CV_BDF);

	if (check_flag((void *) cvode_mem, "CVodeCreate", 0)) {
		throw std::runtime_error("CVODE failed\n");
	}

	// Input user data
	CVodeSetUserData(cvode_mem, (void *) data);

	// Call CVodeInit to initialize the integrator memory and specify the
	//ser's right hand side function in u'=f(t,u), the inital time T0, and
	// the initial dependent variable vector u.

	flag = CVodeInit(cvode_mem, f, T0, u);

	if (check_flag(&flag, "CVodeInit", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}

	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}

	// Create Matrix Object.
	// ---------------------------------------------------------------------------
	// Need to create a dense matrix for the dense solver.
	SUNMatrix A = SUNDenseMatrix(dimension, dimension);
	if(check_flag((void *)A, "SUNDenseMatrix", 0)){
		throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 9. Create Linear Solver Object.
	// ---------------------------------------------------------------------------
	// Dense linear solver object instead of the iterative one in the original
	// simple example.
	SUNLinearSolver LS = SUNDenseLinearSolver(u, A) ;
	if(check_flag((void *)LS, "SUNDenseLinearSolver", 0)){
	  throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 10. Set linear solver optional inputs.

	// 11. Attach linear solver module.
	// ---------------------------------------------------------------------------
	// Call CVDlsSetLinearSolver to attach the matrix and linear solver this
	// function is different for direct solvers.
	flag = CVDlsSetLinearSolver(cvode_mem, LS, A);
	if(check_flag(&flag, "CVDlsSetLinearSolver", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 12. Set linear solver interface optional inputs.
	// ---------------------------------------------------------------------------
	// Sets the jacobian-times-vector function.
	flag = CVDlsSetJacFn(cvode_mem, jtv);
	if(check_flag(&flag, "CVDlsSetJacFn", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}

	//printing simulation trace in a file for debug purpose, in the plot_dim dimension

	std::vector<double> v(dimension);

	math::matrix<double> expAt;
	std::vector<double> g(dimension);
	distance = 0;
	for (unsigned int k = 1; k <= N; k++) {
		double tout = (k * Tfinal) / N;
		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
		if (check_flag(&flag, "CVode", 1))
			break;
		// check polytope satisfaction
		for (unsigned int i = 0; i < dimension; i++)
			v[i] = NV_Ith_S(u,i) ;

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
 * Returns the set of new start points which are valid for starting new simulation from the successor location of the ha.
 */

void simulation::Hyperplane_to_Halfspace(math::matrix<double>& M, std::vector<double>& Bounds, std::vector<double> x){

	for(unsigned int i = 0; i<M.size1()-1; i++){
		int count = 0;
		double sum1 = 0, sum2 = 0;
		for(unsigned int j=0; j<M.size2(); j++){
			if(abs(M(i,j)) != abs(M(i+1,j))){
				count++; // if count = 0, i^th row is half-space otherwise i^th and i+1^th row is line or region
			}
			sum1 = sum1 + M(i,j) * x[j];
			sum2 = sum2 + M(i+1,j) * x[j];
		}
		if(count == 0 && (abs(Bounds[i]) == abs(Bounds[i+1])) && (Bounds[i] != Bounds[i+1] || (Bounds[i] == 0 && Bounds[i+1] == 0))){ // start line to half-space

			if(sum1 <= Bounds[i]){
				for(unsigned int j=0; j<M.size2(); j++){
					if(M(i,j) != 0){
						M(i,j) = M(i,j) * (-1);
					}
				}
				Bounds[i] = Bounds[i] * (-1);
			}
			else if(sum2 <= Bounds[i+1]){
				for(unsigned int j=0; j<M.size2(); j++){
					if(M(i+1,j) != 0){
						M(i+1,j) = M(i+1,j) * (-1);
					}
				}
				Bounds[i+1] = Bounds[i+1] * (-1);
			}
			i = i+1;
		}// end line to half-space

		/*else if(count == 0 && (abs(Bounds[i]) != abs(Bounds[i+1]))){ // Start region to half-space
			if(abs(sum1) < abs(Bounds[i]) && abs(sum1) < abs(Bounds[i+1])){
				if(abs(Bounds[i]) < abs(Bounds[i+1])){
					for(int j=0; j<M.size2(); j++){
							M(i+1,j) = M(i,j);
					}
					Bounds[i+1] = Bounds[i];
				}
				else if(abs(Bounds[i]) > abs(Bounds[i+1])){
					for(int j=0; j<M.size2(); j++){
							M(i,j) = M(i+1,j);
					}
					Bounds[i] = Bounds[i+1];
				}
			}
			else if(abs(sum1) > abs(Bounds[i]) && abs(sum1) > abs(Bounds[i+1])){
				if(abs(Bounds[i]) < abs(Bounds[i+1])){
					for(int j=0; j<M.size2(); j++){
							M(i,j) = M(i+1,j);
					}
					Bounds[i] = Bounds[i+1];
				}
				else if(abs(Bounds[i]) > abs(Bounds[i+1])){
					for(int j=0; j<M.size2(); j++){
							M(i+1,j) = M(i,j);
					}
					Bounds[i+1] = Bounds[i];
				}
			}
		}*/ // End region to half-space
	}
	//cout<<"converted to Halfspace"<<endl;
}

std::vector<sim_start_point> simulation::simulateHaLocation(
		sim_start_point start_point, double start_time, double tot_time,
		hybrid_automata& ha, std::pair<int, polytope::ptr>& forbidden_set,
		bool& safety_status) {

	int flag;

	realtype t = start_time, T0 = 0;
	realtype Tfinal = tot_time - start_time;
	N = Tfinal / time_step;
	double tout1 = start_time;  //New Start Time for new simulation

	Dynamics Dyn = start_point.locptr->getSystem_Dynamics();

	std::vector<double> x = start_point.start_point;

	// Check if zero dynamics. No need to simulate then.
	if (Dyn.isEmptyMatrixA && Dyn.isEmptyC) {
		DEBUG_MSG("A location with empty dynamics reached\n");
		std::vector<sim_start_point> emptylist;
		return emptylist;
	}

	std::vector<sim_start_point> new_start_points;

	//List of intersected polytope
	std::list<eligibleTransition> etrans_list;

	location::ptr loc = start_point.locptr;
	polytope::ptr inv = loc->getInvariant();
	unsigned int this_loc_id = loc->getLocId();

	//Computing guard-invariant intersection and bloating the set with time-step
	std::list<transition::ptr> outgoingtrans;
	outgoingtrans = loc->getOut_Going_Transitions();
	for (std::list<transition::ptr>::iterator it = outgoingtrans.begin();
			it != outgoingtrans.end(); it++) {

		eligibleTransition trans;
		polytope::ptr g = (*it)->getGuard();

		math::matrix<double> M = g->getCoeffMatrix();
		std::vector<double> Bounds = g->getColumnVector();

		Hyperplane_to_Halfspace(M, Bounds, x);  // Convert guard as half-space to detect line crossing
		g->setCoeffMatrix(M);
		g->setColumnVector(Bounds);
		trans.inv_g_intersection = g;
		trans.trans = *it;
		etrans_list.push_back(trans);
	}
	double tol_inv = 1e-10;

	dimension = x.size();
	
	reltol = 1e-8;
	abstol = 1e-8;

	assert(x.size() == dimension);

	N_Vector u = N_VNew_Serial(dimension);

	double dist = math::abs(inv->point_distance(x));

	cout.precision(17);

	if (dist > tol_inv) {
		std::cout << "Initial point outside the location invariant\n";
		std::vector<sim_start_point> emptylist;
		return emptylist;
	};

	for (unsigned int i = 0; i < dimension; i++)
		NV_Ith_S(u,i) = x[i];

	void *cvode_mem;
	cvode_mem = NULL;

	// Call CVodeCreate to create the solver memory and specify the
	// Backward Differentiation Formula and the use of a Newton iteration
	cvode_mem = CVodeCreate(CV_BDF);
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

	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (check_flag(&flag, "CVodeSStolerances", 1)) {
		throw std::runtime_error("CVODE failed\n");
	}

	// Create Matrix Object.
	// ---------------------------------------------------------------------------
	// Need to create a dense matrix for the dense solver.
	SUNMatrix A = SUNDenseMatrix(dimension, dimension);
	if(check_flag((void *)A, "SUNDenseMatrix", 0)){
		throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 9. Create Linear Solver Object.
	// ---------------------------------------------------------------------------
	// Dense linear solver object instead of the iterative one in the original
	// simple example.
	SUNLinearSolver LS = SUNDenseLinearSolver(u, A) ;
	if(check_flag((void *)LS, "SUNDenseLinearSolver", 0)){
	  throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 10. Set linear solver optional inputs.

	// 11. Attach linear solver module.
	// ---------------------------------------------------------------------------
	// Call CVDlsSetLinearSolver to attach the matrix and linear solver this
	// function is different for direct solvers.
	flag = CVDlsSetLinearSolver(cvode_mem, LS, A);
	if(check_flag(&flag, "CVDlsSetLinearSolver", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}
	// ---------------------------------------------------------------------------

	// 12. Set linear solver interface optional inputs.
	// ---------------------------------------------------------------------------
	// Sets the jacobian-times-vector function.
	flag = CVDlsSetJacFn(cvode_mem, jtv);
	if(check_flag(&flag, "CVDlsSetJacFn", 1)){
	  throw std::runtime_error("CVODE failed\n");
	}

	std::vector<double> v(dimension),prev_v;
	v = x;

	// add the initial point to the trace:
	trace_point simpoint;
	simpoint.first = 0;
	simpoint.second = x;
	sim_trace.push_back(simpoint); // adding the simpoint in the sim_trace data-structure.
	int unsafe_loc_id = forbidden_set.first;
	//-------------------
	for (unsigned int k = 1; k <= N; k++) {
		double tout = k * (Tfinal / N);
		flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);

		if (check_flag(&flag, "CVode", 1)) {
			cout << "Start time = " << t << "  Total Time = " << Tfinal
					<< " Value of tout = " << tout << endl;
			break;
		}
		prev_v  = v;
		for (unsigned int i = 0; i < dimension; i++)
			v[i] = NV_Ith_S(u, i) ;
		//checking safety of the trajectory.
		if( (unsafe_loc_id == this_loc_id || unsafe_loc_id ==-1) && forbidden_set.second->point_distance(v) == 0){
			safety_status=false;
			return new_start_points;
		}
		trace_point simpoint;
		simpoint.first = tout;
		simpoint.second = v;
		sim_trace.push_back(simpoint);

		for (std::list<eligibleTransition>::iterator it = etrans_list.begin();
				it != etrans_list.end(); it++) {
			polytope::ptr p = it->inv_g_intersection;

			double dist = p->point_distance(v);

//			cout<<"Checking  point-distance with Invariant_guard = "<<dist<<endl;


			if (dist == 0) { //just intersected the guard
				sim_start_point w;
				int locID = it->trans->getDestination_Location_Id();
				location::ptr loc = ha.getLocation(locID);
//				cout<<"Intersected with the Guard and Destination LocationID="<<locID<<endl;
				w.locptr = loc;
				w.cross_over_time = tout1 + tout;
//				cout<<"w.cross_over_time = "<<w.cross_over_time<<endl;
				//Now assignment operation of the transition to be performed
				std::vector<double> mapped_point;

				mapped_point = it->trans->applyTransitionMap(v);

				w.start_point = mapped_point;
				polytope::ptr new_inv = w.locptr->getInvariant();

				double dist1 = new_inv->point_distance(w.start_point);
				if (dist1 == 0){ // the new point is within the invariant of the new location
					// In the urgent semantics, only the first guard intersecting point is added for further simulation
					new_start_points.push_back(w);
					break;
				} else if(inv->point_distance(prev_v)==0){ //Amit todo modify prev_v with v in consultation with Sir Rajarshi
					sim_start_point u;
					location::ptr loc = start_point.locptr;

					//cout<<"\nInside previous Inv = "<<inv->point_distance(v)<<endl;//Amit testing prev_v with v

					u.locptr = loc;
					//cout<<"This locID = "<<loc->getLocId()<<endl;
					u.cross_over_time = tout1 + tout - Tfinal/N;

					//Now assignment operation of the transition to be performed
					std::vector<double> mapped_point;

					mapped_point = it->trans->applyTransitionMap(prev_v); //Amit: todo modify prev_v with v in consultation with Sir Rajarshi
					u.start_point = mapped_point;
					if(new_inv->point_distance(u.start_point) == 0)
					{
						sim_trace.pop_back();
						new_start_points.push_back(u);
					}
				}
			}
		} // end of for loop

		// Add the point to the sim_trace because it does not intersect with the guard yet
		if (new_start_points.size() > 0) // stop simulation since the next simulation point is found.
			break;

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
void simulation::print_trace_to_outfile(std::string s) {
	std::ofstream myoutfile;
	myoutfile.open(s.c_str(),std::fstream::app);
	for(std::list<trace_point>::const_iterator it = sim_trace.begin();
			it != sim_trace.end(); it++) {
		myoutfile << (*it).second[this->x1] << "  " << (*it).second[this->x2] << "\n";
	}
	myoutfile.close();
}

/**
 * Returns a set of random simulation start points from the given as Hyperbox as initial set.
 */
std::vector<sim_start_point> simulation::get_start_points(unsigned int n,
		hyperbox<double>::ptr hbox, location::ptr locptr) {
	std::vector<sim_start_point> my_start_points;
	for (unsigned int i = 0; i < n; i++) {
		std::vector<double> point = hbox->get_internal_point();
		sim_start_point s;
		s.start_point = point;
		s.locptr = locptr;
		s.cross_over_time = 0;
		my_start_points.push_back(s);

	}
	return my_start_points;
}
;

std::vector<sim_start_point> simulation::get_start_points(unsigned int n,
		polytope::ptr initialset, location::ptr locptr) {
	/**
	 * Check if the polytope is a hyperbox. If so, convert it into hyperbox and
	 * get random start points using the hyperbox class routine
	 */

	unsigned int i, j, rowSize, columnSize;
	math::matrix<double> matrix;
	std::vector<sim_start_point> res;

	matrix = initialset->getCoeffMatrix();
	rowSize = matrix.size1();
	columnSize = matrix.size2();


	int countmatrix[columnSize];

	for (i = 0; i < columnSize; i++) {
		countmatrix[i] = 0;
	}
	bool is_hyperbox = true;
	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < columnSize; j++) {
			if (matrix(i, j) != 0) {
				countmatrix[j] = countmatrix[j] + 1;
			}
		}
		if (j < columnSize && countmatrix[j] != 1) {
			is_hyperbox = false;
			break;
		}
	}

	typename hyperbox<double>::ptr hbox_ptr;

	/**
	 * The following conversion works only for polytopes represented in Ax<=b form.
	 * In addition, it assumes that A is in a certain form, that is, the lower and upper
	 * bound on any dimension is mentioned as consecutive constraints in A, first the
	 * constraint on the upper bound and followed by the constraint on the lower bound.
	 */
	if (is_hyperbox) {
		// convert this polytope into hyperbox object

		hbox_ptr = hyperbox<double>::ptr(new hyperbox<double>());
		hbox_ptr->set_dimension(columnSize);

		for (unsigned int i = 0; i < rowSize;) {
			for (unsigned int j = 0; j < columnSize; j++) {
				if (matrix(i, j) == 0)
					continue;
				else {
					//double upper_bound = initialset->getColumnVector()[i];
					double upper_bound = initialset->getColumnVector()[i];
					double lower_bound = -1
							* initialset->getColumnVector()[i + 1];
					hbox_ptr->set_bounds_on_dimension(j, lower_bound,
							upper_bound);
					//std::cout << "hbox set bounds called with params:" << "j=" << j << ", lower_bound = " << lower_bound << ", upper_bound:" << upper_bound << std::endl;
					i += 2;
					break;
				}
			}
		}

		// generate the points
		for (unsigned int i = 0; i < n; i++) {
			sim_start_point s;
			s.start_point = hbox_ptr->get_internal_point();
			s.cross_over_time = 0;
			s.locptr = locptr;
			res.push_back(s);
		}
	}
	/**
	 * If polytope is general than a hyperbox, do the following
	 */

	// code goes here
	return res;
}

bool simulation::simulateHa(sim_start_point start, double start_time, double tot_time, hybrid_automata& ha, std::pair<int, polytope::ptr>& forbidden_set, unsigned int max_jumps=10)
{
	std::list<sim_start_point> wlist;
	wlist.push_back(start);


	unsigned int jumps_taken = 0;

	bool safety_status = true;
	while (wlist.size() != 0 && jumps_taken <= max_jumps) {
		sim_start_point s = wlist.front();
		wlist.pop_front();
		std::vector<sim_start_point> next_pts;
		next_pts = simulateHaLocation(s, s.cross_over_time, tot_time, ha, forbidden_set, safety_status);
		//simulateHaLocation also creates a sim_trace per location per start_point and concatenates
		if(safety_status == false)
			return false; // the simulated trajectory is unsafe.
		for (unsigned int i = 0; i < next_pts.size(); i++)
			wlist.push_back(next_pts[i]);
		jumps_taken++;
	}
	return true; // the simulated trajectory is safe.
}

bool simulation::parSimulateHa(unsigned int n, polytope::ptr initial_set,
		double start_time, double tot_time, hybrid_automata& ha,
		std::pair<int, polytope::ptr>& forbidden_set, unsigned int max_jumps=10) {

	std::vector<sim_start_point> start_points = get_start_points(n, initial_set,
			ha.getInitial_Location());

	unsigned int t = 0, point_count = 0;
	unsigned int N_cores = omp_get_num_procs();
	std::vector<sim_start_point> wlist[2][N_cores][N_cores];

	for (unsigned int i = 0; i < N_cores; i++) {
		for (unsigned int j = 0; j < N_cores; j++) {
			while (wlist[t][i][j].size()
					<= ceil(start_points.size() / (N_cores * N_cores))
					&& point_count < start_points.size()) {
				wlist[t][i][j].push_back(start_points[point_count]);
				point_count++;
			}
		}
	}

	std::list<std::list<trace_point> > simtraces[N_cores];
	// Bug: safety_status needs to be correctly set with mutual exclusion.
	bool wlistNotEmpty = true, safety_status=true;
	unsigned int jumps_taken = 0;
	while (wlistNotEmpty == true && jumps_taken <= max_jumps) {
		int newpointsCount = 0;
#pragma omp parallel for
		for (unsigned int w = 0; w < N_cores; w++) {
			for (unsigned int q = 0; q < N_cores; q++) {
				while (wlist[t][w][q].size() != 0) {
					sim_start_point s = wlist[t][w][q][0];
					wlist[t][w][q].erase(wlist[t][w][q].begin());
					unsigned int sys_dimension = s.start_point.size();
					simulation myobj(sys_dimension, tot_time / this->time_step,
							s.locptr->getSystem_Dynamics());
					myobj.set_time_step(this->time_step);
					std::vector<sim_start_point> newpoints =
							myobj.simulateHaLocation(s, s.cross_over_time,
									tot_time, ha, forbidden_set, safety_status);
					simtraces[w].push_back(myobj.get_sim_trace()); //TODO::Let us see if we can use pointer here to improve performance-time
					//ToDo:: here w' should be generated randomly and used in place of q in the next wlist[1-t][w'][w].push_back(newpoints)
					//also note that simulateHaLocation is generating only a single point due to "must" semantics of HA
					for (unsigned int j = 0; j < newpoints.size(); j++) {
						wlist[1 - t][q][w].push_back(newpoints[j]);//TODO:: if newpoints is more than 1 points then, q need to be selected randomly
						newpointsCount++; //TODO:: take care of Race condition
					}
				}
				wlist[t][w][q].erase(wlist[t][w][q].begin(),
					wlist[t][w][q].begin() + wlist[t][w][q].size()); //why is this repeated?
			}
		}
		jumps_taken++;
		t = 1 - t;
		if (newpointsCount == 0)
			wlistNotEmpty = false;
	}

	sim_trace.clear();

	// dump the simtraces list into this->sim_trace
	//TODO:: Let us note the time if expensive then better return "list <list<trace_point>> simtraces"
	for (unsigned int i = 0; i < N_cores; i++) {
		for (std::list<std::list<trace_point> >::iterator it =
				simtraces[i].begin(); it != simtraces[i].end(); it++) {
			std::list<trace_point> s = *it;

			for (std::list<trace_point>::const_iterator it = s.begin();
					it != s.end(); it++) {
				sim_trace.push_back(*it);
			}
		}
	}
	return safety_status;
}

/* Check function return value...
 opt == 0 means SUNDIALS function allocates memory so check if
 returned NULL pointer
 opt == 1 means SUNDIALS function returns a flag so check if
 flag >= 0
 opt == 2 means function allocates memory so check if returned
 NULL pointer */

static int check_flag(void *flagvalue, const char* funcname, int opt) {
	int *errflag;

	/* Check if SUNDIALS function returned NULL pointer - no memory allocated */

	if (opt == 0 && flagvalue == NULL) {
		fprintf(stderr,
				"\nSUNDIALS_ERROR: %s() failed - returned NULL pointer\n\n",
				funcname);
		return (1);
	}

	/* Check if flag < 0 */

	else if (opt == 1) {
		errflag = (int *) flagvalue;
		if (*errflag < 0) {
			fprintf(stderr, "\nSUNDIALS_ERROR: %s() failed with flag = %d\n\n",
					funcname, *errflag);
			return (1);
		}
	}

	/* Check if function returned NULL pointer - no memory allocated */

	else if (opt == 2 && flagvalue == NULL) {
		fprintf(stderr,
				"\nMEMORY_ERROR: %s() failed - returned NULL pointer\n\n",
				funcname);
		return (1);
	}

	return (0);
}
static int jtv (realtype t, N_Vector y, N_Vector fy, SUNMatrix Jac,
                void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
	Dynamics* D = (Dynamics *) (user_data);
	math::matrix<double> A;

	if (D->isEmptyMatrixA) {
		assert(!D->isEmptyC); // The assumption is that this function is called with non-zero dynamics.
		unsigned int dim = D->C.size();
		A = math::matrix<double>(D->C.size(), D->C.size());
		for (unsigned int i = 0; i < dim; i++)
			for (unsigned int j = 0; j < dim; j++)
				A(i, j) = 0;
	} else
		A = math::matrix<double>(D->MatrixA);

	std::vector<double> C(A.size1());

	assert(A.size1() == A.size2());
	C = D->C;

	// Input set not included in the dynamics.

	for (unsigned int i = 0; i < A.size1(); i++) {
		for (unsigned int j = 0; j < A.size2(); j++) {
			SM_ELEMENT_D(Jac, i, j) = A(i, j);
		}
	}
	return 0;
}
