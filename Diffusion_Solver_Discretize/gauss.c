#include "header.h"

/*Add in the Gaussian Distribution + Noise values*/
void gaussNoise(double ***gauss, double nx, double ny, double nz, double dt, double std){
	int i, j, k, count;
	double db, noise;
	noise = (.1) * (rand() / (double)RAND_MAX);
	printf("%.3lf\n", noise);
	count = 0;
	db = 2.00;
	for (i = 0; i < nx; i++){
		for (j = 0; j < ny; j++){
			for (k = 0; k < nz; k++){
				gauss[i][j][k] = exp(-(pow((i*dt)-((nx*dt)/2), 2)/(db*std))-(pow((j*dt)-((ny*dt)/2), 2)/(db*std))-(pow((k*dt)-((nz*dt)/2), 2)/(db*std))) + noise;
				 }
		}
	}
}

double source(double nx, double ny, double nz){
	return 0.00;
}


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

double ** init2(double nx, double ny, double nz){
	int i, size;
	double ** A = (double **)malloc(sizeof(double*)*nx*ny*nz);
	size = nx*ny*nz;
	for (i = 0; i < size; i++){
		A[i] = (double*)malloc(sizeof(double)*nx*ny*nz);
	}  

	return A;
}

