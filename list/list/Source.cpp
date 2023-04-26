#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	cout << "enter your sentence:" << endl;
	string answer;
	getline(cin, answer, '.');  //sentence ends with .

	list<int> numbers;
	for (int i = 0; i < answer.length(); i++) 
	{
		if (isdigit(answer[i])) //checking if a digit is a number
		{
			int digit_value = answer[i] - '0'; //convert the character digit to its integer value
			numbers.push_back(digit_value); //if yes-pushing it to the list
		}
	}

	numbers.sort(); //sorting list
	cout << "sorted numbers: " << endl;
	for (int i : numbers) //printing list
	{
		cout << i << " ";
	}
	cout << endl;

	numbers.unique(); //deleting repeated numbers
	cout << "sorted numbers without any repeatings: " << endl;
	list<int>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); ++it) //printing using iterator
	{
		cout << *it << " ";
	}

	return 0;
}
