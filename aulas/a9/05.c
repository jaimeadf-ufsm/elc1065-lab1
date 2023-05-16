#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void PrintNumbers(int numbers[10])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}

int main()
{
    int numbers[10];

    printf("Digite 10 numeros inteiros: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    PrintNumbers(numbers);
    
    for (int a = 0, b = 10 - 1; a < b; a++, b--)
    {
        int temp = numbers[a];

        numbers[a] = numbers[b];
        numbers[b] = temp;
    }

    PrintNumbers(numbers);



    return 0;
}