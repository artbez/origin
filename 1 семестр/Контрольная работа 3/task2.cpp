#include <iostream>
#include <fstream>
#include "date.h"
#include "string.h"

using std::cin;
using std::cout;

using namespace DateSpace;

int main()
{
	freopen("task2.in", "r", stdin);
	const int size = 100;
	char * str = new char[size];

	Date minDate;
	minDate.day = 100;
	minDate.month = 100;
	minDate.year = 10000;

	while (cin >> str)
	{
		if (isDate(str))
		{
			Date curDate = initDate(str);
			if (theFirstDateBigger(minDate, curDate))
			{
				minDate = copyDate(curDate);
			}	
		}	
	}

	if (minDate.day == 100)
	{
		cout << "There are no dates in this text";
	}
	else
	{
		cout << "The answer is ";
		writeDate(minDate);
	}

	delete[] str;
	return 0;
}
