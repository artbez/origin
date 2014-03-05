#pragma once

/// Interface of class which can sort an array
class Sorting
{
public:
    /// Method which sort an array
    virtual void sort(int * newArray, int length) = 0;
};
