#include <QCoreApplication>
#include "linkedlist.h"
#include <iostream>
#include "testuniquelist.h"

int main()
{
    TestingUniqueLists tl;
    QTest::qExec(&tl);

    return 0;
}
