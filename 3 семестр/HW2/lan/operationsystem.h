#pragma once
#include <QString>

class OperationSystem
{
public:
	OperationSystem();
	QString getName();
	float getProbability();

protected:
	QString name;
	/// Probability to have a virus in time of virus attack
	float probability;
};

class MyWindows : public OperationSystem
{
public:
	MyWindows();
};

class MyLinux : public OperationSystem
{
public:
	MyLinux();
};

class MyMac : public OperationSystem
{
public:
	MyMac();
};
