/*
 * directionalApproxError.cpp
 *
 *  Created on: 14-Oct-2017
 *      Author: amit
 */

#include "../utilities/directionalApproxError.h"

#include "../utilities/dbg_msg_logger.h"

nlopt::opt optProb1; // nlopt object to solve the problem 1

/**
 * A linear constraint represented as ax+b ≤ 0
 */

void printErrorStatus(int status) {

	if (status == -1)
		DEBUG_MSG("nlopt::result:=status =  FAILURE " << std::endl);
	if (status == -2)
		DEBUG_MSG("nlopt::result:=status = INVALID_ARGS " << std::endl);
	if (status == -3)
		DEBUG_MSG("nlopt::result:=status = OUT_OF_MEMORY " << std::endl);
	if (status == -4)
		DEBUG_MSG(<< "nlopt::result:=status = ROUNDOFF_LIMITED " << std::endl);
	if (status == -5)
		DEBUG_MSG("nlopt::result:=status = FORCED_STOP " << std::endl);
	if (status == 1)
		DEBUG_MSG("nlopt::result:=status = SUCCESS " << std::endl);
	if (status == 2)
		DEBUG_MSG("nlopt::result:=status = STOPVAL_REACHED " << std::endl);
	if (status == 3)
		DEBUG_MSG(<< "nlopt::result:=status = FTOL_REACHED " << std::endl);
	if (status == 4)
		DEBUG_MSG(<< "nlopt::result:=status = XTOL_REACHED " << std::endl);
	if (status == 5)
		DEBUG_MSG("nlopt::result:=status = MAXEVAL_REACHED " << std::endl);
	if (status == 6)
		DEBUG_MSG("nlopt::result:=status = MAXTIME_REACHED " << std::endl);
}

double LinearHalfSpaceConstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data) {

	polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	std::vector<double> a = d->a;

	unsigned int dim = a.size();

	double sum = 0;
	//Set the variable index correctly
	for (unsigned int j = 0; j < dim; j++) {
		sum += x[j] * d->a[j];
	}
	sum -= d->b;
	return sum;
}

double myobjfunc(const std::vector<double> &y, std::vector<double> &grad, void *my_func_data) {

	std::vector<double> *x_vector = reinterpret_cast<std::vector<double> *>(my_func_data);

	long double dotProduct = 0;
	for(unsigned int i=0;i<x_vector->size();i++)
	{
		dotProduct += (y[i] * x_vector->at(i)); //y is the maximizer solution and input x_vector is the direction l
	}
	return dotProduct;
}


//This is calling the Main Objective Function which should call problem 1 and 2 in turn
double myMainObjFunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {

	// --------------------------- Problem 1 here -------------------------------------------------------------
	// 	local optimization routine: Max x.l subject to x \in X

	double maxProb1, maxProb2;
	std::vector<double>& x_nonconst = const_cast<std::vector<double>&>(x); // here x is the different chosen direction l
	//	std::cout<<"constraint of Min NLP set successful!!"<<std::endl;
	// create the nlopt object to solve the max of mins problem over X
	optProb1.set_max_objective(myobjfunc, &x_nonconst); //this objfunc will call problem1 and l is passed
	optProb1.set_maxeval(100); // Max Iterations to converge to maxima
	//myopt.set_stopval(tolerance);

	std::vector<double> v(x.size(), 0);
	//	std::cout<<"constraints of Max NLP set successful!!"<<std::endl;
	try {
		//std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;
		//@Amit		myopt.set_stopval(tolerance);
		int status = optProb1.optimize(v, maxProb1);
		if (status < 0)
			throw std::runtime_error("Nlopt returned error\n");

	} catch (std::exception& e) {
		std::cout << "Error Function: getDistance()" << e.what() << std::endl;

	}
	//Here we have the solution of problem 1 in maxProb1
	// -------------------------------- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX --------------------------------------


	// --------------------------- Problem 2 here -------------------------------------------------------------
//Now we find the Convex Hull of the list of computed vertices and find there support function ie the dot product of the vertices and take the Maximum value
// Todo @@@@@@@@@@@@@@@@@@@ try printing the value of x and see if it is the direction l


	nlp_VertexData *d = reinterpret_cast<nlp_VertexData *>(my_func_data);


	//std::list<std::vector<double> > X2 = ;
	std::list<std::vector<double> >::iterator it = d->v_list.begin();
	std::vector<double> vertex1 = (*it);
	maxProb2 = dot_product(vertex1,x_nonconst);
it++;
	//for(std::list<std::vector<double> >::iterator it= d->v_list.begin(); it != d->v_list.end();it++ ){
	for( ; it != d->v_list.end();it++ ){
		double max;
		vertex1 = (*it);
		max = dot_product(vertex1,x_nonconst);
		if (max > maxProb2)
			maxProb2 = max;
	}
	// -------------------------------- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX --------------------------------------

	return (maxProb1 - maxProb2);
}

