#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int i, a, b, c;
    int first, second, third;
    
    printf("Representacoes: \n");
    printf("1) ordem crescente\n");
    printf("2) ordem decrescente\n");
    printf("3) o maior entre os outros dois\n");

    printf("\nDigite a representacao: ");
    scanf("%d", &i);

    printf("Digite tres valores inteiros: ");
    scanf("%d %d %d", &a, &b, &c);
    
    first = a;
    second = b;
    third = c;

    if (b > first)
    {
        second = first;
        first = b; 
    }

    if (c > second)
    {
        third = second;
        second = c;
    }

    if (c > first)
    {
        third = second;
        second = first;
        first = c; 
    }
    

    switch (i)
    {
        case 1:
            printf("%d, %d, %d\n", third, second, first);
            break;
        case 2:
            printf("%d, %d, %d\n", first, second, third);
            break;
        case 3:
            printf("%d, %d, %d\n", third, first, second);
            break;
        default:
            printf("%d nao eh uma opcao valida\n", i);
    }

    return 0;
}
