#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "bublesorting.h"

class TestBubleSort: public QObject
{
    Q_OBJECT

public:
    explicit TestBubleSort(QObject *parent = 0) : QObject(parent){}

private slots:
    void reverseTest()
    {
        const int size = 8;
        int ** arr = new int * [size];
        for (int i = 0; i < size; ++i)
            arr[i] = new int[size];

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                arr[i][size - j - 1] = i * size + j;

        BubleSorting bSort;
        bSort.sort(arr, size);

        int ** predicResult = new int * [size];
        for (int i = 0; i < size; ++i)
            predicResult[i] = new int[size];

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                predicResult[i][j] = i * size + j;


        QVERIFY(arraysEqual(arr, predicResult, size));
        for (int i = 0; i < size; ++i)
        {
            delete[] arr[i];
            delete[] predicResult[i];
        }

        delete[] arr;
        delete[] predicResult;
    }

private:
    bool arraysEqual(int ** firstArray, int ** secondArray, int length)
    {
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                if (firstArray[i][j] != secondArray[i][j])
                    return false;

        return true;
    }
};
