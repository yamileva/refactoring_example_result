#include "Movie.h"

Movie::Movie() {
	_title = "";
	setPriceCode(0);
}

Movie::Movie(string title, int priceCode) {
	_title = title;
	setPriceCode(priceCode);
}

int Movie::getPriceCode() {
	return _price->getPriceCode();
}

void Movie::setPriceCode(int priceCode) {
	switch (priceCode)
	{
	case REGULAR:
		_price = new RegularPrice();
		break;
	case CHILDREN:
		_price = new ChildrenPrice();
		break;
	case NEW_RELEASE:
		_price = new NewReleasePrice();
		break;
	default:
		throw invalid_argument("Incorrect price code");
	}
}

string Movie::getTitle() {
	return _title;
}

double Movie::getCharge(int daysRented) {
	return _price->getCharge(daysRented);
}

int Movie::getBonus(int daysRented){
	return _price->getBonus(daysRented);
}
