#include <iostream>
#include <QDebug>
#include "lan.h"

int main()
{
	int number = 0;
	qDebug() << "Enter number of computers";
	std::cin >> number;

	Lan * lan = new Lan(number);

	for (int i = 0; i < number; ++i)
	{
		qDebug() << "Enter number of computers which have connections with computer "
					 + QString::number(i);
		int curNumber = 0;
		std::cin >> curNumber;
		if (curNumber != 0)
		{
			qDebug() << "Enter numbers of computers which have connections with computer "
						 + QString::number(i);
			for (int j = 0; j < curNumber; ++j)
			{
				int numberOfCurr = 0;
				std::cin >> numberOfCurr;
				lan->setConnections(i, numberOfCurr);
			}
		}
	}

	int numberWithViruses = 0;
	qDebug() << "Enter number of computers with viruses";
	std::cin >> numberWithViruses;
	if (numberWithViruses != 0)
	{
		qDebug() << "Enter numbers of computers which have viruses";
		for (int i = 0; i < numberWithViruses; ++i)
		{
			int numberOfCurr = 0;
			std::cin >> numberOfCurr;
			lan->makeWithVirus(numberOfCurr);
		}
	}


	bool flag = true;
	while(flag)
	{
		qDebug() << "1. Say information";
		qDebug() << "2. Next step";
		qDebug() << "3. Quit";
		int choice;
		std::cin >> choice;
		if (choice == 1)
			qDebug() << lan->getInfo();
		if (choice == 2)
			lan->update();
		if (choice == 3)
			flag = false;
		qDebug() << "\n";
	}

	delete lan;
	return 0;
}
