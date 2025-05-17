#include <stdio.h>
#include <stdlib.h>
#include "Headers/arvore.h"
#include "Headers/ordem.h"
#include "Headers/extra.h"


void preOrdem(TAB *no){
    if (no == NULL) return;
    printf("\t%d ", no->chave);
    preOrdem(no->esquerda);
    preOrdem(no->direita);
}

void inOrdem(TAB *no){
    if (no == NULL) return;
    inOrdem(no->esquerda);
    printf("\t%d ", no-> chave);
    inOrdem(no->direita);
}

void posOrdem(TAB *no){
    if (no == NULL) return;
    posOrdem(no->esquerda);
    posOrdem(no->direita);
    printf("\t%d ", no-> chave);
}
