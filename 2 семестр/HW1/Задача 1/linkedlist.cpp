#include "linkedlist.h"
#include <iostream>


LinkedList::~LinkedList()
{
    this->deleteList();
}

void LinkedList::printList()
{
    ListElement * le = head->next;
    while(le != nullptr)
    {
        le->printElement();
        std::cout << "; ";
        le = le->next;
    }
}

int LinkedList::length()
{
    int result = 0;

    ListElement * le = head->next;
    while(le != nullptr)
    {
        result++;
        le = le->next;
    }

    return result;
}

void LinkedList::insert(int position, int value)
{
    ListElement * le = head;
    while(le->next != nullptr && position > 0)
    {
        position--;
        le = le->next;
    }

    if (position != 0)
    {
        std::cerr << "Error. The index is more then the length";
        deleteList();
        exit(0);
    }

    ListElement * newListEl = new ListElement();
    newListEl->value = value;
    newListEl->next = le->next;
    le->next = newListEl;
}

void LinkedList::deleteElement(int position)
{
    ListElement * le = head;
    while(le->next != nullptr && position > 0)
    {
        position--;
        le = le->next;
    }

    if (le->next == nullptr || position > 0)
    {
        std::cerr << "Error. The index is no element with this index";
        deleteList();
        exit(0);
    }

    ListElement * newListEl = le->next;
    le->next = le->next->next;
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

  //  delete head;
}
