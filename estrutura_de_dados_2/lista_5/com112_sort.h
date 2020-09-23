#ifndef _SORT_H
#define _SORT_H

void merge(int *dados, int ini, int meio, int fim, int *mov, int *comp);
double merge_sort(int *dados, int qtd, int ini, int fim, int *mov, int *comp);
void merge_ascencio(int *dados, int ini, int meio, int fim, int *mov, int *comp);
double bubble_sort(int *dados, int qtd, int *mov, int *comp);
double selection_sort(int *dados, int qtd, int *mov, int *comp);
double insertion_sort(int *dados, int qtd, int *mov, int *comp);

#endif