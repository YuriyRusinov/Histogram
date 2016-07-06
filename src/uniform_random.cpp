#include <gsl/gsl_rng.h>
#include "uniform_random.h"

UniformRandomNumberGen :: UniformRandomNumberGen (unsigned long int s)
    : RandomNumberGen (s)
{
}

UniformRandomNumberGen :: UniformRandomNumberGen (const UniformRandomNumberGen& UR)
    : RandomNumberGen (UR)
{
}

UniformRandomNumberGen :: ~UniformRandomNumberGen (void)
{
}

double UniformRandomNumberGen :: gen (void) const
{
    double res = gsl_rng_uniform (r);
    return res;
}
