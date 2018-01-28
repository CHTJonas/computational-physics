#include <iostream>
#include <limits>
#include <gsl/gsl_sf_trig.h>
#include <gsl/gsl_integration.h>

using namespace std;

double C (double x, void* params) {
	double alpha = *(double*) params;
	double f = gsl_sf_cos(alpha * x * x);
	return f;
}

double S (double x, void* params) {
	double alpha = *(double*) params;
	double f = gsl_sf_sin(alpha * x * x);
	return f;
}

double integrate (double u, double (*f)(double, void*)) {
	// Allocate some memory for the integration
	gsl_integration_cquad_workspace *workspace = gsl_integration_cquad_workspace_alloc(1000);
	double result;
	double error;
	size_t evaluations;
	double alpha = M_PI_2;

	// The function to integrate
	gsl_function Funct;
	Funct.function = f;
	Funct.params = &alpha;

	// Do the integration
	gsl_integration_cquad(&Funct, 0, u, 0, 1e-7, workspace, &result, &error, &evaluations);

	// Tidy up objects
	gsl_integration_cquad_workspace_free(workspace);
	return result;
}

int main () {
	double step = 0.0005;
	double min = -7.0;
	double max = 7.0;
	for (double t = min; t < max; t += step) {
		cout << integrate(t, &C);
		cout << " ";
		cout << integrate(t, &S);
		cout << "\n";
	}
	return 0;
}
