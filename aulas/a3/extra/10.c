#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int cars_count;
    double daily_rate;

    printf("Digite a quantidade de carros da locadora: ");
    scanf("%d", &cars_count);

    printf("Digite o valor da diaria da locadora: ");
    scanf("%lf", &daily_rate);

    int monthly_rented_cars_count = cars_count / 3;
    int monthly_rented_cars_delayed_count = monthly_rented_cars_count / 10;
    int annually_retired_cars_count = cars_count / 20;
    int annually_renovated_cars_count = cars_count / 8;

    double annual_billing = 30 * monthly_rented_cars_count * daily_rate * 12;
    double monthly_fine_billing = monthly_rented_cars_delayed_count * daily_rate / 10;
    int final_car_count = cars_count - annually_retired_cars_count - annually_renovated_cars_count;

    printf("Faturamento anual: %lf\n", annual_billing);
    printf("Faturamento mensal de multas: %lf\n", monthly_fine_billing);
    printf("Quantidade de carros ao final do ano: %d\n", final_car_count);

    return 0;
}