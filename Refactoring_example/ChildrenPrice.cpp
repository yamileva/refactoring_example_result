#include "ChildrenPrice.h"
#include "Movie.h"

int ChildrenPrice::getPriceCode()
{
    return Movie::CHILDREN;
}

double ChildrenPrice::getCharge(int daysRented)
{
	double Result = 0;
	
	Result += 1.5;
	if (daysRented > 3)
		Result += (daysRented - 3) * 1.5;
	
	return Result;
}