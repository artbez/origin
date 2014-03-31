#include "queuewithpriority.h"
#include "uniqtest.h"
#include <iostream>

int main()
{
    TestingQueue tq;
    QTest::qExec(&tq);
    return 0;
}
