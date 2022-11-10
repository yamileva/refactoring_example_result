#include "Rental.h"

double Rental::getCharge()
{
	return _movie.getCharge(_daysRented);
}

int Rental::getBonus()
{
	// ���������� �������� �����
	int bonusPoints = 1;

	// ����� �� ����������� ������ �������
	if ((this->getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
		this->getDaysRented() > 1)
		bonusPoints++;
	return bonusPoints;
}