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

bool FormarFree(int dado_a, int dado_b)
{
    return true;
}

bool FormarRank(int dado_a, int dado_b)
{
    return dado_a + 1 == dado_b || dado_a - 1 == dado_b;
}

bool FormarDouble(int dado_a, int dado_b)
{
    return dado_a == dado_b && dado_a != 6;
}

bool FormarMax(int dado_a, int dado_b)
{
    return dado_a == 6 && dado_b == 6;
}

int CalcularBonus(int rodada)
{
    return rodada == 1 ? 5 : 0;
}

int CalcularPontosFree(int rodada, int dado_a, int dado_b)
{
    return FormarFree(dado_a, dado_b) ? dado_a + dado_b : 0;
}

int CalcularPontosRank(int rodada, int dado_a, int dado_b)
{
    return FormarRank(dado_a, dado_b) ? 20 + CalcularBonus(rodada) : 0;
}

int CalcularPontosDouble(int rodada, int dado_a, int dado_b)
{
    return FormarDouble(dado_a, dado_b) ? 30 + CalcularBonus(rodada) : 0;
}

int CalcularPontosMax(int rodada, int dado_a, int dado_b)
{
    return FormarMax(dado_a, dado_b) ? 50 + CalcularBonus(rodada) : 0;
}

int CalcularPontuacaoTotal(int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max)
{
    int total = 0;

    if (EstaMarcada(modalidade_free))
    {
        total += modalidade_free;
    }

    if (EstaMarcada(modalidade_rank))
    {
        total += modalidade_rank;
    }

    if (EstaMarcada(modalidade_double))
    {
        total += modalidade_double;
    }

    if (EstaMarcada(modalidade_max))
    {
        total += modalidade_max;
    }

    return total;
}

void ImprimirDado(int linha, int dado)
{
    if (linha == 0 || linha == 4)
    {
        printf("+-------+");
    } 
    else if (linha < 5)
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
    else
    {
        printf("         ");
    }
}

void ImprimirPontuacaoTabela(int modalidade)
{
    printf(EstaMarcada(modalidade) ? " %10d " : "          ? ", modalidade);
    printf("|");
}

void ImprimirTabelaDaPartida(
    int linha,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max
)
{
    int jogador_total = CalcularPontuacaoTotal(
        jogador_free,
        jogador_rank,
        jogador_double,
        jogador_max
    );
    int computador_total = CalcularPontuacaoTotal(
        computador_free,
        computador_rank,
        computador_double,
        computador_max
    );

    switch (linha)
    {
        case 0:
        case 2:
        case 7:
        case 9:
            printf("+--------+------------+------------+");
            break;
        case 1:
            printf("|        |    Voce    | Computador |");
            break;
        case 3:
            printf("| Free   |");
            ImprimirPontuacaoTabela(jogador_free);
            ImprimirPontuacaoTabela(computador_free);
            break;
        case 4:
            printf("| Rank   |");
            ImprimirPontuacaoTabela(jogador_rank);
            ImprimirPontuacaoTabela(computador_rank);
            break;
        case 5:
            printf("| Double |");
            ImprimirPontuacaoTabela(jogador_double);
            ImprimirPontuacaoTabela(computador_double);
            break;
        case 6:
            printf("| Max    |");
            ImprimirPontuacaoTabela(jogador_max);
            ImprimirPontuacaoTabela(computador_max);
            break;
        case 8:
            printf("| Total  |");
            ImprimirPontuacaoTabela(jogador_total);
            ImprimirPontuacaoTabela(computador_total);
    }
}

void ImprimirTabelaFinal(int linha, int jogador_final, int computador_final)
{
    switch (linha)
    {
        case 0:
        case 2:
        case 4:
            printf("+--------+------------+------------+");
            break;
        case 1:
            printf("|        |    Voce    | Computador |");
            break;
        case 3:
            printf("| Final  | %10d | %10d |", jogador_final, computador_final);
            break;
    }
}

void MostrarResumoDaPartida(
    int partida,
    int jogador_final, int computador_final,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max
)
{
    printf("Resumo da Partida");
    printf("                                                         ");
    printf("Partida %d", partida);
    printf("\n"); 

    for (int linha = 0; linha < 11; linha++)
    {
        ImprimirTabelaDaPartida(
            linha,
            jogador_free,
            jogador_rank,
            jogador_double,
            jogador_max,
            computador_free,
            computador_rank,
            computador_double,
            computador_max
        );

        printf("           ");

        ImprimirTabelaFinal(linha, jogador_final, computador_final);

        printf("\n");
    } 
}

