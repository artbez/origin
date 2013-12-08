namespace myStringSpace
{
	struct MyString
	{
		int length;
		char * mainString;
	};

	MyString initMyString();
	void deleteMyString(MyString &myStr);
	MyString toMyString(char *str);
	MyString clone(const MyString &myStr);
	MyString conc(const MyString &myStr1, const MyString &myStr2);
	char * toString(const MyString &myStr);
	void printString(const MyString &myStr);
	int lengthOfMyString(const MyString &myStr);
	bool isEqual(const MyString &myStr1, const MyString &myStr2);
	bool isEmpty(const MyString &myStr);
	MyString subStr(int begin, int end, const MyString &myStr);
}