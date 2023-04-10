#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    const int seconds_per_minute = 60;
    const int seconds_per_hour = 60 * seconds_per_minute;
    const int seconds_per_day = 24 * seconds_per_hour;
    const int seconds_per_terrestrial_year = 365 * seconds_per_day;
    const int seconds_per_month = seconds_per_terrestrial_year / 12;

    const int seconds_per_blip = 3;
    const int seconds_per_tak = 40 * seconds_per_blip;
    const int seconds_per_salek = 15 * seconds_per_tak;
    const int seconds_per_mazel = 30 * seconds_per_salek;
    const int seconds_per_brat = 8 * seconds_per_mazel;
    const int seconds_per_termopilita_year = 73 * seconds_per_brat;

    char option;

    printf("Menu:\n");
    printf("a) converter de terrestre para termopilita\n");
    printf("b) converter de termopilita para terrestre\n");
    printf("\nO que voce quer fazer? ");

    scanf("%c", &option);

    if (option == 'a')
    {
        int day, month, hours, minutes, seconds;

        printf("Digite uma data terrestre na ordem (dia, mes, hora, minutos e segundos): ");
        scanf("%d %d %d %d %d", &day, &month, &hours, &minutes, &seconds);

        int total_seconds = 0;
        total_seconds += seconds;
        total_seconds += minutes * seconds_per_minute;
        total_seconds += hours * seconds_per_hour;
        total_seconds += (month - 1) * seconds_per_month;
        total_seconds += day * seconds_per_day;

        int blip = (total_seconds % seconds_per_tak) / seconds_per_blip;
        int tak = (total_seconds % seconds_per_salek) / seconds_per_tak;
        int salek = (total_seconds % seconds_per_mazel) / seconds_per_salek;
        int mazel = (total_seconds % seconds_per_brat) / seconds_per_mazel;
        int brat = (total_seconds % seconds_per_termopilita_year) / seconds_per_brat;

        printf("total de segundos: %d\n", total_seconds);
        printf("%d brat, %d mazel, %d salek, %d tak, %d blip\n", brat, mazel, salek, tak, blip);
    }
    else if (option == 'b')
    {
        int blip, tak, salek, mazel, brat;

        printf("Digite um data termopilita na ordem (brat, mazel, salek, tak e blip): ");
        scanf("%d %d %d %d %d", &brat, &mazel, &salek, &tak, &blip);

        int total_seconds = 0;
        total_seconds += blip * seconds_per_blip;
        total_seconds += tak * seconds_per_tak;
        total_seconds += salek * seconds_per_salek;
        total_seconds += mazel * seconds_per_mazel;
        total_seconds += brat * seconds_per_brat;


        int seconds = total_seconds % seconds_per_minute;
        int minutes = (total_seconds % seconds_per_hour) / seconds_per_minute;
        int hours = (total_seconds % seconds_per_day) / seconds_per_hour;
        int day = (total_seconds % seconds_per_month) / seconds_per_day;
        int month = (total_seconds % seconds_per_terrestrial_year) / seconds_per_month + 1;

        printf("total de segundos: %d\n", total_seconds);
        printf("dia %d, mes %d, %d horas, %d minutos, %d segundos\n", day, month, hours, minutes, seconds);
    }
    else
    {
        printf("Infelizmente, nao existe nenhuma opcao com a letra \"%c\".\n", option);
    }

    return 0;
}