/*
 * nlpFunctions.cpp
 *
 *  Contains the NLP instantiation methods and the various objective functions. Each objective function
 *  is to evaluate a different trajectory splicing method.
 *
 *  Created on: 25-Sep-2016
 *      Author: rajarshi
 */

#include "nlpFunctions.h"
#include "vector"

#include "../core/continuous/Polytope/Polytope.h"
#include "../core/math/analyticODESol.h"
#include "application/DataStructureDirections.h"
#include "abstractCE.h"

double myconstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data) {
	polyConstraints *d = reinterpret_cast<polyConstraints*>(data);
	unsigned int id = d->sstate_index;

//	unsigned int row_index = d->row_index;

	assert(id >= 0 && id < N);
	if (!grad.empty()) {
		for (unsigned int i = 0; i < x.size(); i++) {
			grad[i] = 0;
		}
		for (unsigned int j = 0; j < dim; j++)
			grad[id * dim + j] = d->a[j];
	}

	assert(d->a.size() == dim);

	double sum = 0;
	for (unsigned int j = 0; j < dim; j++) {
		//	std::cout << "x at " << i*dim+j << " = " << x[i * dim + j] << std::endl;
		//std::cout << "a at  " << j << " = " << d->a[j] << std::endl;
		sum += x[id * dim + j] * d->a[j];
	}
//	std::cout << "bound " << " = " << d->b << std::endl;
	sum -= d->b;
	return sum;
}

/** Objective function for an iterative NLP-LP (Goran's Idea)
 * @ Rajarshi
 */
