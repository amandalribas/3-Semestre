
#ifndef GERA_REGISTROS_H
#define GERA_REGISTROS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TAM_ARQTXT 80
#define QUANT_REG 10000

#define ARQ_REG "arquivos/registros.bin"

#define TXT_NOME "arquivos/nomes.txt"
#define TXT_SOBRENOME "arquivos/sobrenomes.txt"

typedef struct tRegistro {
    long long int cpf;
    char nome[50];
    int nota;
} TRegistro;

long long int geraCPF();
int geraNota();
char *geraNome(char **nomes, char **sobrenomes);

char **leArquivoTexto(const char *nomeArquivo);

void imprimeVetor(char **nomes);

void escreveRegBin(FILE *arq, TRegistro *reg);

void geraRegistros();

TRegistro *leRegistroBin(FILE *arq);
void imprimeArqBin(char *nomeArquivo);


#endif 