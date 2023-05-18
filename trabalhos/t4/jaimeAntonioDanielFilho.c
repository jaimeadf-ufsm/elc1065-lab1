#include <stdio.h>

#define TAM_NOTAS 100

int LerQuantidadeDeNotas()
{
    int n;

    do {
        printf("Quantas notas voce quer digitar (1 ate %d)? ", TAM_NOTAS);
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    return n;
}

void LerNotas(double *notas, int n)
{
    printf("Digite a(s) %d nota(s) separada(s) por espaços: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &notas[i]);
    }

    printf("\n");
}

void AnalisarFrequencias(double *notas, int *frequencias, int n)
{
    for (int i = 0; i < n; i++)
    {
        frequencias[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (frequencias[i] == -1)
        {
            frequencias[i] = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (notas[i] == notas[j])
                {
                    frequencias[i]++;
                    frequencias[j] = 0;
                }
            }
        }
    }
}

int main()
{
    double notas[TAM_NOTAS];
    int frequencias[TAM_NOTAS];

    printf("============== Sistema do INEP ==============\n");

    int n = LerQuantidadeDeNotas();

    LerNotas(notas, n);
    AnalisarFrequencias(notas, frequencias, n);

    double nota_mais_frequente = notas[0];
    int frequencia_maxima = frequencias[0];

    for (int i = 0; i < n; i++)
    {
        double nota = notas[i];
        int frequencia = frequencias[i];

        if (frequencia > 0)
        {
            printf("%.1lf ocorre %d vez(es)\n", nota, frequencia);

            if (frequencia > frequencia_maxima || frequencia == frequencia_maxima && nota > nota_mais_frequente)
            {
                nota_mais_frequente = nota;
                frequencia_maxima = frequencia;
            }
        }
    }

    printf("\n%.1lf foi a nota mais frequente\n", nota_mais_frequente);

    return 0;
}