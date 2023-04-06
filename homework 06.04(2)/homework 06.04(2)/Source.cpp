#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

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
bool is_all_letters(string str)
{
    for (char c : str) {
        if (!isalpha(c)) {  // checks if the character is not a letter
            return false;
        }
    }
    return true;
}
int main()
{
    try {
        ofstream output("output.txt");
        if (!output.is_open())
        {
            throw runtime_error("Could not open a file!");     //could not open a file
        }

        cout << "Choose language:" << endl;
        cout << "0 UKRAINIAN" << endl << "1 English" << endl << "2 Japanese" << endl;
        int choice;
        cin >> choice;
        cout << "Enter your name:" << endl;
        string name;
        cin >> name;
        if (is_all_letters(name) == false)
        {
            throw invalid_argument("Your name has to contain letters only!");  //your name must contain only letters
        }
        if (name.size() > 16)
        {
            throw length_error("Your name is too long!"); //only 16 digits
        }

        switch (choice)
        {
        case 0:
            output << Greeting(Ukrainian, name);
            break;
        case 1:
            output << Greeting(English, name);
            break;
        case 2:
            output << Greeting(Japanese, name);
            break;
        default:
            throw invalid_argument("Wrong choice of number!");  //wrong number
        }
        output.close();
    }
    catch(invalid_argument e) 
    {
        cerr << "Error:" << e.what() << endl;
    }
    catch (length_error e) 
    {
        cerr << "Error:" << e.what() << endl;
    }
    catch (runtime_error e)
    {
        cerr << "Error:" << e.what() << endl;
    }

    return 0;
}