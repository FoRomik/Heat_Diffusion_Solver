#include "header.h"

/*Print all values of 3D matrix*/
void printMatrix(double ***mat, double nx, double ny, double nz){
	int i, j, k;
	for (i = 0; i < nx; i++){
		for(j = 0; j < ny; j++){
			for (k = 0; k < nz; k++){
				printf("%.3lf\t", mat[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

/*print slice of matrix to get 2D graph*/
void printGraph(double ***mat, double nx, double ny, double nz){
	int i, j, k, half;
	for (i = 0; i < nx; i++){
		for(j = 0; j < ny; j++){
			for (k = 0; k < nz; k++){
				half = nz/2;	
				if (k == half){
					if (j == ny - 1){
						printf("%.3lf", mat[i][j][k]);
					}
					else{
						printf("%.3lf,", mat[i][j][k]);
					}
				}
			}
		}
		printf("\n");
	}
}

void print2D(double **A, int size){
	int i, j; 
	for (i = 0; i < size; i++){
		printf("\n%d)\n", i);
		for (j = 0; j < size; j++){
			printf("%.2lf ", A[i][j]);
		}           
	}
}



