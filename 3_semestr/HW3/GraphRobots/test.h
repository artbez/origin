#pragma once

#include <QtTest/QtTest>
#include "matrix.h"

class Test : public QObject {
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}
private slots:

	void evenCycleTrue()
	{
		int number = 6;
		Matrix myMatrix(number);
		for (int i = 0; i < number; ++i)
			myMatrix.addAdge(i, (i + 1) % number);

		for (int i = 0; i < number; ++i)
			myMatrix.addRobot(i);

		QVERIFY(myMatrix.getResult());
	}

	void evenCycleFalse()
	{
		int number = 6;
		Matrix myMatrix(number);
		for (int i = 0; i < number; ++i)
			myMatrix.addAdge(i, (i + 1) % number);

		for (int i = 0; i < number; i+=2)
			myMatrix.addRobot(i);
		myMatrix.addRobot(1);

		QVERIFY(!myMatrix.getResult());
	}

	void oddCycle()
	{
		int number = 5;
		Matrix myMatrix(number);
		for (int i = 0; i < number; ++i)
			myMatrix.addAdge(i, (i + 1) % number);

		myMatrix.addRobot(0);
		myMatrix.addRobot(1);

		QVERIFY(myMatrix.getResult());
	}

	void graphExample()
	{
		int number = 7;
		Matrix myMatrix(number);
		for (int i = 0; i < number - 2; ++i)
			myMatrix.addAdge(i, i + 1);
		myMatrix.addAdge(4, 6);
		myMatrix.addRobot(0);
		myMatrix.addRobot(4);
		myMatrix.addRobot(1);
		myMatrix.addRobot(6);

		QVERIFY(myMatrix.getResult());
	}
};
