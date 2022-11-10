#pragma once
#include <string>
#include <stdexcept>
#include "Price.h"
#include "RegularPrice.h"
#include "NewReleasePrice.h"
#include "ChildrenPrice.h"

using namespace std;


class Movie
{
public:
	static const int CHILDREN = 2;
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;
private:
	string _title;
	//int _priceCode;
	Price *_price;

public:
	Movie();
	Movie(string title, int priceCode);

	int getPriceCode();
	void setPriceCode(int arg);

	string getTitle();
	double getCharge(int daysRented);
	int getBonus(int daysRented);
};

