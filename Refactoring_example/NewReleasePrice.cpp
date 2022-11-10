#include "NewReleasePrice.h"
#include "Movie.h"

int NewReleasePrice::getPriceCode()
{
    return Movie::NEW_RELEASE;
}
double NewReleasePrice::getCharge(int daysRented)
{
	double result = 0;
	
	result += daysRented * 3;
	
	return result;
}
