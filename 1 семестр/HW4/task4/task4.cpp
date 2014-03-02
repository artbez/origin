#include <iostream>
#include "toOpz.h"
#include "calculateByOpz.h"

using std::cin;
using std::cout;

int main()
{
	const int size = 100;
	char *str = new char[size];
	cout << "Enter an expression\n";
	cin.getline(str, size);

	cout << "The answer is \n";
//	cout << toOpz(str);
	cout << calculateByOpz(toOpz(str));
	delete[] str;
	return 0;
}

        