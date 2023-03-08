#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Phone
{
protected:
	string name;    
	string company;
	int price=0;
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
	virtual void output(ostream& os) 
	{
		os << "Name:" << name << endl;
		os << "Company:" << company << endl;
		os << "Price:" << price << endl;
	}
	friend ostream& operator<<(ostream& os, Phone& phone)
	{
		phone.output(os);
		return os;
	}
	virtual int get_price() { return price; }     
	virtual bool operator<(const Phone& phone)
	{
		return price < phone.price;
	}
};

class Mobile : public Phone
{
private:
	string colour;
	int memory=0;
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
		os << "colour:" << colour << endl;
		os << "memory:" << memory << endl;
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
	int radius=0;
	bool a=1;
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
		os << "radius:" << radius << endl;
		os << "ia there an autoplay?:" << a << endl;
	}
	friend ostream& operator<<(ostream& os, Radio& radiophone)
	{
		radiophone.output(os);
		return os;
	}
	bool GetA()
	{
		return a;
	}
};
void write_radiophones_with_an_autoplay(vector<Phone*>& list, ofstream& output_file);
int main()
{
	vector <Phone*> list;
	ifstream file("data.txt");
	while (!file.eof())                        
	{
		int num;
		Phone* temp=0;
		file >> num;
		if (num == 1) { temp = new Mobile(); }
		if (num == 2) { temp = new Radio(); }
		temp->input(file);
		list.push_back(temp);
	}
	file.close();
	
	sort(list.begin(), list.end(), [](Phone* p1, Phone* p2) { return *p1 < *p2; });
	ofstream output_file;
	output_file.open("output_file.txt");
	output_file << "Phones sorted by price: " << endl;
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->output(output_file);
	}
	output_file << "-----------------------: " << endl;
	int total_price = 0;
	for (int i = 0; i < list.size(); i++)
	{
		total_price = total_price + list[i]->get_price();
	}
	output_file << "Total price: " << total_price << endl;
	output_file << "-----------------------: " << endl;

	write_radiophones_with_an_autoplay(list, output_file);
	output_file.close();


	return 0;
}
void write_radiophones_with_an_autoplay(vector<Phone*>& list, ofstream& output_file)
{
	output_file << "Radiophones with AutoReply:" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		Radio* radio = dynamic_cast<Radio*>(list[i]);
		if (radio && radio->GetA())
		{
			radio->output(output_file);
		}
	}
}