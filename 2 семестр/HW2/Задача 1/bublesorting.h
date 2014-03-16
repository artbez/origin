#pragma once
#include "sorting.h"

/// Class which can sort an array by BubleSort
class BubleSorting : public Sorting
{
public:
    /// Method which sort an array by BubleSort
    void sort(int * newArray, int length);
};

