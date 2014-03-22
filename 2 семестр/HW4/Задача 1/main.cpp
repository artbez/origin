#include <QCoreApplication>
#include <iostream>
#include "linkedlist.h"
#include "linkedlisttest.h"
#include "hashtabletest.h"
#include "myhashtable.h"

using namespace std;

int main()
{
    TestingLinkedLists tl;
    QTest::qExec(&tl);
    TestingHashTable th;
    QTest::qExec(&th);

    int sizeOfHashTable = 17;
    MyHashTable myHashTable(0, sizeOfHashTable);
    const int size = 10;
    QString str = "";
    for (int i = 0; i < size; ++i)
    {
        str.append(QString::number(i));
        myHashTable.add(str);
    }

    myHashTable.print();
    std::cout << "\nstatistics:";
    std::cout << myHashTable.loadFactor() << " " << myHashTable.tableSize() << " " << myHashTable.biggestConflitSize();
    std::cout << "\n";

    return 0;
}

