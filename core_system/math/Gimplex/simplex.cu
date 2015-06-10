#include "simplex.cuh"
//Tested Working for Both Helicopter and Five Dimensional system with Reduction for Min
//Implemented Reduction. But without Streams.

__global__ void mykernel(float *S_MAT, int S_row, int S_col, float *Result,
		int S_N, int *S_Sel, float *R_data, int *R_index) {

	//int index = threadIdx.x + (blockIdx.x * blockDim.x);
	int index = blockIdx.x;
	if (index < S_N) {
		int tid;
		int i; // used for for index
		unsigned int temp_index;
		unsigned int temp_index1;
		int base = index * S_row * S_col;
		int R_base = index * blockDim.x;  // blockDim.x = 96
		__shared__ bool c;
		__shared__ int rm;
		__shared__ int row;	//pivotRow
		__shared__ int pivotCol;//pivotCol this can remove global variable S_Sel

		int col = 1;
		/** remember, col1 arrays exclusively accessed by the threads of a block
		 * Data shared between threads in a block
		 * */
		__shared__ int remember[96]; //Found a column which is negative but theta/Min has no positive value
		__shared__ float col1[60];	//pivotColumn
		/*************/
		c = false;
		rm = 0;
		row = -1;		//pivotRow
		pivotCol = -1;
		__syncthreads();
		while (!c) {
			c = true;
			__syncthreads();
			//   ***************** Get_Pivot function begins  *****************
			//this get_pivot should be done by only one thread as there is too many critical section to handle
			/*if (threadIdx.x == 0) {
			 row = get_pivot(&S_MAT[0], S_row, S_col, &S_Sel[0], base, index);
			 }	//end of if one thread
			 __syncthreads();*/

			//int minValue = 0, newpivotcol = -1;
			int Last_row = S_row - 1;	// Last row
			//if (threadIdx.x == 0) {
			//using reduction to compute min and newpivotcol
			//	__shared__ bool notEntered;
			__shared__ float minValue;
			__shared__ int newpivotcol;
			if (threadIdx.x == 0) {
				minValue = 0;
				newpivotcol = -1;
				//	notEntered = true;
				//printf("R_base = %d\n",R_base);
			}
			__syncthreads();	//making sure newpivotcol is initialised to -1

			if (threadIdx.x >= 2 && threadIdx.x < (S_col - 1)) {
				tid = threadIdx.x - 2;//here my tid should be from 0 to (evenThreadId - 1)
				int j = threadIdx.x;//is the actual column/index number less than (S_col - 1)
				int data_size = (S_col - 1) - 2;
				//printf("Data_size = %d ", data_size);
				temp_index = Last_row + j * S_row + base;//avoiding re-computation
				R_data[tid + R_base] = S_MAT[temp_index];	//	g_data[i];
				R_index[tid + R_base] = j;//tid; should be the real index of the data
				__syncthreads();//here will have all values in shared memory from 0 to index

				for (i = (data_size / 2); i > 0;) {
					if (tid < i) {
						//	if ((R_data[tid] >= R_data[tid + s]) && ((R_data[tid + s] < 0) && (R_data[tid] < 0))){
						if (R_data[tid + R_base] >= R_data[tid + R_base + i]) {
							R_data[tid + R_base] = R_data[tid + R_base + i];
							R_index[tid + R_base] = R_index[tid + R_base + i];
							//	notEntered = false;  //race condition avoided
						}
					}
					__syncthreads();
					i >>= 1;
					if ((i != 1) && (i % 2) != 0) {	//if s is odd
						i = i + 1;
					}
				}
				// if (notEntered == false && tid == 2) { // tid==0 is always true if minValue is still -1 then what?
				if (tid == 0) { // tid==0 is always true if minValue is still -1 then what?
					//	if (notEntered == false) {
					minValue = R_data[0 + R_base];
					newpivotcol = R_index[0 + R_base];
					//	}
				}
				__syncthreads();
			}
			__syncthreads();	//here we have min and newpivotcol
			/*	//TODO:: use reduction to compute min and newpivotcol
			 for (int j = 2; j < S_col - 1; j++) {//only last row but all column
			 unsigned int temp_index1 = Last_row + j * S_row + base;	//avoiding re-computation
			 if (S_MAT[temp_index1] < minValue) {
			 minValue = S_MAT[temp_index1];
			 newpivotcol = j;
			 }
			 }
			 }
			 __syncthreads();	//here we have min and newpivotcol
			 */

			if (threadIdx.x == 0) {
				if (newpivotcol == -1) {
					//return -2;
					row = -2;
				} else {
					float row_min = INT_MAX;
					float row_num = -1;
					//TODO:: this temp_res can be an array of value computed in parallel
					//TODO:: row_min and row_num can then be computed using reduction
					for (i = 0; i < S_row - 1; i++) {

						temp_index = newpivotcol * S_row + i + base; //avoiding re-computation
						temp_index1 = i + (S_col - 1) * S_row + base; //avoiding re-computation
						if ((S_MAT[temp_index] > 0)
								&& (S_MAT[temp_index1] > 0)) {
							float temp_res = S_MAT[temp_index1]
									/ S_MAT[temp_index]; //avoiding re-computation
							if (temp_res <= row_min) {
								row_min = temp_res;
								row_num = i;
							}
						}
					}
					//*S_Sel = newpivotcol;
					//pivotCol = newpivotcol;
					S_Sel[index] = newpivotcol;
					if (row_min == INT_MAX) {
						//return -1;
						row = -1;
					}
					if (row_num != -1) {
						//return row_num;
						row = row_num;
					}
				}
			} //end of one thread
			__syncthreads();

			//   ***************** Get_Pivot function ends  *****************

			col = S_Sel[index];
			//col = *S_Sel;
			//col = pivotCol;
			if (row > -1) {
				tid = threadIdx.x;
				if (threadIdx.x >= 2 && threadIdx.x < S_col) {
					//for (int i1 = 2; i1 < S_col; i1++) {		//Data Parallel section 1
					if (tid == remember[tid - 2]) {
						temp_index = (S_row - 1) + (tid * S_row) + base; //avoiding re-computation
						S_MAT[temp_index] = -1 * S_MAT[temp_index]; //replacing back to original
					}
				}		//Data Parallel section 1 done
				__syncthreads();
				tid = threadIdx.x;
				if (threadIdx.x >= 0 && threadIdx.x < S_row) {
					//for (int i = 0; i < S_row; i++) {	//Data Parallel section 2
					col1[tid] = S_MAT[(tid + col * S_row) + base];//keeping the old pivotcol coeff
				}	//Data Parallel section 2 done
				__syncthreads();

				unsigned int temp_row_base = row + base;//avoiding re-computation
				S_MAT[temp_row_base + S_row] =
						S_MAT[temp_row_base + col * S_row];
				//S_MAT[temp_row_base] = col - 1;
				S_MAT[row + base] = col - 1;//now temp_row_base is not required
				tid = threadIdx.x;
				if (threadIdx.x >= 2 && threadIdx.x < S_col) {
					//for (int j = 2; j < S_col; j++){		//Data Parallel section 3
					unsigned int row_base = row + base;	//avoiding re-computation
					temp_index = row_base + (tid * S_row);//avoiding re-computation
					S_MAT[temp_index] = S_MAT[temp_index] / col1[row];//S_MAT[row_base + S_row];
					//S_MAT[temp_index] = S_MAT[temp_index] / S_MAT[row_base + S_row];
				}		//Data Parallel section 3 done
				__syncthreads();
				//printf("Row here = %d",row);
				tid = threadIdx.x;
				if (threadIdx.x >= 0 && threadIdx.x < S_row) {
					//for (int i = 0; i < S_row; i++) {	//Data parallel section 4
					for (i = 2; i < S_col; i++) {
						if (tid != row) {
							temp_index1 = i * S_row + base;
							temp_index = tid + temp_index1;
							S_MAT[temp_index] = S_MAT[temp_index]
									- (col1[tid] * S_MAT[row + temp_index1]);
						} else {
							break;
						}
					}
				}	//Data Parallel section 4 done
				__syncthreads();

				//if (threadIdx.x >= 2 && threadIdx.x < (S_col - 1)){
				//tid = threadIdx.x;
				if (threadIdx.x == 0) {
					for (i = 2; i < (S_col - 1); i++) {
						if (S_MAT[((S_row - 1) + i * S_row) + base] < 0) {
							c = false; // check needed for race condition here.
							break;
						}
					}
				}
				__syncthreads();

			} else if (row == -1) {
				c = true;
				remember[rm] = col;
				if (threadIdx.x == 0) {
					rm++;
				}
				__syncthreads();

				temp_index = (S_row - 1) + (col * S_row) + base;
				S_MAT[temp_index] = -1 * S_MAT[temp_index];	//remembering by making positive

				//if (threadIdx.x >= 2 && threadIdx.x < (S_col - 1)){
				// tid = threadIdx.x;
				if (threadIdx.x == 0) {
					for (i = 2; i < (S_col - 1); i++) {		//Data parallel 5
						if ((S_MAT[((S_row - 1) + i * S_row) + base] < 0)) {
							c = false; // check needed for race condition here.
							break;
						}
					}
				}
				__syncthreads();
			}
		} //end of while
		__syncthreads();
		if (threadIdx.x == 0) {
			//printf("Value = %f ",S_MAT[(S_row - 1 + (S_col - 1) * S_row) + base]);
			Result[index] = S_MAT[(S_row - 1 + (S_col - 1) * S_row) + base];
		}
	}
}

