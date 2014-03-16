#pragma once

#include "listelement.h"

class Stack
{
public:
    virtual ~Stack(){}
    virtual void printStack() = 0;
    virtual int length() = 0;
    /// return the first element of the stack
    virtual int getFirst() = 0;
    /// add the velue to begin of the stack
    virtual void push(int value) = 0;
    /// add the velue to begin of the stack
    virtual void pop() = 0;
    virtual void deleteStack() = 0;
};

