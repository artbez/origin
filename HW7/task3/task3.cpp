#include "hashTable.h"
#include <iostream>

using std::cin;
using std::cout;

using namespace HashTableSpace;

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	HashTable hashT = initHashTable(7);

	const int size = 1000;
	char * str = new char[size];
	while(cin >> str)
	{
		MyString myStr = toMyString(str);
		add(myStr, hashT);
		delete[] str;
		str = new char[size];
	}
	
	cout << middleOfLists(hashT) << "\n";
	bigestList(hashT);
	cout << "\n";

	printHashTable(hashT);
	deleteHashTable(hashT);
	return 0;
}