#include <stdio.h>
#include <stdlib.h>

#include "fila.h"


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


// função para alocar memória do tipo Fila
Fila* criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->quant = 0;
    }
    return fi;
}

// função para liberar memória
int liberar_fila(Fila *fi){

  if(fi == NULL){    
    return 0;
  }

  Elemento *atual;

  if(fi->inicio == NULL){
      fi->fim = NULL;

  }else{
    while(fi->fim != NULL){
      atual = fi->inicio;
      fi->inicio = atual->prox;
      fi->quant--;
      free(atual);

      if(fi->inicio == NULL){
        fi->fim = NULL;
      }
    }

    free(fi);
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


// função para inserir elemento no final da fila 
int enfileirar(Fila *fi, char dado){

  if(fi == NULL){
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

  // se a fila estiver vazia, insere no início da fila
  if( fi->inicio == NULL ){
    no->prox = NULL;
    fi->inicio = no;
  
  }else{

    // insere elemento no final da fila
    fi->fim->prox = no;
    fi->fim = no;
    fi->quant++;
  }

  return 1;
}

// função para remover elemento do início da fila
char desenfileirar(Fila *fi){

  if(fi == NULL){
    return 0;
  }

  // fila vazia, não remove nada
  if((fi->inicio) == NULL){
    return 0;
  }

  // muda inicio para o proximo elemento
  Elemento *no;
  no = fi->inicio;
  fi->inicio = no->prox;
  fi->quant--;

  // libera Elemento no
  free(no);

  return 1;
}

// função para consultar o primeiro elemento
int consultar_inicio_fila(Fila *fi, char *dado){

  // verifica se a fila foi criada corretamente e se não está vazia
  if(fi == NULL || fi->inicio == NULL){
    return 0;
  }

  Elemento *no = fi->inicio;

  // copia o dado do início da fila
  *dado = no->dado;

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_fila(Fila *fi){
    if(fi == NULL){
        return -1;
    }
    return fi->quant;
}
