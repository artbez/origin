#include <iostream>
#include <string.h>

using namespace std;

int takeHash(char *str, const int magicNumber, const int module);
int stepOfStep(int number, const int step, const int module);

int main()
{
	const int size = 1000;
	char *str = new char[size];
	cin >> str;
	char *subStr = new char[size];
	cin >> subStr;

	const int magicNumber = 237;
	const int module = 9941;
	int initHash = takeHash(subStr, magicNumber, module);
	
	const int lengthOfStr = strlen(str);
	const int lengthOfSubStr = strlen(subStr);
	
	int curHash = 0;
	bool flag = false;
	const int magicPower = stepOfStep(magicNumber, lengthOfSubStr - 1, module);
	for (int i = 0; i < lengthOfStr; ++i)
	{
		if (i < lengthOfSubStr)
		{
			curHash = (str[i] + curHash * magicNumber) % module;
		}
		else
		{
			if (curHash == initHash)
			{
				cout << i - lengthOfSubStr << " ";
				flag = true;
			}
			curHash = (curHash - (((int)str[i - lengthOfSubStr]) * magicPower) % module) % module;
			if (curHash < 0) curHash = module + curHash;
			curHash = (curHash * magicNumber) % module + str[i];
			curHash %= module;
		}
	}
	
	if (curHash == initHash)
	{
		cout << lengthOfStr - lengthOfSubStr;
		flag = true;
	}	

	if (!flag) cout << "No";

	delete[] str;
	delete[] subStr;
	
	int n;
	cin >> n;
	return 0;
}

int takeHash(char *str, const int magicNumber, const int module)
{
	int answer = 0;
	const int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		answer = (str[i] + answer * magicNumber) % module;
	}
	return answer;
}

int stepOfStep(int number, const int step, const int module)
{
	int answer = 1;
	for (int i = 0; i < step; ++i)
	{
		answer *= number;
		answer %= module;
	}
	return answer;
}
