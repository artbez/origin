#pragma once
#include <QVector>

template <typename T, int dimention, T zero>
class MyVector
{
public:
    /// build MyVector from QVector
    MyVector(const QVector<T> &qv);
    /// constructor of copying
    MyVector(const MyVector &otherVector);
    /// is it zero-vector or not
    bool isZero();
    T getElementByIndex(int index);
    void insert(int index, const T& elem);
    MyVector operator+(const MyVector& otherVector);
    MyVector operator-(const MyVector& otherVector);
    /// scalar multiplication
    T operator*(const MyVector& otherVector);
    bool operator==(const MyVector& otherVector);
private:
    QVector<T> qVector;
};


template <typename T, int dimention, T zero>
MyVector<T, dimention, zero>::MyVector(const QVector<T> &qv)
{
    for (int i = 0; i < dimention; ++i)
        qVector.insert(i, qv.at(i));
}

template <typename T, int dimention, T zero>
MyVector<T, dimention, zero>::MyVector(const MyVector &otherVector)
{
    for (int i = 0; i < dimention; ++i)
        qVector.insert(i, otherVector.qVector.at(i));
}

template <typename T, int dimention, T zero>
bool MyVector<T, dimention, zero>::isZero()
{
    for (int i = 0; i < dimention; ++i)
        if (qVector.at(i) != zero)
            return false;
    return true;
}

template <typename T, int dimention, T zero>
T MyVector<T, dimention, zero>::getElementByIndex(int index)
{
    return qVector.at(index);
}

template <typename T, int dimention, T zero>
void MyVector<T, dimention, zero>::insert(int index,const T& elem)
{
    qVector.insert(index, elem);
}

template <typename T, int dimention, T zero>
MyVector<T, dimention, zero> MyVector<T, dimention, zero>::operator+(const MyVector &otherVector)
{
    MyVector answer(qVector);
    for (int i = 0; i < dimention; ++i)
        answer.insert(i, qVector.at(i) + otherVector.qVector.at(i));

    return answer;
}

template <typename T, int dimention, T zero>
MyVector<T, dimention, zero> MyVector<T, dimention, zero>::operator-(const MyVector &otherVector)
{
    MyVector answer(qVector);
    for (int i = 0; i < dimention; ++i)
        answer.insert(i, qVector.at(i) - otherVector.qVector.at(i));

    return answer;
}

template <typename T, int dimention, T zero>
T MyVector<T, dimention, zero>::operator*(const MyVector &otherVector)
{
    T answer = zero;
    for (int i = 0; i < dimention; ++i)
        answer += qVector.at(i) * otherVector.qVector.at(i);

    return answer;
}

template <typename T, int dimention, T zero>
bool MyVector<T, dimention, zero>::operator==(const MyVector &otherVector)
{
    for (int i = 0; i < dimention; ++i)
        if (qVector.at(i) != otherVector.qVector.at(i))
            return false;

    return true;
}
