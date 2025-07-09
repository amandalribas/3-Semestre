#include "bMais.h"


int arquivoVazio(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("\nERRO ao abrir o arquivo!");
        return -1;  // erro ao abrir
    }

    fseek(arquivo, 0, SEEK_END); // vai para o final do arquivo
    long long int tamanho = ftell(arquivo); // pega a posição atual (tamanho)
    fclose(arquivo);

    return (tamanho == 0);
}

int buscaArvoreBM(int chave){
    FILE *arqInd =  fopen(ARQ_BM_IND, "wb+");
    
    return 0;
}

/*
int buscaBM(int chave){
    FILE *arqInd = fopen("")
}*/


void geraArvoreBM(){
    FILE *arqReg = fopen(ARQ_REG, "rb+");

    for (int i = 0; i < QUANT_REG; i++){
        leRegistroBin(arqReg);
        
    }


    fclose(arqReg);
}

