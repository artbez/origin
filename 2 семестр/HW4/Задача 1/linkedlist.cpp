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

void LinkedList::insert(int position, QString &qStr)
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
    newListEl->takeValue(qStr);
    newListEl->takeNext(le->getNext());
    le->takeNext(newListEl);
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

int LinkedList::find(QString &qStr)
{
    int index = 0;
    ListElement * le = head;
    while(le->getNext() != nullptr)
    {
        if (le->getNext()->getValue() == qStr)
            return index;
        index++;
        le = le->getNext();
    }
    index = -1;
    return index;
}

QString LinkedList::get(int index)
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
