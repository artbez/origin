#include <iostream>
#include "set.h"

using std::cin;
using std::cout;

namespace setSpace
{

	SetNode * createLeaf(int value)
	{
		SetNode * setNode = new SetNode();
		setNode->leftChild = NULL;
		setNode->rightChild = NULL;
		setNode->value = value;

		return setNode;
	}

	Set * create()
	{
		Set * set = new Set();
		set->root = NULL;
		return set;
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

	SetNode *& findSmaller(SetNode *&setNode)
	{
		if (setNode->leftChild != NULL)
		{
			findSmaller(setNode->leftChild);
		}
		return setNode->leftChild;
	}
	

	void deleteValue(int value, Set *&curSet)
	{
		SetNode *& finded = find(value, curSet->root);
		if (finded != NULL)
		{
			if ((finded->leftChild != NULL) && (finded->rightChild != NULL))
			{
				SetNode *& tmp = findSmaller(finded->rightChild);
				finded->value = tmp->value;
				delete tmp;
				tmp = NULL;
				return;
			}
			
			if ((finded->leftChild != NULL) && (finded->rightChild == NULL))
			{
				SetNode * deleter = finded; 
				finded = finded->leftChild;
				deleter->leftChild = NULL;
				delete deleter;
				deleter = NULL;
				return;
			}

			if ((finded->leftChild == NULL) && (finded->rightChild != NULL))
			{
				SetNode * deleter = finded; 
				finded = finded->rightChild;
				deleter->rightChild = nullptr;
				delete deleter;
				deleter = NULL;
				return;
			}

			delete finded;
			finded = NULL;
			
		}
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