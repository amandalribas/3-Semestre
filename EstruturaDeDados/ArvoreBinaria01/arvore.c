#include <stdio.h>
#include <stdlib.h>
#include "ordem.h"
#include "arvore.h"

TAB *treeSearch(TAB *no, int chave){
    if (no == NULL || chave == no->chave)
        return no;
    if (no->chave > chave)
        no = treeSearch(no->esquerda, chave);
    else no = treeSearch(no->direita, chave);
}

TAB *treeMinimum(TAB *no){
    if (no->esquerda != NULL)
        no = treeMinimum(no->esquerda);
    return no;
}

TAB *treeMaximum(TAB *no){
    if (no->direita != NULL)
        no = treeMaximum(no->direita);
    return no;
}

TAB *treeInsert(TAB *no, int chave){
    if (no == NULL){ //ALOCANDO MEMORIA CASO SEJA RAIZ, OU TENHA CHEGADO NO FINAL
        no = (TAB*)malloc(sizeof(TAB));
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
        //printf("\nInseri %d", chave);
        return no;
    }

    if (chave < no->chave)
        no->esquerda = treeInsert(no->esquerda, chave);
    else no->direita = treeInsert(no->direita, chave);
    
}



