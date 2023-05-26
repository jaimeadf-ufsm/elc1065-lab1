#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 10

void ReadVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &vector[i]);
    }
}

void PrintVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", vector[i]);
    } 
}

bool Contains(int *vector, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (vector[i] == element)
        {
            return true;
        }
    }

    return false;
}

int Union(int *vector_x, int *vector_y, int *vector_z, int size)
{
    for (int i = 0; i < size; i++)
    {
        vector_z[i] = vector_x[i];
        vector_z[size + i] = vector_y[i];
    }

    return size * 2;
}

int Difference(int *vector_x, int *vector_y, int *vector_z, int size)
{
    int n_z = 0;

    for (int i = 0; i < size; i++)
    {
        if (!Contains(vector_y, size, vector_x[i]))
        {
            vector_z[n_z++] = vector_x[i];
        }
    }

    return n_z;
}

int Sum(int *vector_x, int *vector_y, int *vector_z, int size)
{
    for (int i = 0; i < size; i++)
    {
        vector_z[i] = vector_x[i] + vector_y[i];
    }

    return size;
}

int Product(int *vector_x, int *vector_y, int *vector_z, int size)
{
    for (int i = 0; i < size; i++)
    {
        vector_z[i] = vector_x[i] * vector_y[i];
    }

    return size;
}

int Intersection(int *vector_x, int *vector_y, int *vector_z, int size)
{
    int n_z = 0;

    for (int i = 0; i < size; i++)
    {
        if (Contains(vector_y, size, vector_x[i]))
        {
            vector_z[n_z++] = vector_x[i];
        }
    }

    return n_z;
}

int main()
{
    int vector_x[SIZE] = { 10, 5, 20, 30, 50, 11, 13, 21, 34, 42 };
    int vector_y[SIZE] = { 0, 10, 34, 60, 11, 20, 45, 42, 80, 10 };

    int vector_z[2 * SIZE];
    int n_z = 0;

    printf("Digite %d numeros para o vetor X:\n", SIZE);
    ReadVector(vector_x, SIZE);

    printf("Digite %d numeros para o vetor Y:\n", SIZE);
    ReadVector(vector_y, SIZE);

    printf("\nVetor X:\n");
    PrintVector(vector_x, SIZE);

    printf("\nVetor Y:\n");
    PrintVector(vector_y, SIZE);

    printf("\nMenu:\n");
    printf("a) união: Z é a união de X com Y\n");
    printf("b) diferença: Z é a diferença entre X e Y\n");
    printf("c) soma: Z é a soma de X com Y\n");
    printf("d) produto: Z é o produto entre X e Y\n");
    printf("e) intersecção: Z é a intersecção entre X e Y\n");
    
    printf("\nO que voce deseja fazer?");

    char option;
    scanf("%c", &option);

    switch (option)
    {
        case 'a':
            n_z = Union(vector_x, vector_y, vector_z, SIZE);   
            break;
        case 'b':
            n_z = Difference(vector_x, vector_y, vector_z, SIZE);   
            break;
        case 'c':
            n_z = Sum(vector_x, vector_y, vector_z, SIZE);   
            break;
        case 'd':
            n_z = Product(vector_x, vector_y, vector_z, SIZE);   
            break;
        case 'e':
            n_z = Intersection(vector_x, vector_y, vector_z, SIZE);   
            break;
    }

    printf("\nVetor Z: \n");
    PrintVector(vector_z, n_z);

    return 0;
}