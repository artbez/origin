#include "myhashtable.h"
#include <iostream>

MyHashTable::MyHashTable(int number, int size)
{
    this->size = size;
    hashF = new HashFunction(number, size);
    const int newSize = size;
    hashArray = new LinkedList[newSize];
}

MyHashTable::~MyHashTable()
{
    deleteHashTable();
    delete hashF;
}

void MyHashTable::add(QString &qStr)
{
    int newHash = hashF->hash(qStr);
    hashArray[newHash].insert(0, qStr);
}

void MyHashTable::del(QString &qStr)
{
    int newHash = hashF->hash(qStr);
    int index = hashArray[newHash].find(qStr);
    if (index != -1)
        hashArray[newHash].deleteElement(index);
}

bool MyHashTable::contains(QString &qStr)
{
    int newHash = hashF->hash(qStr);
    return (hashArray[newHash].find(qStr) != -1);
}

void MyHashTable::deleteHashTable()
{
    for (int i = 0; i < size; ++i)
    {
        hashArray[i].~LinkedList();
    }
    delete[] hashArray;
}

int MyHashTable::tableSize()
{
    return size;
}

double MyHashTable::loadFactor()
{
    double result = 0;
    for (int i = 0; i < size; ++i)
    {
        result += hashArray[i].length();
    }
    return result / size;
}

int MyHashTable::numberOfConflicts()
{
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        if (hashArray[i].length() > 1)
            result++;
    }
    return result;
}

int MyHashTable::biggestConflitSize()
{
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        int curResult = hashArray[i].length();
        result = (result > curResult ? result : curResult);
    }
    return result;
}

void MyHashTable::selectHashFunction(int number, int size)
{
    delete hashF;
    hashF = new HashFunction(number, size);
    LinkedList * newHashArray = new LinkedList[size];
    for (int i = 0; i < this->size; ++i)
    {
        ListElement * le = new ListElement();
        while (le->getNext() != nullptr)
        {
            QString curStr = le->getNext()->getValue();
            newHashArray[hashF->hash(curStr)].insert(0, curStr);
            le = le->getNext();
        }
    }
    deleteHashTable();
    hashArray = newHashArray;
}

int MyHashTable::getHash(QString &qStr)
{
    return hashF->hash(qStr);
}

void MyHashTable::print()
{
    for (int i = 0; i < size; ++i)
        if (hashArray[i].length() != 0)
        {
            std::cout << i << " ";
            hashArray[i].printList();
            std::cout << "\n";
        }
}

