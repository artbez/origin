#include <iostream>
#include <fstream>
#include "user.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

using namespace UserSpace;

enum userCommand 
{
	quit,
	addUser,
	findNumber,
	findName,
	saveThis,
	notAcommand
};

userCommand toUserComand(int number);

int main()
{
	ifstream fin ("phone.txt");
		
	const int size = 1000;
	User * arrayOfUsers = new User[size];
	int numberOfUsers = 0;

	if (fin != NULL)
	{
		while (!fin.eof())
		{
			char * curName = new char[size];
			fin >> curName;
			char * curPhone = new char[size];
			fin >> curPhone;
			addUserToArray(arrayOfUsers, numberOfUsers, curName, curPhone);	
		}
	}

	fin.close();

	while(true)
	{
		cout << "Enter a command\n";
		int number;
		cin >> number;
		userCommand userCom = quit;
		userCom = toUserComand(number);
	
		switch(userCom)
		{
			case quit: 
			{
				void cleanMind(User arrayOfUsers, int numberOfUsers);
				return 0;
			}
			case addUser:
			{
				char * curName = new char[size];
				cin >> curName;
				char * curPhone = new char[size];
				cin >> curPhone;
				addUserToArray(arrayOfUsers, numberOfUsers, curName, curPhone);
	
				break;
			}
			case findNumber:
			{
				char * curName = new char[size];
				cin >> curName;
				findNumberOfUser(arrayOfUsers, numberOfUsers, curName);

				delete[] curName;
				break;
			}

			case findName:
			{
				char * curPhone = new char[size];
				cin >> curPhone;
				findNameOfUser(arrayOfUsers, numberOfUsers, curPhone);
				
				delete[] curPhone;
				break;
			}

			case saveThis:
			{
				ofstream fout ("phone.txt");
				for (int i = 0; i < numberOfUsers; ++i)
				{
					fout << getName(arrayOfUsers[i]) << " " << getPhoneNumber(arrayOfUsers[i]) << "\n";
				}
				fout.close();
				
				break;
			}

			case notAcommand:
			{
				cout << "It is not a command\n";
			}
		}
	}
	return 0;
}

userCommand toUserComand(int number)
{
	switch(number)
	{
		case 0: return quit;
		case 1: return addUser;
		case 2: return findNumber;
		case 3: return findName;
		case 4: return saveThis;
		default : return notAcommand;
	}
}
