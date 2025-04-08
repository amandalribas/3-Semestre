#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA{
    char info;
    int chave;
    struct sNoA* esq; //menor
    struct sNoA* dir; //maior
} TNoA;


//CORRIGIR A FUNCAO DE BUSCA DEPOIS:::::::::;
TNoA* busca(TNoA *no, int chave){
    if (no == NULL) //vazia
        return NULL;

    if (chave > no->chave)
        return busca(no->dir, chave);

    if (chave < no->chave)
        return busca(no->esq,chave);

    if (chave == no->chave){
        printf("Encontrou");
        return no;
    }
    printf("Nao Encontrou");
    return NULL;
}

TNoA* insere(TNoA *no, int chave){
    if (no == NULL){
        no = (TNoA*)malloc(sizeof(TNoA));
        no->dir = NULL;
        no->esq = NULL;
        no->chave = chave;
    }

    if (no->chave > chave)
        no->esq = insere(no->esq,chave);
    
    if (no->chave < chave)
        no->dir = insere(no->dir,chave);
    
    //printf("\nInsere %d", chave);
    return no;
}

void preOrdem(TNoA *no){
    if (no == NULL) return;
    printf("\n%d ", no->chave);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

void inOrdem(TNoA *no){
    if (no == NULL) return;
    inOrdem(no->esq);
    printf("\n%d ", no-> chave);
    inOrdem(no->dir);
}

void posOrdem(TNoA *no){
    if (no == NULL) return;
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("\n%d ", no-> chave);
}

int main(void){
    TNoA *no = NULL;
    TNoA *raiz = NULL;
    no = insere(no,3);
    raiz = no;
    no = insere(no,2);
    no = insere(no,1);
    no = insere(no,10);
    no = insere(no,5);
    no = insere(no,14);

    printf("PRE ORDEM:");
    preOrdem(raiz);

    printf("\nEM ORDEM: ");
    inOrdem(raiz);
 
    printf("\nPOS ORDEM: ");
    posOrdem(raiz);
    //no = busca(no,3);
    //no = busca(no,10);
    //no = printa(no);
    return 0;

}