#include <stdio.h>

void toBalance(int array[], int index, int lenght);


int main()
{

    int lenght = 0;
    printf("Enter a lenght\n");
    scanf("%d", &lenght);

    int const size = 1000;
    int mainArray[size];

    printf("Enter an array of %d elements\n", lenght);
    for (int i = 0; i < lenght; ++i)
    {
        scanf("%d", &mainArray[i]);
    }

    for (int i = lenght / 2; i >= 0; --i)
    {
        toBalance(mainArray, i, lenght);
    }

    int newLenght = lenght;

    for (int i = 0; i < lenght; ++i)
    {
        int changer = mainArray[0];
        mainArray[0] = mainArray[newLenght - 1];
        mainArray[newLenght - 1] = changer;
        newLenght--;
        toBalance(mainArray, 0, newLenght);
    }

    for (int i = 0; i < lenght; ++i)
    {
        printf("%d ", mainArray[i]);
    }

    return 0;
}


void toBalance(int array[], int index, int lenght)
{
    int num = array[index];

    while (index * 2 + 1 < lenght)
    {
        int child = index * 2 + 1;
        if (child + 1 < lenght && array[child] < array[child + 1])
        {
            child++;
        }

        if (num < array[child])
        {
            array[index] = array[child];
            index = child;
        }
        else
        {
            break;
        }
    }

    array[index] = num;
}
