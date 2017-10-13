#include "Utilities/HausdorffDistance.h"

nlopt::opt minopt; // nlopt object to solve the distance Inf over Y

/**
 * A linear constraint represented as ax+b ≤ 0
 */

void printStatus2(int status) {

	if (status == -1)
		std::cout << "nlopt::result:=status =  FAILURE "<<std::endl;
	if (status == -2)
		std::cout << "nlopt::result:=status = INVALID_ARGS "<<std::endl;
	if (status == -3)
		std::cout << "nlopt::result:=status = OUT_OF_MEMORY "<<std::endl;
	if (status == -4)
		std::cout << "nlopt::result:=status = ROUNDOFF_LIMITED "<<std::endl;
	if (status == -5)
		std::cout << "nlopt::result:=status = FORCED_STOP "<<std::endl;
	if (status == 1)
		std::cout << "nlopt::result:=status = SUCCESS "<<std::endl;
	if (status == 2)
		std::cout << "nlopt::result:=status = STOPVAL_REACHED "<<std::endl;
	if (status == 3)
		std::cout << "nlopt::result:=status = FTOL_REACHED "<<std::endl;
	if (status == 4)
		std::cout << "nlopt::result:=status = XTOL_REACHED "<<std::endl;
	if (status == 5)
		std::cout << "nlopt::result:=status = MAXEVAL_REACHED "<<std::endl;
	if (status == 6)
		std::cout << "nlopt::result:=status = MAXTIME_REACHED "<<std::endl;
}

double myconstraintH(const std::vector<double> &x, std::vector<double> &grad, void *data) {

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

double myobjfunc3(const std::vector<double> &y, std::vector<double> &grad, void *my_func_data) {

	std::vector<double> *x_vector = reinterpret_cast<std::vector<double> *>(my_func_data);

	long double distance = 0;
	for(unsigned int i=0;i<x_vector->size();i++)
	{
		distance += (y[i] - x_vector->at(i))*(y[i]-x_vector->at(i));
	}
	return std::sqrt(distance);
}

double myobjfunc1(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) {

	double minf; // The min d(x,y) s.t. y \in Y solution

	std::vector<double>& x_nonconst = const_cast<std::vector<double>& >(x);

	minopt.set_min_objective(myobjfunc3, &x_nonconst);
	double tolerance = 1e-8;

	std::vector<double> v(x.size(), 0);
	try {
//		std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;
		minopt.set_maxeval(100); // Max Iterations to converge to maxima

//@Amit		minopt.set_stopval(tolerance);
		int status = minopt.optimize(v, minf);
		if(status<0)
				throw std::runtime_error("Nlopt returned error\n");

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return minf;
}

/**
 * Computes the Housdorff Distance between two polytopes
 */
double getDistance(polytope::ptr X, polytope::ptr Y)
{
	double tolerance = 1e-8;

	unsigned int dim_X = X->getSystemDimension();
	unsigned int dim_Y = Y->getSystemDimension();

	assert(dim_X == dim_Y);

//	std::cout << "nlopt problem dimension = " << optD << std::endl;
	unsigned int optD = dim_X;
	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free

// 	local optimization routine

	struct nlp_data data_Y;
	data_Y.consPoly = Y;


	// create the nlopt object to solve the distance minimization problem over Y
	minopt = nlopt::opt(nlopt::LN_COBYLA, Y->getSystemDimension()); // derivative free

	// Set the constraint of this problem to be Y

	polyConstraints data[Y->getColumnVector().size()]; //total constraints
	for (int i=0;i<Y->getCoeffMatrix().size1();i++){
		std::vector<double> coeff(Y->getCoeffMatrix().size2());
		for(int j=0;j<Y->getCoeffMatrix().size2();j++){
			coeff[j] = Y->getCoeffMatrix()(i,j);
		}
		(data[i].a).assign(coeff.begin(),coeff.end());
		data[i].b = Y->getColumnVector()[i];
		minopt.add_inequality_constraint(myconstraintH, &data[i]); //iterate over the number of constraints of the polytope Y
	}

//	std::cout<<"constraint of Min NLP set successful!!"<<std::endl;
	// create the nlopt object to solve the max of mins problem over X
	myopt.set_max_objective(myobjfunc1, &data_Y);
	myopt.set_maxeval(100); // Max Iterations to converge to maxima
	//myopt.set_stopval(tolerance);


	// Set the initial value of the search
	std::vector<double> x(optD, 0);
	/*
	 * Testing with a point inside the polytope
	 */
//	x[0] = 10; x[1]=10;


	double maxf;
	// Set the constraint of this NLP to be X

	polyConstraints data1[X->getColumnVector().size()]; //total constraints
	for (int i=0;i<X->getCoeffMatrix().size1();i++){
		std::vector<double> coeff(X->getCoeffMatrix().size2()); // dimension of X
		for(int j=0;j<X->getCoeffMatrix().size2();j++){
			coeff[j] = X->getCoeffMatrix()(i,j);
		}
		(data1[i].a).assign(coeff.begin(),coeff.end());
		data1[i].b = X->getColumnVector()[i];
		myopt.add_inequality_constraint(myconstraintH, &data1[i]); //iterate over the number of constraints of the polytope Y
	}
//	std::cout<<"constraints of Max NLP set successful!!"<<std::endl;
	try {
//		std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;

//@Amit		myopt.set_stopval(tolerance);
		int status = myopt.optimize(x, maxf);
		printStatus2(status);
		if(status<0)
				throw std::runtime_error("Nlopt returned error\n");

	} catch (std::exception& e) {
		std::cout<<"Error Function: getDistance()" << e.what() << std::endl;

	}
	return maxf;

}


/**
 *  H_D(X,Y) = max{sup_{x \in X} inf_{y \in Y} d(x,y), sup_{y \in Y} inf_{x \in X} d(X,Y)}
 */
double HausdorffDistance(polytope::ptr X, polytope::ptr Y)
{
	double d1 = getDistance(X,Y);
	std::cout<<"Called second getDistance()"<<std::endl;
	double d2 = getDistance(Y,X);
	std::cout<<"d1="<<d1<<" and d2="<<d2<<std::endl;

	return d1>d2?d1:d2;
}
