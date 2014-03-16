#pragma once

#include "stack.h"

class LinkedStack : public Stack
{
public:
    ~LinkedStack();
    void printStack();
    int length();
    /// return the first element of the stack
    int getFirst();
    /// add the velue to begin of the stack
    void push(int value);
    /// delete first element of the stack
    void pop();
    void deleteStack();
private:
    ListElement * head = nullptr;
};
