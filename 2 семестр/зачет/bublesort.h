#pragma once
#include "comporatorinterface.h"

/// have sorting method
class BubleSort
{
public:
    /// sort array arr by comporator
    template <typename T>
    void sort(T *arr, int size, ComporatorInterface<T> &compInt);
};


template <typename T>
void BubleSort::sort(T *arr, int size, ComporatorInterface<T> &compInt)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size - 1; ++j)
            if (compInt.firstIsGreater(arr[j], arr[j + 1]))
            {
                T changer = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = changer;
            }
}
