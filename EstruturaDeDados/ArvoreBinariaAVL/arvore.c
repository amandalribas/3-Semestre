#include "arvore.h"

//FATOR DE BALANCEAMENTO = alturaDireita - alturaEsquerda = 0, 1, -1. > 1 ou < -1 Esta Desbalanceada

tAVL *newNode(tAVL *no, int chave){
    no = (tAVL*)malloc(sizeof(tAVL));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    no->fb = 0;
}


tAVL *insertAVL(tAVL *no, int chave){
    if (no == NULL){
        newNode(no, chave);
    }
    if (chave < no->chave){
        no->esquerda = insert(no->esquerda,chave);
        no->fb--;
        if (no->fb == -2){
            if((no->esquerda)->fb == -1 || (no->esquerda)->fb == 0)
                no = rotacaoDireita(no);
            else if ((no->esquerda)->fb == 1)
                no = rotacaoEsquerdaDireita(no);
        }
    }
    else if (chave > no->chave){
        no = insert(no->direita,chave);
        no->fb++;
        if (no->fb == 2){
            if ((no->direita)->fb == +1 || (no->direita)->fb == 0) 
                no = rotacaoEsquerda(no); 
            else if (no->direita == -1) 
                no = rotacaoDireitaEsquerda(no);
        }
    }   
    else 
        printf("CHAVE JA EXISTENTE, INSERCAO INVALIDA");
    return no;    
}

tAVL *rotacaoDireita(tAVL *no){
    tAVL *aux = no->esquerda;
    no->esquerda = aux->direita;
    aux->direita = no;
    return no;
}

tAVL *rotacaoEsquerda(tAVL *no){
    tAVL *aux = no->direita;
    no->direita = aux->esquerda;
    aux->esquerda = no;
    return no;
}

tAVL *rotacaoEsquerdaDireita(tAVL *no){ //DUPLA DIREITA
    no->esquerda = rotacaoEsquerda(no->esquerda);
    return rotacaoDireita(no);
}

tAVL *rotacaoDireitaEsquerda(tAVL *no){ //DUPLA ESQUERDA
    no->direita = rotacaoDireita(no->direita);
    return rotacaoEsquerda(no);
}
