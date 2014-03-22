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
        ll = new LinkedList();
    }

    void lengthTest()
    {
        QVERIFY(ll->length() == 0);
    }

    void insertTest()
    {
        QString str = "123";
        ll->insert(0, str);
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
        QString str = "";
        for (int i = 0; i < size; ++i)
        {
            str.append(QString::number(i));
            ll->insert(i, str);
        }
        bool areEqual = true;
        QString newStr = "";
        for (int i = 0; i < size; ++i)
        {
            newStr.append(QString::number(i));
            if (ll->get(i) != newStr)
                areEqual = false;
        }
        QVERIFY(areEqual);
    }

    ///find an element
    void findTest()
    {
        QString qStr = "01234";
        int index = ll->find(qStr);
        QVERIFY2(index == 4, "The index is " + index);
    }

    void cleanTest()
    {
        delete ll;
    }

private:
    LinkedList * ll;

};
