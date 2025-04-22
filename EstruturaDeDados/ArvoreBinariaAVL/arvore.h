#include <stdlib.h>
#include <stdio.h>
#ifndef ARVORE_H
#define ARVORE_H

typedef struct AVL{
    int chave;
    struct AVL *esquerda, *direita;
    int fb;
}tAVL;


#endif