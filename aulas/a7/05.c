#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int SquareRoot(int n)
{
    int accumulator = 0;
    int count = 0;

    while (accumulator < n)
    {
        accumulator += (count * 2) + 1;
        count++;
    }

    if (accumulator == n)
    {
        return count;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int number = 1;

    while (number > 0)
    {
        printf("Digite um numero: ");
        scanf("%d", &number);

        int square_root = SquareRoot(number);

        if (square_root != -1)
        {
            printf("A raiz quadrada de %d eh %d\n", number, square_root);
        }
        else
        {
            printf("O numero %d nao possui raiz quadrada\n", number);
        }
    }
    
    return 0;
}