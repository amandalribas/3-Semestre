#include <stdio.h>
#include <stdlib.h>

#define F 4


typedef struct vencedores{
    int vencedor;
    struct vencedores *endVencedor;
    FILE *f;
    struct vencedores *esquerda;
    struct vencedores *direita;
}TVencedores;

typedef struct lista{
    TVencedores *no;
    struct lista *proximo;
}TLista;

TLista* append(TLista *lista, TVencedores *no){ //Insere no Inicio
    TLista *novo = (TLista*)malloc(sizeof(TLista));
    novo->no = no;
    if (lista == NULL){
        novo->proximo = NULL;        
    }else{
        novo->proximo = lista;
    }
    lista = novo;
    return lista;
}


void Intercalacao(char **nomeArquivos, int quantidadeArquivos, char *nomeArquivoSaida){
    TLista *listaNos = (TLista*)malloc(sizeof(TLista));
    for (int i = 0; i < quantidadeArquivos; i++){
        FILE *arquivoAtual = fopen(nomeArquivos[0],"r");
        if(fscanf(arquivoAtual,"%lld",&valor))
            listaNos = append(listaNos,);
    }

}

/*
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
*/