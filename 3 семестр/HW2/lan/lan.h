#pragma once
#include "computer.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

class Lan
{
public:
	Lan(int number);
	~Lan();
	QString getInfo();
	/// The next step
	void update();
	/// Make the connection between computer with number "computer 1"
	/// and computer with number "computer 2"
	void setConnections(int computer1, int computer2);
	/// Spend a virus to computer with number "computer"
	void makeWithVirus(int computer);
private:
	/// Array of computers
	Computer * comps;
	/// Connection's matrix
	bool ** matrix;
	int numberOfComputers;
};
