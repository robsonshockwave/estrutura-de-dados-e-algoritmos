#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

int menu(int *dados, int qtd, int *mov, int *comp);
void relatorio(int mov, int comp, double tmp);

//-------------------------------------------------------------------------------------------------------------------------------------------
int main(){
  int *dados, mov, comp, qtd , i;
  double tmp;
  printf("\nQUANTOS NÚMEROS DESEJA ORDENAR?\n");
  scanf("%d", &qtd);
  dados = (int *) malloc(qtd * sizeof(int));

  printf("\n\nOS NÚMEROS GERADOS FORAM:\n", qtd);
  for(i=0; i<qtd; i++){
    dados[i] = rand() % 10000;
    printf("%d", dados[i]);
    printf("\n");
  }

  escreve_dado(dados, qtd, 0);    
  menu(dados, qtd, &mov, &comp); 
  return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
int menu(int *dados, int qtd, int *mov, int *comp){ 
  int aux;
  double tmp;

  do
  {
    printf("\n\nMÉTODOS DE ORDENAÇÃO DISPONÍVEIS, SELECIONE ALGUM:\n");
    printf("\n1) Bubble Sort");
    printf("\n2) Selection Sort");
    printf("\n3) Insertion Sort");
    printf("\n4) Merge Sort");
    printf("\n5) Quick Sort");
    printf("\n6) Tirar o Relatorio");
    printf("\n7) Sair\n\n");
    scanf("%d", &aux);

    switch(aux){
      case 1:
        printf("\n\nORDENANDO POR BUBBLE SORT");
        tmp = bubble_sort(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 2:
        printf("\n\nORDENANDO POR SELECTION SORT");
        tmp = selection_sort(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1); 
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 3:
        printf("\n\nORDENANDO POR INSERTION SORT"); //SEMPRE TESTE ESSE PRIMEIRO PARA SAIR O RESULTADO CERTO
        tmp = insertion_sort(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 4:
        printf("\n\nORDENANDO POR MERGE SORT");
        *mov = 0; *comp = 0;
        tmp = merge_sort(dados, qtd, 0, qtd-1, mov, comp);
        escreve_dado(dados, qtd, 1);
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 5:
        printf("\n\nORDENANDO POR QUICK SORT");
        *mov = 0; *comp = 0;
        tmp = quick_sort(dados, 0, qtd-1, mov, comp);
        escreve_dado(dados, qtd, 1);
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 6:
        printf("\n\nGERANDO RELATÓRIO\n");
        escreve_relatorio(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);
        printf("\nSUCESSO AO GERAR ^^\n");
      break;

      case 7:
        printf("\nFINALIZANDO O PROGRAMA :'(");
      exit(0);
    }
  }while(aux!=7);
  return 1;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
void relatorio(int mov, int comp, double tmp){  
  printf("\nRELATÓRIO\n");
  printf("\nTEMPO DE EXECUÇÃO: %f", tmp);
  printf("\nNÚMERO DE COMPARAÇÕES FEITAS DENTRO DO VETOR: %d", comp);
  printf("\nNÚMERO DE MOVIMENTAÇÕES FEITAS DENTRO DO VETOR: %d", mov);
  return;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
