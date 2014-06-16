#include "header.h"

void cn(double *** m, double * b, double nx, double ny, double nz, double dt, double dc, int bc, double bcVal, int totalSteps){

	int i, j, k, index, size, row, col;
	int x, y, z;
	int upI, downI, rightI, leftI, backI, frontI;
	double ** A = init2(nx, ny, nz);
	size = nx*ny*nz;
	x = nx;
	y = ny;
	z = nz;
	col = 0;

	for (i = 0; i < nx; i++){
		for (j = 0; j < ny; j++){
			for (k = 0; k < nz; k++){
				index = i*ny*nz + j*nz + k;
				b[index] = m[i][j][k];
			}
		}
	}
	
	/*Set initial values of 2D matrix A*/
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			if (i == j){
				A[i][j] = -6*b[i];
			}
			else{
				A[i][j] = 0;
			}
		}
	}

	/*Now lets build out the A Matrix, row by row*/
	row = 0;
	for (i = 0; i < nx; i++){
		for (j = 0; j < ny; j++){
			for (k = 0; k < nz; k++){
				if (i == 0){
					upI = (nx-1)*ny*nz + j*nz + k;					
					
					if (bc == 1){
						A[row][upI] = bcVal;
					}
					else if (bc == 2){
						A[row][upI] = b[upI];
					}
					else {
						A[row][upI] = 0;
					}
				}

				else {
					upI = row - ny*nz;
					A[row][upI] = b[upI];
				}

				if (i == nx - 1){
					downI = j*nz + k;
					if (bc == 1){
						A[row][downI] = bcVal;
					}
					else if (bc == 2){
						A[row][downI] = b[downI];
					}
					else {
						A[row][downI] = 0;
					}
				}
				else {
					downI = row + ny*nz;
					A[row][downI] = b[downI];
				}
				
				if (j == 0){
					leftI = row + ((ny-1)*(nx));
					if (bc == 1){
						A[row][leftI] = bcVal;
					}
					else if (bc == 2){
						A[row][leftI] = b[leftI];
					}
					else {
						A[row][leftI] = 0;
					}
					
				}
				else {
					leftI = row - ny;
					A[row][leftI] = b[leftI];
				}

				if (j == ny - 1){
					rightI = row - ((ny-1)*(nx));
					if (bc == 1){
						A[row][rightI] = bcVal;
					}
					else if (bc == 2){
						A[row][rightI] = b[rightI];
					}
					else {
						A[row][rightI] = 0;
					}
				}
				else {
					rightI = row + ny;
					A[row][rightI] = b[rightI];
				}

				if (k == 0){
					backI = row + (nz-1);
					if (bc == 1){
						A[row][backI] = bcVal;
					}
					else if (bc == 2){
						A[row][backI] = b[backI];
					}
					else{
						A[row][backI] = 0;
					}
				}
				else {
					backI = row - 1;
					A[row][backI] = b[backI];
				}
					
				if (k == nz - 1){
					frontI = row - (nz-1); 
					if (bc == 1){
						A[row][frontI] = bcVal;
					}
					else if (bc == 2){
						A[row][frontI] = b[frontI];
					}
					else{
						A[row][frontI] = 0;
					}
				}
				else {
					frontI = row + 1;
					A[row][frontI] = b[frontI];
				}
				
				row++;
			}
		}
	}


	/*Used this to check that 7 values were in each row of the A matrix
	for (i = 0; i< size; i++){
		count = 0;
		for (j = 0; j < size; j++){
			if (A[i][j] != 0){
				count++;
			}
		}
		printf("A[%d] = %d\n", i, count);
	}
*/

}

