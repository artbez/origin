#include <stdio.h>

int main(void)
{
    int dividend = 0;
    int divisor = 0;
    printf("Введите a и b \n");
    scanf("%d %d", &dividend, &divisor);

    int result = 0;
    while (dividend > divisor)
    {
        dividend -= divisor;
        result++;
    }

    printf("Неполное частное равно %d", result);

    return 0;
}

