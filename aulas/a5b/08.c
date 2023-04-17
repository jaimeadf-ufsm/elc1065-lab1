#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double GetFee(int days)
{
    if (days <= 3) 
    {
        return 0;
    }

    if (days <= 7)
    {
        return 0.005;
    }
    
    if (days <= 12)
    {
        return 0.015;
    }

    return 0.03;
}

double GetCost(double price, int days)
{
    return price + price * GetFee(days);
}

int main()
{
    double price;
    int days;

    printf("Qual o valor da compra? ");
    scanf("%lf", &price);

    printf("Qual o prazo de pagamento em dias? ");
    scanf("%d", &days);

    printf("O valor a ser gasto sera de R$%lf\n", GetCost(price, days));

    return 0;
}
