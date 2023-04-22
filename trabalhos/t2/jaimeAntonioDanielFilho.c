#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define LETRA_DADO_A 'a'
#define LETRA_DADO_B 'b'

#define OPCAO_MARCAR 'a'
#define OPCAO_SEPARAR_DADO 'b'
#define OPCAO_REJOGAR_DADOS 'c'

#define POSICAO_FREE 'f'
#define POSICAO_RANK 'r'
#define POSICAO_DOUBLE 'd'
#define POSICAO_MAX 'm'

void Limpar()
{
    system("clear");
}

int JogarDado()
{
    return rand() % 6 + 1;
}

bool EstaMarcada(int modalidade)
{
    return modalidade != -1;
}

bool PodeMarcarFree(int dado_a, int dado_b)
{
    return true;
}

bool PodeMarcarRank(int dado_a, int dado_b)
{
    return dado_a + 1 == dado_b || dado_a - 1 == dado_b;
}

bool PodeMarcarDouble(int dado_a, int dado_b)
{
    return dado_a == dado_b && dado_a != 6;
}

bool PodeMarcarMax(int dado_a, int dado_b)
{
    return dado_a == 6 && dado_b == 6;
}

int CalcularBonus(int rodada)
{
    return rodada == 1 ? 5 : 0;
}

int CalcularPontosFree(int rodada, int dado_a, int dado_b)
{
    return PodeMarcarFree(dado_a, dado_b) ? dado_a + dado_b : 0;
}

int CalcularPontosRank(int rodada, int dado_a, int dado_b)
{
    return PodeMarcarRank(dado_a, dado_b) ? 20 + CalcularBonus(rodada) : 0;
}

int CalcularPontosDouble(int rodada, int dado_a, int dado_b)
{
    return PodeMarcarDouble(dado_a, dado_b) ? 30 + CalcularBonus(rodada) : 0;
}

int CalcularPontosMax(int rodada, int dado_a, int dado_b)
{
    return PodeMarcarMax(dado_a, dado_b) ? 50 + CalcularBonus(rodada) : 0;
}

void ImprimirDado(int linha, int dado)
{
    if (linha >= 5)
    {
        printf("         ");
    }
    else if (linha == 0 || linha == 4)
    {
        printf("+-------+");
    } 
    else
    {
        printf("| ");

        if (
            dado == 6 ||
            (linha == 1 || linha == 3) && (dado == 4 || dado == 5)
        )
        {
            printf("O   O");
        }
        else if (linha == 1 && (dado == 2 || dado == 3))
        {
            printf("O    ");
        }
        else if (linha == 2 && dado % 2 == 1)
        {
            printf("  O  ");
        }
        else if (linha == 3 && (dado == 2 || dado == 3))
        {
            printf("    O");
        }
        else
        {
            printf("     ");
        }

        printf(" |");
    }
}

void ImprimirPontuacaoTabela(int modalidade)
{
    printf(EstaMarcada(modalidade) ? " %9d " : "         ? ", modalidade);
    printf("|");
}

void ImprimirTabela(
    int linha,
    int jogador1_free, int jogador1_rank, int jogador1_double, int jogador1_max,
    int jogador2_free, int jogador2_rank, int jogador2_double, int jogador2_max
)
{
    switch (linha)
    {
        case 0:
        case 2:
        case 7:
            printf("+--------+-----------+-----------+");
            break;
        case 1:
            printf("|        | Jogador 1 | Jogador 2 |");
            break;
        case 3:
            printf("| Free   |");
            ImprimirPontuacaoTabela(jogador1_free);
            ImprimirPontuacaoTabela(jogador2_rank);
            break;
        case 4:
            printf("| Rank   |");
            ImprimirPontuacaoTabela(jogador1_rank);
            ImprimirPontuacaoTabela(jogador2_rank);
            break;
        case 5:
            printf("| Double |");
            ImprimirPontuacaoTabela(jogador1_double);
            ImprimirPontuacaoTabela(jogador2_double);
            break;
        case 6:
            printf("| Max    |");
            ImprimirPontuacaoTabela(jogador1_max);
            ImprimirPontuacaoTabela(jogador2_max);
            break;
    }
}

void MostrarDadosComTabela(
    int dado_a, int dado_b,
    int jogador1_free, int jogador1_rank, int jogador1_double, int jogador1_max,
    int jogador2_free, int jogador2_rank, int jogador2_double, int jogador2_max
)
{
    for (int linha = 0; linha < 9; linha++)
    {
        printf(linha == 0 ? "A) " : "   ");
        ImprimirDado(linha, dado_a);

        printf(linha == 0 ? "   B) " : "      ");
        ImprimirDado(linha, dado_b);

        printf("                    ");
        ImprimirTabela(
            linha,
            jogador1_free,
            jogador1_rank,
            jogador1_double,
            jogador1_max,
            jogador2_free,
            jogador2_rank,
            jogador2_double,
            jogador2_max
        );

        printf("\n");
    }
}

