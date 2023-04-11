#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    char sex;
    double height;

    printf("Digite seu sexo ('M' ou 'F') e sua altura em cm: ");
    scanf("%c %lf", &sex, &height);

    double multiplier;

    switch (sex)
    {
        case 'M':
            multiplier = 0.9;
            break;
        default:
            multiplier = 0.85;
    }

    printf("Seu peso ideal eh: %lfkg\n", (height - 100) * multiplier);

    return 0;
} 
