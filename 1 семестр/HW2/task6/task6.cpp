#include <stdio.h>
#include <string.h>

int lengthOfInt(int a);

int main()
{
    int step = 0;
    printf("Enter a number\n");
    scanf("%d", &step);

    const int size = 100;
    char numbers[size][size];

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            numbers[i][j] = '\0';
        }
    }

    printf("Enter %d numbers\n", step + 1);
    for (int i = 0; i <= step; ++i)
    {
        scanf("%s", numbers[i]);

    }

    char secondStr[size];
    for (int i = 0; i < step; ++i)
    {
        if (numbers[i][0] != '0')
        {
            int length = strlen(numbers[i]);
            if (!(numbers[i][0] == '1' && length == 1) && (!(numbers[i][0] == '-' && numbers[i][1] == '1') || length != 2))
            {
                for (int j = 0; j <= length; ++j)
                {
                    printf(" ");
                }

                strcat(secondStr, numbers[i]);
            }
            if (numbers[i][0] == '1'  && length == 1)
            {
                printf(" ");
            }

            if ((numbers[i][0] == '-' && numbers[i][1] == '1') && length == 2)
            {
                printf("  ");
                strcat(secondStr, "-");
            }

            strcat(secondStr, "x");

            if (step - i != 1)
            {
                printf("%d", step - i);
                for (int j = 0; j < lengthOfInt(step - i); ++j)
                {
                    strcat(secondStr, " ");
                }
            }


            while (numbers[i + 1][0] == '0')
            {
                i++;
            }

            if ((numbers[i + 1][0] != '-') && (numbers[i + 1][0] != '\0'))
            {
                printf(" ");
                strcat(secondStr, "+");
            }
        }
    }
    if (numbers[step][0] != '0')
    {
        strcat(secondStr, numbers[step]);
    }

    printf("\n%s", secondStr);
    return 0;
}

int lengthOfInt(int a)
{
    int answer = 0;
    while (a > 0)
    {
        answer++;
        a /= 10;
    }
    return answer;
}