void MostrarCabecalho(
    int partida, int rodada,
    int dado_a, int dado_b,
    int jogador1_free, int jogador1_rank, int jogador1_double, int jogador1_max,
    int jogador2_free, int jogador2_rank, int jogador2_double, int jogador2_max
)
{
    printf("Partida %d Rodada %d\n", partida, rodada);

    MostrarDadosComTabela(
        dado_a,
        dado_b,
        jogador1_free,
        jogador1_rank,
        jogador1_double,
        jogador1_max,
        jogador2_free,
        jogador2_rank,
        jogador2_double,
        jogador2_max  
    );
}

void MostrarOpcoes(int dado_a, int dado_b)
{
    printf("Opcoes: \n");
    printf("a) Marcar uma posicao na tabela\n");
    printf("b) Separar um dos dados e jogar novamente o outro\n");
    printf("c) Jogar novamente os dois dados\n");
    printf("\n");
}

void MostrarPossivelPosicao(char *nome, int pontos)
{
    printf("%s: %d pontos\n", nome, pontos);
}

void MostrarPossiveisPosicoes(
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int rodada, int dado_a, int dado_b
)
{
    printf("Posicoes:\n");

    if (!EstaMarcada(jogador_free))
    {
        MostrarPossivelPosicao("f) FREE", CalcularPontosFree(rodada, dado_a, dado_b));
    }

    if (!EstaMarcada(jogador_rank))
    {
        MostrarPossivelPosicao("r) RANK", CalcularPontosRank(rodada, dado_a, dado_b));
    }

    if (!EstaMarcada(jogador_double))
    {
        MostrarPossivelPosicao("d) DOUBLE", CalcularPontosDouble(rodada, dado_a, dado_b));
    }

    if (!EstaMarcada(jogador_max))
    {
        MostrarPossivelPosicao("m) MAX", CalcularPontosMax(rodada, dado_a, dado_b));
    }

    printf("\n");
}

char PerguntarOpcao()
{
    char opcao;

    printf("O que voce deseja fazer? ");
    scanf(" %c", &opcao);

    return tolower(opcao);
}

char PerguntarPosicao()
{
    char posicao;

    printf("Em qual posicao voce deseja marcar? ");
    scanf(" %c", &posicao);

    return tolower(posicao);
}

char PerguntarDadoParaRejogar()
{
    char letra;

    printf("Voce deseja jogar novamente o dado A ou o dado B? ");
    scanf(" %c", &letra);

    return tolower(letra);
}

void EsperePorEntrada()
{
    printf("Aperte ENTER para continuar...");
    getchar();
    getchar();
}

void MaiorSomaDe3()
{
    srand(time(NULL));

    for (int partida = 1; partida <= 3; partida++)
    {
        int jogador1_free = -1;
        int jogador1_rank = -1;
        int jogador1_double = -1;
        int jogador1_max = -1;
        int jogador2_free = -1;
        int jogador2_rank = -1;
        int jogador2_double = -1;
        int jogador2_max = -1;

        for (int rodada = 1; rodada <= 4; rodada++)
        {
            int dado_a = JogarDado();
            int dado_b = JogarDado();

            Limpar();
            MostrarCabecalho(
                partida,
                rodada,
                dado_a,
                dado_b,
                jogador1_free,
                jogador1_rank,
                jogador1_double,
                jogador1_max,
                jogador2_free,
                jogador2_rank,
                jogador2_double,
                jogador2_max  
            );
            MostrarOpcoes(dado_a, dado_b);

            char opcao = PerguntarOpcao();

            switch (opcao)
            {
                case OPCAO_SEPARAR_DADO:
                    char letra = PerguntarDadoParaRejogar();
                    
                    if (letra == LETRA_DADO_A)
                    {
                        dado_a = JogarDado();
                    }
                    else
                    {
                        dado_b = JogarDado();
                    }
                    break;
                case OPCAO_REJOGAR_DADOS:
                    dado_a = JogarDado();
                    dado_b = JogarDado();
                    break;
            }

            Limpar();
            MostrarCabecalho(
                partida,
                rodada,
                dado_a,
                dado_b,
                jogador1_free,
                jogador1_rank,
                jogador1_double,
                jogador1_max,
                jogador2_free,
                jogador2_rank,
                jogador2_double,
                jogador2_max  
            );
            MostrarPossiveisPosicoes(
                jogador1_free,
                jogador1_rank,
                jogador1_double,
                jogador1_max,
                rodada,
                dado_a,
                dado_b
            );
 
            char posicao = PerguntarPosicao();

            switch (posicao)
            {
                case POSICAO_FREE:
                    if (!EstaMarcada(jogador1_free))
                    {
                        jogador1_free = CalcularPontosFree(rodada, dado_a, dado_b);
                    }
                    break;
                case POSICAO_RANK:
                    if (!EstaMarcada(jogador1_rank))
                    {
                        jogador1_rank = CalcularPontosRank(rodada, dado_a, dado_b);
                    }
                    break;
                case POSICAO_DOUBLE:
                    if (!EstaMarcada(jogador1_double))
                    {
                        jogador1_double = CalcularPontosDouble(rodada, dado_a, dado_b);
                    }
                    break;               
                case POSICAO_MAX:
                    if (!EstaMarcada(jogador1_max))
                    {
                        jogador1_max = CalcularPontosMax(rodada, dado_a, dado_b);
                    }
                    break;
            }

            EsperePorEntrada();
        }
    }
}

int main()
{
    MaiorSomaDe3();
    return 0;
}