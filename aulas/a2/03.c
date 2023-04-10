#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
int integer;
    float decimal;

    printf("Digite um valor inteiro e um real em ordem: ");
    scanf("%d %f", &integer, &decimal);

    printf("O valor do inteiro equivale a %d e do decimal equivale a %f\n", integer, decimal);

    return 0;
}