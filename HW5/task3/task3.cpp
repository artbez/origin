#include <iostream>
#include <fstream>
#include <string.h>

using std::cin;
using std::cout;
using std::ifstream;

int main()
{
	ifstream fin ("file.txt");
	
	const int size = 1000;
	char *str = new char[size];

	bool wasRemark = false;
	bool isString = false;
	while(!fin.eof())
	{
		fin.getline(str, size); 
		int length = strlen(str);
		int i = 1;                                  
		while (i < length)
		{
			if ((str[i - 1] == '\"') && !wasRemark)
			{
				while((i < length) && (str[i] != '\"')) 
				{
					i++;
				}
				i++;
			}
		
			if (i == length)
				break;

			if (!wasRemark)
			{
				if (str[i - 1] == '/' && str[i] == '/')
				{
					while(i <= length)
					{
						cout << str[i - 1];
						++i;
					}
					cout << "\n";
					break;	
				}
				if (str[i - 1] == '/' && str[i] == '*')
				{
					wasRemark = true;
				}
			}

			if (str[i - 1] == '*' && str[i] == '/')
			{
				wasRemark = false;
			}
			
			++i;
		}		
	}

	delete[] str;
	fin.close();
	return 0;
}
