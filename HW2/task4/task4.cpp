#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
int nod(int a, int b);
void qsort(int array[1000][2], int firstIndex, int secondIndex);

int main()
{
    int number;
    printf("Enter a number \n");
    scanf("%d", &number);

    const int size = 1000;
    int mainArray[size][2];
    int count = 0;

    for (int i = 2; i <= number; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (nod(i, j) == 1)
            {
                mainArray[count][0] = j;
                mainArray[count][1] = i;
                count++;
            }
        }
    }


    qsort(mainArray, 0, count - 1);

    for (int i = 0; i < count; ++i)
    {
        printf("%d/%d ", mainArray[i][0], mainArray[i][1]);
    }

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}


int nod(int a, int b)
{
    if (a != b)
    {
        return nod(max(a, b) - min(a, b), min (a, b));
    }

    return a;
}

void qsort(int array[1000][2], int firstIndex, int secondIndex)
{
    int mainNom = array[firstIndex][0];
    int mainDenom = array[firstIndex][1];
    int l = firstIndex;
    int r = secondIndex;

    while (l < r)
    {

        while (array[l][0] * mainDenom  < mainNom * array[l][1])
        {
            l++;
        }

        while (array[r][0] * mainDenom > mainNom * array[r][1])
        {
            r--;
        }

        if (l <= r)
        {
            int changerNom = array[l][0];
            int changerDenom = array[l][1];
            array[l][0] = array[r][0];
            array[l][1] = array[r][1];
            array[r][0] = changerNom;
            array[r][1] = changerDenom;
            l++;
            r--;
        }

    }


    if (r > firstIndex)
    {
        qsort(array, firstIndex, r);
    }

    if (secondIndex > l)
    {
        qsort(array, l, secondIndex);
    }
}

