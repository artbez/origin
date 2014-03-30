#include "settest.h"

int main()
{
    TestingSet ts;
    QTest::qExec(&ts);
    return 0;
}
