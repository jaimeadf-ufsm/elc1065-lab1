#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int main()
{
    int arrived_hour, arrived_minute;
    int departure_hour, departure_minute;

    printf("Digite o horario da sua chegada (hh mm): ");
    scanf("%d %d", &arrived_hour, &arrived_minute);

    printf("Digite o horario da sua partida (hh mm): ");
    scanf("%d %d", &departure_hour, &departure_minute);

    double arrived_time = arrived_hour + arrived_minute / 60.0;
    double departure_time = departure_hour + departure_minute / 60.0;

    float total_duration = arrived_time <= departure_time
        ? (departure_time - arrived_time)
        : ((departure_time + 24) - arrived_time);

    int duration = abs(ceil(total_duration));
    double bill = MIN(duration, 2) * 1.0;

    if (duration >= 3)
    {
        bill += MIN(duration - 2, 2) * 1.4;
    }

    if (duration >= 5)
    {
        bill += (duration - 4) * 2;
    }
    
    printf("Valor a ser pago: R$%lf\n", bill);

    return 0;
}
