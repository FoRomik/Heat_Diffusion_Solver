#include "header.h"

void sor(double *** xold, Input input){

	int i, j, k, m, n;
	int check;

	double up, down, left, right, front, back, C;
	C = ((input.dt * input.alpha)/(pow(input.dx, 2)));
	double *** xnew = init(input.x, input.y, input.z);
	double *** x = init(input.x, input.y, input.z);

	/*Total Steps*/
	for (n = 0; n < input.nSteps; n++){
		double *** temp = x;
		memcpy(x, xold, input.x*input.y*input.z*sizeof(double));
		memcpy(xold, temp, input.x*input.y*input.z*sizeof(double));
		
		/*Total Iterations per Step*/
		for (m = 0; m < input.maxIter; m++){
			/*Copy x into xnew like GS*/
			copy(xnew, x, input);
			
			/*Run through all values*/
			for (i = 0; i < input.x; i++){
				for (j = 0; j < input.y; j++){
					for (k = 0; k < input.z; k++){
						if (i == 0){ 
							up = input.dtemp; 
						}   
						else{
							up = x[i-1][j][k];
						}   
						if (i == input.x - 1){ 
							down = input.dtemp;
						}   
						else {
							down = x[i+1][j][k];
						}   
						if (j == 0){ 
							left = input.dtemp;
						}   
						else {
							left = x[i][j-1][k];
						}   
						if (j == input.y - 1){ 
							right = input.dtemp;
						}   
						else {
							right = x[i][j+1][k];
						}   
						if (k == 0){ 
							back = input.dtemp;
						}   
						else {
							back = x[i][j][k-1];
						}   
						if (k == input.z - 1){ 
							front = input.dtemp;
						}   
						else {
							front = x[i][j][k+1];
						}
					       	/*update x value based on the SOR function*/	
						x[i][j][k] = (1-input.w)*x[i][j][k] + (input.w*C/(6*C + 1)) * (up+down+right+left+back+front) + ((input.w/(6*C+1)) * xold[i][j][k]);
					}
				}
			}

			/*Check to see if below error value*/
			check = check_for_min(x, xnew, input);
			if (check == 1){
				break;
			}
		}
	
		double ***temp2 = xold;
		xold = x;
		x = temp2;
	}
}
