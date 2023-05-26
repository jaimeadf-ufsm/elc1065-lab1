#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void Insert(char *string1, char *string2, int index)
{
    for (int i = 0; i < strlen(string2); i++)
    {
        for (int j = strlen(string1); j > index + i; j--)
        {
            string1[j] = string1[j - 1];
        }

        string1[index + i] = string2[i];
    }
}

int main()
{
    char string1[200];
    char string2[100];
    
    int index;

    printf("Digite a string 1: ");
    gets(string1);

    printf("Digite a string 2: ");
    gets(string2);

    printf("Em qual indice da string 1 voce deseja inserir a string 2? ");
    scanf("%d", &index);

    Insert(string1, string2, index);

    printf("\n%s\n", string1);

    return 0;
}