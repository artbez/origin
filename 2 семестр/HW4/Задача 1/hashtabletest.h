#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "myhashtable.h"

class TestingHashTable: public QObject
{
    Q_OBJECT

public:
    explicit TestingHashTable(QObject *parent = 0) : QObject(parent){}

private slots:
    void initTest()
    {
        myHash = new MyHashTable(curHash, size);
    }

    /// add an element to hashTable
    void addTest()
    {
        QString qStr = "123";
        myHash->add(qStr);
    }

    /// check if is an element included
    void containsTest()
    {
        QString qStr = "123";
        QVERIFY(myHash->contains(qStr));
    }

    void deleteElementTest()
    {
        QString qStr = "123";
        myHash->del(qStr);
        QVERIFY(!myHash->contains(qStr));
    }

    /// Change hash function test
    void changeHashFucnctionTest()
    {
        QString str = "1234";
        myHash->add(str);
        int firstValue = myHash->getHash(str);
        myHash->selectHashFunction(1, 3333);
        int secondValue = myHash->getHash(str);
        QVERIFY(firstValue != secondValue);
    }

    void deleteTableTest()
    {
        delete myHash;
    }


private:
    const int size = 7777;
    int curHash = 0;
    MyHashTable * myHash;
};
