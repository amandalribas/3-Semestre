#include <stdio.h>
#include <stdlib.h>

int *criaHeap(int tamMax){
    int *heap = (int*)malloc((tamMax+1)* sizeof(int));
    return heap;
}


void sobe(int *heap, int posicao){
    int posPai = posicao/2;
    if (posPai >= 1){        
        if (heap[posPai] < heap[posicao]){ //pai é menor que o filho
            int aux = heap[posicao];
            heap[posicao] = heap[posPai];
            heap[posPai] = aux;
            sobe(heap, posPai);
        }
    }
}


void desce(int *heap, int posicao, int lenght){
    int posEsq = posicao*2;
    int posDir = posicao*2 + 1;

    int maior = posicao;

    if ((posEsq <= lenght)&&(heap[posEsq] > heap[maior])) maior = posEsq; 
    if ((posDir <= lenght)&& (heap[posDir] > heap[maior])) maior = posDir;

    if (heap[posicao] < heap[maior]){ //troca com um dos filhos
        int aux = heap[posicao];
        heap[posicao] = heap[maior];
        heap[maior] = aux;
        desce(heap, maior, lenght);
    }
}

int insere(int *heap,int elemento, int lenght){
    lenght++;
    heap = (int *)realloc(heap, sizeof(int) * (lenght + 1));
    heap[lenght] = elemento;

    sobe(heap, lenght);
    return lenght;
}

void printHeap(int *heap, int lenght){
    for (int i = 0; i<=lenght;i++)
        printf("%d", heap[i]);
}

int main(void){
    int *heap = criaHeap(10);
    int tamPrenchido = insere(heap,5,0);
    printHeap(heap, tamPrenchido);    
    return 0;
}

/*COMPLEXIDADE:
    BUSCA: O(1)
    INSERÇÃO: O(logN) 
    REMOÇÃO:    
    
    -   chave(prioridade do pai é maior [menor] do que dos seus filhos)   
    -   todas as folhas no ultimo ou penultimo nível;
    -   representação por vetor, na qual posição dos filhos é 2i e 2i + 1 (começa do 1);
    */
