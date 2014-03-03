#include "sorting.h"

class QuickSorting : public Sorting
{
public:
     void sort(int * newArray, int length);
private:
     void qsort(int * array, int firstIndex, int secondIndex);
};
