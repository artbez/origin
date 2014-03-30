#pragma once
#include <list>
#include <iostream>

template<typename T>
class Set
{
public:
    /// addition element to a set
    void addElement(T element);
    /// check is this element in set or not
    bool isExistElement(T element);
    /// delete this element form the set if it's exist
    void deleteElement(T element);
    /// make this to intersection if this set with an other set
    void intersectWithSet(Set<T> anotherSet);
    /// make this to union of this set with an other set
    void unionWithSet(Set<T> anotherSet);
    ///  print set
    void printSet();
    /// return set as a list
    std::list<T> getList();
private:
    std::list<T> myList;
};

template<typename T>
void Set<T>::addElement(T element)
{
    if (!isExistElement(element))
            myList.push_back(element);
}

template<typename T>
bool Set<T>::isExistElement(T element)
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
        myList.remove(element);
}

template<typename T>
void Set<T>::intersectWithSet(Set<T> anotherSet)
{
    std::list<T> newList;
    for (const T &el : myList)
        if (anotherSet.isExistElement(el))
            newList.push_back(el);
    myList = newList;
}

template<typename T>
void Set<T>::unionWithSet(Set<T> anotherSet)
{
    std::list<T> newList = anotherSet.getList();
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
std::list<T> Set<T>::getList()
{
    return myList;
}

