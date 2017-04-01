/*
 * io_utility.h
 *
 *  Created on: 19-Jan-2016
 *      Author: amit
 */
#include "io_utility.h"

/*
 * Creating a bounding_box polytope with constraints as (template_directions + invariant_directions)
 * and bounds as maximum of (sfm + invariant_bounds). The polytopes from the ith to the jth columns
 * are merged to get a single polytope. The parameters include the i, j to be merged to get a hull
 */

polytope::ptr get_template_hull(template_polyhedra::ptr sfm, unsigned int start, unsigned int end) {

	unsigned int template_size = sfm->getTotalIterations() ;

	if(start < template_size && end > template_size)
		end = template_size-1;

	// Checking the sanity of the bounds
	//std::cout << "start=" << start << " , end = " << end << std::endl;
	assert(start<=end && end < sfm->getTotalIterations());

	polytope::ptr boundingPolytope;
	boundingPolytope = polytope::ptr(new polytope());

	math::matrix<double> directional_constraints, all_dirs;
	math::matrix<double> each_sfm;

	if (sfm->getInvariantDirections().size2()==0){	//no invariant exists
		all_dirs = sfm->getTemplateDirections();
	}else{	//invariants exists so join the directions
		//std::cout<<" called  ";
		directional_constraints = sfm->getTemplateDirections();
		directional_constraints.matrix_join(sfm->getInvariantDirections(), all_dirs);
	}
	each_sfm = sfm->getMatrixSupportFunction();
	//boundingPolytope->setCoeffMatrix(directional_constraints);
	boundingPolytope->setCoeffMatrix(all_dirs);

	double max_value;
	int Totaldirs = each_sfm.size1();

	unsigned int num_columns = end - start + 1;

	std::vector<double> polytope_bounds(Totaldirs);

	for (int i = 0; i < Totaldirs; i++) { //i==row_number
		for (unsigned int k = start; k < start+num_columns; k++) { //k==col_number
			double sfm_value = each_sfm(i, k);
			if (k == start) {
				max_value = sfm_value;
			} else {
				if (sfm_value > max_value) {
					max_value = sfm_value;
				}
			}
		}	//getting the max_value for each row
		polytope_bounds[i] = max_value;
	} //end of sfm returns vector of all variables[min,max] intervals

	std::vector<double> all_polytope_bounds;

	if (sfm->getInvariantDirections().size2()==0){	//no invariant exists
		all_polytope_bounds = polytope_bounds;
	}else{	////invariants exists so join the bounds
		std::vector<double> inv_bounds(sfm->getMatrix_InvariantBound().size1());
		for (unsigned int k = 0; k < sfm->getInvariantDirections().size1(); k++) { //k==rows or number of invariants
			inv_bounds[k] = sfm->getMatrix_InvariantBound()(k,0);
		}
		all_polytope_bounds = vector_join(polytope_bounds, inv_bounds);
	}

	boundingPolytope->setColumnVector(all_polytope_bounds);
	boundingPolytope->setInEqualitySign(1);//Indicating all <= sign

	return boundingPolytope;
}

