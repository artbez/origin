#include "linkedstack.h"
#include "stackonarray.h"
#include "toOpz.h"
#include "calculateByOpz.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedStack * stack = new LinkedStack();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    std::cout << stack->length() << "\n";
    stack->printStack();
    std::cout << "\n";
    stack->pop();
    stack->pop();
    stack->printStack();
    stack->deleteStack();
    delete stack;

    cout << "\n\n\n";

    //Список на массивах
    StackOnArray * stackOnArray = new StackOnArray();

    stackOnArray->push(5);
    stackOnArray->push(2);

    std::cout << stackOnArray->length() << "\n";
    stackOnArray->printStack();
    std::cout << "\n";
    stackOnArray->pop();
    stackOnArray->printStack();
    stackOnArray->deleteStack();
    delete stackOnArray;

    cout << "\n\n\n";
    //Стековый калькулятор

    const int size = 100;
    char *str = new char[size];
    cout << "Enter an expression\n";
    cin.getline(str, size);

    cout << "The answer is \n";
    //	cout << toOpz(str);
    cout << calculateByOpz(toOpz(str));
    delete[] str;
    return 0;
}

