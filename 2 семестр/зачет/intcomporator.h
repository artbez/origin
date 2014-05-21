#pragma once
#include "comporatorinterface.h"

/// comporator which works with int
class IntComporator : public ComporatorInterface<int>
{
public:
    bool firstIsGreater(const int &first, const int &second)
    {
        return (first > second);
    }
};


