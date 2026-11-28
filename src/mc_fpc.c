#include "mc_fpc.h"
#include <math.h>
#include "utils.h"

state next_simulation(state in, double G, config c){
	state out = {.price=0, .I=in.I};
	double T_diff = c.T / (c.M + 1);
	out.price = in.price * exp(
			(c.r - c.volatility * c.volatility / 2)
			* T_diff
			+ c.volatility * sqrt(T_diff) * G
				
	);
	if(out.price < c.B) out.I++;
	return out;
}

double payoff(state s, config c) {
	double res = 0.0;
	if(c.P1 <= s.I && s.I <= c.P2) res = fmax((s.price - c.K), 0.0);
	return res;
}

double simulate_price(int index, state state_init, long int npaths, config c){
	double t_init = (double) index * c.T / (c.M + 1);
	int nsim = (c.M + 1) - index;
	double G = 0.0;
	state cur_state = {0};
	double avgpayoff = 0.0;
	double fair_price = 0.0;
	for(long int i = 0; i < npaths; i++) {
		cur_state = state_init;
		for(int j = 0; j < nsim; j++) {
			G = randn(0, 1);
			cur_state = next_simulation(cur_state, G, c);
		}
		avgpayoff += payoff(cur_state, c);
	}
	avgpayoff /= npaths;
	fair_price = exp(-c.r * (c.T - t_init)) * avgpayoff;
	return fair_price;
}
