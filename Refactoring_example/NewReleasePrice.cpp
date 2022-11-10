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

int NewReleasePrice::getBonus(int daysRented)
{
	// Начисление бонусных очков
	int bonusPoints = Price::getBonus(daysRented);

	// Бонус за двухдневный прокат новинки
	if (daysRented > 1)
		bonusPoints++;
	return bonusPoints;
}
