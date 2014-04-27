#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "sharedpointer.h"

class SharedPointerTest: public QObject
{
    Q_OBJECT

public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent){}

private slots:

    void init()
    {
        value = new int(intValue);
        sh = new SharedPointer<int>(value);
    }

    void constructorOfCopyingTest()
    {
        newSh = new SharedPointer<int>(*sh);
        QVERIFY(*(newSh->getPointer()) == intValue);
        delete newSh;
    }

    void operatorEqualTest()
    {
        int * newValue = new int(intValue + 42);
        newSh = new SharedPointer<int>(newValue);
        *newSh = *sh;
        QVERIFY(*(newSh->getPointer()) == intValue);
        delete newSh;
    }

    void countLinks()
    { 
        newSh = new SharedPointer<int>(*sh);
        QVERIFY(sh->getCount() == 2);
        delete newSh;
    }

    void deleteTest()
    {
        newSh = new SharedPointer<int>(*sh);
        delete newSh;
        int answer = sh->getCount();
        QVERIFY(answer == 1 && (*(sh->getPointer()) == intValue));
    }

    void cleanup()
    {
        delete sh;
    }

private:
    const int intValue = 3;
    int * value;
    SharedPointer<int> * sh;
    SharedPointer<int> * newSh;
};
