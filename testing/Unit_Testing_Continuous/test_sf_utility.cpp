/*
 * test_sf_utility.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include "application/sf_utility.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "application/DataStructureDirections.h"

using namespace std;

SUITE(sf_utility_TestSuite)
{
	struct ExampleSF_Utility
	{
		ExampleSF_Utility()
		{
			// create a direction
			dir.resize(2);
			dir[0] = -1;
			dir[1] = 2;

			direction2.resize(2);
			direction2[0]=0;
			direction2[1]=1;

			// create a matrix
			typedef math::matrix<double>::size_type stype;
			stype r =  stype(2);
			stype c =  stype(2);
			A = math::matrix<double>(r,c);
			A(0,0) = 1;
			A(0,1) = 2;
			A(1,0) = 3;
			A(1,1) = 4;

			math::matrix<double> Bmatrix;
			row = 2;	col = 2;
			Bmatrix.resize(row, col);
			Bmatrix(0, 0) = 1;
			Bmatrix(0, 1) = 1;
			Bmatrix(1, 0) = 1;
			Bmatrix(1, 1) = 1;

			system_dynamics.MatrixB = Bmatrix;

			//Create polytope V for getting result of V.max_norm for compute_beta
			row=6;	col=2;
			ConstraintsMatrixV.resize(row, col);
				ConstraintsMatrixV(0, 0) = -1;
				ConstraintsMatrixV(0, 1) = 0;
				ConstraintsMatrixV(1, 0) = 0;
				ConstraintsMatrixV(1, 1) = 1;
				ConstraintsMatrixV(2, 0) = 1;
				ConstraintsMatrixV(2, 1) = 1;
				ConstraintsMatrixV(3, 0) = 1;
				ConstraintsMatrixV(3, 1) = 0;
				ConstraintsMatrixV(4, 0) = 0;
				ConstraintsMatrixV(4, 1) = -1;
				ConstraintsMatrixV(5, 0) = -1;
				ConstraintsMatrixV(5, 1) = -1;

				boundValueV.resize(6);

			boundValueV[0] = -1;
			boundValueV[1] = 7;
			boundValueV[2] = 9;
			boundValueV[3] = 3;
			boundValueV[4] =-5;
			boundValueV[5] =-7;

			boundSignV = 1;


			V->setCoeffMatrix(ConstraintsMatrixV);
			V->setColumnVector(boundValueV);
			V->setInEqualitySign(boundSignV);

			system_dynamics.U = V;
			system_dynamics.MatrixA = A;

		}
		~ExampleSF_Utility(){ /* some teardown */}

		typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
			size_type row,col;
		Dynamics system_dynamics;
		polytope::ptr V;
		int boundSignV;
		std::vector<double> boundValueV;
		math::matrix<double> ConstraintsMatrixV;

		std::vector<double> dir, direction2;
		math::matrix<double> A;
		stringstream out,proper;
	};
	TEST_FIXTURE(ExampleSF_Utility, sf_unitball_infnorm_Test)
	{
		double res;
		res = support_unitball_infnorm(dir);
		out<<res;
		//std::cout << res;
		proper << "3";
		CHECK_EQUAL(proper.str(),out.str());
	}

	TEST_FIXTURE(ExampleSF_Utility, compute_beta_Test)
	{
		math::matrix<double> res = math::matrix<double>();
		double tau=2,result;
		result = compute_beta(system_dynamics,tau,1);

		//m2.matrix_exponentiation(res);

		cout<<"\nResult of compute_beta = ";
		cout<<result<<"\t";
		cout<<"Result Over\n ";
		/*out<<result;
		proper << "5200.9";
		CHECK_EQUAL(proper.str(),out.str());*/

	}
	TEST_FIXTURE(ExampleSF_Utility, compute_alfa_Test)
	{
		math::matrix<double> res = math::matrix<double>();
		double tau=2,result;

		result = compute_alfa(tau,system_dynamics,V,1);

		cout<<"\nResult of compute_alfa = ";
		cout<<result<<"\t";
		cout<<"Result Over\n ";
		/*out<<result;
		proper << "26005";
		CHECK_EQUAL(proper.str(),out.str());*/

	}
	TEST_FIXTURE(ExampleSF_Utility, get_ublas_matrix_Test)
	{
		math::matrix<double> res = math::matrix<double>();
		std::vector<std::vector <double> > A;		//Testing vector vector to convert into ublas matrix
		A.resize(2);
		for(int i=0;i<2;i++)
			A[i].resize(2);

		A[0][0]=1;
		A[0][1]=2;
		A[1][0]=3;
		A[1][1]=4;
		get_ublas_matrix(A,res);
		cout<<"\nResult of Get_Ublas_Matrix = ";
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
				cout<<res(i,j)<<"\t";
			cout<<endl;
		}
		cout<<"Result Over\n ";
	}

	TEST_FIXTURE(ExampleSF_Utility, W_Support_Test)
	{

		system_dynamics.MatrixA = A;
		system_dynamics.U->setCoeffMatrix(ConstraintsMatrixV);
		system_dynamics.U->setColumnVector(boundValueV);
		system_dynamics.U->setInEqualitySign(boundSignV);
		double tau=2,result;

		lp_solver lp(1);
		lp.setConstraints(V->getCoeffMatrix(),V->getColumnVector(),V->getInEqualitySign());

		cout << "\nAll Output from W_Support Function\n";
		cout <<"\ttau * SF = "<< tau * V->computeSupportFunction(direction2, lp);

		result = compute_beta(system_dynamics,tau,1);
		cout<<"\t"<<"Beta = "<<result<<"\t";
		double res = support_unitball_infnorm(direction2);
		cout<<"\t"<<"SF_UnitBall = "<<res<<"\t";
		/* todo: deprecated interface  */

		//double final = W_Support(tau,system_dynamics,direction2,2);
//		cout<<"\t"<<"Final W_Support Result = "<<final<<"\t";
		cout<<"Output Over\n ";

	/*	out<<final;
		proper << "5214.9";
		CHECK_EQUAL(proper.str(),out.str());*/
	}

	TEST_FIXTURE(ExampleSF_Utility, Omega_Support_Test)
	{
		system_dynamics.MatrixA = A;
		system_dynamics.U->setCoeffMatrix(ConstraintsMatrixV);
		system_dynamics.U->setColumnVector(boundValueV);
		system_dynamics.U->setInEqualitySign(boundSignV);

		lp_solver lp(1);
		lp.setConstraints(V->getCoeffMatrix(),V->getColumnVector(),V->getInEqualitySign());


		double tau=0.5,res1;
		int Min_Or_Max=2;
		cout << "\nAll Output from Omega_Support Function\n";
		res1 = V->computeSupportFunction(direction2, lp);
		cout <<"\tSF of X_0 = "<< res1;


		math::matrix<double> phi_tau;
		math::matrix<double> phi_tau_Transpose;
		A.matrix_exponentiation(phi_tau, tau);
		std::vector<double> r;
		phi_tau.transpose(phi_tau_Transpose);
		phi_tau_Transpose.mult_vector(direction2,r);

		double term1 = V->computeSupportFunction(r, lp);
		double term2 = tau*V->computeSupportFunction(direction2, lp);
		double term3 = compute_alfa(tau,system_dynamics,V,1) * support_unitball_infnorm(direction2);
		double result = term1 + term2 + term3;
		cout<<"\t"<<"Expression 1 = "<<term1<<"\t";
		cout<<"\t"<<"Expression 2 = "<<term2<<"\t";
		cout<<"\t"<<"Expression 3 = "<<term3<<"\t";
		cout<<"\t"<<"Final Expression = "<<result<<"\t";
		/* todo: deprecated interface */
	//	double final = Omega_Support(tau,direction2,V,system_dynamics,Min_Or_Max);
	//	cout<<"\n"<<"Final Output of OmegaSupport = "<<final<<endl;
		cout<<"Output Over\n ";

	}

}



