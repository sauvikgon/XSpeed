#include <core/math/nlpSolver/nlpSolver.h>
#include <utilities/dbgMsgLogger.h>


/**
 * A linear constraint represented as ax+b ≤ 0
 */

double myLinearConstraint(const std::vector<double> &x,
		std::vector<double> &grad, void *data) {

	//polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	polyConstraints *d = (polyConstraints *) data;

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

//This forms the objective function of the NLP
double myObjFunc(const std::vector<double> &y, std::vector<double> &grad,
		void *my_func_data) {

	//Here objective function is   (x.l) where x is the element in the set X and l is the maximizing/minimizing direction
	std::vector<double> *x_vector =
			reinterpret_cast<std::vector<double> *>(my_func_data);


	long double objFunc = 0;
	for (unsigned int i = 0; i < x_vector->size(); i++) {
		objFunc += (y[i] * x_vector->at(i));
	}
	return objFunc;
}

void printStatus(nlopt::result status) {

	if (status == -1)
		DEBUG_MSG("nlopt::result:=status =  FAILURE " << std::endl);
	if (status == -2)
		DEBUG_MSG("nlopt::result:=status = INVALID_ARGS " << std::endl);
	if (status == -3)
		DEBUG_MSG("nlopt::result:=status = OUT_OF_MEMORY " <<std::endl);
	if (status == -4)
		DEBUG_MSG("nlopt::result:=status = ROUNDOFF_LIMITED "<<std::endl);
	if (status == -5)
		DEBUG_MSG("nlopt::result:=status = FORCED_STOP " << std::endl);
	if (status == 1)
		DEBUG_MSG("nlopt::result:=status = SUCCESS " << std::endl);
	if (status == 2)
		DEBUG_MSG("nlopt::result:=status = STOPVAL_REACHED " << std::endl);
	if (status == 3)
		DEBUG_MSG("nlopt::result:=status = FTOL_REACHED "<<std::endl);
	if (status == 4)
		DEBUG_MSG("nlopt::result:=status = XTOL_REACHED "<<std::endl);
	if (status == 5)
		DEBUG_MSG("nlopt::result:=status = MAXEVAL_REACHED "<<std::endl);
	if (status == 6)
		DEBUG_MSG("nlopt::result:=status = MAXTIME_REACHED "<<std::endl);
}

/**
 * Computes the Housdorff Distance between two polytopes
 */
double computeNLP(polytope::ptr Y, std::vector<double>& objfunc) {



// 	local optimization routine

	struct nlp_data data_Y;
	data_Y.consPoly = Y;


	nlopt::opt minopt; // nlopt object to solve the NLP of polytope constraints Y
	// create the nlopt object to solve the minimization problem over Y
	minopt = nlopt::opt(nlopt::LN_COBYLA, Y->getSystemDimension()); // derivative free

	double minf; // The Max (x.l)
	std::vector<double>& x_nonconst = const_cast<std::vector<double>&>(objfunc);

	minopt.set_max_objective(myObjFunc, &x_nonconst);

	// Set the constraint of this problem to be Y
	polyConstraints data[Y->getColumnVector().size()]; //total constraints
	for (unsigned int i = 0; i < Y->getCoeffMatrix().size1(); i++) {
		std::vector<double> coeff(Y->getCoeffMatrix().size2());
		for (unsigned int j = 0; j < Y->getCoeffMatrix().size2(); j++) {
			coeff[j] = Y->getCoeffMatrix()(i, j);
		}
		(data[i].a).assign(coeff.begin(), coeff.end());
		data[i].b = Y->getColumnVector()[i];

		minopt.add_inequality_constraint(myLinearConstraint, &data[i]); //iterate over the number of constraints of the polytope Y

	}


	std::vector<double> v(objfunc.size(), 0);

	try {
		minopt.set_maxeval(100); // Max Iterations to converge to maxima
		nlopt::result status = minopt.optimize(v, minf);
		printStatus(status);

		if (status < 0)
			throw std::runtime_error("Nlopt returned error\n");

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return minf;

}

