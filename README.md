Heat_Diffusion_Solver
=====================

3D Heat Diffusion Solver using various discretizing equations/Iterative methods

Diffusion_Solver_Discretize:

  3D Heat Diffusion Solver using FTCS(Forward-Time-Central-Space) and CN(Crank-Nicolson).
  
  Used a Gaussian Distribution to demonstrate diffusion over time given user input parameters.
    - Boundary Conditions include Dirichlet (constant boundary value) and Periodic (wrap-around)
  
Iterative_Solvers:

  Incorporated Iterative solvers for the Crank Nicholson scheme for 3D heat equation.
  
  Iterative methods include: Jacobi, Gauss-Seidel, and Successive-over-relaxation
  
  Timers included in the main to demonstrate total runtime performance given problem size.
  
  Also added a FTCS stability analysis for discretized 2D and 3D heat equation
  
MultiGrid_CG_Solvers:

  Final stage of this project: Modifying the MultiGrid Solver provided in Numerical Recipes to incorporate source term
  and Backward Euler discretization.
  
  Built a un-preconditioned CG (Conjugate Gradient) Solver for the same problem. Peformed run-time analysis of the CG solver

