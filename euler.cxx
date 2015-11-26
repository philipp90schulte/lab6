#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

// Define the needed functions
void calcanalytical(double* e, const int N, const double tstep, const double lambda);
void calceulerfor(double* e, const int N, const double tstep, const double lambda);
void calceulerback(double* e, const int N, const double tstep, const double lambda);
void printresult(double* e, const int N, const string outputname, const double tstep);

// main function
int main() {
	// define needed variables
	const double lambda = -2;
	const int N = 1000; // Number of steps
	const double tmax = 5 * (log(0.5) / lambda); // calc max t -> t_hl
	const double tstep = tmax / N;
	double e[N+1];
	e[0] = 0.0;
	e[0] = 1.0;
	
	//perform the calculation
	calcanalytical(e, N, tstep, lambda);
	printresult(e, N, "analytical.txt", tstep);
	calceulerfor(e, N, tstep, lambda);
	printresult(e, N, "eulerfor.txt", tstep);
	calceulerback(e, N, tstep, lambda);
	printresult(e, N, "eulerback.txt", tstep);
	
	
	return 0;
}

void calcanalytical(double* e, const int N, const double tstep, const double lambda) {
	for (int i = 1; i <= N; i++) {
		e[i] = exp(lambda * i * tstep);
	}
	
}

void calceulerfor(double* e, const int N, const double tstep, const double lambda) {
	for (int i = 1; i <= N; i++) {
		e[i] = e[i-1] + tstep * lambda * e[i-1];
	}
	
}

void calceulerback(double* e, const int N, const double tstep, const double lambda) {
	// backward euler is defined as y_i+1 = f(x_i+1, y_i+1)* deltax + y_i
	// that is equal to y_i+1 = lambda * y_i+1 * deltax + y_i
	// y_i = y_i+1 * (1 - deltax * lambda) => y_i+1 = y_i / (1 - deltax * lambda)
	for (int i = 1; i <= N; i++) {
		e[i] =e[i-1] / (1 - tstep * lambda);
	}	
}

void printresult(double* e, const int N, const string outputname, const double tstep) {
	ofstream out(outputname.c_str());
	double t;
	for (int i = 0; i <= N; i++) {
		t = i * tstep;
		out << t << "\t" << e[i] << endl;
	}
	
	out.close();
}