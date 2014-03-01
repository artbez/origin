#include <iostream>

using std::cin;
using std::cout;

void dfs (int vertex, bool **&matrix, bool *&wasHere, int number, int &mark, char *&answer)
{
	answer[vertex] = 'a' + mark;
	wasHere[vertex] = true;
	for (int i = 0; i < number; ++i)
	{
		if ((matrix[vertex][i]) && (!wasHere[i]))
		{
			dfs(i, matrix, wasHere, number, ++mark, answer);
		}
	}
}

int main()
{
	freopen("task1.in", "r", stdin);
	freopen("task1.out", "w", stdout);
	int number = 0;
	cin >> number;

	int vertex = 0;
	cin >> vertex;

	const int size = 100;
	bool **matrix = new bool * [size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new bool[size]; 
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = false;
		}
	}

	int numberOfD = 0;
	cin >> numberOfD;

	for (int i = 0; i < numberOfD; ++i)
	{
		int vertex1 = 0;
		cin >> vertex1;
		int vertex2 = 0;
		cin >> vertex2;
		matrix[vertex1][vertex2] = true;
		matrix[vertex2][vertex1] = true;
	}

	bool * wasHere = new bool[size];
	char * answer = new char[size];

	for (int i = 0; i < size; ++i)
	{
		wasHere[i] = false;
		answer[i] = '#';
	}

	int mask = 0;
	dfs(vertex, matrix, wasHere, number, mask, answer);

	for (int i = 0; i < number; ++i)
	{
		cout << answer[i] << " ";
	}

	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	delete[] wasHere;
	delete[] answer;
	return 0;
}