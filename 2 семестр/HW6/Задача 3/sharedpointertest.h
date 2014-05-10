#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "sharedpointer.h"
#include <iostream>

class SharedPointerTest: public QObject
{
    Q_OBJECT

public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent){}

private slots:

    void init()
    {
         value = new int(intValue);
    }

    void constructorOfCopyingTest()
    {
        SharedPointer<int> sh(value);
        SharedPointer<int> newSh(sh);
        QVERIFY((*newSh.getPointer()) == intValue);
    }

    void operatorEqualTest()
    {
        SharedPointer<int> sh(value);
        int * newValue = new int(intValue + 42);
        SharedPointer<int> newSh(newValue);
        newSh = sh;
        QVERIFY((*newSh.getPointer()) == intValue);
    }

    void countLinks()
    { 
        SharedPointer<int> sh(value);
        SharedPointer<int> newSh(sh);
        QVERIFY(sh.getCount() == 2);
    }

    void deleteTest()
    {
        SharedPointer<int> sh(value);
        SharedPointer<int> newSh(sh);
        newSh.deleteSharedPointer();
        int answer = sh.getCount();
        QVERIFY(answer == 1 && ((*sh.getPointer()) == intValue));
    }

private:
    const int intValue = 3;
    int * value;
};
