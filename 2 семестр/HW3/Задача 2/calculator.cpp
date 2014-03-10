#include "calculator.h"

QString Calculator::calculate(int firstNum, int secondNum, int sign)
{
    int result = 0;
    switch (sign)
    {
    case 0:
        result = firstNum + secondNum;
        break;
    case 1:
        result = firstNum - secondNum;
        break;
    case 2:
        result = firstNum * secondNum;
        break;
    case 3:
        if (secondNum != 0)
            result = firstNum / secondNum;
        else
            return "Error";

        break;
    }

    return QString::number(result);
}
