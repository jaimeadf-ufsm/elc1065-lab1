#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int matrix[2][2];

    printf("Digite uma matrix 2x2: \n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    printf("Determinante: %d\n", determinant);

    return 0;
}