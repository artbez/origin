#include "linkedlist.h"
#include "myerror.h"

/// class which describe lists without repeated elements
class UniqueList : public LinkedList
{
public:
    ~UniqueList(){}
    /// add new element
    void addToUniqueList(int position, int value) throw (MyError::ExceptionOfAdding);
    /// delete celemnent from this list
    void deleteFromUniqueList(int value) throw (MyError::ExceptionOfDeleting);
};
