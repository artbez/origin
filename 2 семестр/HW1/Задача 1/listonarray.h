#ifndef LISTONARRAY_H
#define LISTONARRAY_H

#pragma once
#include "list.h"

class ListOnArray : public List
{
public:
    ~ListOnArray();
    void printList();
    int length();
    void insert(int position, int value);
    void deleteElement(int position);
    void deleteList();
private:
    const int maxLength = 100;
    int * mainArray = new int[maxLength];
    int currentLength = 0;
};

#endif // LISTONARRAY_H
