#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 7
#define CENTRO 3

void Limpar()
{
    system("clear || cls");
}

void PreencherMatriz(char matriz[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            matriz[i][j] = '.';
        }
    }

    matriz[0][0] = '0';
    matriz[0][6] = 'X';
    matriz[6][0] = 'X';
    matriz[6][6] = '0';
    
    matriz[1][1] = 'X';
    matriz[1][5] = '0';
    matriz[5][1] = '0';
    matriz[5][5] = 'X';

    matriz[2][3] = '0';
    matriz[3][2] = 'X';
    matriz[3][4] = 'X';
    matriz[4][3] = '0';
}

void ImprimirMatriz(char matriz[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("  %c  ", matriz[i][j]);
        }

        printf("\n\n");
    }
}

void GirarAntiHorario(char matriz[TAMANHO][TAMANHO], int camada)
{
    int borda_inicial = camada;
    int borda_final = TAMANHO - camada - 1;

    char temporario = matriz[borda_inicial][borda_inicial];

    for (int i = borda_inicial; i < borda_final; i++)
    {
        matriz[borda_inicial][i] = matriz[borda_inicial][i + 1];
    }

    for (int j = borda_inicial; j < borda_final; j++)
    {
        matriz[j][borda_final] = matriz[j + 1][borda_final];
    }

    for (int i = borda_final; i > borda_inicial; i--)
    {
        matriz[borda_final][i] = matriz[borda_final][i - 1];
    }

    for (int j = borda_final; j > borda_inicial; j--)
    {
        matriz[j][borda_inicial] = matriz[j - 1][borda_inicial];
    }

    matriz[borda_inicial + 1][borda_inicial] = temporario;
}

void GirarHorario(char matriz[TAMANHO][TAMANHO], int camada)
{
    int borda_inicial = camada;
    int borda_final = TAMANHO - camada - 1;

    char temporario = matriz[borda_inicial][borda_inicial];

    for (int i = borda_inicial; i < borda_final; i++)
    {
        matriz[i][borda_inicial] = matriz[i + 1][borda_inicial];
    }

    for (int j = borda_inicial; j < borda_final; j++)
    {
        matriz[borda_final][j] = matriz[borda_final][j + 1];
    }
    
    for (int i = borda_final; i > borda_inicial; i--)
    {
        matriz[i][borda_final] = matriz[i - 1][borda_final];
    }

    for (int j = borda_final; j > borda_inicial; j--)
    {
        matriz[borda_inicial][j] = matriz[borda_inicial][j - 1];
    }

    matriz[borda_inicial][borda_inicial + 1] = temporario;
}

bool VerificarCruz(char matriz[TAMANHO][TAMANHO])
{
    char caractere = matriz[0][CENTRO];

    if (caractere == '.')
    {
        return false;
    }

    for (int i = 1; i < CENTRO; i++)
    {
        if (matriz[i][CENTRO] != caractere)
        {
            return false;
        }
    }

    return true;
}

bool VerificarX(char matriz[TAMANHO][TAMANHO])
{
    char caractere = matriz[0][0];

    if (caractere == '.')
    {
        return false;
    }

    for (int i = 1; i < CENTRO; i++)
    {
        if (matriz[i][i] != caractere)
        {
            return false;
        }
    }

    return true;
}

int main()
{   
    char matriz[TAMANHO][TAMANHO];

    char opcao;

    PreencherMatriz(matriz);

    do
    {
        Limpar();
        ImprimirMatriz(matriz);

        if (VerificarCruz(matriz))
        {
            printf("Cruz desenhada.\n");
        }
        else if (VerificarX(matriz))
        {
            printf("X desenhado.\n");
        }
        
        printf("\nCamadas:\n");
        printf("1) Gira no sentido anti-horario.\n");
        printf("2) Gira no sentido horario.\n");
        printf("3) Gira no sentido anti-horario.\n");
        printf("s) Sair\n");
        printf("\nQual camada voce deseja girar? ");

        scanf(" %c", &opcao);

        switch (opcao)
        {
            case '1':
                GirarAntiHorario(matriz, 0);
                break;
            case '2':
                GirarHorario(matriz, 1);
                break;
            case '3':
                GirarAntiHorario(matriz, 2);
                break;
        }
    } while (opcao != 's');

    return 0;
}