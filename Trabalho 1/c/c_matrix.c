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
    
    std::vector< std::vector<float> > m1(N); // Declares a matrix of size N
    std::vector<float> m2(N); // Declares a vector of size N
    std::vector<float> m_res(N); // And a result matrix.

    int i, j, k; // Iterators
    clock_t t1, t2; // Declares a clock

    // Initialize Matrix
    for(i=0; i<N; ++i){
        m1[i] = std::vector<float>(N);
        for(j=0; j<N; ++j){
            m1[i][j] = i*i*1.7453+j*3.674528;
        }
    }

    // Initialize Vector
    for(i=0; i<N; ++i){
        m2[i] =  i*1.3569875*6.76512;
    }

    t1 = clock(); // Starts the time
    register float tmp1;

    printf("Starting Parallel Row\n");

    #pragma omp Parallel default(none) shared(m1, m2, m_res) private(tmp1, i, j) schedule(dynamic) num_threads(20)
    {
        
        #pragma omp for
        for (i = 0; i < N; i++) {
            tmp1 = 0.0;
            for (j = 0; j < N; j++) {
                tmp1 += m1[i][j] * m2[j]; // Computes the product
            }
            m_res[i] = tmp1; // Assign value to the matrix
        }
    }
    double exec_time1 = ((double)t1)/CLOCKS_PER_SEC; // Finishes the time
    printf("Time to Parallel Row = %f seconds.\n", exec_time1);
    

    t2 = clock(); // Starts the time
    float tmp2;

    printf("Starting Row\n");
    for (i = 0; i < N; i++) {
        tmp2 = 0.0;
        for (j = 0; j < N; j++) {
            tmp2 += m1[i][j] * m2[j]; // Computes the product
        }
        m_res[i] = tmp2; // Assign value to the matrix
    }
    double exec_time2 = ((double)t2)/CLOCKS_PER_SEC; // Finishes the time
    printf("Time to Row = %f seconds.\n", exec_time2);

    // t = clock(); // Starts the time
    // for (j = 0; j < N; j++) {
    //     tmp = 0.0;
    //     for (i = 0; i < N; i++) {
    //         tmp += m1[i][j] * m2[j]; // Computes the product
    //     }
    //     m_res[i] = tmp; // Assign value to the matrix
    // }    

    // exec_time = ((double)t)/CLOCKS_PER_SEC; // Finishes the time
    // printf("Time to Column = %f seconds.\n", exec_time);
}