#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    double price;

    printf("Digite o preco do produto: ");
    scanf("%lf", &price);

    printf("%lf - 10%% = %lf\n", price, price * 0.9);
    printf("%lf + 20%% = %lf\n", price, price * 1.2);

    return 0;
}