#include "quicksorting.h"

void QuickSorting::sort(int * newArray, int length)
{
    qsort(newArray, 0, length - 1);
}

void QuickSorting::qsort(int * array, int firstIndex, int secondIndex)
{
    int mainEl = array[firstIndex];
    int l = firstIndex;
    int r = secondIndex;

    while (l < r)
    {

        while (array[l] < mainEl)
        {
            l++;
        }

        while (array[r] > mainEl)
        {
            r--;
        }

        if (l <= r)
        {
            int changer = array[l];
            array[l] = array[r];
            array[r] = changer;
            l++;
            r--;
        }

    }


    if (r > firstIndex)
    {
        qsort(array, firstIndex, r);
    }

    if (secondIndex > l)
    {
        qsort(array, l, secondIndex);
    }
}
