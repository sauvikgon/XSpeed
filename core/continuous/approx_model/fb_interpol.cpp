#include "fb_interpol.h"

fb_interpol::~fb_interpol(){}

fb_interpol::fb_interpol(math::matrix<double> my_A, polytope::ptr X0, polytope::ptr U, double delta, std::vector<double> C, unsigned int num_iters) : approx_model(my_A, X0, U, delta) 
{
	math::matrix<double> absolute_A;
	my_A.absolute(absolute_A);

	get_phi_2(absolute_A,delta).transpose(transpose_phi_2);

	math::matrix<double> expAt;
	my_A.matrix_exponentiation(expAt,delta);
	expAt.transpose(transpose_expAt); 

	math::matrix<double> A_square, AsquarePhi;
	my_A.multiply(my_A, A_square);
	A_square.transpose(transpose_A_square);
	
	A_square.multiply(expAt,AsquarePhi);
	AsquarePhi.transpose(transpose_AsquarePhi);
	
	my_A.transpose(transpose_A);
	this->num_iters = num_iters;

	this->C = C; // the constant dynamics vector.

	rho_psi.resize(num_iters);
	rho_psi[0] = 0;	

	// initializing the phi list
	double t;
	phi_list.resize(num_iters);
	
	for(unsigned int i=0;i<num_iters;i++){
		t = delta*i;
		my_A.matrix_exponentiation(expAt,t);
		expAt.transpose(phi_list[i]);
	}
}

double fb_interpol::rho_symhull_AsquareX0(const std::vector<double>& l)
{
	if(get_X0()->getIsEmpty()) return 0;

	unsigned int dim = get_X0()->getSystemDimension();

	std::vector<double> unit_dir(dim,0), transformed_dir;
	
	double res=0;
	for(unsigned int i=0;i<dim;i++){
		unit_dir[i] = 1;
		transpose_A_square.mult_vector(unit_dir,transformed_dir);
		double max = rho_X0(transformed_dir);
		unit_dir[i] = -1;
		transpose_A_square.mult_vector(unit_dir,transformed_dir);
		double neg_min = rho_X0(transformed_dir);
		unit_dir[i] = 0;
		if(max > neg_min)
			res+= max * fabs(l[i]);
		else
			res+= neg_min * fabs(l[i]);		
	}
	return res;
}
double fb_interpol::rho_omega_plus(const std::vector<double>& l)
{
	if(get_X0()->getIsEmpty()) return 0;

	unsigned int dim = get_X0()->getSystemDimension();

	std::vector<double> unit_dir(dim,0), transformed_dir;
	
	double res=0;
	for(unsigned int i=0;i<dim;i++){
		unit_dir[i] = 1;
		transpose_phi_2.mult_vector(unit_dir,transformed_dir);
		double max = rho_symhull_AsquareX0(transformed_dir);
		unit_dir[i] = -1;
		transpose_phi_2.mult_vector(unit_dir,transformed_dir);
		double neg_min = rho_symhull_AsquareX0(transformed_dir);
		unit_dir[i] = 0;
		if(max > neg_min)
			res+= max * fabs(l[i]);
		else
			res+= neg_min * fabs(l[i]);		
	}
	return res;	
}
double fb_interpol::rho_symhull_AsquarePhiX0(const std::vector<double>& l)
{
	if(get_X0()->getIsEmpty()) return 0;

	unsigned int dim = get_X0()->getSystemDimension();

	std::vector<double> unit_dir(dim,0), transformed_dir;
	
	double res=0;
	for(unsigned int i=0;i<dim;i++){
		unit_dir[i] = 1;
		transpose_AsquarePhi.mult_vector(unit_dir,transformed_dir);
		double max = rho_X0(transformed_dir);
		unit_dir[i] = -1;
		transpose_AsquarePhi.mult_vector(unit_dir,transformed_dir);
		double neg_min = rho_X0(transformed_dir);
		unit_dir[i] = 0;
		if(max > neg_min)
			res+= max * fabs(l[i]);
		else
			res+= neg_min * fabs(l[i]);		
	}
	return res;	
}

