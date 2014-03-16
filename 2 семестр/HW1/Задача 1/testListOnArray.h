#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "listonarray.h"

class TestingListOnArray: public QObject
{
    Q_OBJECT

public:
    explicit TestingListOnArray(QObject *parent = 0) : QObject(parent){}

private slots:
    void intitTest()
    {
        ListOnArray ll;
    }

    void lengthTest()
    {
        ListOnArray ll;
        QVERIFY(ll.length() == 0);
    }

    void insertTest()
    {
        ListOnArray ll;
        ll.insert(0, 1);
        QVERIFY2(ll.length() == 1, "Insert does not work");
    }

    void deleteElementTest()
    {
        ListOnArray ll;
        ll.insert(0, 1);
        ll.deleteElement(0);
        QVERIFY(ll.length() == 0);
    }
};
