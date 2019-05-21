#include <sstream>
#include <iostream>
#include "UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "core_system/math/matrix.h"
#include "core_system/math/ourSimplex_lp_solver/simplex.h"
#include <omp.h>
#include "boost/timer/timer.hpp"

#include <string>
using namespace std;
using namespace math;

SUITE(templated_matrix_class_TestSuite2) {
struct simplex_class {
	simplex_class() {
		// create a direction
		obj_dir.resize(2);
		obj_dir[0] = 4;
		obj_dir[1] = 6;

		// create a matrix
		row = 3;
		col = 2;
		A = math::matrix<double>(row, col);
		A(0, 0) = -1;
		A(0, 1) = 1;
		A(1, 0) = 1;
		A(1, 1) = 1;
		A(2, 0) = 2;
		A(2, 1) = 5;

		b.resize(3);
		b[0] = 11;
		b[1] = 27;
		b[2] = 90;

		s = simplex<double>(A, b, obj_dir);

	}
	~simplex_class() { /* some teardown */
	}

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	std::vector<double> obj_dir, r;
	std::vector<double> b;
	math::matrix<double> A;
	simplex<double> s;
	stringstream out, proper;
};

TEST_FIXTURE(simplex_class, solve_Test) {

	/*	 s.process_lp();
	 r = s.solve();

	 out << s.get_obj_val();
	 proper << "132";
	 CHECK_EQUAL(proper.str(),out.str());

	 obj_dir.resize(3);
	 obj_dir[0] = 3;
	 obj_dir[1] = 1;
	 obj_dir[2] = 2;

	 // create a matrix
	 row = 3;
	 col = 3;
	 A = math::matrix<double>(row, col);
	 A(0, 0) = 1;
	 A(0, 1) = 1;
	 A(0, 2) = 3;
	 A(1, 0) = 2;
	 A(1, 1) = 2;
	 A(1, 2) = 5;
	 A(2, 0) = 4;
	 A(2, 1) = 1;
	 A(2, 2) = 2;

	 b.resize(3);
	 b[0]=30;
	 b[1]=24;
	 b[2]=36;

	 s = simplex<double>(A,b,obj_dir);
	 s.process_lp();
	 r = s.solve();
	 out<<" ";
	 proper<< " ";
	 out << s.get_obj_val();

	 proper << "28";
	 CHECK_EQUAL(proper.str(),out.str());

	 */

	obj_dir.resize(3);

	row = 3;
	col = 3;
	A = math::matrix<double>(row, col);
	obj_dir[0] = 2;
	obj_dir[1] = -3;
	obj_dir[2] = 3;

	// create a matrix

	A(0, 0) = 1;
	A(0, 1) = 1;
	A(0, 2) = -1;
	A(1, 0) = -1;
	A(1, 1) = -1;
	A(1, 2) = 1;
	A(2, 0) = 1;
	A(2, 1) = -2;
	A(2, 2) = 2;

	b.resize(3);
	b[0] = 7;
	b[1] = -7;
	b[2] = 4;

	s = simplex<double>(A, b, obj_dir);
	s.process_lp();
	//s.display_state();
	//r = s.solve();

	/*try {
		r = s.solve();
		throw 0;
	} catch (int err) {
		if (err == 0)
			cout << "No size";
	}*/

	/*std::cout << "AMIT TEST OUR SIMPLEX OBJECTIVE VALUE = " << s.get_obj_val();
	std::cout << std::endl;
*/
	/*

	 obj_dir.resize(2);
	 obj_dir[0] = 3;
	 obj_distd::cout << "values at cnew\n";
	 for (unsigned int i = 1; i < cnew.size(); i++) {
	 std::cout << cnew[i] << std::endl;
	 }r[1] = 2;

	 // create a matrix
	 row = 3;
	 col = 2;
	 A = math::matrix<double>(row, col);
	 A(0, 0) = 2;
	 A(0, 1) = 1;

	 A(1, 0) = 2;
	 A(1, 1) = 3;

	 A(2, 0) = 3;
	 A(2, 1) = 1;


	 b.resize(3);
	 b[0]=18;
	 b[1]=42;
	 b[2]=24;

	 s = simplex<double>(A,b,obj_dir);
	 //s.initialize();
	 s.process_lp();
	 s.display_state();
	 //
	 r = s.solve();
	 out<<" ";
	 proper<< " ";
	 std::cout << s.get_obj_val();
	 out << s.get_obj_val();

	 proper << "33";
	 CHECK_EQUAL(proper.str(),out.str());*/

	/*

	 obj_dir.resize(2);

	 row = 2;
	 col = 2;
	 A = math::matrix<double>(row, col);
	 obj_dir[0] = 2;
	 obj_dir[1] = -1;


	 // create a matrix

	 A(0, 0) = 2;
	 A(0, 1) = -1;
	 A(1, 0) = 1;
	 A(1, 1) = -5;


	 b.resize(2);
	 b[0]=2;
	 b[1]=-4;

	 s = simplex<double>(A,b,obj_dir);
	 s.process_lp();
	 //	 s.display_state();

	 r = s.solve();
	 //out<<" ";
	 //proper<< " ";
	 //out << s.get_obj_val();

	 std::cout << "OPITMAL = " << s.get_obj_val() << std::endl;

	 //	proper << "28";
	 //	CHECK_EQUAL(proper.str(),out.str());

	 */
	/*obj_dir.resize(3);

	 row = 4;
	 col = 3;
	 A = math::matrix<double>(row, col);
	 obj_dir[0] = 1;
	 obj_dir[1] = 0;
	 obj_dir[2] = 0;

	 // create a matrix

	 A(0, 0) = 1;
	 A(0, 1) = 0;
	 A(0, 2) = 0;
	 A(1, 0) = -1;
	 A(1, 1) = 0;
	 A(1, 2) = 0;
	 A(2, 0) = 0;
	 A(2, 1) = 1;
	 A(2, 2) = -1;
	 A(3, 0) = 0;
	 A(3, 1) = -1;
	 A(3, 2) = 1;

	 b.resize(4);
	 b[0]=10.2;
	 b[1]=-10;
	 b[2]=0;
	 b[3]=0;

	 s = simplex<double>(A,b,obj_dir);
	 s.process_lp();

	 r = s.solve();
	 out<<" ";
	 proper<< " ";
	 std::cout << "output from simplex = " << s.get_obj_val();
	 */
	//CHECK_EQUAL(proper.str(),out.str());
}

/*TEST_FIXTURE(simplex_class, initialize_Test) {

 }*/

/*
 TEST_FIXTURE(simplex_class, compare_sequential) {

 obj_dir.resize(3);
 b.resize(3);

 row = 3;
 col = 3;
 A = math::matrix<double>(row, col);

 obj_dir[0] = 2;
 obj_dir[1] = -1;
 obj_dir[2] = 2;

 A(0, 0) = 2;
 A(0, 1) = 1;
 A(0, 2) = 0;
 A(1, 0) = 1;
 A(1, 1) = 2;
 A(1, 2) = -2;
 A(2, 0) = 0;
 A(2, 1) = 1;
 A(2, 2) = 2;

 b[0] = 10;
 b[1] = 20;
 b[2] = 5;

 boost::timer::cpu_timer tt1;
 int number_of_times = 1000000;
 double arr[number_of_times];
 tt1.start();
 for (int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result

 s = simplex<double>(A, b, obj_dir);
 s.process_lp();
 r = s.solve();
 arr[i] = s.get_obj_val();

 }

 tt1.stop();

 double wall_clock, user_clock, system_clock;
 wall_clock = tt1.elapsed().wall / 1000000;//convert nanoseconds to milliseconds
 user_clock = tt1.elapsed().user / 1000000;
 system_clock = tt1.elapsed().system / 1000000;

 std::cout << std::fixed;	//to assign precision on the std::output stream
 std::cout.precision(7);			//cout << setprecision(17);
 std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
 << wall_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:User  (in Seconds) = "
 << user_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:System  (in Seconds) = "
 << system_clock / (double) 1000 << std::endl;

 std::cout << "\nTotal Number of ITERATIONS = " <<number_of_times<<endl;



 std::cout << "Result = " << s.get_obj_val() << endl;
 out << " ";
 proper << " ";
 out << s.get_obj_val();
 proper << "15";
 CHECK_EQUAL(proper.str(), out.str());
 }

 */
/*
 TEST_FIXTURE(simplex_class, compute_OMP) {

 obj_dir.resize(3);
 b.resize(3);

 row = 3;
 col = 3;
 A = math::matrix<double>(row, col);

 obj_dir[0] = 2;
 obj_dir[1] = -1;
 obj_dir[2] = 2;

 A(0, 0) = 2;
 A(0, 1) = 1;
 A(0, 2) = 0;
 A(1, 0) = 1;
 A(1, 1) = 2;
 A(1, 2) = -2;
 A(2, 0) = 0;
 A(2, 1) = 1;
 A(2, 2) = 2;

 b[0] = 10;
 b[1] = 20;
 b[2] = 5;

 boost::timer::cpu_timer tt1;
 int number_of_times = 1000000;
 double arr[number_of_times];

 tt1.start();
 //	omp_set_num_threads(8);
 #pragma omp parallel for
 for (int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result
 simplex<double> simp;
 simp = simplex<double>(A, b, obj_dir);
 simp.process_lp();
 r = simp.solve();
 arr[i] = simp.get_obj_val();
 }

 tt1.stop();

 double wall_clock, user_clock, system_clock;
 wall_clock = tt1.elapsed().wall / 1000000;//convert nanoseconds to milliseconds
 user_clock = tt1.elapsed().user / 1000000;
 system_clock = tt1.elapsed().system / 1000000;

 std::cout << std::fixed;	//to assign precision on the std::output stream
 std::cout.precision(7);			//cout << setprecision(17);
 std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
 << wall_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:User  (in Seconds) = "
 << user_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:System  (in Seconds) = "
 << system_clock / (double) 1000 << std::endl;

 std::cout
 << "\nIN PARALLEL USING OMP CALLS :: Total Number of ITERATIONS = "
 << number_of_times << endl;

 std::cout << "Result = " << arr[1000] << endl;

 }

 */

/*

 TEST_FIXTURE(simplex_class, just_test_omp) {
 //Just verifying the time improvement in OMP approach
 long int sum = 0;
 boost::timer::cpu_timer tt1;
 long int number_of_times = 1000000;
 double arr[number_of_times];
 tt1.start();
 cout<<endl;
 #pragma omp parallel for
 for (int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result
 //	cout<<i<<endl;
 sum = sum + 1;
 }
 tt1.stop();

 double wall_clock, user_clock, system_clock;
 wall_clock = tt1.elapsed().wall / 1000000;//convert nanoseconds to milliseconds
 user_clock = tt1.elapsed().user / 1000000;
 system_clock = tt1.elapsed().system / 1000000;

 std::cout << std::fixed;	//to assign precision on the std::output stream
 std::cout.precision(7);			//cout << setprecision(17);
 std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
 << wall_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:User  (in Seconds) = "
 << user_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:System  (in Seconds) = "
 << system_clock / (double) 1000 << std::endl;

 std::cout
 << "\nIN PARALLEL USING OMP CALLS :: Total Number of ITERATIONS = "
 << number_of_times << endl;

 }

 TEST_FIXTURE(simplex_class, just_test_sequential_time) {
 //Just verifying the time improvement in OMP approach versus Sequential approach
 long int sum = 0;
 boost::timer::cpu_timer tt1;
 long int number_of_times = 1000000;
 double arr[number_of_times];
 tt1.start();
 for (int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result

 sum = sum + 1;
 }
 tt1.stop();

 double wall_clock, user_clock, system_clock;
 wall_clock = tt1.elapsed().wall / 1000000;//convert nanoseconds to milliseconds
 user_clock = tt1.elapsed().user / 1000000;
 system_clock = tt1.elapsed().system / 1000000;

 std::cout << std::fixed;	//to assign precision on the std::output stream
 std::cout.precision(7);			//cout << setprecision(17);
 std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
 << wall_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:User  (in Seconds) = "
 << user_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:System  (in Seconds) = "
 << system_clock / (double) 1000 << std::endl;

 std::cout
 << "\nIN PARALLEL USING Sequential CALLS :: Total Number of ITERATIONS = "
 << number_of_times << endl;

 }
 */

}
