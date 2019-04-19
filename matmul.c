#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv){
	srand(time(NULL));

	for(int matrix_size=0; matrix_size<=800; matrix_size += 50){
		printf("N=%d\n", matrix_size);
		// Building the input matrices
		
		float matrix1[matrix_size][matrix_size];
		float matrix2[matrix_size][matrix_size];
		float result_matrix[matrix_size][matrix_size];

		for(int row=0; row<matrix_size; row++){
			for(int col=0; col<matrix_size; col++){
				// Generate randou floats between -1 and 1
				matrix1[row][col] = (float)rand()/RAND_MAX*2.0 - 1.0;
				matrix2[row][col] = (float)rand()/RAND_MAX*2.0 - 1.0;

				result_matrix[row][col] = 0.0;
			}
		}

		// Running matrix multiplication by rows
		clock_t t;

		t = clock();

		for(int row=0; row<matrix_size; row++){
			for(int col=0; col<matrix_size; col++){
				for(int i=0; i<matrix_size; i++){
					result_matrix[row][col] = result_matrix[row][col] + (matrix1[row][i] * matrix2[i][col]);
				}
			}
		}

		t = clock() - t;

		// Printing elapsed time
		float elapsed_time = ((float)t)/CLOCKS_PER_SEC;

		printf( "linhas: %f\n", elapsed_time );

		// Running matrix multiplication by columns
		t = clock();

		for(int col=0; col<matrix_size; col++){
			for(int row=0; row<matrix_size; row++){
				for(int i=0; i<matrix_size; i++){
					result_matrix[row][col] = result_matrix[row][col] + (matrix1[row][i] * matrix2[i][col]);
				}
			}
		}

		t = clock() - t;

		// Printing elapsed time
		elapsed_time = ((float)t)/CLOCKS_PER_SEC;

		printf( "colunas: %f\n\n", elapsed_time );
	}

	return 0;
}