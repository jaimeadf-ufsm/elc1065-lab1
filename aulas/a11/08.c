#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 25

void ReadVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &vector[i]);
    }
}

void PrintVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", vector[i]);
    } 
}

int main()
{
    int vector_a[SIZE];
    int vector_b[SIZE];

    int vector_c[2 * SIZE];

    printf("Digite %d numeros para o vetor A:\n", SIZE);
    ReadVector(vector_a, SIZE);

    printf("Digite %d numeros para o vetor B:\n", SIZE);
    ReadVector(vector_b, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        vector_c[2 * i] = vector_a[i];
        vector_c[2 * i + 1] = vector_b[i]; 
    }

    printf("\nVetores intercalados:\n");
    PrintVector(vector_c, 2 * SIZE);

    for (int i = 0; i < 2 * SIZE; i++)
    {
        for (int j = 0; j < 2 * SIZE - 1; j++)
        {
            if (vector_c[j] < vector_c[j + 1])
            {
                int temp = vector_c[j];

                vector_c[j] = vector_c[j + 1];
                vector_c[j + 1] = temp;
            }
        }
    }

    printf("\nVetores em ordem descrescente:\n");
    PrintVector(vector_c, 2 * SIZE);
    

    return 0;
}