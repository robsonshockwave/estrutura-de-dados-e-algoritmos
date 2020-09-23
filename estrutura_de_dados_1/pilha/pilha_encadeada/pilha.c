#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"


//criando elemento
struct elemento{
    char dado;
    struct elemento *prox;
};


//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int quant;
};


// função para alocar memória do tipo Pilha
Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->inicio = NULL;
        pi->fim = NULL;
        pi->quant = 0;
    }
    return pi;
}

// função para liberar memória
int liberar_pilha(Pilha *pi){

  if(pi == NULL){    
    return 0;
  }

  Elemento *atual;

  if(pi->inicio == NULL){
      pi->fim = NULL;

  }else{
    while (pi->fim != NULL){
      atual = pi->inicio;
      pi->inicio = atual->prox;
      free(atual);

      if(pi->inicio == NULL){
        pi->fim = NULL;
      }
    }

    free(pi);
  }

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento* criar_elemento(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    return no;
}


// função para inserir elemento no topo da pilha (início da lista)
int empilhar(Pilha *pi, char dado){

  if(pi == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = pi->inicio;

  // insere elemento no início da pilha
  pi->inicio = no;
  pi->fim = no;
  pi->quant++;

  return 1;
}

// função para remover elemento do topo da pilha (início da lista)
char desempilhar(Pilha *pi){

  if(pi == NULL){
    return 0;
  }

  // pilha vazia, não remove nada
  if((pi->inicio) == NULL){
    return 0;
  }

  // muda inicio para o proximo elemento
  Elemento *no;
  no = pi->inicio;
  pi->inicio = no->prox;
  pi->quant--;

  // libera Elemento no
  free(no);

  return 1;
}

// função para consultar o primeiro elemento
int consultar_topo_pilha(Pilha *pi, char *dado){

  // verifica se a pilha foi criada corretamente e se não está vazia
  if(pi == NULL || pi->inicio == NULL){
    return 0;
  }

  Elemento *no = pi->inicio;

  // copia o dado do topo da pilha (início da lista)
  *dado = no->dado;

  return 1;
}

// função que devolve o tamanho da pilha
int tamanho_pilha(Pilha *pi){
    if(pi == NULL){
        return -1;
    }
    return pi->quant;
}
