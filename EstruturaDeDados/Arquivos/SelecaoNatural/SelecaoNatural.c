#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define M 20

int menorChave(long long int *array, int iArray){  
    int iMenor = -1;
    for (int i = 0; i < iArray; i ++){
        if (iMenor == -1 || array[i] < array[iMenor])
            iMenor = i;
    }
    return iMenor;
}

int SelecaoNatural(char *nomeArquivo){
    long long int array[M];
    long long int reservatorio[M];

    int contadorParticoes = 0;
    int iMenor, iReservatorio = 0, iArray = 0;

    FILE *arquivo = fopen(nomeArquivo,"r");
    FILE *novoArquivo;
    char nomeNovoArquivo[40];
    long long int valorAtual;
    if(arquivo){
        for (iArray = 0; iArray < M && fscanf(arquivo, "%lld", &valorAtual)==1;iArray++){
            array[iArray] = valorAtual;
        }
        while(!feof(arquivo)){
            contadorParticoes++;
            sprintf(nomeNovoArquivo,"particao%d.txt",contadorParticoes);
            novoArquivo = fopen(nomeNovoArquivo,"w");
            
            while(!feof(arquivo)){
                iMenor = menorChave(array, iArray);
                fprintf(novoArquivo,"%lld\n",array[iMenor]);

                if(fscanf(arquivo, "%lld", &valorAtual) == 1){
                    if (valorAtual < array[iMenor] && iReservatorio < M){
                        reservatorio[iReservatorio] = valorAtual;
                        iReservatorio++;
                        if (iMenor != iArray - 1)
                            array[iMenor] = array[iArray-1];
                        iArray--;
                    }else{
                        array[iMenor] = valorAtual;
                    }
                }else{
                    if (iMenor != iArray - 1)  // troca só se índices diferentes
                        array[iMenor] = array[iArray-1];
                    iArray--;
                }

                if (iReservatorio == M) break;
            }
            fclose(novoArquivo);
            for (int i = 0; i < iReservatorio; i++)
                array[i] = reservatorio[i];
            iArray = iReservatorio;
            iReservatorio = 0;
        }
        
        fclose(arquivo);
    }
    return contadorParticoes;
}

int main(void){
    int particoes =SelecaoNatural("registro.txt");
    printf("Particoes %d", particoes);
    return 0;
}




/*Ler M registros do arquivo para a memória
2. Selecionar, no array em memória, o registro r com menor chave
3. Gravar o registro r na partição de saída
4. Substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
5. Caso a chave deste último seja menor do que a chave recém gravada, gravá-lo no
reservatório e substituir, no array em memória, o registro r pelo próximo registro do
arquivo de entrada
6. Caso ainda exista espaço livre no reservatório, voltar ao passo 2
7. Caso contrário:
    fechar a partição de saída
    copiar os registros do reservatório para o array em memória
    esvaziar o reservatório
    abrir nova partição de saída
    voltar ao passo 2*/