//Loads necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define N 2000 // Defines the size of the matrix

int main(int argc, char *argv[]){
    char *size = argv[1];
    int N = atoi(size);
    printf("Size of Matrix: %d\n\n", N);
    float m1[N][N]; // Declares a matrix of size N
    float m2[N]; // Declares a vector of size N
    float * m_res; // And a result matrix.
    int i, j, k; // Iterators
    clock_t t; // Declares a clock

    // Initialize Matrix
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            m1[i][j] = i*i*1.7453+j*3.674528;
        }
    }

    // Initialize Vector
    for(i=0; i<N; ++i){
        m2[i] =  i*1.3569875*6.76512;
    }

    m_res = (float *)calloc(N, sizeof(float)); // Allocate an initial array for matrix

    t = clock(); // Starts the time
    float tmp;
    for (i = 0; i < N; i++) {
        tmp = 0.0;
        for (j = 0; j < N; j++) {
            tmp += m1[i][j] * m2[j]; // Computes the product
        }
        m_res[i] = tmp; // Assign value to the matrix
    }
    double exec_time = ((double)t)/CLOCKS_PER_SEC; // Finishes the time
    printf("Time to Row = %f seconds.\n", exec_time);
    
    t = clock(); // Starts the time
    for (j = 0; j < N; j++) {
        tmp = 0.0;
        for (i = 0; i < N; i++) {
            tmp += m1[i][j] * m2[j]; // Computes the product
        }
        m_res[i] = tmp; // Assign value to the matrix
    }    
    exec_time = ((double)t)/CLOCKS_PER_SEC; // Finishes the time
    printf("Time to Column = %f seconds.\n", exec_time);
}