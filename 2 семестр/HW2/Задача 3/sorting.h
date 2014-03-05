#pragma once

/// Interface of class which can sort a matrix
class Sorting
{
public:
    /// Method which sort a matrix
    virtual void sort(int ** newArray, int length) = 0;
};
