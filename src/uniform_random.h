#ifndef _UNIFORM_Random_H
#define _UNIFORM_Random_H

#include "src_config.h"
#include "random.h"

class _HIST_EXPORT_ UniformRandomNumberGen : public RandomNumberGen
{
public:
    UniformRandomNumberGen (unsigned long int s);
    virtual ~UniformRandomNumberGen (void);

    virtual double gen (void) const;
};

#endif
