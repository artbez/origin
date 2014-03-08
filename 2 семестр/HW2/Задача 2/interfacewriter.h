#pragma once

/// Interface of class which can print a matrix as a spiral bypass
class InterfaceWriter
{
public:
    virtual ~InterfaceWriter(){}
    /// Method which print a matrix as a spiral bypass
    virtual void write(int ** arr, int number) = 0;
};

