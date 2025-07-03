#include "heap.h"


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

        if (reg && regPai && reg->nota > regPai->nota){
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

void descer(FILE *arq, int posicao, int tamanho){ //se ja tiver removido antes, o TAM é menor que QUANT_REG
    
     fseek(arq,posicao *REG_TAM, SEEK_SET); //registro inicial
    TRegistro *reg = leRegistroBin(arq);
    if (!reg) return;

    
    int posMaior = posicao;
    int posEsq = filhoEsq(posicao);
    int posDir = filhoDir(posicao);
    
    TRegistro *regEsq = NULL;
    TRegistro *regDir = NULL;
    TRegistro *regMaior = reg;

   

    //filhos
    if (posEsq <= tamanho ){
        fseek(arq,posEsq * REG_TAM, SEEK_SET);
        regEsq = leRegistroBin(arq);
    }if (posDir <= tamanho) {
        fseek(arq,posDir * REG_TAM, SEEK_SET);
        regDir = leRegistroBin(arq);
    }

    if (regEsq && regEsq->nota > regMaior->nota){
        regMaior = regEsq;
        posMaior = posEsq;
    }if (regDir && regDir->nota > regMaior->nota){
        regMaior = regDir;
        posMaior = posDir;
    }
    
    if (posMaior != posicao){ //se um filho maior que o pai
        fseek(arq,posicao *REG_TAM, SEEK_SET);
        escreveRegBin(arq,regMaior);
                
        fseek(arq, posMaior * REG_TAM, SEEK_SET);
        escreveRegBin(arq,reg);
        fflush(arq);
        descer(arq,posMaior,tamanho);
    
    }
    free(reg);
    if ( regMaior != reg) free(regMaior);
    free(regDir);
    free(regEsq);
}


int inserir(FILE *arq, TRegistro *reg, int tamanho) {
    tamanho++;
    fseek(arq, tamanho * REG_TAM, SEEK_SET);
    escreveRegBin(arq, reg);
    fflush(arq);
    subir(arq, tamanho);
    //printf("\nInseri %lld", reg->cpf);
    return tamanho;
}

TRegistro *buscar(FILE *arq){
    fseek(arq, REG_TAM, SEEK_SET); //poe no inicio pulando o vazio inicial 
    TRegistro *reg = leRegistroBin(arq);
    printf("\nBusca:\nRegistro = { CPF= %lld , NOME= %s, NOTA= %d}", reg->cpf, reg->nome, reg->nota);
    return reg;
}

int excluir(FILE *arq, int tamanho){
    
    fseek(arq, REG_TAM * tamanho, SEEK_SET);
    
    TRegistro *reg = leRegistroBin(arq);
    
    fseek(arq, REG_TAM, SEEK_SET);
    escreveRegBin(arq,reg);

    tamanho--;

    descer(arq,1,tamanho);

    return tamanho;
}

void imprimeHeap(FILE *arq, int tamanho){
    //FILE *arq = fopen(nomeArquivo, "rb");

    if (arq == NULL) return;

    TRegistro *reg = NULL;

    printf("\n");
    fseek(arq, REG_TAM, SEEK_SET);
    
    for (int i = 1; i <= tamanho; i++){
        TRegistro *reg = leRegistroBin(arq);
        if (reg == NULL) break;
        printf("\nRegistro %d= { CPF= %lld , NOME= %s, NOTA= %d}",i, reg->cpf, reg->nome, reg->nota);
        free(reg);
    }
}

void geraHeap(){
    int tamanho = 0;
    FILE *arq = fopen(ARQ_REG, "rb+");
    FILE *arqHeap = fopen(ARQ_HEAP, "wb+");
    
    for (int i = 0; i < QUANT_REG; i++){
        TRegistro *reg = leRegistroBin(arq);
        tamanho = inserir(arqHeap, reg, tamanho);
        free(reg);
    }
    fclose(arq); //arquivo de registros

    printf("\n\nTotal de registros inseridos no HEAP: %d", tamanho);
    fseek(arqHeap, 0, SEEK_SET); //poe no inicio  
    
    printf("\n\nHEAP: \n\n");

    imprimeHeap(arqHeap,tamanho);
    
    fclose(arqHeap);

    /* ////////////////// BUSCA E REMOCAO FUNCIONANDO
    buscar(arqHeap);

    printf("\nREMOCAO: ");

    tamanho = excluir(arqHeap,tamanho);
    fseek(arqHeap, 0, SEEK_SET);
    imprimeHeap(arqHeap, tamanho);
    */
}

/*
int main(void){
      srand(time(NULL));
    geraRegistros("output/registros.bin",QUANT_REG);
    imprimeArqBin("output/registros.bin");
    int tamanho = 0;
    FILE *arq = fopen("output/registros.bin", "rb+");
    FILE *arqHeap = fopen("output/heap.bin", "wb+");
    
    for (int i = 0; i < QUANT_REG; i++){
        TRegistro *reg = leRegistroBin(arq);
        tamanho = inserir(arqHeap, reg, tamanho);
        free(reg);
    }

    printf("\n\nTotal de registros inseridos no HEAP: %d", tamanho);

    fclose(arqHeap);
    fclose(arq);
    
    FILE *arqHeap2 = fopen("output/heap.bin", "rb+");

    imprimeHeap(arqHeap2);
    fclose(arqHeap2);
    return 0;



}*/