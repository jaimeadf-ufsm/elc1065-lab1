#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool IsTriangular(int n)
{
    int product = 2;

    while (product < n)
    {
        int triangular = (product - 1) * product * (product + 1);

        if (triangular == n)
        {
            return true;
        }

        product++;
    }

    return false;
}

int main()
{
    int number = 1;

    while (number > 0)
    {
        printf("Digite um numero inteiro e positivo: ");
        scanf("%d", &number);

        if (IsTriangular(number))
        {
            printf("O numero %d satisfaz a condicao de triangular\n", number);
        }
        else
        {
            printf("O numero %d NAO satisfaz a condicao de triangular\n", number);
        }
    }
    
    return 0;
}