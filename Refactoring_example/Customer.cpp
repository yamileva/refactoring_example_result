#include "Customer.h"

string Customer::statement() {
	string result = "Прокат " + getName() + "\n";

	for (auto& each : _rentals) {
		// Вывод результатов для каждого проката
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
	}
	// Добавление колонтитула
	result += "Сумма задолженности: " +
		to_string(getTotalCharge()) + "\n";
	result += "Вы заработали " + to_string(getTotalBonus()) +
		" бонусных очков";
	return result;
}

double Customer::getTotalCharge()
{
	double totalAmount = 0;
	for (auto& each : _rentals) {
		double thisAmount = each.getCharge();
		totalAmount += thisAmount;
	}
	return totalAmount;
}

int Customer::getTotalBonus() {
	int points = 0;
	for (auto& each : _rentals) {
		points += each.getBonus();
	}
	return points;
}

