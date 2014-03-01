#include <iostream>
#include "myString.h"

using std::cin;
using std::cout;

using namespace myStringSpace;

int main()
{
	MyString myStr = init();
	cout << isEmpty(myStr) << "\n";
	myStr = toMyString("!!!");
	MyString myStr2 = toMyString("12345678");

	MyString conStr = conc(myStr, myStr2);
	MyString subString = subStr(2, 7, conStr);
	printString(subString);
	cout << "\n" << isEqual(myStr, myStr) << "\n" << isEmpty(myStr);
	deleteMyString(myStr);
	deleteMyString(myStr2);
	deleteMyString(conStr);
	deleteMyString(subString);
	
	return 0;
}