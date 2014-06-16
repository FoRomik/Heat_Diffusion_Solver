
#define NPRE  1
#define NPOST 1
#define NGMAX 15

void addint(double **uf, double **uc, double **res, int nf);
void mglin(double **u, int n, int ncycle, double C);
void copy(double **aout, double **ain, int n);
void fill0(double **u, int n);
void interp(double **uf, double **uc, int nf);
void relax(double **u, double **rhs, int n, double C);
void resid(double **res, double **u, double **rhs, int n, double C);
void rstrct(double **uc, double **uf, int nc, double C);
void slvsml(double **u, double **rhs, double C);
void cg(double ** A, double *b, int n);
double source(int n);
void clearVector(double * v, int n);
void copyVector(double * aout, double *ain, int n);
