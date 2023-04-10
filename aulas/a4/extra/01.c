#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    const double subscription_fee = 7;
    const double range_11_30_fee = 1;
    const double range_31_100_fee = 2;
    const double range_101_fee = 5;

    double consumption;
    double bill = 0;

    printf("Quanto sua residencia consome em metros cubicos? ");
    scanf("%lf", &consumption);

    bill += subscription_fee;

    if (consumption >= 11)
    {
        bill += fmin(consumption - 10, 20) * range_11_30_fee;
    }

    if (consumption >= 31)
    {
        bill += fmin(consumption - 30, 70) * range_31_100_fee;
    }

    if (consumption >= 101)
    {
        bill += (consumption - 100) * range_101_fee;
    }

    printf("Valor da conta de agua: R$ %lf\n", bill);

    return 0;
}