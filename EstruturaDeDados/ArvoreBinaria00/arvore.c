#include <stdio.h>
#include <stdlib.h>

typedef struct noA{
    int info;
    struct TNoA* esquerda;
    struct TNoA* direita;
}TNoA;

TNoA *criaNo(int num){
    TNoA *node = (TNoA*)malloc(sizeof(TNoA));
    node->direita = NULL;
    node->esquerda = NULL;
    node->info = num;
    return node;
}

void libera(TNoA* node){
    if (node){
        libera(node->esquerda);
        libera(node->direita);
        free(node);
    }
}
