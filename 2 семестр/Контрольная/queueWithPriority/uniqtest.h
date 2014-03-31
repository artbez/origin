#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "queuewithpriority.h"
#include <iostream>

class TestingQueue: public QObject
{
    Q_OBJECT

public:
    explicit TestingQueue(QObject *parent = 0) : QObject(parent){}

private slots:
    void initTestCase()
    {
        qwp = new QueueWithPriority<int>();
    }

    /// test adding element
    void addTest()
    {
        qwp->enqueue(1, 0);
    }

    /// test deleting
    void deleteTest()
    {
        qwp->enqueue(3, 5);
        int newValue = qwp->dequeue();
        QVERIFY(newValue == 3);
    }
    /// create an exception
    void ExceptionTest()
    {
        std::cout << qwp->dequeue() << "\n";
        std::cout << qwp->dequeue() << "\n";
    }

    void cleanupTestCase()
    {
        delete qwp;
    }

private:
    QueueWithPriority<int> * qwp;
};
