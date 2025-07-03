#ifndef HEAP_H
#define HEAP_H

#include "geraRegistros.h"


#define ARQ_HEAP "arquivos/heap.bin"

#define REG_TAM (sizeof(long long int) + sizeof(int) + sizeof(char) * 50)



int pai(int posicao);
int filhoEsq(int posicao);
int filhoDir(int posicao);

void subir(FILE *arq, int posicao);
void descer(FILE *arq, int posicao, int tamanho);
int inserir(FILE *arq, TRegistro *reg, int tamanho);
TRegistro *buscar(FILE *arq);
int excluir(FILE *arq, int tamanho);

void imprimeHeap(FILE *arq, int tamanho);
void geraHeap();

#endif