double fb_interpol::rho_omega_minus(const std::vector<double>& l)
{
	if(get_X0()->getIsEmpty()) return 0;

	unsigned int dim = get_X0()->getSystemDimension();

	std::vector<double> unit_dir(dim,0), transformed_dir;
	
	double res=0;
	for(unsigned int i=0;i<dim;i++){
		unit_dir[i] = 1;
		transpose_phi_2.mult_vector(unit_dir,transformed_dir);
		double max = rho_symhull_AsquarePhiX0(transformed_dir);
		unit_dir[i] = -1;
		transpose_phi_2.mult_vector(unit_dir,transformed_dir);
		double neg_min = rho_symhull_AsquarePhiX0(transformed_dir);
		unit_dir[i] = 0;
		if(max > neg_min)
			res+= max * fabs(l[i]);
		else
			res+= neg_min * fabs(l[i]);		
	}
	return res;
}
/** Computes the support function of the symmetric hull of A.U */
double fb_interpol::rho_symhull_AU(const std::vector<double>& l)
{
	if(get_U()->getIsEmpty()) return 0;

	unsigned int dim = get_U()->getSystemDimension();

	std::vector<double> unit_dir(dim,0), transformed_dir;
	
	double res=0;
	for(unsigned int i=0;i<dim;i++){
		unit_dir[i] = 1;
		transpose_A.mult_vector(unit_dir,transformed_dir);
		double max = rho_U(transformed_dir);
		unit_dir[i] = -1;
		transpose_A.mult_vector(unit_dir,transformed_dir);
		double neg_min = rho_U(transformed_dir);
		unit_dir[i] = 0;
		if(max > neg_min)
			res+= max * fabs(l[i]);
		else
			res+= neg_min * fabs(l[i]);		
	}
	return res;
}

/**
  * Computes the support function of the intersection between
  * omega_plus and omega_minus w.r.t l.
  */
double fb_interpol::rho_fb_intersection(const std::vector<double>& l, double lambda)
{
	unsigned int dim = get_X0()->getSystemDimension();
	std::vector<double> unit_dir(dim,0);
	
	double res=0;
	for(unsigned int i=0;i<dim;i++){
		unit_dir[i] = 1;
		double lambda_max = lambda * rho_omega_plus(unit_dir);
		
		double one_minus_lambda_max = (1-lambda)* rho_omega_minus(unit_dir);

		// Take the min and multiply with |l_i|
		if(lambda_max < one_minus_lambda_max)
			res+= lambda_max * fabs(l[i]);
		else
			res+= one_minus_lambda_max * fabs(l[i]);
		unit_dir[i] = 0;		
	}
	return res;
}

/** Computes the support function of the symmetric hull of 
  * \phi sum-hull(A.U), i.e. epsilon_psi (CAV'11 notation) w.r.t l. 
  */
double fb_interpol::rho_epsilon_psi(const std::vector<double>& l)
{
	if(get_U()->getIsEmpty()) return 0;

	unsigned int dim = get_U()->getSystemDimension();

	std::vector<double> unit_dir(dim,0), transformed_dir;
	
	double res=0;
	for(unsigned int i=0;i<dim;i++){
		unit_dir[i] = 1;
		transpose_phi_2.mult_vector(unit_dir,transformed_dir);
		double max = rho_symhull_AU(transformed_dir);
		unit_dir[i] = -1;
		transpose_phi_2.mult_vector(unit_dir,transformed_dir);
		double neg_min = rho_symhull_AU(transformed_dir);
		unit_dir[i] = 0;
		if(max > neg_min)
			res+= max * fabs(l[i]);
		else
			res+= neg_min * fabs(l[i]);		
	}
	return res;
}

