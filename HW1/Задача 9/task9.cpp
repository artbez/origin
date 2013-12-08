#include <stdio.h>

int abs(int n);

int main()
{
    float a = 0;
    int n = 0;
    printf("Enter a and n \n");
    scanf("%f %d", &a, &n);

    float result = 1;
    for (int i = 0; i < abs(n); ++i)
    {
        result *= a;
    }

    if (n < 0)
    {
        printf("%.*f", 1 / result);
    }
    else
    {
        printf("%d", (int) result);
    }
    return 0;
}

int abs(int n)
{
    return (n > 0 ? n : -n);
}
