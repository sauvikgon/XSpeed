#include "core_system/math/nlp_solver/nlp_solver.h"

/**
 * A linear constraint represented as ax+b ≤ 0
 */

double myLinearConstraint(const std::vector<double> &x,
		std::vector<double> &grad, void *data) {

	//polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	polyConstraints *d = (polyConstraints *) data;

	std::vector<double> a = d->a;
//count++;
	//std::cout<<"Inside Function myLinearConstraint\n";
//	std::cout<<"a[0]="<<a[0]<<"   a[1]="<<a[1]<<"  and b = "<<d->b<<std::endl;

	unsigned int dim = a.size();

	double sum = 0;
	//Set the variable index correctly
	for (unsigned int j = 0; j < dim; j++) {
		sum += x[j] * d->a[j];
	}
	sum -= d->b;
	return sum;
}

//This forms the objective function of the NLP
double myObjFunc(const std::vector<double> &y, std::vector<double> &grad,
		void *my_func_data) {

	/*std::vector<double> *x_vector = reinterpret_cast<std::vector<double> *>(my_func_data);
	 long double distance = 0;
	 for (unsigned int i = 0; i < x_vector->size(); i++) {
	 distance += (y[i] - x_vector->at(i)) * (y[i] - x_vector->at(i));
	 }
	 return std::sqrt(distance);*/
	//Here objective function is   (x.l) where x is the element in the set X and l is the maximizing/minimizing direction
	std::vector<double> *x_vector =
			reinterpret_cast<std::vector<double> *>(my_func_data);

//	std::cout<<"x_vector->at(0) = "<<x_vector->at(0)<<"x_vector->at(1) = "<<x_vector->at(1)<<std::endl;
	long double objFunc = 0;
	for (unsigned int i = 0; i < x_vector->size(); i++) {
		objFunc += (y[i] * x_vector->at(i));
	}
//	std::cout<<"y[0] = "<<y[0]<<" y[1] = "<<y[1]<<std::endl;
	return objFunc;
}

void printStatus(nlopt::result status) {

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

/**
 * Computes the Housdorff Distance between two polytopes
 */
double computeNLP(polytope::ptr Y, std::vector<double>& objfunc) {
	double tolerance = 1e-8;
//	double tolerance = 0;
	//count=0;
	unsigned int dim_Y = Y->getSystemDimension();
//std::cout<<"nlopt problem dimension = " << dim_Y << std::endl;
//std::cout<<"Y->getColumnVector().size() = " << Y->getColumnVector().size() << std::endl;

//	std::cout << "nlopt problem dimension = " << optD << std::endl;
	unsigned int optD = dim_Y;

// 	local optimization routine

	struct nlp_data data_Y;
	data_Y.consPoly = Y;

/*
	std::vector<double> lb(2);
	//lb[0] = -HUGE_VAL;
	lb[0] = 0;
	lb[1] = 0;
*/

	nlopt::opt minopt; // nlopt object to solve the NLP of polytope constraints Y
	// create the nlopt object to solve the minimization problem over Y
	minopt = nlopt::opt(nlopt::LN_COBYLA, Y->getSystemDimension()); // derivative free
	//minopt = nlopt::opt(nlopt::LD_MMA, Y->getSystemDimension()); // derivative free
	//minopt = nlopt::opt(nlopt::GN_DIRECT_L_NOSCAL, Y->getSystemDimension()); // derivative free

/*
	minopt.set_lower_bounds(lb);
	std::vector<double> ub(2);
	ub[0] = HUGE_VAL;
	ub[1] = HUGE_VAL;
	minopt.set_upper_bounds(ub);
*/

	double minf; // The Max (x.l)
	std::vector<double>& x_nonconst = const_cast<std::vector<double>&>(objfunc);
//	std::cout<<"x_nonconst[0] = "<<x_nonconst[0]<<"x_nonconst[1] = "<<x_nonconst[1]<<std::endl;
	minopt.set_max_objective(myObjFunc, &x_nonconst);

	// Set the constraint of this problem to be Y
	polyConstraints data[Y->getColumnVector().size()]; //total constraints
	for (int i = 0; i < Y->getCoeffMatrix().size1(); i++) {
		std::vector<double> coeff(Y->getCoeffMatrix().size2());
		for (int j = 0; j < Y->getCoeffMatrix().size2(); j++) {
			coeff[j] = Y->getCoeffMatrix()(i, j);
		}
		(data[i].a).assign(coeff.begin(), coeff.end());
		data[i].b = Y->getColumnVector()[i];
		//minopt.add_inequality_constraint(myLinearConstraint, &data[i], tolerance); //iterate over the number of constraints of the polytope Y
		minopt.add_inequality_constraint(myLinearConstraint, &data[i]); //iterate over the number of constraints of the polytope Y
	//	std::cout << "Iteration i=" << i << std::endl;
	}
//	minopt.set_xtol_rel(1e-4);

	std::vector<double> v(objfunc.size(), 0);
	//v[0]=10;v[1]=5;

	try {
//		std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;
		minopt.set_maxeval(100); // Max Iterations to converge to maxima
//		minopt.set_stopval(tolerance); //After disabling this result is correct
		std::cout << "Before Calling NLP optimize Function: " << std::endl;
		//int status = minopt.optimize(v, minf);
		nlopt::result status = minopt.optimize(v, minf);
		printStatus(status);
		//	std::cout<<"Solver executed "<<count<< "times to terminate for the solution:   ";
		std::cout << "  v[0]=" << v[0] << "   v[1]=" << v[1] << std::endl;
		if (status < 0)
			throw std::runtime_error("Nlopt returned error\n");

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return minf;

}

