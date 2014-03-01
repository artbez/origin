namespace DateSpace
{
	struct Date
	{
		int day;
		int month;
		int year;
	};

	Date initDate(char * str);
	bool isDate(char * str);
	bool theFirstDateBigger (Date firstDate, Date secondDate);
	Date copyDate (Date date);
	void writeDate (Date date);
}                   