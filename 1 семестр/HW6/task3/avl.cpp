#include <iostream>
#include "avl.h"

using std::cin;
using std::cout;

namespace avlSpace
{

	SetNode * createLeaf(int value)
	{
		SetNode * setNode = new SetNode();
		setNode->leftChild = NULL;
		setNode->rightChild = NULL;
		setNode->value = value;
		setNode->height = 1;
		return setNode;
	}

	Set * create()
	{
		Set * set = new Set();
		set->root = NULL;
		return set;
	}

	int height(SetNode *setNode)
	{
		return (setNode != NULL) ? setNode->height : 0;
	}

	int balanceFactor(SetNode *setNode)
	{
		return height(setNode->rightChild) - height(setNode->leftChild);
	}	

	void updateHeight(SetNode *&setNode)
	{
		int heightLeft = height(setNode->leftChild);
		int heightRight = height(setNode->rightChild);
		setNode->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
	}

	SetNode * rotateRight(SetNode *&root)
	{
		SetNode *pivot = root->leftChild;
		root->leftChild = pivot->rightChild;
		pivot->rightChild = root;
		updateHeight(root);
		updateHeight(pivot);
		return pivot;
	}

	SetNode * rotateLeft(SetNode *&root)
	{
		SetNode *pivot = root->rightChild;
		root->rightChild = pivot->leftChild;
		pivot->leftChild = root;
		updateHeight(root);
		updateHeight(pivot);
		return pivot;
	}

	void balance(SetNode *&setNode)
	{
		updateHeight(setNode);

		if (balanceFactor(setNode) == 2)
		{
			if (balanceFactor(setNode->rightChild) < 0)
				setNode->rightChild = rotateRight(setNode->rightChild);
			setNode = rotateLeft(setNode);
			return;
		}
		
		if (balanceFactor(setNode) == -2)
		{
			if (balanceFactor(setNode->leftChild) < 0)
				setNode->leftChild = rotateRight(setNode->leftChild);
			setNode = rotateRight(setNode);
			return;
		}
	}

	void addValue(int value, SetNode *&setNode)
	{
		if(setNode != NULL)
		{
			if (value < setNode->value)
			{
				addValue(value, setNode->leftChild);
			}
			if (value > setNode->value)
			{
				addValue(value, setNode->rightChild);
			}
			balance(setNode);
			return;
		}
		SetNode * leaf = createLeaf(value);
		setNode = leaf;
	}
	
	void addValue(int value, Set *&curSet)
	{
		addValue(value, curSet->root);
	}
	
	
	SetNode *& find(int value, SetNode *&setNode)
	{
		if(setNode != NULL)
		{
			if (value < setNode->value)
			{
				return find(value, setNode->leftChild);
			}
			if (value > setNode->value)
			{
				return find(value, setNode->rightChild);
			}
		}
	
		return setNode;
	}

	int findSmaller(SetNode *&setNode)
	{
		if (setNode->leftChild != NULL)
		{
			int ans = findSmaller(setNode->leftChild);
			balance(setNode);
			return ans;
		}

		int mAns = setNode->value;
		delete setNode;
		setNode = NULL;
		return mAns;
	}
	
	void deleteValue(int value, SetNode *&setNode)
	{
		if(setNode != NULL)
		{
			if (value < setNode->value)
			{
				deleteValue(value, setNode->leftChild);
			}
			if (value > setNode->value)
			{
				deleteValue(value, setNode->rightChild);
			}
			if (value == setNode->value)
			{
				if ((setNode->leftChild != NULL) && (setNode->rightChild != NULL))
				{
					int tmp = findSmaller(setNode->rightChild);
					setNode->value = tmp;
					balance(setNode);
					return;
				}
			
				if ((setNode->leftChild != NULL) && (setNode->rightChild == NULL))
				{
					SetNode * deleter = setNode; 
					setNode = setNode->leftChild;
					deleter->leftChild = NULL;
					delete deleter;
					deleter = NULL;
					balance(setNode);
					return;
				}

				if ((setNode->leftChild == NULL) && (setNode->rightChild != NULL))
				{
					SetNode * deleter = setNode; 
					setNode = setNode->rightChild;
					deleter->rightChild = nullptr;
					delete deleter;
					deleter = NULL;
					balance(setNode);
					return;
				}

				delete setNode;
				setNode = NULL;
				
			}
			else
			{
				balance(setNode);
			}
		}
	}

	void deleteValue(int value, Set *&curSet)
	{
		deleteValue(value, curSet->root);
	}
	
	bool isExist(int value, Set *&curSet)
	{
		return (find(value, curSet->root) != NULL);
	}

	void deleteSet(SetNode *&setNode)
	{
		if (setNode != NULL)
		{
			deleteSet(setNode->leftChild);
			deleteSet(setNode->rightChild);
			
			delete setNode;
			setNode = NULL;
		}
	}

	void deleteSet(Set *&curSet)
	{
		deleteSet(curSet->root);
	}

	void printInIncreasing(SetNode *setNode)
	{
		if (setNode != NULL)
		{
			printInIncreasing(setNode->leftChild);
			cout << setNode->value << " ";
			printInIncreasing(setNode->rightChild);
		}
	}

	void printInIncreasing(Set *curSet)
	{
		printInIncreasing(curSet->root);
	}
	
	void printInDecreasing(SetNode *setNode)
	{
		if (setNode != NULL)
		{
			printInDecreasing(setNode->rightChild);
			cout << setNode->value << " ";
			printInDecreasing(setNode->leftChild);
		}
	}

	void printInDecreasing(Set *curSet)
	{
		printInDecreasing(curSet->root);
	}
	
	void printInDirect(SetNode *setNode)
	{
		if (setNode != NULL)
		{
			cout << "(" << setNode->value << " ";
			printInDirect(setNode->leftChild);
			cout << ", ";
			printInDirect(setNode->rightChild);
			cout << ")";
		}
		else
		{
			cout << "null";
		}
	}

	void printInDirect(Set *curSet)
	{
		printInDirect(curSet->root);
	}
}