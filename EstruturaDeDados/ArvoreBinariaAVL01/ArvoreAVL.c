#include <stdio.h>
#include <stdlib.h>

typedef struct noAVL{
    int info, altura;
    struct noAVL *esquerda;
    struct noAVL *direita;
}TAVL;

/*int calculaAltura(TAVL *raiz){
    if (!raiz)
        return -1;
    int alturaEsquerda = calculaAltura(raiz->esquerda);
    int alturaDireita = calculaAltura(raiz->direita);
    if (alturaEsquerda > alturaDireita)
        return alturaEsquerda + 1;
    else
        return alturaDireita + 1;
}*/

int calculaAltura(TAVL *raiz){
    if (!raiz) return -1;
    return raiz->altura;
}

int maxAltura(TAVL *no){
    int altEsq = no->esquerda ? no->esquerda->altura : -1;
    int altDir = no->direita ? no->direita->altura : -1;
    return altEsq > altDir ? altEsq : altDir;
}

int calculaFatorBalanceamento(TAVL *raiz){
    return calculaAltura(raiz->direita) - calculaAltura(raiz->esquerda);
}

/*Fator de Balanceamento: diferença entre altura da subárvore direita e esquerda 
FB(n) = altura(n→dir) – altura(n→esq*/


TAVL *rotacaoDireita(TAVL *raiz){
    TAVL *aux = raiz->esquerda;
    raiz->esquerda = aux->direita;
    aux->esquerda = raiz;

    aux->altura = maxAltura(aux) + 1;
    raiz->altura = maxAltura(raiz) + 1;
    return aux;
}

TAVL *rotacaoEsquerda(TAVL *raiz){
    TAVL *aux = raiz->direita;
    raiz->direita = aux->esquerda;
    aux->esquerda = raiz;

    aux->altura = maxAltura(aux) + 1;
    raiz->altura = maxAltura(raiz) + 1;
    return aux;
}

TAVL *rotacaoDireitaEsquerda(TAVL *raiz){
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

TAVL *rotacaoEsquerdaDireita(TAVL *raiz){
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}


TAVL *insereAVL(TAVL *raiz, int info){
    if(!raiz){
        raiz = (TAVL*)malloc(sizeof(TAVL));
        raiz->info = info;
        raiz->altura = 0;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    }else{
        if(info < raiz->info){
            raiz->esquerda = insereAVL(raiz->esquerda, info);
            if(calculaFatorBalanceamento(raiz)==2){
                int fbFilho = calculaFatorBalanceamento(raiz->direita);
                if(fbFilho == 1 || fbFilho == 0){
                    raiz = rotacaoEsquerda(raiz);
                }else{
                    raiz = rotacaoDireitaEsquerda(raiz);
                }
            }
        }else if(info > raiz->info){
            raiz->direita = insereAVL(raiz->direita, info);
            if (calculaFatorBalanceamento(raiz)== -2){
                int fbFilho = calculaFatorBalanceamento(raiz->esquerda);
                if (fbFilho == 1 || fbFilho == 0){
                    raiz = rotacaoEsquerdaDireita(raiz);
                }else{
                    raiz = rotacaoDireita(raiz);
                }
            }
        }
    }
    raiz->altura = maxAltura(raiz) + 1;
    return raiz;
}

TAVL *maiorValor(TAVL *raiz){
    if (!raiz->direita) return raiz;
    return maiorValor(raiz->direita);
}




TAVL *removeAVL(TAVL *raiz, int info){
    if (!raiz ) return raiz;

    if (raiz->info > info) raiz->esquerda = removeAVL(raiz->esquerda,info);
    else if (raiz->info < info) raiz->direita = removeAVL(raiz->direita,info);
    
    else{ //encontrou:
        TAVL *sucessor;
        if (!raiz->esquerda){ //Se for folha, return NULL, se so tiver filho a direita, retorna ele
            sucessor = raiz->direita;
            free(raiz);
            return sucessor;
        }else if (!raiz->direita){ //Se so tem filho a esquerda, retorna ele
            sucessor = raiz->esquerda;
            free(raiz);
            return sucessor;
        }else{
            sucessor = maiorValor(raiz->esquerda);
            raiz->info = sucessor->info;
            raiz->esquerda = removeAVL(raiz->esquerda, sucessor->info);
        }

    }
    raiz->altura = maxAltura(raiz) + 1;
    int fb = calculaFatorBalanceamento(raiz);
    if (fb == 2){
        int fbFilho = calculaFatorBalanceamento(raiz->direita);
        if (fbFilho == 1 || fbFilho == 0){
            raiz = rotacaoEsquerda(raiz);
        }else{
            raiz = rotacaoDireitaEsquerda(raiz);
        }
    }if (fb == -2){
        int fbFilho = calculaFatorBalanceamento(raiz->esquerda);
        if (fbFilho == 1 || fbFilho == 0){
            raiz = rotacaoEsquerdaDireita(raiz);
        }else{
            raiz = rotacaoDireita(raiz);
        }
    }

    return raiz;
}

void inOrder(TAVL *raiz){
    if(!raiz) return;
    inOrder(raiz->esquerda);
    printf("%d\t", raiz->info);
    inOrder(raiz->direita);
}

int main(void){
    TAVL *raiz = NULL;
    raiz = insereAVL(raiz, 10);
    raiz = insereAVL(raiz, 7);
    raiz = insereAVL(raiz, 13);
    raiz = insereAVL(raiz, 5);
    raiz = insereAVL(raiz, 12);
    raiz = insereAVL(raiz, 11);
    inOrder(raiz);
    printf("\n");
    raiz = removeAVL(raiz,12);
    inOrder(raiz);
    return 0;
}