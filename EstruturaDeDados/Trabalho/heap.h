#ifndef HEAP_H
#define HEAP_H

#include "geraRegistros.h"


#define ARQ_HEAP "arquivos/registrosHeap.bin"


int pai(int posicao);
int filhoEsq(int posicao);
int filhoDir(int posicao);

void sobe(FILE *arq, int posicao);
void desce(FILE *arq, int posicao, int tamanho);
int insereHeap(FILE *arq, TRegistro *reg, int tamanho);
TRegistro *buscaHeap(FILE *arq);
int excluiHeap(FILE *arq, int tamanho);

void imprimeHeap(FILE *arq, int tamanho);
void geraHeap();
void geraBuscaHeap();
void geraExcluiHeap();
void geraInsereHeap();
#endif
