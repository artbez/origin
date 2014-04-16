#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "quicksorting.h"

class TestQuickSort: public QObject
{
    Q_OBJECT

public:
    explicit TestQuickSort(QObject *parent = 0) : QObject(parent){}

private slots:
    void reverseTest()
    {
        const int size = 8;
        int * arr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = size - i;
        }

        QuickSorting qSort;
        qSort.sort(arr, size);

        int * predicResult = new int[size];
        for (int i = 0; i < size; ++i)
        {
            predicResult[i] = i + 1;
        }

        QVERIFY(arraysEqual(arr, predicResult, size));
        delete[] arr;
        delete[] predicResult;
    }

    void onePairChanged()
    {
        const int size = 8;
        int * arr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = i + 1;
        }

        int tmp = arr[6];
        arr[6] = arr[7];
        arr[7] = tmp;

        QuickSorting qSort;
        qSort.sort(arr, size);

        int * predicResult = new int[size];
        for (int i = 0; i < size; ++i)
        {
            predicResult[i] = i + 1;
        }

        QVERIFY(arraysEqual(arr, predicResult, size));
        delete[] arr;
        delete[] predicResult;
    }

private:
    bool arraysEqual(int * firstArray, int * secondArray, int length)
    {
        for (int i = 0; i < length; ++i)
        {
            if (firstArray[i] != secondArray[i])
                return false;
        }
        return true;
    }
};
