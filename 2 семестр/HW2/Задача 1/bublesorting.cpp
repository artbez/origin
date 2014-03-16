#include "bublesorting.h"

void BubleSorting::sort(int *newArray, int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - 1; ++j)
        {
            if (newArray[j] > newArray[j + 1])
            {
                int changer = newArray[j];
                newArray[j] = newArray[j + 1];
                newArray[j + 1] = changer;
            }
        }
    }
}
