#ifndef _Exponential_Random_H
#define _Exponential_Random_H

#include "src_config.h"
#include "random.h"

class _HIST_EXPORT_ ExponentialRandomNumberGen : public RandomNumberGen
{
public:
    ExponentialRandomNumberGen (double mat_exp, unsigned long int s=0);
    ExponentialRandomNumberGen (const ExponentialRandomNumberGen& ER);
    ExponentialRandomNumberGen& operator= (const ExponentialRandomNumberGen& ER);
    virtual ~ExponentialRandomNumberGen (void);

    virtual double gen (void) const;
private:
    //
    // Variables
    //
    double mathematical_expectation;
};

#endif
