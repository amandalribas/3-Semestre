#ifndef ARVORE_H
#define ARVORE_H


typedef struct AB {
    int chave;
    struct AB* esquerda;
    struct AB* direita;
} TAB;

// Declarações das funções da árvore
TAB* treeSearch(TAB* no, int chave);
TAB* treeMinimum(TAB* no);
TAB* treeMaximum(TAB* no);
TAB* treeInsert(TAB* no, int chave);

#endif