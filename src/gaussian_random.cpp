#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include "gaussian_random.h"

GaussianRandomNumberGen :: GaussianRandomNumberGen (double m, double sigma, unsigned long int s)
    : RandomNumberGen (s), math_exp (m), g_sigma (sigma)
{
}

GaussianRandomNumberGen :: GaussianRandomNumberGen (const GaussianRandomNumberGen& GR)
    : RandomNumberGen (GR), math_exp (GR.math_exp), g_sigma (GR.g_sigma)
{
}

GaussianRandomNumberGen& GaussianRandomNumberGen :: operator= (const GaussianRandomNumberGen& GR)
{
    RandomNumberGen::operator= (GR);
    math_exp = GR.math_exp;
    g_sigma = GR.g_sigma;
    return *this;
}

GaussianRandomNumberGen :: ~GaussianRandomNumberGen (void)
{
}

double GaussianRandomNumberGen :: gen (void) const
{
    double res = math_exp+gsl_ran_gaussian (r, g_sigma);
    return res;
}
