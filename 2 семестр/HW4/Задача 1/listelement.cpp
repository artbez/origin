#include "listelement.h"
#include <iostream>

ListElement::ListElement(QString &qStr)
{
    takeValue(qStr);
}

ListElement::ListElement()
{
    QString qStr = "1";
    takeValue(qStr);
}

QString &ListElement::getValue()
{
    return value;
}

void ListElement::takeValue(QString &qStr)
{
    value = qStr;
}

ListElement * ListElement::getNext()
{
    return next;
}

void ListElement::takeNext(ListElement * le)
{
    next = le;
}

void ListElement::printElement()
{
    std::cout << value.toStdString();
}
