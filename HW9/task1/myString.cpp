#include "myString.h"
#include <iostream>
#include <string.h>

using std::cout;

namespace myStringSpace
{
	MyString initMyString()
	{
		MyString myStr;	
		myStr.length = 0;
		myStr.mainString = nullptr;
		return myStr;
	}

	void deleteMyString(MyString &myStr)
	{
		delete[] myStr.mainString;
		myStr.mainString = nullptr;
	}

	MyString toMyString(char *str)
	{
		MyString myString = initMyString();
		int length = strlen(str);

		const int size = length + myString.length;
		myString.length = size;
		myString.mainString = new char[size];

		for (int i = 0; i < size; ++i)
		{
			myString.mainString[i] = str[i];
		}

		return myString;
	}

	MyString clone(const MyString &myStr)
	{
		MyString answer = toMyString(myStr.mainString);
		return answer;
	}
	
	MyString conc(const MyString &myStr1, const MyString &myStr2)
	{
		MyString answer = initMyString();
		const int length1 = myStr1.length;
		const int length2 = myStr2.length;

		answer.length = length1 + length2;
		answer.mainString = new char[answer.length];
		for (int i = 0; i < answer.length; ++i)
		{
			if (i < length1)
				answer.mainString[i] = myStr1.mainString[i];
			else
				answer.mainString[i] = myStr2.mainString[i - length1];
		}

		return answer;
	}

	char * toString (const MyString &myStr)
	{
		return myStr.mainString;
	}

	void printString(const MyString &myStr)
	{
		for (int i = 0; i < myStr.length; ++i)
		{
			cout << myStr.mainString[i];
		}
	}

	int lengthOfMyString(const MyString &myStr)
	{
		return myStr.length;
	}

	bool isEqual(const MyString &myStr1, const MyString &myStr2)
	{
		if (myStr1.length == myStr2.length)
		{
			for (int i = 0; i < myStr1.length; ++i)
			{
				if (myStr1.mainString[i] != myStr2.mainString[i])
					return false;
			}

			return true;
		}
		return  false;
	}

	bool isEmpty(const MyString &myStr)
	{
		return (myStr.length == 0);
	}

	MyString subStr(int begin, int end, const MyString &myStr)
	{
		const int size = end - begin;
		MyString answer;
		answer.length = size;
		answer.mainString = new char[size];
		
		for (int i = begin; i < end; ++i)
		{
			answer.mainString[i - begin] = myStr.mainString[i];
		}

		return answer;
	}
}