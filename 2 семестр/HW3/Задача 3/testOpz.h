#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "toOpz.h"
#include "calculateByOpz.h"

class TestingOpz: public QObject
{
    Q_OBJECT

public:
    explicit TestingOpz(QObject *parent = 0) : QObject(parent){}

private slots:
    void sum1()
    {
        QVERIFY(calculateByOpz(toOpz("2+1")) == 3);
    }

    void move1()
    {
        QVERIFY(calculateByOpz(toOpz("2*8")) == 16);
    }

    void twoOperations()
    {
        QVERIFY(calculateByOpz(toOpz("2+2*2")) == 6);
    }

    void withBrackets()
    {
        QVERIFY(calculateByOpz(toOpz("2*(2+2)")) == 8);
    }

    void includedBrackets()
    {
        QVERIFY(calculateByOpz(toOpz("(2*(2+2)-3)*4")) == 20);
    }

    void parallelBrackets()
    {
        QVERIFY(calculateByOpz(toOpz("(2+2)*(3+3)*(1-2)")) == -24);
    }

  };
