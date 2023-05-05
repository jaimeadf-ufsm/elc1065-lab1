#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EMPATE 0
#define JOGADOR_1 1
#define JOGADOR_2 2

#define MODO_VS_PLAYER 'a'
#define MODO_VS_COMPUTADOR 'b'

#define JOGADA_PASSAR_VEZ 'a'
#define JOGADA_JOGAR_DADOS 'b'

void Limpar()
{
    system("clear || cls");
}

int JogarDado()
{
    return rand() % 6 + 1;
}

int CalcularPontosDadoVermelho(int dado)
{
    return dado == 6 ? 2 * dado : dado;
}

void MostrarTitulo()
{
    printf("==================== A Guerra dos Dados ====================\n");
}

void MostrarPontos(int jogador1_pontos, int jogador2_pontos)
{
    printf("Jogador 1: %d pontos\n", jogador1_pontos);
    printf("Jogador 2: %d pontos\n", jogador2_pontos);
}

void MostrarCabecalhoTurno(int jogador, int rodada, int jogador1_pontos, int jogador2_pontos)
{
    MostrarTitulo();
    printf("Vez do Jogador %d                                   Rodada %2d\n", jogador, rodada);
    MostrarPontos(jogador1_pontos, jogador2_pontos);
    printf("\n");
}

void MostrarDado(int dado)
{
    printf("+-------+\n");

    switch (dado)
    {
        case 1:
            printf("|       |\n");
            printf("|   O   |\n");
            printf("|       |\n");
            break;
        case 2:
            printf("| O     |\n");
            printf("|       |\n");
            printf("|     O |\n");
            break;
        case 3:
            printf("| O     |\n");
            printf("|   O   |\n");
            printf("|     O |\n");
            break;
        case 4:
            printf("| O   O |\n");
            printf("|       |\n");
            printf("| O   O |\n");
            break;
        case 5:
            printf("| O   O |\n");
            printf("|   O   |\n");
            printf("| O   O |\n");
            break;
        case 6:
            printf("| O   O |\n");
            printf("| O   O |\n");
            printf("| O   O |\n");
            break;
    }

    printf("+-------+\n");
}

void MostrarDadoBranco(int dado, int pontos)
{
    printf("Branco) %d pontos\n", pontos);
    MostrarDado(dado);
    printf("\n");
}

void MostrarDadoVermelho(int dado, int pontos)
{
    printf("Vermelho) %d pontos\n");
    MostrarDado(dado);
    printf("\n");
}

void MostrarResultado(int resultado)
{
    printf("\n");

    switch (resultado)
    {
        case EMPATE:
            printf("Empate!\n");
            break;
        case JOGADOR_1:
            printf("O jogador 1 ganhou!\n");
            break;
        case JOGADOR_2:
            printf("O jogador 2 ganhou!\n");
            break;
    }

    printf("\n");
}

char LerCaractere()
{
    char caractere, nova_linha;

    scanf(" %c", &caractere);
    scanf("%c", &nova_linha);

    return caractere;
}

char PerguntarModo()
{
    char modo;

    do {
        printf("Modos:\n");
        printf("a) Player X Player\n");
        printf("b) Player x Computador\n");
        printf("\n");
        printf("Qual modo voce deseja jogar? ");

        modo = LerCaractere();
    } while (modo != MODO_VS_PLAYER && modo != MODO_VS_COMPUTADOR);

    return modo;
}

char PerguntarJogada()
{
    char jogada;

    do {
        printf("Opcoes:\n");
        printf("a) Passar a vez\n");
        printf("b) Jogar dados\n");
        printf("\n");
        printf("O que voce deseja fazer? ");

        jogada = LerCaractere();
    } while (jogada != JOGADA_PASSAR_VEZ && jogada != JOGADA_JOGAR_DADOS);

    return jogada;
}

bool PerguntarJogarNovamente()
{
    printf("Voce deseja jogar uma nova partida (s/n)? ");
    char resposta = LerCaractere();

    return resposta == 's' || resposta == 'S';
}

void EsperarPorEntrada()
{
    char nova_linha;

    printf("Aperte ENTER para continuar...");
    scanf("%c", &nova_linha);
}

