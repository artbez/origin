#include <iostream>

using std::cin;
using std::cout;

void qsort(int array[], int firstIndex, int secondIndex);

int main()
{
	const int size = 1000;
	int mainArray[size];

	int length = 0;
	cout << "Enter the length of an array\n";
	cin >> length;

	cout << "Enter the elements\n";
	for (int i = 0; i < length; ++i)
	{
		cin >> mainArray[i];
	}

	qsort(mainArray, 0, length - 1);

	int indexOfEl = length - 1;

	for (int i = length - 2; i >= 0; --i)
	{
		if (mainArray[i] == mainArray[i + 1])
		{
			indexOfEl = i;	
		}		
	}

	if (indexOfEl != length - 1)
	{
		cout << "The answer is " << mainArray[indexOfEl];
	}
	else
	{
		cout << "There are not that element";
	}

	return 0;
}

void qsort(int array[], int firstIndex, int secondIndex)
{
	int mainEl = array[firstIndex];
	int l = firstIndex;
	int r = secondIndex;

	while (l < r)
	{
		while ((array[l] < mainEl) && (l < secondIndex))
		{
			l++;
		}

		while ((array[r] > mainEl) && (r > firstIndex))
		{
			r--;
		}

		if (l <= r)
		{
			int changer = array[l];
			array[l] = array[r];
			array[r] = changer;
			l++;
			r--;
		}

	}

	if (r > firstIndex)
	{
		qsort(array, firstIndex, r);
	}

	if (secondIndex > l)
	{
		qsort(array, l, secondIndex);
	}
}

	