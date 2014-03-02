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
    const int MAX_LENGTH = 100;
    int * mainArray = new int[MAX_LENGTH];
    int currentLength = 0;
};

#endif // LISTONARRAY_H