int JogarDados(int jogador, int rodada, int jogador1_pontos, int jogador2_pontos)
{
    int dado_branco = JogarDado();
    int dado_vermelho = JogarDado();

    int pontos_branco = dado_branco;
    int pontos_vermelho = CalcularPontosDadoVermelho(dado_vermelho);
    int pontos_total = pontos_branco + pontos_vermelho;

    Limpar();

    MostrarCabecalhoTurno(jogador, rodada, jogador1_pontos, jogador2_pontos);
    printf("O jogador %d pontuou %d pontos! \n\n", jogador, pontos_total);
    MostrarDadoBranco(dado_branco, pontos_branco);
    MostrarDadoVermelho(dado_vermelho, pontos_vermelho);

    EsperarPorEntrada();

    return pontos_total;
}

int JogarTurno(char jogada, int jogador, int rodada, int jogador1_pontos, int jogador2_pontos)
{
    if (jogada == JOGADA_JOGAR_DADOS)
    {
        return JogarDados(jogador, rodada, jogador1_pontos, jogador2_pontos);
    }
    else
    {
        return 0;
    }
}

int TurnoJogador(int jogador, int rodada, int jogador1_pontos, int jogador2_pontos)
{
    Limpar();
    MostrarCabecalhoTurno(jogador, rodada, jogador1_pontos, jogador2_pontos);

    return JogarTurno(PerguntarJogada(), jogador, rodada, jogador1_pontos, jogador2_pontos);
}

/*
O computador escolhe passar a vez se estiver com 15 pontos ou
mais ou se o adversario estiver perdido (com mais de 21 pontos).
Nas possibilidades, o computador joga os dados.
*/
int TurnoComputador(int jogador, int rodada, int jogador1_pontos, int jogador2_pontos)
{
    Limpar();
    MostrarCabecalhoTurno(jogador, rodada, jogador1_pontos, jogador2_pontos);

    char jogada;

    if (jogador2_pontos >= 15 || jogador1_pontos >= 21)
    {
        printf("O computador decidiu pular a vez!\n");
        jogada = JOGADA_PASSAR_VEZ;
    }
    else
    {
        printf("O computador decidiu apostar e jogar os dados!\n");
        jogada = JOGADA_JOGAR_DADOS;   
    }

    EsperarPorEntrada();

    return JogarTurno(jogada, jogador, rodada, jogador1_pontos, jogador2_pontos);
}

int VerificarResultado(int jogador1_pontos, int jogador2_pontos)
{
    if (jogador1_pontos >= 21 && jogador2_pontos >= 21 || jogador1_pontos == jogador2_pontos)
    {
        return EMPATE;
    }
    else if (jogador2_pontos >= 21)
    {
        return JOGADOR_1;
    }
    else if (jogador1_pontos >= 21)
    {
        return JOGADOR_2;
    }
    else if (jogador1_pontos > jogador2_pontos)
    {
        return JOGADOR_1;
    }
    else
    {
        return JOGADOR_2;
    }
}

void VermelhoEBranco(char modo)
{
    srand(time(NULL));

    int jogador1_pontos = 0;
    int jogador2_pontos = 0;

    for (int rodada = 1; rodada <= 3; rodada++)
    {
        jogador1_pontos += TurnoJogador(JOGADOR_1, rodada, jogador1_pontos, jogador2_pontos);

        if (modo == MODO_VS_PLAYER)
        {
            jogador2_pontos += TurnoJogador(JOGADOR_2, rodada, jogador1_pontos, jogador2_pontos);
        }
        else
        {
            jogador2_pontos += TurnoComputador(JOGADOR_2, rodada, jogador1_pontos, jogador2_pontos);
        }
    }

    Limpar();
    MostrarTitulo();
    MostrarPontos(jogador1_pontos, jogador2_pontos);

    int resultado = VerificarResultado(jogador1_pontos, jogador2_pontos);

    MostrarResultado(resultado);
}

int main()
{
    MostrarTitulo();

    char modo = PerguntarModo();

    if (modo == MODO_VS_COMPUTADOR)
    {
        printf("O computador jogara como o Jogador 2.\n");
    }

    do {
        VermelhoEBranco(modo);
    } while (PerguntarJogarNovamente());

    return 0;
}