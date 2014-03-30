#pragma once
#include "list.h"
#include "listelement.h"

class LinkedList : public List
{
public:
    ~LinkedList();
    void printList();
    int length();
    int contains(int value);
    void deleteList();
    int get(int index);

protected:
    void insert(int position, int value);
    void deleteElement(int position);

private:
    ListElement * head = new ListElement(-1);
};
