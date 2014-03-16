#include <QCoreApplication>
#include "linkedlist.h"
#include "listonarray.h"
#include <iostream>
#include "testLinkedList.h"
#include "testListOnArray.h"

int main()
{
    TestingLinkedLists tl;
    QTest::qExec(&tl);
    TestingListOnArray ta;
    QTest::qExec(&ta);
    //Список на указателях
    LinkedList * linkedList = new LinkedList();
    linkedList->insert(0, 5);
    linkedList->insert(0, 2);
    std::cout << linkedList->length();
    linkedList->printList();
    std::cout << "\n\n\n";
    linkedList->deleteElement(0);
    linkedList->printList();
    std::cout << "\n\n";
    delete linkedList;

    //Список на массивах
    ListOnArray * listOnArray = new ListOnArray();

    listOnArray->insert(0, 5);
    listOnArray->insert(0, 2);

    std::cout << listOnArray->length() << "\n";
    listOnArray->printList();
    std::cout << "\n";
    listOnArray->deleteElement(0);
    listOnArray->printList();
    delete listOnArray;

    return 0;
}