//double myobjfunc3(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data)
//{
//	math::matrix<double> expAt(dim,dim);
//	math::matrix<double> A_Inv(dim,dim);
//
//	std::list<transition::ptr>::iterator T_iter = transList.begin();
//
//	lp_solver lp(1); // GLPK solver chosen
//	lp.setMin_Or_Max(2); // Setting a distance minimization problem
//
//	unsigned int i=0;
//	polytope::ptr Trans_p;
//
//
//	for(std::list<symbolic_states::ptr>::const_iterator it = ce_sym_states.begin();it!=ce_sym_states.end();it++)
//	{
//		std::set<int>::iterator dset_iter = (*it)->getDiscreteSet().getDiscreteElements().begin();
//		unsigned int locId = *dset_iter;
//		Dynamics d = HA->getLocation(locId)->getSystem_Dynamics();
//		math::matrix<double> expAt;
//		d.MatrixA.matrix_exponentiation(expAt,x[i]);
//		std::cout << "Time chosen = " << x[i] << std::endl;
//		math::matrix<double> M_inv(d.MatrixA.size1(),d.MatrixA.size2());
//		bool invertible = expAt.inverse(M_inv);
//		if(!invertible){
//			throw std::runtime_error("nlpfunctions: myobjfunc3: expAt matrix not invertible. Required for Time translation of initial set\n");
//		}
//
//		polytope::ptr p = (*it)->getInitialPolytope();
//
//		math::matrix<double> A_prime(d.MatrixA.size1(),d.MatrixA.size2());
//		p->getCoeffMatrix().multiply(M_inv, A_prime);
//
//		if(i==0){
//			p->setCoeffMatrix(A_prime); // p changed to time translated polytope
//			lp.join_poly_constraints(p->getCoeffMatrix(), p->getColumnVector(), p->getInEqualitySign());
//			math::matrix<double> A = p->getCoeffMatrix();
//			std::cout << "Matrix of transpose of polytope for sym state  " << i << std::endl;
//			for(unsigned int row=0;row<A.size1();row++)
//			{
//				for(unsigned int col=0;col<A.size2();col++)
//					std::cout << A(row,col) << " ";
//				std::cout << "\n";
//			}
//		}
//		else {
//			lp.join_poly_constraints(p->getCoeffMatrix(), p->getColumnVector(), p->getInEqualitySign());
//			math::matrix<double> A = p->getCoeffMatrix();
//			std::cout << "Matrix of polytope for sym state  " << i << std::endl;
//			for(unsigned int row=0;row<A.size1();row++)
//			{
//				for(unsigned int col=0;col<A.size2();col++)
//					std::cout << A(row,col) << " ";
//				std::cout << "\n";
//			}
//			p->setCoeffMatrix(A_prime); // p changed to time translated polytope
//			lp.join_poly_constraints(p->getCoeffMatrix(), p->getColumnVector(), p->getInEqualitySign());
//
//			A = p->getCoeffMatrix();
//			std::cout << "Matrix of transpose of polytope for sym state  " << i << std::endl;
//			for(unsigned int row=0;row<A.size1();row++)
//			{
//				for(unsigned int col=0;col<A.size2();col++)
//					std::cout << A(row,col) << " ";
//				std::cout << "\n";
//			}
//		}
//		i++; // counting the symbolic states
//
//	}
//
//	// add the bad set constraints also in the lp
//	lp.join_poly_constraints(bad_poly->getCoeffMatrix(),bad_poly->getColumnVector(),bad_poly->getInEqualitySign());
//
//	math::matrix<double> A = bad_poly->getCoeffMatrix();
//	std::cout << "Matrix of bad polytope"  << std::endl;
//	for(unsigned int row=0;row<A.size1();row++)
//	{
//		for(unsigned int col=0;col<A.size2();col++)
//			std::cout << A(row,col) << " ";
//		std::cout << "\n";
//	}
//	// todo: add additional constraints to convert abs to linear objective function
//	// At this point, the constraint space of the joint LP is created
//
//	lp.add_variables(N);
//
//	unsigned int len = 3; // xi - yi - zi <= 0
//
//	// Add the constraints xi - yi - zi <= 0 and yi - xi - zi <= 0
//	for(unsigned int j=0;j<N;j++)
//	{
//		int ind[len+1]; double val[len+1];
//		int ind1[len+1]; double val1[len+1];
//
//		ind[0] = 0; val[0] = 0;
//		ind1[0] = 0; val1[0] = 0;
//
//		for(unsigned int k=1;k<=dim;k++){
//			ind[1] = 2*j*dim+k; val[1] = 1; // coeff of x_j
//			ind[2] = (2*j+1)*dim+k; val[2]=-1; // coeff of y_j
//			ind[3] = 2*N*dim + j + 1 ; val[3] = -1; //coeff of z_i
//
//			ind1[1] = 2*j*dim+k; val1[k] = -1; //coeff of x_j
//			ind1[2] = (2*j+1)*dim+k; val1[2]= 1; // coeff of y_j
//			ind1[3] = 2*N*dim + j + 1 ; val1[3] = -1; //coeff of z_i
//
//			lp.add_new_constraint(len,ind,val);
//			lp.add_new_constraint(len,ind1,val1);
//		}
//
//	}
//	// set the lp objective function
//	for(unsigned int j=2*N*dim+1;j<2*N*dim+1 + N;j++)
//	{
//		lp.set_obj_coeff(j,1);
//	}
//
//	// debug
//	//lp.set_obj_coeff(0,10);
//	double res = lp.solve();
//	std::cout << "obj function val = " << res << std::endl;
//
////	exit(0);
//	// Assign the answer to the start vectors
//	if(res < 2.5){
//		for(unsigned int i=1;i<N;i++){
//			std::vector<double> v(dim,0);
//			for(unsigned int j=0;j<dim;j++)
//			{
//				v[j] = lp.get_col_val(i*dim+j + 1);
//			}
//			X0[i-1] = v;
//		}
//	}
//
//	return res;
//}
/* objective function */
double myobjfunc2(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {

	// 1. Get the N start vectors and dwell times from x and call the simulation routine
	// 2. Get the N end points of the simulation trace, say, y[i].
	// 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	// Computes the L2 norm or Euclidean distances between the trace end points.
	//-----------------------------------------

	/*This is the vector of end-points of N trajectory segments */
	std::vector<std::vector<double> > y(N);

	double cost = 0;
	std::vector<double> deriv(x.size(), 0); // contains the gradient, all initialized to 0

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);

	math::matrix<double> A, expAt, mapExpAt;
	std::vector<double> Axplusb(dim), mapAxplusb;

	std::ofstream myfile;

	polytope::ptr I;

	for (unsigned int i = 0; i < N; i++) {

		// dxli: v is a copy of state variables. (Get the N start vectors)
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		std::vector<double> traj_dist_grad(dim, 0); // holds the grads of the trajectories distance to invariant

		// dxli: simulate the starting point in the current location (v), for some time (x[N*dim + i]) over some dynamics (d)
		// dxli: analytic solution, rather ODE solver call. This closed form is true only when the input set is singular.
		y[i] = ODESol(v, d, x[N * dim + i]);
		// patch for constant dynamics

		if (d.isEmptyMatrixA) {
			A = math::matrix<double>(dim, dim);
			for (unsigned int i = 0; i < dim; i++) {
				for (unsigned int j = 0; j < dim; j++) {
					A(i, j) = 0;
				}
			}
		} else
			A = d.MatrixA;
		// end of patch

		assert(d.C.size() == dim);

		// dxli: some initialization for calculating derivatives
		math::matrix<double> At(A);
		At.scalar_multiply(x[N * dim + i]);
		At.matrix_exponentiation(expAt);

		A.mult_vector(y[i], Axplusb);
		for (unsigned int j = 0; j < dim; j++) {
			Axplusb[j] = Axplusb[j] + d.C[j];
		}

//		For validation, the distance of trace end points from the invariant is
//		added to the cost
		/*
		 * In Dongxu's version this code is commented
		 * *******Start*******
		 */
		std::vector<double> inv_dist_grad(dim, 0);

		cost += I->point_distance(y[i]); // end point distance to invariant added to cost

		inv_dist_grad = dist_grad(y[i], I);

		for (unsigned int j = 0; j < dim; j++) {
			double dist_gradx_j = 0;
			for (unsigned int k = 0; k < dim; k++) {
				dist_gradx_j += inv_dist_grad[k] * expAt(k, j);
			}
			deriv[i * dim + j] += dist_gradx_j;

		}
//		 add the cost gradient w.r.t traj segment's dwell time
		double dist_gradt = 0;
		for (unsigned int j = 0; j < dim; j++) {
			dist_gradt += inv_dist_grad[j] * Axplusb[j];
		}
		deriv[N * dim + i] += dist_gradt;

		/*
		 * In Dongxu's version this code is commented
		 * *******End*******
		 */

		//end of validation logic
		if (i == N - 1) {
			// compute the distance of this endpoint with the forbidden polytope \cap invariant (the segment end point must lie
			// in the intersection of the bad_set and the last location invariant).

			cost += bad_poly->point_distance(y[N - 1]);

			std::vector<double> badpoly_dist_grad(dim, 0);

			badpoly_dist_grad = dist_grad(y[N - 1], bad_poly);

			for (unsigned int j = 0; j < dim; j++) {
				double dist_gradx_j = 0;
				for (unsigned int k = 0; k < dim; k++) {
					dist_gradx_j += badpoly_dist_grad[k] * expAt(k, j);
				}
				deriv[(N - 1) * dim + j] += dist_gradx_j;
			}

			//	add the cost gradient w.r.t last traj segment's dwell time

			double dist_gradt = 0;
			for (unsigned int j = 0; j < dim; j++) {
				dist_gradt += badpoly_dist_grad[j] * Axplusb[j];
			}
			deriv[N * dim + N - 1] += dist_gradt;

			break;
		} else {
			polytope::ptr g;
			Assign R;
			math::matrix<double> mapExpAt(expAt);
			// assign the transition pointer
			Tptr = *(T_iter);
			// assignment of the form: Rx + w

			R = Tptr->getAssignT();
			//guard as a polytope
			g = Tptr->getGaurd();

			std::vector<double> mapderiv(Axplusb);

			// guard \cap invariant distance, to address Eq. (12) in CDC 13' paper
			polytope::ptr guard_intersect_inv;
			guard_intersect_inv = I->GetPolytope_Intersection(g);

			// plot the guard intersection with location invariant
//			if(loc_index == 7){
//				guard_intersect_inv->print2file("./guard_intersect.txt",0,1);
//			}
			//-----------------------------------------------------
			double guard_dist = guard_intersect_inv->point_distance(y[i]);
//			double guard_dist = I->point_distance(y[i]);
			cost += guard_dist;

			std::vector<double> guard_dist_grad(dim, 0);
			guard_dist_grad = dist_grad(y[i], guard_intersect_inv);

			for (unsigned int j = 0; j < dim; j++) {
				double dist_gradx_j = 0;
				for (unsigned int k = 0; k < dim; k++) {
					dist_gradx_j += guard_dist_grad[k] * expAt(k, j);
				}
				deriv[i * dim + j] += dist_gradx_j;

			}

			// dxli: add derivative of guard \cup invariant wrt dwell time
			double dist_gradt = 0;
			for (unsigned int j = 0; j < dim; j++) {
				dist_gradt += guard_dist_grad[j] * Axplusb[j];
			}
			deriv[N * dim + i] += dist_gradt;

			assert(y[i].size() == R.Map.size2());
			std::vector<double> transform(y[i].size(), 0);
			R.Map.mult_vector(y[i], transform);
			for (unsigned int j = 0; j < transform.size(); j++)
				y[i][j] = transform[j] + R.b[j];

			R.Map.multiply(expAt, mapExpAt);
			R.Map.mult_vector(Axplusb, mapAxplusb);

			assert(y[i].size() == R.b.size());

			T_iter++; // Moving to the next transition.

			//compute the Euclidean distance between the next start point and the simulated end point
			for (unsigned int j = 0; j < dim; j++) {
				cost += (y[i][j] - x[(i + 1) * dim + j])
						* (y[i][j] - x[(i + 1) * dim + j]);

				for (unsigned int k = 0; k < dim; k++) {
					deriv[i * dim + j] += 2 * (y[i][k] - x[(i + 1) * dim + k])
							* mapExpAt(k, j);
				}
				if (i != 0) {
					deriv[i * dim + j] += -2 * (y[(i - 1)][j] - x[i * dim + j]);
				}
				deriv[N * dim + i] += 2 * (y[i][j] - x[(i + 1) * dim + j])
						* mapAxplusb[j];
			}
		}

	} // End of for-loop over i

	if (N != 1) { // The abstract CE has at least one discrete jump, and therefore at least one splicing point.
		for (unsigned int j = 0; j < dim; j++)
			deriv[(N - 1) * dim + j] = -2
					* (y[N - 2][j] - x[(N - 1) * dim + j]);
	}

#ifdef VALIDATION
// add to cost the distance of refinement points. Modify the derivatives.

	//std::cout << "Running with trajectory validation enabled\n";

	for (std::list<refinement_point>::iterator it = ref_pts.begin();
			it != ref_pts.end(); it++) {
		refinement_point p = *it;
		assert(p.seq_no < N);
		unsigned int locID = locIdList[p.seq_no];

		double dwell_time = x[N * dim + p.seq_no];
		// if the sampled time is less than the time when the refinement point violated the Inv, then ignore this refinement
		if (dwell_time < p.time)
			continue;
		// Compute the new point v at p.time units from the new sampled start point.
		Dynamics d = HA->getLocation(locID)->getSystem_Dynamics();
		polytope::ptr I = HA->getLocation(locID)->getInvariant();
		assert(d.C.size() == dim);

		std::vector<double> v(dim);
		for (unsigned int i = 0; i < dim; i++)
			v[i] = x[p.seq_no * dim + i];

		v = ODESol(v, d, p.time);
		// patch for constant dynamics

		math::matrix<double> A;
		if (d.isEmptyMatrixA) {
			A = math::matrix<double>(dim, dim);
			for (unsigned int i = 0; i < dim; i++) {
				for (unsigned int j = 0; j < dim; j++) {
					A(i, j) = 0;
				}
			}
		} else
			A = d.MatrixA;

		double dist = I->point_distance(v);

		if (dist > 0) {
			cost += dist;
			math::matrix<double> expAt;
			A.matrix_exponentiation(expAt, p.time);

			std::vector<double> I_dist_grad(dim);
			I_dist_grad = dist_grad(v, I);

			for (unsigned int j = 0; j < dim; j++) {
				double I_dist_grad_j = 0;
				for (unsigned int k = 0; k < dim; k++) {
					I_dist_grad_j += I_dist_grad[k] * expAt(k, j);
				}
				deriv[p.seq_no * dim + j] += I_dist_grad_j;
			}
			// derivative wrt dwell time
			std::vector<double> Axplusb;

			A.mult_vector(v, Axplusb);
			for (unsigned int j = 0; j < dim; j++) {
				Axplusb[j] = Axplusb[j] + d.C[j];
			}

			double dist_gradt = 0;
			for (unsigned int j = 0; j < dim; j++) {
				dist_gradt += I_dist_grad[j] * Axplusb[j];
			}

			deriv[N * dim + p.seq_no] += dist_gradt;
		}
	}
#endif

	// Analytic gradients
	if (!grad.empty()) {
		for (unsigned int i = 0; i < x.size(); i++) {
			grad[i] = deriv[i];
		}
	}
	//std::cout << "current cost=" << cost << std::endl;
	return cost;

}

