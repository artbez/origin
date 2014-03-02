#include "linkedstack.h"
#include <iostream>

LinkedStack::~LinkedStack()
{
    this->deleteStack();
}

void LinkedStack::printStack()
{
    ListElement * le = head;
    while(le != nullptr)
    {
        le->printElement();
        std::cout << "; ";
        le = le->getNext();
    }
}

int LinkedStack::length()
{
    int result = 0;

    ListElement * le = head;
    while(le != nullptr)
    {
        result++;
        le = le->getNext();
    }

    return result;
}

void LinkedStack::push(int value)
{
    ListElement * newEl = new ListElement();
    newEl->takeValue(value);
    newEl->takeNext(head);
    head = newEl;
}

void LinkedStack::pop()
{
    if (head == nullptr)
    {
        std::cerr << "Error. The stack is empty";
        exit(0);
    }

    ListElement * le = head;
    head = head->getNext();
    delete le;
}

void LinkedStack::deleteStack()
{
    int length = this->length();
    while(length > 0)
    {
        this->pop();
        length--;
    }
}

int LinkedStack::getFirst()
{
    if (head == nullptr)
    {
        std::cerr << "Error. The stack is empty";
        exit(0);
    }

    return head->getValue();
}
