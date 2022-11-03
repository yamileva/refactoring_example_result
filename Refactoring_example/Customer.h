#pragma once
#include <vector>
#include <string>
#include "Rental.h"
using namespace std;

class Customer
{
private:
	string _name;
	vector <Rental> _rentals;

public:
	Customer(string name) {
		_name = name;
	}
	void addRental(Rental arg) {
		_rentals.push_back(arg);
	}
	string getName() {
		return _name;
	}
	string statement();


};

