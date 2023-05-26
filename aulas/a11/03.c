#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 30

int main()
{
    int vector[SIZE];

    printf("Digite %d numeros:\n", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &vector[i]);
    }

    int smaller = vector[0];
    int bigger = vector[0];

    for (int i = 1; i < SIZE; i++)
    {
        if (vector[i] > bigger)
        {
            bigger = vector[i];
        }
        else if (vector[i] < smaller)
        {
            smaller = vector[i];
        }
    }

    int difference = bigger - smaller;

    printf("\n%d\n", difference);

    return 0;
}