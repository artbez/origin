#include "example.h"
#include <iostream>

int Example::numberAll;

Example::Example()
{
    numberAll++;
    number = numberAll;
}

Example::~Example()
{
    std::cout << "Object number " << number << " was destroed\n";
}
