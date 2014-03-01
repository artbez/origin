#include "pair.h"
#include <iostream>
#include <string.h>

using std::cout;

bool isStringsEqual(MyString &str1, MyString &str2)
{
	int length1 = lengthOfMyString(str1);
	int length2 = lengthOfMyString(str2);

	if (length1 != length2) 
		return false;

	for (int i = 0; i < length1; ++i)
	{
		if (str1.mainString[i] != str2.mainString[i])
			return false;
	}
	return true;
}

void printSecond(const Pair &p)
{
	int length = lengthOfMyString(p.str);
	for (int i = 0; i < length; ++i)
	{
		std::cout << p.str.mainString[i];
	}
}

void printPair(const Pair &p)
{
	cout << "(";
	int length = lengthOfMyString(p.str);
	for (int i = 0; i < length; ++i)
	{
		cout << p.str.mainString[i];
	}
	cout << ", " << p.number << ")";
}

void deletePair(Pair &p)
{
	if (p.str.mainString != NULL)
	{
	//	cout << "deleted ";
	//	printString(p.str);
	//	cout << "\n";
		deleteMyString(p.str);
	}
}