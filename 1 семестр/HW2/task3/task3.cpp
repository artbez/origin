#include <stdio.h>
#include <string.h>

void partition(int number, int max, char str[]);

int main()
{
    int number = 0;
    printf("Enter a number\n");
    scanf("%d", &number);

    const int size = 1000;

    for (int i = 1; i <= number; ++i)
    {
        char str[size] = "";
        partition(number, i, str);
    }

    return 0;
}

void partition(int number, int max, char str[])
{
    number -= max;

    if (number == 0)
    {
        printf("%s%d\n", str, max);
    }

    const int size = 1000;

    for (int i = 1; (i <= max) && (i <= number); ++i)
    {
        char newStr[size] = "";
        strcat(newStr, str);
        char strAdder[size] = "";
        sprintf(strAdder, "%d+", max);
        strcat(newStr, strAdder);

        partition(number, i, newStr);
    }
}
