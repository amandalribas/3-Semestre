#include <stdio.h>
#include <stdlib.h>

#define F 4

typedef struct No{
    int vencedor; //valor da menor chave daquela sub-árvore
    struct No *endVencedor; //ponteiro para o nó folha que tem aquela chave
    FILE *f; //variável FILE atrelada ao arquivo do vencedor
    struct No *esquerda;
    struct No *direita;
}TNo;

typedef struct listaNo{
    TNo *folha;
    struct listaNo *proximo;
}TLista;

TLista* append(TLista *lista, TNo *no){ 
    TLista *novo = (TLista*)malloc(sizeof(TLista));
    novo->folha = no;
    novo->proximo = NULL;
    if (lista == NULL){
        return novo;
    }else{
        TLista *atual = lista;
        while (atual != NULL)
            atual = atual->proximo;
        atual->proximo = novo;
    }
    
    return lista;
}

TLista* remove(TLista *lista){
    TLista *atual = lista;
    if (lista!=NULL)
        lista = lista->proximo;
    free(atual);
    return lista;
}

TNo* criaNo(FILE *arquivo){
    TNo *novo = (TNo*)malloc(sizeof(TNo));
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->endVencedor = NULL;
    fscanf(arquivo, "%d", &novo->vencedor);
    novo->f = arquivo;
    return novo;
}

TNo* criaNoArvore(TNo *direita, TNo *esquerda){
    TNo *atual;
    
    atual = (TNo*)malloc(sizeof(TNo));
    atual->direita = direita;
    atual->esquerda = esquerda;

    if(esquerda->vencedor > direita->vencedor){
        atual->vencedor = direita->vencedor;
        atual->f = direita->f;
        atual->endVencedor = direita;
    }else{
        atual->vencedor = esquerda->vencedor;
        atual->f = esquerda->f;
        atual->endVencedor = esquerda;
    }
    return atual;
}

char** criaListaArquivos(int quantidade){
    char **lista = malloc(sizeof(char)*quantidade);
    for (int i = 1; i <= quantidade; i++){
        lista[i] = malloc(sizeof(char)*quantidade);
        sprintf(lista[i],"particao%d.txt",i);    
    }
    return lista;
}

TNo* criaArvoreVencedores(char **listaArquivos, int quantidade, char *nomeSaida){
    TLista *lista = NULL;
    FILE **arquivos;
    int quant = quantidade;
    for (int i = 0; i < quantidade; i++){
        arquivos[i] = fopen(listaArquivos[i],"r");
        TNo *noAtual = criaNo(arquivos[i]);
        lista = append(lista, noAtual);
    }

    TNo *p = NULL;
    while (quant > 1){
        p = criaNoArvore(lista, lista->proximo);
        lista = remove(lista);
        lista = remove(lista);
        lista = append(lista, p);
        quant =- 2;
    }
    
    //Fechando Arquivos
    for (int i = 0; i < quantidade; i++){
        fclose(arquivos[i]);
    }
    free(arquivos);
    return p;
}

void intercalacao(int numParticoes){
    

}

int main(void){

    return 0;
}

/*
MONTAGEM ARVORE DOS VENCEDORES:
Entrada:
Lista com os nomes dos arquivos de partições (entrada)
Quantidade de arquivos de entrada
Nome do arquivo de saída
Algoritmo:
1. Criar uma lista de nós vazia
2. Criar nós folha da árvore, e adicioná-los na lista
3. Enquanto lista tiver mais de 1 elemento:
    1. Retirar os 2 primeiros nós da lista
    2. Criar um nó p para ser o pai desses dois, escolhendo o vencedor e ajustando os campos do nó criado de acordo
    3. Adicionar p no final da lista
4. O elemento que sobrou na lista é a raiz da árvore de vencedores

INTERCALACAO OTIMA:

. Criar uma lista com os nomes dos arquivos a intercalar
2. Enquanto houver mais de 1 arquivo na lista
1. Retirar os F-1 primeiros itens da lista e intercalá-los
2. Colocar o arquivo resultante no final da lista
3. O arquivo que sobrar na lista será o arquivo resultante (arquivo completo
que contém todos os registros)
*/