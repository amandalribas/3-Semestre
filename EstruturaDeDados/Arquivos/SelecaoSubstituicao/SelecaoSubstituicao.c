#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dado{
    long long int info;
    int congelado;
}TDado;


#define M 20
#define MAX 999999999999LL



int menorChave(TDado *array){
    int iMenor = -1;

    for (int i = 0; i < M; i++){
        if (!array[i].congelado) {
            if (iMenor == -1 || array[i].info < array[iMenor].info)
                iMenor = i;
        }
    }
    return iMenor;
}

int selecaoSubstituicao(char *nomeArquivo){
    TDado array[M];
    FILE *arquivo = fopen(nomeArquivo, "r");
    FILE *novoArquivo;
    long long int infoAtual, contadorParticoes = 0;
    char nomeNovoArquivo[40];
    int iMenor;
    //1. Ler M registros do arquivo para a memória
    if (arquivo){
        for (int i = 0; i < M && fscanf(arquivo, "%lld", &infoAtual)==1; i++){
                array[i].info = infoAtual;
                array[i].congelado = 0;
            }
            while (!feof(arquivo)){
                contadorParticoes++;
                sprintf(nomeNovoArquivo, "particao%d.txt", contadorParticoes);
                novoArquivo = fopen(nomeNovoArquivo,"w");
                if(novoArquivo){
                    do{

                        //2. Selecionar, no array em memória, o registro r com menor chave
                        iMenor = menorChave(array);
                        if (iMenor == -1) break;

                        //3. Gravar o registro r na partição de saída
                        fprintf(novoArquivo, "%lld\n", array[iMenor].info);
                        if (fscanf(arquivo,"%lld", &infoAtual) == 1){
                            if (infoAtual < array[iMenor].info) //5.Caso a chave deste último seja menor do que a chave recém gravada, considerá-lo congelado
                                array[iMenor].congelado = 1;
                            array[iMenor].info = infoAtual;
                        }else{
                            array[iMenor].info = MAX;
                            array[iMenor].congelado = 1;
                        } 
                    }while(1);
                    fclose(novoArquivo);
                    for (int i = 0; i < M; i++) array[i].congelado = 0;
                    }
            }
        fclose(arquivo);
    }
    return contadorParticoes;

}



int main (void){
    int particoes = selecaoSubstituicao("registro.txt");
    printf("%d Particoes Realizadas", particoes);
    return 0;

}

/*
1. Ler M registros do arquivo para a memória
2. Selecionar, no array em memória, o registro r com menor chave
3. Gravar o registro r na partição de saída
4. Substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
5. Caso a chave deste último seja menor do que a chave recém gravada, considerá-lo congelado
e ignorá-lo no restante do processamento
6. Caso existam em memória registros não congelados, voltar ao passo 2
7. Caso contrário:
    fechar a partição de saída
    descongelar os registros congelados
    abrir nova partição de saída
    voltar ao passo 2

Em média, o tamanho das partições obtidas pelo processo de seleção com substituição é de 2 * M
    */
