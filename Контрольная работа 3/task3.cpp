#include <iostream>
#include "stack.h"
#include <fstream>

using std::cin;
using std::cout;

using namespace StackSpace;

int main()
{
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);

	int a = 0;
	int b = 0;
	
	cin >> a >> b;

	int curNumber = 0;
	Stack firstStack;
	init(firstStack);

	Stack secondStack;
	init(secondStack);

	Stack thirdStack;
	init(thirdStack);


	while(cin >> curNumber)
	{
		if (curNumber < a)
			add(curNumber, firstStack);
		if (curNumber >= a && curNumber <= b)
			add(curNumber, secondStack);
		if (curNumber > b)
			add(curNumber, thirdStack);	
	}

	printRemotedStack(firstStack);
	cout << "\n";
	printRemotedStack(secondStack);
	cout << "\n";
	printRemotedStack(thirdStack);

	deleteStack(firstStack);
	deleteStack(secondStack);
	deleteStack(thirdStack);

	return 0;
}