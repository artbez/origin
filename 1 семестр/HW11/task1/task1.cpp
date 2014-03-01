#include <iostream>
#include "polinom.h"

using std::cin;
using std::cout;

enum commands {Equals, Value, Add, Quit};

int main()
{
	const int size = 100;
	int * coPol1 = new int[size];
	int * coPol2 = new int[size];

	int length1 = 0;
	cout << "Enter the size of the first polinom\n";
	cin >> length1;
	cout << "Enter coeficients of the polinom\n";
	for (int i = 0; i < length1; ++i)
	{
		cin >> coPol1[i];
	}
	Polinom * pol1 = make(coPol1, length1);
	
	int length2 = 0;
	cout << "Enter the size of the second polinom\n";
	cin >> length2;
	cout << "Enter coeficients of the polinom\n";
	for (int i = 0; i < length2; ++i)
	{
		cin >> coPol2[i];
	}
	Polinom * pol2 = make(coPol2, length2);

	delete[] coPol1;
	delete[] coPol2;

	bool flag = true;
	while (flag)
	{
		int com = 0;
		cout << "Enter a command\n";
		cin >> com;

		switch (com)
		{
		case Equals:
			{
				if (equals(pol1, pol2))
					cout << "They are equals\n";
				else
					cout << "They are not equals\n";
				break;
			}
		case Value: 
			{
				int point = 0;
				cout << "Enter the point\n";
				cin >> point;

				cout << "Value of first is " << value(pol1, point) << "\n";
				cout << "Value of second is " << value(pol2, point) << "\n";
				break;
			}
		case Add: 
			{
				Polinom * pol = add(pol1, pol2);
				printPolinom(pol);
				cout << "\n";
				deletePolinom(pol);
				break;
			}
		case Quit: 
			{
				deletePolinom(pol1);
				deletePolinom(pol2);
				delete pol1;
				delete pol2;
				flag = false;
				break;
			}
		}
	}

	return 0;
}