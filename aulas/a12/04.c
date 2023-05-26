#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    char words[10][100];
    int sizes[10];
    
    printf("Digite 10 palavras:\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        sizes[i] = 0;

        for (int j = 0; words[i][j] != '\0'; j++)
        {
            sizes[i]++;
        }
    }

    printf("\nTamanhos:\n");

    int bigger_index = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("%s %d\n", words[i], sizes[i]);

        if (sizes[i] > sizes[bigger_index])
        {
            bigger_index = i;
        }
    }

    printf("A maior palavra foi %s com %d caracteres.", words[bigger_index], sizes[bigger_index]);

    return 0;
}