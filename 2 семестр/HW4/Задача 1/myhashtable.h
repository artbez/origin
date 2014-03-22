#pragma once
#include "hashtableinterface.h"
#include "linkedlist.h"

class MyHashTable : public HashTableInterface
{
public:
    /// Constructor which get a number of a function for table
    MyHashTable(int number, int size);
    ~MyHashTable();
    /// Method which add a string to hashTable
    void add(QString &qStr);
    /// Method which delete a string from hashTable
    void del(QString &qStr);
    /// Method which check is this string included
    bool contains(QString &qStr);
    /// Method which delete hashTable
    void deleteHashTable();
    /// Method which return size of hashTable
    int tableSize();
    /// Method which return loadFactor
    double loadFactor();
    /// Method which return number of conflicts
    int numberOfConflicts();
    /// Method which return size of biggest conflict
    int biggestConflitSize();
    /// Method which select the hash fucntion
    void selectHashFunction(int number, int size);
    /// return hash of QString
    int getHash(QString &qStr);
    /// Method which print the hashTable
    void print();
private:
    int size = 7777;
    HashFunction * hashF;
    LinkedList * hashArray;
};
