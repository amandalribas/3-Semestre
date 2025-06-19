#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//Retornam as posições
int pai(int i){
    return i/2;
}

int filhoEsq(int i){
    return i*2;
}

int filhoDir(int i){
    return (i*2)+1;
}

void subir(int *heap, int i){
    int j = pai(i); //posição pai 
    if (j >= 1){
        if (heap[i] > heap[j]){
            int aux = heap[i];
            heap[i] = heap[j];
            heap[j] = aux;
            subir(heap, j);
        }
    }
}

void descer(int *heap, int i, int tam){
    int esq = filhoEsq(i);
    int dir = filhoDir(i);

    int maior = i;
    if (esq <= tam && heap[esq] > heap[maior]) maior = esq;
    if (dir <= tam && heap[dir] > heap[maior]) maior = dir;

    if (maior != i){
        int aux = heap[i];
        heap[i] = heap[maior];
        heap[maior] = aux;
        descer(heap, maior, tam);
    }

}

int inserir(int *heap, int valor, int tam){
    tam++;
    if (tam <=MAX){
        heap[tam] = valor;
        subir(heap, tam);
    }else printf("\n NAO foi possivel inserir, heap cheio.");

    
    return tam;
}

int remover(int *heap, int tam){ //remove do topo (prioridade)
    heap[1] = heap[tam];
    tam--;

    descer(heap, 1, tam);
    return tam;
}

void printHeap(int *heap, int tam){
    for (int i = 1; i <=tam;i++) 
        printf("%d\t", heap[i]);
}

int main(void){
    int *heap;
    int tam, novo, quant;
    tam = 0;
    heap = (int*)malloc(sizeof(int)*(MAX+2)); //vetor começa no 1
    do{
        printf("\nDigite o Valor para INSERIR: ");
        scanf("%d", &novo);
        tam = inserir(heap, novo, tam);
        printf("HEAP ATUAL: ");
        printHeap(heap, tam);
    }while(tam<MAX);

    printf("\nDigite quantos valores deseja REMOVER: ");
    scanf("%d", &quant);
    for (int i = 0; i < quant; i++){
        tam = remover(heap, tam);
        printf("\nHEAP ATUAL: ");
        printHeap(heap, tam);
    }
    free(heap);
    return 1;

}