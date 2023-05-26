#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void Intercalate(char *string1, char *string2, char *output)
{
    int n = strlen(string1) + strlen(string2);

    for (int i = 0; string1[i] != '\0'; i++)
    {
        output[2 * i] = string1[i];
    }

    for (int i = 0; string2[i] != '\0'; i++)
    {
        output[2 * i + 1] = string2[i];
    }

    output[n] = '\0';
}

void Desintercalate(char *string, char *output1, char *output2)
{
    int n1 = 0, n2 = 0;

    for (int i = 0; i < strlen(string); i += 2)
    {
        output1[i / 2] = string[i];
        n1++;
    }

    for (int j = 1; j < strlen(string); j += 2)
    {
        output2[j / 2] = string[j];
        n2++;
    }

    output1[n1] = '\0';
    output2[n2] = '\0';
}

int main()
{
    char option;

    char input1[100];
    char input2[100];

    char output1[100];
    char output2[100];


    printf("Opcoes:\n");
    printf("a) Intercalar\n");
    printf("b) Desintercalar\n");
    printf("\nO que voce deseja fazer? ");

    scanf(" %c", &option);

    switch (option)
    {
        case 'a':
            printf("Digite a primeira palavra:");
            scanf("%s", input1);
            printf("Digite a segunda palavra:");
            scanf("%s", input2);

            Intercalate(input1, input2, output1);

            printf("\nIntercaladas: %s\n", output1);

            break;
        case 'b':
            printf("Digite a palavra intercalada: ");
            scanf("%s", input1);

            Desintercalate(input1, output1, output2);

            printf("\nDesintercaladas: %s %s\n", output1, output2);

            break;
    }    

    return 0;
}