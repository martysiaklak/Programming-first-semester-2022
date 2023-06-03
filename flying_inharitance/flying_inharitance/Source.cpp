#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//�� � ������������ � ����
//��������� ����������� ��� �������� ������, �� ��� �������� ���� � ���� �� �������� ����.
//���� �������� ������ ������ ���� ��� ��������� ������� �� ����������� ������,�� ��� �� ���� ��������,
//���� ���� - ���� ��������,
//���� �������� ���� � ���� ������������ ��� �������.
//� ���������� ���� ������ ��� ��� ������� �������� �������. 
//������ ��� � ���� ��������� �
//�) ������� � ����� ���� � ������ �������, �� ������ �������� �� ������ x.
//�) ��������� ��� ������� ����� �� ������ ���� �� �������� � ���� �� ������ (600 ��)
class Aircraft
{
private:
	string type;
	int max_height;
public:
	int GetHight()
	{
		return max_height;
	}
	virtual void input(istream& is)
	{
		is >> type >> max_height;
	}
	friend istream& operator>>(istream& is, Aircraft& aircraft)   //���� ��������
	{
		aircraft.input(is);
		return is;
	}
	virtual void output(ostream& os) const
	{
		os << "Type of aircraft: " << type << endl;
		os << "Max possible height: " << max_height <<"m"<<endl;
	}
	friend ostream& operator<<(ostream& os, const Aircraft& aircraft)
	{
		aircraft.output(os);
		return os;
	}
};
class Plane : public Aircraft
{
private:
	int speed;
public:
	int GetSpeed()
	{
		return speed;
	}
	virtual void input(istream& is)
	{
		Aircraft::input(is);
		is >> speed;
	}
	friend istream& operator>>(istream& is, Plane& plane)   //���� ��������
	{
		plane.input(is);
		return is;
	}
	virtual void output(ostream& os) const
	{
		Aircraft::output(os);
		os << "Speed: " << speed << " km/h" <<endl;
	}
	friend ostream& operator<<(ostream& os, const Plane& plane)
	{
		plane.output(os);
		return os;
	}
};
class Ballon : public Aircraft
{
private:
	int max_time;
public:
	virtual void input(istream& is)
	{
		Aircraft::input(is);
		is >> max_time;
	}
	friend istream& operator>>(istream& is, Ballon& ballon)
	{
		ballon.input(is);
		return is;
	}
	virtual void output(ostream& os) const
	{
		Aircraft::output(os);
		os << "Max time in air: " << max_time;
	}
	friend ostream& operator<<(ostream& os, const Ballon& ballon)
	{
		ballon.output(os);
		return os;
	}
};
int main()
{
	fstream input_file("info.txt");
	
	vector<Aircraft*> aircrafts;
	int height;
	input_file >> height;
	while (!input_file.eof())
	{
		int num;
		input_file >> num;
		if (num == 1)
		{
			Plane* plane = new Plane(); //��������
			input_file >> *plane;
			aircrafts.push_back(plane);
		}
		else if (num == 2) 
		{
			Ballon* ballon = new Ballon();
			input_file >> *ballon;
			aircrafts.push_back(ballon);
		}
	}
	input_file.close();

	ofstream output1("height.txt");
	for (auto& i : aircrafts)
	{
		if (i->GetHight() >= height)
		{
			output1 << *i << endl;
			output1 << "------------------" << endl;
		}
	}
	output1.close();

	ofstream output2("trip.txt");   
	for (auto& i : aircrafts)   //��������� � �����
	{
		if (dynamic_cast<Plane*>(i))
		{
			int time;
			Plane* plane = dynamic_cast<Plane*>(i);
			time = 600 / plane->GetSpeed();
			output2 << *i;
			output2 << "time to get from Lviv to Kyiv: "<<time<<"h"<< endl;
			output2 << "----------------" << endl;
		}

	}
	output2.close();
	return 0;
}