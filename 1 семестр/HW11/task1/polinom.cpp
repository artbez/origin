#include "polinom.h"
#include <iostream>


Polinom * init()
{
	Polinom * polinom = new Polinom();
	polinom->head = new ListElement();
	polinom->head->next = NULL;
	
	return polinom;
}

Polinom * make(int * arr, const int size)
{
	Polinom * polinom = init();
	
	ListElement * le = polinom->head;
	for (int i = 0; i < size; ++i)
	{
		ListElement * newEl = new ListElement();
		Pair p;
		p.first = i;
		p.second = arr[i];
		if (arr[i] != 0)
		{
			newEl->mono = p;
			newEl->next = NULL;
			le->next = newEl;
			le = le->next;
		}
		else
		{
			delete newEl;
		}
	}

	return polinom;
}

void correct(Polinom *&pol)
{
	ListElement * le = pol->head;
	while(le->next != NULL)
	{
		if (le->next->mono.second == 0)
		{
			ListElement * changer = le->next;
			le->next = le->next->next;
			delete changer;
		}
		else
			le = le->next;
			
	}
	
	if (pol->head->next == NULL)
	{
		ListElement * newEl = new ListElement();
		newEl->mono.first = 0;
		newEl->mono.second = 0;
		newEl->next = NULL;
		pol->head->next = newEl;
	}	
}

bool equals(Polinom * pol1, Polinom * pol2)
{
	ListElement * le1 = pol1->head->next;
	ListElement * le2 = pol2->head->next;

	while(le1 != NULL)
	{
		if (le2 == NULL || !equals(le1->mono, le2->mono))
			return false;
		le1 = le1->next;
		le2 = le2->next;
	}

	return (le2 == NULL);
}

int value(Polinom * pol, int point)
{
	int answer = 0;
	int curStep = 1;
	ListElement * le = pol->head->next;
	while(le != NULL)
	{
		answer += curStep * (le->mono.second); 
		curStep *= point;
		le = le->next;
	}

	return answer;
}

Polinom * add(Polinom * pol1, Polinom * pol2)
{
	Polinom * answer = init();
	
	ListElement * le1 = pol1->head->next;
	ListElement * le2 = pol2->head->next;
	ListElement * count = answer->head;
	while (le1 != NULL || le2 != NULL)
	{
		ListElement * newEl = new ListElement();
		newEl->next = NULL;

		if (le1 != NULL && le2 != NULL)
		{
			if (le1->mono.first < le2->mono.first)
			{
				makeClone(newEl->mono, le1->mono);
				count->next = newEl;
				le1 = le1->next;
			}
			else
			if (le1->mono.first == le2->mono.first)
			{
				newEl->mono.first = le1->mono.first;
				newEl->mono.second = le1->mono.second + le2->mono.second;
				count->next = newEl;

				le1 = le1->next;
				le2 = le2->next;
				
			}
			else
			if (le1->mono.first > le2->mono.first)
			{
				makeClone(newEl->mono, le2->mono);
				count->next = newEl;
				le2 = le2->next;
			}
		}
		else
		{
			if (le1 == NULL)
			{
				makeClone(newEl->mono, le2->mono);
				count->next = newEl;
				le2 = le2->next;
			}
			else
			if (le2 == NULL)
			{
				makeClone(newEl->mono, le1->mono);
				count->next = newEl;
				le1 = le1->next;
			}
		}
		count = count->next;
	}
	
	correct(answer);
	return answer;
}

void printPolinom(Polinom * pol)
{
	ListElement * le = pol->head->next;

	while(le != NULL)
	{
		printPair(le->mono);
		if ((le->next != NULL) && (le->next->mono.second >= 0))
			std::cout << "+";
		le = le->next;
	}
}

void deleteAll(ListElement *& el)
{
	if (el != NULL)
		deleteAll(el->next);
	delete el;
}

void deletePolinom(Polinom *& pol)
{
	deleteAll(pol->head);
}