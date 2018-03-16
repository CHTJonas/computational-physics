#include <iostream>
#include <limits>
#include <math.h>
#include <gsl/gsl_sf_trig.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_pow_int.h>

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

void optics(int steps, double wavelength, double slitWidth, double seperationDistance) {
	double scalingFactor = sqrt(2.0 / wavelength / seperationDistance);
	double x = -slitWidth / 2.0;
	double w1 = 0.0;
	double w2 = slitWidth * scalingFactor;
	double step = w2 / (double)steps;
	while (x <= slitWidth / 2.0) {
		double real = integrate(w2, &C) - integrate(w1, &C);
		double imag = integrate(w2, &S) - integrate(w1, &S);
		double result = sqrt( gsl_sf_pow_int(real, 2) + gsl_sf_pow_int(imag, 2) );
		cout << x << " " << result << "\n";
		w1 -= step;
		w2 -= step;
		x += slitWidth / (double)steps;
	}
}

int main (int argc, char* argv[]) {
	if (argc != 2) {
		cerr << "Distance to screen not given, or too many arguments" << "\n";
		return 1;
	}
	int steps = 1000;
	double wavelength = 0.01;
	double slitWidth = 0.1;
	double seperationDistance = atof(argv[1]);
	optics(steps, wavelength, slitWidth, seperationDistance);
	return 0;
}
