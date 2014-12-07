#include "test.h"
#include <iostream>

int main()
{
	Test myTest;
	QTest::qExec(&myTest);

	return 0;
}
