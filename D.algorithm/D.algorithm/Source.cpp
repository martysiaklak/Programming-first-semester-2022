#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include<iostream>
#include<queue>
#include<stack>
#include <limits>

using namespace std;

class Graph 
{
private:
	int** matrix;
	int vCount; //кількість вершин
	int* key;
	int* distance;
	int* parent;

	void initial()
	{
		for (int i = 0; i < vCount; i++) {
			key[i] = 0; // 0=not, 1=yes
			distance[i] = INT_MAX; // ∞
			parent[i] = -1;
		}
	}

	int isAllKeyTrue()  //0 means not MST, 1 means MST
	{
		for (int i = 0; i < vCount; i++) 
		{
			if (key[i] == 0)
				return 0; // not MST yet
		}
		return 1; // MST done
	}
public:
	//граф
	Graph(int vcount)//конструктор(задаємо кількість вершин)
	{
		vCount = vcount;
		key = new int[vCount];
		distance = new int[vCount];
		parent = new int[vCount];
		matrix = new int* [vCount];
		for (int i = 0; i < vCount; i++)
		{
			matrix[i] = new int[vCount];
			for (int j = 0; j < vCount; j++)
				matrix[i][j] = 0;
		}
	};
	void add(int r, int c, int elem)//заносимо значення елемента в матрицю(задаємо рядок, стовпчик, значення елемента)
	{
		if (r >= 0 && r < vCount && c >= 0 && c < vCount)
		{
			matrix[r][c] = elem;
		}
	}
	void remove(int r, int c)//видаляємо елемент з матриці
	{
		if (r >= 0 && r < vCount && c >= 0 && c < vCount)
		{
			matrix[r][c] = 0;
			matrix[c][r] = 0;//бо матриця симетрична
		}
	}
	int search(int r, int c)//шукаємо елемент
	{
		if (r >= 0 && r < vCount && c >= 0 && c < vCount)
			return matrix[r][c];
		else
			return 0;
	}

	//алгоритм 
	int findMinDistanceNode()//шукаємо вершину, від якої є найкоротша відстань
	{
		int minDist = INT_MAX;
		int minDistantNode;
		for (int i = 0; i < vCount; i++) 
		{
			if (minDist > distance[i] && key[i] == 0)
			{
				minDistantNode = i;
				minDist = distance[i];
			}
		}
		return minDistantNode;
	}
	int Dijkstra() //Застосовує алгоритм Дейкстри для знаходження найкоротших шляхів в графі. Спочатку ініціалізуємо значення початкової вершини.
	{
		initial();
		distance[0] = 0;
		while (!isAllKeyTrue())
		{
			int minDistanceNode = findMinDistanceNode();
			key[minDistanceNode] = 1;  // this node's shortes path is done
			cout << "Shortest Path: " << parent[minDistanceNode] << "->" << minDistanceNode << ", Destination Node's cost is: " << distance[minDistanceNode] << "\n";
			for (int i = 0; i < vCount; i++) {
				if (search(minDistanceNode, i) && key[i] == 0) {
					if (distance[i] > distance[minDistanceNode] + matrix[minDistanceNode][i])
					{
						distance[i] = distance[minDistanceNode] + matrix[minDistanceNode][i];
						parent[i] = minDistanceNode;
					}
				}
			}
			return distance[minDistanceNode];
		}
	}
	~Graph()
	{
		for (int i = 0; i < vCount; i++)
			delete[] matrix[i];
		delete[] matrix;
		delete[] parent;
		delete[] distance;
		delete[] key;
	}
};
TEST_CASE("Test 1: Adding and removing nodes") 
{
	Graph g(3);
	g.add(0, 1, 2);
	g.add(1, 2, 3);
	CHECK(g.search(0, 1) == 2);
	CHECK(g.search(1, 2) == 3);
	g.remove(1, 2);
	CHECK(g.search(1, 2) == 0);
}

TEST_CASE("Test 2: Dijkstra algorithm") 
{
	Graph g(5);
	g.add(0, 1, 10);
	g.add(0, 4, 5);
	g.add(1, 2, 1);
	g.add(1, 4, 2);
	g.add(2, 3, 4);
	g.add(3, 2, 6);
	g.add(3, 0, 7);
	g.add(4, 1, 3);
	g.add(4, 2, 9);
	g.add(4, 3, 2);

}

