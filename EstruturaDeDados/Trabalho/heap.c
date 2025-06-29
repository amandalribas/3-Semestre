#include "geraRegistros.h"

#define REG_TAM (8 + 4 + 100)

int pai(int posicao){
    return posicao/2;
}

int filhoEsq(int posicao){
    return posicao*2;
}

int filhoDir(int posicao){
    return (posicao*2)+1;
}

void subir(FILE *arq, int posicao){
    int posPai = pai(posicao);
    if (posPai>=1){
        fseek(arq, posicao * REG_TAM, SEEK_SET);
        TRegistro *reg = leRegistroBin(arq);
    
        fseek(arq, posPai * REG_TAM, SEEK_SET);
        TRegistro *regPai = leRegistroBin(arq);

        if (reg->cpf > regPai->cpf){
            fseek(arq, posicao * REG_TAM, SEEK_SET);
            escreveRegBin(arq, regPai);

            fseek(arq,posPai *TAM_ARQTXT,SEEK_SET);
            escreveRegBin(arq,reg);
            fflush(posPai);
            subir(arq,posPai);
        }
        free(reg);
    }
}

int insere(FILE *arq, TRegistro *reg, int tamanho) {
    //Abre o arquivo
    //aumenta tamanho da heap
    tamanho++;
    fseek(arq, tamanho * REG_TAM, SEEK_SET);
    escreveRegBin(arq, reg);
    fflush(arq);
    subir(arq, tamanho);
    //retorna o novo valor de n
    return tamanho;
}

int main(void){
    int tamanho = 0;
    FILE *arq = fopen("registros.bin", "rb+");
    for (int i = 0; i < QUANT_REG; i++){
        TRegistro *reg = leRegistroBin(arq);
        tamanho = insere("heap.bin", reg, tamanho);
    }
    fclose(arq);
    imprimeArqBin("heap.bin");
    return 0;

}