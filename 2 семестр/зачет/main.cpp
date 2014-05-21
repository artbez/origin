#include <QCoreApplication>
#include "tests.h"

int main()
{
    Tests test;
    QTest::qExec(&test);
    return 0;
}
