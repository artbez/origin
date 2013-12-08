#include <iostream>
#include <string.h>

using std::cin;
using std::cout;

int main()
{
	int size = 1000;
	char *str = new char[size];
	
	cout << "Enter a string\n";
	cin.getline(str, size);
	
	int neededLength = 0;
	cout << "Enter the neededLength\n";
	cin >> neededLength;

	int numberOfWords = 0;

	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			numberOfWords++;
		}
	}
	numberOfWords++;

	int beginSpace = (neededLength - length) / (numberOfWords - 1);
	int endinSpace = (neededLength - length) % (numberOfWords - 1);

	cout << "The answer is ";

	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			for (int j = 0; j < beginSpace; ++j)
			{
				cout << ' ';
			}
			if (endinSpace > 0)
			{
				cout << ' ';
				endinSpace--;
			}
		}

		cout << str[i]; 
	}

	delete[] str;

	return 0;
}