/*
 * flowpipe_cluster.cpp
 *
 *  Created on: 02-Apr-2017
 *      Author: rajarshi
 */

#include "Utilities/flowpipe_cluster.h"

poly_list flowpipe_cluster(template_polyhedra::ptr template_poly, int cluster)
{
	assert(cluster>=0 && cluster<=100);

	poly_list poly_cluster;

	/* 0 factor means no clusterting */
	if(cluster==0){
		for(unsigned int i=0;i<template_poly->getTotalIterations();i++)
			poly_cluster.push_back(template_poly->getPolytope(i));
		return poly_cluster;
	}

	unsigned int template_size = template_poly->getTotalIterations();
	unsigned int cluster_size = std::ceil ((template_size * cluster)/100 ); // size of one cluster
	unsigned int num_clusters = std::ceil (template_size/cluster_size);

//	std::cout << "Number of clusters:" << num_clusters << std::endl;
//	std::cout << "Cluster Size:" << cluster_size << std::endl;
//	std::cout << "Template Size:" << template_size << std::endl;

	for(unsigned int i=0;i<num_clusters;i++){
		polytope::ptr clustered_poly;
		clustered_poly = get_template_hull(template_poly, i*cluster_size, (i + 1) * cluster_size-1);
		poly_cluster.push_back(clustered_poly);
	}
	return poly_cluster;
};

bool check_continuation(location::ptr src_loc_ptr, location::ptr dest_loc_ptr, transition::ptr trans_ptr)
{
	// Check for the dynamics of the destination loc and the source location
	Dynamics src_d, dest_d;
	src_d = src_loc_ptr->getSystem_Dynamics();
	dest_d = dest_loc_ptr->getSystem_Dynamics();

	if(src_d.MatrixA==dest_d.MatrixA && src_d.MatrixB == dest_d.MatrixB && src_d.C == dest_d.C){
		// check the transition assignment for identity
		Assign A = trans_ptr->getAssignT();
		std::vector<double> zero_vec(A.b.size(),0);

		if (A.Map.isIdentity() && A.b==zero_vec)
			return true;
	}
	return false;

}
