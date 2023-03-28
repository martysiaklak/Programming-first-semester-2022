#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>

using namespace std;
const int TABLE_SIZE = 128;    //одразу визначаю максимальну м≥стк≥сть

template<typename T>       //значенн€ можуть бути р≥зних тип≥в
class HashEntry
{
private:
    int key;
    T value;
public:

    HashEntry(int key, T value)
    {
        this->key = key;
        this->value = value;
    }

    int getKey()
    {
        return key;
    }

    T getValue()
    {
        return value;
    }
};

template<typename T>
class HashMap
{
private:
    //динам≥чно створена двовим≥рна матриц€, де кожен р€док м≥стить вказ≥вник на об'Їкт типу HashEntry<T>
    HashEntry<T>** table;          
public:
    HashMap()
    {
        table = new HashEntry<T>*[TABLE_SIZE];    
        for (int i = 0; i < TABLE_SIZE; i++)      //створюЇмо масив  ≥ занулюЇмо
        {
            table[i] = NULL;           
        }
    }
    
    void insert(int key, T value)
    {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)  //€кщо м≥сце зайн€те, то шукаЇмо нове
        {
            hash = (hash + 1) % TABLE_SIZE;
        }
        table[hash] = new HashEntry<T>(key, value); //додаЇмо в таблицю
    }

    void remove(int key)
    {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL)
        {
            if (table[hash]->getKey() == key)
            {
                delete table[hash];
                table[hash] = NULL;
                return;
            }
            hash = (hash + 1) % TABLE_SIZE;
        }
    }

    T search(int key)     //метод пошуку
    {
        int hash = (key % TABLE_SIZE);      //обчислюЇмо хеш
        while (table[hash] != NULL && table[hash]->getKey() != key)
        {
            hash = (hash + 1) % TABLE_SIZE;  //шукаЇмо за наступним хешем
        }
        if (table[hash] == NULL)
        {
            throw runtime_error("Key was not found!");         //€кщо не знайдено
        }
        else
        {
            return table[hash]->getValue();
        }
    }

    ~HashMap()

    {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
            {
                delete table[i];
            }
        delete[] table;
    }
};
TEST_CASE("Insertion and search")
{
    HashMap<string> hash_map;
    hash_map.insert(1, "One");
    hash_map.insert(2, "Two");
    hash_map.insert(3, "Three");

    CHECK(hash_map.search(1) == "One");
    CHECK(hash_map.search(2) == "Two");
    CHECK(hash_map.search(3) == "Three");
}

TEST_CASE("Remove")
{
    HashMap<string> hash_map;
    hash_map.insert(1, "One");
    hash_map.insert(2, "Two");
    hash_map.insert(3, "Three");

    hash_map.remove(2);
    CHECK_THROWS(hash_map.search(2));
}

TEST_CASE("Exception on search")
{
    HashMap<string> hash_map;
    hash_map.insert(1, "One");
    hash_map.insert(2, "Two");
    hash_map.insert(3, "Three");

    CHECK_THROWS(hash_map.search(4));
}

TEST_CASE("Insertion and search")
{
    HashMap<int> map;
    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    CHECK(map.search(1) == 10);
    CHECK(map.search(2) == 20);
    CHECK(map.search(3) == 30);
}