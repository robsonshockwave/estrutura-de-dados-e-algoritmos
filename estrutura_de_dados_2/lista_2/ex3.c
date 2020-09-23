// Exercício 2
// Faça um programa que cadastre o nome e o salário de 10 funcionários. Use o algoritmo
// de ordenação Selection Sort para listar todos os dados dos funcionários das seguintes
// formas:
// (a) em ordem decrescente de salário.
// (b) em ordem alfabética.

#include <stdio.h>
#include <string.h>

// Vector Size
#define vectorSize 10
#define stringSize 50

// Estrutura para os dados
typedef struct produto{
    char codigo [stringSize];
    char descricao [stringSize];
    float preco;        
}DadosProduto;


// Protótipos de função
int readVector(DadosProduto vet[]);
int printVector(DadosProduto vet[]);
int dummyData(DadosProduto vector[]);
void insertionSort(DadosProduto arr[]);
int linearSearch(DadosProduto v[], int n, char value[]);

int main()
{
    // Definindo o Vetor
    DadosProduto vector[vectorSize];  // Código para leitura de vetor  
    char searchValue[stringSize];
    int compare;


    printf("\nPrograma de Ordenacao com SelectionSort\n\n");

    // Leitura do Vetor
    //readVector(vector);
    // Populando o vetor sem necessidade de interação com usuario
    dummyData(vector);
    

    // Imprime o vetor antes
    printf("\n--- Vetor antes da ordenacao:\n\n");
    printVector(vector);

    insertionSort(vector);

    // Imprime o vetor após
    printf("\n--- Vetor apos a ordenacao:\n\n");
    printVector(vector);

    printf("\n");

    // Leitura do valor a ser pesquisado
    printf("\nDigite um valor para pesquisar: ");
    scanf("%s", &searchValue);
    compare = linearSearch(vector, vectorSize, searchValue);

    printf("\n\n --Número de comparações = %d", compare);
    return 0;
}

// Dummy Data
int dummyData(DadosProduto vector[]){
    
    strcpy(vector[0].descricao,"Microdone do R. J. Dio");
    strcpy(vector[0].codigo,"C001");
    vector[0].preco = 2000;

    strcpy(vector[1].descricao,"Paleta do Jeff Hanneman");
    strcpy(vector[1].codigo,"C003");
    vector[1].preco = 20000;

    strcpy(vector[2].descricao,"Regata do Dimebag Darrel");
    strcpy(vector[2].codigo,"C021");
    vector[2].preco = 1000;

    strcpy(vector[3].descricao,"Contrabaixo do Tom Araya");
    strcpy(vector[3].codigo,"F012");
    vector[3].preco = 592;
    
    strcpy(vector[4].descricao,"Bermuda do Phil Anselmo");
    strcpy(vector[4].codigo,"F1233");
    vector[4].preco = 3698;
    
    strcpy(vector[5].descricao,"Cachecol do Ritchie Blackmore");
    strcpy(vector[5].codigo,"C11");
    vector[5].preco = 68423;

    strcpy(vector[6].descricao,"Lembranca do Chuck Schuldiner");
    strcpy(vector[6].codigo,"LCC19");
    vector[6].preco = 1255;

    strcpy(vector[7].descricao,"Camiseta do Gary Holt");
    strcpy(vector[7].codigo,"YCC019");
    vector[7].preco = 5264;

    strcpy(vector[8].descricao,"Corrente do Kerry King ");
    strcpy(vector[8].codigo,"DCC19");
    vector[8].preco = 78944;

    strcpy(vector[9].descricao,"Oculos da Nina Hagen");
    strcpy(vector[9].codigo,"LC4C19");
    vector[9].preco = 36885;


}

// Função para leitura do Vetor
// Recebe um vetor como parâmetro
int readVector(DadosProduto vet[])
{
    printf("Leitura do vetor:\n");
    for (int i = 0; i < vectorSize; i++)
    {
        printf("Codigo do produto[%d] = ", i + 1);
        scanf("%s", &vet[i].codigo);
        printf("Descricao do produto[%d] = ", i + 1);
        scanf("%f", &vet[i].descricao);
        printf("Preco do produto[%d] = ", i + 1);
        scanf("%f", &vet[i].preco);
    }
    return 0;
}

// Função para impressão do Vetor
// Recebe um vetor como parâmetro
int printVector(DadosProduto vet[])
{
    for (int i = 0; i < vectorSize; i++)
        printf("Produto[%d]\n - Codigo %s\n - Descricao: %s\n - Preco: %2.f\n", (i + 1), vet[i].codigo, vet[i].descricao, vet[i].preco);
    return 0;
}

// Função Insertion Sort
// Recebe um vetor como parâmetro
void insertionSort(DadosProduto arr[]) 
{ 
    int j, count; 
    DadosProduto varAux, key;
    for (int i = 1; i < vectorSize; i++) { 
        key = arr[i]; 
        j = i - 1;           
        while (j >= 0 && arr[j].preco > key.preco) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

// Função de Busca Sequencial
// Recebe um vetor e um valor de pesquisa como parâmetros
int linearSearch(DadosProduto v[], int n, char value[])
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        if (strcmp(v[i].codigo, value) == 0)
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



