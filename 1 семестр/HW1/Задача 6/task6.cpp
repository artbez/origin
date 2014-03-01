#include <stdio.h>
#include <string.h>

long hash(char str[],  long steps[]);
char* subString(char str[], int index1, int index2);

int main()
{
    const int size = 1000;

    char bigStr[size];
    printf("Enter a string S\n");
    scanf("%s", bigStr);

    char smallStr[size];
    printf("Enter a string S1\n");
    scanf("%s", smallStr);

    const int magicNumber = 7;
    const int numberOfSteps = 100;
    long steps[numberOfSteps];

    steps[0] = 1;
    for (int i = 1; i < numberOfSteps; ++i)
    {
        steps[i] = magicNumber * steps[i - 1];
    }

    const int lenghtOfBigStr = strlen(bigStr);
    const int lenghtOfSmallStr = strlen(smallStr);

    int arrayOfHash[size];
    arrayOfHash[0] = 0;
    for (int i = 1; i <= lenghtOfBigStr; ++i)
    {
        arrayOfHash[i] = arrayOfHash[i - 1] + bigStr[i - 1] * steps[i - 1];
    }

    const long hashOfSmallStr = hash(smallStr, steps);

    int counter = 0;
    int hashOfSubStr = 0;
    for (int i = 0; i + lenghtOfSmallStr <= lenghtOfBigStr; ++i)
    {
        hashOfSubStr = arrayOfHash[i + lenghtOfSmallStr] - arrayOfHash[i];

        if (hashOfSubStr == hashOfSmallStr * steps[i])
        {

            bool flag = true;
            for (int j = i; i < i + lenghtOfSmallStr; ++j)
            {
                if (bigStr[j] != smallStr[j - i])
                {
                    flag = false;
                    break;
                }
            }

            if (!flag)
            {
                counter++;
            }
        }

    }

    printf("The answer is %d", counter);
    return 0;
}


 long hash(char str[],  long steps[])
{
    long value = 0;
    const int lenght = strlen(str);

    for (int i = 0; i < lenght; ++i)
    {
        value += str[i] * steps[i];
    }

    return value;
}


char* subString(char str[], int index1, int index2)
{
    const int size = 1000;
    char subStr[size];

    for (int i = index1; i < index2; ++i)
    {
        subStr[i - index1] = str[i];
    }

    return subStr;
}
