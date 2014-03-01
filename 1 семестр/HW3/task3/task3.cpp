#include <stdio.h>

void makeArray(int *arr, int number, int length);
void enterMin(int *arr, int length);

int main()
{
    int number;
    printf("Enter a number\n");
    scanf("%d", &number);

    int size = 10;
    int * arr = new int[size];
    makeArray(arr, number, size);
    enterMin(arr, size);

    delete[](arr);
    arr = nullptr;

    return 0;
}

void makeArray(int *arr, int number, int length)
{
    for (int i = 0; i < length; ++i)
    {
        arr[i] = 0;
    }

    while(number > 0)
    {
        arr[number % 10]++;
        number /= 10;
    }
}

void enterMin(int *arr, int length)
{
    for (int i = 1; i < length; ++i)
    {
        if (arr[i] != 0)
        {
            printf("%d", i);
            arr[i]--;
            break;
        }
    }

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < arr[i]; ++j)
        {
            printf("%d", i);
        }
    }


}
