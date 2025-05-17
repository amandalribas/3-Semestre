#include <stdio.h>
#include <stdlib.h>
#include "Headers/ordem.h"
#include "Headers/arvore.h"

TAB *treeMinimum(TAB *no){ //left most
    if (no->esquerda != NULL)
        no = treeMinimum(no->esquerda);
    return no;
}

TAB *treeMaximum(TAB *no){ //right most
    if (no->direita != NULL)
        no = treeMaximum(no->direita);
    return no;
}


TAB *treeSucessor(TAB *raiz, int chave){
    TAB *x = treeSearch(raiz, chave);
    TAB *sucessor = NULL;

    if (x == NULL) return NULL;

    if(x->direita != NULL)
        return treeMinimum(x->direita);
    
    x = raiz;
    while (x!=NULL){
        if (chave < x->chave){
            sucessor = x;
            x = x->esquerda;
        }
        else if(chave > x->chave)
            x = x->direita;
        else return sucessor;
    }
}

TAB *treePredecessor(TAB *raiz, int chave){
    TAB *x = treeSearch(raiz,chave);
    TAB *predecessor = NULL;

    if (x == NULL) return NULL;

    if (x->esquerda != NULL)
        return treeMaximum(x->esquerda);
    
    x = raiz;
    while (x!= NULL){
        if (chave > x->chave){
            predecessor = x; 
            x = x->direita;
        }
        else if (chave < x->chave)
            x = x->esquerda;
        else return predecessor;
    }
}

int treeHeight(TAB *no){
    if (no == NULL)
        return -1; //altura comeca em 0 se n tiver nenhum filho
    int alturaEsquerda = treeHeight(no->esquerda);
    int alturaDireita = treeHeight(no->direita);
    if (alturaEsquerda > alturaDireita)
        return alturaEsquerda + 1;
    else
        return alturaDireita + 1;
} 

int treeNode(TAB *no){
    if (no==NULL) return 0;
    return treeNode(no->esquerda)+1 + treeNode(no->direita);
}

int treeSon(TAB *no){
    if (no == NULL) return 0;
    if (no->esquerda == NULL && no->direita == NULL)
        return 1;
    return treeSon(no->esquerda) + treeSon(no->direita);
    
}