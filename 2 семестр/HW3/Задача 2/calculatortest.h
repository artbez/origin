#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "calculator.h"

class TestingCalculator: public QObject
{
    Q_OBJECT

public:
    explicit TestingCalculator(QObject *parent = 0) : QObject(parent){}

private slots:
    void initTestCase()
    {
        calc = new Calculator();
    }
    void sumTest()
    {
        QVERIFY(calc->calculate(4, 3, '+') == QString::number(7));
    }
    void moveTest()
    {
        QVERIFY(calc->calculate(4, 3, '*') == QString::number(12));
    }
    void minesTest()
    {
        QVERIFY(calc->calculate(4, 3, '-') == QString::number(1));
    }
    void devTest()
    {
        QVERIFY(calc->calculate(12, 4, '/') == QString::number(3));
    }
    void devByZeroTest()
    {
        QVERIFY(calc->calculate(12, 0, '/') == "Error");
    }
    void cleanupTestCase()
    {
        delete calc;
    }

private:
    Calculator * calc;
};
