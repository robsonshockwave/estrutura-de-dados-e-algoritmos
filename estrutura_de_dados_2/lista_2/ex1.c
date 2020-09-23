// Exercício 1
// Faça um programa que armazene em um vetor V um conjunto de 10 números inteiros.
// Utilize o algoritmo de ordenação Bubble Sort para ordenar um conjunto de números
// em ordem decrescente

#include <stdio.h>
// Vector Size
#define vectorSize 10

// Protótipos de função
int readVector(int vet[]);
int printVector(int vet[]);
int bubbleSort(int vet[]);

int main()
{
    // Definindo o Vetor
    int vector[vectorSize];  // Código para leitura de vetor  
    //int vector[] = { 9,33,65,45,79,99,103,22,19,20};  // Código para vetor com valores atribuídos 

    // Definindo o índice a ser retornado e o valor de pesquisa
    int index, searchValue;

    printf("\nPrograma de Ordenacao com Bubble Sort\n\n");

    // Leitura do Vetor
    // Comente a linha abaixo caso o vetor já tenha os valores atribuidos
    readVector(vector);

    // Imprime o vetor antes
    printf("-- Vetor antes da ordenacao:\n");
    printVector(vector);

    bubbleSort(vector);

    // Imprime o vetor após
    printf("-- Vetor apos a ordenacao:\n");
    printVector(vector);

    printf("\n");
    return 0;
}

// Função para leitura do Vetor
// Recebe um vetor como parâmetro
int readVector(int vet[])
{
    printf("Leitura do vetor:\n");
    for (int i = 0; i < vectorSize; i++)
    {
        printf("Vetor[%d] = ", i + 1);
        scanf("%d", &vet[i]);
    }
    return 0;
}

// Função para impressão do Vetor
// Recebe um vetor como parâmetro
int printVector(int vet[])
{
    for (int i = 0; i < vectorSize; i++)
        printf("[%d] = %d \n", (i + 1), vet[i]);
    return 0;
}

// Função Buuble Sort
// Recebe um vetor como parâmetro
int bubbleSort(int vet[])
{
    int varAuxiliar;

    for (int k = vectorSize - 1; k > 0; k--)
    {
        for (int j = 0; j < k; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                varAuxiliar = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = varAuxiliar;
            }
        }
    }
    return 0;
}
