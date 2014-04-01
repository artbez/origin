#pragma once
#include <iostream>
#include <QList>

template<typename T>
class Set
{
public:
    /// addition element to a set
    void addElement(T element);
    /// check is this element in set or not
    bool isExistElement(T element) const;
    /// delete this element form the set if it's exist
    void deleteElement(T element);
    /// make this to intersection if this set with an other set
    void intersectWithSet(const Set<T> &anotherSet);
    /// make this to union of this set with an other set
    void unionWithSet(const Set<T> &anotherSet);
    ///  print set
    void printSet();
    /// return set as a list
    QList<T> toList() const;
private:
    QList<T> myList;
};

template<typename T>
void Set<T>::addElement(T element)
{
    if (!isExistElement(element))
            myList.append(element);
}

template<typename T>
bool Set<T>::isExistElement(T element) const
{
    for (const T &el : myList)
        if (el == element)
            return true;
    return false;
}

template<typename T>
void Set<T>::deleteElement(T element)
{
    if (isExistElement(element))
        myList.removeOne(element);
}

template<typename T>
void Set<T>::intersectWithSet(const Set<T> &anotherSet)
{
    QList<T> newList;
    for (const T &el : myList)
        if (anotherSet.isExistElement(el))
            newList.append(el);
    myList = newList;
}

template<typename T>
void Set<T>::unionWithSet(const Set<T> &anotherSet)
{
    QList<T> newList = anotherSet.toList();
    for (const T &el : newList)
        addElement(el);
}

template<typename T>
void Set<T>::printSet()
{
    for (const T &el : myList)
    {
        std::cout << el << " ";
    }
}

template<typename T>
QList<T> Set<T>::toList() const
{
    return myList;
}

