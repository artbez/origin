#include "operationsystem.h"

OperationSystem::OperationSystem()
	: name("Windows"), probability (0.4)
{
}

QString OperationSystem::getName()
{
	return name;
}

float OperationSystem::getProbability()
{
	return probability;
}

void OperationSystem::generateById(int id)
{
	if (id == 0)
	{
		name = "Windows";
		probability = 0.5;
	}
	if (id == 1)
	{
		name = "Linux";
		probability = 0.4;
	}
	if (id == 2)
	{
		name = "Macintosh";
		probability = 0.3;
	}
}

