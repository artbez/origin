#include <stdio.h>

int writeFibList(int number);

int main()
{
    int number = 0;
    printf("Enter a number ");
    scanf("%d", &number);

    int prev = 1;
    int prePrev = 1;
    int sumator = 0;


    for (int i = 0; i < number; ++i)
    {
        sumator = prev + prePrev;
        prePrev = prev;
        prev = sumator;
    }

    printf("The first way to count n' fibonacci number %d\n", prePrev);

    printf("The second way to count n' fibonacci number %d\n", writeFibList(number));

    return 0;
}

int writeFibList(int number)
{
    if ((number == 1) || (number == 0))
    {
        return 1;
    }
    else
    {
        return writeFibList(number - 2) + writeFibList(number - 1);
    }
}
