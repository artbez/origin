#include "sign.h"
#include <iostream>

Sign::Sign(int value)
{
    this->value = value;
}

int Sign::getValue()
{
    return value;
}

void Sign::printSign()
{
    std::cout << (char) value;
}
