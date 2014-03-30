#include <iostream>
#include "example.h"
#include "errorclass.h"


int main()
{
    const int size = 10;
    try
    {
        Example examples[size];
        X::f();
    }
    catch(X::Exception1 &)
    {
        std::cout << "Error";
    }

    return 0;
}

