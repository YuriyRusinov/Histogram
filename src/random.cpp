#include <gsl/gsl_rng.h>

#include "random.h"

RandomNumberGen :: RandomNumberGen (unsigned long int s)
    : r(gsl_rng_alloc(gsl_rng_default))
{
    gsl_rng_set (r, s);
}

RandomNumberGen :: RandomNumberGen (const RandomNumberGen& R)
{
    r = gsl_rng_clone (R.r);
}

RandomNumberGen& RandomNumberGen :: operator= (const RandomNumberGen& R)
{
    if (&R == this)
        return *this;

    if (r)
        gsl_rng_free (r);
    r = gsl_rng_alloc(gsl_rng_default);

    gsl_rng_memcpy (r, R.r);
    return *this;
}

RandomNumberGen :: ~RandomNumberGen (void)
{
    gsl_rng_free (r);
}
