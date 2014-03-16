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
    void intitTest()
    {
        LinkedList ll;
    }

    void lengthTest()
    {
        LinkedList ll;
        QVERIFY(ll.length() == 0);
    }

    void insertTest()
    {
        LinkedList ll;
        ll.insert(0, 1);
        QVERIFY2(ll.length() == 1, "Insert does not work");
    }

    void deleteElementTest()
    {
        LinkedList ll;
        ll.insert(0, 1);
        ll.deleteElement(0);
        QVERIFY(ll.length() == 0);
    }
};
