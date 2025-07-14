#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBERADO 0
#define OCUPADO 1
#define M 100;


typedef struct pessoa{
    int idade;
    int matricula;
    char nome[30];
    int prox;
    int ocupado;
}TPessoa;
typedef TPessoa *Hash;

int h(int matricula){
    return matricula % M;
}


TPessoa *aloca(int idade, int matricula, char nome[30], int ocupado, int prox){
    TPessoa *novo = (TPessoa*)malloc(sizeof(TPessoa));
    novo->idade;
    novo->matricula;
    strcpy(novo->nome,nome);
    novo->ocupado = ocupado;
    return novo;
}

void iniciailiza(Hash *hash){
    for (int i = 0; i < M; i++){
        hash[i] = aloca(-1,-1,"",LIBERADO);
    }
}

int busca(Hash *hash, int matricula, int *achou){
    *achou = -1;
    int aux = -1;
    int i = h(matricula);
    while (*achou == -1){
        TPessoa *atual = hash[i];
        if (atual->ocupado){
            aux = i;
        }if (atual->matricula == matricula && atual->ocupado){
            *achou = 1
        }else {
            if (atual->prox == -1){
                *achou = 0;
                i = aux;
            }else {
                i = atual->prox;
            }
        }
    }
    return i;
}


