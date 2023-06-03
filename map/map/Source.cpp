#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

struct HourQuantity
{
    int hour;
    int quantity;
};

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

    ofstream outputFile("output1.txt");   //���������� �� ���� ����� ������ � ���������� ����������� 
    if (!outputFile.is_open()) 
    {
        cerr << "Error opening file.\n";
        return 1;
    }

    for (auto& dayData : visitData) //� ���������� ������� ���������� ��. ���� ���� � � �������� �� �����
        //������ ���� � �������� �� ����������
        //������, ���� � ��� ������ �������� ����
    {
        int maxVisitors = 0;
        vector<int> maxVisitorsHour;
        for (auto& hourData : dayData.second)
        {
            if (hourData.quantity > maxVisitors)
            {
                maxVisitors = hourData.quantity;
                maxVisitorsHour.clear();
                maxVisitorsHour.push_back(hourData.hour);
            }
            else if (hourData.quantity == maxVisitors)
            {
                maxVisitorsHour.push_back(hourData.hour);
            }
        }
        outputFile << "day of the week: " << dayData.first << endl;
        outputFile << "hour(s) with max visitors: ";
        for (auto& hour : maxVisitorsHour)
        {
            outputFile << hour << " ";
        }
        outputFile << endl;
        outputFile << "quantity of visitors: " << maxVisitors << endl;
        outputFile << "-------------------------------" << endl;
    }

    outputFile.close();

    ofstream outputFileNew("output2.txt");   //�� ���������� �� ��������� ������� ���������� 
    if (!outputFileNew.is_open())
    {
        cerr << "Error opening file.\n";
        return 1;
    }

    outputFileNew << "days sorted by the whole quantity of visitors:" << endl;

    vector<pair<string, int>> dailyTotals;
    for (auto& dayData : visitData) 
    {
        int total = 0;
        for (auto& hourData : dayData.second) 
        {
            total += hourData.quantity;
        }
        dailyTotals.push_back(make_pair(dayData.first, total));
    }
    sort(dailyTotals.begin(), dailyTotals.end(), compareByValue);

    for (auto& day : dailyTotals)
    {
        outputFileNew << day.first << ": " << day.second << endl;
    }

    /* map<string, int> dailyTotals;
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
   sort(sortedTotals.begin(), sortedTotals.end(), compareByValue);*/

    outputFileNew.close();

    return 0;
}