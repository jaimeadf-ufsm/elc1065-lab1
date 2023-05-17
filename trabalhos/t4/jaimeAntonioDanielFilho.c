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

int BuscarNota(double *notas, int n, double nota)
{
    for (int i = 0; i < n; i++)
    {
        if (notas[i] == nota)
        {
            return i;
        }
    }

    return -1;
}

int AnalisarFrequencias(double *notas, double *repetidas, int *frequencias, int n)
{
    int n_repetidas = 0;

    for (int i = 0; i < n; i++)
    {
        double nota = notas[i];
        int i_repetida = BuscarNota(repetidas, n_repetidas, nota);

        if (i_repetida == -1)
        {
            i_repetida = n_repetidas++;

            repetidas[i_repetida] = nota;
            frequencias[i_repetida] = 0;
        }

        frequencias[i_repetida]++;
    }

    return n_repetidas;
}

int main()
{
    double notas[TAM_NOTAS];

    double repetidas[TAM_NOTAS];
    int frequencias[TAM_NOTAS];

    printf("============== Sistema do INEP ==============\n");

    int n = LerQuantidadeDeNotas();

    LerNotas(notas, n);

    int n_repetidas = AnalisarFrequencias(notas, repetidas, frequencias, n);

    double nota_mais_frequente = repetidas[0];
    int maior_frequencia = frequencias[0];

    for (int i = 0; i < n_repetidas; i++)
    {
        double nota = repetidas[i];
        int frequencia = frequencias[i];

        printf("%.1lf ocorre %d vez(es)\n", nota, frequencia);

        if (frequencia > maior_frequencia || frequencia == maior_frequencia && nota > nota_mais_frequente)
        {
            nota_mais_frequente = nota;
            maior_frequencia = frequencia;
        }
    }

    printf("\n%.1lf foi a nota mais frequente\n", nota_mais_frequente);

    return 0;
}