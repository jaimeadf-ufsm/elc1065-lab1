#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int x, y;
    char option;

    printf("Opcoes: \n");
    printf("A) Media aritmetica\n");
    printf("P) Media ponderada com peso 4 para para X e 6 para Y\n");
    printf("R) Resto da divisao de Y por X\n");
    
    printf("Digite um valor para X, um para Y e a opcao: ");
    scanf("%d %d %c", &x, &y, &option);

    switch (option)
    {
        case 'A':
            printf("Media aritmetica: %d\n", (x + y) / 2);
            break;
        case 'P':
            printf("Media ponderada: %d\n", (4 * x + 6 * y) / 10);
            break;
        case 'R':
            printf("Resto da divisao: %d\n", y % x);
            break;
        default:
            printf("Opcao invalida\n");
    }
    
    return 0;
}
