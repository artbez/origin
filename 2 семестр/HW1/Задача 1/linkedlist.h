#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
#include "list.h"
#include "listelement.h"

class LinkedList : public List
{
public:
    ~LinkedList();
    void printList();
    int length();
    void insert(int position, int value);
    void deleteElement(int position);
    void deleteList();
private:
    ListElement * head = new ListElement(-1);
};

#endif // LINKEDLIST_H
