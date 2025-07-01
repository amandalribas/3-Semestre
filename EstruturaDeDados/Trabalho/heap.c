#include "geraRegistros.h"

#define REG_TAM sizeof(TRegistro)

int pai(int posicao){
    return posicao/(2);
}

int filhoEsq(int posicao){
    return posicao*(2);
}

int filhoDir(int posicao){
    return (posicao*2+1);
}

void subir(FILE *arq, int posicao){
    int posPai = pai(posicao);
    if (posPai>=1){
        fseek(arq, posicao * REG_TAM, SEEK_SET);
        TRegistro *reg = leRegistroBin(arq);
    
        fseek(arq, posPai * REG_TAM, SEEK_SET);
        TRegistro *regPai = leRegistroBin(arq);

        if (reg && regPai && reg->cpf > regPai->cpf){
            fseek(arq, posicao * REG_TAM, SEEK_SET);
            escreveRegBin(arq, regPai);

            fseek(arq,posPai * REG_TAM, SEEK_SET);
            escreveRegBin(arq,reg);
            fflush(arq);
            subir(arq,posPai);
        }
        free(reg);
        free(regPai);
    }
}

int insere(FILE *arq, TRegistro *reg, int tamanho) {
    tamanho++;
    fseek(arq, tamanho * REG_TAM, SEEK_SET);
    escreveRegBin(arq, reg);
    fflush(arq);
    subir(arq, tamanho);
    printf("\nInseri %lld", reg->cpf);
    return tamanho;
}


void imprimeHeap(FILE *arq){
    //FILE *arq = fopen(nomeArquivo, "rb");
    if (arq == NULL) return;
    TRegistro *reg;
    printf("\n");
    int i = 0;
    while ((reg = leRegistroBin(arq)) != NULL){
        printf("\nRegistro %d= { CPF= %lld , NOME= %s, NOTA= %.1f}",i, reg->cpf, reg->nome, reg->nota);
        i++;
        free(reg);
    }
}


int main(void){
    srand(time(NULL));
    geraRegistros("output/registros.bin",QUANT_REG);
    imprimeArqBin("output/registros.bin");
    int tamanho = 0;
    FILE *arq = fopen("output/registros.bin", "rb+");
    FILE *arqHeap = fopen("output/heap.bin", "wb+");
    TRegistro *reg = leRegistroBin(arq);
    for (int i = 0; i < QUANT_REG; i++){
        reg = leRegistroBin(arq);
        tamanho = insere(arqHeap, reg, tamanho);
        free(reg);
    }

    fclose(arqHeap);
    fclose(arq);
    printf("Total de registros inseridos: %d\n", tamanho);
    
    FILE *arqHeap2 = fopen("output/heap.bin", "rb");

    imprimeHeap(arqHeap2);
    fclose(arqHeap2);
    return 0;


}