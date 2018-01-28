#include <iostream>
#include <cstdlib>
#include <ctime>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf_pow_int.h>
#include <gsl/gsl_sf_trig.h>

using namespace std;

double f(double x_0, double x_1, double x_2, double x_3, double x_4, double x_5, double x_6, double x_7) {
	double total = x_0 + x_1 + x_2 + x_3 + x_4 + x_5 + x_6 + x_7;
	double f = gsl_sf_sin(total);
	return f;
}

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

int main() {
	srand(time(NULL));
	double s = M_PI_4 / 2.0;
	double V = gsl_sf_pow_int(s, 8);
	int N = 100000;
	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		double randX_0 = fRand(0.0, s);
		double randX_1 = fRand(0.0, s);
		double randX_2 = fRand(0.0, s);
		double randX_3 = fRand(0.0, s);
		double randX_4 = fRand(0.0, s);
		double randX_5 = fRand(0.0, s);
		double randX_6 = fRand(0.0, s);
		double randX_7 = fRand(0.0, s);
		sum += f(randX_0, randX_1, randX_2, randX_3, randX_4, randX_5, randX_6, randX_7);
	}
	double result = sum / (double)N;
	result = V * result;
	result = gsl_sf_pow_int(10.0, 6) * result;
	cout << result << "\n";
	return 0;
}
