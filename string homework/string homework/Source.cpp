#include <iostream>
#include <string>
using namespace std;
void chars(string text, char c);
string new_text = "";
int main()
{
	cout << "Enter text:" << endl;
	string text;
	getline(cin, text, '.');
	for (int i = 0; i < text.length(); i++)
		{
			char c = text[i];
			chars(text, c);
		}
	cout << new_text <<endl;
	return 0;
}
void chars(string text, char c)
{
	
	int sum = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == c)
		{
			sum++;
		}
		
	}
	for (int i = 0; i < new_text.length(); i++) //checking if a char is repeating
	{
		if (new_text[i] == c)
		{
			return;
		}
	
	}
	if (sum >= 2)
	{
		new_text += c;
		
	}
}