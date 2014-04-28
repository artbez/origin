#pragma once
#include <QMap>
#include <QMapIterator>
#include <iostream>

/// class which keep multiset
template <typename T>
class Bag
{
public:
    Bag(){}
    /// add an element to the bag
    void addToBag(const T& element);
    /// delete an element from the bag
    void deleteFromBag(const T& element);
    /// try to find an element in the bag
    bool findInBag(const T& element);
    /// return number of repeating considered element
    int numberOfElements(const T& element);
    /// print all elements with number of repeating
    void printBag();
private:
    QMap<T, int> qMap;
};

template <typename T>
void Bag<T>::addToBag(const T &element)
{
    if (qMap.contains(element))
        qMap[element]++;
    else
        qMap.insert(element, 1);
}

template <typename T>
void Bag<T>::deleteFromBag(const T &element)
{
    if (findInBag(element))
    {
        if (qMap[element] == 1)
            qMap.remove(element);
        else
            qMap[element]--;
    }
}

template <typename T>
bool Bag<T>::findInBag(const T &element)
{
    return qMap.contains(element);
}

template <typename T>
int Bag<T>::numberOfElements(const T &element)
{
    if (qMap.contains(element))
        return qMap[element];
    return 0;
}

template <typename T>
void Bag<T>::printBag()
{
    QMapIterator<T, int> i(qMap);
    while (i.hasNext())
    {
        i.next();
        std::cout << i.key() << ": " << i.value() << "\n";
    }
}
