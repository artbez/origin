#pragma once

/// Helps see number of links to same memory
template <typename T>
struct SPointer
{
    T * pointer = nullptr;
    int count = 0;
};

template <typename T>
class SharedPointer
{
public:
    /// Construct SharedPointer by pointer
    SharedPointer(T *value);
    /// Constructor of copying
    SharedPointer(SharedPointer<T> &sp);
    ~SharedPointer();
    void operator=(SharedPointer<T>& sp);
    SPointer<T> * getSPointer();
    /// Returns pointer which is covered by SharedPointer
    T * getPointer();
    /// Returns number of links to the memory which is indicated by the pointer
    int getCount();
private:
    void deleteSPointer();
    SPointer<T> * sPointer = nullptr;
};

template <typename T>
SharedPointer<T>::SharedPointer(T * value)
{
    sPointer = new SPointer<T>();
    sPointer->count = 1;
    sPointer->pointer = value;
}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T> &sp)
{
    sp.getSPointer()->count++;
    sPointer = sp.getSPointer();
}

template <typename T>
void SharedPointer<T>::operator=(SharedPointer<T> &sp)
{
    if (sPointer != nullptr)
        deleteSPointer();

    sp.getSPointer()->count++;
    sPointer = sp.getSPointer();
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    deleteSPointer();
}

template <typename T>
SPointer<T> *SharedPointer<T>::getSPointer()
{
    return sPointer;
}

template <typename T>
T *SharedPointer<T>::getPointer()
{
    return sPointer->pointer;
}

template <typename T>
int SharedPointer<T>::getCount()
{
    return sPointer->count;
}

template <typename T>
void SharedPointer<T>::deleteSPointer()
{
    if (sPointer->count == 1)
    {
        delete sPointer->pointer;
        delete sPointer;
    }
    else
        sPointer->count--;
}
