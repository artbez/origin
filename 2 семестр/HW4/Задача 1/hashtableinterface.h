#pragma once
#include <QString>
#include "hashfunction.h"

class HashTableInterface
{
public:
    virtual ~HashTableInterface(){}
    virtual void add(QString &qStr) = 0;
    virtual void del(QString &qStr) = 0;
    virtual bool contains(QString &qStr) = 0;
    virtual void deleteHashTable() = 0;
    virtual int tableSize() = 0;
    virtual double loadFactor() = 0;
    virtual int numberOfConflicts() = 0;
    virtual int biggestConflitSize() = 0;
    virtual void print() = 0;
};
