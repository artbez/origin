#include "sorting.h"

/// Class which can sort a matrix by BubleSort
class BubleSorting : public Sorting
{
public:
    /// Method which sort a matrix by BubleSort
    void sort(int ** newArray, int length);
private:
    /// Method which change columns with indexes firstIndex and secondIndex in the matrix
    void changer(int ** newArray, int firstIndex, int secondIndex, const int length);
};

