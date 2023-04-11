#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int code;
    
    printf("Digite o codigo do produto: ");
    scanf("%d", &code);

    switch (code)
    {
        case 1:
            printf("Alimento nao perecivel\n");
            break;
        case 2:
        case 3:
        case 4:
            printf("Alimento perecivel\n");
            break;
        case 5:
        case 6:
            printf("Higiene pessoal\n");
            break;
        case 8:
        case 9:
        case 10:
        case 11:
            printf("Limpeza\n");
            break;
        default:
            printf("Codigo invalido\n");
    }

    return 0;
}
