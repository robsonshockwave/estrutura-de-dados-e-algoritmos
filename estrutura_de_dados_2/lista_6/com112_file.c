#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "com112_file.h"
#include "com112_sort.h"

//-------------------------------------------------------------------------------------------------------------------------------------------
int* copia_vetor(int *dados, int qtd){ 
  int *aux;                                 
  aux = (int *) malloc(qtd * sizeof(int));
  int i;
  for (i=0; i<qtd; i++){
    aux[i] = dados[i];
  }
  return aux;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
void escreve_dado(int *dados, int qtd, int aux){
  int i;
  FILE *file;

  if (aux == 0){
    file = fopen("com112_entrada.txt", "w");
    fprintf(file, "%d\n", qtd);
    for(i=0; i<qtd; i++){
      fprintf(file, "%d ", dados[i]);
  }
    fclose(file);
    } else if (aux == 1){
    file = fopen("com112_saida.txt", "w");
    fprintf(file, "%d\n", qtd);
    for(i=0; i<qtd; i++){
      fprintf(file, "%d ", dados[i]);
  }
    fclose(file);
    }

  return;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
void escreve_relatorio(int *dados, int qtd, int *mov, int *comp){
  //NO RELATÓRIO O BUBBLE SORT E INSERTION SORT ESTÃO SAINDO COM AS MOVIMENTAÇÕES ERRADAS, CONCERTO EM ANÁLISE!!!  
  FILE *file;
  float tmp;
  int *aux;
//-------------------------------------------------------------------------------------------------------------------------------------------
  aux = copia_vetor(dados, qtd);
  tmp = bubble_sort(aux, qtd, mov, comp);
  file = fopen("com112_relatorio.txt", "w");
  fprintf(file, "\nMetodo Bubble Sort\n");
  fprintf(file, "\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d", tmp, *comp, *mov);
  fprintf(file, "\n\n");
  fclose(file);
  printf("\nMetodo Bubble Sort\n");
  printf("\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d\n\n", tmp, *comp, *mov);
  free(aux);
//-------------------------------------------------------------------------------------------------------------------------------------------
  aux = copia_vetor(dados, qtd);
  tmp = selection_sort(aux, qtd, mov, comp);
  file = fopen("com112_relatorio.txt", "a");
  fprintf(file, "\nMetodo Selection Sort\n");
  fprintf(file, "\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d", tmp, *comp, *mov);
  fprintf(file, "\n\n");
  fclose(file);
  printf("\nMetodo Selection Sort\n");
  printf("\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d\n\n", tmp, *comp, *mov);
  free(aux);
//-------------------------------------------------------------------------------------------------------------------------------------------
  aux = copia_vetor(dados, qtd);
  tmp = insertion_sort(aux, qtd, mov, comp);
  file = fopen("com112_relatorio.txt", "a");
  fprintf(file, "\nMetodo Insertion Sort\n");
  fprintf(file, "\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d", tmp, *comp, *mov);
  fprintf(file, "\n\n");
  fclose(file);
  printf("\nMetodo Insertion Sort\n");
  printf("\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d\n\n", tmp, *comp, *mov);
  free(aux);
//-------------------------------------------------------------------------------------------------------------------------------------------
  aux = copia_vetor(dados, qtd);
  tmp = merge_sort(aux, qtd, 0, qtd-1, mov, comp);
  file = fopen("com112_relatorio.txt", "a");
  fprintf(file, "\nMetodo Merge Sort\n");
  fprintf(file, "\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d", tmp, *comp, *mov);
  fprintf(file, "\n\n");
  fclose(file);
  printf("\nMetodo Merge Sort\n");
  printf("\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d\n\n", tmp, *comp, *mov);
  free(aux);
//-------------------------------------------------------------------------------------------------------------------------------------------
  aux = copia_vetor(dados, qtd);
  tmp = quick_sort(dados, 0, qtd-1, mov, comp);
  file = fopen("com112_relatorio.txt", "a");
  fprintf(file, "\nMetodo Quick Sort\n");
  fprintf(file, "\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d", tmp, *comp, *mov);
  fprintf(file, "\n\n");
  fclose(file);
  printf("\nMetodo Quick Sort\n");
  printf("\t\tTEMPO DE EXECUÇÃO: %f\n\t\tNUMEROS DE COMPARACOES FEITAS: %d\n\t\tNUMEROS DE MOVIMENTAÇÕES FEITAS %d\n\n", tmp, *comp, *mov);
  free(aux);
//-------------------------------------------------------------------------------------------------------------------------------------------
    return;
  }
//-------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------
void le_dado(int aux){ 
  int i;
  int dado;
  FILE *file;
  if (aux == 0){
    file = fopen("com112_entrada.txt", "r");
    while(fscanf(file, "%d", &dado) != EOF)
      printf("%d ", dado);
    fclose(file);
    } else if (aux == 1){
    file = fopen("com112_saida.txt", "r");
    while(fscanf(file, "%d", &dado) != EOF)
      printf("%d ", dado);
    fclose(file);
    }
  return;
}
//-------------------------------------------------------------------------------------------------------------------------------------------