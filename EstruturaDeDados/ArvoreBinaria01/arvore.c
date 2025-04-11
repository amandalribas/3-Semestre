#include <stdio.h>
#include <stdlib.h>
#include "Headers/ordem.h"
#include "Headers/arvore.h"
#include "Headers/extra.h"


TAB *treeSearch(TAB *no, int chave){
    if (no == NULL || chave == no->chave)
        return no;
    if (no->chave > chave)
        return treeSearch(no->esquerda, chave);
    else return treeSearch(no->direita, chave);
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
    else if (chave > no->chave) 
        no->direita = treeInsert(no->direita, chave);
    else if (chave == no->chave){
        printf("CHAVE JA EXISTENTE. INSERCAO INVALIDA.");
        return no;
    }
}

TAB *treeDelete(TAB *no, int chave){
    if (no==NULL) //NAO ENCONTROU / LISTA VAZIA
        return NULL;
    if (chave < no->chave)
        no->esquerda = treeDelete(no->esquerda,chave);
    else if (chave > no->chave)
        no->direita = treeDelete(no->direita, chave);
    else{ //ENCONTROU
        //SEM FILHOS:
        if ((no->esquerda == NULL)&&(no->direita == NULL)){
            free(no);
            return NULL;
        }

        //1 FILHO:
        if (no->esquerda == NULL || no->direita == NULL){
            TAB *aux;
            if (no->esquerda == NULL)
                aux = no->direita;
            else if (no->direita == NULL)
                aux = no->esquerda;
            free(no);
            return aux;
        }
        

        //2 FILHOS:
         //substitui valor do nó que tenha a maior chave da sua subárvore à esquerda
        TAB *aux;
        aux = treeMaximum(no->esquerda);
        no->chave = aux->chave;
        no->esquerda = treeDelete(no->esquerda, aux->chave);
        
    }     
    return no;
}




