//Loads necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define N 2000 // Defines the size of the matrix

int main(int argc, char *argv[]){
    char *size = argv[1];
    int N = atoi(size);
    printf("Size of Matrix: %d\n\n", N);
    float m1[N][N],m2[N][N]; // Declares 2 matrices of size N
    float ** m_res; // And a result matrix.
    int i, j, k; // Iterators
    clock_t t; // Declares a clock

    // Initialize Matrix 1
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            m1[i][j] = i*i*1.7453+j*3.674528;
        }
    }

    // Initialize Matrix 2
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            m2[i][j] =  i*j*1.3569875*6.76512;
        }
    }

    m_res = (float **)calloc(N, sizeof(float *)); // Allocate an initial array for matrix
    for (int i = 0; i < N; i++)
        m_res[i] = (float *)calloc(N, sizeof(float)); // Allocate the array for each array (now, it's N by N)

    t = clock(); // Starts the time
    float tmp;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp = 0.0;
            for (k = 0; k < N; k++)
                tmp += m1[i][k] * m2[k][j]; // Computes the product
            m_res[i][j] = tmp; // Assign value to the matrix
        }
    }
    double exec_time = ((double)t)/CLOCKS_PER_SEC; // Finishes the time
    printf("Time to Row = %f seconds.\n", exec_time);
    
    t = clock(); // Starts the time
    tmp = 0.0;
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            tmp = 0.0;
            for (k = 0; k < N; k++)
                tmp += m1[i][k] * m2[k][j]; // Computes the product
            m_res[i][j] = tmp; // Assign value to the matrix
        }
    }
    exec_time = ((double)t)/CLOCKS_PER_SEC; // Finishes the time
    printf("Time to Column = %f seconds.\n", exec_time);

    printf("%f %f %f\n",m_res[0][0],m_res[0][1],m_res[0][2]);
}