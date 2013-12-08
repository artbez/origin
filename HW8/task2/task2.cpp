#include <iostream>

using std::cin;
using std::cout;
using std::min;

void deykstra(int vertex, int **&matrix, const int number, bool *&wasHere, int *&marks, int *&position, int &indexOfPosition)
{
	for (int i = 0; i < number; ++i)
	{
		if ((matrix[vertex][i] != 0) && (!wasHere[i]))
		{
			marks[i] = min(marks[i], matrix[vertex][i] + marks[vertex]);
		}
	}

	wasHere[vertex] = true;
	position[indexOfPosition] = vertex;

	int minIndex = -1;
	int curMin = INT_MAX;
	for (int i = 0; i < number; ++i)
	{
		if ((marks[i] < curMin) && (!wasHere[i]))
		{
			minIndex = i;
			curMin = marks[i];
		}
	}

	if (minIndex == -1)
		return;

	deykstra(minIndex, matrix, number, wasHere, marks, position, ++indexOfPosition);
}

int main()
{
	freopen("task2.in", "r", stdin);
	freopen("task2.out", "w", stdout);

	int numberOfCities = 0;
	cin >> numberOfCities;
	int numberOfRoads = 0;
	cin >> numberOfRoads;

	const int size = 100;
	int ** matrix = new int * [size]; 
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < numberOfRoads; ++i)
	{
		int vertex1 = 0;
		int vertex2 = 0;
		int len = 0;
		cin >> vertex1;
		cin >> vertex2;
		cin >> len;

		matrix[vertex1 - 1][vertex2 - 1] = len;
		matrix[vertex2 - 1][vertex1 - 1] = len;
	}

	bool * wasHere = new bool[size];
	int * marks = new int[size];
	int * position = new int[size];
	int indexOfPosition = 0;

	for (int i = 0; i < size; ++i)
	{
		wasHere[i] = false;
		marks[i] = INT_MAX;
		position[i] = -1;
	}

	marks[0] = 0;

	deykstra(0, matrix, numberOfCities, wasHere, marks, position, indexOfPosition);
	for (int i = 0; i < numberOfCities; ++i)
	{
		cout << position[i] + 1 << " ";
	}

	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] wasHere;
	delete[] marks;
	delete[] position;

	return 0;
}