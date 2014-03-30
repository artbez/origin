#include "uniquelist.h"
#include <iostream>
#include "myerror.h"

void UniqueList::addToUniqueList(int position, int value)
{
    try
    {
        if (contains(value) != -1)
            MyError::addingError();
        insert(position, value);
    }
    catch(MyError::ExceptionOfAdding &)
    {
        std::cout << "This element is already exists\n";
    }
}

void UniqueList::deleteFromUniqueList(int value)
{
    try
    {
        int indexOfDeletingElem = contains(value);
        if (indexOfDeletingElem == -1)
            MyError::deletingError();
        deleteElement(indexOfDeletingElem);
    }
    catch(MyError::ExceptionOfDeleting &)
    {
        std::cout << "There is no this element in the list\n";
    }
}
