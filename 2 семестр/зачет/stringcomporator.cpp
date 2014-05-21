#include "stringcomporator.h"

bool StringComporator::firstIsGreater(const std::string &first, const std::string &second)
{
    int lengthOfFirst = first.length();
    int lengthOfSecond = second.length();
    if (lengthOfFirst < lengthOfSecond)
        return false;
    if (lengthOfSecond < lengthOfFirst)
        return true;
    for (int i = 0; i < lengthOfFirst; ++i)
    {
        if (first[i] > second[i])
            return true;
        if (second[i] < first[i])
            return false;
    }
    return false;
}
