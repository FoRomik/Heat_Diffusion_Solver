#include "header.h"

int main(){
	
	/*
	 dc = diffusivity constant (Alpha)
	 bc = boundary condition -> 0 = Zero value, 1 = You choose the constant value, 2 => periodic
	 bcVal = Your chosen boundary value
	 */


	double x, y, z, dt, dc, std, bcVal, time_taken, t;
	int bc, totalSteps;
	srand(time(NULL));
	
	printf("Enter X, Y, and Z Dimensions(No commas, just spaces between values):\n");
	scanf("%lf %lf %lf", &x, &y, &z);
	printf("Enter your Alpha Value\n");
	scanf("%lf", &dc);
	printf("Enter your total Timesteps to take:\n");
	scanf("%d", &totalSteps);
	printf("Enter your time per timestep:\n");
	scanf("%lf", &dt);
	if (((dc * dt)/((.01*.01))) > (1/6)){
		printf("WARNING: Your C value is greater than 1/6, this could cause strange values with your FTCS.\n");
	}

	printf("Now, Boundary Conditions...Enter 0 for a 0 Boundary Value, Enter 1 to set your own Value, Enter 2 for Periodic\n");
	scanf("%d", &bc);
	if (bc == 1){
		printf("Please Enter your Boundary Value:\n");
		scanf("%lf", &bcVal); 
	}
	else {
		bcVal = 0;
	}

	/*
	totalSteps = 10000;	
	std = .001;
	x = 3;
	y = 3; 
	z = 3; 
	dt = .01;
	dc = .01;
	bcVal = 100;
	bc = 2;
	*/

	std = .001;
	double *b = (double*)malloc(sizeof(double)*x*y*z);
	double *** mat = init(x, y, z); 
	
	double *** new = init(x, y, z);	

	gaussNoise(mat, x, y, z, dt, std);	
	
	cn(mat, b, x, y, z, dt, dc, bc, bcVal, totalSteps);

	t = clock();
	ftcs(mat, new, x, y, z, dt, dc, bc, bcVal, totalSteps);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("FTCS of Dimensions(%.1f, %.1f, %.1f) took %.5f seconds\n", x, y, z, time_taken);
	
	return 0;
}

