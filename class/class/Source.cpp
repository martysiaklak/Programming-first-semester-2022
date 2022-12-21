#include <iostream>
using namespace std;
class Monitor
{
private:
	string brand;
	float length;
	float price;
public:
	Monitor() : brand("Samsung"), length(21), price(1500.45) {}
	Monitor(string brand_, float length_, float price_) : brand(brand_), length(length_), price(price_) {}
	Monitor(const Monitor& monitor) : brand(monitor.brand), length(monitor.length), price(monitor.price) {}
	friend istream& operator>>(istream& is, Monitor& monitor)
	{
		cout << "Enter brand name:" << endl;
		is >> monitor.brand;
		cout << "Enter diagonal length:" << endl;
		is >> monitor.length;
		while (monitor.length <= 0)
		{
			cout << "Diagonal length cannot be a negative number!" << endl;
			cout << "Enter diagonal length:" << endl;
			is >> monitor.length;
		}
		cout << "Enter price:" << endl;
		is >> monitor.price;
		while (monitor.price <= 0)
		{
			cout << "Price cannot be a negative number!" << endl;
			cout << "Enter price:" << endl;
			is >> monitor.price;
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Monitor& monitor)
	{
		os << "Brand: " << monitor.brand << endl;
		os << "Diagonal length: " << monitor.length << endl;
		os << "Price: " << monitor.price << endl;
		return os;
	}
	float get_price() const
	{
		return price;
	}
	string get_brand()
	{
		return brand;
	}
	float get_length()
	{
		return length;
	}
	bool operator<(const Monitor& monitor2)
	{
		return get_price() < monitor2.get_price();
	}
};
void sort(Monitor* array);
int main()
{
	Monitor array[6];
	Monitor monitor1("Apple", 28.5, 1000);
	Monitor monitor2;
	Monitor monitor3(monitor1);

	array[0] = monitor1;
	array[1] = monitor2;
	array[2] = monitor3;

	for (int i = 3; i < 6; i++)
	{
		cout << "Monitor " << i + 1 << ":" << endl;
		cin >> array[i];
	}
	sort(array);
	cout << "--------------------------" << endl;
	cout << "Sorted by prices" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "Monitor " << i + 1 << ":" << endl;
		cout<< array[i];
	}
	cout << "---------------------" << endl;
	cout << "Brands that we have:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << array[i].get_brand() << endl;
	}
	float length;
	cout << "---------------------" << endl;
	cout << "Enter diagonal length: " << endl;
	cin >> length;
	cout << "Monitors that we have with that length:" << endl;
	int sum = 0;
	for (int i = 0; i < 6; i++)
	{
		if (array[i].get_length() == length)
		{
			cout << array[i]<< endl;
			sum++;
		}
	}
	if (sum==0)
	{
		cout << "sorry, we don't have monitors with that diagonal length" << endl;
	}
	return 0;
}
void sort(Monitor* array)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (array[i] < array[j])
			{
				Monitor temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}