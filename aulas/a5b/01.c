#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void due_ipva()
{
    int month, plate;

    printf("Digite o mes atual: ");
    scanf("%d", &month);

    printf("Digite os 4 digitos da placa do veiculo: ");
    scanf("%d", &plate);

    int due_month = plate % 10;

    if (due_month == 0)
    {
        due_month = 10;
    }

    int difference = due_month - month;    

    switch (due_month)
    {
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Marco");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
    }

    printf("\n");

    if (difference > 0)
    {
        printf("Sua placa vence de que %d meses\n", difference);
    } else {
        printf("Sua placa venceu ha %d meses\n", -difference);
    } 
}

int main()
{
    due_ipva();
    return 0;
}
