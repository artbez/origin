#include "hashTable.h"
#include <string.h>
#include <iostream>

using std::cout;

namespace HashTableSpace
{
	HashTable initHashTable(int size)
	{
		HashTable hashT;
		hashT.size = size;
		hashT.arr = new List[size];
		for (int i = 0; i < size; ++i)
		{
			List st;
			init(st);
			hashT.arr[i] = st;
		}
		return hashT;
	}

	int hash(MyString &str, int size)
	{
		int prime = 233; 
		int length = lengthOfMyString(str);
		int answer = 0;
		for (int i = 0; i < length; ++i)
		{
			answer = (answer * prime  + str.mainString[i]) % size;
		}

		return answer;
	}

	void add(MyString &str, const HashTable &hashT)
	{
		int hashOfCurStr = hash(str, hashT.size);
		insert(str, hashT.arr[hashOfCurStr]);	
	}

	void printHashTable(const HashTable &hashT)
	{
		for (int i = 0; i < hashT.size; ++i)
		{
			if (!isEmpty(hashT.arr[i]))
			{
				printList(hashT.arr[i]);
				std::cout << "\n";
			}
		}
	}

	bool find(MyString &str, const HashTable &hashT)
	{
		int hashOfCurStr = hash(str, hashT.size);
			return findInList(str, hashT.arr[hashOfCurStr]);
	}

	void deleteHashTable(HashTable &hashT)
	{
		for (int i = 0; i < hashT.size; ++i)
		{
		//	cout << "deleted list ";
		//	printList(hashT.arr[i]);
		//	cout << "\n";
			deleteList(hashT.arr[i]);
		}
		delete[] hashT.arr;
	}

	int middleOfLists(const HashTable &hashT)
	{
		int sum = 0;
		for (int i = 0; i < hashT.size; ++i)
		{
			sum += length(hashT.arr[i]);
		}

		return sum / hashT.size;
	}

	void bigestList(const HashTable &hashT)
	{
		int max = 0;
		int index = 0;
		for (int i = 0; i < hashT.size; ++i)
		{
			if (max < length(hashT.arr[i]))
			{
				max = length(hashT.arr[i]);
				index = i;
			}
		}
		cout << max << " ";
		printList(hashT.arr[index]);
	}
}