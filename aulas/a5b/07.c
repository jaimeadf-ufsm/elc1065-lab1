#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double GetEntrancePrice(double base_price, char day, bool live_music)
{
    if (live_music)
    {
        base_price *= 1.15;
    }

    switch (day)
    {
        case 'D':
        case '2':
        case '3':
            return base_price * 0.75;
        case '4':
        case '5':
        case '6':
        case 'S':
            return base_price;
        default:
            return -1;
    }
}

int main()
{
    double base_price;
    char day;
    char live_music;

    printf("Digite o preco normal de entrada: ");
    scanf("%lf", &base_price);

    printf("Digite o dia da semana ('D', '2', '3, '4', '5', '6', 'S'): ");
    scanf(" %c", &day);

    printf("Tem musica ao vivo (s/n)? ");
    scanf(" %c", &live_music);

    double price = GetEntrancePrice(base_price, day, live_music == 's' || live_music == 'S');

    printf("R$%lf", price);

    return 0;
}
