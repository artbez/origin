#include <stdio.h>

void reverse(int* array, int begin, int end);

int main(void)
{

    int firstNum = 0;
    int secondNum = 0;

    printf("Введите n и m.\n");
    scanf("%d %d", &firstNum, &secondNum);
    int array[firstNum + secondNum];

    printf("Введите исходный массив.\n");
    for (int i = 0; i < firstNum + secondNum; ++i)
    {
        scanf("%d", &array[i]);
    }

    reverse(array, 0, firstNum);
    reverse(array, firstNum, firstNum + secondNum);
    reverse(array, 0, firstNum + secondNum);

    for (int i = 0; i < firstNum + secondNum; ++i)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

void reverse(int* array, int begin, int end)
{
    for (int i = 0; i < (end - begin) / 2; ++i)
    {
        int changer = 0;
        changer = array[begin + i];
        array[begin + i] = array[end - i - 1];
        array[end - i - 1] = changer;
    }
}
