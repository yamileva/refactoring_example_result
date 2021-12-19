#pragma once
#include <string>
using namespace std;


class Movie
{
public:
	static const int CHILDREN = 2;
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;
private:
	string _title;
	int _priceCode;

public:
	Movie() {
		_title = "";
		_priceCode = 0;
	}

	Movie(string title, int priceCode){
		_title = title;
		_priceCode = priceCode;
	}

	int getPriceCode() {
		return _priceCode;
	}

	void setPriceCode(int arg) {
		_priceCode = arg;
	}

	string getTitle() {
		return _title;
	}
};

