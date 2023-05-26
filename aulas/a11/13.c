#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LINES 8
#define COLUMNS 7

void ReadMatrix(int matrix[LINES][COLUMNS])
{
    printf("Digite uma matrix de %dx%d: \n", LINES, COLUMNS);

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    } 
}

void PrintMatrix(int matrix[LINES][COLUMNS])
{
    printf("\n");

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%4d", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int main()
{
    int matrix[LINES][COLUMNS];

    int product = 1;
    int negatives = 0;

    int element, element_i = -1, element_j = -1;

    ReadMatrix(matrix);

    printf("Digite um elemento: ");
    scanf("%d", &element);

    PrintMatrix(matrix);

    for (int j = 0; j < COLUMNS; j++)
    {
        int bigger = matrix[0][j];

        for (int i = 1; i < LINES; i++)
        {
            if (matrix[i][j] > bigger)
            {
                bigger = matrix[i][j];
            }
        }

        printf("a) Maior elemento da coluna %d: %d\n", bigger);
    }

    for (int i = 0; i < LINES; i++)
    {
        double average = 0;

        for (int j = 0; j < COLUMNS; j++)
        {
            average += matrix[i][j];
        }

        average /= COLUMNS;

        printf("b) Media dos elementos da linha %d: %lf\n", i, average);
    }


    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (matrix[i][j] != 0)
            {
                product *= matrix[i][j];
            }
        }
    }

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (matrix[i][j] < 0)
            {
                negatives++;
            }
        }
    }

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (matrix[i][j] == element)
            {
                element_i = i;
                element_j = j;
            }
        }
    }

    printf("c) Produto de todos elementos diferentes de 0: %d\n", product);
    printf("d) Quantidade de elementos negativos: %d\n", negatives);
    printf("e) Posicao de %d: (%d, %d)\n", element, element_i, element_j);

    return 0;
}