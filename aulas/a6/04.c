#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void calculate_diesel_cost()
{
    const float DIESEL_PRICE = 2.5f;
    const float PROMOTIONAL_DIESEL_PRICE = 2.3f;

    const float KM_PER_LITER = 10.0f;
    const float TANK_CAPACITY = 90.0f;

    float distance;

    printf("Digite o numero de quilometros que serao percorridos: ");
    scanf("%f", &distance);

    float required_liters = distance / KM_PER_LITER;
    
    float price_per_liter = required_liters >= 45 ? PROMOTIONAL_DIESEL_PRICE : DIESEL_PRICE;
    float total_price = required_liters * price_per_liter;

    printf("R$ %f\n", total_price); 
}

int main()
{
    calculate_diesel_cost();
    
    return 0;
}
