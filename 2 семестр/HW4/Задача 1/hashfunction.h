#pragma once

#include <QString>

class HashFunction
{
public:
    /// Constructor which get a number of a function for table
    HashFunction(int number, int size);
    /// Return the hash of a string
    int hash(const QString &qStr);
private:
    int number;
    int size;
};
