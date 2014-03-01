#include "tree.h"
#include <iostream>

using std::cout;

namespace TreeSpace
{
	Tree * initTree(int value, char character)
	{
		Tree * tree = new Tree();
		tree->root = new TreeNode();
		tree->root->character = character;
		tree->root->value = value;
		tree->root->left = NULL;
		tree->root->rigth = NULL;
		
		return tree;
	}

	Tree * makeUnderTree(Tree * tree1, Tree * tree2)
	{
		Tree * tree = new Tree();
		tree->root = new TreeNode();
		tree->root->left = tree1->root;
		tree->root->rigth = tree2->root;
		tree->root->value = tree1->root->value + tree2->root->value;
		return tree;
	}

	void printTree(TreeNode * treeNode)
	{
		cout << "(";
		if (treeNode->left != NULL)
			printTree(treeNode->left);
		else cout << "null";
		cout << ", " << treeNode->value << ", ";
		if (treeNode->rigth != NULL)
			printTree(treeNode->rigth);
		else cout << "null";
		cout << ")";
	}

	void printTree(Tree * tree)
	{
		printTree(tree->root);	
	}

	
	void toString(TreeNode * treeNode, char *str, int &index)
	{
		if (treeNode->left == NULL && treeNode->rigth == NULL)
		{
			str[index] = treeNode->character;
		}
		else
		{
			str[index] = '(';
			if (treeNode->left != NULL)
				toString(treeNode->left, str, ++index);
		
			if (treeNode->rigth != NULL)
				toString(treeNode->rigth, str, ++index);
			
			index++;
			str[index] = ')';
		}
	}

	char * toString(Tree * tree)
	{
		const int size = 1000;
		char *str = new char[size];
		for (int i = 0; i < size; ++i)
			str[i] = '\0';

		int index = 0;
		toString(tree->root, str, index);
		return str;	
	}

	void deleteTreeNode(TreeNode *& treeNode)
	{
		if (treeNode->left != NULL)
			deleteTreeNode(treeNode->left);
		if (treeNode->rigth != NULL)
			deleteTreeNode(treeNode->rigth);
			
		delete treeNode;
	}

	void deleteTree(Tree *& tree)
	{
		deleteTreeNode(tree->root);
	}

	void makeTree(TreeNode *&treeNode, char * str, int &index, const int length)
	{
		if(index < length)
		{
			while(str[index] == ')')
				index++;
	
			if (str[index] == '(')
			{
				TreeNode * left = new TreeNode();
				left->left = NULL;
				left->rigth = NULL;
				treeNode->left = left;
				makeTree(left, str, ++index, length);

				TreeNode * rigth = new TreeNode();
				rigth->left = NULL;
				rigth->rigth = NULL;
				treeNode->rigth = rigth;
				makeTree(rigth, str, ++index, length);
			}
			if ((str[index] != ')') && (str[index] != '('))
			{
				treeNode->character = str[index];
			}
		}
	}

	Tree * makeTree(char * str)
	{
		Tree * tree = new Tree();
		tree->root = new TreeNode();
		int index = 0;
		const int length = strlen(str);
		makeTree(tree->root, str, index, length);

		return tree;
	}
}