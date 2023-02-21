#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdexcept>
#include "doctest.h"
using namespace std;
//Counting sort is typically used for sorting positive integers within a small range

int FindMax(int* array, int number_of_elements)
{
	int max = array[0];
	for (int j = 1; j < number_of_elements; j++)
	{
		if (array[j] > max)
		{
			max = array[j];
		}
	}
	return max;
}

void Sort(int* array, int* repeated_times, int* result, int size, int number_of_elements)
{
	memset(repeated_times, 0, sizeof(int) * size);

	for (int i = 0; i < number_of_elements; i++)
	{
		if (array[i] < 0) 
		{
			throw invalid_argument("All numbers have to be positive");
		}
		if (int(array[i]) != array[i])
		{
			throw invalid_argument("All numbers have to be integers");
		}

		for (int j = 0; j < size; j++)
		{
			if (array[i] == j)
			{
				repeated_times[j]++;
			}
		}
	}

	int current_index = 0;
	for (int i = 0; i < size; i++)
	{
		if (repeated_times[i] > 0)
		{
			for (int j = repeated_times[i]; j > 0; j--)
			{
					result[current_index] = i;
					current_index++;
			}
		}
	}
}

TEST_CASE("Sorting an array of wrong elements (negative integers)")
{
	int arrayToSort[] = { -4, 9, -9, 3, 6, 5 , 8 , 8 };
	int number_of_elements = sizeof(arrayToSort) / sizeof(arrayToSort[0]);
	const int size = FindMax(arrayToSort, number_of_elements) + 1;
	int* repeated_times = new int[size];
	int* result = new int[size];

	REQUIRE_THROWS(Sort(arrayToSort, repeated_times, result, size, number_of_elements));

	delete[] repeated_times;
	delete[] result;
}

TEST_CASE("Sorting an array of one element")
{
	int arrayToSort[] = { 6 };
	int number_of_elements = sizeof(arrayToSort) / sizeof(arrayToSort[0]);
	const int size = FindMax(arrayToSort, number_of_elements) + 1;
	int* repeated_times = new int[size];
	int* result = new int[size];
	Sort(arrayToSort, repeated_times, result, size, number_of_elements);

	CHECK(result[0] == 6);

	delete[] repeated_times;
	delete[] result;
}

TEST_CASE("Sorting an array of integers")
{
	int arrayToSort[] = { 6, 3, 4, 5, 1, 2, 7, 9, 8, 0 };
	int number_of_elements = sizeof(arrayToSort) / sizeof(arrayToSort[0]);
	const int size = FindMax(arrayToSort, number_of_elements) + 1;
	int* repeated_times = new int[size];
	int* result = new int[size];
	Sort(arrayToSort, repeated_times, result, size, number_of_elements);

	CHECK(result[0] == 0);
	CHECK(result[1] == 1);
	CHECK(result[2] == 2);
	CHECK(result[3] == 3);
	CHECK(result[4] == 4);
	CHECK(result[5] == 5);
	CHECK(result[6] == 6);
	CHECK(result[7] == 7);
	CHECK(result[8] == 8);
	CHECK(result[9] == 9);

	delete[] repeated_times;
	delete[] result;
}