#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Cria um Arquivo com Registro (STRINGS)
Gerar particoes TAM 20*/

#define M 20

int comparaLongLong(const void *a, const void *b){
    long long int val1 = *(const int long long *)a;
    long long int val2 = *(const int long long *)b;
    if(val1 < val2) return -1;
    if(val1 > val2) return 1;
    return 0; 
}

int ClassificacaoInteira(char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");
    FILE *novoArquivo;
    char nomeNovoArquivo[20];
    long long int valores[M];

    int contadorParticoes = 0;
    if(arquivo){
        while (!feof(arquivo)){
            
            for (int i = 0; i < M; i++){
                fscanf(arquivo,"%lld", &valores[i]);
            }

            sprintf(nomeNovoArquivo, "registro%d.txt", contadorParticoes);
            contadorParticoes++;

            qsort(valores,M,sizeof(long long int),comparaLongLong);
            novoArquivo = fopen(nomeNovoArquivo, "w");

            for (int i = 0; i < M; i++){
                fprintf(novoArquivo,"%lld\n", valores[i]);
            }
            fclose(novoArquivo);
        }
        fclose(arquivo);
    }
    return contadorParticoes;
}

int main(void){
    char nomeArquivo[20];
    printf("Digite o nome do Arquivo: ");
    scanf("%s", nomeArquivo);
    
    int particoes = ClassificacaoInteira(nomeArquivo);
    printf("%d Particoes Realizadas.", particoes);

    return 0;

}