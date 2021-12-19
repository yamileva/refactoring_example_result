#include "Customer.h"

string Customer::statement() {
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	string result = "Прокат " + getName() + "\n";

	for (auto& each : _rentals) {
		double thisAmount = 0;
		switch (each.getMovie().getPriceCode()) {
		case Movie::REGULAR:
			thisAmount += 2;

			if (each.getDaysRented() > 2)
				thisAmount += (each.getDaysRented() - 2) * 1.5;
			break;

		case Movie::NEW_RELEASE:
			thisAmount += each.getDaysRented() * 3;
			break;

		case Movie::CHILDREN:
			thisAmount += 1.5;
			if (each.getDaysRented() > 3)
				thisAmount += (each.getDaysRented() - 3) * 1.5;
			break;
		}

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