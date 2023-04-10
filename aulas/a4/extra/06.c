#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define SECONDS_PER_TERRESTRIAL_YEAR (365 * SECONDS_PER_DAY)

#define SECONDS_PER_BLIP 3
#define SECONDS_PER_TAK (40 * SECONDS_PER_BLIP)
#define SECONDS_PER_SALEK (15 * SECONDS_PER_TAK)
#define SECONDS_PER_MAZEL (30 * SECONDS_PER_SALEK)
#define SECONDS_PER_BRAT (8 * SECONDS_PER_MAZEL)
#define SECONDS_PER_TERMOPILITA_YEAR (73 * SECONDS_PER_BRAT)

int get_seconds_in_month(int month)
{
    if (month == 0)
        return 0;

    if (month % 2 == 1)
        return 31 * SECONDS_PER_DAY;

    if (month == 2)
        return 28 * SECONDS_PER_DAY;

    return 30 * SECONDS_PER_DAY;
}

int get_seconds_to_month(int month)
{
    int total_seconds = 0;

    for (int i = 1; i <= month; i++)
    {
        total_seconds += get_seconds_in_month(month);
    }

    return total_seconds;
}

int get_month_by_seconds(int total_seconds)
{
    int total_seconds_in_year = total_seconds % SECONDS_PER_TERRESTRIAL_YEAR;

    for (int i = 12; i >= 1; i--)
    {
        if (total_seconds_in_year % get_seconds_to_month(i) < total_seconds_in_year)
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    char option;

    printf("Menu:\n");
    printf("a) converter de terrestre para termopilita\n");
    printf("b) converter de termopilita para terrestre\n");
    printf("\nO que voce quer fazer? ");

    scanf("%c", &option);

    if (option == 'a')
    {
        int seconds, minutes, hours, day, month, terrestrial_year;

        printf("Digite uma data terrestre na ordem (dia, mes, ano, horas, minutos e segundos): ");
        scanf("%d %d %d %d %d %d", &day, &month, &terrestrial_year, &hours, &minutes, &seconds);

        int total_seconds = 0;
        total_seconds += seconds;
        total_seconds += minutes * SECONDS_PER_MINUTE;
        total_seconds += hours * SECONDS_PER_HOUR;
        total_seconds += day * SECONDS_PER_DAY;
        total_seconds += get_seconds_to_month(month);
        total_seconds += terrestrial_year * SECONDS_PER_TERRESTRIAL_YEAR;

        int blip = (total_seconds % SECONDS_PER_TAK) / SECONDS_PER_BLIP;
        int tak = (total_seconds % SECONDS_PER_SALEK) / SECONDS_PER_TAK;
        int salek = (total_seconds % SECONDS_PER_MAZEL) / SECONDS_PER_SALEK;
        int mazel = (total_seconds % SECONDS_PER_BRAT) / SECONDS_PER_MAZEL;
        int brat = (total_seconds % SECONDS_PER_TERMOPILITA_YEAR) / SECONDS_PER_BRAT;
        int termopilita_years = total_seconds / SECONDS_PER_TERMOPILITA_YEAR;

        printf("total de segundos: %d\n", total_seconds);
        printf("%d anos, %d brat, %d mazel, %d salek, %d tak, %d blip\n", termopilita_years, brat, mazel, salek, tak, blip);
    }
    else if (option == 'b')
    {
        int blip, tak, salek, mazel, brat, termopilita_year;

        printf("Digite um data termopilita na ordem (ano, brat, mazel, salek, tak e blip): ");
        scanf("%d %d %d %d %d %d", &termopilita_year, &brat, &mazel, &salek, &tak, &blip);

        int total_seconds = 0;
        total_seconds += blip * SECONDS_PER_BLIP;
        total_seconds += tak * SECONDS_PER_TAK;
        total_seconds += salek * SECONDS_PER_SALEK;
        total_seconds += mazel * SECONDS_PER_MAZEL;
        total_seconds += brat * SECONDS_PER_BRAT;
        total_seconds += termopilita_year * SECONDS_PER_TERMOPILITA_YEAR;

        int seconds = total_seconds % SECONDS_PER_MINUTE;
        int minutes = (total_seconds % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
        int hours = (total_seconds % SECONDS_PER_DAY) / SECONDS_PER_HOUR;
        int terrestrial_year = total_seconds / SECONDS_PER_TERRESTRIAL_YEAR;
        int month = get_month_by_seconds(total_seconds);
        int day = (total_seconds % SECONDS_PER_TERRESTRIAL_YEAR - get_seconds_to_month(month)) / SECONDS_PER_DAY;

        printf("total de segundos: %d\n", total_seconds);
        printf("ano %d, dia %d, mes %d, %d horas, %d minutos, %d segundos\n", terrestrial_year, day, month, hours, minutes, seconds);
    }
    else
    {
        printf("Infelizmente, nao existe nenhuma opcao com a letra \"%c\".\n", option);
    }

    return 0;
}