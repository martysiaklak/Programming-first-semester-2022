#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//У двох текстових файлах задано дані про телефони двох різних фірм.
//Зчитати ці дані в один масив  і вивести у текстовий файл : 
//1)всі телефони, посортовані за ціною із зазначенням загальної суми; 
//2) радіотелефони з автовідповідачем
class Phone
{
protected:
	string name;    //коли тип даних стає абстрактним?
	string company;
	int price;
public:
	virtual void input(istream& is) 
	{ 
		is >> name >> company>> price; 
	}
	friend istream& operator>>(istream& is, Phone& phone)
	{
		phone.input(is);
		return is;
	}
	virtual void output(ostream& os) { os << name<<company<<price; }
	friend ostream& operator<<(ostream& os, Phone& phone)
	{
		phone.output(os);
		return os;
	}
	//virtual int get_price() = 0;      //????
	bool operator<(const Phone& phone)
	{
		return price < phone.price;
	}
};

class Mobile : public Phone
{
private:
	string colour;
	int memory;
public:
	virtual void input(istream& is)
	{
		Phone::input(is);
		is >> colour >> memory;
	}
	friend istream& operator>>(istream& is, Mobile& mobile)
	{
		mobile.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Phone::output(os);
		os << colour << memory;
	}
	friend ostream& operator<<(ostream& os, Mobile& mobile)
	{
		mobile.output(os);
		return os;
	}
};
class Radio : public Phone
{
private:
	int radius;
	bool a;
public:
	virtual void input(istream& is)
	{
		Phone::input(is);
		is >> radius>> a;
	}
	friend istream& operator>>(istream& is, Radio& radiophone)
	{
		radiophone.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Phone::output(os);
		os << radius<<a;
	}
	friend ostream& operator<<(ostream& os, Radio& radiophone)
	{
		radiophone.output(os);
		return os;
	}
};
int main()
{
	vector <Phone*> list;
	ifstream file("data.txt");
	int num_objects;
	file >> num_objects;

	for (int i = 0; i < num_objects; i++)
	{
		int num;
		Phone* temp = nullptr;
		file >> num;
		if (num == 1) { temp = new Mobile(); }
		if (num == 2) { temp = new Radio(); }
		temp->input(file);
		list.push_back(temp);
	}
	//while (!file.eof())                        //не паше
	//{
	//	int num;
	//	Phone* temp = 0;
	//	file >> num;
	//	if (num == 1) { temp = new Mobile(); }
	//	if (num == 2) { temp = new Radio(); }
	//	temp->input(file);
	//	list.push_back(temp);
	//}
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->output(cout);
	}
	file.close();

	int sum = 0;
	for (int i = 0; i < list.size(); i++)
	{
		sum = sum + list[i].get_income();                           //з тими інкомами розібратися
	}
	/*}*/
	/*int total_income = 0;
	for (int i = 0; i < list.size(); i++)
	{
		total_income = list[i]->get_income();
	}
	cout << "Total income: " << total_income << endl;
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->output(cout);
	}*/

	return 0;
}