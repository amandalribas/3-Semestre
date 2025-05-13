#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Cria um Arquivo com Registro (STRINGS)
Gerar particoes TAM 20*/

#define M 20

void mergeSortedArrays(int n[], int leftIndex, int rightIndex, int m){
    int leftLenght = m - leftIndex + 1;
    int rightLenght = rightIndex - m;

    int leftArray[leftLenght];
    int rightArray[rightLenght];
    
    for (int i = 0; i < leftLenght; i++)
        leftArray[i] = n[leftIndex + i];

    for (int i = 0; i < rightLenght; i++)
        rightArray[i] = n[m + 1 + i];

    for (int i = 0, j = 0, k = leftIndex; k <= rightIndex; k++){
        if((i<leftLenght)&&(j>=rightLenght || leftArray[i]<=rightArray[j])){
            n[k] = leftArray[i];
            i++;
        }else{
            n[k] = rightArray[j];
            j++;
        }
    }
}

void mergeSortRecursion(int n[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex){
        int m = leftIndex + (rightIndex - leftIndex) / 2;
        mergeSortRecursion(n,leftIndex,m);
        mergeSortRecursion(n,m+1, rightIndex);
        mergeSortedArrays(n, leftIndex, rightIndex, m);
    }

}

void mergeSort(int n[]){
    mergeSortRecursion(n,0,M-1);
}

int main(void){
    FILE *arquivo;
    FILE *novoArquivo; //Vai conter o nome do Arquivo de Registro Atual
    //FILE **registros;
    char nomeArquivoParticao[20];
    char s[11]; //1 cpf
    int valores[M]; //array de int com ate 20 cps
     
    int contadorParticoes = 0;



    arquivo = fopen("registro.txt", "r");
    if (arquivo!=NULL){
        printf("LENDO ARQUIVOS...");
        sprintf(nomeArquivoParticao, "registro%d.txt", contadorParticoes);

        contadorParticoes++;

        for (int i = 0; i < M; i++){
            fscanf(arquivo,"%s", s);
            valores[i] = atoi(s);
        }

        mergeSort(valores);
        novoArquivo = fopen(nomeArquivoParticao, "w");
        for (int i = 0; i < M; i++){
            fprintf(novoArquivo,"%d\n", valores[i]);
        }
        fclose(novoArquivo);

        fclose(arquivo);
        return 0;
    }
    printf("ERRO AO ABRIR ARQUIVO!");
    return 1;

}