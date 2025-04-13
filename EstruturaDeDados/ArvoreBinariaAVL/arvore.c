#include <stdio.h>
#include <stdlib.h>

 //FATOR DE BALANCEAMENTO = alturaEsquerda - alturaDireita = 0, 1, -1. > 1 ou < -1 Esta Desbalanceada
typedef struct AVL{
    int chave;
    int FB;
    struct AVL *esquerda, *direita;
}tAVL;