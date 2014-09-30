#pragma once
#include "operationsystem.h"
#include <QString>
#include <stdlib.h>
#include <time.h>

/// Class describe a computer in the Lan
class Computer
{
public:
	Computer();
	void setStatus(bool newStatus);
	bool getStatus();
	QString getInfo();
	int getNumber();
	void setNumber(int newNumber);
	/// if a virus try to attack the computer
	bool virusAttack();
	/// Based on the id choose an operation system
	void setOperationSystemById(int id);
private:
	OperationSystem os;
	/// true if it is with virus
	bool status;
	/// number of the computer
	int number;
};
