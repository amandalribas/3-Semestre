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

void sobe(FILE *arq, int posicao){
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
            sobe(arq,posPai);
        }
        free(reg);
        free(regPai);
    }
}

void desce(FILE *arq, int posicao, int tamanho){ //se ja tiver removido antes, o TAM é menor que QUANT_REG
    
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
        desce(arq,posMaior,tamanho);
    
    }
    free(reg);
    if ( regMaior != reg) free(regMaior);
    free(regDir);
    free(regEsq);
}


int insereHeap(FILE *arq, TRegistro *reg, int tamanho) {
    tamanho++;
    fseek(arq, tamanho * REG_TAM, SEEK_SET);
    escreveRegBin(arq, reg);
    fflush(arq);
    sobe(arq, tamanho);
    //printf("\nInseri %lld", reg->cpf);
    return tamanho;
}

TRegistro *buscaHeap(FILE *arq){
    fseek(arq, REG_TAM, SEEK_SET); //poe no inicio pulando o vazio inicial 
    TRegistro *reg = leRegistroBin(arq);
    printf("\nBusca:\nRegistro = { CPF= %lld , NOME= %s, NOTA= %d}", reg->cpf, reg->nome, reg->nota);
    return reg;
}

int excluiHeap(FILE *arq, int tamanho){
    
    fseek(arq, REG_TAM * tamanho, SEEK_SET);
    
    TRegistro *reg = leRegistroBin(arq);
    
    fseek(arq, REG_TAM, SEEK_SET);
    escreveRegBin(arq,reg);

    tamanho--;

    desce(arq,1,tamanho);

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
        tamanho = insereHeap(arqHeap, reg, tamanho);
        free(reg);
    }
    fclose(arq); //arquivo de registros

    printf("\n\nTotal de registros inseridos no HEAP: %d", tamanho);
    fseek(arqHeap, 0, SEEK_SET); //poe no inicio  
    
    printf("\n\nHEAP: \n\n");

    imprimeHeap(arqHeap,tamanho);
    
    fclose(arqHeap);

    /* ////////////////// BUSCA E REMOCAO FUNCIONANDO
    buscaHeap(arqHeap);

    printf("\nREMOCAO: ");

    tamanho = excluiHeap(arqHeap,tamanho);
    fseek(arqHeap, 0, SEEK_SET);
    imprimeHeap(arqHeap, tamanho);
    */
}

void geraBuscaHeap(){
    FILE *arqHeap = fopen(ARQ_HEAP, "rb+");
    TRegistro *reg = buscaHeap(arqHeap);
    free(reg);
    fclose(arqHeap);
}

void geraExcluiHeap() {
    FILE *arqHeap = fopen(ARQ_HEAP, "rb+");
    if (!arqHeap) {
        printf("\nErro ao abrir arquivo heap!\n");
        return;
    }

    fseek(arqHeap, 0, SEEK_END);
    int tamanho = (ftell(arqHeap) / REG_TAM) - 1;
    rewind(arqHeap);

    if (tamanho <= 0) {
        printf("\nHeap vazio - nada para remover!\n");
        fclose(arqHeap);
        return;
    }

    fseek(arqHeap, REG_TAM, SEEK_SET); 
    TRegistro *topo = leRegistroBin(arqHeap);
    printf("\nRemovendo registro:\n{ CPF= %lld, NOME= %s, NOTA= %d }", topo->cpf, topo->nome, topo->nota);
    free(topo);

    tamanho = excluiHeap(arqHeap, tamanho);

    printf("\n\nHeap apos remoção (tamanho: %d):", tamanho);
    imprimeHeap(arqHeap, tamanho);

    fclose(arqHeap);
}

void geraInsereHeap() {
    FILE *arqHeap = fopen(ARQ_HEAP, "rb+");
    if (!arqHeap) {
        
        arqHeap = fopen(ARQ_HEAP, "wb+");
        if (!arqHeap) {
            printf("\nErro ao criar arquivo heap!\n");
            return;
        }
   
        TRegistro *vazio = preencheReg(-1, -1, "");
        escreveRegBin(arqHeap, vazio);
        free(vazio);
    }

    
    fseek(arqHeap, 0, SEEK_END);
    int tamanho = (ftell(arqHeap) / REG_TAM) - 1;  
    rewind(arqHeap);

    TRegistro novoReg;
    printf("\nDigite o CPF: ");
    scanf("%lld", &novoReg.cpf);
    
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome: ");
    fgets(novoReg.nome, sizeof(novoReg.nome), stdin);
    novoReg.nome[strcspn(novoReg.nome, "\n")] = '\0'; 
    
    printf("Digite a nota: ");
    scanf("%d", &novoReg.nota);

    TRegistro *reg = preencheReg(novoReg.cpf, novoReg.nota, novoReg.nome);
    tamanho = insereHeap(arqHeap, reg, tamanho);
    free(reg);

    printf("\nRegistro inserido com sucesso!");
    printf("\n\nHeap atualizado (tamanho: %d):", tamanho);
    imprimeHeap(arqHeap, tamanho);

    fclose(arqHeap);
}