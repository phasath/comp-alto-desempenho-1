//Loads necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <omp.h>

int main(int argc, char *argv[]){
    char *size = argv[1];
    int N = atoi(size);
    printf("Size of Matrix: %d\n\n", N);
    
    std::vector< std::vector<float>> mtr(N); // Declares a matrix of size N
    std::vector<float> vtr(N); // Declares a vector of size N
    std::vector<float> v_res(N); // And a result matrix.

    int i, j, k; // Iterators
    clock_t t1, t2; // Declares a clock

    #pragma omp Parallel default(none) shared(mtr) private(i, j) schedule(dynamic) num_threads(8)
    {
        #pragma omp for
        // Initialize Matrix and vector
        for(i=0; i<N; ++i){
            vtr[i] =  i*1.3569875*6.76512;
            mtr[i] = std::vector<float>(N);
            for(j=0; j<N; j++){
                mtr[i][j] = i*i*1.7453+j*3.674528;
            }
        }
    }

    t1 = clock(); // Starts the time
    register float tmp1;

    printf("Starting Parallel Row\n");

    #pragma omp Parallel default(none) shared(mtr, vtr, v_res) private(tmp1, i, j) schedule(dynamic, 2) num_threads(8)
    {
        
        #pragma omp for 
        for (i = 0; i < N; i++) {
            tmp1 = 0.0;
            for (j = 0; j < N; j++) {
                tmp1 += mtr[i][j] * vtr[j]; // Computes the product
            }
            v_res[i] = tmp1; // Assign value to the matrix
        }
    }
    double exec_time1 = ((double)t1)/CLOCKS_PER_SEC; // Finishes the time
    printf("Time to Parallel Row = %f seconds.\n", exec_time1);
    
}