#include "hash.h"


int h(int x, int k){
    srand(x);
    return ((rand()*2654435761U) + k) % M; //2654435761U multiplicador p manter uniforme  
}
/*
int h(){ //se der srand dentro do h vai sempre sair o mesmo numero, reinicia a seed
    return (rand() * 2654435761U) % M;  
}*/

void inicilizaHash(FILE *arq){
    int vazio = -1;
    long long int llvazio = -1;
    char nomeVazio[50] = "";
    TRegistro *reg = preencheReg(llvazio, vazio, nomeVazio);    
    for (int i = 0; i < M; i++){
        escreveRegBin(arq,reg);
    }
}


int buscaHash(FILE *arq, int chaveCPF) {
    int posicao, k = 0;
    TRegistro *atual = NULL;

    do {
        posicao = h(chaveCPF, k);
        fseek(arq, posicao * REG_TAM, SEEK_SET);
        
        // Libera registro anterior se existir
        if (atual != NULL) {
            free(atual);
        }
        
        atual = leRegistroBin(arq);
        
        // Verifica se o registro é válido e se corresponde ao CPF buscado
        if (atual != NULL && atual->cpf != -1 && geraChaveCPF(atual->cpf) == chaveCPF) {
            free(atual);
            return posicao;  // encontrou
        }

        k++;
    } while (atual != NULL && atual->cpf != -1 && k < M);

    // Libera memória antes de retornar
    if (atual != NULL) {
        free(atual);
    }
    
    return -1;  // não encontrou
}


void insereHash(FILE *arq, TRegistro *reg){
    int chaveCPF = geraChaveCPF(reg->cpf);
    if (buscaHash(arq,chaveCPF) != -1) return;
       
    int posicao, k = 0;
    TRegistro *atual;
    //srand(chaveCPF);
    do {
        posicao = h(chaveCPF, k);
        //posicao = h();
        fseek(arq, posicao * REG_TAM, SEEK_SET);
        atual = leRegistroBin(arq);
        k++;
    } //while (atual->cpf != -1);
    while (atual->cpf != -1 && k < M);
    if(atual->cpf == -1){
        fseek(arq, posicao*REG_TAM, SEEK_SET);
        escreveRegBin(arq,reg);
        ///printf("\nInseri %lld", reg->cpf);
    }else printf("\nERRO! Tabela preenchida.");
    
}

int excluiHash(FILE *arq, int chaveCPF){
    int posicao = buscaHash(arq,chaveCPF);
    if (posicao == -1 ){
        printf("\nERRO! %lld nao esta no HASH.", chaveCPF);
        return -1; // o cpf nao esta entre os registros
    }
    fseek(arq, posicao*REG_TAM, SEEK_SET);
    TRegistro *vazio = preencheReg(-1,-1,"");
    escreveRegBin(arq,vazio);
    printf("\n%dRemovido na %d", chaveCPF, posicao);
    return posicao;
}

void imprimeHash(FILE *arq){
    int j = 0;
    TRegistro *reg = NULL;
    for (int i = 0; i < M; i++){
        fseek(arq, i* REG_TAM, SEEK_SET);
        reg = leRegistroBin(arq);
        if (reg->cpf != -1 && reg->cpf != 0){
            printf("\nRegistro %d = { CPF= %lld , NOME= %s, NOTA= %d}", i, reg->cpf, reg->nome, reg->nota);
            j++;
        }
    }
    //printf("\n%d Registros Inseridos", j);
}


void geraHash(){
    FILE *arq = fopen(ARQ_REG, "rb+");
    FILE *arqHash = fopen(ARQ_HASH, "wb+");

    inicilizaHash(arqHash);
    //imprimeHash(arqHash);

    for (int i = 0; i < QUANT_REG; i++){
        TRegistro *reg = leRegistroBin(arq);
        insereHash(arqHash, reg);
    }
    fclose(arq);
    
    printf("\n\nHASH: \n\n");
    imprimeHash(arqHash);
    
    /* Testando busca
    int chaveCPF = geraChaveCPF(23441268150);
    int pos = buscaHash(arqHash,chaveCPF);
    printf("\n%d na posicao %d", chaveCPF, pos);
    */

    /* Testando exclui
    int chaveCPF = geraChaveCPF(83900060083);
    int pos = excluiHash(arqHash,chaveCPF);
    imprimeHash(arqHash);
    */
    fclose(arqHash);
}

/*void geraInsereHash(){
    FILE *arqHash = fopen(ARQ_HASH, "wb+");

    inicilizaHash(arqHash);

    char nome[50];
    long long int cpf;
    int nota;

    printf("\nDigite o CPF a inserir: ");
    scanf("%lld", &cpf);
    printf("\nDigite o nome de %lld: ", cpf);
    scanf("%s", nome);
    printf("\nDigite a nota de %lld: ", cpf);
    scanf("%d", &nota);
    TRegistro *reg = preencheReg(cpf,nota,nome);
    insereHash(arqHash, reg);
    printf("\nInseri %d", cpf);
    //printf("\n\nHASH: \n\n");
    //imprimeHash(arqHash);
   
    fclose(arqHash);
}*/
void geraInsereHash() {
    FILE *arqHash = fopen(ARQ_HASH, "rb+");
    if (!arqHash) {
        printf("\nErro ao abrir arquivo hash!\n");
        return;
    }

    fseek(arqHash, 0, SEEK_END);
    if (ftell(arqHash) == 0) {
        inicilizaHash(arqHash);
    }
    rewind(arqHash);
    // Coleta dados do novo registro
    TRegistro novoReg;
    printf("\nDigite o CPF a inserir: ");
    scanf("%lld", &novoReg.cpf);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("Digite o nome: ");
    fgets(novoReg.nome, sizeof(novoReg.nome), stdin);
    novoReg.nome[strcspn(novoReg.nome, "\n")] = '\0'; 
    
    printf("Digite a nota: ");
    scanf("%d", &novoReg.nota);

    int chave = geraChaveCPF(novoReg.cpf);
    if (buscaHash(arqHash, chave) != -1) {
        printf("\nERRO: CPF %lld já existe na tabela!\n", novoReg.cpf);
        fclose(arqHash);
        return;
    }

    // Insere o novo registro
    TRegistro *reg = preencheReg(novoReg.cpf, novoReg.nota, novoReg.nome);
    insereHash(arqHash, reg);
    free(reg);

    printf("\nRegistro inserido com sucesso!\n");
    
    //printf("\nTabela Hash atualizada:\n");
    //imprimeHash(arqHash);
    
    fclose(arqHash);
}

void geraBuscaHash(){
    FILE *arqHash = fopen(ARQ_HASH, "rb+");
    long long int cpf;
    printf("Digite o CPF a ser BUSCADO:");
    scanf("%lld", &cpf);
    int chaveCPF = geraChaveCPF(cpf);
    int pos = buscaHash(arqHash,chaveCPF);
    printf("\n%d na posicao %d", chaveCPF, pos);
    fclose(arqHash);
}

void geraExcluiHash(){
    FILE *arqHash = fopen(ARQ_HASH, "rb+");
    long long int cpf;
    printf("Digite o CPF a ser EXCLUIDO:");
    scanf("%lld", &cpf);
    int chaveCPF = geraChaveCPF(cpf);
    int pos = excluiHash(arqHash,chaveCPF);
    imprimeHash(arqHash);
    fclose(arqHash);
}