#include "simplex_CPU.h"
//  ********** CPU Computation Only ********************
//Solves only One LP problem and returns the Result
float Simplex(float *S_MAT, int S_row, int S_col) {

	int tid;
	int i; // used for for index
	unsigned int temp_index;
	unsigned int temp_index1;

	bool c;
	int rm, row;	//pivotRow
	int pivotCol;	//pivotCol this can remove global variable S_Sel

	int col = 1;
	/** remember, col1 arrays exclusively accessed by the threads of a block
	 * Data shared between threads in a block
	 * */
	int remember[96]; //Found a column which is negative but theta/Min has no positive value
	float col1[60];	//pivotColumn

	/*************/
	c = false;
	rm = 0;
	row = -1;		//pivotRow

	while (!c) {

		c = true;
		int minValue = 0, newpivotcol = -1;
		int Last_row = S_row - 1;	// Last row

		//   ***************** Get_Pivot function begins  *****************

		//this get_pivot should be done by only one thread as there is too many critical section to handle
		/*if (threadIdx.x == 0) {
		 row = get_pivot(&S_MAT[0], S_row, S_col, &S_Sel[0], base, index);
		 }	//end of if one thread
		 __syncthreads();*/
		//TODO:: use reduction to compute min and newpivotcol
		for (int j = 2; j < S_col - 1; j++) {	//only last row but all column
			unsigned int temp_index1 = Last_row + j * S_row;//avoiding re-computation
			if (S_MAT[temp_index1] < minValue) {
				minValue = S_MAT[temp_index1];
				newpivotcol = j;
			}
		}
		if (newpivotcol == -1) {
			//return -2;
			row = -2;
		} else {
			float row_min = INT_MAX;
			float row_num = -1;
			//TODO:: this temp_res can be an array of value computed in parallel
			//TODO:: row_min and row_num can then be computed using reduction
			for (i = 0; i < S_row - 1; i++) {
				temp_index = newpivotcol * S_row + i; //avoiding re-computation
				temp_index1 = i + (S_col - 1) * S_row; //avoiding re-computation
				if ((S_MAT[temp_index] > 0) && (S_MAT[temp_index1] > 0)) {
					float temp_res = S_MAT[temp_index1] / S_MAT[temp_index]; //avoiding re-computation
					if (temp_res <= row_min) {
						row_min = temp_res;
						row_num = i;
					}
				}
			}
			//*S_Sel = newpivotcol;
			pivotCol = newpivotcol;
			//S_Sel[index] = newpivotcol;
			if (row_min == INT_MAX) {
				//return -1;
				row = -1;
			}
			if (row_num != -1) {
				//return row_num;
				row = row_num;
			}
		}

		//   ***************** Get_Pivot function ends  *****************

		//col = S_Sel[index];
		//col = *S_Sel;
		col = pivotCol;
		if (row > -1) {
			for (tid = 2; tid < S_col; tid++) {	//Data Parallel section 1
				if (tid == remember[tid - 2]) {
					temp_index = (S_row - 1) + (tid * S_row); //avoiding re-computation
					S_MAT[temp_index] = -1 * S_MAT[temp_index]; //replacing back to original
				}
			}
			for (tid = 0; tid < S_row; tid++) {	//Data Parallel section 2
				col1[tid] = S_MAT[(tid + col * S_row)]; //keeping the old pivotcol coeff
			}	//Data Parallel section 2 done

			//unsigned int temp_row_base = row + base;//avoiding re-computation
			//S_MAT[temp_row_base + S_row] =	S_MAT[temp_row_base + col * S_row];
			//S_MAT[temp_row_base] = col - 1;
			S_MAT[row] = col - 1;			//now temp_row_base is not required
			for (tid = 2; tid < S_col; tid++) {	//Data Parallel section 3
				temp_index = row + (tid * S_row);	//avoiding re-computation
				S_MAT[temp_index] = S_MAT[temp_index] / col1[row];//S_MAT[row_base + S_row];
				//S_MAT[temp_index] = S_MAT[temp_index] / S_MAT[row_base + S_row];
			}		//Data Parallel section 3 done
			//printf("Row here = %d",row);
			for (tid = 0; tid < S_row; tid++) {	//Data parallel section 4
				for (i = 2; i < S_col; i++) {
					if (tid != row) {
						temp_index1 = i * S_row;
						temp_index = tid + temp_index1;
						S_MAT[temp_index] = S_MAT[temp_index]
								- (col1[tid] * S_MAT[row + temp_index1]);
					} else {
						break;
					}
				}
			}	//Data Parallel section 4 done

			for (i = 2; i < (S_col - 1); i++) {
				if (S_MAT[((S_row - 1) + i * S_row)] < 0) {
					c = false; // check needed for race condition here.
					break;
				}
			}

		} else if (row == -1) {
			c = true;
			remember[rm] = col;
			rm++;

			temp_index = (S_row - 1) + (col * S_row);
			S_MAT[temp_index] = -1 * S_MAT[temp_index];	//remembering by making positive

			for (i = 2; i < (S_col - 1); i++) {		//Data parallel 5
				if ((S_MAT[((S_row - 1) + i * S_row)] < 0)) {
					c = false; // check needed for race condition here.
					break;
				}
			}
		}
	} //end of while
	  //printf("Value = %f ",S_MAT[(S_row - 1 + (S_col - 1) * S_row) + base]);
	return S_MAT[(S_row - 1 + (S_col - 1) * S_row)];
}

