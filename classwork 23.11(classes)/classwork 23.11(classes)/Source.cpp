#include <iostream>
#include<string>
using namespace std;
class Car
{
private:
	string name;
	string color;
	int price;
public:
	Car() : name(""), color(""), price(0){}
	Car(string n, string c, int p) : name(n), color(c), price(p){}
	int get_price()
	{
		return price;
	}
	void set_price(int new_price)
	{
		price = new_price;
	}
	string get_name()
	{
		return name;
	}
	string get_color()
	{
		return color;
	}
	void input()
	{
		cout << "Enter name:" << endl;
		//getline(cin, name);
		cin >> name;
		cout << "Enter color:" << endl;
		cin >> color;
		cout << "Enter price:" << endl;
		cin >> price;
	}
	void print()
	{
		cout << "Name" << name << endl;
		cout << "Color" << color << endl;
		cout << "Price" << price << endl;
	}
};
int main()
{
	Car car1;
	Car car2("Opel", "Red", 1000);
	int size;
	cout << "Enter size:" << endl;
	cin >> size;
	Car* array_cars = new Car[size];
	array_cars[0] = car1;
	array_cars[1] = car2;
	for (int i = 2; i < size; i++)
	{
		//cout << "Enter " << i + 1 << endl;
		array_cars[i].input();
	}
	cout << "Enter color:" << endl;
	string color;
	cin >> color;
	for (int i = 0; i < size; i++)
	{
		if (array_cars[i].get_color() == color)
		{
			array_cars[i].print();
		}
	}
	/*cout << "Enter name:" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < size; i++)
	{
		array_cars[i].get_name() == name;
		array_cars[i].print();
	}*/
	for (int i = 0; i < size; i++)
	{
		if (array_cars[i].get_color() == "gold")
		{
			array_cars[i].set_price(array_cars[i].get_price() * 0.9);
			array_cars[i].print();
		}
		//array_cars[i].print();
	}
	


	


	return 0;
}
