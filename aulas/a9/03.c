#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 4

int main()
{
    int numbers[SIZE];
 
    printf("Digite %d numeros inteiros: ", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int smaller_index = 0;

    for (int i = 1; i < SIZE; i++)
    {
        if (numbers[i] < numbers[smaller_index])
        {
            smaller_index = i;
        }
    }

    printf(
        "O menor elemento encontrado foi numero %d com o valor %d\n",
        smaller_index + 1,
        numbers[smaller_index]
    );

    return 0;
}