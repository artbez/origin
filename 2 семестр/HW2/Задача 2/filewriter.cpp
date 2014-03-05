#include "filewriter.h"
#include <iostream>

FileWriter::FileWriter(const char * newFileName)
{
    fileName.open(newFileName);
}

FileWriter::~FileWriter()
{
    fileName.close();
}

void FileWriter::write(int ** arr, int number)
{
    int index1 = number / 2;
    int index2 = number / 2;
    int max = 1;

    fileName << arr[index1][index2] << " ";

    while(true)
    {
        if (!step(arr, index1, index2, index1, 1, max, number))
            break;
        if (!step(arr, index1, index2, index2, 1, max, number))
            break;
        if (!step(arr, index1, index2, index1, -1, max + 1, number))
            break;
        if (!step(arr, index1, index2, index2, -1, max + 1, number))
            break;

            max += 2;
    }
}

bool FileWriter::step(int ** arr, int &index1, int &index2, int &direct, int sum, int max, int number)
{
    for (int i = 0; i < max; ++i)
    {
        if ((direct + sum < number) && (direct + sum >= 0))
        {
            direct += sum;
            fileName << arr[index1][index2] << " ";
        }
        else
            return false;
    }

    return true;
}
