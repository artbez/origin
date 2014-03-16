#include <iostream>
#include "bublesorting.h"
#include "quicksorting.h"

int main()
{
    const int length  = 8;
    int arr1[length] = {2, 5, 12, -1, 3, 2, 12, 3};
    BubleSorting bSorter;
    bSorter.sort(arr1, length);
    for (int i = 0; i < length; ++i)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n\n\n";

    int arr2[length] = {2, 5, 12, -1, 3, 2, 12, 3};
    QuickSorting qSorter;
    qSorter.sort(arr2, length);
    for (int i = 0; i < length; ++i)
    {
        std::cout << arr2[i] << " ";
    }

    return 0;
}

