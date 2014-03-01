#pragma once 

namespace TreeSpace
{
	struct TreeNode
	{
		int value;
		char character;
		TreeNode *left;
		TreeNode *rigth;
	};
	struct Tree
	{
		TreeNode *root;
	};

	Tree * initTree(int value, char character);
	Tree * makeUnderTree(Tree * tree1, Tree * tree2);
	char * toString(Tree * tree);
	void printTree(Tree * tree);
	void deleteTree(Tree *& tree);
	Tree * makeTree(char * str);
}