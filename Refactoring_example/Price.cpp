#include "Price.h"
#include "Movie.h"


int Price::getBonus(int daysRented)
{
	// ���������� �������� �����
	int bonusPoints = 1;

	// ����� �� ����������� ������ �������
	if ((getPriceCode() == Movie::NEW_RELEASE) &&
		daysRented > 1)
		bonusPoints++;
	return bonusPoints;
}