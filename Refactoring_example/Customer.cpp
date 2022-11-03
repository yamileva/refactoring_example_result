#include "Customer.h"

string Customer::statement() {
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	string result = "Прокат " + getName() + "\n";

	for (auto& each : _rentals) {
		double thisAmount = each.getCharge();

		frequentRenterPoints += each.getBonus();

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



