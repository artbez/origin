#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "uniquelist.h"

class TestingUniqueLists: public QObject
{
    Q_OBJECT

public:
    explicit TestingUniqueLists(QObject *parent = 0) : QObject(parent){}

private slots:
    void initTestCase()
    {
        ll = new UniqueList();
    }

    void lengthTest()
    {
        QVERIFY(ll->length() == 0);
    }

    void insertTest()
    {
        ll->addToUniqueList(0, 1);
        QVERIFY2(ll->length() == 1, "Insert does not work");
      //  ll->addToUniqueList(0, 1);
    }

    void deleteElementTest()
    {
        ll->deleteFromUniqueList(1);
        QVERIFY(ll->length() == 0);
    }

    void cleanupTestCase()
    {
        delete ll;
    }

private:
    UniqueList * ll;

};
