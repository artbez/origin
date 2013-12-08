#include "list.h"

using namespace ListSpace;

namespace HashTableSpace
{
	struct HashTable
	{
		List * arr;
		int size;
	};

	HashTable initHashTable(int size);
	void add(MyString &str, const HashTable &hashT);
	void printHashTable(const HashTable &hashT);
	void deleteHashTable(HashTable &hashT);
	bool find(MyString &str, const HashTable &hashT);
	int middleOfLists(const HashTable &hashT);
	void bigestList(const HashTable &hashT);
}