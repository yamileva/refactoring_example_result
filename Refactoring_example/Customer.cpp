#include "Customer.h"

string Customer::statement() {
	string result = "������ " + getName() + "\n";

	for (auto& each : _rentals) {
		// ����� ����������� ��� ������� �������
		result += "\t" + each.getMovie().getTitle() + "\t" +
			to_string(each.getCharge()) + "\n";
	}
	// ���������� �����������
	result += "����� �������������: " +
		to_string(getTotalCharge()) + "\n";
	result += "�� ���������� " + to_string(getTotalBonus()) +
		" �������� �����";
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

