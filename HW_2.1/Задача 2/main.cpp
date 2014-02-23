#include "linkedstack.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedStack * stack = new LinkedStack();
    stack->push(new ListElement(1));
    stack->push(new ListElement(2));
    stack->push(new ListElement(3));
    stack->push(new ListElement(4));
    stack->push(new ListElement(5));
    std::cout << stack->length() << "\n";
    stack->printStack();
    std::cout << "\n";
    stack->pop();
    stack->pop();
    stack->printStack();
    stack->deleteStack();

    return 0;
}

