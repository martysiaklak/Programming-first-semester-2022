#include <iostream>
#include <cmath>
using namespace std;
int repeat(char c, int minpoint, int maxpoint, string text);

int main()
{
    string text;
    cout << "Enter text:" << endl;
    cin >> text;
    int numbers = 0;
    int letters = 0;
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        numbers += repeat('0' + i, 0, text.length() / 2, text);
    }
    cout << "Number of digits in first half:" << numbers<<endl;

    for (int i = 0; i < 26; i++)
    {
        letters += repeat('a' + i, text.length()/4*3.0, text.length(), text);
    }
    cout << "Number of letters in last quarter: " << letters << endl;

    if (numbers < 12 && letters == 0)
    {
        k = repeat('*', text.length() / 3 * 2.0, text.length(), text);
        cout << "Number of stars in last third: " << k << endl;
    }
    else
    {
        cout << "Invalid text";
    }
    return 0;
}
int repeat(char c, int minpoint, int maxpoint, string text)
{
    int sum = 0;
    for (int i = minpoint; i < maxpoint; i++)
    {
        if (text[i] == c)
        {
            sum++;
        }
    }
    return sum;
}
