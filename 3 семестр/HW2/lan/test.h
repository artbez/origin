#pragma once

#include <QtTest/QtTest>
#include "lan.h"

class Test : public QObject {
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}
private slots:

	void AllWithConnection() {
		const int n = 2;
		Lan myLan(n);

		for (int i = 0; i < n; ++i)
			myLan.setConnections(i, (i + 1) % n);

		myLan.makeWithVirus(0);

		bool flag = false;
		while(!flag)
		{
			flag = true;
			myLan.update();

			for (int i = 0; i < n; ++i)
				flag = flag && myLan.comps[i].getStatus();
		}
	}

	void OneWithoutConnection()
	{
		const int n = 5;
		Lan myLan(n);

		for (int i = 0; i < n - 2; ++i)
			myLan.setConnections(i, i + 1);

		myLan.makeWithVirus(0);

		for (int i = 0; i < n * 100000; ++i)
			myLan.update();

		QVERIFY(!myLan.comps[n - 1].getStatus());
	}
};
