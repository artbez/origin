#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "uniquelist.h"
#include <iostream>

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
        ll->deleteList();
        ll->addToUniqueList(0, 1);
        QVERIFY2(ll->length() == 1, "Insert does not work");
    }

    void deleteElementTest()
    {
        ll->deleteList();
        ll->addToUniqueList(0, 1);
        ll->deleteFromUniqueList(1);
        QVERIFY(ll->length() == 0);
    }

    void exceptionOfAdding()
    {
        try
        {
            ll->addToUniqueList(0, 1);
            ll->addToUniqueList(0, 1);
        }
        catch(MyError::ExceptionOfAdding &)
        {
            std::cout << "This element is already exists\n";
        }
    }

    void exceptionOfDeleting()
    {
        try
        {
            ll->deleteFromUniqueList(0);
            ll->deleteFromUniqueList(0);
        }
        catch(MyError::ExceptionOfDeleting &)
        {
            std::cout << "There is no this element in the list\n";
        }
    }

    void cleanupTestCase()
    {
        delete ll;
    }

private:
    UniqueList * ll;

};
