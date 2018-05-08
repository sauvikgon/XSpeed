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

#include "../core_system/continuous/Polytope/Polytope.h"
#include "application/DataStructureDirections.h"
#include "abstractCE.h"
#include "core_system/math/analyticODESol.h"


double myconstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data) {
	polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	unsigned int id = d->sstate_index;

//	unsigned int row_index = d->row_index;

	assert(id>=0 && id<N);
	if (!grad.empty()) {
		for(unsigned int i=0;i<x.size();i++){
			grad[i] = 0 ;
		}
		for(unsigned int j=0;j<dim;j++)
			grad[id*dim+j] = d->a[j];
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
double myobjfunc2(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) {

	// 1. Get the N start vectors and dwell times from x and call the simulation routine
	// 2. Get the N end points of the simulation trace, say, y[i].
	// 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	// Computes the L2 norm or Euclidean distances between the trace end points.
	//-----------------------------------------

	/*This is the vector of end-points of N trajectory segments */
	std::vector<std::vector<double> > y(N);

	double cost = 0;
	std::vector<double> deriv(x.size(),0); // contains the gradient, all initialized to 0


	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);
	assert(transList.size() == N-1);

	math::matrix<double> A, expAt, mapExpAt;
	std::vector<double> Axplusb(dim), mapAxplusb;

	std::ofstream myfile;
	myfile.open("./endpoints");

	for (unsigned int i = 0; i < N; i++) {

		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		std::vector<double> traj_dist_grad(dim,0); // holds the grads of the trajectories distance to invariant

		y[i] = ODESol(v,d,x[N*dim + i]);
		// patch for constant dynamics

		if(d.isEmptyMatrixA){
			A = math::matrix<double>(dim,dim);
			for(unsigned int i=0;i<dim;i++){
				for(unsigned int j=0;j<dim;j++){
					A(i,j)=0;
				}
			}
		}
		else
			A = d.MatrixA;
		// end of patch

		assert(d.C.size() == dim);

		math::matrix<double> At(A);
		At.scalar_multiply(x[N*dim+i]);
		At.matrix_exponentiation(expAt);

		A.mult_vector(y[i],Axplusb);
		for (unsigned int j = 0; j < dim; j++) {
			Axplusb[j] = Axplusb[j] + d.C[j];
		}

//		For validation, the distance of trace end points from the invariant is
//		added to the cost

		std::vector<double> inv_dist_grad(dim,0);
		cost+= I->point_distance(y[i]); // end point distance to invariant added to cost

		inv_dist_grad = dist_grad(y[i],I);

		for(unsigned int j=0;j<dim;j++) {
			double dist_gradx_j = 0;
			for(unsigned int k=0;k<dim;k++)
			{
				dist_gradx_j +=  inv_dist_grad[k] * expAt(k,j);
			}
			deriv[i*dim+j] += dist_gradx_j;

		}
		// add the cost gradient w.r.t traj segment's dwell time
		double dist_gradt = 0;
		for(unsigned int j=0;j<dim;j++)
		{
			dist_gradt +=  inv_dist_grad[j] * Axplusb[j];
		}
		deriv[N*dim + i] += dist_gradt;

		//end of validation logic

		if(i==N-1)
			break;
		else {
			polytope::ptr g;
			Assign R;
			math::matrix<double> mapExpAt(expAt);
			// assignment of the form: Rx + w

			R = Tptr->getAssignT();
			//guard as a polytope
			// This matrix is require to compute the derivative
			g = Tptr->getGaurd();

			std::vector<double> mapderiv(Axplusb);

			// If traj end point inside guard, then apply map.
//			double guard_dist = g->point_distance(y[i]);
//			if(guard_dist == 0)
//			{
//				std::cout << "Inside g condition\n";
				assert(y[i].size() == R.Map.size2());
				std::vector<double> transform(y[i].size(),0);
//				//debug
//				std::cout << "transition assignment map:" << R.Map << std::endl;
//				std::cout << "transition w: ";
//				for(unsigned int i=0;i<R.b.size();i++)
//					 std::cout << R.b[i] << std::endl;
//				//---
				R.Map.mult_vector(y[i],transform);
				for(unsigned int j=0;j<transform.size();j++)
					y[i][j] = transform[j] + R.b[j];

				R.Map.multiply(expAt,mapExpAt);
				R.Map.mult_vector(Axplusb,mapAxplusb);
				// add vectors
				assert(y[i].size() == R.b.size());

//			}
//			else{
//			}
			if(T_iter!=transList.end())
				T_iter++;

			//debug
			myfile << y[i][9] << " " << y[i][0] << std::endl;
			myfile << x[(i+1)*dim + 9] << x[(i+1)*dim + 0] << std::endl;
			//---

			//compute the Euclidean distance between the next start point and the simulated end point
			for (unsigned int j = 0; j < dim; j++) {
				cost += (y[i][j] - x[(i+1)*dim + j]) * (y[i][j] - x[(i+1)*dim + j]);

				for(unsigned int k=0;k<dim;k++)
				{
					deriv[i*dim+j] += 2*(y[i][k] - x[(i+1)*dim + k]) * mapExpAt(k,j);
				}
				if(i!=0){
					deriv[i*dim+j] +=  - 2*(y[(i-1)][j] - x[i*dim+j]);
				}
				deriv[N*dim+i] += 2*(y[i][j] - x[(i+1)*dim + j]) * mapAxplusb[j];
			}
		}

	} // End of for-loop over i

	for(unsigned int j=0;j<dim;j++)
		deriv[(N-1)*dim+j] = -2*(y[N-2][j] - x[(N-1)*dim+j]);


#ifdef VALIDATION
// add to cost the distance of refinement points. Modify the derivatives.

	for(std::list<refinement_point>::iterator it = ref_pts.begin();it!=ref_pts.end();it++)
	{
		refinement_point p = *it;
		assert(p.seq_no<N);
		unsigned int locID = locIdList[p.seq_no];

		double dwell_time = x[N*dim+p.seq_no];
		// if the sampled time is less than the time when the refinement point violated the Inv, then ignore this refinement
		if(dwell_time<p.time)
			continue;
		// Compute the new point v at p.time units from the new sampled start point.
		Dynamics d = HA->getLocation(locID)->getSystem_Dynamics();
		polytope::ptr I = HA->getLocation(locID)->getInvariant();
		assert(d.C.size() == dim);

		std::vector<double> v(dim);
		for(unsigned int i=0;i<dim;i++)
			v[i] = x[p.seq_no*dim+i];

		v = ODESol(v, d, p.time);
		// patch for constant dynamics

		math::matrix<double> A;
		if(d.isEmptyMatrixA){
			A = math::matrix<double>(dim,dim);
			for(unsigned int i=0;i<dim;i++){
				for(unsigned int j=0;j<dim;j++){
					A(i,j)=0;
				}
			}
		}
		else
			A = d.MatrixA;

		double dist = I->point_distance(v);

		if(dist>0) {
			cost+= dist;
			math::matrix<double> expAt;
			A.matrix_exponentiation(expAt,p.time);

			std::vector<double> I_dist_grad(dim);
			I_dist_grad = dist_grad(v,I);

			for(unsigned int j=0;j<dim;j++){
				double I_dist_grad_j = 0;
				for(unsigned int k=0;k<dim;k++){
					I_dist_grad_j += I_dist_grad[k] * expAt(k,j);
				}
				deriv[p.seq_no*dim+j] += I_dist_grad_j;
			}
			// derivative wrt dwell time
			std::vector<double> Axplusb;

			A.mult_vector(v,Axplusb);
			for (unsigned int j = 0; j < dim; j++) {
				Axplusb[j] = Axplusb[j] + d.C[j];
			}

			double dist_gradt = 0;
			for(unsigned int j=0;j<dim;j++)
			{
				dist_gradt +=  I_dist_grad[j] * Axplusb[j];
			}

			deriv[N*dim + p.seq_no] += dist_gradt;
		}
	}
#endif
	//debug
	myfile << y[N-1][9] << " " << y[N-1][0] << std::endl;
	//---
	myfile.close();
	//---

	// compute the distance of this endpoint with the forbidden polytope
	cost+= bad_poly->point_distance(y[N-1]);

	std::vector<double> badpoly_dist_grad(dim,0);

	badpoly_dist_grad = dist_grad(y[N-1], bad_poly);

	for(unsigned int j=0;j<dim;j++) {
		double dist_gradx_j = 0;
		for(unsigned int k=0;k<dim;k++)
		{
			dist_gradx_j +=  badpoly_dist_grad[k] * expAt(k,j);
		}
		deriv[(N-1)*dim+j] += dist_gradx_j;
	}

	//	add the cost gradient w.r.t last traj segment's dwell time

	double dist_gradt = 0;
	for(unsigned int j=0;j<dim;j++)
	{
		dist_gradt +=  badpoly_dist_grad[j] * Axplusb[j];
	}
	deriv[N*dim + N - 1] += dist_gradt;

	// Analytic gradients
	if(!grad.empty())
	{
		for(unsigned int i=0;i<x.size();i++){
			grad[i] = deriv[i];
		}
	}
//	std::cout << "current cost=" << cost << std::endl;

	return cost;
}

//double myobjfunc1(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data)
//{
//	math::matrix<double> expAt(dim,dim);
//
//	std::vector<std::vector<double> > y(N-1);
//	for(unsigned int j=0;j<N-1;j++)
//		y[j] = std::vector<double>(dim,0);
//
//	double cost = 0;
//	double deriv[x.size()];// contains the gradient
//
//	std::list<transition::ptr>::iterator T_iter = transList.begin();
//
//	for (unsigned int i = 0; i < N-1; i++) {
//		std::vector<double> v(dim, 0);
//		for (unsigned int j = 0; j < dim; j++) {
//			v[j] = x[i * dim + j];
//		}
//
//		int loc_index = locIdList[i];
//		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
//		polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
//		assert(d.C.size() == dim);
//		// If dynamics invertible, then get analytical solution. Otherwise, perform
//		// numerically simulation with Euler steps.
////		if(d.MatrixA.inverse(expAt)){
////			y[i] = ODESol(v,d,x[N * dim + i]);
////		}
////		else {
////			simulation::ptr sim = simulation::ptr(new simulation(dim,1000,d));
////			y[i] = sim->simulate(v, x[N * dim + i]);
////		}
//		y[i] = ODESol(v,d,x[N*dim + i]);
//		transition::ptr Tptr= *(T_iter);
//		// assignment of the form: Ax + b
//		Assign R = Tptr->getAssignT();
//		//guard as a polytope
//		polytope::ptr g = Tptr->getGaurd();
//		// If traj end point inside guard, then apply map.
//		if(g->point_distance(y[i])==0)
//		{
//			assert(y[i].size() == R.Map.size2());
//			std::vector<double> res(y[i].size(),0);
//			R.Map.mult_vector(y[i],res);
//			// add vectors
//			assert(y[i].size() == R.b.size());
//			for(unsigned int j=0;j<res.size();j++)
//				y[i][j] = res[j] + R.b[j];
//		}
//		if(T_iter!=transList.end())
//			T_iter.operator ++();
//
//		double sum=0;
//
//		d.MatrixA.matrix_exponentiation(expAt,x[N*dim+i]);
//		assert(expAt.size1() == dim);
//		assert(expAt.size2() == dim);
//
//		std::vector<double> Axplusb(dim);
//		d.MatrixA.mult_vector(y[i],Axplusb);
//		assert(d.C.size() == Axplusb.size());
//		for (unsigned int j = 0; j < dim; j++) {
//			Axplusb[j] = Axplusb[j] + d.C[j];
//		}
//
//		//compute the Euclidean distance between the next start point and the simulated end point
//		for (unsigned int j = 0; j < dim; j++) {
//			cost += (y[i][j] - x[(i+1)*dim + j]) * (y[i][j] - x[(i+1)*dim + j]);
//			if(i==0){
////				deriv[i*dim+j] = 2*(y[i][j]-next_start[j])* expAt(j,j) + traj_dist_grad[j];
//
//				deriv[i*dim+j] = 2*(y[i][j]-x[(i+1)*dim + j])* expAt(j,j);
//			}
//			else{
//				deriv[i*dim+j] = (2*(y[i][j] - x[(i+1)*dim + j]) * expAt(j,j) ) - 2*(y[(i-1)][j] - x[i*dim+j]);
//			}
//			sum+= 2*(y[i][j] - x[(i+1)*dim + j]) * Axplusb[j];
//		}
//		deriv[N*dim+i] = sum;
//	}
//
//	std::vector<double> v(dim, 0);
//	for (unsigned int j = 0; j < dim; j++) {
//		v[j] = x[ (N-1) * dim + j];
//	}
//	std::vector<double> trace_end_pt(dim,0);
//	int loc_index = locIdList[N-1];
//	Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
//	polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
//
//	simulation::ptr sim = simulation::ptr(new simulation(dim,1000,d));
//	trace_end_pt = sim->simulate(v, x[N * dim + N-1]);
//	//trace_end_pt = ODESol(v, d, x[N * dim + N-1]);
//
//	// analytical grad computation wrt start point
//	math::matrix<double> Aexp(d.MatrixA.size1(),d.MatrixA.size2());
//	std::vector<double> Axplusb(dim), chain_mult(dim);
//	d.MatrixA.matrix_exponentiation(Aexp,x[N*dim+N-1]);
//	d.MatrixA.mult_vector(trace_end_pt,Axplusb);
//
//	for(unsigned int j=0;j<dim;j++){
//		chain_mult[j] = Aexp(j,j);
//		Axplusb[j] = Axplusb[j] + d.C[j];
//	}
//	std::vector<double> bad_dist_gradx(dim,0), bad_dist_gradt(dim,0);
//
//	bad_dist_gradx = dist_grad(trace_end_pt,bad_poly,chain_mult);
//
//	for(unsigned int j=0;j<dim;j++){
////		deriv[(N-1)*dim+j] = -2*(y[N-2][j] - x[(N-1)*dim+j]) + d_dist_dx[j] + traj_dist_grad[j];
//		deriv[(N-1)*dim+j] = -2*(y[N-2][j] - x[(N-1)*dim+j]) + bad_dist_gradx[j];
//	}
//
//	//deriv of cost function w.r.t dwell time of last trajectory going to bad set
//
//	deriv[N*dim+N-1] = 0;
//	bad_dist_gradt = dist_grad(trace_end_pt,bad_poly,Axplusb);
//	for(unsigned int j=0;j<dim;j++)
//		deriv[N*dim+N-1]+=bad_dist_gradt[j];
//	// compute the distance of this endpoint with the forbidden polytope
//	cost+= bad_poly->point_distance(trace_end_pt);
//
//	// Analytic gradients
//	if(!grad.empty())
//	{
//		for(unsigned int i=0;i<x.size();i++){
//			grad[i] = deriv[i];
//		}
//	}
////	std::cout << "cost = " << cost << std::endl;
//	return cost; //dummy
//}
