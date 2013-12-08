#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::cerr;

struct Pair
{
	int first;
	int second;
};

int getLabel(Pair curPair, Pair * pArr, int * label, int * position);

int main()
{
	freopen("student.in", "r", stdin);
	freopen("student.out", "w", stdout);

	int numberOfStudent;
	cin >> numberOfStudent;

	const int size = 1000;
	Pair * pArr = new Pair[size];
	int * position = new int[size];
	int * label = new int[size];

	for (int i = 0; i < size; ++i)
	{
		position[i] = 0;
		label[i] = 0;
	}

	label[1] = 1;
	label[2] = 2;
	label[3] = 3;

	Pair currPair;
	int numberOfPairs = 1;
	
	while(cin >> currPair.first && cin >> currPair.second)
	{
		pArr[numberOfPairs] = currPair;
		position[currPair.first] = numberOfPairs;
		numberOfPairs++;
	}

	for (int i = 1; i < numberOfPairs; ++i)
	{
		if (label[pArr[i].first] == 0)
		{
			getLabel(pArr[i], pArr, label, position);
		}
	}

	for (int i = 1; i <= numberOfStudent; ++i)
	{
		if (label[i] != 0)
			cout << i << " " << label[i] << "\n";
		else
			cout << "student " << i << " must be certified\n";
	}
	
	delete[] position;
	delete[] label;
	delete[] pArr;
	return 0;
}

int getLabel(Pair curPair, Pair * pArr, int * label, int * position)
{	
	switch(label[curPair.second])
	{
		case 1:
		case 2:
		case 3:
		{
			label[curPair.first] = label[curPair.second];
			break;
		}
		case 0:
		{
			label[curPair.first] = getLabel(pArr[position[curPair.second]], pArr, label, position);
			break;
		}
	}
	return label[curPair.first];
}
