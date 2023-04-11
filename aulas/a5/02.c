#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    double a, b;
    char operation;

    printf("Digite uma expressao matematica: ");
    scanf("%lf %c %lf", &a, &operation, &b);

    double result;
    bool valid = true;
     
    switch (operation)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
            {
                valid = false;
            }
            else
            {
                result = a / b;
            }
            break;
       default:
            valid = false;
    }

    if (valid)
    {
        printf("%lf %c %lf = %lf\n", a, operation, b, result);
    }
    else
    {
        printf("%lf %c %lf = (erro)\n", a, operation, b);
    }
    
    return 0;
}
