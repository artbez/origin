#include "myString.h"

using namespace myStringSpace;

struct Pair
{
	MyString str;
	int number;
};

bool isStringsEqual(MyString &str1, MyString &str2);
void printSecond(const Pair &p);
void printPair(const Pair &p);
void deletePair(Pair &p);
