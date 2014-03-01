#include <iostream>
#include <stdio.h>
#include <math.h>

using std::cin;
using std::cout;

int main()
{
	double x = 12312.323;
	cout << "Enter a double number\n";
	cin >> x;

	if (x == 0)
	{
		cout << "0*0^0";
		return 0;
	}

	unsigned short * b = (unsigned short*)&x;
	unsigned short s = (unsigned)b[3];

	unsigned int twoInFifteen = pow(2, 15);

	if ((twoInFifteen & (unsigned)b[3]) == 0)
	{
		cout << "+";
	}
	else
	{
		s -= pow(2, 15);
		cout << "-";
	}

	s >>= 4;

	int power = s - pow(2, 10) + 1;
	
	unsigned char ty = ((unsigned)b[3] & 15);
	
	printf("%f", 1 + (float)( ty * pow(2, 32) + (unsigned)b[2] * pow(2, 16) + (unsigned)b[0]) / pow(2, 36));
	cout << "*2^" << power; 
	return 0;
}