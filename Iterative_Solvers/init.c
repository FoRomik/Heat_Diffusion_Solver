#include "header.h"

/*Malloc the 3D Matrix*/
double *** init(double x, double y, double z){ 
	double *** new = (double ***)malloc(sizeof(double**) * x); 
	int i, j;
	for (i = 0; i < x; i++){
		new[i] = (double**)malloc(sizeof(double*) * y); 
		for (j = 0; j < y; j++){
			new[i][j] = (double*)malloc(sizeof(double) * z); 
		}   
	}   

	return new;
}

/*Add in the Gaussian Distribution + Noise values*/
void gaussNoise(double ***gauss, double nx, double ny, double nz){
	int i, j, k;
	double db, dt, std, noise;
	noise = (.1) * (rand() / (double)RAND_MAX);
	dt = .01;
	std = .001;
	db = 2.00;
	for (i = 0; i < nx; i++){
		for (j = 0; j < ny; j++){
			for (k = 0; k < nz; k++){
				gauss[i][j][k] = exp(-(pow((i*dt)-((nx*dt)/2), 2)/(db*std))-(pow((j*dt)-((ny*dt)/2), 2)/(db*std))-(pow((k*dt)-((nz*dt)/2), 2)/(db*std))) + noise;
			}   
		}   
	}   
}
