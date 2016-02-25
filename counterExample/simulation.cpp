/*
 * simulation.cpp
 *
 *  Created on: 12-Feb-2016
 *      Author: rajarshi
 */

#include "counterExample/simulation.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include <fstream>

simulation::simulation() {
	// TODO Auto-generated constructor stub

}

simulation::~simulation() {
	// TODO Auto-generated destructor stub
}

/* Private function to check function return values */

static int check_flag(void *flagvalue, char *funcname, int opt);

static int f(realtype t, N_Vector y, N_Vector ydot, void *f_data)
{
	Dynamics* D = (Dynamics *)(f_data);
	math::matrix<double> A(D->MatrixA);
	math::vector<double> C(A.size1());

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

std::vector<double> simulation::simulate(std::vector<double> x, double time)
{
	int flag;
	realtype T0 = 0;
	realtype Tfinal = time;
	realtype t=0;
	Dynamics *data = &D;


	N_Vector y = NULL;
	N_Vector u = NULL;

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

	// double distance=0.0;

	//printing simulation trace in a file for debug purpose, in the plot_dim dimension

	double time_offset = x[get_index("t")];

	bool print_flag = false;
	std::ofstream myfile;
	if(!filename.empty()){
		myfile.open(this->filename.c_str(),std::fstream::app);
		print_flag = true;
	}
	if(print_flag){
		for(unsigned int k=1;k<N;k++) {
			double tout = (k*Tfinal)/N;
			flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
			if(check_flag(&flag, "CVode", 1)) break;
			//myfile << NV_Ith_S(u,this->x) << "  " << NV_Ith_S(u,this->y);
			myfile << time_offset + t << "  " << NV_Ith_S(u,this->x);
			myfile << "\n";
		}
		myfile << "\n";
		myfile.close();
	}
	else{ // no printing the simulation points to file
		for(unsigned int k=1;k<N;k++) {
			double tout = (k*Tfinal)/N;
			flag = CVode(cvode_mem, tout, u, &t, CV_NORMAL);
			if(check_flag(&flag, "CVode", 1)) break;
		}
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

/* Check function return value...
     opt == 0 means SUNDIALS function allocates memory so check if
              returned NULL pointer
     opt == 1 means SUNDIALS function returns a flag so check if
              flag >= 0
     opt == 2 means function allocates memory so check if returned
              NULL pointer */

static int check_flag(void *flagvalue, char *funcname, int opt)
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
      return(1); }}

  /* Check if function returned NULL pointer - no memory allocated */

  else if (opt == 2 && flagvalue == NULL) {
    fprintf(stderr, "\nMEMORY_ERROR: %s() failed - returned NULL pointer\n\n",
            funcname);
    return(1); }

  return(0);
}
/**
 * Returns the distance of the simulation trace from the
 * polytope passed as P. The distance computed is the sum of
 * the pointwise distances of simulation points.
 */
/*double simulation::trace_distance(polytope::ptr P)
{

}*/
