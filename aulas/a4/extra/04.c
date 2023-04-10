#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    double gasoline_price, gasoline_distance_per_liter;
    double alcohol_price, alcohol_distance_per_liter;

    printf("Digite o preco da gasolina e a distancia percorrida por litro: ");
    scanf("%lf %lf", &gasoline_price, &gasoline_distance_per_liter);

    printf("Digite o preco do alcool e a distancia percorrida por litro: ");
    scanf("%lf %lf", &alcohol_price, &alcohol_distance_per_liter);

    double gasoline_km_per_currency = gasoline_distance_per_liter / gasoline_price;
    double alcohol_km_per_currency = alcohol_distance_per_liter / alcohol_price;

    if (gasoline_km_per_currency >= alcohol_km_per_currency)
    {
        printf("Abastecer o carro com gasolina eh mais vantajoso.\n");    
    }
    else
    {
        printf("Abastecer o carro com alcool eh mais vantajoso.\n");    
    }

    return 0;
}