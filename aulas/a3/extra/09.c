#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int amount_of_1_cent_coins;
    int amount_of_5_cent_coins;
    int amount_of_10_cent_coins;
    int amount_of_25_cent_coins;
    int amount_of_50_cent_coins;
    int amount_of_1_real_coins;

    printf("Digite a quantidade de moedas de 1, 5, 10, 25 e 50 centavos e de 1 real: ");
    scanf(
        "%d %d %d %d %d %d",
        &amount_of_1_cent_coins,
        &amount_of_5_cent_coins,
        &amount_of_10_cent_coins,
        &amount_of_25_cent_coins,
        &amount_of_50_cent_coins,
        &amount_of_1_real_coins);

    double total = 0;
    total += 0.01 * amount_of_1_cent_coins;
    total += 0.05 * amount_of_5_cent_coins;
    total += 0.1 * amount_of_10_cent_coins;
    total += 0.25 * amount_of_25_cent_coins;
    total += 0.5 * amount_of_50_cent_coins;
    total += 1 * amount_of_1_real_coins;

    printf("Voce conseguiu economizar R$ %lf\n", total);

    return 0;
}