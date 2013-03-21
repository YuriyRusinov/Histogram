#ifndef _Random_H
#define _Random_H

#include "src_config.h"

//class gsl_rng;

class _HIST_EXPORT_ RandomNumberGen
{
public:
    RandomNumberGen (unsigned long int s);
    virtual ~RandomNumberGen (void);

    virtual double gen (void) const = 0;
private:
    gsl_rng * r;
};

#endif
