#include "ABB.h"

int main(void){
    TABB *raiz = cria(12,NULL, NULL);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz,14);
    raiz = inserir(raiz,8);
    raiz = inserir(raiz, 11);
    raiz = inserir(raiz,15);
    
    inOrder(raiz);

    raiz = remover(raiz,14);
    printf("\n");
    inOrder(raiz);
    return 0;

}