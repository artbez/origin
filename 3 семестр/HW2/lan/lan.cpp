#include "lan.h"

Lan::Lan(int number) : numberOfComputers(number)
{
	srand(time(NULL));
	comps = new Computer[numberOfComputers];
	for (int i = 0; i < numberOfComputers; ++i)
	{
		comps[i].setNumber(i);
		int id = rand() % 3;
		comps[i].setOperationSystemById(id);
	}
	matrix = new bool * [numberOfComputers];
	for (int i = 0; i < numberOfComputers; ++i)
	{
		matrix[i] = new bool[numberOfComputers];
		for (int j = 0; j < numberOfComputers; ++j)
			matrix[i][j] = false;
	}
}

Lan::~Lan()
{
	delete[] comps;
	for (int i = 0; i < numberOfComputers; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

void Lan::makeWithVirus(int computer)
{
	comps[computer].setStatus(true);
}

void Lan::setConnections(int computer1, int computer2)
{
	matrix[computer1][computer2] = true;
	matrix[computer2][computer1] = true;
}

QString Lan::getInfo()
{
	QString info = "There are " + QString::number(numberOfComputers) + " comupters.\n";
	for (int i = 0; i < numberOfComputers; ++i)
	{
		info.append(comps[i].getInfo() + "\n");
	}
	return info;
}

void Lan::update()
{
	bool newIllComputers[numberOfComputers];
	for (int i = 0; i < numberOfComputers; ++i)
		newIllComputers[i] = false;

	for (int i = 0; i < numberOfComputers; ++i)
	{
		/// status = is computer i with a virus
		if (comps[i].getStatus())
		{
			for (int j = 0; j < numberOfComputers; ++j)
				if (matrix[i][j] && comps[j].virusAttack())
					newIllComputers[j] = true;
		}
	}

	for (int i = 0; i < numberOfComputers; ++i)
		if (newIllComputers[i])
			comps[i].setStatus(true);
}
