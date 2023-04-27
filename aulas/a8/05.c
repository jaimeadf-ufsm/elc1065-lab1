#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number;
    int square = 1;

    printf("Digite um numero: ");
    scanf("%d", &number);

    do {
        square++;
    } while (square * square <= number);

    printf("%d eh o menor inteiro cujo quadradado eh superior a %d\n", square, number);

    return 0;
}