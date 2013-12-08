namespace TreeSpace
{
	struct TreeNode
	{
		int value;
		bool isLeaf;
		TreeNode * leftChild;
		TreeNode * rigthChild;
	};

	struct Tree
	{
		TreeNode * root;
	};

	Tree * create(char *str);
	void printTree(Tree *tree);
	int countTree(Tree *tree);
	void deleteTree(Tree *tree);
}