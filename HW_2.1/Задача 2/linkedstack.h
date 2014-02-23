#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#pragma once
#include "stack.h"

class LinkedStack : public Stack
{
public:
    LinkedStack();
    ~LinkedStack();
    void printStack();
    int length();
    void push(ListElement * newElement);
    void pop();
    void deleteStack();
private:
    LinkedStack * next;
};

#endif // LINKEDSTACK_H
