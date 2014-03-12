#include "calculator.h"

QString Calculator::calculate(int firstNum, int secondNum, char sign)
{

    int result = 0;
    switch (sign)
    {
    case '+':
        result = firstNum + secondNum;
        break;
    case '-':
        result = firstNum - secondNum;
        break;
    case '*':
        result = firstNum * secondNum;
        break;
    case '/':
        if (secondNum != 0)
            result = firstNum / secondNum;
        else
            return "Error";

        break;
    }

    return QString::number(result);
}
