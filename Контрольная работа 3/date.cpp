#include <iostream>
#include "date.h"
#include "string.h"

using std::cout;

namespace DateSpace
{
	bool isDate(char * str)
	{
		const int lenght = strlen(str);

		if (lenght != 10)
			return false;

		for (int i = 0; i < lenght; ++i)
   		{
   			if (i == 2 || i == 5)
   			{
   				if (str[i] != '.') 
   					return false;
   			}	
   			else
   			{
   				if (!(str[i] >= '0' && str[i] <= '9'))
   					return false;	
   			}
   		}
   		return true;
	}

	Date initDate(char * str)
	{
		Date date;
		date.day = (str[0] - '0') * 10 + (str[1] - '0');
		date.month = (str[3] - '0') * 10 + (str[4] - '0');
		date.year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
		
		return date;
	}

	bool theFirstDateBigger (Date firstDate, Date secondDate)
	{  	
		if (firstDate.year > secondDate.year)
			return true;

		if (firstDate.year < secondDate.year)
			return false;

		if (firstDate.month > secondDate.month)
			return true;

		if (firstDate.month < secondDate.month)
			return false;

		if (firstDate.day > secondDate.day)
			return true;

		if (firstDate.day < secondDate.day)
			return false;

  	 	return false;
	}  	

	Date copyDate (Date date)
	{
		Date answer;
		answer.day = date.day;
		answer.month = date.month;
		answer.year = date.year;
	
		return answer;
	}

	void writeDate(Date date)
	{
		cout << date.day << "." << date.month << "." << date.year;
	}
}  	