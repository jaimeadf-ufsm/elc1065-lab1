#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 50

void PrintNumbers(int *numbers, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}

int main()
{
    int evens[SIZE], even_count = 0;
    int odds[SIZE], odd_count = 0;

    printf("Digite %d numeros inteiros: ", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        int number;
        scanf("%d", &number);

        if (number % 2 == 0)
        {
            evens[even_count] = number;
            even_count++;
        }
        else
        {
            odds[odd_count] = number;
            odd_count++;
        }
    }

    printf("Pares: ");
    PrintNumbers(evens, even_count);    

    printf("Impares: ");
    PrintNumbers(odds, odd_count);

    return 0;
}