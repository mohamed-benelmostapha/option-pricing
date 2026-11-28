#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

typedef struct config {
	double volatility;
	double r;
	double T;
	double K;
	double B;
	int P1;
	int P2;
	int M;
} config;

double calculate_fair_price_from_mean(double t, double mean, config c);

double calculate_fair_price_from_u(double u_val, double t, config c);

#endif
