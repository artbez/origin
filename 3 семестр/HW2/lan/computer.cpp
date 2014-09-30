#include "computer.h"

Computer::Computer() : status(false)
{
	srand(time(NULL));
}

void Computer::setStatus(bool newStatus)
{
	status = newStatus;
}

void Computer::setNumber(int newNumber)
{
	number = newNumber;
}

bool Computer::getStatus()
{
	return status;
}

void Computer::setOperationSystemById(int id)
{
	os.generateById(id);
}

QString Computer::getInfo()
{
	QString info = "Computer has number = " + QString::number(getNumber())
			+ ". Operation System is " + os.getName() + ". "
			+ (status ? "With a virus." : "Without any viruses.");
	return info;
}

int Computer::getNumber()
{
	return number;
}

bool Computer::virusAttack()
{
	int curPos = rand() % 100 + 1;
	if (curPos <= (os.getProbability() * 100))
		return true;
	return false;
}
