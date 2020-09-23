// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "pilha.h"

// protótipo da função que cria um dado 
int criar_dado(char *dado);


// funcao principal
int main(void) {

  // no início a pilha está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da pilha
  Pilha *pi = NULL;
  int opcao, ok, pos;
  char dado;

  // menu de opções para execuções de operações sobre a pilha
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar pilha");
    printf("\n2 - Liberar pilha");
    printf("\n3 - Empilhar elemento");
    printf("\n4 - Desempilhar elemento");
    printf("\n5 - Consultar topo");
    printf("\n6 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar pilha
        pi = criar_pilha();

        if(pi != NULL){
          printf("\n Pilha criada com sucesso!");
        }else{
          printf("\n Pilha não criada!");
        }
        break;


      case 2:

        // liberar pilha
        ok = liberar_pilha(pi);

        if(ok){
          printf("\n Pilha liberada com sucesso!");
        }else{
          printf("\n Pilha não liberada!");
        }
        break;

      case 3:

        // empilhar elemento 
        ok = criar_dado(&dado);
        ok = empilhar(pi, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // desempilhar elemento
        ok = desempilhar(pi);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 5:

        ok = consultar_topo_pilha(pi, &dado);

        if(ok){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento no topo da pilha: ");
          printf(" %c", dado);
        }else{
          printf("\n Pilha vazia!");
        }

        break;

      case 6:

        // libera memória e finaliza programa
        liberar_pilha(pi);
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