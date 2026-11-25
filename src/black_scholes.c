#include "../include/black_scholes.h"
#include <math.h>

double calculate_fair_price_from_mean(double t, double mean) {
        return exp(
                        risk_free_rate_globalvar *
                        (contract_maturity - t)
                  ) *
                mean; // calculates F(t, x, j) where j is taken into account in the mean
}

double calculate_fair_price_from_u(double u_val, double t) {
        return exp(
                        -(
                          risk_free_rate_globalvar *
                          (contract_maturity - t)
                         )
                  ) * u_val; // gives you F(t, e^x, j) for u(t, x, j)
}
