
//вивести у окремий файл 5 найбільших оплат за воду
//перенести введення і виведення у файл
#include <iostream>
#include <deque>
#include <fstream>
#include <algorithm>

using namespace std;
struct GasBill
{
	string surname;
	int quantity;
	double sum;
	bool operator<(const GasBill& b)
	{
		return quantity > b.quantity;
	}
};

struct WaterBill
{
	string surname;
	double V;
	double sum;
	int pokazy;
	bool operator<(const WaterBill& b)
	{
		return surname < b.surname;
	}/*
	bool operator>(const WaterBill& b)
	{
		return sum > b.sum;
	}*/
};

int main()
{
	deque<GasBill> gas_bills;
	deque<WaterBill> water_bills;
	try {
	ifstream file("data1.txt");
	if (!file.is_open()) 
	{
		throw runtime_error("Could not open a file!");
	}
		while (!file.eof())
		{
			int num;
			file >> num;
			if (num == 1)
			{
				GasBill bill;
				file >> bill.surname >> bill.quantity >> bill.sum;
				gas_bills.push_back(bill);
			}
			else if (num == 2)
			{
				WaterBill bill;
				file >> bill.surname >> bill.V >> bill.sum >> bill.pokazy;
				water_bills.push_back(bill);
			}
			else
			{
				throw invalid_argument("Invalid bill type.");
			}
		}
		file.close();
	}
	catch (invalid_argument e)
	{
		cerr << "Error:" << e.what() << endl;
	}
	catch (runtime_error e)
	{
		cerr << "Error:" << e.what() << endl;
	}

	ofstream gas_file("gasbills.txt");
	if (!gas_file.is_open())
	{
		throw runtime_error("Could not open a file!");
	}
	gas_file << "gas bills sorted by quantity of people living: " << endl;
	sort(gas_bills.begin(), gas_bills.end());
	for (const auto& bill : gas_bills)
	{
		gas_file << "your surname: " << bill.surname << endl;
		gas_file << "quantity of people living with you: " << bill.quantity << endl;
		gas_file << "you need to pay: "<<bill.sum << endl;
		gas_file << "---------------------------------------" << endl;
	}
	gas_file.close();

	ofstream water_file("waterbills.txt");
	if (!water_file.is_open())
	{
		throw runtime_error("Could not open a file!");
	}
	water_file << "water bills sorted by surnames: " << endl;
	sort(water_bills.begin(), water_bills.end());
	for (const auto& bill : water_bills)
	{
		water_file << "your surname: " << bill.surname << endl;
		water_file << "water consumption volume: " << bill.V << endl;
		water_file << "pokazy: " << bill.pokazy << endl;
		water_file << "you need to pay: " << bill.sum << endl;
		water_file << "---------------------------------------" << endl;
	}/*
	partial_sort(water_bills.begin(), water_bills.begin() + 5, water_bills.end());
	water_file << "Water bills sorted by sum (top 5): " << endl;
	for (const auto& bill : water_bills)
	{
		water_file << "your surname: " << bill.surname << endl;
		water_file << "water consumption volume: " << bill.V << endl;
		water_file << "pokazy: " << bill.pokazy << endl;
		water_file << "you need to pay: " << bill.sum << endl;
		water_file << "---------------------------------------" << endl;
	}*/
	water_file.close();

	

	return 0;
}