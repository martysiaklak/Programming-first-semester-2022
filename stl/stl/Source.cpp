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
	friend istream& operator>>(istream& is, GasBill& bill)    //input
	{
		is >> bill.surname >> bill.quantity >> bill.sum;
			return is;
	}
	friend ostream& operator<<(ostream& os, const GasBill& bill)  //output
	{
		os << "your surname: " << bill.surname << endl;
		os << "quantity of people living with you: " << bill.quantity << endl;
		os << "you need to pay: " << bill.sum << endl;
		os << "---------------------------------------" << endl;
		return os;
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
	}
	friend istream& operator>>(istream& is,  WaterBill& bill)   //input
	{
		is >> bill.surname >> bill.V >> bill.sum >> bill.pokazy;
		return is;
	}
	friend ostream& operator<<(ostream& os, const WaterBill& bill)  //output
	{
		os << "your surname: " << bill.surname << endl;
		os << "water consumption volume: " << bill.V << endl;
		os << "pokazy: " << bill.pokazy << endl;
		os << "you need to pay: " << bill.sum << endl;
		os << "---------------------------------------" << endl;
		return os;
	}
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
		while (!file.eof())      //deviding into 2 deques
		{
			int num;
			file >> num;
			if (num == 1)
			{
				GasBill bill;
				file >> bill;
				gas_bills.push_back(bill);
			}
			else if (num == 2)
			{
				WaterBill bill;
				file >> bill;
				water_bills.push_back(bill);
			}
			else
			{
				throw invalid_argument("Invalid bill type.");
			}
		}
		file.close();
	
	ofstream gas_file("gasbills.txt");
	if (!gas_file.is_open())
	{
		throw runtime_error("Could not open a file!");
	}

	gas_file << "gas bills sorted by quantity of people living with you: " << endl;
	gas_file << "------------------------" << endl;
	sort(gas_bills.begin(), gas_bills.end());         //sorting by quantity of people living in the house
	for (const auto& bill : gas_bills)    //printing sorted results
	{
		if (gas_bills.size() == 0)
		{
			throw invalid_argument("No elements in this deque");
		}
		gas_file << bill;
	}
	gas_file.close();

	ofstream water_file("waterbills.txt");
	if (!water_file.is_open())
	{
		throw runtime_error("Could not open a file!");
	}

	water_file << "water bills sorted by surnames: " << endl;
	water_file << "------------------------" << endl;
	sort(water_bills.begin(), water_bills.end());    //sorting by surnames(alphabet)
	for (const auto& bill : water_bills)   //printing sorted results
	{
		if (water_bills.size() == 0)
		{
			throw invalid_argument("No elements in this deque");
		}
		water_file << bill;
	}

	sort(water_bills.begin(), water_bills.end(), [](const WaterBill& a, const WaterBill& b) //sorting by sum
		{
			return a.sum > b.sum;  // Sort in descending order
		});
	water_file << "top-5 bills with the biggest sum" << endl;
	water_file << "------------------------" << endl;
	for (int i = 0; i < 5; i++)     //printing 5 bills with the biggest sum
	{
		if (water_bills.size() == 0)
		{
			throw invalid_argument("No elements in this deque");
		}
		water_file << water_bills[i] << endl;
	}
	water_file.close();

	}
	catch (invalid_argument e)
	{
		cerr << "Error:" << e.what() << endl;
	}
	catch (runtime_error e)
	{
		cerr << "Error:" << e.what() << endl;
	}
	return 0;
}