double myobjfuncOnStateVars(const std::vector<double> &x,
		std::vector<double> &grad, void *my_func_data) {
	std::vector<double> t = *((std::vector<double>*) my_func_data);

	/*This is the vector of end-points of N trajectory segments */
	std::vector<std::vector<double> > y(N);

	double cost = 0;
	std::vector<double> deriv(x.size(), 0); // contains the gradient, all initialized to 0

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);

	math::matrix<double> A, expAt, mapExpAt;
	std::vector<double> Axplusb(dim), mapAxplusb;

	std::ofstream myfile;
	myfile.open("./endpoints");

	polytope::ptr I;

	for (unsigned int i = 0; i < N; i++) {

		// dxli: v is a copy of state variables. (Get the N start vectors)
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		std::vector<double> traj_dist_grad(dim, 0); // holds the grads of the trajectories distance to invariant

		// dxli: simulate the starting point in the current location (v), for some time (x[N*dim + i]) over some dynamics (d)
		// dxli: analytic solution, rather ODE solver call. This closed form is true only when the input set is singular.
		y[i] = ODESol(v, d, t[i]);
//		y[i] = ODESol(v,d,x[N*dim + i]);
		// patch for constant dynamics

		if (d.isEmptyMatrixA) {
			A = math::matrix<double>(dim, dim);
			for (unsigned int i = 0; i < dim; i++) {
				for (unsigned int j = 0; j < dim; j++) {
					A(i, j) = 0;
				}
			}
		} else
			A = d.MatrixA;
		// end of patch

		assert(d.C.size() == dim);

		// dxli: some initialization for calculating derivatives
		math::matrix<double> At(A);
//		At.scalar_multiply(x[N*dim+i]);
		At.scalar_multiply(t[i]);
		At.matrix_exponentiation(expAt);

		A.mult_vector(y[i], Axplusb);
		for (unsigned int j = 0; j < dim; j++) {
			Axplusb[j] = Axplusb[j] + d.C[j];
		}

//		For validation, the distance of trace end points from the guard \cap invariant is
//		added to the cost

//		std::vector<double> inv_dist_grad(dim,0);
//
//		cost+= I->point_distance(y[i]); // end point distance to invariant added to cost
//
//		inv_dist_grad = dist_grad(y[i],I);
//
//		for(unsigned int j=0;j<dim;j++) {
//			double dist_gradx_j = 0;
//			for(unsigned int k=0;k<dim;k++)
//			{
//				dist_gradx_j +=  inv_dist_grad[k] * expAt(k,j);
//			}
//			deriv[i*dim+j] += dist_gradx_j;
//
//		}
		// add the cost gradient w.r.t traj segment's dwell time
//		double dist_gradt = 0;
//		for(unsigned int j=0;j<dim;j++)
//		{
//			dist_gradt +=  inv_dist_grad[j] * Axplusb[j];
//		}
//		deriv[N*dim + i] += dist_gradt;

		//end of validation logic

		if (i == N - 1) {
			// compute the distance of this endpoint with the forbidden polytope \cap invariant (the segment end point must lie
			// in the intersection of the bad_set and the last location invariant).

			cost += bad_poly->point_distance(y[N - 1]);

			std::vector<double> badpoly_dist_grad(dim, 0);

			badpoly_dist_grad = dist_grad(y[N - 1], bad_poly);

//			std::vector<double> badpoly_dist_grad_numeric = dist_grad_by_definition(y[N-1], bad_poly);

//			for (int i =0; i < dim; i++){
//				cout << "difference: " << badpoly_dist_grad[i] - badpoly_dist_grad_numeric[i] << endl;
////				cout << "analytic gradient: " << badpoly_dist_grad[i] << "; numeric gradient: " << badpoly_dist_grad_numeric[i] << endl;
//			}
//			cout << endl;

			for (unsigned int j = 0; j < dim; j++) {
				double dist_gradx_j = 0;
				for (unsigned int k = 0; k < dim; k++) {
					dist_gradx_j += badpoly_dist_grad[k] * expAt(k, j);
				}
				deriv[(N - 1) * dim + j] += dist_gradx_j;
			}
			break;
		} else {
			polytope::ptr g;
			Assign R;
			math::matrix<double> mapExpAt(expAt);
			// assign the transition pointer
			Tptr = *(T_iter);
			// assignment of the form: Rx + w

			R = Tptr->getAssignT();
			//guard as a polytope
			g = Tptr->getGaurd();

			std::vector<double> mapderiv(Axplusb);

			// guard \cap invariant distance, to address Eq. (12) in CDC 13' paper
			polytope::ptr guard_intersect_inv;
			guard_intersect_inv = I->GetPolytope_Intersection(g);

			// plot the guard intersection with location invariant
//			if(loc_index == 7){
//				guard_intersect_inv->print2file("./guard_intersect.txt",0,1);
//			}
			//-----------------------------------------------------
			double guard_dist = guard_intersect_inv->point_distance(y[i]);
//			double guard_dist = I->point_distance(y[i]);
			cost += guard_dist;

			std::vector<double> guard_dist_grad(dim, 0);
			guard_dist_grad = dist_grad(y[i], guard_intersect_inv);

			for (unsigned int j = 0; j < dim; j++) {
				double dist_gradx_j = 0;
				for (unsigned int k = 0; k < dim; k++) {
					dist_gradx_j += guard_dist_grad[k] * expAt(k, j);
				}
				deriv[i * dim + j] += dist_gradx_j;

			}

			assert(y[i].size() == R.Map.size2());
			std::vector<double> transform(y[i].size(), 0);
			R.Map.mult_vector(y[i], transform);
			for (unsigned int j = 0; j < transform.size(); j++)
				y[i][j] = transform[j] + R.b[j];

			R.Map.multiply(expAt, mapExpAt);
			R.Map.mult_vector(Axplusb, mapAxplusb);

			assert(y[i].size() == R.b.size());

			T_iter++; // Moving to the next transition.

			//compute the Euclidean distance between the next start point and the simulated end point
			for (unsigned int j = 0; j < dim; j++) {
				cost += (y[i][j] - x[(i + 1) * dim + j])
						* (y[i][j] - x[(i + 1) * dim + j]);

				for (unsigned int k = 0; k < dim; k++) {
					deriv[i * dim + j] += 2 * (y[i][k] - x[(i + 1) * dim + k])
							* mapExpAt(k, j);
				}
				if (i != 0) {
					deriv[i * dim + j] += -2 * (y[(i - 1)][j] - x[i * dim + j]);
				}
			}
		}

	} // End of for-loop over i

	if (N != 1) { // The abstract CE has at least one discrete jump, and therefore at least one splicing point.
		for (unsigned int j = 0; j < dim; j++)
			deriv[(N - 1) * dim + j] = -2
					* (y[N - 2][j] - x[(N - 1) * dim + j]);
	}
