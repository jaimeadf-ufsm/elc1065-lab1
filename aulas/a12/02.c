#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int main()
{
    int occurrences[100];
    int n = 0;

    char string[100];
    char character;

    printf("Digite uma frase: ");
    fgets(string, 100, stdin);

    printf("Digite um caractere: ");
    scanf(" %c", &character);

    for (int i = 0; string[i] != '\0'; i++)
    {
        occurrences[n++] = i;
    }

    printf("%c aparece em %s nos indices: \n", character, string);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", occurrences[i]);
    }

    return 0;
}