#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
class Exhibit
{
protected:
	string name;
	string author;
public:
	virtual void input(istream& is)
	{
		is >> name >> author;
	}
	friend istream& operator>>(istream& is, Exhibit& exhibit)
	{
		exhibit.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		os << "Name: " << name << endl;
		os << "Author: " << author << endl;
	}
	friend ostream& operator<<(ostream& os, Exhibit& exhibit)
	{
		exhibit.output(os);
		return os;
	}
	virtual bool operator<(const Exhibit& exhibit)
	{
		return author < exhibit.author;
	}
	string GetAuthor()
	{
		return author;
	}
};

class Painting: public Exhibit
{
protected:
	string style;
	int size;
public:
	virtual void input(istream& is)
	{
		Exhibit::input(is);
		is >> style >> size;
	}
	friend istream& operator>>(istream& is, Painting& painting)
	{
		painting.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Exhibit::output(os);
		os << "Style: " << style << endl;
		os << "Size: " << size << endl;
		os << "-------------------" << endl;
	}
	friend ostream& operator<<(ostream& os, Painting& painting)
	{
		painting.output(os);
		return os;
	}
};

class Sculpture : public Exhibit
{
protected:
	string material;
public:
	virtual void input(istream& is)
	{
		Exhibit::input(is);
		is >> material;
	}
	friend istream& operator>>(istream& is, Sculpture& sculpture)
	{
		sculpture.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Exhibit::output(os);
		os << "Material: " << material << endl;
		os << "-------------------" << endl;
	}
	friend ostream& operator<<(ostream& os, Sculpture& sculpture)
	{
		sculpture.output(os);
		return os;
	}
	string GetMaterial()
	{
		return material;
	}
};
int main()
{
	vector <Exhibit*> list;
	ifstream file("data.txt");
	while (!file.eof())
	{
		int num;
		Exhibit* temp = 0;
		file >> num;
		if (num == 1) { temp = new Painting(); }
		if (num == 2) { temp = new Sculpture(); }
		temp->input(file);
		list.push_back(temp);
	}
	file.close();

	sort(list.begin(), list.end(), [](Exhibit* e1, Exhibit* e2) { return *e1 < *e2; }); //sorting
	ofstream output_file;
	output_file.open("output.txt");
	output_file << "Exhibits sorted by author: " << endl;
	output_file << "-------------------------" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->output(output_file);
	}
	
	cout << "Enter author:" << endl;    //paintings by author
	string author_test;
	cin >> author_test;
	output_file << "Paintings by " << author_test<<": "<< endl;
	output_file << "-------------------" << endl;
	int test = 0;
	for (int i = 0; i < list.size(); i++)
	{
		Painting* temp = dynamic_cast<Painting*>(list[i]);
		if (temp != nullptr)
		{
			if (temp->GetAuthor() == author_test)
			{
				temp->output(output_file);
				test++;
			}
		}
	}
	if (test == 0)
	{
		output_file << "No paintings found "<< endl;
		output_file << "-------------------" << endl;
	}

	int sum = 0;
	for (int i = 0; i < list.size(); i++)      //Quantity of sculptures made of marmur
	{
		Sculpture* temp = dynamic_cast<Sculpture*>(list[i]);
		if (temp != nullptr)
		{
			if (temp->GetMaterial() == "marmur")
			{
				sum++;
			}
		}
	}
	output_file << "Quantity of sculptures made of marmur: " << sum <<endl;
	output_file.close();
	return 0;
}