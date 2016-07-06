#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include "exponential_random.h"

ExponentialRandomNumberGen :: ExponentialRandomNumberGen (double mat_exp, unsigned long int s)
    : RandomNumberGen (s),
    mathematical_expectation (mat_exp)
{
}

ExponentialRandomNumberGen :: ExponentialRandomNumberGen (const ExponentialRandomNumberGen& ER)
    : RandomNumberGen (ER),
    mathematical_expectation (ER.mathematical_expectation)
{
}

ExponentialRandomNumberGen& ExponentialRandomNumberGen :: operator= (const ExponentialRandomNumberGen& ER)
{
    RandomNumberGen::operator= (ER);
    mathematical_expectation = ER.mathematical_expectation;
    return *this;
}

ExponentialRandomNumberGen ::  ~ExponentialRandomNumberGen (void)
{
}

double ExponentialRandomNumberGen :: gen (void) const
{
    double res = gsl_ran_exponential (r, mathematical_expectation);
    return res;
}
