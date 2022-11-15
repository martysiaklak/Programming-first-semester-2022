#include <iostream>
#include <string>
using namespace std;
/*bool is_it_text(string text, char c, int k);
int count(string text, char c, int l);
int main()
{
	cout << "Enter text:" << endl;
	string text;
	getline(cin, text);
	for (int i = 0; i < text.length(); i++)
	{
		if (is_it_text(text, text[i], i - 1)==false)
		{
			cout << "char "<<text[i] << "--->" << count(text, text[i], i) <<" times" << endl;
		}
	}
	return 0;
}
bool is_it_text(string text, char c,  int k)
{
	for (int i = 0; i <=k; i++)
	{
			if (text[i] == c)
			{
				return true;
			}
	}
	return false;
}
int count(string text, char c, int l)
{
	int sum = 0;
	for (int j = l; j < text.length(); j++)
	{
		if (text[j] == c)
		{
			sum++;
		}
	}
	return sum;
}*/
/*int main()
{
	string text[10];
	cout << "Enter text:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> text[i];
	}
	int mas[10];
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		mas[i] = stoi(text[i]);
		sum = sum + mas[i];
	}
	cout << "Sum:" << sum;*/

	/*string text;
	getline(cin, text);
	int sum = 0;
	for (int i = 0; i < text.length(); i++)
	{
		sum = sum + text[i];
	}
	cout << "Sum:" << sum;
	return 0;
}*/
int main()
{
	cout << "Enter text:" << endl;
	string fulltext;
	getline(cin, fulltext, '.');
	int i, j = 0;
	text[0] = "";
	while (fulltext[i] != '.')
	{
		text[j] = "";
		if (fulltext[i] != ",")
		{
			text[j]+=fulltext[ i]
		}
		else
		{
			j++;
			text[j] = "";

		}
	}

}