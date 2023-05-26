#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#define SIZE 20

int main()
{
    int vector[SIZE];

    printf("Digite %d numeros:\n", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &vector[i]);
    }

    int even_count = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (vector[i] % 2 == 0)
        {
            even_count++;
        }
    }

    printf("\n%d pares\n", even_count);

    return 0;
}