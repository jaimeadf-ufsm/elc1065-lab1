#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

void RunGame()
{
    int tries = 0;
    int number = rand() % 10;

    int guess;

    do
    {
        printf("Tente advinhar meu numero secreto de 0 a 9: ");
        scanf("%d", &guess);

        tries++;
    } while (guess != number);

    printf("Voce tentou %d vezes para acertar o numero\n", tries);
}

int main()
{
    srand(time(NULL));

    char answer;

    do {
        RunGame();
        
        printf("Voce deseja jogar novamente (s/n): ");
        scanf(" %c", &answer);
    } while (answer == 's' || answer == 'S');

    return 0;
}