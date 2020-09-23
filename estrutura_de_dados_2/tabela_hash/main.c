#include <stdio.h>
#include <stdlib.h>
#include "com112_hash.h"

int menu();

int main(){

    int tamanho = 1024;
    Hash *tabela;
    struct aluno al, a[4]; 
    int opcao, x, num, cont = 0;

    do{
    opcao = menu();
    switch(opcao){

    case 1: 
        tabela = criaHash(tamanho);
        printf("\nHash criada com sucesso\n\n");
        break;

    case 2: 
        liberaHash(tabela);
        printf("\nLiberada com sucesso\n\n");
        break;

    case 3:
        printf("Digite o numero de matricula: ");
        scanf("%d", &a[cont].matricula);
        getchar();
        printf("Digite o nome: ");
        fgets(a[cont].nome, 30, stdin);
        printf("Digite a nota 1: ");
        scanf("%f", &a[cont].n1);
        printf("Digite a nota 2: ");
        scanf("%f", &a[cont].n2);
        x = insereHash_SemColisao(tabela, a[cont]);
        if(x){
            printf("\nInserido :)\n");
            cont++;
        }else{
            printf("\nnao foi possivel inserir\n");
        }
        break;

    case 4:
        printf("Digite o numero de matricula: ");
        scanf("%d", &num);
        x = buscaHash_SemColisao(tabela, num, &al);
        if(x){
            printf("\nNome: %s\n", al.nome);
            printf("Matricula: %d\n", al.matricula);
            printf("Nota 1: %f\n", al.n1);
            printf("Nota 2: %f\n", al.n2);
        }else{
            printf("Nao encontrado");
        }
        break;

    case 5:
        printf("\nFinalizando...");
        break;

    default: 
        printf("\nOpcao invalida");
        break;
    }
    }while(opcao>0 && opcao<5);

    return 0;
}

int menu(){

    int opcao;
    
    printf("\n\n~~ Bem vindo(a) a Tabela Hashing ~~\n\nMenu de opções");
    printf("\n1 - Criar tabela hash");
    printf("\n2 - Liberar tabela hash");
    printf("\n3 - Inserir elemento (sem colisao)");
    printf("\n4 - Consultar elemento (sem colisao)");
    printf("\n5 - Sair");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    printf("\n");

    return opcao;
}
