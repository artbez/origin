#include "linkedstack.h"
#include <iostream>

LinkedStack::LinkedStack() : Stack()
{
    this->head = nullptr;
    this->next = nullptr;
}

LinkedStack::~LinkedStack()
{
    this->deleteStack();
}

void LinkedStack::printStack()
{
    LinkedStack * list = this;
    while(list->head != nullptr)
    {
        list->head->printElement();
        std::cout << "; ";
        list = list->next;
    }
}

int LinkedStack::length()
{
    int result = 0;

    LinkedStack * list = this->next;
    while(list != nullptr)
    {
        result++;
        list = list->next;
    }

    return result;
}

void LinkedStack::push(ListElement * newElement)
{
    LinkedStack * list = new LinkedStack();
    list->head = this->head;
    list->next = this->next;
    this->head = newElement;
    this->next = list;
}

void LinkedStack::pop()
{
    if (this->head == nullptr)
    {
        std::cerr << "Error. The stack is empty";
        this->deleteStack();
        exit(0);
    }

    delete this->head;
    this->head = this->next->head;
    this->next = this->next->next;
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
