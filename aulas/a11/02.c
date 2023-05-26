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

    printf("\nVetor inverso: \n");
    for (int i = SIZE - 1; i >= 0; i--)
    {
        printf("%d\n", vector[i]);
    }
    

    return 0;
}