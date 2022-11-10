#include "Price.h"
#include "Movie.h"


int Price::getBonus(int daysRented)
{
	// Начисление бонусных очков
	int bonusPoints = 1;

	// Бонус за двухдневный прокат новинки
	if ((getPriceCode() == Movie::NEW_RELEASE) &&
		daysRented > 1)
		bonusPoints++;
	return bonusPoints;
}