#include <stdio.h>
#include <stdbool.h>

int main() {
    const double VALOR_LITORAL = 216.72;
    const double VALOR_CAPITAL = 157.36;
    const double VALOR_SERRA = 182.19;
    const double VALOR_FRONTEIRA = 259.41;
    const double VALOR_INTERESTADUAL = 368.92;

    const double PERCENTUAL_SEGURO = 2.16 / 100.0;
    const double TAXA_EMISSAO_VOLTA = 1.50;

    const double VALOR_POR_PONTO = 120.0;

    const int PONTOS_CEREAL = 2;
    const int PONTOS_AGUA = 5;

    int qtd_passagens;
    int codigo_destino;

    printf("==================== Bem-vindo(a) a Rodoviaria Tux ====================\n");
    printf("Nossos destinos: \n");
    printf("1) Litoral       - R$%.2lf\n", VALOR_LITORAL);
    printf("2) Capital       - R$%.2lf\n", VALOR_CAPITAL);
    printf("3) Serra         - R$%.2lf\n", VALOR_SERRA);
    printf("4) Fronteira     - R$%.2lf\n", VALOR_FRONTEIRA);
    printf("5) Interestadual - R$%.2lf\n", VALOR_INTERESTADUAL);
    printf("\n");
    printf("Nossos combos: \n");
    printf("2 passagens:          9%% de desconto no valor da segunda.\n");
    printf("3 passagens:         11%% de desconto no valor da segunda e 13%% da terceira.\n");
    printf("4 passagens:         15%% de desconto nas tres ultimas passagens.\n");
    printf("5 passagens ou mais: 16%% de desconto no valor base da compra.\n");

    printf("\n");
    printf("Quantas passagens voce deseja comprar? ");
    scanf("%d", &qtd_passagens);

    if (qtd_passagens > 0) {
        printf("Qual o codigo de seu destino? ");
        scanf("%d", &codigo_destino);

        if (codigo_destino >= 0 && codigo_destino <= 5) {
            double valor_passagem;

            switch (codigo_destino) {
                case 1:
                    valor_passagem = VALOR_LITORAL;
                    break;
                case 2:
                    valor_passagem = VALOR_CAPITAL;
                    break;
                case 3:
                    valor_passagem = VALOR_SERRA;
                    break;
                case 4:
                    valor_passagem = VALOR_FRONTEIRA;
                    break;
                case 5:
                    valor_passagem = VALOR_INTERESTADUAL;
                    break;
            }

            char resposta_seguro, resposta_volta;
            double valor_emissao = 0.0, valor_seguro = 0.0, valor_desconto = 0.0;

            printf("Voce deseja incluir o seguro de vida (s/n)? ");
            scanf(" %c", &resposta_seguro);

            printf("Voce deseja comprar tambem passagens de volta (s/n)? ");
            scanf(" %c", &resposta_volta);

            bool incluir_seguro = resposta_seguro == 's' || resposta_seguro == 'S';
            bool incluir_volta = resposta_volta == 's' || resposta_volta == 'S';

            if (incluir_volta) {
                valor_emissao += qtd_passagens * TAXA_EMISSAO_VOLTA;
                qtd_passagens *= 2;
            }

            double valor_compra_base = qtd_passagens * valor_passagem;

            if (incluir_seguro) {
                valor_seguro += qtd_passagens * (valor_passagem * PERCENTUAL_SEGURO);
            }

            if (qtd_passagens == 2) {
                valor_desconto += valor_passagem * (9.0 / 100.0);
            } else if (qtd_passagens == 3) {
                valor_desconto += valor_passagem * (11.0 / 100.0);
                valor_desconto += valor_passagem * (13.0 / 100.0);
            } else if (qtd_passagens == 4) {
                valor_desconto += 3 * valor_passagem * (15.0 / 100.0);
            } else if (qtd_passagens >= 5) {
                valor_desconto += valor_compra_base * (16.0 / 100.0);
            }

            double valor_compra = valor_compra_base - valor_desconto + valor_seguro;
            double valor_compra_com_desconto = valor_compra_base - valor_desconto;
            double valor_compra_com_seguro = valor_compra_base + valor_seguro;

            double valor_compra_final = valor_compra + valor_emissao;
            double diferenca = (valor_compra_final - valor_compra_base) / valor_compra_base;

            int pontos = valor_compra_final / 120;

            printf("\n");
            printf("######################### Relatorio de Compra #########################\n");

            if (incluir_volta) {
                printf("Valor base da compra:               R$%.2lf (%d passagens * 2)\n", valor_compra_base, qtd_passagens / 2);
            } else {
                printf("Valor base da compra:               R$%.2lf (%d passagem(ns))\n", valor_compra_base, qtd_passagens);
            }

            printf("Valor da compra:                    R$%.2lf\n", valor_compra);

            if (valor_desconto > 0) {
                printf("Valor da compra apenas c/ desconto: R$%.2lf\n", valor_compra_com_desconto);
                printf("Valor do desconto do combo:         R$%.2lf\n", valor_desconto);
            }

            if (valor_seguro > 0) {
                printf("Valor da compra apenas c/ seguro:   R$%.2lf\n", valor_compra_com_seguro);
                printf("Valor do seguro:                    R$%.2lf\n", valor_seguro);
            }

            printf("\n");

            if (valor_emissao > 0) {
                printf("Valor final:                        R$%.2lf (%.2lf + emissao)\n", valor_compra_final, valor_compra);
            } else {
                printf("Valor final:                        R$%.2lf\n", valor_compra_final);
            }

            printf("Pontuacao:                          %d ponto(s)\n", pontos);

            if (diferenca > 0) {
                printf("-> Voce gastou %.2lf%% a mais que o valor base.\n", diferenca * 100);
            } else if (diferenca < 0) {
                printf("-> Voce gastou %.2lf%% a menos que o valor base.\n", -diferenca * 100);
            } else {
                printf("-> Voce gastou o mesmo que o valor base.\n");
            }

            int qtd_cereal = 0, qtd_agua = 0;
            int pontos_restantes = pontos;

            if (pontos_restantes >= PONTOS_CEREAL) {
                printf("\n");
                printf("Voce pode trocar nossos pontos por: \n");
                printf("a) Barra de cereal (2 pontos)\n");
                printf("b) Garrafa de agua (5 pontos)\n");

                int max_cereal = pontos_restantes / PONTOS_CEREAL;

                printf("\nQuantas barras de cereal voce deseja (maximo %d): ", max_cereal);
                scanf("%d", &qtd_cereal);
            }

            if (qtd_cereal >= 0) {
                pontos_restantes -= qtd_cereal * PONTOS_CEREAL;

                if (pontos_restantes >= 0) {
                    if (pontos_restantes >= PONTOS_AGUA) {
                        int max_agua = pontos_restantes / PONTOS_AGUA;

                        printf("Quantas garrafas de agua voce deseja (maximo %d): ", max_agua);
                        scanf("%d", &qtd_agua);
                    }

                    if (qtd_agua >= 0) {
                        pontos_restantes -= qtd_agua * PONTOS_AGUA;

                        if (pontos_restantes >= 0) {
                            if (qtd_cereal > 0 || qtd_agua > 0) {
                                printf("\n");
                                printf("################################ Bonus ################################\n");

                                if (qtd_cereal > 0) {
                                    printf("a) %d barra(s) de cereal\n", qtd_cereal);
                                }

                                if (qtd_agua > 0) {
                                    printf("b) %d garrafa(s) de agua\n", qtd_agua);
                                }

                                if (pontos_restantes > 0) {
                                    printf("OBS: Voce ainda possui %d ponto(s) para gastar em compras futuras.\n", pontos_restantes);
                                }
                            }

                            printf("\n");
                            printf("Obrigado por comprar conosco. Nos, da Rodoviaria Tux, te desejamos uma otima viagem.\n");
                        } else {
                            printf("ERRO: Voce nao possui pontos suficiente para trocar por %d garrafas de agua.\n", qtd_agua);
                        }
                    } else {
                        printf("ERRO: A quantidade de garrafas de agua precisa maior ou igual a 0.\n");
                    }
                } else {
                    printf("ERRO: Voce nao possui pontos suficiente para trocar por %d barras de cereal.\n", qtd_cereal);
                }
            } else {
                printf("ERRO: A quantidade de barras de cereais precisa maior ou igual a 0.\n");
            }
        } else {
            printf("ERRO: Infelizmente, o codigo digitado nao faz parte da nossa lista de destinos.\n");
        }
    } else {
        printf("ERRO: Voce precisa comprar pelo menos 1 passagem.\n");
    }

    return 0;
}
