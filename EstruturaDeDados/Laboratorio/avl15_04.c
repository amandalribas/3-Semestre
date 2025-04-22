#include <stdio.h>
#include <stdlib.h>

 //FATOR DE BALANCEAMENTO = AlturaDireita - Altura Esquerda
typedef struct AVL{
    int chave;
    int FB;
    struct AVL *esquerda, *direita;
}tAVL;


tAVL *treeSearch(tAVL *no, int chave){
    if (no == NULL || chave == no->chave)
        return no;
    if (no->chave > chave)
        return treeSearch(no->esquerda, chave);
    else return treeSearch(no->direita, chave);
}



tAVL *treeInsert(tAVL *no, int chave){
    if (no == NULL){ //ALOCANDO MEMORIA CASO SEJA RAIZ, OU TENHA CHEGADO NO FINAL
        no = (tAVL*)malloc(sizeof(tAVL));
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
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


tAVL *balanceia(tAVL *no){
    if (no->FB == -2){
        if((no->esquerda)->FB == -1 || (no->esquerda)->FB == 0)
            return rotacaoDireita(no);
        else if ((no->esquerda)->FB == +1)
            return rotacaoEsquerdaDireita(no);
    }
    else if (no->FB == 2){
        if ((no->direita)->FB == +1 || (no->direita)->FB == 0)
            return rotacaoEsquerda(no);
        if ((no->direita)->FB == -1)
            return rotacaoDireitaEsquerda(no);
    }
}


tAVL *rotacaoDireita(tAVL *no){
    tAVL *aux = no;
    no = aux->esquerda;
    aux->esquerda = (*no)->direita 
    (*no)->direita = aux;    
    //MUDAR O FB???
    return no;
}

tAVL *rotacaoEsquerda(tAVL *no){
    tAVL *aux = no;
    no = aux->direita;
    aux->esquerda = (*no)->direita 
    (*no)->direita = aux;
    return no;
}

tAVL *rotacaoDireitaEsquerda(tAVL *no){
    tAVl *aux = no;
    return no;
}

tAVL *rotacaoEsquerdaDireita(tAVL *no){
    tAVL *aux;

    return no;
}

//rotacao dupla, onde (fb = -2 ou fb = 2): fb = 0