//Objective function for solving max opt. problem
double myobjfun(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data)
{
	assert(x.size() == 1);
	struct terms * objfun_terms= reinterpret_cast<struct terms *>(my_func_data);
	std::vector<double> dir = objfun_terms->direction;
	double lambda = x[0];
	double res;
	res = (1-lambda) * objfun_terms->sup_X0;
	res += lambda * objfun_terms->sup_phiX0;
	res += lambda * objfun_terms->sup_deltaU;
	res += lambda * lambda * objfun_terms->sup_epsilon_psi;
	res += (objfun_terms->fb_interpol_obj)->rho_fb_intersection(dir,lambda);
	
	//std::cout << "lambda="<< lambda << ", cost=" << res << std::endl;
	return res;
}

double fb_interpol::first_omega_support(const std::vector<double>& l, double time_step)
{
	double res;
	double sup_X0;
	// This is term1 
	sup_X0 = rho_X0(l);
	
	// This term to compute rho_(X0) in the direction transpose(expAt).l
	double term2;
	math::matrix<double> expAt, my_transpose_expAt;
	if(time_step != get_delta()){
		get_A().matrix_exponentiation(expAt,time_step);
		expAt.transpose(my_transpose_expAt);
	}
	else{
		my_transpose_expAt = transpose_expAt;	
	} 
	
	// transform l to transpose(exp^{At}).l
	 
	std::vector<double> transformed_l;
	my_transpose_expAt.mult_vector(l,transformed_l);
	term2 = rho_X0(transformed_l);

	// This term to compute time_step * rho_U(l)
	double term3 = time_step *  rho_U(l);
	
	// Term 4 is lambda dependent and will be computed inside
        // the objective function of nlopt.

	
	// This term to compute rho_{sym-hull(\phi. sym-hull(AU)}
	
	double term5 = rho_epsilon_psi(l);
	
	// creating a structure to pass on calculated terms to the obj of nlopt.
	terms my_terms;
	my_terms.sup_X0 = sup_X0;
	my_terms.sup_phiX0 = term2;
	my_terms.sup_deltaU = term3;
	my_terms.sup_epsilon_psi = term5;
	my_terms.direction = l;
	my_terms.fb_interpol_obj = this;
	
	// Now, we create an nlopt obj for solving the maximization problem
	// over lambda.
	
	unsigned int optD = 1;
	nlopt::opt myopt(nlopt::GN_DIRECT, optD); // derivative free

	unsigned int maxeval = 10; // the max allowed iterations in nlp

	std::vector<double> ub(1),lb(1);
	lb[0]=0;
	ub[0]=1;
 	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	myopt.set_maxeval(maxeval);
 
	// set the objective function
	std::vector<double> opt_lambda(1);
	myopt.set_max_objective(myobjfun, &my_terms);
	myopt.optimize(opt_lambda,res);
	return res;
}

double fb_interpol::omega_support(const std::vector<double>& l, unsigned int iter)
{
	double res;

	// transform l to transpose(exp^{At}).l	 
	std::vector<double> transformed_l;
	if(iter==0)
		transformed_l = l;
	else
		phi_list[iter].mult_vector(l,transformed_l);

	double first_omega_sup = first_omega_support(transformed_l, get_delta());
	// get support function of constant input
	if(C.size() != 0){
		double sup_const_input = 0;
		unsigned int dim = l.size();
		assert(C.size() == l.size());
		double my_delta = get_delta();

		for(unsigned int i=0;i<dim;i++){
			sup_const_input += l[i] *my_delta*iter;	
		}
		res = sup_const_input;
	}
	//--
	res += first_omega_sup + psi_support(l,iter) ;
	return res;
}

/**
  * Implementing with the limitation that it is expected to be called
  * with iters following the sequence 0,1, ..., num_iters.
  */
double fb_interpol::psi_support(const std::vector<double>& l, unsigned int iter)
{
	if(iter == 0) return 0;
	double res;
	
	std::vector<double> transformed_l;
	phi_list[iter-1].mult_vector(l,transformed_l);

	double term1 = get_delta() * rho_U(transformed_l);
	double term2 = rho_epsilon_psi(transformed_l);

	double sup_psi_delta = term1 + term2;
	res = rho_psi[iter-1] + sup_psi_delta;
	rho_psi[iter] = res;
	return res;
}
