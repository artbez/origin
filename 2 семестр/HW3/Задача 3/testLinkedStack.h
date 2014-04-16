#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "linkedstack.h"

class TestingLinkedStack: public QObject
{
    Q_OBJECT

public:
    explicit TestingLinkedStack(QObject *parent = 0) : QObject(parent){}

private slots:
    void init()
    {
        ll = new LinkedStack();
    }

    void lengthTest()
    {
        QVERIFY(ll->length() == 0);
    }

    void insertTest()
    {
        ll->push(1);
        QVERIFY2(ll->length() == 1, "Push does not work");
    }

    void deleteElementTest()
    {
        ll->push(1);
        ll->pop();
        QVERIFY(ll->length() == 0);
    }

    ///addition some elements
    void insertElementsTest()
    {
        const int size = 10;
        for (int i = 0; i < size; ++i)
            ll->push(i);
        bool areEqual = true;
        for (int i = 0; i < size; ++i)
        {
            if (ll->getFirst() != size - i - 1)
                areEqual = false;
            ll->pop();
        }
        QVERIFY(areEqual);
    }

    void claenup()
    {
        delete ll;
    }

private:
    LinkedStack * ll;

};
