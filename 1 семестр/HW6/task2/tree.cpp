#include <iostream>
#include "tree.h"

using std::cin;
using std::cout;
using std::cerr;

namespace TreeSpace
{
	
	TreeNode * createL(char *str, int &index)
	{
		
		while((str[index] == ' ') || (str[index] == ')')) index++;
			
		TreeNode * treeNode = new TreeNode();
		
		if (str[index] == '(')
		{
			index++;
			treeNode->value = str[index];
			treeNode->isLeaf = false;
			
			index++;
			treeNode->leftChild = createL(str, index);
			treeNode->rigthChild = createL(str, index);	
		}
		else
		{
			int val = 0;
			int powTen = 10;
			if (str[index] == '-') 
			{
				powTen = -10;
				index++;
			}
			while(str[index] >= '0' && str[index] <= '9')
			{
				val *= powTen;
				val += (str[index] - '0');
				index++;
			}

			index++;
			treeNode->value = val;
			treeNode->isLeaf = true;
			treeNode->leftChild = NULL;
			treeNode->rigthChild = NULL;
		}
		
		return treeNode;
	}

	Tree * create(char *str)
	{
		Tree * tree = new Tree();
		tree->root = NULL;
		int index = 0;
		tree->root = createL(str, index);
		return tree;
	}
	
	void printTree(TreeNode *treeNode)
	{
		if (treeNode->isLeaf)
		{
			cout << treeNode->value;
		}
		else
		{
			cout << "(" << (char) treeNode->value << " ";
			printTree(treeNode->leftChild);
			cout << " ";
			printTree(treeNode->rigthChild);
			cout << ")";
		}
	}

	
	void deleteTree(TreeNode *&treeNode)
	{
		if (treeNode != NULL)
		{
			deleteTree(treeNode->leftChild);
			deleteTree(treeNode->rigthChild);
			delete treeNode;
			treeNode = NULL;
		}
	}

	void deleteTree(Tree *tree)
	{
		deleteTree(tree->root);
	}

	void printTree(Tree *tree)
	{
		if (tree->root != NULL)
			printTree(tree->root);
	}
	
	int countTree(TreeNode * treeNode)
	{
		if (treeNode->isLeaf)
		{
			return treeNode->value;
		}
		else
		{
			switch (treeNode->value)
			{
				case '+':	return countTree(treeNode->leftChild) + countTree(treeNode->rigthChild); break;
				case '*':	return countTree(treeNode->leftChild) * countTree(treeNode->rigthChild); break;			
				case '-':	return countTree(treeNode->leftChild) - countTree(treeNode->rigthChild); break;	
				case '/':	
				{
					int second = countTree(treeNode->rigthChild);
					if (second != 0)
						return countTree(treeNode->leftChild) / second; 
					else
					{
						cerr << "Division by zero";
						exit(0);
					}
					break;
				}
			}
		}

		return 0;
	}

	int countTree(Tree *tree)
	{
		return countTree(tree->root);
	}

}