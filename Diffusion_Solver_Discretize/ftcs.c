#include "header.h"

/*Run FTCS by taking in original Gaussian and timestepping for however many user chooses*/
void ftcs(double ***m, double ***new, double nx, double ny, double nz, double dt, double dc, int bc, double bcVal, int totalSteps){
	int i, j, k;
	int x_len, y_len, z_len, numSteps;
	double dx, up, down, left, right, front, back, C, q;
	dx = .01;
	C = ((dc*dt)/pow(dx, 2));
	q = 0;
	x_len = nx;
	y_len = ny;
	z_len = nz;
	numSteps = 0;


	/*Main While LOOP -> Create new matrix by looking at original m values then memcopy new to m to start over*/

	while (numSteps < totalSteps){

		for (i = 0; i< nx; i++){
			for (j = 0; j < ny; j++){
				for (k = 0; k < nz; k++){
					if (i == 0){
						if(bc == 0){
							up = 0;
						}
						else if (bc == 1){
							up = bcVal;
						}
						else if (bc == 2){
							up = m[x_len - 1][j][k];
						}
					}
					else{
						up = m[i-1][j][k];
					}

					if (i == nx - 1){
						if (bc == 0){
							down = 0;
						}
						else if (bc == 1){
							down = bcVal;
						}
						else if (bc == 2){
							down = m[0][j][k];
						}
					}
					else {
						down = m[i+1][j][k];
					}

					if (j == 0){
						if (bc == 0){
							left = 0;
						}
						else if(bc == 1){
							left = bcVal;
						}
						else if (bc == 2){
							left = m[i][y_len - 1][k];
						}
					}
					else {
						left = m[i][j-1][k];
					}

					if (j == ny - 1){
						if (bc == 0){
							right = 0;
						}
						else if (bc == 1){
							right = bcVal;
						}
						else if (bc == 2){
							right = m[i][0][k];
						}
					}
					else {
						right = m[i][j+1][k];
					}

					if (k == 0){
						if (bc == 0){
							back = 0;
						}
						else if (bc == 1){
							back = bcVal;
						}
						else if (bc == 2){
							back = m[i][j][z_len - 1];
						}
					}	
					else {
						back = m[i][j][k-1];
					}
					if (k == nz - 1){
						if (bc == 0){
							front = 0;
						}
						else if (bc == 1){
							front = bcVal;
						}
						else if (bc == 2){
							front = m[i][j][0];
						}
					}
					else {
						front = m[i][j][k+1];
					}

					new[i][j][k] = m[i][j][k] + (C*(up + down + right + left + back + front - (6*(m[i][j][k])))) + source(nx, ny, nz);
				}
			}
		}

/*		printGraph(m, nx, ny, nz);   */
		/*Copy the new Matrix to the old matrix so we can start again, bump the # of steps taken*/		
		memcpy(m, new, nx*ny*nz + 1);
		numSteps++;
	}
}



