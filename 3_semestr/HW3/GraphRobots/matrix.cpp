#include "matrix.h"
#include <QQueue>
#include <QDebug>

Matrix::Matrix(int size) : size(size)
{
	isRobot = new bool[size];
	typeMatrix = new int[size];
	for (int i = 0; i < size; ++i)
	{
		isRobot[i] = false;
		typeMatrix[i] = 1;
	}
	adjMatrix = new bool * [size];
	for (int i = 0; i < size; ++i)
	{
		adjMatrix[i] = new bool[size];
		for (int j = 0; j < size; ++j)
			adjMatrix[i][j] = false;
	}
}

Matrix::~Matrix()
{
	delete[] isRobot;
	for (int i = 0; i < size; ++i)
		delete[] adjMatrix[i];
	delete[] adjMatrix;
	delete[] typeMatrix;
}

void Matrix::addAdge(int index1, int index2)
{
	adjMatrix[index1][index2] = true;
	adjMatrix[index2][index1] = true;
}

void Matrix::addRobot(int index)
{
	isRobot[index] = true;
}

void Matrix::separateCells(int start)
{
	QQueue<int> verteces;
	verteces.push_back(start);
	typeMatrix[start] = 2;
	while(!verteces.isEmpty())
	{
		int current = verteces.front();
		verteces.pop_front();
		for (int i = 0; i < size; ++i)
		{
			if (adjMatrix[current][i])
				for (int j = 0; j < size; ++j)
					if (adjMatrix[i][j] && (typeMatrix[j] == 1))
					{
						typeMatrix[j] = 2;
						verteces.push_back(j);
					}
		}
	}
}

bool Matrix::getResult()
{
	separateCells(0);
	int numberOfRobotsType1 = 0;
	int numberOfRobotsType2 = 0;
	for (int i = 0; i < size; ++i)
		if (isRobot[i])
			typeMatrix[i] == 1 ? numberOfRobotsType1++ : numberOfRobotsType2++;
	return (numberOfRobotsType1 != 1 && numberOfRobotsType2 != 1) ;
}
