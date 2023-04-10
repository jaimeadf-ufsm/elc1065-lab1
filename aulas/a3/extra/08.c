#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    const double fuel_price = 6.99;

    double initial_odometer, final_odometer;
    double consumed_fuel;
    double total_money;

    printf("Digite o valor inicial e final do odometro: ");
    scanf("%lf %lf", &initial_odometer, &final_odometer);

    printf("Digite quantos litros de combustivel foram gastos: ");
    scanf("%lf", &consumed_fuel);

    printf("Digite quanto de dinheiro foi recebido: ");
    scanf("%lf", &total_money);

    double distance = final_odometer - initial_odometer;
    double average_fuel_consumption = consumed_fuel / distance;
    double profit = total_money - consumed_fuel * fuel_price;

    printf("Media de combustivel consumido: %lf Km/L\n", average_fuel_consumption);
    printf("Lucro: R$ %lf\n", profit);

    return 0;
}