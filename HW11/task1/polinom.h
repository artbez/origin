#include "pair.h"

struct ListElement
{
	Pair mono;
	ListElement * next;
};

struct Polinom
{
	ListElement * head;
};

Polinom * make(int * arr, const int size);
bool equals(Polinom * pol1, Polinom * pol2);
int value(Polinom * pol, int point);
Polinom * add(Polinom * pol1, Polinom * pol2);
void printPolinom(Polinom * pol);
void deletePolinom(Polinom *& pol);