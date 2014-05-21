#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <iostream>
#include "bublesort.h"
#include "intcomporator.h"
#include "stringcomporator.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;

class Tests: public QObject
{
    Q_OBJECT

public:
    explicit Tests(QObject *parent = 0) : QObject(parent){}

private slots:
    /// Testing buble sort with ints
    void intTest()
    {
        const int size = 10;
        int * arr = new int[size];
        for (int i = 0; i < size; ++i)
            arr[i] = 10 - i;
        bool resultIsCorrect = true;
        IntComporator intComp;
        bSort.sort<int>(arr, size, intComp);
        for (int i = 0; i < size; ++i)
            if (arr[i] != i + 1)
                resultIsCorrect = false;
        delete[] arr;
        QVERIFY(resultIsCorrect);
    }

    /// Testing buble sort with strings
    void stringTest()
    {
        const int size = 6;
        string strArr[] = {"adc", "abc", "za", "zas", "abct", "q"};
        string correctArr[] = {"q", "za", "abc", "adc", "zas", "abct"};
        StringComporator strComp;
        bSort.sort<string>(strArr, size, strComp);
        bool resultIsCorrect = true;
        for (int i = 0; i < size; ++i)
            if (strArr[i] != correctArr[i])
                resultIsCorrect = false;
        QVERIFY(resultIsCorrect);
    }

private:
    BubleSort bSort;
};
