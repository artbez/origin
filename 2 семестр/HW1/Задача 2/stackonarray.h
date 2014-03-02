#ifndef STACKONARRAY_H
#define STACKONARRAY_H

#pragma once
#include "stack.h"

class StackOnArray : public Stack
{
public:
    ~StackOnArray();
    void printStack();
    int length();
    int getFirst();
    void push(int value);
    void pop();
    void deleteStack();
private:
    const int MAX_LENGTH = 100;
    int * mainArray = new int[MAX_LENGTH];
    int currentLength = 0;
};

#endif // STACKONARRAY_H
