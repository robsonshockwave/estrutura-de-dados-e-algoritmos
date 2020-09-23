// Exercício 1
// Escreva um algoritmo (utilize a linguagem C) que resolva o problema da busca sequencial
// de um valor chave inteiro em um vetor V de tamanho n, sem repetição de valores.
// E devolva a quantidade de números comparados até encontrar o valor chave.

#include <stdio.h>
// Vector Size
#define vectorSize 5

// Protótipos de função
int readVector(int vet[]);
int printVector(int vet[]);
int linearSearch(int v[], int n,int value);

int main()
{
    // Definindo o Vetor
    int vector[vectorSize];
    // Definindo o índice a ser retornado e o valor de pesquisa
    int index, searchValue;

    printf("\nPrograma de Busca Sequencial\n\n");

    // Leitura do Vetor
    readVector(vector);

    // Leitura do valor a ser pesquisado
    printf("\nDigite um valor para pesquisar: ");
    scanf("%d", &searchValue);

    // Imprime o vetor lido
    printVector(vector);

    // Chamada da pesquisa sequencial
    index = linearSearch(vector, vectorSize, searchValue);
    
    // Imprime o número de comparações executadas para encontrar o valor procurado no vetor
    printf("\n\n --Número de comparações = %d", index);

    // Tratamento do retorno da Pesquisa Sequencial
    if (index == vectorSize)    
        printf("\n\n --Valor nao encontrado no vetor!");    
    else    
        printf("\n\n --Valor %d encontrado em Vetor[%d]", searchValue, index);
    
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
    printf("Vetor na memoria:\n");
    for (int i = 0; i < vectorSize; i++)
        printf("[%d] = %d \n", (i + 1), vet[i]);
    return 0;
}

// Função de Busca Sequencial
// Recebe um vetor e um valor de pesquisa como parâmetros
int linearSearch(int v[], int n, int value)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        if (v[i] == value)
        {
            // Quando a chave é encontrada, houve (i+1) comparações (posição da chave no vetor acrescida de um)
            // No MELHOR CASO a chave estará na primeira posição do vetor (1 comparação) => T(n) = 1
            return i+1;  
        }
    }
    
    // Quando a chave NÃO é encontrada, houve i comparações (total de elementos do vetor)
    // No PIOR CASO a chave não existe ou é o último elemento do vetor (n comparações) => T(n) = n
    return i; 
}

