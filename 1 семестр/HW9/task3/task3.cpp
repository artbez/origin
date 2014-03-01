#include <iostream>

using std::cin;
using std::cout;

struct Pair
{
	int first;
	int second;
};

int **& toOstThree(int **&matrix, const int number, const int size)
{

	int ** answer = new int * [size];
	for (int i = 0; i < size; ++i)
	{
		answer[i] = new int[size];
		for (int j = 0; j < size; ++j)
		{
			answer[i][j] = 0;
		}
	}

	bool *wasHere = new bool[size];
	Pair *distance = new Pair[size];
	for (int i = 0; i < size; ++i)
	{
		wasHere[i] = false;
		distance[i].first = INT_MAX;
		distance[i].second = -1;
	}

	int curVertex = 0;

	bool flag = true;
	while (flag)
	{
		wasHere[curVertex] = true;

		int minIndex = -1;
		int min = INT_MAX;
		for (int i = 0; i < number; ++i)
		{
			if (!wasHere[i])
			{
				if (matrix[curVertex][i] < distance[i].first && matrix[curVertex][i] != 0)
				{
					distance[i].first = matrix[curVertex][i];
					distance[i].second = curVertex;
				}

				if (distance[i].first < min)
				{
					min = distance[i].first;
					minIndex = i;
				}
			}
		}
		if (minIndex != -1)
		{
			answer[distance[minIndex].second][minIndex] = distance[minIndex].first;
			answer[minIndex][distance[minIndex].second] = distance[minIndex].first;
			
			curVertex = minIndex;
		}
		else
		{
			flag = false;
		}
	}

	delete[] wasHere;
	delete[] distance;

	return answer;
}

int main()
{
	freopen("task3.in", "r", stdin);
	freopen("task3.out", "w", stdout);

	int numberOfVertexes;
	cin >> numberOfVertexes;

	const int size = 100;
	int **matrix = new int * [size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size];
	}

	for (int i = 0; i < numberOfVertexes; ++i)
	{
		for (int j = 0; j < numberOfVertexes; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	
	int **newMatrix = toOstThree(matrix, numberOfVertexes, size);
	
	for (int i = 0; i < size; ++i)
		delete[] matrix[i];

	delete[] matrix;
	
	for (int i = 0; i < numberOfVertexes; ++i)
	{
		for (int j = 0; j < numberOfVertexes; ++j)
		{
			cout << newMatrix[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < size; ++i)
		delete[] newMatrix[i];

	delete[] newMatrix;
	
	return 0;
}