#include <vector>
#include <iostream>
#include <cmath>
#include <gsl/gsl_math.h>
#include <fftw3.h>

using namespace std;

void transform(vector<double> &inp, vector<double> &out) {
	fftw_complex *finp = (fftw_complex *) &inp[0];
	fftw_complex *fout = (fftw_complex *) &out[0];
	fftw_plan plan = fftw_plan_dft_1d(inp.size() / 2, finp, fout, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(plan);
	fftw_destroy_plan(plan);
}

int main() {
	const int n = 512;
	double delta = 0.000005;
	double wavelength = 500 * pow(10, -9);
	double slitWidth = 100.0 * pow(10, -6);
	double screenDistance = 1.0;
	vector<double> inp(2 * n, 0);
	vector<double> out(2 * n, 0);

	// Generate the aperture function
	for (int i = 0; i < n; i++) {
		inp[2 * i] = 0;
		inp[2 * i + 1] = 0;
		if (i <= slitWidth / delta) {
			inp[2 * i] = 1;
		}
	}

	// Do the FFT now:
	transform(inp, out);

	//	https://en.wikipedia.org/wiki/Fraunhofer_diffraction_equation#Slit_of_infinite_depth
	//	y = f * wavelength * screenDistance / pi / slitWidth

	// Display negatives first
	for (int i = n / 2; i < n; i++) {
		double f = ((double)i / (double)n - 1.0) / delta;
		double intensity = pow(out[2 * i], 2);
		// Scale correctly
		f = f * wavelength * screenDistance / M_PI / slitWidth;
		f = f * 2.0 * M_PI / 100.0; // don't know why this is necessary...
		cout << f << " " << intensity << "\n";
	}

	// Then do positive frequencies
	for (int i = 0; i < n / 2; i++) {
		double f = ((double)i / (double)n) / delta;
		double intensity = pow(out[2 * i], 2);
		// Scale correctly
		f = f * wavelength * screenDistance / M_PI / slitWidth;
		f = f * 2.0 * M_PI / 100.0; // don't know why this is necessary...
		cout << f << " " << intensity << "\n";
	}

	return 0;
}
