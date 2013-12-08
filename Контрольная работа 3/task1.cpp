#include <stdio.h>

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

    printf("It is n' fibonacci number %d\n", prePrev);

	return 0;
}
