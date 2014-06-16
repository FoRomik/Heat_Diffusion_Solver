#include "header.h"

int main (){
	
	double t1, t2, t3, time_taken1, time_taken2, time_taken3;
	Input input;
	/*Update input values to whatever you want to run simulation*/
	input.x = 10;
	input.y = 10;
	input.z = 10;
	input.nSteps = 1000;
	input.alpha = .01;
	input.dt = .005;
	input.dx = .01;
	input.dtemp = 0;
	input.maxIter = 30;
	input.w = 1.70;
	/*End of user Input*/
	
	srand(time(NULL));

	double *** matrix = init(input.x, input.y, input.z);	
	
	/*Run Gaussian distribution+noise on matrix*/
	gaussNoise(matrix, input.x, input.y, input.z);

	/*Now time the 3 methods implemented*/	
	t1 = clock();
	jacobi(matrix, input);
	t1 = clock() - t1;
	time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
	
	t2 = clock();
	gs(matrix, input);
	t2 = clock() - t2;
	time_taken2 = ((double)t2)/CLOCKS_PER_SEC;

	t3 = clock();
	sor(matrix, input);
	t3 = clock() - t3;
	time_taken3 = ((double)t3)/CLOCKS_PER_SEC;

	printf("-------------------------\n");
	printf("JACOBI:\t %lf  \n", time_taken1);
	printf("GAUSS-SEIDEL:\t%lf \n", time_taken2);
	printf("SOR:\t%lf \n", time_taken3);
	
	return 0;
}
