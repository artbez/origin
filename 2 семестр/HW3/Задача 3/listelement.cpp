#include "listelement.h"
#include <iostream>

ListElement::ListElement(int value)
{
    this->takeValue(value);
}

ListElement::ListElement()
{
    this->takeValue(0);
}

int ListElement::getValue()
{
    return value;
}

void ListElement::takeValue(int value)
{
    this->value = value;
}

ListElement * ListElement::getNext()
{
    return next;
}

void ListElement::takeNext(ListElement * le)
{
    next = le;
}

void ListElement::printElement()
{
    std::cout << this->value;
}
