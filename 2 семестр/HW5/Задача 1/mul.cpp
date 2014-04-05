#include <iostream>
#include "mul.h"

int Mul::count()
{
    return leftChild->count() * rightChild->count();
}

Mul::~Mul()
{
    delete leftChild;
    delete rightChild;
}

void Mul::print()
{
    std::cout <<"(* ";
    leftChild->print();
    std::cout << " ";
    rightChild->print();
    std::cout << ")";
}
