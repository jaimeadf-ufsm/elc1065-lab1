#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 7

int main()
{
    int numbers[SIZE];

    printf("Digite %d numeros: ", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int bigger_sublist_size = 0;
    int bigger_sublist_start = 0;

    int current_sublist_size = 1;
    int current_sublist_start = 0;

    for (int i = 1; i < SIZE; i++)
    {
        if (numbers[i] > numbers[i - 1])
        {
            current_sublist_size++;
        }
        else
        {
            current_sublist_size = 1;
            current_sublist_start = i;
        }

        if (current_sublist_size > bigger_sublist_size)
        {
            bigger_sublist_size = current_sublist_size;
            bigger_sublist_start = current_sublist_start;
        }
    }

    printf("Maior sub-lista: ");

    for (int i = 0; i < bigger_sublist_size; i++)
    {
        printf("%d ", numbers[bigger_sublist_start + i]);
    }

    printf("\nTamanho: %d\n", bigger_sublist_size);

    return 0;
}