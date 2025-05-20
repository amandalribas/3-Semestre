#include <stdio.h>
#include <stdlib.h>


typedef struct noA{
    int info;
    struct noA* esquerda;
    struct noA* direita;
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

typedef struct fila{
    TNoA *no;
    struct fila *proximo;
}TFila;

void appendFila(TNoA *no, TFila **fila){
    if (!(*fila)){
        (*fila) = (TFila*)malloc(sizeof(TFila));
        (*fila)->no = no;
        (*fila)->proximo = NULL;
        return;
    }
    appendFila(no, &((*fila)->proximo));
}

TNoA *popFila(TFila **fila){
    TNoA *no = NULL;
    if ((*fila)){
        TFila *aux = *fila;
        (*fila) = (*fila)->proximo;
        no = aux->no;
        free(aux);
    }
    return no;
}

void percorreNivel(TNoA *no){
    TFila *fila = NULL;
    TNoA *atual = no;
    appendFila(atual, &fila);

    while (fila != NULL){
        atual = popFila(&fila);

        printf("%d \t", atual->info);
        if (atual->esquerda)
            appendFila(atual->esquerda, &fila);
        if (atual->direita)
            appendFila(atual->direita, &fila);
    }

}

int cheia(TNoA *no){
    if(!no) return 1;
    if ((!no->esquerda && no->direita)||(no->esquerda && !no->direita))
        return 0;
    return cheia(no->esquerda) && cheia(no->direita);
    
}

void espelho(TNoA *no){
    if (no){
        TNoA *aux = no->esquerda;
        no->esquerda = no->direita;
        no->direita = aux;
        espelho(no->esquerda);
        espelho(no->direita);
    }
}

TNoA *insere(TNoA *raiz, int valor){
    if (!raiz){
        raiz = (TNoA*)malloc(sizeof(TNoA));
        raiz->direita = NULL;
        raiz->info = valor;
        raiz->esquerda = NULL;
    }else{
        if (valor < raiz->info) raiz->esquerda = insere(raiz->esquerda, valor);
        else if (valor > raiz->info) raiz->direita = insere(raiz->direita, valor);
        else printf("CHAVE JA EXISTENTE.");
    }
    return raiz;
}

void criaArvoreBalanceada(TNoA *raiz, int v[], int inicio, int fim){
    if (inicio <= fim){
        int meio = (inicio + fim)/2;
        raiz = insere(raiz, v[meio]);
        criaArvoreBalanceada(raiz,v,inicio, meio-1);
        criaArvoreBalanceada(raiz,v,meio+1,fim);
    }

}
int main(void){
    TNoA *raiz = criaNo(5);
    raiz->esquerda = criaNo(3);
    raiz->direita = criaNo(7);
    raiz->direita->esquerda = criaNo(6);
    raiz->direita->direita = criaNo(8);

    percorreNivel(raiz);

    espelho(raiz);
    printf("\n");
    percorreNivel(raiz);
    return 0;
}

/*Estrutura auxiliar necessária: fila
1. Adicionar a raiz na fila
2. Repetir até que a fila fique vazia
1. Retirar primeiro da fila (visita)
2. Adicionar nó da esquerda na fila (se diferente de NULL)
3. Adicionar nó da direita na fila (se diferente de NULL)*/