#include <iostream>
#include "avl.h"

using std::cin;
using std::cout;

using namespace avlSpace;

int main()
{
	Set * set = create();
	addValue(1, set);
	addValue(2, set);
	addValue(3, set);
	addValue(4, set);

	addValue(5, set);
	addValue(6, set);
	addValue(7, set);
	addValue(8, set);

	addValue(9, set);
	addValue(10, set);
	addValue(11, set);
	addValue(12, set);
	
	addValue(13, set);
	addValue(14, set);
	addValue(15, set);
	addValue(16, set);

	printInIncreasing(set);
	cout << "\n";
	deleteValue(8, set);
	deleteValue(4, set);
	deleteValue(3, set);
	deleteValue(2, set);
	
	printInIncreasing(set);
	cout << "\n";

	cout << isExist(3, set);
	cout << "\n";

	printInDecreasing(set);
	cout << "\n";

	printInDirect(set);
	deleteSet(set);
	delete set;
	set = nullptr;
	return 0;
}