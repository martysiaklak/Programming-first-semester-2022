#include <iostream>
using namespace std;
class Product
{
private:
	string name;
	int price;
	int code;
public:
	Product(int c=0):code(c), price(0), name("lol") {}
	int GetPrice()
	{
		return price;
	}
	int GetCode()
	{
		return code;
	}
	string GetName()
	{
		return name;
	}
	friend istream& operator>>(istream& is, Product& product)
	{
		cout << "Enter name: ";
		is >> product.name;
		cout << "Enter price: ";
		is >> product.price;
		cout << "Enter code: ";
		is >> product.code;
		return is;
	}
	friend ostream& operator<<(ostream& os, Product product)
	{
		os << product.name << ", price " << product.price << ", code " << product.code;
		return os;
	}
	bool operator==(const Product& product2)
	{
		return code == product2.code;
	}
};
class Cart
{
private:
	Product* products;
	int* quantity;
	int cur=0;
public:
	Cart() { products = new Product[100]; quantity = new int[100]; }
	Cart(int size) { products = new Product[size]; quantity = new int[size]; }
	int total_price()
	{
		int sum = 0;
		for (int i = 0; i < cur; i++)
		{
			sum = sum + products[i].GetPrice() * quantity[i];
		}
		return sum;
	}
	void AddProd(Product& product, int quant)
	{
		products[cur] = product;
		quantity[cur] = quant;
		cur++;
	}
	void remove(Product product)
	{
		int i = 0;
		for (int i = 0; i < cur; i++)
		{
			if (products[i] == product)
			{
				if (quantity[i] >= 1)
				{
					quantity[i]--;
				}
				else
				{
					for (int j = i; j < cur; j++)
					{
						products[j] = products[j + 1];
					}
					cur--;
				}
				break;
			}
		}
	}
	int GetCur()
	{
		return cur;
	}
		friend ostream& operator<<(ostream & os, Cart cart)
		{
			os << "Youe cart:" << endl;
			for (int i = 0; i < cart.cur; i++)
			{
				if (cart.quantity[i] == 0)
				{
					i++;
				}
				os << "Product: " << cart.products[i] << endl;
				os << "Quantity: " << cart.quantity[i] << endl;
				os << "-----------------------" << endl;
			}
			os << "total price:" << cart.total_price() << endl;
			os << "-----------------------" << endl;
			return os;
		}
};
int main()
{
	string answer;
	Cart cart;
	cout << "Hello!" << endl;
	do
	{
		cout << "Do you want to ADD or REMOVE product?" << endl;
		cin >> answer;
		if (answer == "add" || answer == "Add" || answer == "ADD")
		{
			Product product1;
			cin >> product1;
			cout << "Enter quantity" << endl;
			int qua;
			cin >> qua;
			cart.AddProd(product1, qua);
		}
		if (answer == "remove" || answer == "Remove" || answer == "REMOVE")
		{
			if (cart.GetCur() <= 0)
			{
				cout << "There are 0 products in your cart" << endl;
			}
			else
			{
				cout << cart << endl;
				cout << "what item would you like to delete?(enter code)" << endl;
				int product_code;
				cin >> product_code;
				cart.remove(Product(product_code));
				cout << cart << endl;
			}
		}
	} while (answer != "done");
}
