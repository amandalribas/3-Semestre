#include <stdio.h>
#include <stdlib.h>

typedef struct vizinhos{
    int idVizinho;
    struct vizinhos *proximo;
}TVizinho;

typedef struct grafos{
    int idVertice;
    struct grafos *proximo;
    TVizinho *primeiroVizinho;
}TGrafo;

void imprime(TGrafo *grafo){
    while (grafo != NULL){
        printf("\nVertice: %d", grafo->idVertice);
        printf("\tVizinhos: ");
        TVizinho *vizinho = grafo->primeiroVizinho;
        while(vizinho != NULL){
            printf("%d... ", vizinho->idVizinho);
            vizinho = vizinho->proximo;
        }
        grafo = grafo->proximo;
    }
}

TGrafo* inicializa(){
    return NULL;
}

/*FREE*/
void liberaVizinho(TVizinho *vizinho){
    while (vizinho != NULL){
        TVizinho *aux = vizinho;
        vizinho = vizinho->proximo;
        free(aux);
    }
}

void liberaGrafo(TGrafo *grafo){
    while (grafo != NULL){
        liberaVizinho(grafo->primeiroVizinho);
        TGrafo *g = grafo;
        grafo = grafo->proximo;
        free(g);
    }
}

TGrafo* buscaVertice(TGrafo *grafo, int vertice){
    while(grafo != NULL && grafo->idVertice != vertice){
        grafo = grafo->proximo;
    }
    return grafo;
}

TVizinho* buscaAresta(TGrafo *grafo, int v1, int v2){
    TGrafo *g1 = buscaVertice(grafo, v1);
    TGrafo *g2 = buscaVertice(grafo, v2);
    TVizinho *atual = NULL;
    if(g1 != NULL && g2 != NULL){
        atual = g1->primeiroVizinho;
        while(atual && atual->idVizinho != v2){
            atual = atual->proximo;
        }
    }
    return atual;
}

TGrafo* insereVertice(TGrafo *grafo, int vertice){
    TGrafo *g = buscaVertice(grafo, vertice);
    if (g == NULL){
        g = (TGrafo*)malloc(sizeof(TGrafo));
        g->proximo = grafo;
        g->idVertice = vertice;
        g->primeiroVizinho = NULL;
        grafo = g;
    }
    return grafo;
}

void insereUmSentido(TGrafo *grafo, int v1, int v2){
    TGrafo *g1 = buscaVertice(grafo, v1);
    TVizinho *v = (TVizinho*)malloc(sizeof(TVizinho));
    v->idVizinho = v2;
    v->proximo = g1->primeiroVizinho;
    g1->primeiroVizinho = v;
}

//GRAFO NAO ORIENTADO: ARESTA = {v1, v2}
void insereAresta(TGrafo *grafo, int v1, int v2){
    TVizinho *v = buscaAresta(grafo, v1, v2);
    if (v == NULL){
        insereUmSentido(grafo,v1,v2);
        insereUmSentido(grafo,v2,v1);
    }
}

//DIGRAFO (GRAFO ORIENTADO): ARESTA = (v1,v2)
/*
void *insereAresta(TGrafo *grafo, int v1, int v2){
    TVizinho *g = buscaAresta(grafo,v1,v2);
    if(g != NULL)
        insereUmSentido(grafo,v1,v2);
}
*/

void retiraEmUmSentido(TGrafo *grafo, int v1, int v2){
    TGrafo *g = buscaVertice(grafo,v1);
    TVizinho *atual = g->primeiroVizinho;
    TVizinho *anterior = NULL;
    while (atual!= NULL && atual->idVizinho != v2){
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual->idVizinho == v2){
        if (anterior != NULL)
            anterior->proximo = atual->proximo;
        else //Era o primeiro da lista
            g->primeiroVizinho = atual->proximo;
        free(atual);
    }
    
}

//GRAFO NAO ORIENTADO: ARESTA = {v1,v2}
void retiraAresta(TGrafo *grafo, int v1, int v2){
    TVizinho *v = buscaAresta(grafo,v1,v2);
    if (v != NULL){
        retiraEmUmSentido(grafo, v1, v2);
        retiraEmUmSentido(grafo,v2,v1);
    }
}

//GRAFO ORIENTADO (DIGRAFO): ARESTA = (v1,v2)
/*
void retiraAresta(TGrafo *grafo, int v1, int v2){
    TGrafo *g = buscaAresta(grafo, v1, v2);
    if (g!= NULL)
        retiraEmUmSentido(grafo,v1,v2);
}*/

TGrafo* retiraVertice(TGrafo *grafo, int vertice){
    TGrafo *g = buscaVertice(grafo, vertice);
    if (g == NULL) return g;
    TVizinho *v = g->primeiroVizinho;
    while (v != NULL){
        TVizinho *prox = v->proximo;
        retiraAresta(grafo,v->idVizinho, vertice);
        //v = v->proximo;
        v = prox;
    }
    liberaVizinho(g->primeiroVizinho);
    
    TGrafo *atual = grafo;
    TGrafo *anterior = NULL;
    while (atual != NULL && atual->idVertice != vertice){
        anterior = atual;
        atual = atual->proximo;
    }
    if (anterior == NULL)
        grafo = atual->proximo;
    else 
        anterior->proximo = atual->proximo;
    free(atual);
    return grafo;
}

int main(void){
    TGrafo *grafo = inicializa();
    grafo = insereVertice(grafo,1);
    grafo = insereVertice(grafo,2);

    insereAresta(grafo,1,2);
    grafo = insereVertice(grafo,3);
    grafo = insereVertice(grafo,4);
    grafo = insereVertice(grafo,5);
    grafo = insereVertice(grafo,6);

    insereAresta(grafo,2,6);
    insereAresta(grafo,1,3);

    imprime(grafo);

    printf("\n");
    grafo = retiraVertice(grafo,1);
    imprime(grafo);
    return 0;
}
