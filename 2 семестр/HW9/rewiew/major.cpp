#include "list1.h"

using namespace std;

enum Change { exitProgramm, add1, del1, pop1, show1, add2, del2, pop2, show2};

Change intToChange(int one) {
	return static_cast<Change>(one);
}

int main() {
	allLists* left = new pointList();
	allLists* right = new arrayList();

	cout << "Welcome!" << endl << "Enter the number of state" << endl;
	cout << "0 = exit" << endl;
	cout << "1 = add 1" << endl;
	cout << "2 = delete all 1" << endl;
	cout << "3 = pop 1" << endl;
	cout << "4 = show 1" << endl;
	cout << "5 = add 2" << endl;
	cout << "6 = delete all 2" << endl;
	cout << "7 = pop 2" << endl;
	cout << "8 = show 2" << endl;
	
	int buffer = 0;

	for (;;) {
		cout << "Enter number of state" << endl;
		int changeTemp = 0;
		Change c;
		cin >> changeTemp;

		if (!((changeTemp >= 0) && (changeTemp <= 8))) {
			cout << "Wrong command!" << endl;
			return 0;
		}

		c = intToChange(changeTemp);

		if (c == exitProgramm) {
			cout << "L.A.Goodbay" << endl;
			break;
		}
		if ( c == add1) {
			cout << "enter value\n";
			cin >> buffer;
			left->push(buffer);
		}
		if ( c == del1) {
			left->clean();
		}
		if ( c == pop1) {
			left->pop();
		}
		if (c == show1) {
			left->print();
		}

		if ( c == add2) {
			cout << "enter value\n";
			cin >> buffer;
			right->push(buffer);
		}
		if ( c == del2) {
			right->clean();
		}
		if ( c == pop2) {
			right->pop();
		}
		if (c == show2) {
			right->print();
		}
	}

	left->clean();
	right->clean();
	return 0;
}
