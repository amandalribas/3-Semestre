#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NoABB{
    int info;
    struct NoABB *esquerda;
    struct NoABB *direita;
}TABB;

TABB *cria(int info,TABB *esquerda, TABB *direita);
void libera(TABB *node);
TABB *inserir(TABB *root, int info);
TABB *remover(TABB *root, int info);

void preOrder(TABB *root);
void inOrder(TABB *root);
void postOrder(TABB *root);


#endif