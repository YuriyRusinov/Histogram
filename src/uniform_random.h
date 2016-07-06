#ifndef _UNIFORM_Random_H
#define _UNIFORM_Random_H

#include "src_config.h"
#include "random.h"

class _HIST_EXPORT_ UniformRandomNumberGen : public RandomNumberGen
{
public:
    UniformRandomNumberGen (double m, double sigma, unsigned long int s=0);
    UniformRandomNumberGen (const UniformRandomNumberGen& UR);
    UniformRandomNumberGen& operator= (const UniformRandomNumberGen& UR);
    virtual ~UniformRandomNumberGen (void);

    virtual double gen (void) const;
private:
    //
    // Variables
    //
    double math_exp;
    double g_sigma;
};

#endif
