#include <iostream>

using namespace std;

int main()
{
    const int maxSum = 28;

    int counter[maxSum];
    for (int i = 0; i < maxSum; ++i)
    {
        counter[i] = 0;
    }


    const int maxDigit = 10;

    for (int i = 0; i < maxDigit; ++i)
    {
        for (int j = 0; j < maxDigit; ++j)
        {
            for (int k = 0; k < maxDigit; ++k)
            {
                counter[i + j + k]++;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < maxSum; ++i)
    {
        answer += counter[i] * counter[i];
    }

    printf("Всего счастливых билетов %d", answer);

    return 0;
}

