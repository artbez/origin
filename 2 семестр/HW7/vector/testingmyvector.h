#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "myvector.h"

class TestingMyVector: public QObject
{
    Q_OBJECT

public:
    explicit TestingMyVector(QObject *parent = 0) : QObject(parent){}

private slots:

    void initTestCase()
    {
        for (int i = 0; i < dimention; ++i)
            qVect.push_back(i);
    }

    void init()
    {
        myVect = new MyVector<int, 5, 0>(qVect);
    }

    void testCostructor()
    {
        bool correct = true;
        for (int i = 0; i < dimention; ++i)
            if (myVect->getElementByIndex(i) != qVect.at(i))
                correct = false;

        QVERIFY(correct);
    }

    void testCopyingConstructor()
    {
        bool correct = true;
        MyVector<int, 5, 0> newMyVector(*myVect);
        for (int i = 0; i < dimention; ++i)
            if (myVect->getElementByIndex(i) != newMyVector.getElementByIndex(i))
                correct = false;

        QVERIFY(correct);
    }

    void testAddition()
    {
        QVector<int> newQVect;
        for (int i = 0; i < dimention; ++i)
            newQVect.push_back(i + 10);

        MyVector<int, 5, 0> newMyVector(newQVect);
        MyVector<int, 5, 0> result(*myVect + newMyVector);
        bool correct = true;
        for (int i = 0; i < dimention; ++i)
            if (result.getElementByIndex(i) !=
                    (myVect->getElementByIndex(i) + newMyVector.getElementByIndex(i)))
                    correct = false;

        QVERIFY(correct);
    }

    void testSubtraction()
    {
        QVector<int> newQVect;
        for (int i = 0; i < dimention; ++i)
            newQVect.push_back(i + 10);

        MyVector<int, 5, 0> newMyVector(newQVect);
        MyVector<int, 5, 0> result(*myVect - newMyVector);
        bool correct = true;
        for (int i = 0; i < dimention; ++i)
            if (result.getElementByIndex(i) !=
                    (myVect->getElementByIndex(i) - newMyVector.getElementByIndex(i)))
                    correct = false;

        QVERIFY(correct);
    }

    void testMultiplication()
    {
        QVector<int> newQVect;
        for (int i = 0; i < dimention; ++i)
            newQVect.push_back(i + 1);

        MyVector<int, 5, 0> newMyVector(newQVect);
        int result = newMyVector * (*myVect);
        QVERIFY(result == 40);
    }

    void testEquals()
    {
        MyVector<int, 5, 0> newMyVect(*myVect);
        QVERIFY(newMyVect == *myVect);
    }

    void testIsNotZero()
    {
        QVERIFY(!myVect->isZero());
    }

    void testIsZero()
    {
        for (int i = 0; i < dimention; ++i)
            myVect->insert(i, 0);
        QVERIFY(myVect->isZero());
    }

    void cleanup()
    {
        delete myVect;
    }

private:
    const int dimention = 5;
    QVector<int> qVect;
    MyVector<int, 5, 0> * myVect;
};