__host__ Simplex::Simplex(int N_S) {
	number_of_LPs = N_S;
	i = 0;
	a = 0.0;
	M = 0;
	N = 0;
	NB = 0;
	c = 0;
	No_c = 0;
	f = j = 0;
//	Sel = (int *) malloc(N_S * sizeof(int));
	R = (float*) malloc(N_S * sizeof(float));
	/*
	 MAT = (float *) malloc(N_S * M * N * sizeof(float));
	 N_MAT = (float *) malloc(N_S * M * N * sizeof(float));
	 cudaMalloc((void **) &G_MAT, (N_S * M * (N + 1) * sizeof(float)));*/
	/*	cudaError_t err;
	 err = cudaMalloc((void **) &G_R, N_S * sizeof(float));
	 */

	//printf("CUDA malloc G_R: %s\n", cudaGetErrorString(err));
	cudaMalloc((void **) &G_Sel, N_S * sizeof(int));
	//printf("CUDA malloc G_Sel: %s\n", cudaGetErrorString(err));
}

//get status of particular simplex
__host__ int Simplex::getStatus(int n) {
	int s;
	for (int i = 0; i < C.size1(); i++) {
		if (i == (n - 1)) {
			if (R[i] == -1) {
				s = 6;	// 6 = Simplex Is Unbounded
			} else if (R[i] > 0) {
				s = 2;	// 2= Simplex has feasible and Optimal solution
			}
		}
	}
	return s;

}	//get status of particular simplex

