#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAM_SEQUENCIA 100
#define TAM_PALAVRA 10

int LerN()
{
    int n;

    do {
        printf("Voce deseja fazer uma sequencia de quantas palavras (2 a %d)? ", TAM_SEQUENCIA);
        scanf("%d", &n);

        if (n < 2 || n > TAM_SEQUENCIA)
        {
            printf("Por favor, digite um numero de palavras valido de 2 ate %d.\n", TAM_SEQUENCIA);
        }
    } while (n < 2 || n > TAM_SEQUENCIA);

    return n;
}

void LerSequencia(char sequencia[TAM_SEQUENCIA][TAM_PALAVRA], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite a palavra %d: ", i + 1);
        scanf("%s", sequencia[i]);
    }
}

void ImprimirSequencia(char sequencia[TAM_SEQUENCIA][TAM_PALAVRA], int n)
{
    printf("\n%s", sequencia[0]);

    for (int i = 1; i < n; i++)
    {
        printf(" -> %s", sequencia[i]);
    }

    printf("\n\n");
}

int ContarDiferencas(char palavra1[TAM_PALAVRA], char palavra2[TAM_PALAVRA], int comprimento)
{
    int diferencas = 0;

    for (int i = 0; i < comprimento; i++)
    {
        if (palavra1[i] != palavra2[i])
        {
            diferencas++;
        }
    }

    return diferencas;
}

bool VerificarSequencia(char sequencia[TAM_SEQUENCIA][TAM_PALAVRA], int n)
{
    for (int i = 1; i < n; i++)
    {
        int comprimento_anterior = strlen(sequencia[i - 1]);
        int comprimento_atual = strlen(sequencia[i]);

        if (comprimento_anterior != comprimento_atual)
        {
            printf("Infelizmente, a sequencia foi quebrada por diferentes tamanhos.\n");
            printf(
                "A palavra \"%s\" possui %d letras que difere das %d letras da palavra anterior \"%s\".\n\n",
                sequencia[i],
                comprimento_atual,
                comprimento_anterior,
                sequencia[i - 1]
            );

            return false;
        }

        int diferencas = ContarDiferencas(sequencia[i - 1], sequencia[i], comprimento_atual);

        if (diferencas > 1)
        {
            printf("Infelizmente, a sequencia foi quebrada por grandes mudancas.\n");
            printf(
                "A palavra \"%s\" difere em %d letras da palavra anterior \"%s\".\n\n",
                sequencia[i],
                diferencas,
                sequencia[i - 1]
            );

            return false;
        }
    }

    return true;
}

int main()
{
    char sequencia[TAM_SEQUENCIA][TAM_PALAVRA];

    printf("==================== Jogo de Palavras ====================\n");

    int n = LerN();

    printf("\nAgora, digite a sequencia de %d palavras:\n", n);
    printf("-> Todas a palavras devem ter o mesmo comprimento (maximo %d caracteres).\n", TAM_PALAVRA);
    printf("-> Duas palavras consecutivas podem variar em apenas 1 letra.\n\n");

    LerSequencia(sequencia, n);
    ImprimirSequencia(sequencia, n);

    if (VerificarSequencia(sequencia, n))
    {
        printf(
            "PARABENS!!! Voce encontrou uma sequencia de palavras de \"%s\" a \"%s\".\n",
            sequencia[0],
            sequencia[n - 1]
        );
    }
    else
    {
        printf("Boa sorte na proxima tentativa.\n");
    }

    return 0;
}