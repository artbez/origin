#include <iostream>
#include "num.h"

Num::Num(int value)
{
    this->value = value;
}

void Num::print()
{
    std::cout << value;
}

int Num::count()
{
    return value;
}
