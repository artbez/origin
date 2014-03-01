#include <stdio.h>

void qsort(int array[], int firstIndex, int secondIndex);

int main()
{
    const int size = 7;
    int array[size];

    printf("Enter %d numbers\n", size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &array[i]);
    }

    qsort(array, 0, size-1);


    printf("It is sorted array \n");

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

void qsort(int array[], int firstIndex, int secondIndex)
{
    int mainEl = array[firstIndex];
    int l = firstIndex;
    int r = secondIndex;

    while (l < r)
    {

        while (array[l] < mainEl)
        {
            l++;
        }

        while (array[r] > mainEl)
        {
            r--;
        }

        if (l <= r)
        {
            int changer = array[l];
            array[l] = array[r];
            array[r] = changer;
            l++;
            r--;
        }

    }


    if (r > firstIndex)
    {
        qsort(array, firstIndex, r);
    }

    if (secondIndex > l)
    {
        qsort(array, l, secondIndex);
    }
}
