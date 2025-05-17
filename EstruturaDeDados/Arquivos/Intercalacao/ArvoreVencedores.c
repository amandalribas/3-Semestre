#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    long long int vencedor; //valor da menor chave daquela sub-árvore
    struct No endVencedor;
    FILE *f; //variável FILE atrelada ao arquivo do vencedor
    struct No esquerda; //ponteiro para o filho da esquerda
    struct No direita; //ponteiro para o filho da direita
}TNo;

typedef struct listaVencedores{
    TNo *no;
    struct listaVencedores *proximo;
}TLista;

#define F 40
//quant = F - 1 (?)

TNo* criaNo(FILE *arquivo){
    long long int valor;
    fscanf(arquivo,"%lld", &valor);
    
    TNo *no = (TNo*)malloc(sizeof(TNo));
    no->vencedor = valor;
    no->endVencedor = no;
    no->esquerda = NULL;
    no->direita = NULL;
    no->f = arquivo;
    return no;
}

void append(TLista **lista, TNo *no) {
    TLista *novo = (TLista*)malloc(sizeof(TLista));
    novo->no = no;
    novo->proximo = NULL;

    if (*lista == NULL) *lista = novo;
    else {
        TLista *aux = *lista;
        while (aux->proximo != NULL) aux = aux->proximo;
        aux->proximo = novo;
    }
}

TNo *comparacao(TNo *a, TNo *b){
    TNo resultado = (TNo*)malloc(sizeof(TNo));
    if (a->vencedor < TNo *b){

    }
}

void arvoreVencedores(char **listaArquivos, int quant, char *nomeSaida){
    TLista listaNo;
    FILE *arquivoAtual;
    TNo *noAtual;
    int listaTamanho = 0;
    for (int i = 0; i <= quant; i++){
        arquivoAtual = fopen(listaArquivos[i],"r");
        noAtual = criaNo(arquivoAtual);
        append(&listaNo, noAtual);
        fclose(arquivoAtual);
        listaTamanho++;
    }
    while (listaTamanho > 1){
        if(listaTamanho % 2 == 0){
            
            listaTamanho -= 2;
        }        
    }
}

/*Entrada:
 Lista com os nomes dos arquivos de partições (entrada)
 Quantidade de arquivos de entrada
 Nome do arquivo de saída
Algoritmo:
1. Criar uma lista de nós vazia
2. Criar nós folha da árvore, e adicioná-los na lista
3. Enquanto lista tiver mais de 1 elemento:
    1. Retirar os 2 primeiros nós da lista
    2. Criar um nó p para ser o pai desses dois, escolhendo o vencedor e ajustando os campos do nó criado de acordo
    3. Adicionar p no final da lista
    4. O elemento que sobrou na lista é a raiz da árvore de vencedores
 */