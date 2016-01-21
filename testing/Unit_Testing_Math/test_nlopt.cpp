#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include <nlopt.hpp>
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {

	double a, b;

} my_constraint_data;

double myvconstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data) {
	my_constraint_data *d = reinterpret_cast<my_constraint_data*>(data);
	double a = d->a, b = d->b;
	if (!grad.empty()) {

		grad[0] = 3 * a * (a * x[0] + b) * (a * x[0] + b);
		grad[1] = -1.0;
	}

	return ((a * x[0] + b) * (a * x[0] + b) * (a * x[0] + b) - x[1]);
}
double myvfunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {
	if (!grad.empty()) {
		grad[0] = 0.0;
		grad[1] = 0.5 / sqrt(x[1]);
	}
	return sqrt(x[1]);
}

SUITE(NLOpt_TestSuite) {
struct ExampleOptProb {
	ExampleOptProb() {
		myobjfunc = &myvfunc;
		count = 0;
	}
	double (*myobjfunc)(const std::vector<double>&, std::vector<double>&,
			void *);
	int count;
	stringstream expected, test;
	~ExampleOptProb() { /* some teardown */
	}

};
TEST_FIXTURE(ExampleOptProb, derivative_Test) {
	nlopt::opt myopt(nlopt::LN_COBYLA, 2);
	myopt.set_min_objective(myobjfunc, NULL);

	my_constraint_data data[2] = { { 2, 0 }, { -1, 1 } };
	myopt.add_inequality_constraint(myvconstraint, &data[0], 1e-8);
	myopt.add_inequality_constraint(myvconstraint, &data[1], 1e-8);

	// Initial value
	std: vector<double> x(2);
	x[0] = 1.234;
	x[1] = 5.678;

	std::vector<double> lb(2);
	lb[0] = -HUGE_VAL;
	lb[1] = 0;

	myopt.set_lower_bounds(lb);
	myopt.set_stopval(sqrt(8. / 27.) + 1e-3);
	myopt.set_xtol_rel(1e-4);

	double minf;
	try {
		nlopt::result result = myopt.optimize(x, minf);
		if (result < 0)
			throw "NLOpt failed\n";

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "The min value returned from nlopt:" << minf << std::endl;
	expected << "0.544911";
	test << minf;
	CHECK_EQUAL(expected.str(), test.str());
}
}
