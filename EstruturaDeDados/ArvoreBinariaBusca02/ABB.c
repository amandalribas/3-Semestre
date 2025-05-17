#include "ABB.h"

TABB *cria(int info,TABB *esquerda, TABB *direita){
    TABB *node = (TABB*)malloc(sizeof(TABB));
    node->direita = direita;
    node->esquerda = esquerda;
    node->info = info;
    return node;
}

void libera(TABB *node){
    if(node){
        libera(node->esquerda);
        libera(node->direita);
        free(node); 
    }
}

TABB *treeMaximum(TABB *node){
    if (!node || !(node->direita)) return node;
    return node = treeMaximum(node->direita);
    
}

TABB *treeMinimum(TABB *node){
    if (!node || !(node->esquerda)) return node;
    return node = treeMinimum(node->esquerda);
}

TABB *inserir(TABB *root, int info){
    if (!root) return cria(info, NULL, NULL); //Raiz/No Atual Vazio.
    if (root->info > info) root->esquerda = inserir(root->esquerda, info);
    else if (root->info < info) root->direita = inserir(root->direita, info);
    return root;
}

TABB *buscar(TABB *root, int info){
    if (!root || root->info == info) return root;

    if (root->info < info) return buscar(root->direita,info);
    if (root->info > info) return buscar(root->esquerda, info);
}

TABB *remover(TABB *root, int info){
    if(!root) return root; //NULL

    //busca
    if (root->info > info) root->esquerda = remover(root->esquerda,info);
    else if (root->info < info) root->direita = remover(root->direita, info);

    //ENCONTROU:
    else{
        if(!(root->esquerda)&&!(root->direita)){ //SEM FILHOS
            free(root);
            return NULL;
        }else if (!(root->esquerda)||!(root->direita)){ //1 FILHO SÓ
            TABB *aux = root;
            if((root->direita)) root = root->direita;
            else if((root->esquerda)) root = root->esquerda;
            free(aux);
            return root;
        }else{ //2 FILHOS (PEGA O MAXIMO A ESQUERDA)
            TABB *maior = treeMaximum(root->esquerda);
            root->info = maior->info;
            root->esquerda = remover(root->esquerda, maior->info);
        }
    }
    return root;
}

/*ORDEM:*/

void preOrder(TABB *root){ //raiz - esquerda - direita
    if(!root) return;
    printf("\t%d",root->info);
    preOrder(root->esquerda);
    preOrder(root->direita);
}

void inOrder(TABB *root){ // esquerda - raiz - direita
    if (!root) return;
    inOrder(root->esquerda);
    printf("\t%d", root->info);
    inOrder(root->direita);
}

void postOrder(TABB *root){ // esquerda - direita - raiz
    if(!root) return;
    postOrder(root->esquerda);
    postOrder(root->direita);
    printf("\t%d", root->info);
}

