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
    const int maxLength = 100;
    int * mainArray = new int[maxLength];
    int currentLength = 0;
};

#endif // STACKONARRAY_H
