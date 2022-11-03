#include "Customer.h"

string Customer::statement() {
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	string result = "Прокат " + getName() + "\n";

	for (auto& each : _rentals) {
		double thisAmount = amountFor(each);

		// Начисление бонусных очков
		frequentRenterPoints++;

		// Бонус за двухдневный прокат новинки
		if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
			each.getDaysRented() > 1)
			frequentRenterPoints++;

		// Вывод результатов для каждого проката
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(thisAmount) + "\n";
		totalAmount += thisAmount;
	}

	// Добавление колонтитула
	result += "Сумма задолженности: " +
		to_string(totalAmount) + "\n";
	result += "Вы заработали " + to_string(frequentRenterPoints) +
		" бонусных очков";
	return result;
}

double Customer::amountFor(Rental aRental)
{
	double result = 0;
	switch (aRental.getMovie().getPriceCode()) {
	case Movie::REGULAR:
		result += 2;

		if (aRental.getDaysRented() > 2)
			result += (aRental.getDaysRented() - 2) * 1.5;
		break;

	case Movie::NEW_RELEASE:
		result += aRental.getDaysRented() * 3;
		break;

	case Movie::CHILDREN:
		result += 1.5;
		if (aRental.getDaysRented() > 3)
			result += (aRental.getDaysRented() - 3) * 1.5;
		break;
	}
	return result;
}
