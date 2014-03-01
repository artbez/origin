#include <stdio.h>

long fact(int a);

int main()
{
    int number;
    printf("Enter a number\n");
    scanf("%d", &number);

    long value = 1;
    for (int i = 1; i <= number; ++i) {
        value *= i;
    }

    printf("It is the factorial by for    %ld\n", value);
    printf("It is the factorial by recursion    %ld", fact(number));
    return 0;
}

long fact(int a)
{
    if (a == 1)
    {
        return 1;
    }

    return a * fact(a - 1);
}
