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
    if (j >= 1){ //se nao for raiz
        if (heap[i] > heap[j]){ //se o filho for maior que o pai
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
    //pega o maior filho
    if (esq <= tam && heap[esq] > heap[maior]) maior = esq;
    if (dir <= tam && heap[dir] > heap[maior]) maior = dir;

    if (maior != i){ //se o maior for diferente do que si mesmo
        int aux = heap[i];
        heap[i] = heap[maior]; 
        heap[maior] = aux;
        descer(heap, maior, tam);
    }
    //troca com o maior filho

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

void constroiHeapMaximo(int *heap, int tam){
    int j = (tam/2);
    for (int i = j; i >= 1; i--)
        descer(heap,i,tam);

}

void heapSort(int *heap, int tam){
    int i;
    int j=tam;
    constroiHeapMaximo(heap, tam);
    for(i=tam;i>1;i--){
        //troca raiz com o ultimo elemento (posicao j)
        int aux=heap[i];
        heap[i]=heap[1];
        heap[1]=aux;
        //diminui o tamanho do vetor a ser considerado na heep
        j--;
        //desce com a raiz nessa nova heap de tamanho j-1
        descer(heap, 1, j);
    }
}


int main(void){
    int vetor[] = {-1,1,2,3,4,5,6,7,8,9,10}; //termo 0 tem que ficar vazio
    int tam = 10;
    constroiHeapMaximo(vetor,tam);
    printf("\nHeap MAXIMO: ");
    printHeap(vetor,tam);
    heapSort(vetor, tam);
    printf("\nHeap SORT:");
    printHeap(vetor,tam);
    /*int *heap;
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
    free(heap);*/
    return 0;

}
