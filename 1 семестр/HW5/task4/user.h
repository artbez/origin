namespace UserSpace
{
	struct User
	{
		char *name;
		char *phoneNumber;
	};

	char * getName(User us);
	char * getPhoneNumber(User us);
	User createUser(char *name, char *phoneNumber);
	void addUserToArray(User *&users, int &length, char *name, char *phoneNumber);
	void findNameOfUser(User *users, int length, char *phoneNumber);
	void findNumberOfUser(User *users, int length, char *name);
	void cleanMind(User *users, int sizeOfArray);
}