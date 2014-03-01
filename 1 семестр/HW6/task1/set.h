namespace setSpace {
	
	struct SetNode	
	{
		int value;
		SetNode *leftChild;
		SetNode *rightChild;
	};

	struct Set
	{
		SetNode *root;
	};

	Set * create();
	void addValue(int value, Set *&curSet);
	void deleteValue(int value, Set *&curSet);
	bool isExist(int value, Set *&curSet);
	void deleteSet(Set *&curSet);
	void printInIncreasing(Set *curSet);
	void printInDecreasing(Set *curSet);
	void printInDirect(Set *curSet);
}