//get the No of simplex the object is ruuning on GPU
__host__ int Simplex::getNo_OF_Simplx() {
	return C.size1();
}	//get the No of simplex the object is ruuning on GPU

//get the result of all simplex
__host__ std::vector<float> Simplex::getResultAll() {

	std::vector<float> Res(C.size1());
	for (int i = 0; i < C.size1(); i++) {
		Res[i] = R[i];
	}
	return Res;
}

//get the result of all simplex

__host__ float Simplex::getResult(int n) {
	// get result of particular simplex
	float r;
	for (int i = 0; i < C.size1(); i++) {
		if (i == (n - 1)) {
			r = R[i];
		}
	}
	return r;
}	// get result of particular simplex

__host__ std::vector<int> Simplex::getStatusAll() {

	std::vector<int> Status(C.size1());
	for (int i = 0; i < C.size1(); i++) {
		if (R[i] == -1)
			Status[i] = 6;
		else
			Status[i] = 2;
	}
	return Status;
}	//get the status of all simplex

__host__ void Simplex::setConstratint(math::matrix<double> &A,
		std::vector<double> &B) {
	int N_S = number_of_LPs;
	orig_CoefficientMatrix = A;
	BoundValue = B;

//	A = math::matrix<float>(A1);
//	B = std::vector<float>(B1);
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
	MAT = (float *) malloc(N_S * M * N * sizeof(float));
	/*cudaMalloc((void **) &G_MAT, (N_S * M * N * sizeof(float)));
	 cudaMalloc((void **) &G_R, N_S * sizeof(float));
	 cudaMalloc((void **) &G_Sel, N_S * sizeof(int));*/

	for (int s = 0; s < N_S; s++) {
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				if ((j == 0) && (i != (M - 1))) {
					MAT[(int) ((i + j * M) + (M * N * s))] = NB;
					NB = NB + 1;
				} else if (j == 1) {
					MAT[(int) ((i + j * M) + (M * N * s))] = 0;
				} else if ((j > 1) && (i != (M - 1))) {
					if (j < (No_O + 2)) {
						//Coefficient of A
						MAT[(int) ((i + j * M) + (M * N * s))] = (float) A(i,
								j - 2);
					} else if (j == N - 1) {
						//std::cout<<"Enter RHS of coefficient "<< i+1 <<"\n";
						MAT[(int) ((i + j * M) + (M * N * s))] = (float) B[i];
					} else if (j < N - 1) {
						if ((MAT[(int) ((i + j * M) + (M * N * s))] != 1)
								&& (f == 0)) {
							if (j > c) {
								MAT[(int) ((i + j * M) + (M * N * s))] = 1;
								f = 1;
								c = j;
							} else {
								MAT[(int) ((i + j * M) + (M * N * s))] = 0;
							}
						} else {
							MAT[(int) ((i + j * M) + (M * N * s))] = 0;
						}
					}
				} else if ((i == M - 1) && (j > 1)) {
					if (j < 2 + No_O) {
						continue;

					} else {
						MAT[(int) ((i + j * M) + (M * N * s))] = 0;
					}
				} else {
					MAT[(int) ((i + j * M) + (M * N * s))] = 0;
				}
			}
			f = 0;
		}
		NB = M, f = 0, c = 1 + No_O;
	}
}	//setting constraints of simplex

