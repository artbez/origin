#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "set.h"

class TestingSet: public QObject
{
    Q_OBJECT

public:
    explicit TestingSet(QObject *parent = 0) : QObject(parent){}

private slots:

    void addTest()
    {
        mySet.addElement(1);
    }

    void isExistTest()
    {
        mySet.addElement(42);
        QVERIFY(mySet.isExistElement(42) && !mySet.isExistElement(43));
    }

    void deleteElementTest()
    {
        mySet.addElement(666);
        mySet.deleteElement(666);
        QVERIFY(!mySet.isExistElement(666));
    }

    void intersectWithSetTest()
    {
        Set<int> newSet;
        newSet.addElement(1);
        newSet.addElement(2);
        mySet.addElement(1);
        mySet.intersectWithSet(newSet);
        QVERIFY(mySet.isExistElement(1) && !mySet.isExistElement(2));
    }

    void unionWithSetTest()
    {
        Set<int> newSet;
        newSet.addElement(3);
        newSet.addElement(4);
        mySet.addElement(3);
        mySet.unionWithSet(newSet);
        QVERIFY(mySet.isExistElement(3) && mySet.isExistElement(4));
    }

private:
    Set<int> mySet;
};
