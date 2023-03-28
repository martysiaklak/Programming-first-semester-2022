
//Ввести дані про 10 різних транспортних засобів : водні, наземні і амфібії(човен, підводний човен, вантажівка, всюдихід, …) в один масив,
//видрукувати дані про всі транспортні засоби
//.Посортувати їх за назвою.
//Знайти засіб з найбільшим і найменшим об’ємом двигуна.
//Видрукувати окремо водний транспорт, і окремо транспорт - амфібію
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Transport
{
protected:
	int V;
	string name;
public:
	virtual void input(istream& is)
	{
		is >> V >> name;
	}
	friend istream& operator>>(istream& is, Transport& transport)
	{
		transport.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		os << "V:" << V << endl;
		os << "name:" << name << endl;
	}
	friend ostream& operator<<(ostream& os, Transport& transport)
	{
		transport.output(os);
		return os;
	}
};

class Water: public virtual Transport
{
private:
	string type_of_water;
	int max_speed_water;
public:
	virtual void input(istream& is)
	{
		Transport::input(is);
		is >> type_of_water >> max_speed_water;
	}
	friend istream& operator>>(istream& is, Water& water_transport)
	{
		water_transport.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Transport::output(os);
		os << "type of water:" << type_of_water << endl;
		os << "max speed in water:" << max_speed_water << endl;
	}
	friend ostream& operator<<(ostream& os, Water& water_transport)
	{
		water_transport.output(os);
		return os;
	}
};

class Land: public virtual Transport
{
private:
	int max_speed_land;
	int q_of_places;
public:
	virtual void input(istream& is)
	{
		Transport::input(is);
		is >> max_speed_land >> q_of_places;
	}
	friend istream& operator>>(istream& is, Land& transport)
	{
		transport.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Transport::output(os);
		os << "max speed on land:" << max_speed_land << endl;
		os << "quantity of places:" << q_of_places << endl;
	}
	friend ostream& operator<<(ostream& os, Land& transport)
	{
		transport.output(os);
		return os;
	}
};

//class Amphibia : public virtual Water, public virtual Land
//{
//public:
//	virtual void input(istream& is)
//	{
//		Water::input(is);
//		Land::input(is);
//	}
//	friend istream& operator>>(istream& is, Amphibia& amphibious_transport)
//	{
//		amphibious_transport.input(is);
//		return is;
//	}
//	virtual void output(ostream& os)
//	{
//		Water::output(os);
//		Land::output(os);
//	}
//	friend ostream& operator<<(ostream& os, Amphibia& amphibious_transport)
//	{
//		amphibious_transport.output(os);
//		return os;
//	}
//};
class Amphibia : public Water, public Land
{
private:
	int max_speed_land;
	int q_of_places;
public:
	virtual void input(istream& is)
	{
		Water::input(is);
		// Read in only the max_speed_land and q_of_places values for the Land object
		is >> max_speed_land >> q_of_places;
	}
	friend istream& operator>>(istream& is, Amphibia& amphibious_transport)
	{
		amphibious_transport.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Water::output(os);
		// Output the max_speed_land and q_of_places values for the Land object
		os << "max speed on land:" << max_speed_land << endl;
		os << "quantity of places:" << q_of_places << endl;
	}
	friend ostream& operator<<(ostream& os, Amphibia& amphibious_transport)
	{
		amphibious_transport.output(os);
		return os;
	}
};

int main()
{
	vector<Transport*> transports(10); // create a vector to hold 10 pointers to Transport objects

	ifstream file("data.txt");
	
	// read the data from the file and create the corresponding objects
	for (int i = 0; i < 10; i++) {
		char type;
		file >> type; // read the type of the transport object
		switch (type) 
		{
		case 'W':
			transports[i] = new Water(); // create a new Water object
			break;
		case 'L':
			transports[i] = new Land(); // create a new Land object
			break;
		case 'A':
			transports[i] = new Amphibia(); // create a new Amphibia object
			break;
		}

		file >> *transports[i]; // read the data for the object from the file
	}

	file.close(); 

	// do something with the transport objects, e.g. print them to the console
	for (int i = 0; i < 10; i++) 
	{
		cout << *transports[i] << endl;
	}

	// free the memory allocated for the objects
	for (int i = 0; i < 10; i++) {
		delete transports[i];
		transports[i] = nullptr;
	}

}