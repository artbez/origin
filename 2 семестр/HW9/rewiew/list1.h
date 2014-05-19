#pragma once
#include <iostream>
#include <cstdlib>

struct list {
public:
	list(int value) {
		this->value = value;
		previous = nullptr;
		next = nullptr;
	}
	list() { 
		value = 0; 
	}
	list *previous;
	list *next;
	int getValue();
private:
	int value;
};

class allLists {
public:
	virtual void clean() = 0;
	virtual void print() = 0;
	virtual void push(int value) = 0;
	virtual int pop() = 0;
};

class pointList : public allLists {
public:
	pointList();
	void clean();
	void print();
	void push(int value);
	int pop();
private:
	list* end;
	list* begin;
};

class arrayList : public allLists {
public:
	arrayList();
	void clean();
	void print();
	void push(int value);
	int pop();
private:
	list* mas;
	int end;
	int length;

};