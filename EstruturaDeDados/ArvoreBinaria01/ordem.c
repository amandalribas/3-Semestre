#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "ordem.h"


void preOrdem(TAB *no){
    if (no == NULL) return;
    printf("\n%d ", no->chave);
    preOrdem(no->esquerda);
    preOrdem(no->direita);
}

void inOrdem(TAB *no){
    if (no == NULL) return;
    inOrdem(no->esquerda);
    printf("\n%d ", no-> chave);
    inOrdem(no->direita);
}

void posOrdem(TAB *no){
    if (no == NULL) return;
    posOrdem(no->esquerda);
    posOrdem(no->direita);
    printf("\n%d ", no-> chave);
}
