#include "operationsystem.h"

OperationSystem::OperationSystem() : name("NoInfo"), probability(0.5)
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

MyWindows::MyWindows()
{
	name = "Windows";
	probability = 0.5;
}

MyLinux::MyLinux()
{
	 name = "Linux";
	 probability = 0.4;
}

MyMac::MyMac()
{
	name = "Macintosh";
	probability = 0.2;
}
