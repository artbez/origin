#pragma once
#include <iostream>
#include "myerror.h"

template<typename T>
class QueueWithPriority
{
public:
    ~QueueWithPriority();
    /// adding new element
    void enqueue(T newValue, int priority);

    /// deleting first element with maximal priority
    T dequeue();
private:
    class Pair
    {
    public:
        T first;
        int second;
    };
    /// helping class whcih includes value and ling to the next element
    class ListElement
    {
    public:
        ListElement(Pair value)
        {
            this->value.first = value.first;
            this->value.second = value.second;
        }
        ~ListElement()
        {
            if (next != nullptr)
                delete next;
        }

        ListElement();
        Pair value;
        ListElement * next = nullptr;
    };
    ListElement * head = nullptr;
};

template<typename T>
QueueWithPriority<T>::~QueueWithPriority()
{
    delete head;
}

template<typename T>
void QueueWithPriority<T>::enqueue(T newValue, int priority)
{
    Pair p;
    p.first = newValue;
    p.second = priority;
    ListElement * newEl = new ListElement(p);

    ListElement * le = head;
    if (head == nullptr)
        head = newEl;
    else
    {
        while(le->next != nullptr)
        {
            le = le->next;
        }
        le->next = newEl;
    }
}

template<typename T>
T QueueWithPriority<T>::dequeue()
{
    try
    {
        if (head == nullptr)
            MyError::deletingError();
        int max = 0;
        ListElement * le = head;
        while(le != nullptr)
        {
            if (max < le->value.second)
            {
                max = le->value.second;
            }
            le = le->next;
        }
        le = head;
        if (le->value.second == max)
        {
            T newT = le->value.first;
            head = le->next;
            le->next = nullptr;
            delete le;
            return newT;
        }
        else
        {
            while(le->next != nullptr)
            {
                if (le->next->value.second == max)
                {
                    T newT = le->next->value.first;
                    ListElement * newEl = le->next;
                    newEl->next = nullptr;
                    delete newEl;
                    le->next = le->next->next;
                    return newT;
                }
            }
        }
    }
    catch(MyError::ExceptionOfDeleting &)
    {
        std::cout << "The queue is empty";
    }
}


