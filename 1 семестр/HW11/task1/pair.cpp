#include "pair.h"
#include <iostream>


bool equals(Pair p1, Pair p2)
{
	return ((p1.first == p2.first) && (p1.second == p2.second));
}

void makeClone(Pair &p1, Pair p2)
{
	p1.first = p2.first;
	p1.second = p2.second;
}

void printPair(Pair p)
{
	
	if (p.second != 1 && p.second != -1 || p.first == 0) 
		std::cout << p.second;
	if (p.second == -1 && p.first != 0)
		std::cout << "-";
	if (p.first != 0)
		std::cout << "x^(" << p.first << ")";
}