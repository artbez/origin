#include <iostream>
#include <fstream>
#include "hashTable.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

using namespace HashTableSpace;

bool areEquals(char *str1, char *str2);

int main()
{
	ifstream fin1("file1.in");
	ofstream fout("file.out");

	const int sizeOfHashTable = 771;
	HashTable hashT = initHashTable(sizeOfHashTable);

	const int size = 1000;
	while(!fin1.eof())
	{
		char *str = new char[size];
		fin1.getline(str, size);
		
		MyString myStr = toMyString(str);
		add(myStr, hashT);
		delete[] str;
	}
	fin1.close();

	ifstream fin2("file2.in");
	while(!fin2.eof())
	{
		char *str = new char[size];
		fin2.getline(str, size);
		
		MyString myStr = toMyString(str);
		if (find(myStr, hashT))
			fout << str << "\n";

		delete[] str;
		deleteMyString(myStr);
	}
	fin2.close();
	fout.close();

	deleteHashTable(hashT);

	return 0;
}
