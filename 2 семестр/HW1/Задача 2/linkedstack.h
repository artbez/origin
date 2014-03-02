#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#pragma once
#include "stack.h"

class LinkedStack : public Stack
{
public:
    ~LinkedStack();
    void printStack();
    int length();
    int getFirst();
    void push(int value);
    void pop();
    void deleteStack();
private:
    ListElement * head = nullptr;
};

#endif // LINKEDSTACK_H
