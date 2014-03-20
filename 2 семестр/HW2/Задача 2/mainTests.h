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
        fWriter = new FileWriter("testFile");
    }

    void consolWriterInitTest()
    {
        cWriter = new ConsoleWriter();
    }

    void createHelpingArray()
    {
        arr = new int * [number];
        for (int i = 0; i < number; ++i)
        {
            arr[i] = new int[number];
            for (int j = 0; j < number; ++j)
                arr[i][j] = i * number + j;
        }

    }

    void writeToConsoleTest()
    {
        cWriter->write(arr, number);
    }

    void writeToFileTest()
    {
        fWriter->write(arr, number);
    }

    void deleteHelpingArray()
    {
        for (int i = 0; i < number; ++i)
            delete[] arr[i];
        delete[] arr;
    }

    void clean()
    {
        delete fWriter;
        delete cWriter;
    }

private:
    FileWriter * fWriter;
    ConsoleWriter * cWriter;
    const int number = 7;
    int ** arr;
};
