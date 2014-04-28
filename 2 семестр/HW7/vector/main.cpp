#include "myvector.h"
#include "testingmyvector.h"
#include <QCoreApplication>

int main()
{
    TestingMyVector testMyVector;
    QTest::qExec(&testMyVector);

    return 0;
}
