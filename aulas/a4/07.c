#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float a, b;
    char operation;

    printf("Digite a conta: ");
    scanf("%f %c %f", &a, &operation, &b);

    float result = 0;
    bool has_result = true;

    if (operation == '+')
    {
        result = a + b;
    }
    else if (operation == '-')
    {
        result = a - b;
    }
    else if (operation == '*')
    {
        result = a * b;
    }
    else if (operation == '/')
    {
        if (b != 0)
        {
            result = a / b;
        }
        else
        {
            has_result = false;
        }
    }

    if (has_result)
    {
        printf("%f %c %f = %f\n", a, operation, b, result);
    }
    else
    {
        printf("%f %c %f = (undefined)\n", a, operation, b, result);
    }

    return 0;
}