#pragma once
#include <QString>

class OperationSystem
{
public:
	OperationSystem();
	void generateById(int id);
	QString getName();
	float getProbability();
private:
	QString name;
	/// Probability to have a virus in time of virus attack
	float probability;
};