//
//
//#ifdef VALIDATION
//// add to cost the distance of refinement points. Modify the derivatives.
//
//	//std::cout << "Running with trajectory validation enabled\n";
//
//	for(std::list<refinement_point>::iterator it = ref_pts.begin();it!=ref_pts.end();it++)
//	{
//		refinement_point p = *it;
//		assert(p.seq_no<N);
//		unsigned int locID = locIdList[p.seq_no];
//
//		double dwell_time = x[N*dim+p.seq_no];
//		// if the sampled time is less than the time when the refinement point violated the Inv, then ignore this refinement
//		if(dwell_time < p.time)
//			continue;
//		// Compute the new point v at p.time units from the new sampled start point.
//		Dynamics d = HA->getLocation(locID)->getSystem_Dynamics();
//		polytope::ptr I = HA->getLocation(locID)->getInvariant();
//		assert(d.C.size() == dim);
//
//		std::vector<double> v(dim);
//		for(unsigned int i=0;i<dim;i++)
//			v[i] = x[p.seq_no*dim+i];
//
//		v = ODESol(v, d, p.time);
//		// patch for constant dynamics
//
//		math::matrix<double> A;
//		if(d.isEmptyMatrixA){
//			A = math::matrix<double>(dim,dim);
//			for(unsigned int i=0;i<dim;i++){
//				for(unsigned int j=0;j<dim;j++){
//					A(i,j)=0;
//				}
//			}
//		}
//		else
//			A = d.MatrixA;
//
//		double dist = I->point_distance(v);
//
//		if(dist>0) {
//			cost+= dist;
//			math::matrix<double> expAt;
//			A.matrix_exponentiation(expAt,p.time);
//
//			std::vector<double> I_dist_grad(dim);
//			I_dist_grad = dist_grad(v,I);
//
//			for(unsigned int j=0;j<dim;j++){
//				double I_dist_grad_j = 0;
//				for(unsigned int k=0;k<dim;k++){
//					I_dist_grad_j += I_dist_grad[k] * expAt(k,j);
//				}
//				deriv[p.seq_no*dim+j] += I_dist_grad_j;
//			}
//			// derivative wrt dwell time
//			std::vector<double> Axplusb;
//
//			A.mult_vector(v,Axplusb);
//			for (unsigned int j = 0; j < dim; j++) {
//				Axplusb[j] = Axplusb[j] + d.C[j];
//			}
//
//			double dist_gradt = 0;
//			for(unsigned int j=0;j<dim;j++)
//			{
//				dist_gradt +=  I_dist_grad[j] * Axplusb[j];
//			}
//
//			deriv[N*dim + p.seq_no] += dist_gradt;
//		}
//	}
//#endif

	// Analytic gradients
	if (!grad.empty()) {
		for (unsigned int i = 0; i < x.size(); i++) {
			grad[i] = deriv[i];
		}
	}
	std::cout << "opt over x, current cost=" << cost << std::endl;
	return cost;
}

