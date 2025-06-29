#include "geraRegistros.h"


long long int geraCPF(){
    long long int n1 = (rand()%100000) + (100000 * (rand()%7+1));
    long long int n2 = (rand()%100000) + 100000;
    long long int cpf = (n1*n2);
    printf("\nCPF GERADO: %lld", cpf);
    return cpf;
}

float geraNota(){
    float nota = (rand() % 101) / 10.0;
    printf("\nNOTA GERADA: %.1f", nota);
    return nota;
}

char **leArquivoTexto(const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo '%s'\n", nomeArquivo);
        return NULL;
    }

    char **total = malloc(TAM_ARQTXT * sizeof(char*)); 
    char s[30];
    int i = 0;

    while (fscanf(arq, "%99s", s) == 1 && i < TAM_ARQTXT) {
        total[i] = malloc(strlen(s) + 1); // aloca espaço para a string
        strcpy(total[i], s);              // copia string para posição
        i++;
    }

    fclose(arq);
    return total;
}
    
void imprimeVetor(char **nomes) {
    for (int i = 0; i < TAM_ARQTXT-1; i++) {
        printf("%s\n", nomes[i]);
    }
}

char *geraNome(char **nomes, char **sobrenomes){

    char *nome = nomes[(int)rand()%(TAM_ARQTXT-1)]; 
    //printf("\nNOME GERADO : %s", nome);
    char *sobrenome1 = sobrenomes[(int)rand()%(TAM_ARQTXT-1)]; 
    //printf("\nSOBRENOME 1 GERADO : %s", sobrenome1);
    char *sobrenome2 = sobrenomes[(int)rand()%(TAM_ARQTXT-1)]; 
    //printf("\nSOBRENOME 2 GERADO : %s", sobrenome2);
    
    static char nomeCompleto[100];
    snprintf(nomeCompleto, sizeof(nomeCompleto), "%s %s %s", nome, sobrenome1, sobrenome2);

    printf("\nNOME GERADO: %s", nomeCompleto);

    return nomeCompleto;

}

void escreveRegBin(FILE *arq, TRegistro *reg){
    if (arq == NULL) return;
    fwrite(&reg->cpf, sizeof(long long int), 1, arq);
    fwrite(&reg->nota, sizeof(float), 1, arq);
    fwrite(reg->nome, sizeof(char),sizeof(reg->nome), arq);

}


void geraRegistros(char *nomeArquivo, int quantidade){
    char **nomes = leArquivoTexto("nomes.txt");
    char **sobrenomes = leArquivoTexto("sobrenomes.txt");
    FILE *arq = fopen(nomeArquivo, "wb");
    TRegistro *reg = (TRegistro*)malloc(sizeof(TRegistro));
    for (int i = 0; i < quantidade; i++){
        printf("\n\nRegistro %d", i);
        reg->cpf = geraCPF();
        reg->nota = geraNota();
        strcpy(reg->nome, geraNome(nomes, sobrenomes));
        escreveRegBin(arq, reg);
    }
    fclose(arq);
}

TRegistro *leRegistroBin(FILE *arq){
    TRegistro *reg = (TRegistro*)malloc(sizeof(TRegistro));
    if (0 >= fread(&reg->cpf, sizeof(long long int), 1, arq)) {
        free(reg);
        return NULL;
    }
    fread(&reg->nota, sizeof(float), 1, arq);
    fread(reg->nome, sizeof(char),sizeof(reg->nome), arq);

    return reg;
}

void imprimeArqBin(char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) return;
    TRegistro *reg;
    printf("\n");
    for (int i = 0; i < QUANT_REG; i++){
        reg = leRegistroBin(arq);
        printf("\nRegistro %d= { CPF= %lld , NOME= %s, NOTA= %.1f}",i, reg->cpf, reg->nome, reg->nota);
    }
}

int main(void){
    srand(time(NULL));
    geraRegistros("registros.bin",QUANT_REG);
    imprimeArqBin("registros.bin");
    return 0;
}