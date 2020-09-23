#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"

//-------------------------------------------------------------------------------------------------------------------------------------------
double bubble_sort(int *dados, int qtd, int *mov, int *comp){
	clock_t start = clock();
  int i, j, aux;
  *mov = 0; *comp = 0;
	for (i=0; i<qtd; i++){
  j = 0;
		for (j=0;j<qtd-1;j++){
      (*comp)++;
			if (dados[j] > dados[j+1]){
				aux = dados[j];
				dados[j] = dados[j+1];
				dados[j+1] = aux;
        (*mov)++;
			}
		}
	}
  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;
	return tmp;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
double selection_sort(int *dados, int qtd, int *mov, int *comp){
  clock_t start = clock();
  int i, j, min_marc, aux;
  *mov = 0; *comp = 0;
  for (i=0; i<qtd-1; i++){
    min_marc = i;
    for (j=i+1; j<qtd; j++){
      (*comp)++;
      if (dados[j] < dados[min_marc]){
        min_marc = j;
      }
    }
    (*mov)++;
    aux = dados[min_marc];
    dados[min_marc] = dados[i];
    dados[i] = aux;
    (*mov)++;

  }
  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;
  return tmp;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
double insertion_sort(int *dados, int qtd, int *mov, int *comp){
  clock_t start = clock();
  int j, i, aux;
  *mov = 0; *comp = 0;
  for(i=1; i<qtd; i++){
    (*comp)++;
    aux = dados[i];
    j = i - 1;
    while(j >= 0 && (aux < dados[j])){
      dados[j+1] = dados[j];
      j = j - 1;
      (*mov)++;
    }
    dados[j+1] = aux;
  }
  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;
  return tmp;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
void merge(int *dados, int ini, int meio, int fim, int *mov, int *comp){
	int *temp, p1, p2, tam, i, j, k;
	int fim1=0, fim2=0;
	tam = fim - ini + 1;
	p1 = ini;
	p2 = meio + 1;
	temp = (int *) malloc(tam*sizeof(int));
	if(temp != NULL){
		for(i=0; i<tam; i++){
			if(!fim1 && !fim2){
        (*comp)++;
				if(dados[p1] < dados[p2]){
					temp[i] = dados[p1++];
					(*mov)++;
				}
				else
					temp[i] = dados[p2++];
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}else{
				if(!fim1){
					temp[i] = dados[p1++];
          (*mov)++;
        }
				else{
					temp[i] = dados[p2++];
          (*mov)++;
        }
			}
		}
		for(j=0, k=ini; j<tam; j++, k++)
			dados[k] = temp[j];
      (*mov)++;
	}
	free(temp);
	return;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
void print_test(int *dados, int ini, int fim)
{
  for (int i = ini; i <= fim; i++)
    printf("%d ", dados[i]);
  printf("\n");
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
void merge_ascencio(int *dados, int ini, int meio, int fim, int *mov, int *comp){
  int poslivre, inicio_vetor1, inicio_vetor2, i, tam;
  int *aux;

  tam = fim - ini + 1;
	aux = (int *) malloc(tam*sizeof(int));
  inicio_vetor1 = ini;
  inicio_vetor2 = meio + 1;
  poslivre = 0;

  while (inicio_vetor1 <= meio && inicio_vetor2 <= fim){

    (*comp)++;
    if (dados[inicio_vetor1] <= dados[inicio_vetor2]){
      aux[poslivre] = dados[inicio_vetor1];
      inicio_vetor1++;
      poslivre++;
      (*mov)++;
    }
    else{
      aux[poslivre] = dados[inicio_vetor2];
      inicio_vetor2++;
      poslivre++;
      (*mov)++;
    }
  }

  for(i=inicio_vetor1; i<=meio; i++){
    aux[poslivre] = dados[i];
    poslivre++;
    (*mov)++;
  }

  for(i=inicio_vetor2; i<=fim; i++){
    aux[poslivre] = dados[i];
    poslivre++;
    (*mov)++;
  }
  
  int j = 0;
  for(i=ini; i<=fim; i++){
    dados[i] = aux[j];
    j++;
  }

  free(aux);

  return;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
double merge_sort(int *dados, int qtd, int ini, int fim, int *mov, int *comp){
  clock_t start = clock();
  
	int meio;
	if(ini < fim){
		meio = floor((ini+fim)/2);
		merge_sort(dados, qtd, ini, meio, mov, comp);
		merge_sort(dados, qtd, meio+1, fim, mov, comp);
    merge_ascencio(dados, ini, meio, fim, mov, comp);
	}

  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;

  return tmp;
}
//-------------------------------------------------------------------------------------------------------------------------------------------