double myobjfuncOnDwellTime(const std::vector<double> &t,
		std::vector<double> &grad, void *my_func_data) {

	std::vector<double> x = *((std::vector<double>*) my_func_data);
	// 1. Get the N start vectors and dwell times from x and call the simulation routine
	// 2. Get the N end points of the simulation trace, say, y[i].
	// 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	// Computes the L2 norm or Euclidean distances between the trace end points.
	//-----------------------------------------

	/*This is the vector of end-points of N trajectory segments */
	std::vector<std::vector<double> > y(N);

	double cost = 0;
	std::vector<double> deriv(t.size(), 0); // contains the gradient, all initialized to 0

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);

	math::matrix<double> A, expAt, mapExpAt;
	std::vector<double> Axplusb(dim), mapAxplusb;

	std::ofstream myfile;
	myfile.open("./endpoints");

	polytope::ptr I;

//	cout << "before loop over i" << endl;
	for (unsigned int i = 0; i < N; i++) {

		// dxli: v is a copy of state variables. (Get the N start vectors)
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}
//		cout << "line 819" << endl;

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		std::vector<double> traj_dist_grad(dim, 0); // holds the grads of the trajectories distance to invariant

		// dxli: simulate the starting point in the current location (v), for some time (x[N*dim + i]) over some dynamics (d)
		// dxli: analytic solution, rather ODE solver call. This closed form is true only when the input set is singular.
		y[i] = ODESol(v, d, t[i]);
		// patch for constant dynamics

		if (d.isEmptyMatrixA) {
			A = math::matrix<double>(dim, dim);
			for (unsigned int i = 0; i < dim; i++) {
				for (unsigned int j = 0; j < dim; j++) {
					A(i, j) = 0;
				}
			}
		} else
			A = d.MatrixA;
		// end of patch

//		cout << "line 845" << endl;
		assert(d.C.size() == dim);

		// dxli: some initialization for calculating derivatives
		math::matrix<double> At(A);
		At.scalar_multiply(t[i]);
		At.matrix_exponentiation(expAt);

		A.mult_vector(y[i], Axplusb);
		for (unsigned int j = 0; j < dim; j++) {
			Axplusb[j] = Axplusb[j] + d.C[j];
		}

//		cout << "line 857" << endl;
//		For validation, the distance of trace end points from the guard \cap invariant is
//		added to the cost

//		std::vector<double> inv_dist_grad(dim,0);
//
//		cost+= I->point_distance(y[i]); // end point distance to invariant added to cost
//
//		inv_dist_grad = dist_grad(y[i],I);
//
//		for(unsigned int j=0;j<dim;j++) {
//			double dist_gradx_j = 0;
//			for(unsigned int k=0;k<dim;k++)
//			{
//				dist_gradx_j +=  inv_dist_grad[k] * expAt(k,j);
//			}
//			deriv[i*dim+j] += dist_gradx_j;
//
//		}
		// add the cost gradient w.r.t traj segment's dwell time
