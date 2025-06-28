#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <time.h>

#define TAM_ARQTXT 80

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
    
    int tamanho = strlen(nome) + strlen(sobrenome1) + strlen(sobrenome2) + 3 + 1;
    char *nomeCompleto = malloc(tamanho);
    snprintf(nomeCompleto, tamanho, "%s %s %s", nome, sobrenome1, sobrenome2);

    printf("\nNOME GERADO: %s", nomeCompleto);

    return nomeCompleto;

}

int main(void){
    srand(time(NULL));
    long long int cpf = geraCPF();
    float nota = geraNota();
    char **nomes = leArquivoTexto("nomes.txt");
    char **sobrenomes = leArquivoTexto("sobrenomes.txt");
    
    char **nome = geraNome(nomes,sobrenomes);
    /*printf("\nNomes:");
    imprimeVetor(nomes);
    printf("\nSobrenomes:");
    imprimeVetor(sobrenomes);*/
    return 0;
}