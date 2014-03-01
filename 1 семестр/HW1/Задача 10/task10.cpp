#include <stdio.h>
#include <string.h>


bool isPalindrom(char* str);

int main()
{

    const int size = 1000;
    char mainStr[size];

    printf("Enter a string \n");
    scanf("%s", mainStr);

    if (isPalindrom(mainStr))
    {
        printf("This is a palindrom");
    }
      else
    {
        printf("This is not a palindrom");
    }

    return 0;
}

bool isPalindrom(char str[]) {

    const int length = strlen(str);

    for (unsigned int i = 0; i < length / 2; ++i)
    {
        if (str[i] != str[length - i - 1])
        {
            return false;
        }
    }

    return true;
}

