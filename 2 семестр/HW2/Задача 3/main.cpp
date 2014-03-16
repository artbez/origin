#include <iostream>
#include "bublesorting.h"

int main()
{
    int size = 0;
    std::cout << "Eneter a size of matrix\n";
    std::cin >> size;

    int ** arr = new int * [size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = new int[size];
    }
    std::cout << "Enter a matrix of " << size << "x" << size << "\n";
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            std::cin >> arr[i][j];

    BubleSorting bSort;
    bSort.sort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < size; ++i)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

