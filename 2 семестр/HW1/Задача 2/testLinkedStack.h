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
    void intitTest()
    {
        LinkedStack ll;
    }

    void lengthTest()
    {
        LinkedStack ll;
        QVERIFY(ll.length() == 0);
    }

    void insertTest()
    {
        LinkedStack ll;
        ll.push(1);
        QVERIFY2(ll.length() == 1, "Push does not work");
    }

    void deleteElementTest()
    {
        LinkedStack ll;
        ll.push(1);
        ll.pop();
        QVERIFY(ll.length() == 0);
    }
};
