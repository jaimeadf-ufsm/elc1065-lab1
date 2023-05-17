#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LINES 3
#define COLUMNS 3

int main()
{
    int vector[COLUMNS];
    int matrix[LINES][COLUMNS];

    printf("Digite um vetor de %d elementos: ", LINES);

    for (int i = 0; i < LINES; i++)
    {
        scanf("%d", &vector[i]);
    }

    printf("Digite uma matrix de %dx%d: \n", LINES, COLUMNS);

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            matrix[i][j] = matrix[i][j] * vector[j];
        }
    }

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%4d", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}