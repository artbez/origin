#include <stdio.h>

long toStep(int firstN, int secondN);

int main()
{
    int firstN = 0;
    int secondN = 0;
    printf ("Enter two numbers\n");
    scanf("%d", &firstN);
    scanf("%d", &secondN);
    printf("The answer is %ld", toStep(firstN, secondN));

    return 0;
}

long toStep(int firstN, int secondN)
{
    if (secondN == 1)
    {
        return firstN;
    }
    if (secondN % 2 == 0)
    {
        long quadrik = toStep(firstN, secondN / 2);

        return quadrik * quadrik;
    }

    return firstN * toStep(firstN, secondN - 1);
}
