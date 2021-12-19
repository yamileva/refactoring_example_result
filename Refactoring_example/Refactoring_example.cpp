#include <iostream>
#include "Customer.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Movie movies[] = {
		{"Movie_1", 0}, {"Movie_2", 0}, {"Movie_3", 0}, {"Movie_4", 0},
		{"Movie_5", 1}, {"Movie_6", 1}, {"Movie_7", 1}, {"Movie_8", 1},
		{"Movie_9", 2}, {"Movie_10", 2}, {"Movie_11", 2}, {"Movie_12", 2},
	};
	Rental rentals[] = {
		{movies[0], 1}, {movies[1], 2}, {movies[2], 1}, {movies[3], 2},
		{movies[0], 1}, {movies[1], 2}, {movies[2], 3}, {movies[3], 4},
		{movies[4], 1}, {movies[5], 1}, {movies[6], 2}, {movies[7], 3},
		{movies[8], 1}, {movies[9], 2}, {movies[10], 3}, {movies[11], 3},
		{movies[8], 4}, {movies[9], 5}, {movies[10], 6}, {movies[11], 7}
	};
	Customer customer = { "Customer" };
	string expected = "Прокат Customer\n"
		"\tMovie_1 2,000000\n"
		"\tMovie_2 2,000000\n"
		"\tMovie_3 3,500000\n"
		"\tMovie_4 5,000000\n"
		"Сумма задолженности: 12,500000\n"
		"Вы заработали 4 бонусных очков";
	string result = customer.statement();
	cout << expected << endl << endl << result;
}

