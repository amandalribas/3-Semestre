#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7

typedef struct pessoa{
    int idade;
    int matricula;
    char nome[30];
    struct pessoa *proximo_vizinho;
}TPessoa;
typedef TPessoa *Hash;

int h(int x){
    return x % 7;
}

void inicializaHash(Hash *hash){
    for (int i = 0; i < M; i++) hash[i] = NULL;
}

TPessoa *aloca(int idade, int matricula, char nome[30]){
    TPessoa *novo = (TPessoa*)malloc(sizeof(TPessoa));
    novo->idade = idade;
    novo->matricula = matricula;
    strcpy(novo->nome,nome);
    novo->proximo_vizinho = NULL;
    return novo;
}


TPessoa *busca(Hash *hash, int x){
    int posicao =  h(x); //1. Calcular o endereço aplicando a função h(x)
    TPessoa *atual = hash[posicao];
    do{
        atual = atual->proximo_vizinho; //2. Percorrer a lista encadeada associada ao endereço
    }while (atual->idade != x && atual!= NULL);
    // 3. Comparar a chave de cada nó da lista encadeada com a chave x, até encontrar o nó desejado
    //4. Se final da lista for atingido, registro não está lá */
    return atual;
}


void insere(Hash *hash, int x, int matricula, char nome[30]){
    int posicao = h(x);
    TPessoa *novo = aloca(x, matricula, nome);

    // Se a lista estiver vazia
    if (hash[posicao] == NULL) {
        hash[posicao] = novo;
        return;
    }

    TPessoa *atual = hash[posicao];

    // Verifica se o elemento já existe
    while (atual != NULL) {
        if (atual->matricula == x) {
            printf("\nERRO! O Elemento ja existe.");
            free(novo); // libera o nó alocado que não será usado
            return;
        }
        if (atual->proximo_vizinho == NULL) break; // chegamos no fim da lista
        atual = atual->proximo_vizinho;
    }

    // Inserir no final da lista
    atual->proximo_vizinho = novo;
}



void exclui(Hash *hash, int x){
    int posicao = h(x); //1. Calcular o endereço aplicando a função h(x)
    TPessoa *atual = hash[posicao]; //2. Buscar registro na lista associada ao endereço h(x)
    
    TPessoa *anterior = NULL;
    atual = hash[posicao];
    while (atual != NULL && atual->idade != x){
        anterior = atual;
        atual = atual->proximo_vizinho;
    }

    if (atual == NULL){
        printf("\nERRO! O Elemento NAO existe.");
        return;
    }

    if (anterior == NULL) hash[posicao] = atual->proximo_vizinho; //eh o primeiro elemento
    else anterior->proximo_vizinho = atual->proximo_vizinho;
    free(atual); //3. Se registro for encontrado, excluir registro

}

void imprime(Hash *hash){
    for (int i = 0; i < M; i++){
        TPessoa *atual = hash[i];
        printf("\nRegistro %d = {", i);
        while (atual != NULL){
            printf(" [Idade = %d, Matricula= %d, Nome = %s] ->", atual->idade, atual->matricula, atual->nome);
            atual = atual->proximo_vizinho;
        }
        printf(" NULL }");
    }
}

int main(void){
    Hash hash[M];
    inicializaHash(hash);
    insere(hash,19,123,"Amanda");
    insere(hash,18,345,"Lais");
    insere(hash,21,456,"Diogo");
    insere(hash,19,865,"Madu");
    insere(hash,7,999,"Mike");
    imprime(hash);

    return 0;
}

//COMPLEXIDADE NO PIOR CASO: O(n)
//Se assumirmos que o número de chaves n é proporcional ao tamanho da tabela m,  n/m = O(1)
