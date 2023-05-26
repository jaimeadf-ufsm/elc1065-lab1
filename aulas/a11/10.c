#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 10

void PrintVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", vector[i]);
    } 
}

void Insert(int *vector, int size, int at, int element)
{
    for (int i = size - 1; i >= at; i--)
    {
        vector[i + 1] = vector[i];
    }

    vector[at] = element;
}

int FindInsertionIndex(int *vector, int current_index, int number)
{
    for (int i = 0; i < current_index; i++)
    {
        if (number > vector[i])
        {
            return i;
        }
    }

    return current_index;
}

int main()
{
    int vector[SIZE];

    printf("Digite %d elementos:\n", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        int number;
        scanf("%d", &number);
        
        int insertion_index = FindInsertionIndex(vector, i, number);
        Insert(vector, SIZE, insertion_index, number);
    }

    printf("\nOrdem descrescente:\n");
    PrintVector(vector, SIZE);

    return 0;
}