void MostrarDadosComTabelaDaPartida(
    int dado_a, int dado_b,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max
)
{
    for (int linha = 0; linha < 11; linha++)
    {
        printf(linha == 0 ? "A) " : "   ");
        ImprimirDado(linha, dado_a);

        printf(linha == 0 ? "   B) " : "      ");
        ImprimirDado(linha, dado_b);

        printf("                    ");
        ImprimirTabelaDaPartida(
            linha,
            jogador_free,
            jogador_rank,
            jogador_double,
            jogador_max,
            computador_free,
            computador_rank,
            computador_double,
            computador_max
        );

        printf("\n");
    }
}

void MostrarTabelaFinal(int jogador_final, int computador_final)
{
    for (int linha = 0; linha < 5; linha++)
    {
        ImprimirTabelaFinal(linha, jogador_final, computador_final);
        printf("\n");
    } 
}

void MostrarVitoria()
{
    printf(" /$$$$$$$                                /$$                                     /$$\n");
    printf("| $$__  $$                              | $$                                    | $$\n");
    printf("| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$ | $$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$$| $$\n");
    printf("| $$$$$$$/ |____  $$ /$$__  $$ |____  $$| $$__  $$ /$$__  $$| $$__  $$ /$$_____/| $$\n");
    printf("| $$____/   /$$$$$$$| $$  \\__/  /$$$$$$$| $$  \\ $$| $$$$$$$$| $$  \\ $$|  $$$$$$ |__/\n");
    printf("| $$       /$$__  $$| $$       /$$__  $$| $$  | $$| $$_____/| $$  | $$ \\____  $$\n");
    printf("| $$      |  $$$$$$$| $$      |  $$$$$$$| $$$$$$$/|  $$$$$$$| $$  | $$ /$$$$$$$/ /$$\n");
    printf("|__/       \\_______/|__/       \\_______/|_______/  \\_______/|__/  |__/|_______/ |__/\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf(" /$$    /$$\n");
    printf("| $$   | $$\n");
    printf("| $$   | $$  /$$$$$$   /$$$$$$$  /$$$$$$\n");
    printf("|  $$ / $$/ /$$__  $$ /$$_____/ /$$__  $$\n");
    printf(" \\  $$ $$/ | $$  \\ $$| $$      | $$$$$$$$\n");
    printf("  \\  $$$/  | $$  | $$| $$      | $$_____/\n");
    printf("   \\  $/   |  $$$$$$/|  $$$$$$$|  $$$$$$$\n");
    printf("    \\_/     \\______/  \\_______/ \\_______/\n");
    printf("\n");
    printf("  /$$$$$$                      /$$                                     /$$$$$$$\n");
    printf(" /$$__  $$                    | $$                                    | $$__  $$\n");
    printf("| $$  \\__/  /$$$$$$  /$$$$$$$ | $$$$$$$   /$$$$$$  /$$   /$$       /$$| $$  \\ $$\n");
    printf("| $$ /$$$$ |____  $$| $$__  $$| $$__  $$ /$$__  $$| $$  | $$      |__/| $$  | $$\n");
    printf("| $$|_  $$  /$$$$$$$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  | $$          | $$  | $$\n");
    printf("| $$  \\ $$ /$$__  $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$       /$$| $$  | $$\n");
    printf("|  $$$$$$/|  $$$$$$$| $$  | $$| $$  | $$|  $$$$$$/|  $$$$$$/      |__/| $$$$$$$/\n");
    printf(" \\______/  \\_______/|__/  |__/|__/  |__/ \\______/  \\______/           |_______/\n");
}

void MostrarDerrota()
{
    printf(" /$$    /$$\n");
    printf("| $$   | $$\n");
    printf("| $$   | $$  /$$$$$$   /$$$$$$$  /$$$$$$\n");
    printf("|  $$ / $$/ /$$__  $$ /$$_____/ /$$__  $$\n");
    printf(" \\  $$ $$/ | $$  \\ $$| $$      | $$$$$$$$\n");
    printf("  \\  $$$/  | $$  | $$| $$      | $$_____/\n");
    printf("   \\  $/   |  $$$$$$/|  $$$$$$$|  $$$$$$$\n");
    printf("    \\_/     \\______/  \\_______/ \\_______/\n");
    printf("\n");
    printf(" /$$$$$$$                            /$$                                 /$$$\n");
    printf("| $$__  $$                          | $$                                /$$_/\n");
    printf("| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$  /$$   /$$       /$$ /$$/\n");
    printf("| $$$$$$$/ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$  | $$      |__/| $$\n");
    printf("| $$____/ | $$$$$$$$| $$  \\__/| $$  | $$| $$$$$$$$| $$  | $$          | $$\n");
    printf("| $$      | $$_____/| $$      | $$  | $$| $$_____/| $$  | $$       /$$|  $$\n");
    printf("| $$      |  $$$$$$$| $$      |  $$$$$$$|  $$$$$$$|  $$$$$$/      |__/ \\  $$$\n");
    printf("|__/       \\_______/|__/       \\_______/ \\_______/ \\______/             \\___/\n");   
}

void MostrarEmpate()
{
    printf(" /$$$$$$$$                                     /$$\n");
    printf("| $$_____/                                    | $$\n");
    printf("| $$       /$$$$$$/$$$$   /$$$$$$   /$$$$$$  /$$$$$$    /$$$$$$\n");
    printf("| $$$$$   | $$_  $$_  $$ /$$__  $$ |____  $$|_  $$_/   /$$__  $$\n");
    printf("| $$__/   | $$ \\ $$ \\ $$| $$  \\ $$  /$$$$$$$  | $$    | $$$$$$$$\n");
    printf("| $$      | $$ | $$ | $$| $$  | $$ /$$__  $$  | $$ /$$| $$_____/\n");
    printf("| $$$$$$$$| $$ | $$ | $$| $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$$\n");
    printf("|________/|__/ |__/ |__/| $$____/  \\_______/   \\___/   \\_______/\n");
    printf("                        | $$\n");
    printf("                        | $$\n");
    printf("                        |__/\n");
}

void MostrarCabecalhoJogador(
    int partida, int rodada,
    int dado_a, int dado_b,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max
)
{
    printf("Sua vez");
    printf("                                                          ");
    printf("Partida %d Rodada %d", partida, rodada);
    printf("\n");

    MostrarDadosComTabelaDaPartida(
        dado_a,
        dado_b,
        jogador_free,
        jogador_rank,
        jogador_double,
        jogador_max,
        computador_free,
        computador_rank,
        computador_double,
        computador_max  
    );
}

void MostrarCabecalhoComputador(
    int partida, int rodada,
    int dado_a, int dado_b,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max
)
{
    printf("Computador");
    printf("                                                       ");
    printf("Partida %d Rodada %d", partida, rodada);
    printf("\n");

    MostrarDadosComTabelaDaPartida(
        dado_a,
        dado_b,
        jogador_free,
        jogador_rank,
        jogador_double,
        jogador_max,
        computador_free,
        computador_rank,
        computador_double,
        computador_max  
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

void MostrarOpcaoRejogarDadosComputador()
{
    printf("O computador decidiu jogar os dois dados novamente.\n");
}

void MostrarOpcaoSepararDadoComputador(char letra)
{
    printf("O computador decidiu jogar o dado %c novamente.\n", toupper(letra));
}

void MostrarPosicaoComputador(char posicao)
{
    printf("O computador decidiu marcar a modalidade ");

    switch (posicao)
    {
        case POSICAO_FREE:
            printf("FREE");
            break;
        case POSICAO_RANK:
            printf("RANK");
            break;
        case POSICAO_DOUBLE:
            printf("DOUBLE");
            break;
        case POSICAO_MAX:
            printf("MAX");
            break;
        default:
            printf("?");
            break;
    }

    printf(".\n");
}

char PerguntarOpcao()
{
    char opcao;

    printf("O que voce deseja fazer? ");
    scanf(" %c", &opcao);
    getchar();

    return tolower(opcao);
}

char PerguntarPosicao()
{
    char posicao;

    printf("Em qual posicao voce deseja marcar? ");
    scanf(" %c", &posicao);
    getchar();

    return tolower(posicao);
}

char PerguntarDadoParaRejogar()
{
    char letra;

    printf("Voce deseja jogar novamente o dado A ou o dado B? ");
    scanf(" %c", &letra);
    getchar();

    return tolower(letra);
}

char AvaliarMelhorOpcao(
    int dado_a, int dado_b,
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max
)
{
    if (!EstaMarcada(modalidade_max) && FormarMax(dado_a, dado_b))
    {
        return OPCAO_MARCAR;
    }

    if (!EstaMarcada(modalidade_double) && FormarDouble(dado_a, dado_b))
    {
        return OPCAO_MARCAR;
    }

    if (!EstaMarcada(modalidade_rank) && FormarRank(dado_a, dado_b))
    {
        return OPCAO_MARCAR;
    }

    if (!EstaMarcada(modalidade_free) && dado_a == 6 && dado_b == 6)
    {
        return OPCAO_MARCAR;
    }

    if (!EstaMarcada(modalidade_max) && (dado_a == 6 && dado_b != 6 || dado_b == 6 && dado_a != 6))
    {
        return OPCAO_SEPARAR_DADO;
    }

    if (!EstaMarcada(modalidade_rank) || !EstaMarcada(modalidade_double))
    {
        return OPCAO_SEPARAR_DADO;
    }

    return OPCAO_REJOGAR_DADOS;
}

char AvaliarMelhorDadoParaRejogar(
    int dado_a, int dado_b,
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max
) 
{
    if (!EstaMarcada(modalidade_max))
    {
        if (dado_a == 6)
        {
            return LETRA_DADO_B;
        }

        if (dado_b == 6)
        {
            return LETRA_DADO_A;
        }
    }

    if (dado_a == 1 || dado_a == 6)
    {
        return LETRA_DADO_A;
    }

    if (dado_b == 1 || dado_b == 6)
    {
        return LETRA_DADO_B;
    }

    if (dado_a >= dado_b)
    {
        return LETRA_DADO_B;
    }

    return LETRA_DADO_A;
}

char AvaliarMelhorPosicao(
    int dado_a, int dado_b,
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max
)
{
    if (!EstaMarcada(modalidade_max) && FormarMax(dado_a, dado_b))
    {
        return POSICAO_MAX;
    }

    if (!EstaMarcada(modalidade_double) && FormarDouble(dado_a, dado_b))
    {
        return POSICAO_DOUBLE;
    }

    if (!EstaMarcada(modalidade_rank) && FormarRank(dado_a, dado_b))
    {
        return POSICAO_RANK;
    }
    
    if (!EstaMarcada(modalidade_free))
    {
        return POSICAO_FREE;
    }

    if (!EstaMarcada(modalidade_max))
    {
        return POSICAO_MAX;
    }

    if (!EstaMarcada(modalidade_double))
    {
        return POSICAO_DOUBLE;
    }

    return POSICAO_RANK;
}

void EsperarPorEntrada()
{
    printf("Aperte ENTER para continuar...");
    getchar();
}

void MaiorSomaDe3()
{
    srand(time(NULL));

    int jogador_final = 0;
    int computador_final = 0;

    for (int partida = 1; partida <= 3; partida++)
    {
        int jogador_free = -1;
        int jogador_rank = -1;
        int jogador_double = -1;
        int jogador_max = -1;

        int computador_free = -1;
        int computador_rank = -1;
        int computador_double = -1;
        int computador_max = -1;

        for (int rodada = 1; rodada <= 4; rodada++)
        {
            int jogador_dado_a = JogarDado();
            int jogador_dado_b = JogarDado();

            Limpar();
            MostrarCabecalhoJogador(
                partida,
                rodada,
                jogador_dado_a,
                jogador_dado_b,
                jogador_free,
                jogador_rank,
                jogador_double,
                jogador_max,
                computador_free,
                computador_rank,
                computador_double,
                computador_max  
            );

            MostrarOpcoes(jogador_dado_a, jogador_dado_b);

            char opcao_jogador = PerguntarOpcao();

            switch (opcao_jogador)
            {
                case OPCAO_SEPARAR_DADO:
                    char letra_jogador = PerguntarDadoParaRejogar();
                    
                    if (letra_jogador == LETRA_DADO_A)
                    {
                        jogador_dado_a = JogarDado();
                    }
                    else
                    {
                        jogador_dado_b = JogarDado();
                    }
                    break;
                case OPCAO_REJOGAR_DADOS:
                    jogador_dado_a = JogarDado();
                    jogador_dado_b = JogarDado();
                    break;
            }

            Limpar();
            MostrarCabecalhoJogador(
                partida,
                rodada,
                jogador_dado_a,
                jogador_dado_b,
                jogador_free,
                jogador_rank,
                jogador_double,
                jogador_max,
                computador_free,
                computador_rank,
                computador_double,
                computador_max  
            );
            MostrarPossiveisPosicoes(
                jogador_free,
                jogador_rank,
                jogador_double,
                jogador_max,
                rodada,
                jogador_dado_a,
                jogador_dado_b
            );
 
            char posicao_jogador = PerguntarPosicao();

            switch (posicao_jogador)
            {
                case POSICAO_FREE:
                    if (!EstaMarcada(jogador_free))
                    {
                        jogador_free = CalcularPontosFree(rodada, jogador_dado_a, jogador_dado_b);
                    }
                    break;
                case POSICAO_RANK:
                    if (!EstaMarcada(jogador_rank))
                    {
                        jogador_rank = CalcularPontosRank(rodada, jogador_dado_a, jogador_dado_b);
                    }
                    break;
                case POSICAO_DOUBLE:
                    if (!EstaMarcada(jogador_double))
                    {
                        jogador_double = CalcularPontosDouble(rodada, jogador_dado_a, jogador_dado_b);
                    }
                    break;               
                case POSICAO_MAX:
                    if (!EstaMarcada(jogador_max))
                    {
                        jogador_max = CalcularPontosMax(rodada, jogador_dado_a, jogador_dado_b);
                    }
                    break;
            }

            int computador_dado_a = JogarDado();
            int computador_dado_b = JogarDado();

            Limpar();
            MostrarCabecalhoComputador(
                partida,
                rodada,
                computador_dado_a,
                computador_dado_b,
                jogador_free,
                jogador_rank,
                jogador_double,
                jogador_max,
                computador_free,
                computador_rank,
                computador_double,
                computador_max  
            );

            char opcao_computador = AvaliarMelhorOpcao(
                computador_dado_a,
                computador_dado_b,
                computador_free,
                computador_rank,
                computador_double,
                computador_max
            );

            switch (opcao_computador)
            {
                case OPCAO_SEPARAR_DADO:
                    char letra_computador = AvaliarMelhorDadoParaRejogar(
                        computador_dado_a,
                        computador_dado_b,
                        computador_free,
                        computador_rank,
                        computador_double,
                        computador_max
                    );

                    MostrarOpcaoSepararDadoComputador(letra_computador);
                    EsperarPorEntrada();

                    if (letra_computador == LETRA_DADO_A)
                    {
                        computador_dado_a = JogarDado();
                    }
                    else
                    {
                        computador_dado_b = JogarDado();
                    }
                    break;
                case OPCAO_REJOGAR_DADOS:
                    MostrarOpcaoRejogarDadosComputador();
                    EsperarPorEntrada();

                    computador_dado_a = JogarDado();
                    computador_dado_b = JogarDado();
                    break;
            }

            char posicao_computador = AvaliarMelhorPosicao(
                computador_dado_a,
                computador_dado_b,
                computador_free,
                computador_rank,
                computador_double,
                computador_max  
            );

            switch (posicao_computador)
            {
                case POSICAO_FREE:
                    computador_free = CalcularPontosFree(rodada, computador_dado_a, computador_dado_b);
                    break;
                case POSICAO_RANK:
                    computador_rank = CalcularPontosRank(rodada, computador_dado_a, computador_dado_b);
                    break;
                case POSICAO_DOUBLE:
                    computador_double = CalcularPontosDouble(rodada, computador_dado_a, computador_dado_b);
                    break;
                case POSICAO_MAX:
                    computador_max = CalcularPontosMax(rodada, computador_dado_a, computador_dado_b);
                    break;
            }

            Limpar();
            MostrarCabecalhoComputador(
                partida,
                rodada,
                computador_dado_a,
                computador_dado_b,
                jogador_free,
                jogador_rank,
                jogador_double,
                jogador_max,
                computador_free,
                computador_rank,
                computador_double,
                computador_max  
            );
            MostrarPosicaoComputador(posicao_computador);
            EsperarPorEntrada();
        }

        jogador_final += CalcularPontuacaoTotal(
            jogador_free,
            jogador_rank,
            jogador_double,
            jogador_max
        );
        computador_final += CalcularPontuacaoTotal(
            computador_free,
            computador_rank,
            computador_double,
            computador_max
        );

        Limpar();
        MostrarResumoDaPartida(
            partida,
            jogador_final,
            computador_final,
            jogador_free,
            jogador_rank,
            jogador_double,
            jogador_max,
            computador_free,
            computador_rank,
            computador_double,
            computador_max
        );

        EsperarPorEntrada();
    }

    Limpar();
    MostrarTabelaFinal(jogador_final, computador_final);

    if (jogador_final > computador_final)
    {
        MostrarVitoria();
    }
    else if (computador_final > jogador_final)
    {
        MostrarDerrota();
    }
    else
    {
        MostrarEmpate();
    }

    EsperarPorEntrada();
}

int main()
{
    MaiorSomaDe3();
    return 0;
}