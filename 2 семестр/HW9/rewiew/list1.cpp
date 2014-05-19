#include "list1.h"

using namespace std;

int list::getValue() {
	return value;
}

arrayList::arrayList() {
	length = 1;
	end = -1;
	mas = new list[length];
}

void arrayList::clean() {
	delete []mas;
}

int arrayList::pop() {
	if (end >= 0) 
		return mas[end--].getValue();
	else 
		cout << "List is empty" << endl;
}

void arrayList::push(int value) {
	if (end >= length - 1) {
		list* temp = new list[++length];
		for (int i = 0; i < length; ++i)
			temp[i] = mas[i];
		delete []mas;
		mas = temp;
	}
	mas[++end] = value;
}

void arrayList::print() {
	for (int i = 0; i < end; i++)
		cout << mas[i].getValue() << ' ';
}


pointList::pointList() {
	begin = nullptr;
	end = nullptr;
}

void pointList::clean() {
	list* temp = nullptr;
	while (begin) {
		temp = begin;
		begin = begin->next;
		delete temp;
	}
}

void pointList::push(int value) {
	if (!end) {
		end = new list(value);
		begin = end;
	}
	else {
		list* temp = new list(value);
		end->next = temp;
		temp->previous = end;
		end = temp;
	}
}

int pointList::pop() {
	if (begin) {
		list* temp = begin;
		int value = temp->getValue();
		begin = begin->next;
		delete temp;
		return value;
	}
	cout << "List is empty" << endl;
}

void pointList::print() {
	list* temp = begin;
	cout << "inorder:\n";
	while (temp) {
		cout << temp->getValue() << " ";
		temp = temp->next;
	}
	cout << endl;
	cout << "postorder:\n";
	temp = end;
	while (temp) {
		cout << temp->getValue() << " ";
		temp = temp->previous;
	}
	cout << endl;
}