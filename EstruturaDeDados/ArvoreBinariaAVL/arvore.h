#ifndef ARVORE_H
#define ARVORE_H

typedef struct AVL{
    int chave;
    struct AVL *esquerda, *direita;
    int altura;
}tAVL;


#endif