#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    const int start_x = 0, start_y = 0;
    const int end_x = 432, end_y = 468;

    int ball_x, ball_y;

    printf("Digite a coordenada X e Y do ponto em que a bola entrou em contato com o solo: ");
    scanf("%d %d", &ball_x, &ball_y);

    if (ball_x >= start_x && ball_x <= end_x && ball_y >= start_y && ball_y <= end_y)
    {
        printf("A bola bateu no solo DENTRO da semi-quadra.\n");
    }
    else
    {
        printf("A bola bateu no solo FORA da semi-quadra.\n");
    }

    return 0;
}