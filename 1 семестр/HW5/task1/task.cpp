#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::ifstream;

int main()
{
	ifstream myFile ("fail.txt");
	const int size = 100;
	char *str = new char[size]; 
	while(!myFile.eof())
	{
		myFile >> str;	
		int length = strlen(str);
		const int numberOfLetters = 26;
		bool *wasHere = new bool[numberOfLetters];
		for (int i = 0; i < numberOfLetters; ++i)
		{
			wasHere[i] = false;
		}

		for (int i = 0; i < length; ++i)
		{
			if ((str[i] >= 'a') && (str[i] <= 'z'))
			{
				if (!wasHere[str[i] - 'a'])
				{
					cout << str[i];
					wasHere[str[i] - 'a'] = true;
				}
			}
			 
			if ((str[i] >= 'A') && (str[i] <= 'Z'))
			{
				if (!wasHere[str[i] - 'A'])
				{
					cout << str[i];
					wasHere[str[i] - 'A'] = true;
				}
			}
		}

		delete[] wasHere;
		cout << " ";
	}

	delete[] str;
	myFile.close();
	return 0;
}