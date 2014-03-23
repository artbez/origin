#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "linkedlist.h"

class TestingLinkedLists: public QObject
{
    Q_OBJECT

public:
    explicit TestingLinkedLists(QObject *parent = 0) : QObject(parent){}

private slots:
    void initTestCase()
    {
        ll = new LinkedList();
    }

    void lengthTest()
    {
        QVERIFY(ll->length() == 0);
    }

    void insertTest()
    {
        ll->insert(0, 1);
        QVERIFY2(ll->length() == 1, "Insert does not work");
    }

    void deleteElementTest()
    {
        ll->deleteElement(0);
        QVERIFY(ll->length() == 0);
    }

    ///addition some elements
    void insertElementsTest()
    {
        const int size = 10;
        for (int i = 0; i < size; ++i)
            ll->insert(i, i);
        bool areEqual = true;
        for (int i = 0; i < size; ++i)
            if (ll->get(i) != i)
                areEqual = false;
        QVERIFY(areEqual);
    }

    void cleanupTestCase()
    {
        delete ll;
    }

private:
    LinkedList * ll;

};
