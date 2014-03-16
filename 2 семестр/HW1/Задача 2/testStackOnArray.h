#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "stackonarray.h"

class TestingStackOnArray: public QObject
{
    Q_OBJECT

public:
    explicit TestingStackOnArray(QObject *parent = 0) : QObject(parent){}

private slots:
    void intitTest()
    {
        StackOnArray ll;
    }

    void lengthTest()
    {
        StackOnArray ll;
        QVERIFY(ll.length() == 0);
    }

    void insertTest()
    {
        StackOnArray ll;
        ll.push(1);
        QVERIFY2(ll.length() == 1, "Insert does not work");
    }

    void deleteElementTest()
    {
        StackOnArray ll;
        ll.push(1);
        ll.pop();
        QVERIFY(ll.length() == 0);
    }
};
