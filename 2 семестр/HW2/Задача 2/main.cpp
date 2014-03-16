#include "consolewriter.h"
#include "filewriter.h"
#include <iostream>
#include "mainTests.h"

using std::cin;
using std::cout;

int main()
{
    TestMain tm;
    QTest::qExec(&tm);

    cout << "Enter an odd number > 0\n";
    int number = 0;
    cin >> number;
    int ** arr = new int * [number];

    cout << "Enter an array\n";

    for (int i = 0; i < number; ++i)
    {
        arr[i] = new int[number];
        for (int j = 0; j < number; ++j)
            cin >> arr[i][j];
    }

    int wayToWrite = 0;
    cout << "\nSelect a way of writing\n";
    cout << "1. Print console\n";
    cout << "2. Print file\n";
    cin >> wayToWrite;

    switch (wayToWrite)
    {
        case 1:
        {
            ConsoleWriter consoleWriter;
            consoleWriter.write(arr, number);
            break;
        }
        case 2:
        {
            const int size = 100;
            char * fileName = new char[size];

            cout << "Enter file's name\n";
            cin >> fileName;
            FileWriter fileWriter(fileName);
            fileWriter.write(arr, number);
            delete[] fileName;
            break;
        }
        default:
            cout << "Error";
    }

    for (int i = 0; i < number; ++i)
        delete[] arr[i];

    delete[] arr;

    return 0;
}

