#include "bublesorting.h"

void BubleSorting::sort(int ** newArray, const int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - 1; ++j)
        {
            if (newArray[0][j] > newArray[0][j + 1])
                changer(newArray, j, j + 1, length);
        }
    }
}

void BubleSorting::changer(int ** newArray, int firstIndex, int secondIndex, const int length)
{
     int * helper = new int[length];
     for (int i = 0; i < length; ++i)
         helper[i] = newArray[i][firstIndex];
     for (int i = 0; i < length; ++i)
         newArray[i][firstIndex] = newArray[i][secondIndex];
     for (int i = 0; i < length; ++i)
         newArray[i][secondIndex] = helper[i];
     delete[] helper;
}


