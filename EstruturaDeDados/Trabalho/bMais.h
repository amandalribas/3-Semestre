#ifndef BMAIS_H
#define BMAIS_H

#include "geraRegistros.h"

#define D 5 // ORDEM DA ÁRVORE B+

typedef struct noBM {
    int nChaves;          // Número de chaves no nó
    int folha;            // Indicador de folha (1 para folha, 0 para nó interno)
    long long int *chave; // Array de chaves
    struct noBM **filho;  // Array de ponteiros para filhos
    struct noBM *prox;    // Ponteiro para o próximo nó (usado em folhas)
} TNoBM;

/* Operações básicas */
TNoBM *criaBM(); 
TNoBM *inicializaBM(); 
void liberaBM(TNoBM *raiz);
//void carregaRegistrosNaArvore(TNoBM **arvore);

void geraBM();
void geraBuscaBM();
void geraExcluiBM();
void geraInsereBM();
/* Operações de busca */
TNoBM *buscaBM(TNoBM *raiz, TRegistro *reg);

/* Operações de impressão */
void imprimeChavesBM(TNoBM *raiz);
void imprimeBM(TNoBM *raiz);
void imprimeRegistrosBM(TNoBM *raiz, FILE *arq);

/* Operações de inserção */
TNoBM *divisao(TNoBM *x, int i, TNoBM *y);
TNoBM *insereNaoCompletoBM(TNoBM *x, TRegistro *reg);
TNoBM *insereBM(TNoBM *T, TRegistro *reg);

/* Operações de remoção */
TNoBM *excluiBM(TNoBM *arv, TRegistro *reg);
TNoBM *retiraBM(TNoBM *arv, TRegistro *reg);

#endif