Simplex_CPU::Simplex_CPU() {
	i = 0;
	a = 0.0;
	M = 0;
	N = 0;
	NB = 0;
	c = 0;
	No_c = 0;
	f = j = 0;
}

void Simplex_CPU::setConstratint_CPU(math::matrix<double> &A,
		std::vector<double> &B) {
	int N_S = 1;
	orig_CoefficientMatrix = A;
	BoundValue = B;

	int No_O = A.size2();
//std::cout << "No of Variable is " << A.size2() << " And no of constraints "	<< A.size1() << std::endl;
	int No_C = A.size1();
	M = No_C + 1;
	N = No_O + 3 + No_C;
	c = 1 + No_O;
	NB = c;
	f = 0;

	/*Sel = (int *) malloc(N_S * sizeof(int));
	 R = (float*) malloc(N_S * sizeof(float));*/
	MAT = (float *) malloc(N_S * M * N * sizeof(float));	//Paged Memory
	orig_MAT = (float *) malloc(N_S * M * N * sizeof(float));	//Paged Memory
	for (int s = 0; s < N_S; s++) {
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				if ((j == 0) && (i != (M - 1))) {
					MAT[(int) ((i + j * M) + (M * N * s))] = NB;
					orig_MAT[(int) ((i + j * M) + (M * N * s))] = NB;
					NB = NB + 1;
				} else if (j == 1) {
					MAT[(int) ((i + j * M) + (M * N * s))] = 0;
					orig_MAT[(int) ((i + j * M) + (M * N * s))] = 0;
				} else if ((j > 1) && (i != (M - 1))) {
					if (j < (No_O + 2)) {
						//Coefficient of A
						MAT[(int) ((i + j * M) + (M * N * s))] = (float) A(i,
								j - 2);
						orig_MAT[(int) ((i + j * M) + (M * N * s))] = (float) A(
								i, j - 2);
					} else if (j == N - 1) {
						//std::cout<<"Enter RHS of coefficient "<< i+1 <<"\n";
						MAT[(int) ((i + j * M) + (M * N * s))] = (float) B[i];
						orig_MAT[(int) ((i + j * M) + (M * N * s))] =
								(float) B[i];
					} else if (j < N - 1) {
						if ((MAT[(int) ((i + j * M) + (M * N * s))] != 1)
								&& (f == 0)) {
							if (j > c) {
								MAT[(int) ((i + j * M) + (M * N * s))] = 1;
								orig_MAT[(int) ((i + j * M) + (M * N * s))] = 1;
								f = 1;
								c = j;
							} else {
								MAT[(int) ((i + j * M) + (M * N * s))] = 0;
								orig_MAT[(int) ((i + j * M) + (M * N * s))] = 0;
							}
						} else {
							MAT[(int) ((i + j * M) + (M * N * s))] = 0;
							orig_MAT[(int) ((i + j * M) + (M * N * s))] = 0;
						}
					}
				} else if ((i == M - 1) && (j > 1)) {
					if (j < 2 + No_O) {
						continue;

					} else {
						MAT[(int) ((i + j * M) + (M * N * s))] = 0;
						orig_MAT[(int) ((i + j * M) + (M * N * s))] = 0;
					}
				} else {
					MAT[(int) ((i + j * M) + (M * N * s))] = 0;
					orig_MAT[(int) ((i + j * M) + (M * N * s))] = 0;
				}
			}
			f = 0;
		}
		NB = M, f = 0, c = 1 + No_O;
	}
}	//setting constraints of simplex

float Simplex_CPU::ComputeLP_CPU(std::vector<double> &C) {

	int No_C = orig_CoefficientMatrix.size1();
	float res;
	int i, j, k, count = 0, basen, base;

	int No_O = C.size();
	M = No_C + 1, N = No_O + 3 + No_C;
	int N_C = No_C, ch;
	NB = M, f = 0, c = 1 + No_O;
	float sum = 0;

	// ***** copying the Entire A and B matrix from orig_MAT
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			MAT[i + j * M] = orig_MAT[i + j * M];
		}
	}

