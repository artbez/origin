#include <iostream>
#include "table.h"

void takeTable(TreeSpace::TreeNode * treeNode, char **& hafmanTable, int index, char *&curStr)
{
	if (treeNode->left != NULL)
	{
		curStr[index] = '0';
		takeTable(treeNode->left, hafmanTable, index + 1, curStr);
		curStr[index] = '\0';
	}
	if (treeNode->rigth != NULL)
	{
		curStr[index] = '1';
		takeTable(treeNode->rigth, hafmanTable, index + 1, curStr);
		curStr[index] = '\0';
	}
	if ((treeNode->left == NULL) && (treeNode->rigth == NULL))
	{
		int length = strlen(curStr);
		for (int i = 0; i < length; ++i)
		{
			hafmanTable[(int) treeNode->character][i] = curStr[i];
		}
	}
}
		
char ** takeTable(TreeSpace::Tree * tree, const int size)
{
	char ** hafmanTable = new char * [size] ;
	for (int i = 0; i < size; ++i) 
		hafmanTable[i] = new char[size];
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			hafmanTable[i][j] = '\0';
	char * curStr = new char[size];
	for (int i = 0; i < size; ++i)
		curStr[i] = '\0';

	takeTable(tree->root, hafmanTable, 0, curStr);

	delete[] curStr;
	return hafmanTable; 
}
