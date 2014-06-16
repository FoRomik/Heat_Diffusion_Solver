#include "mg.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cg(double ** A, double * b, int n){
	int i, j, iter;
	double a, tol, err, beta, max, result_r0, result_r1, result_p0;
	tol = 1.e-6;
	err = 1000;
	result_r0 = result_r1 = 0;
	
	double * x = (double *)malloc(sizeof(double)*n);
	double * temp = (double *)malloc(sizeof(double)*n);
	double * r0 = (double*)malloc(sizeof(double)*n);
	double * p0 = (double*)malloc(sizeof(double)*n);
	double * x0 = (double*)malloc(sizeof(double)*n);
	double * result_ap0 =  (double*)malloc(sizeof(double)*n);
	double * x1 = (double*)malloc(sizeof(double)*n);
	double * r1 = (double*)malloc(sizeof(double)*n);
	double * p1 = (double*)malloc(sizeof(double)*n);
	double * result_Ap0 = (double*)malloc(sizeof(double)*n);
	double * result_aAp0 = (double*)malloc(sizeof(double)*n);
	double * result_betap0 = (double*)malloc(sizeof(double)*n);

	for (i = 0; i < n; i++){
		x0[i] = 0;
		temp[i] = 0;
		result_Ap0[i] = 0;
		result_aAp0[i] = 0;
		r0[i] = 0;
	}

	//copy vectors
	copyVector(r0, b, n);
	copyVector(p0, r0, n);

	iter = 0;

	//Begin While loop with tolerance check
	while (err > tol){
		iter = iter + 1;

		for (i = 0; i < n; i++){
			result_r0 += r0[i] * r0[i];
		//	printf("result_r0: %lf\n", result_r0);
		}
		
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				temp[i] += (A[i][j] * p0[j]);
		//		printf("temp[%d]: %lf\n", j , temp[j]);
			}
		}

		for (i = 0; i < n; i++){
			result_p0 += (temp[i] * p0[i]);
		//	printf("result_p0: %lf\n", result_p0);
		}

		//Get a
		a = (result_r0)/(result_p0);
//		printf("a: %lf\n", a);
		
		for (i = 0; i < n; i++){
			result_ap0[i] += a * p0[i];  
		//	printf("result_ap0[%d]: %lf\n", i, result_ap0[i]);
		}
		
		//Get x1
		for (i = 0; i < n; i++){
			x1[i] = x0[i] + result_ap0[i];
		//	printf("x1[%d]: %lf \n", i, x1[i]);
		}	

		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				result_Ap0[i] += (p0[j] * A[i][j]);   
			}
		}

		for (i = 0; i < n; i++){
			result_aAp0[i] = (result_Ap0[i] * a);
		//	printf("result_aAp0[%d]: %lf\n", i, result_aAp0[i]);
		}

		//Get r1
		for (i = 0; i < n; i++){
			r1[i] = (r0[i] - result_aAp0[i]);
//			printf("r1[%d]: %lf\n", i, r1[i]);
		}

		
		//Get Beta		
		for (i = 0; i < n; i++){
			result_r1 += (r1[i] * r1[i]);
//			printf("ResultR1: %lf\n", result_r1);
//			printf("ResultR0: %lf\n", result_r0);
		}

		beta = (result_r1)/(result_r0);
//		printf("Beta: %lf\n", beta);

		//Get p1
		for (i = 0; i < n; i++){
			result_betap0[i] = (beta * p0[i]);
			p1[i] = r1[i] + result_betap0[i];
//			printf("p1[%d]: %lf \n", i, p1[i]);
		}

		//Get norm of r1
		max = 0;
		for (i = 0; i < n; i++){
			max += pow(r1[i],2);
		}

		//Get err value
		err = sqrt(max);
//		printf("Error: %lf\n", err);

		//Copy and clear vectors to restart next iteration
		copyVector(p0, p1, n);
		copyVector(x0, x1, n);
		copyVector(r0, r1, n);
		clearVector(p1, n);
		clearVector(x1, n);
		clearVector(r1, n);
		clearVector(result_ap0, n);
		clearVector(result_Ap0, n);
		result_r0 = 0;
		result_r1 = 0;
		result_p0 = 0;
	}

	//Solution x
	copyVector(x, x0, n);

	for (int i = 0; i < n; i++){
//		printf("x[%d] = %lf \n", i, x[i]);
	}
//	printf("Iter: %d\n" , iter);
	//return x
}

void copyVector(double * aout, double * ain, int n){
	for (int i = 0; i < n; i++){
		aout[i] = ain[i];
	}
}

void clearVector(double * v, int n){
	for (int i = 0; i < n; i++){
		v[i] = 0;
	}
}

