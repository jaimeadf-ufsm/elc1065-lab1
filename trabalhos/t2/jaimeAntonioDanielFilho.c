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
    system("clear || cls");
}

int JogarDado()
{
    return rand() % 6 + 1;
}

bool EstaMarcada(int modalidade)
{
    return modalidade != -1;
}

// Caso as regras do jogo mudem
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

int CalcularPontuacaoTotal(
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max)
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

bool VerificarPosicao(
    char posicao,
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max)
{
    switch (posicao)
    {
    case POSICAO_FREE:
        return EstaMarcada(modalidade_free);
        break;
    case POSICAO_RANK:
        return EstaMarcada(modalidade_rank);
        break;
    case POSICAO_DOUBLE:
        return EstaMarcada(modalidade_double);
        break;
    case POSICAO_MAX:
        return EstaMarcada(modalidade_max);
        break;
    default:
        return false;
        break;
    }
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
            (linha == 1 || linha == 3) && (dado == 4 || dado == 5))
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

void ImprimirColunaPontuacao(int modalidade)
{
    printf(EstaMarcada(modalidade) ? " %10d " : "          ? ", modalidade);
    printf("|");
}

void ImprimirTabelaDaPartida(
    int linha,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max)
{
    int jogador_total = CalcularPontuacaoTotal(
        jogador_free,
        jogador_rank,
        jogador_double,
        jogador_max);
    int computador_total = CalcularPontuacaoTotal(
        computador_free,
        computador_rank,
        computador_double,
        computador_max);

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
        ImprimirColunaPontuacao(jogador_free);
        ImprimirColunaPontuacao(computador_free);
        break;
    case 4:
        printf("| Rank   |");
        ImprimirColunaPontuacao(jogador_rank);
        ImprimirColunaPontuacao(computador_rank);
        break;
    case 5:
        printf("| Double |");
        ImprimirColunaPontuacao(jogador_double);
        ImprimirColunaPontuacao(computador_double);
        break;
    case 6:
        printf("| Max    |");
        ImprimirColunaPontuacao(jogador_max);
        ImprimirColunaPontuacao(computador_max);
        break;
    case 8:
        printf("| Total  |");
        ImprimirColunaPontuacao(jogador_total);
        ImprimirColunaPontuacao(computador_total);
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

void MostrarTitulo()
{
    printf("================================= Melhor Soma de 3 ================================\n");
}

void MostrarVitoria()
{
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
    printf("\n");
}

void MostrarDerrota()
{
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
    printf(" /$$$$$$$                            /$$                                 /$$$\n");
    printf("| $$__  $$                          | $$                                /$$_/\n");
    printf("| $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$  /$$   /$$       /$$ /$$/\n");
    printf("| $$$$$$$/ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$  | $$      |__/| $$\n");
    printf("| $$____/ | $$$$$$$$| $$  \\__/| $$  | $$| $$$$$$$$| $$  | $$          | $$\n");
    printf("| $$      | $$_____/| $$      | $$  | $$| $$_____/| $$  | $$       /$$|  $$\n");
    printf("| $$      |  $$$$$$$| $$      |  $$$$$$$|  $$$$$$$|  $$$$$$/      |__/ \\  $$$\n");
    printf("|__/       \\_______/|__/       \\_______/ \\_______/ \\______/             \\___/\n");
    printf("\n");
}

void MostrarEmpate()
{
    printf("\n");
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
    printf("\n");
}

void MostrarInstrucoes()
{
    MostrarTitulo();
    printf("-> O jogo consiste em 3 partidas com 4 rodadas cada.\n");
    printf("-> Quem somar a maior quantidade de pontos durante as 3 partidas, torna-se o ganhador.\n");
    printf("\n");
    printf("-> Em cada rodada, o jogador joga 2 dados e pode escolher uma opcao:\n");
    printf("a) Marcar uma posicao na tabela\n");
    printf("b) Separar um dos dados e jogar novamente o outro\n");
    printf("c) Jogar novamente os dois dados\n");
    printf("\n");
    printf("-> Conforme o valor dos dados, o jogador marca uma posicao na tabela:\n");
    printf("f) FREE: 2 dados quaisquer (pontua a soma dos dados)\n");
    printf("r) RANK: 2 dados diferentes em sequencia (20 pontos)\n");
    printf("d) DOUBLE: 2 dados iguais diferentes de 6 (30 pontos)\n");
    printf("m) MAX: 2 dados iguais a 6 (50 pontos)\n");
    printf("\n");
    printf("OBS: Caso o jogador marque RANK, DOUBLE ou MAX ja na primeira rodada,\n");
    printf("     acrescenta-se um bonus de 5 pontos.\n");
    printf("\n");
}

void MostrarDadosComTabelaDaPartida(
    int dado_a, int dado_b,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max)
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

void MostrarCabecalhoJogador(
    int partida, int rodada,
    int dado_a, int dado_b,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max)
{
    MostrarTitulo();

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
        computador_max);
}

void MostrarCabecalhoComputador(
    int partida, int rodada,
    int dado_a, int dado_b,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max)
{
    MostrarTitulo();

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
        computador_max);
}

