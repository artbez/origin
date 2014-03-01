#ifndef STACK_H
#define STACK_H

#pragma once
#include "listelement.h"

class Stack
{
public:
    virtual void printStack() = 0;
    virtual int length() = 0;
    virtual void push(ListElement * newElement) = 0;
    virtual void pop() = 0;
    virtual void deleteStack() = 0;
protected:
    ListElement * head;
};
#endif // STACK_H
