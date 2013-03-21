#include <gsl/gsl_rng.h>

#include "random.h"

RandomNumberGen :: RandomNumberGen (unsigned long int s)
    : r(gsl_rng_alloc(gsl_rng_default))
{
    gsl_rng_set (r, s);
}

RandomNumberGen :: ~RandomNumberGen (void)
{
    gsl_rng_free (r);
}
