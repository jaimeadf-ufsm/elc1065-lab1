#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int date;

    printf("Digite uma data no formata ddmmaa: ");
    scanf("%d", &date);

    int year = date % 100;
    int month = ((date % 10000) - year) / 100;
    int day = (date - month - year) / 10000;

    printf("Dia: %d\n", day);
    printf("Mes: %d\n", month);
    printf("Ano: %d\n", year);

    return 0;
}