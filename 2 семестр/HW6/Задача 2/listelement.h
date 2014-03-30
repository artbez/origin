#pragma once

class ListElement
{
public:
    ListElement(int value);
    ListElement();
    int getValue();
    void takeValue(int value);
    ListElement * getNext();
    void takeNext(ListElement * le);
    void printElement();
private:
    int value;
    ListElement * next = nullptr;
};


