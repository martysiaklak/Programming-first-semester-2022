
//В текстовому файлі задано дані про n студентів.
//Зчитати ці дані у масив 
//і видрукувати у текстовий файл список всіх шпаргалок, посортованих за предметом та номерами
//.В інший текстовий файл вивести всі електронні шпаргалки на носіях «комп» та їх кількість.
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
class Shpora
{
protected:
	string subject;
	int number;
public:
	virtual void input(istream& is)
	{
		is >> subject >> number;
	}
	friend istream& operator>>(istream& is, Shpora& shpora)
	{
		shpora.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		os << "subject: " << subject << endl;
		os << "number: " << number << endl;
	}
	friend ostream& operator<<(ostream& os, Shpora& shpora)
	{
		shpora.output(os);
		return os;
	}
	/*virtual bool operator<(const Exhibit& exhibit)
	{
		return author < exhibit.author;
	}
	string GetAuthor()
	{
		return author;
	}*/
};

class Paper : public Shpora
{
protected:
	int size;
	string place;
public:
	virtual void input(istream& is)
	{
		Shpora::input(is);
		is >> size >> place;
	}
	friend istream& operator>>(istream& is, Paper& paper)
	{
		paper.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Shpora::output(os);
		os << "size: " << size << endl;
		os << "place: " << place << endl;
		os << "-------------------" << endl;
	}
	friend ostream& operator<<(ostream& os, Paper& paper)
	{
		paper.output(os);
		return os;
	}
};

class Electronic : public Shpora
{
protected:
	string device;
public:
	virtual void input(istream& is)
	{
		Shpora::input(is);
		is >> device;
	}
	friend istream& operator>>(istream& is, Electronic& electronic)
	{
		electronic.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Shpora::output(os);
		os << "device: " << device << endl;
		os << "-------------------" << endl;
	}
	friend ostream& operator<<(ostream& os, Electronic& electronic)
	{
		electronic.output(os);
		return os;
	}
	/*string GetMaterial()
	{
		return material;
	}*/
};
class Student
{
private:
	string name;
	int group;
	Shpora* shporas;
public:
	Student() : name(""), group(0), shporas(nullptr) {}
	/*friend istream& operator>>(istream& is, Electronic& electronic)
	{
		.input(is);
		return is;
	}*/
	friend istream& operator>>(istream& is, Student& student) 
	{
		is >> student.name >> student.group;
	
		cout << "Now add data about students" << endl;
		student.shporas = new Shpora[5];
		for (int i = 0; i < 5; i++)
		{
			is >> student.shporas[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& student)
	{
		os << "name:" << student.name << endl;
		os << "group:" << student.group << endl;
		for (int i = 0; i < 5; i++)
		{
			os << student.shporas[i];
		}
		return os;
	}
};
int main()
{

	vector <Student*> list;
	ifstream file("data.txt");
	while (!file.eof())
	{
		int num;
		Student* temp = 0;
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
	output_file << "Paintings by " << author_test << ": " << endl;
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
		output_file << "No paintings found " << endl;
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
	output_file << "Quantity of sculptures made of marmur: " << sum << endl;
	output_file.close();
	return 0;
}