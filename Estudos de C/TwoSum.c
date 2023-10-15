#include <stdio.h>
#include <stdlib.h>

void findTwoSum(int vetor[], int TAMANHO, int soma, int resultado[][2]);
/*
*EXERCICIO: Dado um array de números e um número isolado,
retorne todas as combinações de números no array cuja soma seja igual ao número isolado. */

// Tentativa de utilizar o Big O para a melhor solução possível

// Tentativa de método "bruto"
void findTwoSum (int vetor[], int TAMANHO, int soma, int resultado [][2])
{
    int contador = 0;

    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            if (vetor[i] + vetor[j] == soma) {
                resultado [contador] [0] = vetor [i];
                resultado [contador] [1] = vetor [j];
                contador++;
            }
        }
    }
}

int main()
{
    int vetor[] = {2, 5, 8, 3, -2, 9, 0};
    int soma = 3;
    int TAMANHO = sizeof(vetor) / sizeof(vetor[0]);
    int resultado[100][2];

    findTwoSum(vetor, TAMANHO, soma, resultado);

    for (int i = 0; i<100 && resultado [i][0] != 0; i++){
        printf("[%d, %d]\n", resultado[i][0], resultado[i][1]);
    }
    return 0;
}

