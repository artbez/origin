#include <iostream>
#include "set.h"

using std::cin;
using std::cout;

using namespace setSpace;

int main()
{
	Set * set = create();
	addValue(4, set);
	addValue(6, set);
	addValue(3, set);
	addValue(5, set);

	printInIncreasing(set);
	cout << "\n";
	deleteValue(4, set);
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