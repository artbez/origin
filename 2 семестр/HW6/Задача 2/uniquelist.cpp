#include "uniquelist.h"
#include <iostream>
#include "myerror.h"

void UniqueList::addToUniqueList(int position, int value) throw (MyError::ExceptionOfAdding)
{
    if (contains(value) != -1)
        throw MyError::ExceptionOfAdding();

    insert(position, value);
}

void UniqueList::deleteFromUniqueList(int value) throw (MyError::ExceptionOfDeleting)
{
    int indexOfDeletingElem = contains(value);
    if (indexOfDeletingElem == -1)
        throw MyError::ExceptionOfDeleting();

    deleteElement(indexOfDeletingElem);
}
