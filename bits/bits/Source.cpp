#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
using namespace std;

class Set
{
private:
	char a[5];
public:
	Set()
	{
		for (size_t i = 0; i < 5; i++)
		{
			a[i] = 0;
		}
	}
	void insert(char elem)
	{
		int index;
		if (elem >= 'a' && elem <= 'z')   //якщо буква
			index = elem - 'a';
		else
			index = elem + 26 - '0';     //якщо цифра
		//Отриманий індекс використовується для визначення, в якому окремому біті масиву a зберігається інформація про наявність елемента в множині
		a[index / 8] |= (1 << (7 - index % 8));
	}
	void remove(char elem)
	{
		int index;
		if (elem >= 'a' && elem <= 'z')
			index = elem - 'a';
		else
			index = elem + 26 - '0';
		//Операція &= використовується для виконання побітового "і з присвоєнням", щоб обнулити відповідний біт в масиві a
		a[index / 8] &= ~(1 << (7 - index % 8));
	}
	bool contains(char elem)
	{
		int index;
		if (elem >= 'a' && elem <= 'z')
			index = elem - 'a';
		else
			index = elem + 26 - '0';
		return a[index / 8] & (1 << (7 - index % 8));
	}
	void intersect(Set other)
	{
		for (size_t i = 0; i < 5; i++)
		{
			//для кожного біта на відповідних позиціях обох масивів, результат буде 1 тільки в тому випадку, 
			//якщо на цих позиціях обидва біти були встановлені в 1
			a[i] &= other.a[i];
		}
	}
	void unionWith(Set other)
	{
		for (size_t i = 0; i < 5; i++)
		{
			a[i] |= other.a[i];
		}
	}
};

TEST_CASE("Insert and Contains")
{
	Set set;
	set.insert('a');
	set.insert('b');
	set.insert('1');
	CHECK(set.contains('a') == true);
	CHECK(set.contains('b') == true);
	CHECK(set.contains('1') == true);
	CHECK(set.contains('c') == false);
}

TEST_CASE("Insert and Remove")
{
	Set set;
	set.insert('a');
	set.insert('b');
	set.remove('a');
	set.remove('c');
	CHECK(set.contains('a') == false);
	CHECK(set.contains('b') == true);
	CHECK(set.contains('c') == false);
}

TEST_CASE("Intersection")
{
	Set set1;
	set1.insert('a');
	set1.insert('b');
	set1.insert('1');

	Set set2;
	set2.insert('b');
	set2.insert('c');

	set1.intersect(set2);
	CHECK(set1.contains('a') == false);
	CHECK(set1.contains('b') == true);
	CHECK(set1.contains('1') == false);
	CHECK(set1.contains('c') == false);
}

TEST_CASE("Union")
{
	Set set1;
	set1.insert('a');
	set1.insert('b');
	set1.insert('1');

	Set set2;
	set2.insert('b');
	set2.insert('c');

	set1.unionWith(set2);
	CHECK(set1.contains('a') == true);
	CHECK(set1.contains('b') == true);
	CHECK(set1.contains('1') == true);
	CHECK(set1.contains('c') == true);
}

