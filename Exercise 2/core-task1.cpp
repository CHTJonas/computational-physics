// GSL solution to the ODE for a driven pendulum
// d^2 theta/dt^2 = - (g/l) * sin(theta) - q * d theta/dt + F * sin(omega_D * t)
#include <iostream>
#include <fstream>
#include <cmath>
#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv.h>

using namespace std;

// Evaluate the derivatives
// We work in the transformed variables
// y[0] = theta
// y[1] = d(theta)/dt
int calc_derivatives(double t, const double y[], double dydx[], void *params) {
	// Extract the parameters
	// params is a pointer to an array of doubles
	double q = *((double *)(params) + 0);
	double F = *((double *)(params) + 1);
	// g=l
	double omega_D = 2/3;
	dydx[0] = y[1];
	dydx[1] = - sin(y[0]) - q * y[1] + F * sin(omega_D * t);
	return GSL_SUCCESS;
}

double calc_energy(double theta, double thetaDot) {
	double m = 1.0;
	double g = 9.8;
	double l = 9.8;
	double ke = m * pow(l, 2) * pow(thetaDot, 2) / 2;
	double pe = m * g * l * (1 - cos(theta));
	double energy = ke + pe;
	return energy;
}

int main() {
	// Initial conditions:
	double params[2] = {0.0, 0.0};
	const int n_equations = 2;
	const double initialAmplitude = M_PI_2;
	double y[n_equations] = {initialAmplitude, 0.0};
	double t = 0.0;
	// Create a stepping function
	gsl_odeiv_step *gsl_step = gsl_odeiv_step_alloc(gsl_odeiv_step_rk4, n_equations);
	// Adaptive step control: let's use fixed steps here:
	gsl_odeiv_control *gsl_control = NULL;
	// Create an evolution function:
	gsl_odeiv_evolve *gsl_evolve = gsl_odeiv_evolve_alloc(n_equations);
	// Set up the system needed by GSL
	// The 4th arg is a pointer to any parameters needed by the evaluator
	// The 2nd arg points to the jacobian function if needed (it's not needed here)
	gsl_odeiv_system gsl_sys = {calc_derivatives, NULL, n_equations, params};
	double max_oscillations = 10000;
	double t_max = 2 * M_PI * max_oscillations;
	double h = 1e-3;

	// Main loop: advance solution until t_max reached.
	int n = 0;
	bool goneNegative = false;
	double period;
	while (t < t_max) {
		if (++n == 10000) {
			cout << t << " " << y[0] << " " << y[1] << " " << calc_energy(y[0], y[1]) << "\n";
			n = 0;
		}
		int status = gsl_odeiv_evolve_apply(gsl_evolve, gsl_control, gsl_step, &gsl_sys, &t, t_max, &h, y);
		// Calculate period
		if (y[0] <= 0) {
			if (goneNegative == false) {
				period = t * 4.0;
			}
			goneNegative = true;
		}
		if (status != GSL_SUCCESS) break;
	}
	ofstream datfile;
	datfile.open ("core-task1-periods.dat", ios::app);
	datfile << initialAmplitude << " " << period << "\n";
	datfile.close();
	// Tidy up the GSL objects for neatness:
	gsl_odeiv_evolve_free(gsl_evolve);
	gsl_odeiv_step_free(gsl_step);
	return 0;
}
