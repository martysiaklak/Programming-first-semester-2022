#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	cout << "enter your sentence:" << endl;
	string answer;
	getline(cin, answer, '.');  //sentence ends with .

	list<string> divided_answer;
	string word = "";
	for (auto c : answer) 
	{
		if (c == ' ') 
		{
			divided_answer.push_back(word);
			word = "";
		}
		else 
		{
			word += c;
		}
	}
	divided_answer.push_back(word);

	list<int> numbers;
	for (string i : divided_answer)
	{
		bool isNumeric = true;
		for (auto t : i)
		{
			if (!isdigit(t)) 
			{
				isNumeric = false;
				break;
			}
		}
		if (isNumeric) 
		{
			numbers.push_back(stoi(i));
		}
	}

	//for (int i = 0; i < answer.length(); i++) 
	//{
	//	if (isdigit(answer[i])) //checking if a digit is a number
	//	{
	//		int digit_value = answer[i] - '0'; //convert the character digit to its integer value
	//		numbers.push_back(digit_value); //if yes-pushing it to the list
	//	}
	//}

	numbers.sort(); //sorting list
	cout << "sorted numbers: " << endl;
	for (int i : numbers) //printing list
	{
		cout << i << " ";
	}
	cout << endl;

	numbers.unique(); //deleting repeated numbers
	cout << "sorted numbers without any repeatings: " << endl;
	list<int>::iterator it; //iterators are used to point at the memory addresses of STL containers
	for (it = numbers.begin(); it != numbers.end(); ++it) //printing using iterator
	{
		cout << *it << " ";
	}

	return 0;
}




/*³� �������� �������� �� �������� �������� � ���� - ����� ���� ������ �� ��������� ���������
��� ����, ������ ����������� �� ������ ���, �� ���� �� � ����������� ������� ���'��. 
���� ����������� � �����, �� ����������� ���� �� ������, 
�� �������� ��������� ��������� �� �������� �������� � �������� ������.*/