__host__ void Simplex::ComputeLP(math::matrix<float> &C1) {

	cudaError_t err;
	//If the size of threads exceeds 32(warp-size) be careful of (unknown error/deadlock/abort) situation
	//For helicopter the variable=28+slack(56 constraints) + 0 (artificial) + 3(extra) = 87 NEEDS 32 * INT(87/32) + 32
	//For Five Dim System the variable=5+slack(10 constraints) + 1 (artificial) + 3(extra) = 19 NEEDS 32 * INT(19/32) + 32
	unsigned int threads_per_block;	//Maximum threads depends on CC 1.x =512 2.x and > = 1024

	unsigned int number_of_blocks;//depends on our requirements (better to be much more than the number of SMs)

	int device;
	cudaDeviceProp props;
	cudaGetDevice(&device);
	cudaGetDeviceProperties(&props, device);
	/*
	 std::cout<<"\nprops.major = "<<props.major;
	 std::cout<<"\nprops.minor = "<<props.minor;
	 std::cout<<"\nprops.maxThreadsPerBlock = "<<props.maxThreadsPerBlock;
	 std::cout<<"\nprops.sharedMemPerMultiprocessor = "<<props.sharedMemPerMultiprocessor;
	 std::cout<<"\nprops.sharedMemPerBlock = "<<props.sharedMemPerBlock;
	 std::cout<<"\nprops.multiProcessorCount = "<<props.multiProcessorCount;

	 int total_SMs = props.multiProcessorCount;//returns the number of SMs the device has

	 if (props.major < 2) {	//only 512 threads per block :: but number of resident blocks per SM is 2.x/3.x/5.x = 8/16/32 times the SM
	 if (this->number_of_LPs > (total_SMs * 8)){ //at least 8 times the SMs
	 std::cout<<"Too many LPs to solve!!! DEVICE unable to handle";
	 number_of_blocks = this->number_of_LPs;
	 }
	 }else{	//1024 threads per block supported    ::

	 number_of_blocks = this->number_of_LPs;

	 }
	 */

	int No_C = orig_CoefficientMatrix.size1();
	C = math::matrix<float>(C1);

	int N_S = C.size1(), i, j, k, count = 0, basen, base;

	err = cudaMalloc((void **) &G_R, N_S * sizeof(float));//Doing it here for the First Time

	int No_O = C.size2();
	M = No_C + 1, N = No_O + 3 + No_C;
	int N_C = No_C, ch;
	NB = M, f = 0, c = 1 + No_O;
	float sum = 0;
	for (int s = 0; s < N_S; s++) {
		for (i = M - 1; i < M; i++) {
			for (j = 2; j < N; j++) {
				if (j < 2 + No_O) {
					MAT[(int) ((i + j * M) + (M * N * s))] = -C(s, j - 2);
				} else {
					MAT[(int) ((i + j * M) + (M * N * s))] = 0;
				}
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
	threads_per_block = 32 * (nc / 32) + 32; //if count equal 0 than nc=N so works for for Model
	if (threads_per_block > props.maxThreadsPerBlock) //Assuming maximum threads supported by CC is 1024
		threads_per_block = props.maxThreadsPerBlock;

	int *R_index;	//reduction data
	float *R_data;	//reduction index
	err = cudaMalloc((void **) &R_data, C1.size1() * threads_per_block * sizeof(float));//C1.size1() * 96 being the maximum threads
	err = cudaMalloc((void **) &R_index, C1.size1() * threads_per_block * sizeof(int));//C1.size1() being the number of LPs
	//printf("CUDA malloc R_index: %s\n", cudaGetErrorString(err));

	//std::cout << "Number of threads per block = " << threads_per_block << "\n";

	if (count > 0) {		//Helicopter model has no negative bound so count=0
		N_MAT = (float *) malloc(N_S * M * nc * sizeof(float));
		for (i = 0; i < N_S; i++) {
			for (j = 0; j < M; j++) {
				base = i * M * N;
				basen = i * M * nc;
				//base=i*M*N;
				N_MAT[j + ((nc - 1) * M) + basen] =
						MAT[j + ((N - 1) * M) + base];
			}
		}
//Creating Artificial Variables
		for (k = 0; k < N_S; k++) {
			base = k * M * N;
			basen = k * M * nc;
			for (i = 0; i < M; i++) {
				ch = 0;
				for (j = 0; j < nc; j++) {
					if (MAT[i + ((N - 1) * M) + base] < 0) {
						if ((j >= (N - 1)) && (j < (nc - 1))) {
							/*if(i==(S_row-1))
							 binayak[(i+j*S_row)+base]=-1;
							 else*/if (!ch) {
								N_MAT[(i + j * M) + basen] = 1;
								ch = 1;
							}
						} else if (j == (nc - 1)) {
							N_MAT[(i + j * M) + basen] = -1
									* N_MAT[(i + j * M) + basen];
						} else if (j == 1) {
							N_MAT[(i + j * M) + basen] = -1;
						}

						else if (j == 0) {
							N_MAT[((i + j * M)) + basen] = ((N - M) + i + 3
									+ No_O);
						}

						/*else if(j==0){
						 //int cb=S_col+i;
						 binayak[(int)((i+j*S_row)+base)]=S_col+i;
						 }
						 */
						else if (j > 1) {
							N_MAT[(i + j * M) + basen] = -1
									* (MAT[(i + j * M) + base]);
						}
					} else if ((i != (M - 1)) && (j < N - 1)) {
						N_MAT[(i + j * M) + basen] = MAT[(i + j * M) + base];
					} else if ((i != (M - 1)) && (j == nc - 1)) {
						continue;
					} else if (i == (M - 1)) {
						if ((j >= (N - 1)) && (j < nc - 1)) {
							N_MAT[(i + j * M) + basen] = -1;
						} else if (j == nc - 1) {
							continue;
						} else {
							N_MAT[(i + j * M) + basen] = 0;
						}
						//else{
						//N_MAT[(i+j*M)]=-1;
						//}
					} else {
						N_MAT[(i + j * M) + basen] = 0;
					}
				}
			}
		}
		//Checked
		//Creation of new Z
		/*std::cout << "Simplex -BEFORE CREATION OF Z\n";
		 for (k = 0; k < N_S; k++) {
		 basen = k * M * nc;
		 for (i = 0; i < M; i++) {
		 for (j = 0; j < nc; j++) {
		 std::cout << N_MAT[(i + j * M) + basen] << "("
		 << ((i + j * M) + basen) << ")\t";
		 }
		 std::cout << "\n";
		 }
		 std::cout << "\n";
		 }*/
//Creation of Last Row or Z-Value(Z-C)
		for (k = 0; k < N_S; k++) {
			sum = 0;
			//base = k * M * N;
			basen = k * M * nc;
			for (int k1 = 2; k1 < nc; k1++) {
				sum = 0;
				for (j = 0; j < (M - 1); j++) {
					sum = sum
							+ (N_MAT[(j + k1 * M) + basen]
									* N_MAT[(j + 1 * M) + basen]);
					//std::cout << N_MAT[(j + k1 * M) + basen] << "*"<< N_MAT[(j + 1 * M) + basen] << "\t";
				}
				//std::cout << sum << "-"	<< N_MAT[((M - 1) + k1 * M) + basen];
				N_MAT[((M - 1) + k1 * M) + basen] = sum
						- N_MAT[((M - 1) + k1 * M) + basen];
				//std::cout << "=" << N_MAT[((M - 1) + k1 * M) + basen]
				//<< "\n";

			}
		}
		//cudaEvent_t start, stop;
		/*std::cout << "Simplex -AFTER CREATION OF Z\n";
		 for (k = 0; k < N_S; k++) {
		 basen = k * M * nc;
		 for (i = 0; i < M; i++) {
		 for (j = 0; j < nc; j++) {
		 std::cout << N_MAT[(i + j * M) + basen] << "("
		 << ((i + j * M) + basen) << ")\t";
		 }
		 std::cout << "\n";
		 }
		 std::cout << "\n";
		 }*/

		cudaMalloc((void **) &G_MAT, (N_S * M * nc * sizeof(float)));
		//printf("CUDA malloc G_MAT: %s\n", cudaGetErrorString(err));
		cudaMemcpy(G_MAT, N_MAT, (N_S * M * nc * sizeof(float)),
				cudaMemcpyHostToDevice);
		//printf("CUDA malloc N_MAT: %s\n", cudaGetErrorString(err));
		//	cudaMemcpy(G_Sel, Sel, sizeof(int), cudaMemcpyHostToDevice);
		//printf("CUDA malloc G_Sel: %s\n", cudaGetErrorString(err));

		mykernel<<<N_S, threads_per_block>>>(G_MAT, M, nc, G_R, N_S, G_Sel, R_data, R_index);
		//mykernel<<<N_S, 96>>>(G_MAT, M, nc, G_R, N_S, R_data, R_index);

		cudaDeviceSynchronize();
		cudaMemcpy(R, G_R, N_S * sizeof(float), cudaMemcpyDeviceToHost);
		cudaMemcpy(N_MAT, G_MAT, (N_S * M * nc * sizeof(float)),
				cudaMemcpyDeviceToHost);
		/*std::cout<< "***********Final SIMPLEX from GPU*************\n Time took:\n";
		 for (k = 0; k < N_S; k++) {
		 // base=k*M*N;
		 basen = k * M * nc;
		 for (i = 0; i < M; i++) {
		 for (j = 0; j < nc; j++) {
		 std::cout << N_MAT[(i + j * M) + basen] << "("
		 << ((i + j * M)) << ")\t";
		 }
		 std::cout << "\n";
		 }
		 std::cout << "\n";
		 }*/

		//	std::cout << "Result for Artificial\n";
		for (i = 0; i < N_S; i++) {
			base = i * M * N;
			basen = i * M * nc;
			for (j = 0; j < M; j++) {
				for (k = 0; k < N; k++) {
					if (N_MAT[j + basen] == k + 1) {
						//std::cout<<"Row value="<<N_MAT[j+basen]<<"\n N_MAT[j+M+basen]"<<N_MAT[j+M+basen];
						//std::cout<<"MAT[1+(2+j)*M+base]"<<MAT[(M-1)+(2+k)*M+base]<<"\n";
						N_MAT[j + M + basen] =
								MAT[(M - 1) + (2 + k) * M + base];
					}
				}
			}
		}

		for (int s = 0; s < N_S; s++) {

			if (R[s] == 0) {
				sum = 0;
				base = s * M * N;
				basen = s * M * nc;
				for (i = 0; i < N; i++) {
					sum = 0;
					for (j = 0; j < M; j++) {
						if ((j < M - 1)) {
							if (i != (N - 1)) {
								//std::cout<<N_MAT[(j+(i*M))+basen]<<"*"<<N_MAT[(j+(1*M))+basen]<<std::endl;
								sum = sum
										+ (N_MAT[(j + (i * M)) + basen]
												* N_MAT[(j + (1 * M)) + basen]);
								MAT[(j + (i * M)) + base] = N_MAT[(j + (i * M))
										+ basen];
							} else if (i == N - 1) {
								sum = sum
										+ (N_MAT[(j + (nc - 1) * M) + basen]
												* N_MAT[(j + (1 * M)) + basen]);
								MAT[(j + (i * M)) + base] = N_MAT[(j
										+ (nc - 1) * M) + basen];
							}
						}
						if (j == (M - 1)) {
							if (i > 1) {
								//std::cout<<sum<<" And "<<MAT[(j+(i*M))+base]<<std::endl;
								MAT[(j + (i * M)) + base] = MAT[(j + (i * M))
										+ base] + (-1) * sum;
							}
						}
					}
					//}
					//}
				}

			}

		}

		cudaFree(G_MAT);
		//		cudaFree(G_R);
		//cudaFree(G_Sel);
		//cudaDeviceSynchronize();
		//		cudaMalloc((void **) &G_R, N_S * sizeof(float));
		cudaMalloc((void **) &G_MAT, (N_S * M * N * sizeof(float)));
		// printf("CUDA malloc G_MAT: %s\n", cudaGetErrorString(err));
		cudaMemcpy(G_MAT, MAT, (N_S * M * N * sizeof(float)),
				cudaMemcpyHostToDevice);
		//printf("CUDA malloc N_MAT: %s\n", cudaGetErrorString(err));
		//	cudaMemcpy(G_Sel, Sel, sizeof(int), cudaMemcpyHostToDevice);
		//printf("CUDA malloc G_Sel: %s\n", cudaGetErrorString(err));

		mykernel<<<N_S, threads_per_block>>>(G_MAT, M, N, G_R, N_S, G_Sel, R_data, R_index);
		//mykernel<<<N_S, 96>>>(G_MAT, M, N, G_R, N_S, R_data, R_index);
		cudaDeviceSynchronize();
		cudaMemcpy(R, G_R, N_S * sizeof(float), cudaMemcpyDeviceToHost);

		/*cudaMemcpy(MAT, G_MAT, (N_S * M * N * sizeof(float)),
		 cudaMemcpyDeviceToHost);*/
		//std::cout
		// << "***********Final SIMPLEX from GPU*************\n Time took:\n";*/
	}

	else {
		//cudaEvent_t start, stop;

		err = cudaMalloc((void **) &G_MAT, (N_S * M * N * sizeof(float)));
		//printf("CUDA malloc G_MAT : %s\n", cudaGetErrorString(err));
		err = cudaMemcpy(G_MAT, MAT, (N_S * M * N * sizeof(float)),
				cudaMemcpyHostToDevice);
		//printf("CUDA memcpy G_MAT : %s\n", cudaGetErrorString(err));

		//err = cudaMemcpy(G_Sel, Sel, sizeof(int), cudaMemcpyHostToDevice);
		//printf("CUDA memcpy G_Sel: %s\n", cudaGetErrorString(err));
		/*std::cout << "Simplex -AFTER CREATION OF Z\n";

		 for (i = 0; i < M; i++) {
		 for (j = 0; j < N; j++) {
		 std::cout << MAT[(i + j * M)] << "(" << (i + j * M) << ")\t";
		 }
		 std::cout << "\n";
		 }*/
		mykernel<<<N_S, threads_per_block>>>(G_MAT, M, N, G_R, N_S, G_Sel, R_data, R_index);
		//mykernel<<<N_S, 96>>>(G_MAT, M, N, G_R, N_S, R_data, R_index);
		//	cudaDeviceSynchronize();		//removed as hopping that cudaFree will handle it
		err = cudaMemcpy(R, G_R, N_S * sizeof(float), cudaMemcpyDeviceToHost);
		//printf("CUDA memcpy G_R: %s\n", cudaGetErrorString(err));
		//cudaMemcpy(MAT, G_MAT, (N_S * M * N * sizeof(float)), cudaMemcpyDeviceToHost);
		//	std::cout << "N_S = " << N_S << std::endl;
	}
//	cudaFree(G_MAT);
//	cudaFree(G_Sel);
	cudaFree(R_index);	//Only to synchronise with the cudamemcpy
//	cudaDeviceReset();

}

//  Computes the entire list of LPs by diving into different blocks :: this interface not use at present
std::vector<float> Simplex::bulkSolver(math::matrix<float> &List_of_ObjValue) {
	unsigned int tot_lp = List_of_ObjValue.size1();
	std::cout << "Total LPs " << tot_lp << std::endl;
	int lp_block_size = 1000;//input how many LPs you want to solve at a time ??????
	unsigned int number_of_blocks;
	if (tot_lp % lp_block_size == 0)
		number_of_blocks = tot_lp / lp_block_size;
	else
		number_of_blocks = (tot_lp / lp_block_size) + 1;
	std::cout << "Total Blocks " << number_of_blocks << std::endl;

	std::list<block_lp> bulk_lps(number_of_blocks);	//list of sub-division of LPs
	struct block_lp myLPList;
	myLPList.block_obj_coeff.resize(lp_block_size, List_of_ObjValue.size2());
	math::matrix<float> block_obj_coeff(lp_block_size,
			List_of_ObjValue.size2());
	unsigned int index = 0;
	for (unsigned int lp_number = 0; lp_number < tot_lp; lp_number++) {
		for (unsigned int i = 0; i < List_of_ObjValue.size2(); i++) {
			myLPList.block_obj_coeff(index, i) = List_of_ObjValue(lp_number, i);
		}
		index++;
		if (index == lp_block_size) {
			index = 0;
			bulk_lps.push_back(myLPList);
		}
	}	//end of all LPs
	std::list<block_lp_result> bulk_result(number_of_blocks);
	struct block_lp_result eachBlock;
	eachBlock.results.resize(lp_block_size);	//last block will be less

	for (std::list<block_lp>::iterator it = bulk_lps.begin();
			it != bulk_lps.end(); it++) {
		ComputeLP((*it).block_obj_coeff);
		eachBlock.results = this->getResultAll();
		bulk_result.push_back(eachBlock);
	}
	std::vector<float> res(tot_lp);
	unsigned int index_res = 0;
	for (std::list<block_lp_result>::iterator it = bulk_result.begin();
			it != bulk_result.end(); it++) {
		unsigned int block_result_size = (*it).results.size();
		for (unsigned int i = 0; i < block_result_size; i++) {
			res[index_res] = (*it).results[i];
			index_res++;
		}
	}
	std::cout << "Result size = " << res.size() << std::endl;
//R = res;
	return res;
}

