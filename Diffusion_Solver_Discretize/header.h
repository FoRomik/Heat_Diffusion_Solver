#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

double ***init(double x, double y, double z); 
double **init2(double nx, double ny, double nz);
void gaussNoise(double ***gauss, double nx, double ny, double nz, double dt, double std);
double source(double x, double y, double z);
void printMatrix(double ***m, double nx, double ny, double nz);
void printGraph(double ***m, double nx, double ny, double nz);
void print2D(double **A, int size);
void ftcs(double ***m, double ***new, double nx, double ny, double nz, double dt, double dc, int bc, double bcVal, int totalSteps);
void cn(double ***m, double *b, double nx, double ny, double nz, double dt, double dc, int bc, double bcVal, int totalSteps);
