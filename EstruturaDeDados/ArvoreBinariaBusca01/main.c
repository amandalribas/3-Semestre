#include <stdio.h>
#include <stdlib.h>
#include "Headers/ordem.h"
#include "Headers/arvore.h"
#include "Headers/extra.h"

/*
gcc main.c arvore.c ordem.c -o nomeDaExecucao
.\nomeDaExecucao
*/

int main(void){
    TAB *raiz = NULL, *no = NULL, *min = NULL, *max = NULL, *busca, *sucessor, *predecessor;
    no = treeInsert(no,15);
    raiz = no;
    no = treeInsert(no,6);
    no = treeInsert(no,18);
    no = treeInsert(no,3);
    no = treeInsert(no,21);
    no = treeInsert(no,14);
    no = treeInsert(no,10);
    no = treeInsert(no,7);
    no = treeInsert(no,11);
    no = treeInsert(no,25);
    no = treeInsert(no,10); //JA INSERIDA;
    no = treeInsert(no,30);

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


    busca = treeSearch(raiz,7);
    printf("\nEncontrou? %d", busca->chave);

    sucessor = treeSucessor(raiz,15);
    printf("\nSucessor de 15:: %d", sucessor->chave);

    sucessor = treeSucessor(raiz,14);
    printf("\nSucessor de 14: %d", sucessor->chave);

    sucessor = treeSucessor(raiz,18);
    printf("\nSucessor de 18: %d", sucessor->chave);

    predecessor = treePredecessor(raiz,15);
    printf("\nPredecessor de 15: %d", predecessor->chave);

    predecessor = treePredecessor(raiz,21);
    printf("\nPredecessor de 21: %d", predecessor->chave);

    printf("\nAltura da Arvore: %d", treeHeight(raiz));
    printf("\nQuantidade de nos: %d", treeNode(raiz));
    printf("\nQuantidade de Folhas: %d", treeSon(raiz));

    no = treeDelete(no,15);
    printf("\nTestando Delete: ");
    inOrdem(raiz);

    no = treeDelete(no,10);
    printf("\nTestando Delete: ");
    inOrdem(raiz);

    no = treeDelete(no,21);
    printf("\nTestando Delete: ");
    inOrdem(raiz);
    return 0;
}