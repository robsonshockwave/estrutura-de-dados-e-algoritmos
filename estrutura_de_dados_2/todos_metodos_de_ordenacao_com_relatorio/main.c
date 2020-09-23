#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

void relatorio(double tempo, int movimento, int comparacao);
int menu();

//--------------------------------------------------------------------------------------------------------------------
int main(){
    int n, *v, opcao, movimento = 0, comparacao = 0;
    double tempo;

    clock_t inicio, fim;
//--------------------------------------------------------------------------------------------------------------------
    printf("==================================================\n");
    printf("||DIGITE 10000 PARA GERAR 10MIL NUMEROS NO VETOR||\n");
    printf("==================================================\n\n Digite aqui ->  ");
    scanf("%d", &n);
//--------------------------------------------------------------------------------------------------------------------
    //Aparece o Menu
    opcao = menu();
    
    while(opcao > 7 || opcao <= 0){
        opcao = menu();
    }
    if (opcao == 7){
        return 0;
    }

    /*
    do{
        opcao = menu();
    }while(n!=7);
    */
//--------------------------------------------------------------------------------------------------------------------
    //cria o vetor para gerar os números aleatórios
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL){
        printf("SEM MEMORIA :(\n");
        return 0;
    }else{
        printf("\n\n...ORDENANDO NUMEROS!!!...");
    }
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand() % 10000;
    }
//--------------------------------------------------------------------------------------------------------------------
    entrada(n, v);

    //chama a verificação de tempo
    inicio = clock();
    metodos(opcao, v, n, &comparacao, &movimento);
    fim = clock();
    tempo = (double)(fim - inicio)*1000 / CLOCKS_PER_SEC;
//--------------------------------------------------------------------------------------------------------------------
    if(opcao != 6){
        relatorio(tempo, movimento, comparacao);
    }
    saida(n, v);
    estatistica(opcao, v, n, tempo, movimento, comparacao);
    free(v);
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------
int menu(){
    int opcao;
    printf("==========================================================================\n");
    printf("||             ESCOLHA UM DOS METODOS DE ORDENACAO ABAIXO:              ||\n");
    printf("||                          1. BUBBLE SORT                              ||\n");
    printf("||                         2. SELECTION SORT                            ||\n");
    printf("||                         3. INSERTION SORT                            ||\n");
    printf("||                          4. MERGE SORT                               ||\n");
    printf("||                          5. QUICK SORT                               ||\n");
    printf("|| VOCE PODE GERAR UM RELATORIO COM AS ESTATISTICAS DE TODOS OS METODOS ||\n");
    printf("||                          6. RELATORIO                                ||\n");
    printf("||                              7. SAIR                                 ||\n");
    printf("==========================================================================\n");
    printf("Digite aqui a opcao desejada ->  ");
    scanf("%d", &opcao);

    return opcao;
}
//--------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------
void relatorio(double tempo, int movimento, int comparacao){
    printf("\n");
    printf("==========================================================================\n");
    printf("                         TEMPO DE EXECUCAO: %lf                           \n", tempo);
    printf("                       COMPARACOES FEITAS NO VETOR: %d                    \n", comparacao);
    printf("                      MOVIMENTACOES FEITAS NO VETOR: %d                   \n", movimento);
    printf("==========================================================================\n");
    printf("\n\n Obg por usar o programa! \n\n");
}
//--------------------------------------------------------------------------------------------------------------------
