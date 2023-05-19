#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 7
#define CENTRO 3

void Limpar()
{
    system("clear || cls");
}

void ImprimirMatriz(char matriz[TAMANHO][TAMANHO])
{
    for (int linha = 0; linha < TAMANHO; linha++)
    {
        for (int coluna = 0; coluna < TAMANHO; coluna++)
        {
            printf(" %c ", matriz[linha][coluna]);
        }

        printf("\n");
    }
}

bool EstaNoCanto(int camada, int linha, int coluna)
{
    int borda_inicial = camada;
    int borda_final = TAMANHO - camada - 1;

    return (linha == borda_inicial || linha == borda_final) &&
        (coluna == borda_inicial || coluna == borda_final);
}

void Girar(char matriz[TAMANHO][TAMANHO], int camada, int direcao_linha, int direcao_coluna)
{
    int linha_inicial = camada;
    int coluna_inicial = camada;

    int linha = linha_inicial;
    int coluna = coluna_inicial;

    char anterior = matriz[linha][coluna];

    do
    {
        linha += direcao_linha;
        coluna += direcao_coluna;

        if (EstaNoCanto(camada, linha, coluna))
        {
            int direcao_temporaria = direcao_linha;

            direcao_linha = direcao_coluna;
            direcao_coluna = direcao_temporaria;

            if (linha == coluna)
            {
                direcao_linha *= -1;
                direcao_coluna *= -1;
            }
        }

        char atual = matriz[linha][coluna];

        matriz[linha][coluna] = anterior;
        anterior = atual;
    } while (linha != linha_inicial || coluna != coluna_inicial);
}

void GirarHorario(char matriz[TAMANHO][TAMANHO], int camada)
{
    Girar(matriz, camada, 0, 1);
}

void GirarAntiHorario(char matriz[TAMANHO][TAMANHO], int camada)
{
    Girar(matriz, camada, 1, 0);
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
    char matriz[TAMANHO][TAMANHO] = {
        { '0', '.', '.', '.', '.', '.', 'X' },
        { '.', 'X', '.', '.', '.', '0', '.' },
        { '.', '.', '.', '0', '.', '.', '.' },
        { '.', '.', 'X', '.', 'X', '.', '.' },
        { '.', '.', '.', '0', '.', '.', '.' },
        { '.', '0', '.', '.', '.', 'X', '.' },
        { 'X', '.', '.', '.', '.', '.', '0' }
    };

    char opcao;

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