#include <stdio.h>

bool step(int **arr, int &index1, int &index2, int &direct, int sum, int max, int number);

int main()
{
    printf("Enter a number > 0\n");
    int number = 0;
    scanf("%d", &number);


    int **arr = new int*[number];

    printf ("Enter an array\n");

    for (int i = 0; i < number; ++i)
    {
        arr[i] = new int[number];
        for (int j = 0; j < number; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int index1 = number / 2;
    int index2 = number / 2;

    int max = 1;

    printf("%d ", arr[index1][index2]);

    while(true)
    {
        if (!step(arr, index1, index2, index1, 1, max, number))
        {
            break;
        }
        if (!step(arr, index1, index2, index2, 1, max, number))
        {
            break;
        }
        if (!step(arr, index1, index2, index1, -1, max + 1, number))
        {
            break;
        }
        if (!step(arr, index1, index2, index2, -1, max + 1, number))
        {
            break;
        }

        max += 2;
    }

    for (int i = 0; i < number; ++i)
    {
        delete[] arr[i];
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}

bool step(int **arr, int &index1, int &index2, int &direct, int sum, int max, int number)
{
    for (int i = 0; i < max; ++i)
    {
        if ((direct + sum < number) && (direct + sum >= 0))
        {
            direct += sum;
            printf("%d ", arr[index1][index2]);
        }
        else
        {
            return false;
        }
    }

    return true;
}
