#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "filewriter.h"
#include "consolewriter.h"

class TestMain: public QObject
{
    Q_OBJECT

public:
    explicit TestMain(QObject *parent = 0) : QObject(parent){}

private slots:
    void fileWriterInitTest()
    {
        FileWriter fWriter("testFile");
    }

    void writeToConsoleTest()
    {
        const int number = 7;
        int ** arr = new int * [number];
        for (int i = 0; i < number; ++i)
        {
            arr[i] = new int[number];
            for (int j = 0; j < number; ++j)
                arr[i][j] = i * number + j;
        }
        ConsoleWriter cWriter;
        cWriter.write(arr, number);

        for (int i = 0; i < number; ++i)
            delete[] arr[i];
        delete[] arr;
    }

    void writeToFileTest()
    {
        const int number = 7;
        int ** arr = new int * [number];
        for (int i = 0; i < number; ++i)
        {
            arr[i] = new int[number];
            for (int j = 0; j < number; ++j)
                arr[i][j] = i * number + j;
        }
        FileWriter fWriter("testFile");
        fWriter.write(arr, number);

        for (int i = 0; i < number; ++i)
            delete[] arr[i];
        delete[] arr;
    }
};