typedef std::vector<std::pair<double, double> > Intervals;
void interval_generator(std::list<symbolic_states::ptr>& symbolic_states_list,userOptions user_ops) {
	symbolic_states::ptr sym_state = *symbolic_states_list.begin();
	//unsigned int system_dim = sym_state->getInitialPolytope()->getSystemDimension();	//may not exists
	unsigned int system_dim = sym_state->getContinuousSetptr()->getTemplateDirections().size2();	//this definitely exists
	unsigned int first_var_index = user_ops.get_first_plot_dimension();
	unsigned int second_var_index = user_ops.get_second_plot_dimension();

	std::vector<double> d_max_1(system_dim,0), d_min_1(system_dim,0);
	d_max_1[first_var_index] = 1;
	d_min_1[first_var_index] = -1;

	std::vector<double> d_max_2(system_dim,0), d_min_2(system_dim,0);
	d_max_2[second_var_index] = 1;
	d_min_2[second_var_index] = -1;
	double max_global_first = INT_MIN, min_global_first=INT_MAX;
	double max_global_second = INT_MIN, min_global_second=INT_MAX;
	std::list<symbolic_states::ptr>::iterator SS;
	for (SS = symbolic_states_list.begin(); SS != symbolic_states_list.end();
			SS++) {

		template_polyhedra::ptr sym_state_sfm = (*SS)->getContinuousSetptr();
		polytope::ptr bounding_poly_ptr = get_template_hull(sym_state_sfm,0,sym_state_sfm->getTotalIterations()-1);
		lp_solver lp;
		lp.setConstraints(bounding_poly_ptr->getCoeffMatrix(),bounding_poly_ptr->getColumnVector(),bounding_poly_ptr->getInEqualitySign());
		lp.setMin_Or_Max(2);

		double first_dim_max = bounding_poly_ptr->computeSupportFunction(d_max_1,lp);
		double first_dim_min = -1 * bounding_poly_ptr->computeSupportFunction(d_min_1,lp);

		if(first_dim_max > max_global_first) max_global_first = first_dim_max;
		if(first_dim_min < min_global_first) min_global_first = first_dim_min;

		double second_dim_max = bounding_poly_ptr->computeSupportFunction(d_max_2,lp);
		double second_dim_min = -1 * bounding_poly_ptr->computeSupportFunction(d_min_2,lp);

		if(second_dim_max > max_global_second) max_global_second = second_dim_max;
		if(second_dim_min < min_global_second) min_global_second = second_dim_min;

	} //end of sfm returns vector of all variables[min,max] intervals

	std::cout << "The Interval for the first Dimension is:" << min_global_first << ", " << max_global_first << std::endl;
	std::cout << "The Interval for the second Dimension is:" << min_global_second << ", " << max_global_second << std::endl;

}
void vertex_generator(std::list<symbolic_states::ptr>& symbolic_states_list, userOptions user_options)
{
	std::list<symbolic_states::ptr>::iterator it;
	math::matrix<double> vertices_list;
	std::ofstream outFile;
	outFile.open(user_options.getOutFilename().c_str());

	for (it = symbolic_states_list.begin(); it != symbolic_states_list.end();
				it++) {
			template_polyhedra::ptr temp_polyhedra;
			temp_polyhedra = (*it)->getContinuousSetptr();

			math::matrix<double> A, template_directions, invariant_directions;
			math::matrix<double> big_b, sfm, invariant_bound_values;

			template_directions = temp_polyhedra->getTemplateDirections();
			invariant_directions = temp_polyhedra->getInvariantDirections(); //invariant_directions

			sfm = temp_polyhedra->getMatrixSupportFunction(); //total number of columns of SFM
			invariant_bound_values = temp_polyhedra->getMatrix_InvariantBound(); //invariant_bound_matrix

			if (invariant_directions.size1() == 0) { //indicate no invariants exists
				A = template_directions;
				big_b = sfm;
			} else {
				template_directions.matrix_join(invariant_directions, A); //creating matrix A
				sfm.matrix_join(invariant_bound_values, big_b);
			}
			std::vector<double> b(big_b.size1()); //rows of big_b
			for (unsigned int i = 0; i < big_b.size2(); i++) { //all the columns of new formed sfm
				for (unsigned int j = 0; j < big_b.size1(); j++) { //value of all the rows
					b[j] = big_b(j, i);
				} //creating vector 'b'

				polytope::ptr p = polytope::ptr(new polytope(A, b, 1));
				vertices_list = p->get_2dVertices(
						user_options.get_first_plot_dimension(),
						user_options.get_second_plot_dimension()); //
				//vertices_list = p->enumerate_2dVertices(x, y); //

				// ------------- Printing the vertices on the Output File -------------
				for (unsigned int i = 0; i < vertices_list.size1(); i++) {
					for (unsigned int j = 0; j < vertices_list.size2(); j++) {
						outFile << vertices_list(i, j) << " ";
					}
					outFile << std::endl;
				}
				outFile << std::endl; // 1 gap after each polytope plotted
				// ------------- Printing the vertices on the Output File -------------

			}
		}
		outFile.close();
}
