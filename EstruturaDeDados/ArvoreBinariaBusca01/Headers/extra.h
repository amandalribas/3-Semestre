#include "arvore.h"

#ifndef EXTRA_H
#define EXTRA_H

TAB* treeMinimum(TAB* no);
TAB* treeMaximum(TAB* no);
TAB* treeSucessor(TAB *no, int chave);
TAB *treePredecessor(TAB *raiz, int chave);
int *treeHeight(TAB *no);
int treeNode(TAB *no);
int treeSon(TAB *no);
#endif