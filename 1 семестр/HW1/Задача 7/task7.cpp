#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number\n");
    scanf("%d", &number);

    int array[10000];
    for (int i = 0; i <= number; ++i)
    {
        array[i] = i;
    }


    int primeStric = 2;
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = primeStric; primeStric * i <= number; ++i)
        {
            array[primeStric * i] = -1;
        }

        for (int i = primeStric + 1; i * i <= number; ++i) {
            if (array[i] != -1)
            {
                flag = true;
                primeStric = array[i];
                break;
            }
        }

    }

    printf("Prime numbers no more then %d are ", number);
    for (int i = 2; i <= number; ++i)
    {
        if (array[i] != -1)
        printf("%d ", array[i]);
    }

    return 0;
}

