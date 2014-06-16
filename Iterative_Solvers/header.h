#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define JACOBI 0
#define GS 1
#define SOR 2

/*Input Struct */
typedef struct {
	/*X,Y,Z dimensions are assumed equal for this assignment*/
	double x;
	double y;
	double z;
	/*Number of steps total*/
	int nSteps;
	/*Number of iterations per step*/
	int maxIter;
	/*C constants*/
	double alpha;
	double dt;
	double dx;
	double w;
	/*Boundary tempterature - assume 0 in testing*/
	double dtemp;
} Input;

double *** init(double x, double y, double z);
void printMatrix(double ***mat, double x, double y, double z);
void printGraph(double ***mat, double x, double y, double z);
void gaussNoise(double *** matrix, double x, double y, double z);
int check_for_min(double *** temp, double *** mat, Input input);
void jacobi(double *** Matrix, Input input);
void copy(double *** dest, double *** src, Input input);
void gs(double *** Matrix, Input input);
void sor(double *** Matrix, Input input);
