#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE_A 10
#define SIZE_B 20

void ReadVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &vector[i]);
    }
}

bool Contains(int *vector, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (vector[i] == element)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int vector_a[SIZE_A];
    int vector_b[SIZE_B];

    int vector_c[SIZE_A];
    int n_c = 0;

    printf("Digite %d numeros para o vetor A:\n", SIZE_A);
    ReadVector(vector_a, SIZE_A);

    printf("Digite %d numeros para o vetor B:\n", SIZE_B);
    ReadVector(vector_b, SIZE_B);

    for (int i = 0; i < SIZE_A; i++)
    {
        int element = vector_a[i];

        if (!Contains(vector_c, n_c, element))
        {
            if (Contains(vector_b, SIZE_B, element))
            {
                vector_c[n_c++] = element;
            }
        }
    }

    printf("\nElementos comuns:\n");

    for (int i = 0; i < n_c; i++)
    {
        printf("%d\n", vector_c[i]);
    }

    return 0;
}