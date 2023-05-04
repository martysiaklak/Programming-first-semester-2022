#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;
//-вивести у файл2 дні посортовані за загальною кількістю відвідувачів.


struct HourQuantity
{
    int hour;
    int quantity;
};

bool compareByHour(const HourQuantity& a, const HourQuantity& b)
{
    return a.hour < b.hour;
}

bool compareByValue(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

int main()
{
    map<string, vector<HourQuantity>> visitData;
    string day;
    int hour, visitors;

    ifstream inputFile("visits.txt");
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file.\n";
        return 1;
    }

    while (inputFile >> day >> hour >> visitors) 
    {
        visitData[day].push_back({ hour, visitors });
    }

    inputFile.close();

    ofstream outputFile("output1.txt");   //посортовані за днем тижня години з найбільшими відвідувачами 
    if (!outputFile.is_open()) 
    {
        cerr << "Error opening file.\n";
        return 1;
    }

    for (auto& dayData : visitData)
    {
        // Find the maximum visitor count for this day
        int maxVisitors = 0;
        int maxVisitorsHour;
        for (auto& hourData : dayData.second)
        {
            if (hourData.quantity > maxVisitors)
            {
                maxVisitors = hourData.quantity;
                maxVisitorsHour = hourData.hour;
            }
        }
        cout << "day of the week: "<<dayData.first<<endl;
        cout << "hour with max visitors: " << maxVisitorsHour << endl;
        cout << "quantity of visitors: " << maxVisitors << endl;
    }
    outputFile.close();

    ofstream outputFileNew("output2.txt");   //дні посортовані за загальною кількістю відвідувачів. 
    if (!outputFileNew.is_open())
    {
        cerr << "Error opening file.\n";
        return 1;
    }
    vector<int> quantityTroughDay;
    for (auto & dayData : visitData)
    {
        int dayquantity;
        for (auto& hourData : dayData.second)
        {
            dayquantity += hourData.quantity;
        }
        quantityTroughDay.push_back(dayquantity);
    }
    sort(quantityTroughDay.begin(), quantityTroughDay.end());
   
    map<string, int> dailyTotals;
    for (auto& dayData : visitData) 
    {
        int total = 0;
        for (auto& hourData : dayData.second) 
        {
            total += hourData.quantity;
        }
        dailyTotals[dayData.first] = total;
    }
    vector<pair<string, int>> sortedTotals;
    copy(dailyTotals.begin(), dailyTotals.end(), back_inserter(sortedTotals));
    sort(sortedTotals.begin(), sortedTotals.end(), compareByValue);


    // Write sorted days to file
    ofstream outputFile("output2.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file.\n";
        return 1;
    }

    for (auto& day : sortedDays) 
    {
        outputFile << day.first << ": " << day.second << endl;
    }

    outputFile.close();

    return 0;
}


    //// Print out the data to verify it was stored correctly
    //for (auto& dayData : visitData) 
    //{
    //    cout << dayData.first << ": ";
    //    for (auto& hourData : dayData.second) {
    //        cout << hourData.hour << " - " << hourData.quantity << " visitors, ";
    //    }
    //    cout << endl;
    //}