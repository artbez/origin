#pragma once
#include "comporatorinterface.h"
#include <iostream>
#include <string>

using std::string;

/// comporator which works with strings
class StringComporator : public ComporatorInterface<string>
{
public:
    bool firstIsGreater(const string &first, const string &second);
};

