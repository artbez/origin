#include "linkedstack.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedStack * stack = new LinkedStack();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    std::cout << stack->length() << "\n";
    stack->printStack();
    std::cout << "\n";
    stack->pop();
    stack->pop();
    stack->printStack();
    stack->deleteStack();
    delete stack;
    return 0;
}

