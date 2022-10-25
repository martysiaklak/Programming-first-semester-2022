#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;



int main()
{
    float a, b;
    float x[10];
    float e = pow(10, -5);
    double S = 0;
    cout << "Enter the first number:";
    cin >> a;
    cout << "Enter the last number:";
    cin >> b;
    cout << left << setw(15) << "X" << left << setw(15) << "S" << left
    << setw(15) << "Y" << left << setw(15) << "Pohubka" << endl;
    double h = (b - a) / 9.0; 
    for (int i = 0; i < 10; i++)
    {
        x[i] = a + i * h;
        int j = 0;
        double w0 = 0, w=0;
        S = 0;
        do
        {
            int starter_factorial = 2 * j + 1;
            long int fact = 1;
            for (int k = 1; k <= starter_factorial; k++)
            {
                fact = fact * k;
            }
            w0 = w;
            w= pow(x[i], 2 * j + 1) / fact;
            S = S + w;
            j = j + 1;
        } while (fabs(w-w0)>e);
        double y = (exp(x[i]) - exp(-x[i])) / 2;
        double pohubka = fabs((S - y) / y)*100;
        cout << left << setw(15) << x[i] << left << setw(15) << S << left << setw(15) << y << fixed<< left << setw(15) << pohubka<< endl;


    }
    
    return 0;
}