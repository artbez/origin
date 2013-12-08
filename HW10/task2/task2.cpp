#include <iostream>
#include "list.h"
#include "tree.h"

using std::cin;
using std::cout;

using namespace TreeSpace;

int main()
{
	freopen("file.out", "r", stdin);
	freopen("result.in", "w", stdout);

	const int size = 1000;
	char * str = new char[size];
	cin.getline(str, size);

	Tree * tree = makeTree(str);
	char * mainStr = toString(tree);
	cout << mainStr << "\n";

	delete[] mainStr;
	char ch;
	TreeNode * tn = tree->root;
	while(cin >> ch)
	{
		if (ch == '0')
			tn = tn->left;
		if (ch == '1')
			tn = tn->rigth;
		if ((tn->left == NULL) && (tn->rigth == NULL))
		{
			cout << tn->character;
			tn = tree->root;
		}
	}

	delete[] str;
	deleteTree (tree);
	delete tree;
	return 0;
}