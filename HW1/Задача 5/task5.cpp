#include <stdio.h>
#include <string.h>

bool isCorrect(char mainStr[]);

int main()
{
    const int size = 1000;

    char mainStr[size];
    printf("Enter a string\n");
    scanf("%s", mainStr);

    if (isCorrect(mainStr))
    {
        printf("This is correct");
    }
    else
    {
        printf("This is not correct");
    }
    return 0;
}

bool isCorrect(char mainStr[])
{
    int counter = 0;
    const int lenght = strlen(mainStr);

    for (int i = 0; i < lenght; ++i)
    {
        if (mainStr[i] == '(')
        {
            counter++;
        }
        if (mainStr[i] == ')')
        {
            counter--;
        }
        if (counter < 0)
        {
            return false;
        }
    }

    return (counter == 0);
}
