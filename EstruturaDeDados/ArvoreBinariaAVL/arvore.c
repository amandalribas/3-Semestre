#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//FATOR DE BALANCEAMENTO = alturaEsquerda - alturaDireita = 0, 1, -1. > 1 ou < -1 Esta Desbalanceada

tAVL *insertAVL(tAVL *no, int chave){
    if (no == NULL){
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
        no->altura = 0; //altura de uma folha
    }
    if (chave < no->chave)
        no->esquerda = insert(no->esquerda,chave);
    else if (chave > no->chave)
        no = insert(no->direita,chave);
    else 
        printf("CHAVE JA EXISTENTE, INSERCAO INVALIDA");
    return no;    
}

int alturaAVL(tAVL *no){
    if (no  == NULL)
        return -1;
    int alturaEsquerda = alturaAVL(no->esquerda);
    int alturaDireita = alturaAVL(no->direita);
    return comparaVal(alturaEsquerda,alturaDireita) + 1;
    
}

int fatorBalanceamento(tAVL *no){
    if (no)
        return alturaAVL(no->esquerda) - alturaAVL(no->direita);
    return 0;
}

int comparaVal(int altura1, int altura2){ //RETORNA O MAIOR ENTRE VALORES;
    if (altura1 > altura2)
        return altura1;
    else return altura2;
}