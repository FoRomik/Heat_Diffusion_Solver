#include "header.h"

void jacobi(double *** xold, Input input){

	int i, j, k, m, n;
	int check;
	
	double up, down, left, right, front, back, C;
	double *** xnew = init(input.x, input.y, input.z);
	double *** x = init(input.x, input.y, input.z);
	memcpy(x, xold, input.x*input.y*input.z*sizeof(double));
	C = ((input.alpha*input.dt)/pow(input.dx, 2));

	/*Total Number of steps loop*/
	for (n = 0; n < input.nSteps; n++){
		double *** temp = x;
		memcpy(x, xold, input.x*input.y*input.z*sizeof(double));
		memcpy(xold, temp, input.x*input.y*input.z*sizeof(double));

		/*For each step, run however many Iterations chosen*/
		for (m = 0; m < input.maxIter; m++){

			/*Now run through each value*/
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
						/*Jacobi equation*/
						xnew[i][j][k] = (((1.0/(6.0*C + 1.0))*(xold[i][j][k]))+(((C)/(6.0*C + 1.0))*(up + down + right + left + back + front)));	
						
					}
				}
			}
			
			double ***temp2 = xnew;
			xnew = x;
			x = temp2;	
	
			/*Check if below error value*/
			check = check_for_min(x, xnew, input);
			if (check == 1){
				break;				
			}
		}
		
		double ***temp3 = xold;
		xold = x;
		x = temp3;
		}	
}

/*Check to see if value is below the 1.0e-6 value*/
int check_for_min(double *** temp, double *** mat, Input input){
	int i, j, k, count;
	double runSum, mean;
	count = runSum = 0;
	for (i = 0; i < input.x; i++){
		for (j = 0; j < input.y; j++){
			for (k = 0; k < input.z; k++){
				runSum = runSum + fabs(temp[i][j][k] - mat[i][j][k]);
				count++;
			}
		}
	}	
	mean = ((runSum)/(count));
	if (mean < 1.0e-6){
		return 1;
	}
	return 0;
}
