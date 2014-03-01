#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#pragma once

class ListElement
{
public:
    ListElement(int value);
    ListElement();
    int getValue();
    void takeValue(int value);
    void printElement();
public:
    int value;
    ListElement * next = nullptr;
};

#endif // LISTELEMENT_H
