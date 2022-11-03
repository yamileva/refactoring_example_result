#include "Rental.h"

double Rental::getCharge()
{
	double result = 0;
	switch (this->getMovie().getPriceCode()) {
	case Movie::REGULAR:
		result += 2;

		if (this->getDaysRented() > 2)
			result += (this->getDaysRented() - 2) * 1.5;
		break;

	case Movie::NEW_RELEASE:
		result += this->getDaysRented() * 3;
		break;

	case Movie::CHILDREN:
		result += 1.5;
		if (this->getDaysRented() > 3)
			result += (this->getDaysRented() - 3) * 1.5;
		break;
	}
	return result;
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