// ***** copying the objective value in the Last_Row
	for (i = M - 1; i < M; i++) {
		for (j = 2; j < N; j++) {
			if (j < 2 + No_O) {
				MAT[(int) (i + j * M)] = (float) -C[j - 2];
			} else {
				MAT[(int) (i + j * M)] = 0;
			}
		}
	}

	for (i = 0; i < N_C; i++) {
		//std::cout << B[i] << "\n";
		if (BoundValue[i] < 0) {
			count++;
			//std::cout<<B[i]<<"\n";
		}
	}
//std::cout<<"C="<<count<<"\n";
	int nc = N + count;

	if (count > 0) {	//Helicopter model has no negative bound so count=0
		N_MAT = (float *) malloc(M * nc * sizeof(float));//NOTE: CHANGING THIS TO PINNED MEMORY SLOW DOWN

		// ***** copying the Entire A and B matrix from orig_MAT
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				N_MAT[i + j * M] = orig_MAT[i + j * M];
			}
		}
		// ***** copying the boundary Value from orig_MAT
		for (j = 0; j < M; j++) {
			N_MAT[j + (nc - 1) * M] = orig_MAT[j + (N - 1) * M];
		}

		// ********** copying Artificial Variables
		for (i = 0; i < M; i++) {
			ch = 0;
			for (j = 0; j < nc; j++) {
				if (orig_MAT[i + ((N - 1) * M)] < 0) {
					if ((j >= (N - 1)) && (j < (nc - 1))) {
						if (!ch) {
							N_MAT[(i + j * M)] = 1;
							ch = 1;
						}
					} else if (j == (nc - 1)) {
						N_MAT[(i + j * M)] = -1 * N_MAT[(i + j * M)];
					} else if (j == 1) {
						N_MAT[(i + j * M)] = -1;
					}

					else if (j == 0) {
						N_MAT[((i + j * M))] = ((N - M) + i + 3 + No_O);
					} else if (j > 1) {
						N_MAT[(i + j * M)] = -1 * (orig_MAT[(i + j * M)]);
					}
				} else if ((i != (M - 1)) && (j < N - 1)) {
					N_MAT[(i + j * M)] = orig_MAT[(i + j * M)];
				} else if ((i != (M - 1)) && (j == nc - 1)) {
					continue;
				} else if (i == (M - 1)) {
					if ((j >= (N - 1)) && (j < nc - 1)) {
						N_MAT[(i + j * M)] = -1;
					} else if (j == nc - 1) {
						continue;
					} else {
						N_MAT[(i + j * M)] = 0;
					}
				} else {
					N_MAT[(i + j * M)] = 0;
				}
			}
		}
		// ************************************
		//  ********Creation of new Z // Last_Row
		sum = 0;
		for (int k1 = 2; k1 < nc; k1++) {
			sum = 0;
			for (j = 0; j < (M - 1); j++) {
				sum = sum + (N_MAT[(j + k1 * M)] * N_MAT[(j + 1 * M)]);
			}
			N_MAT[((M - 1) + k1 * M)] = sum - N_MAT[((M - 1) + k1 * M)];
		}
		//  ********Creation of new Z // Last_Row Ends

		res = Simplex(N_MAT, M, nc);

		//std::cout << "Result for Artificial\n";
		for (j = 0; j < M; j++) {
			for (k = 0; k < N; k++) {
				if (N_MAT[j] == k + 1) {
					N_MAT[j + M] = orig_MAT[(M - 1) + (2 + k) * M];	//All the rows of First Column
					//std::cout << "Amit " << orig_MAT[(M - 1) + (2 + k) * M]<< " Amit";
				}
			}
		}

		if (res == 0) {
			sum = 0;
			// **** computing the Last_Row **********
			for (i = 0; i < N; i++) {
				sum = 0;
				for (j = 0; j < M; j++) {
					if ((j < M - 1)) {
						if (i != (N - 1)) {
							sum = sum
									+ (N_MAT[(j + (i * M))]
											* N_MAT[(j + (1 * M))]);
							MAT[(j + (i * M))] = N_MAT[(j + (i * M))];
						} else if (i == N - 1) {
							sum = sum
									+ (N_MAT[(j + (nc - 1) * M)]
											* N_MAT[(j + (1 * M))]);
							MAT[(j + (i * M))] = N_MAT[(j + (nc - 1) * M)];
						}
					}
					if (j == (M - 1)) {
						if (i > 1) {
							MAT[(j + (i * M))] = MAT[(j + (i * M))]
									+ (-1) * sum;
						}
					}
				}
				// *********** Last_Row computed
			}
		}
		res = Simplex(MAT, M, N);
		//std::cout << "\nResult = " << res << "\n";
	} else {
		res = Simplex(MAT, M, N);
		//	std::cout << "\nResult = " << res << "\n";
	}
	return res;
}
