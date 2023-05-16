#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int vector[10];
    int search;
    int occurrences = 0;

    printf("Digite 10 numeros: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vector[i]);
    }

    printf("Digite um numero para buscar: ");
    scanf("%d", &search);

    for (int i = 0; i < 10; i++)
    {
        if (vector[i] == search)
        {
            occurrences++;
        }
    }

    printf("O numero %d tem %d ocorrencias\n", search, occurrences);

    return 0;
}