double UnitSphereConstraint(const std::vector<double> &x,
		std::vector<double> &grad, void *data) {

	polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	std::vector<double> a = d->a;

	unsigned int dim = a.size();

	double sum = 0;
	//Set the variable index correctly
	for (unsigned int j = 0; j < dim; j++) {
		sum += (x[j] * x[j]) * d->a[j];
	}
	sum -= d->b;
	return sum;
}

/**
 * Computes the Directional Approximation Error between two polytopes
 * X the exact given polytope to be enumerated
 * X2 is the Vertices of the enumerated polytope using our enumeration by planar projection Algorithm
 */
double getSolution(polytope::ptr X, std::list<std::vector<double> > X2) {

	unsigned int dim_X = X->getSystemDimension();
	unsigned int dim_X2 = (*X2.begin()).size();
	unsigned int optD = dim_X;

	assert(dim_X == dim_X2);

	// --------------------------- Problem Main here -------------------------------------------------------------
	// 	local optimization routine: Max abs[problem1(l) - problem2(l)]
	/* (x^2 + y^2 = 1) equation of a unit sphere
	 * subject to x^2 + y^2 - 1 <= 0 and -x^2 - y^2 + 1 <= 0
	 *   ( 1  1  <=   1   )
	 *   ( -1  -1  <=  -1   )
	 * */
//	struct nlp_data data_main;
//	data_main.consPoly = X;
	// create the nlopt object to solve the problem
	nlopt::opt optProbMain(nlopt::LN_COBYLA, optD); // derivative free // derivative free
	// Set the constraint of this problem
	polyConstraints data_main[2]; //total constraints

	std::vector<double> coeff(2);

	coeff[0] = 1;
	coeff[1] = 1;
	(data_main[0].a).assign(coeff.begin(), coeff.end());
	data_main[0].b = 1;
	optProbMain.add_inequality_constraint(UnitSphereConstraint, &data_main[0]);

	coeff[0] = -1;
	coeff[1] = -1;
	(data_main[1].a).assign(coeff.begin(), coeff.end());
	data_main[1].b = -1;
	optProbMain.add_inequality_constraint(UnitSphereConstraint, &data_main[1]);

	// Set the objective function but take same l for all the problem

	// -------------------------------- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX --------------------------------------

// ----------------------------------- Problem  1 constraints can be defined here to avoid repeated creation -----------------------
	// Set the initial value of the search
	std::vector<double> x(optD, 0);
	/*
	 * Testing with a point inside the polytope
	 */
//	x[0] = 10; x[1]=10;
	double maxf;
	// Set the constraint of this NLP to be X

	// create the nlopt object to solve the problem
	optProb1 = nlopt::opt(nlopt::LN_COBYLA, X->getSystemDimension()); // derivative free
	// Set the constraint of this problem
	polyConstraints data[X->getColumnVector().size()]; //total constraints
	for (unsigned int i = 0; i < X->getCoeffMatrix().size1(); i++) {
		std::vector<double> coeff(X->getCoeffMatrix().size2());
		for (unsigned int j = 0; j < X->getCoeffMatrix().size2(); j++) {
			coeff[j] = X->getCoeffMatrix()(i, j);
		}
		(data[i].a).assign(coeff.begin(), coeff.end());
		data[i].b = X->getColumnVector()[i];
		optProb1.add_inequality_constraint(LinearHalfSpaceConstraint, &data[i]); //iterate over the number of constraints of the polytope Y
	}
// -----------------------------------------------------------------------------------------------------------------------------------

	struct nlp_VertexData data_X2;
	data_X2.v_list = X2;


//	std::cout<<"constraint of Min NLP set successful!!"<<std::endl;
	// create the nlopt object to solve the max of mins problem over X
	optProbMain.set_max_objective(myMainObjFunc, &data_X2); //this objfunc will call (problem1 - problem2)
	optProbMain.set_maxeval(100); // Max Iterations to converge to maxima
	//myopt.set_stopval(tolerance);

//	std::cout<<"constraints of Max NLP set successful!!"<<std::endl;
	try {
//		std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;

//@Amit		myopt.set_stopval(tolerance);
		int status = optProbMain.optimize(x, maxf);
		printErrorStatus(status);
		if (status < 0)
			throw std::runtime_error("Nlopt returned error\n");

	} catch (std::exception& e) {
		std::cout << "Error Function: getDistance()" << e.what() << std::endl;

	}
	return maxf;

}

/**
 *  ApproxError(X1,X2) = max{sup_{x \in X1}(l) - sup_{x \in X2}(l)}
 *  subject to x^2 + y^2 = 1
 *  For NLOpt have to convert constraints as x<=0 format
 *  So constraints is given by
 *  x^2 + y^2 - 1 <=0
 *  -x^2 - y^2 + 1 <=0
 *
 *  X2 is a convex set with the list vertices so take Convex Hull of X2. Each element of the list is a n-dimensional vector, n is the dimension of the Vertex
 */
double ApproxError(polytope::ptr X1, std::list<std::vector<double> > X2) {
	double d = getSolution(X1, X2);
	return d;
}
