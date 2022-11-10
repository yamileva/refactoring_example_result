#pragma once
#include "Price.h"
class NewReleasePrice :
    public Price
{
public:
    // Inherited via Price
    virtual int getPriceCode() override;
};

