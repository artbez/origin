#ifndef LIST_H
#define LIST_H

#pragma once

class List
{
public:
    virtual ~List(){}
    virtual void printList() = 0;
    virtual int length() = 0;
    virtual void insert(int position, int value) = 0;
    virtual void deleteElement(int position) = 0;
    virtual void deleteList() = 0;
};

#endif // LIST_H
