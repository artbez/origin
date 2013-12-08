#include <iostream>
#include <string.h>
#include "tree.h"

using std::cin;
using std::cout;
using std::gets;

using namespace TreeSpace;

int main()
{
	const int size = 1000;
	char * str = new char[size];
	gets(str);

	Tree *tree = create(str);
	printTree(tree);
	cout << "\n" << countTree(tree);
	
	deleteTree(tree);
	
	delete[] str;
	str = nullptr;
	delete tree;
	tree = nullptr;
	return 0;
}