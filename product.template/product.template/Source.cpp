#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Product 
{
protected:
	T object;
	int production_day;    //I decided to operate one mounth only. 
	int expiration_period_in_days;
public:
	Product() : object(), production_day(0), expiration_period_in_days(0) {}
	Product(T obj, int prod_day, int exp_period_in_days) :
		object(obj), production_day(prod_day), expiration_period_in_days(exp_period_in_days) {}
	int best_before()
	{
		return production_day + expiration_period_in_days;
	}
	friend istream& operator>>(istream& is, Product& product)
	{
		cout << "Product: " << endl;
		is >> product.object;
		cout << "Date of producing: " << endl;
		is >> product.production_day;
		cout << "Expiration period (days): " << endl;
		is>>product.expiration_period_in_days;
		return is;
	}
	friend ostream& operator<<(ostream& os, Product& product)
	{
		os << "Product: " << product.object << endl;
		os << "Date of producing: " << product.production_day<<endl;
		os << "Expiration period (days): " << product.expiration_period_in_days <<endl;
		return os;
	}
};
struct Milk
{
	string name;
	double fat; 
	friend ostream& operator<<(ostream& os, const Milk& milk)
	{
		os << "Milk: " << milk.name << ", " << milk.fat << "% fat";
		return os;
	}

	friend istream& operator>>(istream& is, Milk& milk)
	{
		cout << "Enter the name of the milk: " << endl;
		is >> milk.name;
		cout << "Enter the fat content (in %): " << endl;
		is >> milk.fat;
		return is;
	}
};
int main()
{
	Product<string> organic_food[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "data about organic food #" << i + 1 << endl;
		cin >> organic_food[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "best eat product #" << i + 1<<" before:" << organic_food[i].best_before()<<endl;
	}

	Product<Milk> milk_products[3];
	for (int i = 0; i < 3; i++) 
	{
		cout << "data about milk #" << i + 1 << endl;
		cin >> milk_products[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "best drink milk #" << i+1<< " before:" << milk_products[i].best_before()<<endl;
	}
	/*Product<Milk> milk_products[3] = {
	Product<Milk>({"Molokia", 2.5}, 1, 27),
	Product<Milk>({"Zvenuhora", 2.5}, 2, 10),
	Product<Milk>({"Mimosa", 2.5}, 3, 14),
	};*/
}