#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "bag.h"

class TestingBag: public QObject
{
    Q_OBJECT

public:
    explicit TestingBag(QObject *parent = 0) : QObject(parent){}

private slots:
    void init()
    {
        bag = new Bag<int>();
    }

    void addTest()
    {
        bag->addToBag(3);
    }

    void containsTest()
    {
        bag->addToBag(3);
        QVERIFY(bag->findInBag(3));
    }

    void addSomeElementsTest()
    {
        bag->addToBag(3);
        bag->addToBag(3);
        QVERIFY(bag->numberOfElements(3) == 2);
    }

    void deleteTest()
    {
        bag->addToBag(3);
        bag->deleteFromBag(3);
        QVERIFY(!bag->findInBag(3));
    }

    void cleanup()
    {
        delete bag;
    }

private:
    Bag<int> * bag;
};
