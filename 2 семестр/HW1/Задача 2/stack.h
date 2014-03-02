#ifndef STACK_H
#define STACK_H

#pragma once
#include "listelement.h"

class Stack
{
public:
    virtual ~Stack(){};
    virtual void printStack() = 0;
    virtual int length() = 0;
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void deleteStack() = 0;
};
#endif // STACK_H
