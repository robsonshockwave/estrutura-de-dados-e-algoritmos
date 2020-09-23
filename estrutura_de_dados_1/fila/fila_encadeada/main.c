
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "fila.h"

// protótipo da função que cria um dado 
int criar_dado(char *dado);


// funcao principal
int main(void) {

  // no início a fila está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da fila
  Fila *fi = NULL;
  int opcao, ok, pos;
  char dado;

  // menu de opções para execuções de operações sobre a fila
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar fila");
    printf("\n2 - Liberar fila");
    printf("\n3 - Enfileirar elemento");
    printf("\n4 - Desenfileirar elemento");
    printf("\n5 - Consultar início da fila");
    printf("\n6 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar fila
        fi = criar_fila();

        if(fi != NULL){
          printf("\n Fila criada com sucesso!");
        }else{
          printf("\n Fila não criada!");
        }
        break;


      case 2:

        // liberar fila
        ok = liberar_fila(fi);

        if(ok){
          printf("\n Fila liberada com sucesso!");
        }else{
          printf("\n Fila não liberada!");
        }
        break;

      case 3:

        // enfileirar elemento 
        ok = criar_dado(&dado);
        ok = enfileirar(fi, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // desenfileirar elemento
        ok = desenfileirar(fi);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 5:

        ok = consultar_inicio_fila(fi, &dado);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento no início da fila: ");
          printf(" %c", dado);
        }else{
          printf("\n Fila vazia!");
        }

        break;

      case 6:

        // libera memória e finaliza programa
        liberar_fila(fi);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 6);

  return 0;
}





int criar_dado(char *dado)
{
    printf("\nDigite um caractere: ");
    scanf(" %c", dado);

    return 1;
}