#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

string Greeting(string(*f)(string), string name)
{
    ostringstream os;
    os << setw(4) << f(name) << endl;
    return os.str();
}

string Ukrainian(string name)
{
    return "Привіт, " + name + "!";
}
string English(string name)
{
    return "Hello, " + name + "!";
}
string Japanese(string name)
{
    return "こんにちは, " + name + "!";
}

int main()
{
    cout << "Choose language:" << endl;
    cout << "0 UKRAINIAN"<< endl << "1 English" << endl << "2 Japanese" << endl;
    int choice;
    cin >> choice;
    cout << "Enter your name:" << endl;
    string name;
    cin >> name;
    switch(choice)
    {
    case 0:
        cout << Greeting(Ukrainian, name);
            break;
    case 1:
        cout << Greeting(English, name);
        break;
    case 2:
        cout << Greeting(Japanese, name);
        break;
    }

    return 0;
}