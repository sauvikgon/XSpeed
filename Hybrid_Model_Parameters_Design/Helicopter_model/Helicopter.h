/*
 * Helicopter.h
 *
 *  Created on: 17-Sep-2014
 *      Author: amit
 */

#ifndef HELICOPTER_H_
#define HELICOPTER_H_

/*	Trying with 35 variables i.e., x1 to x28, u1 to u6 and t
 *
 * Basic Model Design requirements are ---
 *
 * Initial Polytope (take x values followed by u values and then t values)
 * Dynamics : Matrix A(take Aut), Matrix B(identity matrix) and Polytope U(for U take an Empty polytope)
 * Gaurd : Polytope	Not requred for Helicopter
 * Invariant : Polytope take a Universe polytope bounded for all cases ...  or invariant <= T; T=timebound
 * Transition Dynamics : Just a single location so no transition
 *
 */

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include "application/DataStructureDirections.h"
#include <fstream>
#include <string>

using namespace std;
using namespace boost::numeric::ublas;
//using namespace boost;

typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

void SetHelicopter_Parameters(ReachabilityParameters& reach_parameters, polytope& initial_polytope_I,
		Dynamics& system_dynamics, polytope& invariant,
		polytope& gaurd_polytope) {

	std::cout << std::fixed;	//to assign precision on the std::output stream
	std::cout.precision(12);			//cout << setprecision(17);

	math::matrix<double> ConstraintsMatrixI, invariantConstraintsMatrix,
			gaurdConstraintsMatrix, Amatrix, AUmatrix, Bmatrix;	//ConstraintsMatrixV,
	std::vector<double> boundValueI, invariantBoundValue, gaurdBoundValue;//boundValueV,
	int boundSignI, invariantBoundSign, gaurdBoundSign;		//boundSignV

	size_type row, col;

	//Polytope I Declaration in the form of Ax<=b
	//Input Polytope I as a line(bar) 10<=x(position)<=10.2 y(velocity)== 0.
	row = 70;			//18	//56	//68		//70;
	col = 35;			//28	//34		//35;
	ConstraintsMatrixI.resize(row, col);
	boundValueI.resize(row);
	//int i_index = 0, j_index = 0;
	for (int i = 0; i < 35; i++) {		//28		//34		//35
		for (int j = 0; j < 35; j++) {	//28		//34		//35
			if (i == j) {	//for diagonal elements assign 1 and -1
				ConstraintsMatrixI(2 * i, j) = 1;			//for xi
				ConstraintsMatrixI(2 * i + 1, j) = -1;		//for -xi
			} else {	//for all other elements assign zeros
				ConstraintsMatrixI(2 * i, j) = 0;			//for xi
				ConstraintsMatrixI(2 * i + 1, j) = 0;		//for -xi
			}
		}
		if (i < 8){		//x1  to x8
			boundValueI[2 * i] = 0.1;
			boundValueI[2 * i + 1] = 0;
		}
		if ((i >= 8) && (i < 28)) {		//x9  to x28
			boundValueI[2 * i] = 0;
			boundValueI[2 * i + 1] = 0;
		}
		if (i >= 28 ) {		//u1 to u6 and t
			boundValueI[2 * i] = 0;
			boundValueI[2 * i + 1] = 0;
		}
	}

	boundSignI = 1;

/*
	cout<<"\nPrinting the Initial Polytope Set\n";
	 for (int i=0;i<row;i++){
	 for (int j=0;j<col;j++){
	 cout << ConstraintsMatrixI(i,j)<<"\t";
	 }
	 cout<<endl;
	 }
	 cout<<"\nPrinting the Initial Polytope Set\n";
	 for (int i=0;i<row;i++){
	 cout << boundValueI[i]<<"\n";
	 }



	 row = 3;
	 col = 2;
	 gaurdConstraintsMatrix.resize(row, col);
	 gaurdConstraintsMatrix(0, 0) = 1;
	 gaurdConstraintsMatrix(0, 1) = 0;
	 gaurdConstraintsMatrix(1, 0) = -1;
	 gaurdConstraintsMatrix(1, 1) = 0;
	 using namespace boost;
	 gaurdConstraintsMatrix(2, 0) = 0;
	 gaurdConstraintsMatrix(2, 1) = 1;

	 gaurdBoundValue.resize(3);
	 gaurdBoundValue[0] = 0;
	 gaurdBoundValue[1] = 1;
	 gaurdBoundValue[2] = 0;	//gaurd is:: Position==0 and velocity <=0         0 <=x<= 0 and y<=0

	 gaurdBoundSign = 1;
	 */

	/*	 * Invariant constraint
	 * invariant <= TimeBound
	 */

	row = 35;
	col = 35;
	invariantConstraintsMatrix.resize(row, col);
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			invariantConstraintsMatrix(i, j) = 0.0;			//for xi
		}
	}
	invariantConstraintsMatrix(34,34) = 1;

	invariantBoundValue.resize(row);
	for (int i = 0; i < 35 - 1; i++) {
		invariantBoundValue[i] = 0;
	}
	invariantBoundValue[34] = reach_parameters.TimeBound;	//<= timebound
	invariantBoundSign = 1;
	invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,
			invariantBoundSign);
	//invariant.setIsUniverse(true);	//
	// Invariant Initialised above


	std::ofstream MatLabfile, MatLabfile2;
	//file for making matrix 'A' for MatLab output function con2vert(A,b) to be executed from plotoutput.m
	MatLabfile.open("/home/amit/matlabTest/ProjectOutput/MatrixA_file.txt");
	MatLabfile2.open("/home/amit/matlabTest/ProjectOutput/MatrixB_file.txt");
	for (int i = 0; i < ConstraintsMatrixI.size1(); i++) {
		for (int j = 0; j < ConstraintsMatrixI.size2(); j++) {
			MatLabfile << ConstraintsMatrixI(i, j) << " ";
		}
		MatLabfile << std::endl;
		MatLabfile2 << boundValueI[i]<<std::endl;
	}
	MatLabfile.close();
	MatLabfile2.close();

	// Initial Polytope is initialised
	initial_polytope_I.setPolytope(ConstraintsMatrixI, boundValueI, boundSignI);
	//--------------

	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign);

	string s(
			"1.000000000002, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000022507624, -0.050176870833, 0.003161246171, -0.003826227932, 0.486165175190, -0.266739403717, 0.000010307207, 0.019757788570, -0.009012833714, 0.001602140073, -0.311015942657, 2.810095522339, 0.000013852188, 0.030385323449, -0.003110159427, 0.002331730630, -0.312812882924, 0.287229690327, -0.000000329150, -0.002667394037, -0.004496152836, -0.000146052012, -0.045956750452, -1.764522071270, -0.000010762331, -0.024056576806, 0.001361685819, -0.001832537128, 0.230715295944, -0.185649147617, 0.000862889566, 1.753103616578, -0.521869609890, 0.138741289403, -23.319318958026, -145.074852087154, -0.000725566870, -1.708539622488, -0.111898315003, -0.127584976026, 13.174473231922, -91.469578800748, 0.000038146360, 0.069753861204, -0.041269247265, 0.005772466581, -1.243498527057, -13.467174945528, 0.227719797948, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 11.385989897412, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 4.554395958965, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, 4.554395958965, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, 4.554395958965, -0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 11.385989897412, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 1.000000000001");

	string matrix_au(
			"0.000000000000, 0.000000000000, 0.998573780060, 0.053384274244, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 1.000000000000, -0.003182219341, 0.059524655342, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -11.570495605469, -2.544637680054, -0.063602626324, 0.106780529022, -0.094918668270, 0.007107574493, -3.700790207851, -16.213284674534, -2.984968535139, -0.493137919288, -1.186954196152, -0.031106608756, 0.024595252653, 0.008231369923, 0.231787619674, 0.745302732591, 7.895709940231, 2.026930360369, 0.271792657736, 0.315196108541, 0.015876847710, 0.009288507454, 0.087920280806, -0.103727794204, -4.447282126346, 0.016271459306, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.439356565475, -1.998182296753, 0.000000000000, 0.016651883721, 0.018462046981, -0.001187470742, -7.517319654181, 0.236494174025, -0.028725044803, -2.442989538035, 0.034510550810, -0.004683216652, -0.005154038690, -0.002104275246, -0.079935853309, 1.420125114638, -0.117856066698, -0.226142434271, -0.002585832387, -0.001365917341, 0.035962654791, 0.028993699893, -0.045896888864, 0.716358354284, 0.029085601036, -0.001242728387, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -2.040895462036, -0.458999156952, -0.735027790070, 0.019255757332, -0.004595622420, 0.002120360732, -0.740775522612, -2.555714688932, -0.339301128908, -0.033104023297, -1.446467788369, -0.007442776396, -0.000012314482, 0.030657946816, 1.002118140789, 0.153644862643, 1.273828227991, 1.983204935524, 0.048757213739, 0.060295617991, 0.001605314985, 0.000554368427, 0.475422075598, -0.010880647601, -0.775712358056, -0.408545111762, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -32.103607177734, 0.0, -0.503355026245, 2.297859191895, 0.000000000000, -0.021215811372, -0.021167919040, 0.015811592340, 8.689411857722, -0.215429806172, 0.063500560122, 2.847523923644, -0.297021616015, 0.001323463163, 0.002124820781, 0.068860932948, 1.694077894544, -1.639571645676, 0.110652545728, 0.728735301618, 0.003107735169, 0.003335187976, -0.042347579477, -0.034247794709, 0.469091132962, -0.814424502262, -0.018082452136, 0.016747349252, 0.000000000000 ,0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.102161169052, 32.057830810547, -2.347217559814, -0.503611564636, 0.834947586060, 0.021226570010, -0.037879735231, 0.000354003860, -0.560681623936, -3.574948145694, -0.788176766644, -0.107590635594, 0.908657075077, -0.008720966051, 0.005669792925, 0.044884407612, 0.788227489086, 0.111065913657, 1.709840089441, -0.946574755181, 0.054255711842, 0.060392345409, 0.003299051857, 0.001965592530, -0.035607238660, -0.021984114632, -0.893130060176, 0.503048977806, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -1.910972595215, 1.713829040527, -0.004005432129, -0.057411193848, 0.0, 0.013989634812, -0.000906753354, -0.290513515472, -1.440209153996, -1.089782421583, -0.599051729911, -0.930901394778, 5.044060722850, 0.079229241316, 0.074101747848, -1.301808243838, -31.393874531397, 0.233327947688, 0.478559456452, -9.198865975131, -0.002820980233, -0.034669033757, 0.022125233836, 0.019923408940, -8.159414332666, -0.129736796488, -0.298841506489, -0.300193732750, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.050176870833, -0.003161246171, -0.486165175190, 0.266534777047, 0.003826227932, 0.000001339204, 0.000001199431, -0.000022435600, -0.020657323970, 0.001301453941, 0.213359280279, 0.881596311923, 0.051809053856, -0.000000551337, -0.000000493794, 0.000009236516, -0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000022507624, -0.050176870833, 0.003161246171, -0.003826227932, 0.486165175190, -0.266739403717, -0.019757788570, 0.009012833714, 0.311015942657, 2.810181204790, -0.001602140073, -0.000000613279, -0.000000549271, 0.000010274224, 0.008134087133, -0.003710494952, 0.863507011470, -1.236460821044, 0.060184240645, 0.000000252481, 0.000000226129, -0.000004229797, -0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000010307207, 0.019757788570, -0.009012833714, 0.001602140073, -0.311015942657, 2.810095522339, -0.030385323449, 0.003110159427, 0.312812882924, 0.287354391281, -0.002331730630, -0.000000824205, -0.000000738183, 0.000013807861, -8.414922645141, -36.922139523656, -18.505141519315, -3.793715804769, -2.765572372983, 0.035944961732, -0.038910104720, 0.025846348888, 0.527826299191, 1.697201876759, 17.980094722474, 4.615721721183, 0.618925691035, 0.717763941510, 0.036154725527, 0.021151770407, 0.200211885807, -0.236208723376, -10.127341872304, 0.037053334254, 0.000013852188, 0.030385323449, -0.003110159427, 0.002331730630, -0.312812882924, 0.287229690327, 0.002667394037, 0.004496152836, 0.045956750452, 1.764514260408, 0.000146052012, 0.000000019584, 0.000000017540, -0.000000328097, -17.119523267503, 0.536693033369, 0.353775293385, -8.335731095093, 0.078527228401, 0.005987264162, 0.006725273267, -0.005979187005, -0.182029763642, 3.233906041666, -0.268381596955, -0.514971094398, -0.005888452287, -0.003110464210, 0.081894084826, 0.066024394813, -0.104516302587, 1.631289796960, 0.066233671911, -0.002829938571, -0.000000329150, -0.002667394037, -0.004496152836, -0.000146052012, -0.045956750452, -1.764522071270, 0.024056576806, -0.001361685819, -0.230715295944, 0.185551143531, 0.001832537128, 0.000000640359, 0.000000573525, -0.000010727892, -1.696796379292, -5.819307733117, -2.712299197847, -0.615817527040, -4.029675752634, 0.002306818331, -0.004623901048, 0.071938991843, 2.282021405408, 0.349879770769, 2.900759066988, 4.516150272075, 0.111029828612, 0.137305059460, 0.003655620040, 0.001262406662, 1.082630189953, -0.024777388732, -1.766450614425, -0.930338103031, -0.000010762331, -0.024056576806, 0.001361685819, -0.001832537128, 0.230715295944, -0.185649147617, -1.753103616578, 0.521869609890, 23.319318958026, 145.082271971311, -0.138741289403, -0.000051341929, -0.000045983385, 0.000860128319, -11.594360544437, -0.705424902410, -10.592707880324, -54.888617486514, -0.619258600252, -0.018180886764, -0.016310350542, 0.172267463350, 3.857750758541, -3.733629238750, 0.251977753557, 1.659474556422, 0.007076928248, 0.007594883320, -0.096433822422, -0.077989008913, 1.068213380174, -1.854605830991, -0.041177323469, 0.038137029879, 0.000862889566, 1.753103616578, -0.521869609890, 0.138741289403, -23.319318958026, -145.074852087154, 1.708539622488, 0.111898315003, -13.174473231922, 91.462755556230, 0.127584976026, 0.000043171229, 0.000038665459, -0.000723245056, -1.878010842263, 23.870898681235, 1.639719754761, -40.888303474223, 2.851614162302, 0.001349430570, -0.024984412428, 0.102862439056, 1.794950045519, 0.252919074168, 3.893644396914, -2.155538119928, 0.123550997381, 0.137525326941, 0.007512594224, 0.004476043338, -0.081084731931, -0.050062181420, -2.033833968448, 1.145542115841, -0.000725566870, -1.708539622488, -0.111898315003, -0.127584976026, 13.174473231922, -91.469578800748, -0.069753861204, 0.041269247265, 1.243498527057, 13.467483657041, -0.005772466581, -0.000002269708, -0.000002032820, 0.000038024292, -5.161896992464, -0.784811430978, -1.913888711445, -8.087612492321, 11.488701354150, 0.194411237470, 0.167838434014, -3.255004272242, -71.490067651024, 0.531333931032, 1.089774627294, -20.947639012098, -0.006423930487, -0.078948253623, 0.050383537787, 0.045369546582, -18.580601832107, -0.295436370828, -0.680521274763, -0.683600561672, 0.000038146360, 0.069753861204, -0.041269247265, 0.005772466581, -1.243498527057, -13.467174945528, -0.000000000000, -0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, -0.013549327978, -0.012135188033, 0.226991094595, 0.000000000000, 0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.012000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 11.385989897412, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -11.385989897412, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.005000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 11.385989897412, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -4.554395958965, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.005000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 4.554395958965, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.243569095885, -4.554395958965, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, -0.010000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, 4.554395958965, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -4.554395958965, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -8.500000000000, -18.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, 4.554395958965, -0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 1.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -0.000000000000, -0.000000000000, 0.000000000000, -0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -11.385989897412, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -8.500000000000, -18.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 11.385989897412, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 1.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.683186075980, 0.514736886625, 0.282998565164, 0.440668616363, -2.382738811465, -0.037424700426, -0.035002491999, 0.614952694278, 14.829958398888, -0.110759742503, -0.226034186438, 4.345468653096, 0.001333027828, 0.016376955559, -0.010465240818, -0.009422482600, -6.145615181050, 0.061014181775, 0.141165339638, 0.141806743312, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, -36.039354729710, 0.767400874818, -0.190879388177, -11.678174370212, -0.041149877278, -0.026017271417, -0.026698725144, 0.036415219598, 0.738656358350, 6.810845841283, -0.384784957980, -0.708557300741, -0.005524328707, 0.002522572903, 0.171826920583, 0.138368426838, 0.071909684799, -6.567495145681, 0.039293511274, 0.006041152866, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 1.997224587333, 13.482210983798, 2.488520358003, 0.076750797248, 0.804972334222, 0.023466195202, -0.022740687251, 0.018646161041, 0.436604617107, -0.414374632569, -6.563020897889, -1.423460802051, -0.224998971426, -0.259852011779, -0.008437464875, -0.003945344110, 0.102235829031, 0.191829027845,-6.312428841540, -0.038075090345, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 1.761524247668, -3.415298165208, -1.836225244248, -0.015605131825, 10.486845595600, -0.031379180918, 0.001266746410, 0.525873993847, 9.808565668907, -0.367529750255, 1.370405524130, -12.076970057329, 0.004883176776, -0.015765473705, -0.000399777933, -0.000497333312, 0.199818976539, -0.002648145523, -0.101212258081, -5.199268943788, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000, 0.000000000000");

	int i = 0, j = 0;

	/*
	 boost::char_separator<char> sep(", ");//, and " " a single space is the separator
	 boost::tokenizer<boost::char_separator<char> > tok(s, sep);
	 //   tokenizer<> tok(s);
	 //   for(tokenizer<boost::char_separator<double> >::iterator beg=tok.begin(); beg!=tok.end();++beg){
	 row = 28;
	 col = 6;
	 Amatrix.resize(row, col);
	 BOOST_FOREACH (const string& t, tok) {
	 try {
	 double value = boost::lexical_cast<double>(t);
	 Amatrix(i, j) = value;
	 j++;
	 if (j == col) {
	 j = 0;
	 i++;
	 }
	 if (i == row)
	 break;
	 } catch (boost::bad_lexical_cast&) {
	 cout << "Error converting the Model Matrix u\n";	//Do your errormagic
	 }
	 }

	 //this is Code is Tested and is working for matrix AU of dimension 28 x 34
	 *
	 //Initialize matrix au
	 row = 28;	col = 34;
	 AUmatrix.resize(row, col);
	 i = 0;	j = 0;
	 boost::char_separator<char> delimet(", ");//, and " " a single space is the separator
	 boost::tokenizer<boost::char_separator<char> > token(matrix_au, delimet);
	 BOOST_FOREACH (const string& tex, token) {
	 //string::size_type sz;
	 //double sum = std::stod(t, &sz);
	 try {
	 double val = boost::lexical_cast<double>(tex);
	 AUmatrix(i, j) = val;
	 j++;
	 if (j == col) {
	 j = 0;
	 i++;
	 }
	 if (i == row)
	 break;
	 } catch (bad_lexical_cast&) {
	 cout << "Error converting the Model Matrix\n";	//Do your errormagic
	 }
	 }
	 */

	AUmatrix.resize(35, 35);
	//Initialize matrix au
	row = 28;
	col = 35;
	i = 0;
	j = 0;
	boost::char_separator<char> delimet(", ");//, and " " a single space is the separator
	boost::tokenizer<boost::char_separator<char> > token(matrix_au, delimet);
	BOOST_FOREACH (const string& tex, token) {
		//string::size_type sz;
		//double sum = std::stod(t, &sz);
		try {
			double val = boost::lexical_cast<double>(tex);
			AUmatrix(i, j) = val;
			j++;
			if (j == 34) {
				AUmatrix(i, j) = 0.000000000000;//Assigning Last column (for t) = 0
				j++;
			}
			if (j == col) {
				j = 0;
				i++;
			}
			if (i == row)
				break;
		} catch (boost::bad_lexical_cast &) {
			cout << tex << " -- Error converting the Model Matrix\n";

		}
	}

	/*	cout << "\nPrinting The AU matrix\n";
	 for (int i = 0; i < row; i++) {
	 for (int j = 0; j < col; j++) {
	 cout << AUmatrix(i, j) << "\t";
	 }
	 cout << endl << endl << endl;
	 }*/

	//now we run the loop to create zeros for row 'u1...u6' and row 't' for 35 columns
	row = 35;		//row + 7;	//28 + 6 + 1;
	col = 35;
	for (int i_row = 28; i_row < row; i_row++) {//starting from 29th row ie after x28 is over for 'u1 to u6' and then for 't'
		for (int j_col = 0; j_col < col; j_col++) {
			AUmatrix(i_row, j_col) = 0.000000000000;
		}
	}
	AUmatrix(34, 34) = 1;	//set t=1

// matrix AUt has been Initialized

	/*
	 cout << "\nPrinting The AU matrix\n";
	 for (int i = 0; i < row; i++) {
	 for (int j = 0; j < col; j++) {
	 cout << AUmatrix(i, j) << "\t";
	 }
	 cout << endl << endl << endl;
	 }
	 */

//Initialization of Identity Matrix B
	row = 35;
	col = 35;
	Bmatrix.resize(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (i == j)
				Bmatrix(i, j) = 1;
			else
				Bmatrix(i, j) = 0;
		}
	}

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = AUmatrix;
	system_dynamics.U->setIsEmpty(true);	//set empty = true which is by default
	//reach_parameters.InvariantExists = false;
//	system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);	//set empty = true which is by default
//	Dynamics Initalised ---------------------

}

#endif /* HELICOPTER_H_ */
