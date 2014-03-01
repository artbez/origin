#include <stdio.h>

int main(void)
{

    int number = 0;

    printf("Enter x\n");
    scanf("%d", &number);

    int quadroNumber = 0;
    quadroNumber = number * number;

    printf("x^4 + x^3 + x^2 + x = %d", (quadroNumber + 1) * (quadroNumber + number));

    return 0;
}

