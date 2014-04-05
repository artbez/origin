#pragma once
#include <QString>
#include "list.h"
#include "listelement.h"

class LinkedList : public List
{
public:
    ~LinkedList();
    void printList();
    int length();
    void insert(int position, QString &qStr);
    void deleteElement(int position);
    void deleteList();
    int find(QString &qStr);
    QString get(int index);
    ListElement * getHead();
private:
    ListElement * head = new ListElement();
};
