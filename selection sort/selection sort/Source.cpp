#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdexcept>
#include "doctest.h"
using namespace std;
//Selection sort is typically used for sorting small arrays. When memory space is limited

void Sort(int* array, int size)
{
	for (int j = 0; j < size; j++)
	{
		int min = array[j];
		int min_index = j;
		for (int i = j+1; i < size; i++)
		{
			if (array[i] < min)
			{
				min = array[i];
				min_index = i;
			}
		}
		if (min_index != j)
		{
			int temp = array[j];
			array[j] = array[min_index];
			array[min_index] = temp;
		}
	}
}

TEST_CASE("Sorting 4 integers")
{
	int unsorted_array[] = { 2, -3, 1, 0 };
	int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]);
	Sort(unsorted_array, size);

	CHECK(unsorted_array[0] == -3);
	CHECK(unsorted_array[1] == 0);
	CHECK(unsorted_array[2] == 1);
	CHECK(unsorted_array[3] == 2);
}
TEST_CASE("Sorting already sorted array")
{
	int sorted_array[] = { -3, 0, 1 };
	int size = sizeof(sorted_array) / sizeof(sorted_array[0]);
	Sort(sorted_array, size);

	CHECK(sorted_array[0] == -3);
	CHECK(sorted_array[1] == 0);
	CHECK(sorted_array[2] == 1);
}

TEST_CASE("Sorting only 1 number")
{
	int unsorted_array[] = { 1 };
	int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]);
	Sort(unsorted_array, size);

	CHECK(unsorted_array[0] == 1);
}

TEST_CASE("Sorting array with duplicates")
{
	int unsorted_array[] = { 9, 2, -3, 1, 0, 2, -3, 9 };
	int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]);
	Sort(unsorted_array, size);

	CHECK(unsorted_array[0] == -3);
	CHECK(unsorted_array[1] == -3);
	CHECK(unsorted_array[2] == 0);
	CHECK(unsorted_array[3] == 1);
	CHECK(unsorted_array[4] == 2);
	CHECK(unsorted_array[5] == 2);
	CHECK(unsorted_array[6] == 9);
	CHECK(unsorted_array[7] == 9);
}
