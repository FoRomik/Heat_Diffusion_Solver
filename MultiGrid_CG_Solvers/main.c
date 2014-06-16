#include "mg.h"
#include "nrutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv){

	//ADD IN C + Source Term here for USER GENERATED C + SOURCE.

	int i,j;
	FILE *outfile;
	double **f;
	double **g;
	double **h;
	double * b1;
	double * b2;
	double * b3;
	double C, alpha, dt, dx;
	double t1, t2, t3, time_taken1, time_taken2, time_taken3;
	double c1, c2, c3, c_taken1, c_taken2, c_taken3;

	/* Input Values for C*/
	dt = .005;
	dx = .01;
	alpha = .01;
	/* End of Input*/

	C = ((alpha*dt)/pow(dx, 2));

	int n=4097;
	int ncycle=1;

	f = dmatrix(1,n,1,n);
	f[1023][1023]=1.0;
	g = dmatrix(1,n,1,n);
	g[500][500]=1.0;
	h = dmatrix(1,n,1,n);
	h[250][250]=1.0;
	//  for (i=2;i<n;++i)
	//  for (j=2;j<n;++j)
	//    f[i][j] = 2.0;

/*	printf("-------- Running MG --------- \n");
	  t1 = clock();  
	    mglin(f,n,ncycle,C);
	    t1 = clock() - t1;
	    time_taken1 = ((double)t1)/CLOCKS_PER_SEC;

	    printf("Problem Size = 1023:\t%lf\n", time_taken1);

	    t2 = clock();
	    mglin(g,n,ncycle,C);
	    t2 = clock() - t2;
	    time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
	    printf("Problem Size = 500:\t%lf\n", time_taken2);

	    t3 = clock();
	    mglin(h,n,ncycle,C);
	    t3 = clock() - t3;
	    time_taken3 = ((double)t3)/CLOCKS_PER_SEC;

	    printf("Problem Size = 250:\t%lf\n", time_taken3);
*/
	 
	//  outfile = fopen("soln.dat", "w");
	/*  fwrite(&f[1][1],sizeof(double),n*n,outfile);*/
	/*  fclose(outfile);*/

	n = 1023;
	b1 = (double*)malloc(sizeof(double)*n);
	for (i = 0; i < n; i++){
		b1[i] = 1.0;
	}

	double ** A1 = (double**)malloc(sizeof(double*));
	for (i = 0; i < n; i++){
		A1[i] = (double*)malloc(sizeof(double)*n);
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			A1[i][j] = 1.0;
		}
	}

	c1 = clock();
	cg(A1, b1, n);
	c1 = clock() - c1;
	c_taken1 = ((double)c1)/CLOCKS_PER_SEC;
	printf("--------- Running CG ---------- \n");
	printf("Problem Size = 1023:\t%lf\n", c_taken1);


	n = 500;
	b2 = (double*)malloc(sizeof(double)*n);
	for (i = 0; i < n; i++){
		b2[i] = 1.0;
	}
	double ** A2 = (double**)malloc(sizeof(double*));
	for (i = 0; i < n; i++){
		A2[i] = (double*)malloc(sizeof(double)*n);
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			A2[i][j] = 1.0;
		}   
	}

	c2 = clock();
	cg(A2, b2, n); 
	c2 = clock() - c2;
	c_taken2 = ((double)c2)/CLOCKS_PER_SEC;
	printf("Problem Size = 500:\t%lf\n", c_taken2);
	
	n = 250;
	b3 = (double*)malloc(sizeof(double)*n);
	for (i = 0; i < n; i++){
		b3[i] = 1.0;
	}

	double ** A3 = (double**)malloc(sizeof(double*));
	for (i = 0; i < n; i++){
		A3[i] = (double*)malloc(sizeof(double)*n);
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			A3[i][j] = 1.0;
		}   
	}

	c3 = clock();
	cg(A3, b3, n); 
	c3 = clock() - c3;
	c_taken3 = ((double)c3)/CLOCKS_PER_SEC;
	printf("Problem Size = 250:\t%lf\n", c_taken3);
}

