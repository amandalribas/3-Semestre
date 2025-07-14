#ifndef HASH_H
#define HASH_H

#include "geraRegistros.h"

#define M 100000
#define ARQ_HASH "arquivos/registrosHash.bin"

int h();
//int h(int x, int k);

void inicilizaHash(FILE *arq);

int buscaHash(FILE *arq, int chaveCPF);
void insereHash(FILE *arq, TRegistro *reg);
int excluiHash(FILE *arq, int chaveCPF);
void imprimeHash(FILE *arq);

void geraHash();
void geraInsereHash();
void geraBuscaHash();
void geraExcluiHash();
#endif