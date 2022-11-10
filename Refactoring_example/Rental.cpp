#include "Rental.h"

double Rental::getCharge()
{
	return _movie.getCharge(_daysRented);
}

int Rental::getBonus()
{
	// Начисление бонусных очков
	int bonusPoints = 1;

	// Бонус за двухдневный прокат новинки
	if ((this->getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
		this->getDaysRented() > 1)
		bonusPoints++;
	return bonusPoints;
}