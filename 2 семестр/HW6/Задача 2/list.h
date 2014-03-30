#pragma once

class List
{
public:
    virtual ~List(){}
    virtual void printList() = 0;
    virtual int length() = 0;
    /// insert elemen value into place with index = position in List
    virtual void insert(int position, int value) = 0;
    /// delete element with this index
    virtual void deleteElement(int position) = 0;
    virtual void deleteList() = 0;
    virtual int get(int index) = 0;
};
