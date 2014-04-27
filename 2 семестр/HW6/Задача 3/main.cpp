#include <QCoreApplication>
#include "sharedpointer.h"
#include "sharedpointertest.h"
#include <iostream>

int main()
{
    SharedPointerTest spt;
    QTest::qExec(&spt);

    return 0;
}
