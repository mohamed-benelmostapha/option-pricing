#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

double volatility_globalvar = 0.2;
double risk_free_rate_globalvar = 0.1;
// the time at which the owner of the contract can buy the stock
double contract_maturity = 1;
// price for which the owner of the contract can buy the stock at maturity
double contract_strike = 100;
int B = 110;
int P1 = 10, P2 = 40;

double calculate_fair_price_from_mean(double t, double mean);

double calculate_fair_price_from_u(double u_val, double t);

#endif
