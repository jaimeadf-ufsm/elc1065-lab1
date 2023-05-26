#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 20

int main()
{
    int vector_a[SIZE];
    int vector_b[SIZE];

    int n_b = 0;

    printf("Digite %d numeros: \n", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &vector_a[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (vector_a[i] > 0)
        {
            vector_b[n_b++] = vector_a[i];
        }
    }

    printf("\nVetor compactado:\n");

    for (int i = 0; i < n_b; i++)
    {
        printf("%d\n", vector_b[i]);
    }

    return 0;
}