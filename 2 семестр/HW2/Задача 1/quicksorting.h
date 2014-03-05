#include "sorting.h"

/// Class which can sort an array by QuickSort
class QuickSorting : public Sorting
{
public:
     /// Method which sort an array by QuickSort
     void sort(int * newArray, int length);
private:
     void qsort(int * array, int firstIndex, int secondIndex);
};
