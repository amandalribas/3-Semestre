#ifndef BMAIS_H
#define BMAIS_H

#include "geraRegistros.h"

#define D 2 // Ordem da árvore (número mínimo de chaves)

typedef struct bplus_node {
    int folha;
    int *chaves;
    TRegistro **registros;
    int numChaves;
    struct bplus_node **filhos;
    struct bplus_node *prox;
    struct bplus_node *pai;
} BPlusNode;

// Protótipos das funções
BPlusNode* criaNoBM(int folha);
void liberaBM(BPlusNode *root);
int buscaPosChave(BPlusNode *node, int chave);
TRegistro* buscaBM(BPlusNode *root, long long int cpf);
BPlusNode* insereBM(BPlusNode *root, TRegistro *registro);
BPlusNode* excluiBM(BPlusNode *root, long long int cpf);
TRegistro* create_registro(long long int cpf, const char *nome, int nota);
void print_tree(BPlusNode *node, int level);
void print_all_registros(BPlusNode *root);

#endif