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
    // метод який додає новий елемент в таблицю, або якщо такий ключ вже існує, то змінює його значення на нове
    void Set(int key, const string& value) 
    {
        for (auto& i : data) //проходимося по всіх значеннях вектора
        {
            if (i.first == key) 
            {
                i.second = value;
                return;
            }
        }
        data.push_back(pair<int, string>(key, value));  //якщо не існує, то створюємо
    }

    void EraseByKey(int key) //видалення
    {
        for (auto i = data.begin(); i != data.end(); i++) //data.begin() i data.end() вказівники на перший і останній елементи вектора
        {
            if (i->first == key)          
            {
                data.erase(i);
                return;
            }
        }
        // якщо в циклі if не спрацював, то значить пари з таким ключем не існує, викидаємо помилку
        throw runtime_error("Key was not found!");
    }

    string Get(int key) const     //пошук
    {
        for (const auto& i : data) 
        {
            if (i.first == key) 
            {
                // якщо так, то повертаємо значення (second)
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