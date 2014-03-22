#pragma once
#include <QString>

class List
{
public:
    virtual ~List(){}
    virtual void printList() = 0;
    virtual int length() = 0;
    virtual void insert(int position, QString &qStr) = 0;
    virtual void deleteElement(int position) = 0;
    virtual void deleteList() = 0;
    virtual int find(QString &qStr) = 0;
    virtual QString get(int index) = 0;
};
