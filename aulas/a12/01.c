#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void Replace()
{
    char string1[100];
    char string2[100];
    
    char c1;
    char c2;

    int i;

    printf("Digite um texto: ");
    scanf("%s", string1);

    printf("Voce deseja substituir qual caractere por qual caractere: ");
    scanf(" %c %c", &c1, &c2);

    for (i = 0; string1[i] != '\0'; i++)
    {
        string2[i] = string1[i] == c1 ? c2 : string1[i];
    }

    string2[i] = '\0';

    printf("%s\n", string1);
    printf("%s\n", string2);
}

int main()
{
    Replace();

    return 0;
}