#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
        printf("%d ", vector[i]);
    }

    printf("\n");
}

void Sort(int *a, int *b, int *c, int size)
{
    int count = 0;
    int last_bigger = INT_MAX;

    while (count < 2 * size)
    {
        int current_bigger = a[0];

        for (int i = 0; i < size; i++)
        {
            if (count == 0 || a[i] < last_bigger)
            {
                if (a[i] > current_bigger)
                {
                    current_bigger = a[i];
                }
            }

            if (count == 0 || b[i] < last_bigger)
            {
                if (b[i] > current_bigger)
                {
                    current_bigger = b[i];
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (a[i] == current_bigger)
            {
                c[count++] = a[i];
            }

            if (b[i] == current_bigger)
            {
                c[count++] = b[i];
            }
        }

        last_bigger = current_bigger;
    }
}

int main()
{
    int a[10];
    int b[10];

    int c[20];

    printf("Digite 10 valores para o vetor A: ");
    ReadVector(a, 10);

    printf("Digite 10 valores para o vetor B: ");
    ReadVector(b, 10);

    Sort(a, b, c, 10);

    printf("Vetor A: ");
    PrintVector(a, 10);

    printf("Vetor B: ");
    PrintVector(b, 10);

    printf("Vetor C: ");
    PrintVector(c, 20);

    return 0;
}