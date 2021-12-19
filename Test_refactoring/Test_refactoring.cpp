#include "pch.h"
#include "CppUnitTest.h"
#include "../Refactoring_example/Customer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testrefactoring
{
	Movie movies[] = {
		{"Movie_1", 0}, {"Movie_2", 0}, {"Movie_3", 0}, {"Movie_4", 0},
		{"Movie_5", 1}, {"Movie_6", 1}, {"Movie_7", 1}, {"Movie_8", 1},
		{"Movie_9", 2}, {"Movie_10", 2}, {"Movie_11", 2}, {"Movie_12", 2},
	};
	Rental rentals[] = {
		{movies[0], 1}, {movies[1], 2}, {movies[2], 1}, {movies[3], 2},
		{movies[0], 1}, {movies[1], 2}, {movies[2], 3}, {movies[3], 4},
		{movies[4], 1}, {movies[5], 1}, {movies[6], 2}, {movies[7], 3},
		{movies[8], 1}, {movies[9], 2}, {movies[10], 1}, {movies[11], 3},
		{movies[8], 4}, {movies[9], 5}, {movies[10], 6}, {movies[11], 7}
	};

	TEST_CLASS(TestCustomer)
	{
	public:
		
		TEST_METHOD(all_reg_no_more_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			for (int i = 0; i < 4; i++) {
				customer.addRental(rentals[i]);
			}
			string expected = "Прокат Customer\n"
				"\tMovie_1\t2,000000\n"
				"\tMovie_2\t2,000000\n"
				"\tMovie_3\t2,000000\n"
				"\tMovie_4\t2,000000\n"
				"Сумма задолженности: 8,000000\n"
				"Вы заработали 4 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_all_reg_more_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			for (int i = 4; i < 8; i++) {
				customer.addRental(rentals[i]);
			}
			string expected = "Прокат Customer\n"
				"\tMovie_1\t2,000000\n"
				"\tMovie_2\t2,000000\n"
				"\tMovie_3\t3,500000\n"
				"\tMovie_4\t5,000000\n"
				"Сумма задолженности: 12,500000\n"
				"Вы заработали 4 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		
		TEST_METHOD(customer_all_new_less_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			for (int i = 8; i < 10; i++) {
				customer.addRental(rentals[i]);
			}
			string expected = "Прокат Customer\n"
				"\tMovie_5\t3,000000\n"
				"\tMovie_6\t3,000000\n"
				"Сумма задолженности: 6,000000\n"
				"Вы заработали 2 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_all_new_mixed)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			for (int i = 8; i < 12; i++) {
				customer.addRental(rentals[i]);
			}
			string expected = "Прокат Customer\n"
				"\tMovie_5\t3,000000\n"
				"\tMovie_6\t3,000000\n"
				"\tMovie_7\t6,000000\n"
				"\tMovie_8\t9,000000\n"
				"Сумма задолженности: 21,000000\n"
				"Вы заработали 6 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_all_children_no_more_3)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			for (int i = 12; i < 16; i++) {
				customer.addRental(rentals[i]);
			}
			string expected = "Прокат Customer\n"
				"\tMovie_9\t1,500000\n"
				"\tMovie_10\t1,500000\n"
				"\tMovie_11\t1,500000\n"
				"\tMovie_12\t1,500000\n"
				"Сумма задолженности: 6,000000\n"
				"Вы заработали 4 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_all_children_more_3)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			for (int i = 16; i < 20; i++) {
				customer.addRental(rentals[i]);
			}
			string expected = "Прокат Customer\n"
				"\tMovie_9\t3,000000\n"
				"\tMovie_10\t4,500000\n"
				"\tMovie_11\t6,000000\n"
				"\tMovie_12\t7,500000\n"
				"Сумма задолженности: 21,000000\n"
				"Вы заработали 4 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_reg_less_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[0]);
			string expected = "Прокат Customer\n"
				"\tMovie_1\t2,000000\n"
				"Сумма задолженности: 2,000000\n"
				"Вы заработали 1 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_reg_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[1]);
			string expected = "Прокат Customer\n"
				"\tMovie_2\t2,000000\n"
				"Сумма задолженности: 2,000000\n"
				"Вы заработали 1 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_reg_more_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[6]);
			string expected = "Прокат Customer\n"
				"\tMovie_3\t3,500000\n"
				"Сумма задолженности: 3,500000\n"
				"Вы заработали 1 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_new_less_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[8]);
			string expected = "Прокат Customer\n"
				"\tMovie_5\t3,000000\n"
				"Сумма задолженности: 3,000000\n"
				"Вы заработали 1 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_new_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[10]);
			string expected = "Прокат Customer\n"
				"\tMovie_7\t6,000000\n"
				"Сумма задолженности: 6,000000\n"
				"Вы заработали 2 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_new_more_2)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[11]);
			string expected = "Прокат Customer\n"
				"\tMovie_8\t9,000000\n"
				"Сумма задолженности: 9,000000\n"
				"Вы заработали 2 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_child_less_3)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[12]);
			string expected = "Прокат Customer\n"
				"\tMovie_9\t1,500000\n"
				"Сумма задолженности: 1,500000\n"
				"Вы заработали 1 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_child_3)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[15]);
			string expected = "Прокат Customer\n"
				"\tMovie_12\t1,500000\n"
				"Сумма задолженности: 1,500000\n"
				"Вы заработали 1 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(customer_single_child_more_3)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			customer.addRental(rentals[16]);
			string expected = "Прокат Customer\n"
				"\tMovie_9\t3,000000\n"
				"Сумма задолженности: 3,000000\n"
				"Вы заработали 1 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(custumer_empty)
		{
			setlocale(LC_ALL, "Russian");
			Customer customer = { "Customer" };
			string expected = "Прокат Customer\n"
				"Сумма задолженности: 0,000000\n"
				"Вы заработали 0 бонусных очков";
			string result = customer.statement();
			Assert::AreEqual(expected, result);
		}
	};
}
