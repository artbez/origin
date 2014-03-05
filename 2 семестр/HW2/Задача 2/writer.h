#pragma once

/// Interface of class which can print a matrix as a spiral bypass
class Writer
{
public:
    virtual ~Writer(){}
    /// Method which print a matrix as a spiral bypass
    virtual void write(int ** arr, int number) = 0;
};

