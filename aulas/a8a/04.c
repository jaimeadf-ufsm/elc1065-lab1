#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void PrintDivisors(int n)
{
    for (int divisor = 1; divisor <= n; divisor++)
    {
        if (n % divisor == 0)
        {
            printf("%d\n", divisor);
        }
    }

    printf("\n");
}

int main()
{
    int n;
    char answer;

    do {
        printf("De qual numero voce deseja obter os divisores? ");
        scanf("%d", &n);

        PrintDivisors(n);

        printf("Voce deseja continuar (s/n)? ");
        scanf(" %c", &answer);
    } while (answer == 's' || answer == 'S');
    
    return 0;
}