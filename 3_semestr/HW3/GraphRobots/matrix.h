#pragma once

class Matrix
{
public:
	Matrix(int size);
	~Matrix();
	bool getResult();
	void addAdge(int index1, int index2);
	void addRobot(int index);

private:
	void separateCells(int start);
	void calculateNumberOfRobots(int type);

	int size;
	bool * isRobot;
	int * typeMatrix;
	bool ** adjMatrix;
};
