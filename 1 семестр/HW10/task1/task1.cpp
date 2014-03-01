#include <iostream>
#include <fstream>
#include <string.h>
#include "list.h"
#include "table.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

using namespace TreeSpace;

int main()
{
	const int size = 256;
	ifstream fin("file.in");
	ofstream fout("file.out");
	int table[size];
	for (int i = 0; i < size; ++i)
	{
		table[i] = 0;
	}

	char ch;
	while(fin >> ch)
	{
		table[ch]++;
	}
	
	fin.close();

	ListSpace::List * list = ListSpace::init();
	
	int curIndex = 0;
	while(curIndex < size)
	{
		if (table[curIndex] != 0)
		{
			ListSpace::addSortedList(initTree(table[curIndex], curIndex), list);		
		}
	
		curIndex++;
	}

	int length = ListSpace::size(list);
	for (int i = 0; i < length - 1; ++i)
	{
		Tree * tree1 = ListSpace::getFirst(list);
		ListSpace::pop(list);
		Tree * tree2 = ListSpace::getFirst(list);
		ListSpace::pop(list);
		Tree * newTree = makeUnderTree(tree1, tree2);
		ListSpace::addSortedList(newTree, list);
	}
	
	Tree * mainTree = list->head->next->curTree;
	
	char * endStr = toString(mainTree);

	fout << endStr << "\n";

	delete[] endStr;

	char ** mainTable = takeTable(mainTree, size);
	
	ifstream fin2 ("file.in");
	
	while(fin2 >> ch)
	{
		fout << mainTable[(int) ch];
	}

	fin2.close();
	fout.close();

	for (int i = 0; i < size; ++i)
	{
		delete[] mainTable[i];
	}
	delete[] mainTable;
	deleteList(list);
	delete list;
	delete mainTree;
 
	return 0;
}