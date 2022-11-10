#include "RegularPrice.h"
#include "Movie.h"

int RegularPrice::getPriceCode()
{
    return Movie::REGULAR;
}

double RegularPrice::getCharge(int daysRented)
{
	double result = 0;
	result += 2;
		if (daysRented > 2)
		result += (daysRented - 2) * 1.5;
			
	return result;
}