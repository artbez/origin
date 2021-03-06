#include "linkedlist.h"
#include <iostream>


LinkedList::~LinkedList()
{
    deleteList();
    delete head;
}

void LinkedList::printList()
{
    ListElement * le = head->getNext();
    while(le != nullptr)
    {
        le->printElement();
        std::cout << "; ";
        le = le->getNext();
    }
}

int LinkedList::length()
{
    int result = 0;

    ListElement * le = head->getNext();
    while(le != nullptr)
    {
        result++;
        le = le->getNext();
    }

    return result;
}

void LinkedList::insert(int position, int value)
{
    ListElement * le = head;
    while(le->getNext() != nullptr && position > 0)
    {
        position--;
        le = le->getNext();
    }

    if (position != 0)
    {
        std::cerr << "Error. The index is more then the length";
        deleteList();
        exit(0);
    }

    ListElement * newListEl = new ListElement();
    newListEl->takeValue(value);
    newListEl->takeNext(le->getNext());
    le->takeNext(newListEl);
}

int LinkedList::contains(int value)
{
    ListElement * le = head;
    int position = 0;
    while(le->getNext() != nullptr)
    {
        if (le->getNext()->getValue() == value)
            return position;
        le = le->getNext();
        position++;
    }
    return -1;
}

void LinkedList::deleteElement(int position)
{
    ListElement * le = head;
    while(le->getNext() != nullptr && position > 0)
    {
        position--;
        le = le->getNext();
    }

    if (le->getNext() == nullptr || position > 0)
    {
        std::cerr << "Error. The index is no element with this index";
        deleteList();
        exit(0);
    }

    ListElement * newListEl = le->getNext();
    le->takeNext(le->getNext()->getNext());
    delete newListEl;
}

void LinkedList::deleteList()
{
    int length = this->length();
    while(length > 0)
    {
        deleteElement(0);
        length--;
    }
}

int LinkedList::get(int index)
{
    ListElement * le = head;
    while(le->getNext() != nullptr && index > 0)
    {
        index--;
        le = le->getNext();
    }

    if (le->getNext() == nullptr || index > 0)
    {
        std::cerr << "Error. The index is no element with this index";
        deleteList();
        exit(0);
    }

    return le->getNext()->getValue();
}
