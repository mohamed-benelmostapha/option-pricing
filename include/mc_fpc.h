#ifndef MONTE_CARLO_FAIR_PRICE_CALCULATOR_H
#define MONTE_CARLO_FAIR_PRICE_CALCULATOR_H
#include "black_scholes.h"

typedef struct state {
	double price;
	int I;
} state;

state next_simulation(state in, double G, config c);

double payoff(state s, config c);

double simulate_price(int index_init, state state_init, long int npaths, config c);

#endif
