
#ifndef REGISTRO_H
#define REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TAM_ARQTXT 80
#define QUANT_REG 100

typedef struct tRegistro {
    long long int cpf;
    char nome[100];
    float nota;
} TRegistro;

long long int geraCPF();

float geraNota();

char *geraNome(char **nomes, char **sobrenomes);

char **leArquivoTexto(const char *nomeArquivo);

void imprimeVetor(char **nomes);

void escreveRegBin(FILE *arq, TRegistro *reg);

void geraRegistros(char *nomeArquivo, int quantidade);

TRegistro *leRegistroBin(FILE *arq);

void imprimeArqBin(char *nomeArquivo);

#endif 