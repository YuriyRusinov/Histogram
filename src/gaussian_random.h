#ifndef _Gaussian_Random_H
#define _Gaussian_Random_H

#include "src_config.h"
#include "random.h"

class _HIST_EXPORT_ GaussianRandomNumberGen : public RandomNumberGen
{
public:
    GaussianRandomNumberGen (double sigma, unsigned long int s);
    virtual ~GaussianRandomNumberGen (void);

    virtual double gen (void) const;
private:
    double g_sigma;
};

#endif