//		double dist_gradt = 0;
//		for(unsigned int j=0;j<dim;j++)
//		{
//			dist_gradt +=  inv_dist_grad[j] * Axplusb[j];
//		}
//		deriv[N*dim + i] += dist_gradt;

		//end of validation logic

		if (i == N - 1) {
			// compute the distance of this endpoint with the forbidden polytope \cap invariant (the segment end point must lie
			// in the intersection of the bad_set and the last location invariant).

//			cout << "line  891" << endl;
			cost += bad_poly->point_distance(y[N - 1]);

			std::vector<double> badpoly_dist_grad(dim, 0);

			badpoly_dist_grad = dist_grad(y[N - 1], bad_poly);

			//	add the cost gradient w.r.t last traj segment's dwell time

			double dist_gradt = 0;
			for (unsigned int j = 0; j < dim; j++) {
				dist_gradt += badpoly_dist_grad[j] * Axplusb[j];
			}
//			deriv[N*dim + N - 1] += dist_gradt;
			deriv[N - 1] += dist_gradt;

			break;
		} else {
//			cout << "line  911" << endl;
			polytope::ptr g;
			Assign R;
			math::matrix<double> mapExpAt(expAt);
			// assign the transition pointer
			Tptr = *(T_iter);
			// assignment of the form: Rx + w

			R = Tptr->getAssignT();
			//guard as a polytope
			g = Tptr->getGaurd();

			std::vector<double> mapderiv(Axplusb);

			// guard \cap invariant distance, to address Eq. (12) in CDC 13' paper
			polytope::ptr guard_intersect_inv;
			guard_intersect_inv = I->GetPolytope_Intersection(g);

			// plot the guard intersection with location invariant
//			if(loc_index == 7){
//				guard_intersect_inv->print2file("./guard_intersect.txt",0,1);
//			}
			//-----------------------------------------------------
			double guard_dist = guard_intersect_inv->point_distance(y[i]);
//			double guard_dist = I->point_distance(y[i]);
			cost += guard_dist;

			std::vector<double> guard_dist_grad(dim, 0);
			guard_dist_grad = dist_grad(y[i], guard_intersect_inv);

			// dxli: add derivative of guard \cup invariant wrt dwell time
			double dist_gradt = 0;
			for (unsigned int j = 0; j < dim; j++) {
				dist_gradt += guard_dist_grad[j] * Axplusb[j];
			}
//			deriv[N*dim + i] += dist_gradt;
			deriv[i] += dist_gradt;

//			cout << "line  949" << endl;
			assert(y[i].size() == R.Map.size2());
			std::vector<double> transform(y[i].size(), 0);
//			cout << "line  953" << endl;
			R.Map.mult_vector(y[i], transform);
			for (unsigned int j = 0; j < transform.size(); j++)
				y[i][j] = transform[j] + R.b[j];

//			cout << "line  957" << endl;
			R.Map.multiply(expAt, mapExpAt);
//			cout << "line  960" << endl;
			R.Map.mult_vector(Axplusb, mapAxplusb);
//			cout << "line  962" << endl;

			assert(y[i].size() == R.b.size());

//			cout << "line  962" << endl;
			T_iter++; // Moving to the next transition.

			//compute the Euclidean distance between the next start point and the simulated end point
//			cout << "line  971" << endl;
			for (unsigned int j = 0; j < dim; j++) {
				cost += (y[i][j] - x[(i + 1) * dim + j])
						* (y[i][j] - x[(i + 1) * dim + j]);
//				deriv[N*dim+i] += 2*(y[i][j] - x[(i+1)*dim + j]) * mapAxplusb[j];
				deriv[i] += 2 * (y[i][j] - x[(i + 1) * dim + j])
						* mapAxplusb[j];
			}
		}

//		cout << "line  979" << endl;
	} // End of for-loop over i
//
//	cout << "end looping over i" << endl;
//	if(N!=1){ // The abstract CE has at least one discrete jump, and therefore at least one splicing point.
//		for(unsigned int j=0;j<dim;j++)
//			deriv[(N-1)*dim+j] = -2*(y[N-2][j] - x[(N-1)*dim+j]);
//	}

//#ifdef VALIDATION
//// add to cost the distance of refinement points. Modify the derivatives.
//
//	//std::cout << "Running with trajectory validation enabled\n";
//
//	for(std::list<refinement_point>::iterator it = ref_pts.begin();it!=ref_pts.end();it++)
//	{
//		refinement_point p = *it;
//		assert(p.seq_no<N);
//		unsigned int locID = locIdList[p.seq_no];
//
//		double dwell_time = x[N*dim+p.seq_no];
//		// if the sampled time is less than the time when the refinement point violated the Inv, then ignore this refinement
//		if(dwell_time < p.time)
//			continue;
//		// Compute the new point v at p.time units from the new sampled start point.
//		Dynamics d = HA->getLocation(locID)->getSystem_Dynamics();
//		polytope::ptr I = HA->getLocation(locID)->getInvariant();
//		assert(d.C.size() == dim);
//
//		std::vector<double> v(dim);
//		for(unsigned int i=0;i<dim;i++)
//			v[i] = x[p.seq_no*dim+i];
//
//		v = ODESol(v, d, p.time);
//		// patch for constant dynamics
//
//		math::matrix<double> A;
//		if(d.isEmptyMatrixA){
//			A = math::matrix<double>(dim,dim);
//			for(unsigned int i=0;i<dim;i++){
//				for(unsigned int j=0;j<dim;j++){
//					A(i,j)=0;
//				}
//			}
//		}
//		else
//			A = d.MatrixA;
//
//		double dist = I->point_distance(v);
//
//		if(dist>0) {
//			cost+= dist;
//			math::matrix<double> expAt;
//			A.matrix_exponentiation(expAt,p.time);
//
//			std::vector<double> I_dist_grad(dim);
//			I_dist_grad = dist_grad(v,I);
//
//			for(unsigned int j=0;j<dim;j++){
//				double I_dist_grad_j = 0;
//				for(unsigned int k=0;k<dim;k++){
//					I_dist_grad_j += I_dist_grad[k] * expAt(k,j);
//				}
//				deriv[p.seq_no*dim+j] += I_dist_grad_j;
//			}
//			// derivative wrt dwell time
//			std::vector<double> Axplusb;
//
//			A.mult_vector(v,Axplusb);
//			for (unsigned int j = 0; j < dim; j++) {
//				Axplusb[j] = Axplusb[j] + d.C[j];
//			}
//
//			double dist_gradt = 0;
//			for(unsigned int j=0;j<dim;j++)
//			{
//				dist_gradt +=  I_dist_grad[j] * Axplusb[j];
//			}
//
//			deriv[N*dim + p.seq_no] += dist_gradt;
//		}
//	}
//#endif

