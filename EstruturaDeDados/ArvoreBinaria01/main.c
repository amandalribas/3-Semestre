#include <stdio.h>
#include <stdlib.h>
#include "ordem.h"
#include "arvore.h"

/*
gcc main.c arvore.c ordem.c -o nomeDaExecucao
.\nomeDaExecucao
*/

int main(void){
    TAB *raiz = NULL, *no = NULL, *min = NULL, *max = NULL, *busca;
    no = treeInsert(no,15);
    raiz = no;
    no = treeInsert(no,6);
    no = treeInsert(no,18);
    no = treeInsert(no,3);
    no = treeInsert(no,21);
    no = treeInsert(no,14);

    printf("\nPRE ORDEM:");
    preOrdem(raiz);

    printf("\nIN ORDEM: ");
    inOrdem(raiz);

    printf("\nPOS ORDEM: ");
    posOrdem(raiz);
    
    min = treeMinimum(raiz);
    printf("\n MINIMO DA ARVORE: %d", min->chave);
    
    max = treeMaximum(raiz);   
    printf("\n MAXIMO DA ARVORE: %d", max->chave);

    busca = treeSearch(raiz,14);
    printf("\nEncontrou? %d", busca->chave);

    busca = treeSearch(raiz,12);
    printf("\nEncontrou? %d", busca->chave);
    return 0;
}