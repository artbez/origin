#pragma once

/// interface of comporator
template<typename T>
class ComporatorInterface
{
public:
    virtual bool firstIsGreater(const T &first, const T &second) = 0;
};
