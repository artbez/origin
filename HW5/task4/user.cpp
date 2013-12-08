#include "user.h";
#include <iostream>
#include <string>

using std::cin;
using std::cout;

namespace UserSpace
{
	char * getName(User us)
	{
		return us.name;
	}

	char * getPhoneNumber(User us)
	{
		return us.phoneNumber;
	}

	User createUser(char *name, char *phoneNumber)
	{
		User us;
		us.name = name;
		us.phoneNumber = phoneNumber;

		return us;
	}

	void addUserToArray(User *&users, int &length, char *name, char *phoneNumber)
	{
		User us = createUser(name, phoneNumber);
		users[length] = us;
		length++;
	}
	
	void findNumberOfUser(User *users, int length, char *curName)
	{
		
		for (int i = 0; i < length; ++i)
		{
			if (strcmp(curName, getName(users[i])) == 0)
			{
				cout << getPhoneNumber(users[i]) << "\n";
				break;
			}
		}
	}

	void findNameOfUser(User *users, int length, char *curPhone)
	{
		
		for (int i = 0; i < length; ++i)
		{
			if (strcmp(curPhone, getPhoneNumber(users[i])) == 0)
			{
				cout << getName(users[i]) << "\n";
				break;
			}
		}

	}

	void cleanMind(User *users, int sizeOfArray)
	{
		for (int i = 0; i < sizeOfArray; ++i)
		{
			delete[] users[i].name;
			delete[] users[i].phoneNumber;
		}
		delete[] users;
	}
}