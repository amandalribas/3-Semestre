#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 20

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
    int j = pai(i);
    if (j >=1){
        if (heap[i] < heap[j]){
            int aux = heap[i];
            heap[i] = heap[j];
            heap[j] = aux;
            subir(heap,j);
        }
    }

}

void descer(int *heap, int i, int tam){
    int iEsq = filhoEsq(i);
    int iDir = filhoDir(i);
    int iMenor = i;
    if (iEsq <= tam && heap[iEsq] < heap[i]) iMenor = iEsq;
    if (iDir <= tam && heap[iDir] < heap[iMenor]) iMenor = iDir;
    
    if (iMenor != i){
        int aux = heap[i];
        heap[i] = heap[iMenor];
        heap[iMenor] = aux;
        descer(heap, iMenor, tam);
    }
}

int inserir(int *heap, int i, int tam){
    tam++;

    if (tam >= TAM_MAX){
        printf("\nHEAP CHEIO. IMPOSSIVEL INSERIR!");
        tam--;
        return tam; //IMPOSSIVEL INSERIR
    } 
    heap[tam] = i;
    subir(heap,tam);
    return tam;
}

int remover(int *heap, int tam){
    heap[1] = heap[tam];
    tam--;
    descer(heap,1,tam);
    return tam;
}

void constroiHeapMinimo(int *heap, int tam){
    int j=(tam/2);
    for(int i=j;i>=1;i--)
        descer(heap, i, tam);
}


void printarHeap(int *heap, int tam){
    for (int i = 1; i <= tam; i++){
        printf("***%d***", heap[i]);
    }printf("\n");
}

void heapSort(int *heap, int tam){
    int i;
    int j=tam;
    constroiHeapMinimo(heap, tam);
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
    //int *heap;
    //heap = (int*)malloc(sizeof(int)*(TAM_MAX+2));
    int heap[TAM_MAX];
    int tam = 0;
    tam = inserir(heap,5,tam);
    tam = inserir(heap,10,tam);
    tam = inserir(heap,13,tam);
    tam = inserir(heap,2,tam);
    tam = inserir(heap,7,tam);
    tam = inserir(heap,14,tam);
    tam = inserir(heap,1,tam);
    printarHeap(heap, tam);

    tam = remover(heap,tam);
    printarHeap(heap,tam);

    tam = remover(heap,tam);
    printarHeap(heap,tam);

    tam = remover(heap,tam);
    printarHeap(heap,tam);
    printf("\n\n");
    int vetor[] = {-1,6,8,23,7,42,19,1,4,2,11};
    constroiHeapMinimo(vetor,10);
    printarHeap(vetor,10);
    heapSort(vetor,10);
    printarHeap(vetor,10);
    return 0;
}