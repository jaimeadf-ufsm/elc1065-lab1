#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    double salary;
    char plan;    

    printf("Planos: \n");
    printf("A) 9%%\n");
    printf("B) 13%%\n");
    printf("C) 17%%\n");

    printf("\nDigite seu salario atual e o plano: \n");
    scanf("%lf %c", &salary, &plan);

    switch (plan)
    {
        case 'A':
            printf("Novo salario: R$%lf\n", salary * 1.09);
            break;
        case 'B':
            printf("Novo salario: R$%lf\n", salary * 1.13);
            break;
        case 'C':
            printf("Novo salario: R$%lf\n", salary * 1.17);
            break;
        default:
            printf("Plano invalido\n");
    } 

    return 0;
}
