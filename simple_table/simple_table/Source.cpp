#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "doctest.h"
#include <stdexcept>

using namespace std;

class Table 
{
private:
    vector<pair<int, string>> data;
public:
    // ����� ���� ���� ����� ������� � �������, ��� ���� ����� ���� ��� ����, �� ����� ���� �������� �� ����
    void Set(int key, const string& value) 
    {
        for (auto& i : data) //����������� �� ��� ��������� �������
        {
            if (i.first == key) 
            {
                i.second = value;
                return;
            }
        }
        data.push_back(pair<int, string>(key, value));  //���� �� ����, �� ���������
    }

    void EraseByKey(int key) //���������
    {
        for (auto i = data.begin(); i != data.end(); i++) //data.begin() i data.end() ��������� �� ������ � ������� �������� �������
        {
            if (i->first == key)          
            {
                data.erase(i);
                return;
            }
        }
        // ���� � ���� if �� ���������, �� ������� ���� � ����� ������ �� ����, �������� �������
        throw runtime_error("Key was not found!");
    }

    string Get(int key) const     //�����
    {
        for (const auto& i : data) 
        {
            if (i.first == key) 
            {
                // ���� ���, �� ��������� �������� (second)
                return i.second;
            }
        }
        throw runtime_error("Key was not found!");
    }
};
TEST_CASE("Setting new values in table")
{
    Table table;
    table.Set(1, "Hello");
    table.Set(2, "World");
    table.Set(3, "!");
    CHECK(table.Get(1) == "Hello");
    CHECK(table.Get(2) == "World");
    CHECK(table.Get(3) == "!");
}

TEST_CASE("Changing values in table")
{
    Table table;
    table.Set(1, "Hello");
    table.Set(2, "World");
    table.Set(3, "!");
    table.Set(1, "Hello World");
    table.Set(2, "Hello World!");
    table.Set(3, "Hello World!!!");
    CHECK(table.Get(1) == "Hello World");
    CHECK(table.Get(2) == "Hello World!");
    CHECK(table.Get(3) == "Hello World!!!");
}

TEST_CASE("Erasing values from table")
{
    Table table;
    table.Set(1, "Hello");
    table.Set(2, "World");
    table.Set(3, "!");
    table.EraseByKey(1);
    table.EraseByKey(2);
    table.EraseByKey(3);
    CHECK_THROWS(table.Get(1));
    CHECK_THROWS(table.Get(2));
    CHECK_THROWS(table.Get(3));
}