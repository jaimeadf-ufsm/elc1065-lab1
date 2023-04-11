#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number;

    printf("Digite um numero: ");
    scanf("%d", &number);

    printf(number % 2 == 0 ? "par" : "impar");
    printf("\n");

    return 0;
}
