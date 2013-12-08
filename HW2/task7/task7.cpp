#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int const size1 = 4;
    int const size2 = 10;
    bool isIt[size2];
    for (int i = 0; i < size2; ++i)
    {
        isIt[i] = false;
    }

    srand(time(NULL));
    int mainArray[size1];
    int num = 0;
    for (int i = 0; i < size1; ++i)
    {
        num = rand()%9;
        if (!isIt[num])
        {
            mainArray[i] = num;
            isIt[num] = true;
        }
        else
        {
            i--;
        }
     }

    bool flag = true;
    int bull = 0;
    int cow = 0;
    int newNumber = 0;
    int figure = 0;
    while(flag)
    {
        printf("Enter a number\n");
        scanf("%d", &newNumber);
        printf("\n");
        for (int i = size1 - 1; i >= 0; --i)
        {
            figure = newNumber % 10;
            newNumber /= 10;
            if (isIt[figure])
            {

                if (mainArray[i] == figure)
                {
                    bull++;
                }
                else
                {
                    cow++;
                }
            }
        }

        if (bull == 4)
        {
            flag = false;
        }
        printf("You have %d bulls and %d cows\n", bull, cow);
        bull = 0;
        cow = 0;
    }
    return 0;
}
