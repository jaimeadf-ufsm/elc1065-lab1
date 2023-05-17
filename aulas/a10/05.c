#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LINES 5
#define COLUMNS 5

void PrintMatrix(int matrix[LINES][COLUMNS])
{
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

    printf("Digite uma matrix de %dx%d: \n", LINES, COLUMNS);

    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matriz: \n");
    PrintMatrix(matrix);

    for (int j = 0; j < COLUMNS; j++)
    {
        int temp = matrix[1][j];

        matrix[1][j] = matrix[4][j];
        matrix[4][j] = temp;
    }

    printf("Troca a segunda linha pela quinta: \n");
    PrintMatrix(matrix);

    for (int i = 0; i < LINES; i++)
    {
        int temp = matrix[i][2];

        matrix[i][2] = matrix[i][4];
        matrix[i][4] = temp;
    }


    printf("Troca a terceira coluna pela quinta: \n");
    PrintMatrix(matrix);

    for (int i = 0; i < LINES; i++)
    {
        int principalJ = i;
        int secondaryJ = COLUMNS - i - 1;

        int temp = matrix[i][principalJ];

        matrix[i][principalJ] = matrix[i][secondaryJ];
        matrix[i][secondaryJ] = temp;
    }

    printf("Troca a diagonal princiapl pela secundaria: \n");
    PrintMatrix(matrix);

    return 0;
}