//	cout << "before copying gradient" << endl;
	// Analytic gradients
	if (!grad.empty()) {
		for (unsigned int i = 0; i < t.size(); i++) {
			grad[i] = deriv[i];
		}
	}
//	cout << "end copying gradient" << endl;
//	std::cout << "opt over t: current cost=" << cost << std::endl;
	return cost;

}

/*
 * Amit:
 * Function to compute dist(endPoints, startPoints) + dist(endPoints, Reach ^ Guard) + dist(endPoints, Bad_Set)
 * Here endPoints are computed using the equation x* = e^(At) x + v
 * startPoints are fixed vectors taken as inputs.
 */
double myobjfuncIterativeNLP(const std::vector<double> &t,
		std::vector<double> &grad, void *my_func_data) {

// 1. Get the N start vectors (fixed-constants) and dwell times (variables) and call the simulation routine to get endpoints, say y[i]
// 2. Get the N end points of the simulation trace, say, y[i].
// 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
// Computes the L2 norm or Euclidean distances between the trace end points.
//-----------------------------------------
//	cout << "Inside myobjfuncIterative NLP due to call from optimize" << endl;
	//Current use std::vector<double> *x = (std::vector<double>*) my_func_data;
	std::vector<double> *x = reinterpret_cast<std::vector<double>*>(my_func_data);
	//std::vector<double> *x = (std::vector<double>*) my_func_data;

//	cout << "N=" << N << "   dim=" << dim << endl;
/*

	cout << "FixedStartPoints are \n";
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < dim; j++) {
			cout << x[i][j] << "  ";
		}
	}
	cout << endl;
	cout << endl;
*/



//	cout << "1 success"<<endl;
//	std::vector<std::vector<double>> x =
//			*((std::vector<std::vector<double>>*) my_func_data); //N start vectors (fixed-constants)

	/*This is the vector of end-points of N trajectory segments to be computed*/
	std::vector<std::vector<double> > y(N);
	double cost = 0;
	std::vector<double> deriv(N, 0); // contains the gradient, all initialized to 0.

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);
	math::matrix<double> A, expAt, mapExpAt;
	//std::vector<double> Axplusb(dim); //this is causing error
	std::vector < double > myAxPlusb(dim);
	//double myAxPlusb[dim];

	std::vector<double> mapAxplusb;

//	std::ofstream myfile;
//	myfile.open("./endpoints");

	polytope::ptr I;

	for (unsigned int i = 0; i < N; i++) {

//		cout << "After 1 loop over i" << endl;
		// dxli: v is a copy of state variables. (Get the N start vectors)
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i][j];
			//v[j] = x[i * dim+j];
		}

		int loc_index = locIdList[i]; //global variable populated already
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		std::vector<double> traj_dist_grad(dim, 0); // holds the grads of the trajectories distance to invariant

		//Simulate the starting point in the current location (v), for some time (t[i], i \in N) over some dynamics (d)
		//dxli: analytic solution, rather ODE solver call. This closed form is true only when the input set is singular.
		y[i] = ODESol(v, d, t[i]);
		// patch for constant dynamics

		if (d.isEmptyMatrixA) {
			A.resize(dim,dim);	// = math::matrix<double>(dim, dim);
			A.clear(); //Amit: writes zero for all elements
		} else
			A = d.MatrixA;
		// end of patch
		assert(d.C.size() == dim);

		math::matrix<double> At(A);
	//	cout << "7Success" << endl;
		At.scalar_multiply(t[i]);
		At.matrix_exponentiation(expAt);

		A.mult_vector(y[i], myAxPlusb);
		for (unsigned int j = 0; j < dim; j++) {
			myAxPlusb[j] = myAxPlusb[j] + d.C[j];
		}

//		cout << "8Success" << endl;
		//		For validation, the distance of trace end points from the invariant is
		//		added to the cost
/*
		std::vector<double> inv_dist_grad(dim, 0);

		cost += I->point_distance(y[i]); // end point distance to invariant added to cost; Soft-Constriant check on inv
//		cout << "9Success" << endl;
		inv_dist_grad = dist_grad(y[i], I);
//		cout << "8Success" << endl;

//		cout << "9Success" << endl;
		//	add the cost gradient w.r.t traj segment's dwell time
		double dist_gradt = 0;
		for (unsigned int j = 0; j < dim; j++) {
			dist_gradt += inv_dist_grad[j] * myAxPlusb[j];
		}
		//cout << "12Success" << endl;
		//deriv[N * dim + i] += dist_gradt;
		deriv[i] = dist_gradt;

*/


