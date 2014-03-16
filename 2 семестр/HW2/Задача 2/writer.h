#ifndef WRITER_H
#define WRITER_H

#include "interfacewriter.h"

class Writer : public InterfaceWriter
{
public:
    virtual ~Writer(){}
    /// Method which can print a matrix as a spiral bypass
    void write(int ** arr, int number);
protected:
    /// Method which check is it possible or not move to the next cell
    bool step(int ** arr, int &index1, int &index2, int &direct, int sum, int max, int number);
    /// Method which print element of the matrix to somewhere
    virtual void printElement(int el) = 0;
};

#endif // WRITER_H
