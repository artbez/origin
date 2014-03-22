#pragma once
#include <QString>

class ListElement
{
public:
    ListElement(QString &qStr);
    ListElement();
    QString &getValue();
    void takeValue(QString &qStr);
    ListElement * getNext();
    void takeNext(ListElement * le);
    void printElement();
private:
    QString value;
    ListElement * next = nullptr;
};

