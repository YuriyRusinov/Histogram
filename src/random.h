#ifndef _Random_H
#define _Random_H

#include "src_config.h"

class _HIST_EXPORT_ RandomNumberGen
{
public:
    RandomNumberGen (unsigned long int s);
    virtual ~RandomNumberGen (void);

    virtual double gen (void) const = 0;

protected:
    gsl_rng * r;
};

#endif
