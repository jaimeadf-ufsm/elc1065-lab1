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
        printf("Jogador  1");
    }
    else
    {
        printf(modo == MODO_VS_COMPUTADOR ? "Computador" : "Jogador  2");
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

int JogarDados(char modo, int jogador, int pontos)
{
    int dado_branco = JogarDado();
    int dado_vermelho = JogarDado();

    int pontos_branco = dado_branco;
    int pontos_vermelho = CalcularPontosDadoVermelho(dado_vermelho);
    int pontos_obtidos = pontos_branco + pontos_vermelho;

    ImprimirJogador(modo, jogador);
    printf(" pontuou %d pontos! \n\n", pontos_obtidos);

    printf("Branco) +%d pontos => %d pontos\n", pontos_branco, pontos + pontos_branco);
    MostrarDado(dado_branco);

    printf(
        "Vermelho) +%d pontos => %d pontos\n",
        pontos_vermelho,
        pontos + pontos_branco + pontos_vermelho
    );
    MostrarDado(dado_vermelho);

    EsperarPorEntrada();

    return pontos_obtidos;
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
O computador escolhe jogar os dados se, quando seu adversário ainda não estiver perdido
(ou seja, com menos ou igual a 21 pontos), possuir menos pontos que o adversário ou possuir
menos que 15 pontos. Nas outras possibilidades, ele escolhe passar a vez por considerar mais
seguro.
*/
char TurnoComputador(int pontos_adversario, int pontos_computador)
{
    if (pontos_adversario <= 21)
    {
        if (pontos_computador <= pontos_adversario)
        {
            printf("O Computador decidiu jogar os dados por estar perdendo.\n");
            return JOGADA_JOGAR_DADOS;

        }
        else if (pontos_computador <= 15)
        {
            printf("O Computador decidiu jogar os dados por estar com poucos\npontos.\n");
            return JOGADA_JOGAR_DADOS;
        }
        else
        {
            if (pontos_computador == 21)
            {
                printf("O Computador decidiu passar a vez por estar ganho.\n");
            }
            else
            {
                printf("O Computador decidiu passar a vez por nao considerar seguro\narriscar a sorte.\n");
            }

            return JOGADA_PASSAR_VEZ;
        }
    }
    else
    {
        printf("O Computador decidiu passar a vez por que seu adversario\nesta perdido.\n");
        return JOGADA_PASSAR_VEZ;
    }
}

int FazerJogada(char modo, int jogador, char jogada, int pontos)
{
    if (jogada == JOGADA_JOGAR_DADOS)
    {
        return JogarDados(modo, jogador, pontos);
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
        jogador1_pontos += FazerJogada(modo, JOGADOR_1, jogada_jogador1, jogador1_pontos);

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
        jogador2_pontos += FazerJogada(modo, JOGADOR_2, jogada_jogador2, jogador2_pontos);
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
