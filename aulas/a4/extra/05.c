#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int maximum_value;
    
    int a, b;
    char operation;

    printf("Qual o valor maximo que o computador consegue armazenar? ");
    scanf("%d", &maximum_value);

    printf("Qual a operacao voce deseja realizar? ");
    scanf("%d %c %d", &a, &operation, &b);

    if (operation == '+' && (maximum_value - a) < b || operation == '*' && (maximum_value / a) < b)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Ok\n");
    }

    return 0;
}