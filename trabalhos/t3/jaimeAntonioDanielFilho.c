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

void ImprimirJogador(char modo, int jogador)
{
    if (jogador == JOGADOR_1)
    {
        printf("JOGADOR  1");
    }
    else
    {
        printf(modo == MODO_VS_COMPUTADOR ? "COMPUTADOR" : "JOGADOR  2");
    }
}

void MostrarTitulo()
{
    printf("==================== A Guerra dos Dados ====================\n");
}

void MostrarPontos(char modo, int jogador1_pontos, int jogador2_pontos)
{
    ImprimirJogador(modo, JOGADOR_1);
    printf(": %d pontos\n", jogador1_pontos);
    ImprimirJogador(modo, JOGADOR_2);
    printf(": %d pontos\n", jogador2_pontos);
}

void MostrarCabecalhoTurno(char modo, int jogador, int rodada, int jogador1_pontos, int jogador2_pontos)
{
    MostrarTitulo();

    printf("Vez do ");
    ImprimirJogador(modo, jogador);
    printf("                                  Rodada %2d\n", rodada);

    MostrarPontos(modo, jogador1_pontos, jogador2_pontos);
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

    printf("+-------+\n\n");
}

void MostrarResultado(char modo, int resultado)
{
    printf("\n");

    switch (resultado)
    {
        case EMPATE:
            printf("Empate!\n");
            break;
        case JOGADOR_1:
        case JOGADOR_2:
            ImprimirJogador(modo, resultado);
            printf(" GANHOU!\n");
            break;
    }

    printf("\n");
}

void LimparTurno(char modo, int jogador, int rodada, int jogador1_pontos, int jogador2_pontos)
{
    Limpar();
    MostrarCabecalhoTurno(modo, jogador, rodada, jogador1_pontos, jogador2_pontos);
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

bool PerguntarJogarNovamente()
{
    printf("Voce deseja jogar uma nova partida (s/n)? ");
    char resposta = LerCaractere();

    return resposta == 's' || resposta == 'S';
}

void EsperarPorEntrada()
{
    char nova_linha;

    printf("\nAperte ENTER para continuar...");

    do {
        scanf("%c", &nova_linha);
    } while (nova_linha != '\n');
}

int JogarDados(char modo, int jogador)
{
    int dado_branco = JogarDado();
    int dado_vermelho = JogarDado();

    int pontos_branco = dado_branco;
    int pontos_vermelho = CalcularPontosDadoVermelho(dado_vermelho);
    int pontos_total = pontos_branco + pontos_vermelho;

    ImprimirJogador(modo, jogador);
    printf(" pontuou %d pontos! \n\n", pontos_total);

    printf("Branco) %d pontos\n", pontos_branco);
    MostrarDado(dado_branco);

    printf("Vermelho) %d pontos\n", pontos_vermelho);
    MostrarDado(dado_vermelho);

    EsperarPorEntrada();

    return pontos_total;
}

char TurnoJogador()
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

/*
O computador escolhe jogar os dados se possuir menos que 15
pontos ou se estiver perdendo do seu adversario. Nas outras
possibilidades, ele escolhe passar a vez.
*/
char TurnoComputador(int pontos_adversario, int pontos_computador)
{
    if ((pontos_computador <= 15 || pontos_computador < pontos_adversario) && pontos_adversario <= 21)
    {
        printf("O COMPUTADOR decidiu apostar e jogar os dados!\n");
        return JOGADA_JOGAR_DADOS;
    }
    else
    {
        printf("O COMPUTADOR decidiu pular a vez!\n");
        return JOGADA_PASSAR_VEZ;
    }
}

int FazerJogada(char modo, int jogador, char jogada)
{
    if (jogada == JOGADA_JOGAR_DADOS)
    {
        return JogarDados(modo, jogador);
    }
    else
    {
        return 0;
    }
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
        char jogada_jogador1;
        char jogada_jogador2;

        LimparTurno(modo, JOGADOR_1, rodada, jogador1_pontos, jogador2_pontos);
        jogada_jogador1 = TurnoJogador();


        LimparTurno(modo, JOGADOR_1, rodada, jogador1_pontos, jogador2_pontos);
        jogador1_pontos += FazerJogada(modo, JOGADOR_1, jogada_jogador1);

        LimparTurno(modo, JOGADOR_2, rodada, jogador1_pontos, jogador2_pontos);

        if (modo == MODO_VS_PLAYER)
        {
            jogada_jogador2 = TurnoJogador();
        }
        else
        {
            jogada_jogador2 = TurnoComputador(jogador1_pontos, jogador2_pontos);
            EsperarPorEntrada();
        }

        LimparTurno(modo, JOGADOR_2, rodada, jogador1_pontos, jogador2_pontos);
        jogador2_pontos += FazerJogada(modo, JOGADOR_2, jogada_jogador2);
    }

    int resultado = VerificarResultado(jogador1_pontos, jogador2_pontos);

    Limpar();
    MostrarTitulo();
    MostrarPontos(modo, jogador1_pontos, jogador2_pontos);

    MostrarResultado(modo, resultado);
}

int main()
{
    MostrarTitulo();

    char modo = PerguntarModo();

    do {
        VermelhoEBranco(modo);
    } while (PerguntarJogarNovamente());

    return 0;
}
