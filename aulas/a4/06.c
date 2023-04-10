#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float height;
    char sex;

    printf("Digite sua altura e seu sexo (M ou F): ");
    scanf("%f %c", &height, &sex);

    float ideal_weight;

    if (sex == 'F')
    {
        ideal_weight = (62.1 * height) - 44.7;
    }
    else
    {
        ideal_weight = (72.7 * height) - 58;
    }

    printf("Seu peso ideal eh %fkg\n", ideal_weight);

    return 0;
}