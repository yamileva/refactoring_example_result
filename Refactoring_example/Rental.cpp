#include "Rental.h"

double Rental::getCharge()
{
	return _movie.getCharge(_daysRented);
}

int Rental::getBonus()
{
	return _movie.getBonus(_daysRented);
}