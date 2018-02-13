#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <gsl/gsl_math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_sf_pow_int.h>
#include <gsl/gsl_sf_trig.h>

using namespace std;
gsl_rng* rng = gsl_rng_alloc(gsl_rng_default);

double f(double x_0, double x_1, double x_2, double x_3, double x_4, double x_5, double x_6, double x_7) {
	double total = x_0 + x_1 + x_2 + x_3 + x_4 + x_5 + x_6 + x_7;
	double f = gsl_sf_sin(total);
	return f;
}

double fRand(double fMin, double fMax)
{
	double f = gsl_rng_uniform(rng);
	return fMin + f * (fMax - fMin);
}

void MonteCarlo(int N) {
	double s = M_PI_4 / 2.0;
	double V = gsl_sf_pow_int(s, 8);
	double sum = 0.0;
	double sumSquares = 0.0;
	for (int i = 0; i < N; i++) {
		double randX_0 = fRand(0.0, s);
		double randX_1 = fRand(0.0, s);
		double randX_2 = fRand(0.0, s);
		double randX_3 = fRand(0.0, s);
		double randX_4 = fRand(0.0, s);
		double randX_5 = fRand(0.0, s);
		double randX_6 = fRand(0.0, s);
		double randX_7 = fRand(0.0, s);
		double result = f(randX_0, randX_1, randX_2, randX_3, randX_4, randX_5, randX_6, randX_7);
		sum += result;
		sumSquares += gsl_sf_pow_int(result, 2);
	}
	double result = sum / (double)N;
	result = V * result;
	double error = sumSquares / (double)N;
	error = error - gsl_sf_pow_int(result, 2);
	error = error / (double)N;
	error = sqrt(error);
	error = V * error;
	result = gsl_sf_pow_int(10.0, 6) * result;
	error = gsl_sf_pow_int(10.0, 6) * error;
	cout << N << " " << result << " " << error << "\n";
}

int main() {
	// Seed the PRNG with the current time
	gsl_rng_set(rng, time(NULL));
	// Run Monte-Carlo simulations with i number of samples
	for (int i=1; i<1000; i++) {
		// Run each simulation 10 times to estimate error
		for (int n=0; n<10; n++) {
			MonteCarlo(i);
		}
	}
	return 0;
}
