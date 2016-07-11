#include <gsl/gsl_rng.h>
#include "uniform_random.h"

UniformRandomNumberGen :: UniformRandomNumberGen (double m, double sigma, unsigned long int s)
    : RandomNumberGen (s),
    math_exp (m),
    g_sigma (sigma)
{
}

UniformRandomNumberGen :: UniformRandomNumberGen (const UniformRandomNumberGen& UR)
    : RandomNumberGen (UR),
    math_exp (UR.math_exp),
    g_sigma (UR.g_sigma)
{
}

UniformRandomNumberGen& UniformRandomNumberGen :: operator= (const UniformRandomNumberGen& UR)
{
    RandomNumberGen::operator= (UR);
    math_exp = UR.math_exp;
    g_sigma = UR.g_sigma;
    return *this;
}

UniformRandomNumberGen :: ~UniformRandomNumberGen (void)
{
}

double UniformRandomNumberGen :: gen (void) const
{
    double xr = gsl_rng_uniform (r);
    double res = g_sigma *(xr+math_exp-0.5);
    return res;
}