void MostrarResumoDaPartida(
    int partida,
    int jogador_final, int computador_final,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max,
    int computador_free, int computador_rank, int computador_double, int computador_max)
{
    MostrarTitulo();

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
            computador_max);

        printf("           ");
        ImprimirTabelaFinal(linha, jogador_final, computador_final);
        printf("\n");
    }
}

void MostrarTelaFinal(int jogador_final, int computador_final)
{
    MostrarTitulo();
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
}

void MostrarOpcoes()
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
    int rodada, int dado_a, int dado_b,
    int jogador_free, int jogador_rank, int jogador_double, int jogador_max)
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

void MostrarDecisaoRejogarDadosComputador()
{
    printf("O computador decidiu jogar os dois dados novamente.\n");
}

void MostrarDecisaoSepararDadoComputador(char letra)
{
    printf("O computador decidiu separar um dos dados e jogar novamente o outro.\n");
    printf("O computador decidiu jogar o dado %c novamente.\n", toupper(letra));
}

void MostrarDecisaoPosicaoComputador(char posicao)
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

void EsperarPorEntrada()
{
    char letra;

    printf("Aperte ENTER para continuar...");
    getchar();
}

char AvaliarMelhorOpcao(
    int dado_a, int dado_b,
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max)
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
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max)
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

char AvaliarMelhorPosicaoParaMarcar(
    int dado_a, int dado_b,
    int modalidade_free, int modalidade_rank, int modalidade_double, int modalidade_max)
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

void MaiorSomaDe3()
{
    srand(time(NULL));

    int jogador_final = 0;
    int computador_final = 0;

    Limpar();
    MostrarInstrucoes();

    EsperarPorEntrada();

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

            int computador_dado_a = JogarDado();
            int computador_dado_b = JogarDado();

            char opcao_jogador, letra_jogador, posicao_jogador;
            char opcao_computador, letra_computador, posicao_computador;

            bool posicao_valida;

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
                computador_max);

            MostrarOpcoes();

            opcao_jogador = PerguntarOpcao();

            switch (opcao_jogador)
            {
            case OPCAO_SEPARAR_DADO:
                letra_jogador = PerguntarDadoParaRejogar();

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
                computador_max);
            MostrarPossiveisPosicoes(
                rodada,
                jogador_dado_a,
                jogador_dado_b,
                jogador_free,
                jogador_rank,
                jogador_double,
                jogador_max);

            posicao_jogador = PerguntarPosicao();
            posicao_valida = VerificarPosicao(
                posicao_jogador,
                jogador_free,
                jogador_rank,
                jogador_double,
                jogador_max);

            if (!posicao_valida)
            {
                posicao_jogador = AvaliarMelhorPosicaoParaMarcar(
                    jogador_dado_a,
                    jogador_dado_b,
                    jogador_free,
                    jogador_rank,
                    jogador_double,
                    jogador_max);
            }

            switch (posicao_jogador)
            {
            case POSICAO_FREE:
                jogador_free = CalcularPontosFree(rodada, jogador_dado_a, jogador_dado_b);
                break;
            case POSICAO_RANK:
                jogador_rank = CalcularPontosRank(rodada, jogador_dado_a, jogador_dado_b);
                break;
            case POSICAO_DOUBLE:
                jogador_double = CalcularPontosDouble(rodada, jogador_dado_a, jogador_dado_b);
                break;
            case POSICAO_MAX:
                jogador_max = CalcularPontosMax(rodada, jogador_dado_a, jogador_dado_b);
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
                computador_max);

            opcao_computador = AvaliarMelhorOpcao(
                computador_dado_a,
                computador_dado_b,
                computador_free,
                computador_rank,
                computador_double,
                computador_max);

            switch (opcao_computador)
            {
            case OPCAO_SEPARAR_DADO:
                letra_computador = AvaliarMelhorDadoParaRejogar(
                    computador_dado_a,
                    computador_dado_b,
                    computador_free,
                    computador_rank,
                    computador_double,
                    computador_max);

                MostrarDecisaoSepararDadoComputador(letra_computador);
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
                MostrarDecisaoRejogarDadosComputador();
                EsperarPorEntrada();

                computador_dado_a = JogarDado();
                computador_dado_b = JogarDado();
                break;
            }

            posicao_computador = AvaliarMelhorPosicaoParaMarcar(
                computador_dado_a,
                computador_dado_b,
                computador_free,
                computador_rank,
                computador_double,
                computador_max);

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
                computador_max);
            MostrarDecisaoPosicaoComputador(posicao_computador);
            EsperarPorEntrada();
        }

        jogador_final += CalcularPontuacaoTotal(
            jogador_free,
            jogador_rank,
            jogador_double,
            jogador_max);
        computador_final += CalcularPontuacaoTotal(
            computador_free,
            computador_rank,
            computador_double,
            computador_max);

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
            computador_max);

        EsperarPorEntrada();
    }

    Limpar();
    MostrarTelaFinal(jogador_final, computador_final);

    EsperarPorEntrada();
}

int main()
{
    MaiorSomaDe3();
    return 0;
}