//end of validation logic
		if (i == N - 1) {
			// compute the distance of this endpoint with the forbidden polytope \cap invariant (the segment end point must lie
			// in the intersection of the bad_set and the last location invariant).

		//	cout << "Inside Last transition 1" << endl;
			cost += bad_poly->point_distance(y[N - 1]); // end point distance to bad-set added to cost; Soft-Constriant check on bad-set
//			cout<<"Inside bad-set = "<< bad_poly->point_distance(y[N - 1])<<endl;
			std::vector<double> badpoly_dist_grad(dim, 0);

			badpoly_dist_grad = dist_grad(y[N - 1], bad_poly);
		//	cout << "Inside Last transition 2" << endl;
		//	cout << "Inside Last transition 3" << endl;

			//	add the cost gradient w.r.t last traj segment's dwell time
			double dist_gradt = 0;
			for (unsigned int j = 0; j < dim; j++) {
				dist_gradt += badpoly_dist_grad[j] * myAxPlusb[j];
			}
			//deriv[N * dim + N - 1] += dist_gradt;
			deriv[i] = dist_gradt;
		//	cout << "Inside Last transition 4" << endl;
			break;
		} else {
	//		cout <<"         Loop "<<i << "     \n";
//			cout << "line  911" << endl;
			polytope::ptr g;
			Assign R;

			// assign the transition pointer
			Tptr = *(T_iter);
			// assignment of the form: Rx + w

			R = Tptr->getAssignT();

			//guard as a polytope
			g = Tptr->getGaurd();
	//		cout << "A Success" << endl;


			// guard \cap invariant distance, to address Eq. (12) in CDC 13' paper
			polytope::ptr guard_intersect_inv;
			guard_intersect_inv = I->GetPolytope_Intersection(g);

	//		cout << "B Success" << endl;
			// plot the guard intersection with location invariant
//			if(loc_index == 7){
//				guard_intersect_inv->print2file("./guard_intersect.txt",0,1);
//			}
			//-----------------------------------------------------
			double guard_dist = guard_intersect_inv->point_distance(y[i]);
			cost += guard_dist;
//			cout <<"Point y["<<i<<"] is inside ="<<guard_dist<<endl;


	//		cout << "C Success" << endl;
			std::vector<double> guard_dist_grad(dim, 0);
			guard_dist_grad = dist_grad(y[i], guard_intersect_inv);

	//		cout << "D 1 Success" << endl;

	//		cout << "D Success" << endl;

			// dxli: add derivative of guard \cup invariant wrt dwell time
			double dist_gradt = 0;
			for (unsigned int j = 0; j < dim; j++) {
				dist_gradt += guard_dist_grad[j] * myAxPlusb[j];
			}

	//		cout << "E Success" << endl;
			//deriv[N * dim + i] += dist_gradt;
			deriv[i] = dist_gradt;

//cout << "y[i].size"<<y[i].size()<<"   R.map.size2()="<<R.Map.size2() << endl;
			assert(y[i].size() == R.Map.size2());
			std::vector<double> transform(y[i].size(), 0);
//			cout << "line  953" << endl;
			R.Map.mult_vector(y[i], transform);
			for (unsigned int j = 0; j < transform.size(); j++)
				y[i][j] = transform[j] + R.b[j];

	//		cout << "F Success" << endl;
//			cout << "line  957" << endl;

//			cout << "line  960" << endl;
			R.Map.mult_vector(myAxPlusb, mapAxplusb);
//			cout << "line  962" << endl;

			assert(y[i].size() == R.b.size());

//			cout << "line  962" << endl;
			T_iter++; // Moving to the next transition.

	//		cout << "G Success" << endl;
			//compute the Euclidean distance between the next start point and the simulated end point
			for (unsigned int j = 0; j < dim; j++) {
				//cost += (y[i][j] - x[(i + 1) * dim + j]) * (y[i][j] - x[(i + 1) * dim + j]);
				//cost += (y[i][j] - x[(i + 1) * dim][j]) * (y[i][j] - x[(i + 1) * dim][j]);
				cost += (y[i][j] - x[(i + 1)][j]) * (y[i][j] - x[(i + 1)][j]);
//				double gaps = (y[i][j] - x[(i + 1)][j]) * (y[i][j] - x[(i + 1)][j]);
//				cout<<"Gaps between points = "<< gaps <<endl;
				deriv[i] += 2 * (y[i][j] - x[(i + 1)][j]) * mapAxplusb[j];
			}
		}
//		cout << "line  979" << endl;
	} // End of for-loop over i
//
//	cout << "end looping over i" << endl;
//	if(N!=1){ // The abstract CE has at least one discrete jump, and therefore at least one splicing point.
//		for(unsigned int j=0;j<dim;j++)
//			deriv[(N-1)*dim+j] = -2*(y[N-2][j] - x[(N-1)*dim+j]);
//	}

//#ifdef VALIDATION
//// add to cost the distance of refinement points. Modify the derivatives.
//
//	//std::cout << "Running with trajectory validation enabled\n";
//
//	for(std::list<refinement_point>::iterator it = ref_pts.begin();it!=ref_pts.end();it++)
//	{
//		refinement_point p = *it;
//		assert(p.seq_no<N);
//		unsigned int locID = locIdList[p.seq_no];
//
//		double dwell_time = x[N*dim+p.seq_no];
//		// if the sampled time is less than the time when the refinement point violated the Inv, then ignore this refinement
//		if(dwell_time < p.time)
//			continue;
//		// Compute the new point v at p.time units from the new sampled start point.
//		Dynamics d = HA->getLocation(locID)->getSystem_Dynamics();
//		polytope::ptr I = HA->getLocation(locID)->getInvariant();
//		assert(d.C.size() == dim);
//
//		std::vector<double> v(dim);
//		for(unsigned int i=0;i<dim;i++)
//			v[i] = x[p.seq_no*dim+i];
//
//		v = ODESol(v, d, p.time);
//		// patch for constant dynamics
//
//		math::matrix<double> A;
//		if(d.isEmptyMatrixA){
//			A = math::matrix<double>(dim,dim);
//			for(unsigned int i=0;i<dim;i++){
//				for(unsigned int j=0;j<dim;j++){
//					A(i,j)=0;
//				}
//			}
//		}
//		else
//			A = d.MatrixA;
//
//		double dist = I->point_distance(v);
//
//		if(dist>0) {
//			cost+= dist;
//			math::matrix<double> expAt;
//			A.matrix_exponentiation(expAt,p.time);
//
//			std::vector<double> I_dist_grad(dim);
//			I_dist_grad = dist_grad(v,I);
//
//			for(unsigned int j=0;j<dim;j++){
//				double I_dist_grad_j = 0;
//				for(unsigned int k=0;k<dim;k++){
//					I_dist_grad_j += I_dist_grad[k] * expAt(k,j);
//				}
//				deriv[p.seq_no*dim+j] += I_dist_grad_j;
//			}
//			// derivative wrt dwell time
//			std::vector<double> Axplusb;
//
//			A.mult_vector(v,Axplusb);
//			for (unsigned int j = 0; j < dim; j++) {
//				Axplusb[j] = Axplusb[j] + d.C[j];
//			}
//
//			double dist_gradt = 0;
//			for(unsigned int j=0;j<dim;j++)
//			{
//				dist_gradt +=  I_dist_grad[j] * Axplusb[j];
//			}
//
//			deriv[N*dim + p.seq_no] += dist_gradt;
//		}
//	}
//#endif

//	cout << "before copying gradient" << endl;
	// Analytic gradients
	if (!grad.empty()) {
		for (unsigned int i = 0; i < t.size(); i++) {
			grad[i] = deriv[i];
		}
	}
//	cout << "end copying gradient" << endl;
//	std::cout << "opt over t: current cost=" << cost << std::endl;
	return cost;

}

