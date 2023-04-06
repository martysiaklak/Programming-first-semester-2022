#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

string Modified(double(*f)(double), double a[], int n) 
{
    ostringstream os;
    os<< fixed << setprecision(2)<<right;   //2 digits after coma
    os << "|  " << setw(11) << "i  |" << setw(13) << "a[i]  |" << setw(15) << "Modified a[i]  |"<<endl;

    for (int i = 0; i < n; i++)
    {
        os << "|  " << setw(8) << i << "  | " << setw(10) << a[i] << "  | " << setw(11) << f(a[i]) << "  |" << endl;

    }
    return os.str();       
}

double square(double x) 
{
    return pow(x, 2);
}

double Trygo(double x) 
{
        return sin(x) + cos(x) - tan(x);
}

double nearestInt(double x) 
{
    return round(x);
}

int main() 
{
    ofstream output("output.txt");    

    double a[] = {
        1.001,
        2.234,
        3.3,
        4.423,
        5.51111,
        6.216,
        7.7,
        8.28,
        9.96,
        10.71,
        11.0
    };
    int n = sizeof(a) / sizeof(a[0]);

    // square
    output << "SQUARE:"<<endl;
    output << Modified(square, a, n);

    // (sin + cos - tg)
    output << "SIN + COS - TG:"<<endl;
    output << Modified(Trygo, a, n);

    // Nearest integer using lambda
    output << "NEAREST INTEGER:"<<endl;
    output << Modified([](double x) { return round(x); }, a, n);

    output.close();

    return 0;
}
