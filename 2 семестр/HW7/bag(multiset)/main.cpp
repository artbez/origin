#include <QCoreApplication>
#include "bag.h"
#include "testingbag.h"

int main()
{
    TestingBag testBag;
    QTest::qExec(&testBag);

    return 0;
}
