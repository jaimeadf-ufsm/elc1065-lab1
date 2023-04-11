#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int month;

    printf("Digite um mes: ");
    scanf("%d", &month);

    switch (month)
    {
        case 2:
            printf("28 dias\n");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30 dias\n");
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 dias\n");
            break;
        default:
            printf("Mes invalido\n");
    }

    return 0;
}
