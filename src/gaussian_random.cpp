#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include "gaussian_random.h"

GaussianRandomNumberGen :: GaussianRandomNumberGen (double sigma, unsigned long int s)
    : RandomNumberGen (s), g_sigma (sigma)
{
}

GaussianRandomNumberGen :: ~GaussianRandomNumberGen (void)
{
}

double GaussianRandomNumberGen :: gen (void) const
{
    double res = gsl_ran_gaussian (r, g_sigma);
    return res;
}
