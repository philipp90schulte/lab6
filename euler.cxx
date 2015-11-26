#include <cmath>
#include <iostream>
#include <cstdlib>

// Define the needed functions
void calcanalytical();
void calceulerfor(double* const e, const int N, const double tstep, const double lambda);
void calceulerback();
void printresult();

// main function
int main() {
	// define needed variables
	const double lambda = -2;
	const int Nstep = 1000;
	const double tmax = 5 * (log(0.5) / lambda); // calc max t -> t_hl
	const double tstep = tmax / Nstep;
	double* e[Nstep+1][2];
	*e[0][0] = 0;
	*e[0][1] = 1;
	
	
}

void calcanalytical(double* const e, const int N, const double tstep, const double lambda) {
	for (int i = 1; i <= N; i++) {
		e[i][0] = i * tstep;
		e[i][1] = exp(lambda * e[i][0]);
	}
	
}

void calceulerfor(double* const e, const int N, const double tstep, const double lambda) {
	for (int i = 1; i <= N; i++) {
		e[i][1] = e[i-1][1] + tstep * lambda * e[i-1][1];
	}
	
}

void calceulerback() {
	
	
}

void printresult() {
	
	
}