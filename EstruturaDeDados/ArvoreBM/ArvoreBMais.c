#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura de um nó da árvore B+
typedef struct bplus_node {
    bool is_leaf;           // Indica se é folha
    int *keys;              // Array de chaves
    int num_keys;           // Número atual de chaves
    struct bplus_node **children;  // Ponteiros para filhos (nós internos) ou dados (folhas)
    struct bplus_node *next;       // Ponteiro para próxima folha (só usado em folhas)
    struct bplus_node *parent;     // Ponteiro para o pai
} BPlusNode;

// Cria um novo nó
BPlusNode* create_node(bool is_leaf, int order) {
    BPlusNode *node = (BPlusNode*)malloc(sizeof(BPlusNode));
    node->is_leaf = is_leaf;
    node->keys = (int*)malloc(sizeof(int) * (2 * order));
    node->num_keys = 0;
    node->children = (BPlusNode**)malloc(sizeof(BPlusNode*) * (2 * order + 1));
    for (int i = 0; i < 2 * order + 1; i++) {
        node->children[i] = NULL;
    }
    node->next = NULL;
    node->parent = NULL;
    return node;
}

// Libera a árvore
void free_tree(BPlusNode *root) {
    if (root == NULL) return;
    
    if (!root->is_leaf) {
        for (int i = 0; i <= root->num_keys; i++) {
            free_tree(root->children[i]);
        }
    }
    
    free(root->keys);
    free(root->children);
    free(root);
}

// Encontra a posição de uma chave no nó
int find_key_position(BPlusNode *node, int key) {
    int pos = 0;
    while (pos < node->num_keys && key > node->keys[pos]) {
        pos++;
    }
    return pos;
}

// Busca um valor na árvore (sempre termina em uma folha)
BPlusNode* search(BPlusNode *root, int key) {
    if (root == NULL) return NULL;
    
    BPlusNode *current = root;
    while (!current->is_leaf) {
        int pos = find_key_position(current, key);
        current = current->children[pos];
    }
    
    return current;
}

// Insere um valor na árvore B+
BPlusNode* insert(BPlusNode *root, int order, int key) {
    // Caso especial: árvore vazia
    if (root == NULL) {
        BPlusNode *new_root = create_node(true, order);
        new_root->keys[0] = key;
        new_root->num_keys = 1;
        return new_root;
    }
    
    // Encontra a folha onde a chave deve ser inserida
    BPlusNode *leaf = search(root, key);
    
    // Verifica se a chave já existe
    int pos = find_key_position(leaf, key);
    if (pos < leaf->num_keys && leaf->keys[pos] == key) {
        // Chave já existe - não faz nada (ou pode atualizar valor associado)
        return root;
    }
    
    // Insere na folha
    for (int i = leaf->num_keys; i > pos; i--) {
        leaf->keys[i] = leaf->keys[i-1];
    }
    leaf->keys[pos] = key;
    leaf->num_keys++;
    
    // Se a folha não estourou, terminamos
    if (leaf->num_keys <= 2 * order) {
        return root;
    }
    
    // Folha estourou - precisa dividir
    BPlusNode *new_leaf = create_node(true, order);
    int split_pos = order;
    
    // Copia metade das chaves para a nova folha
    for (int i = split_pos; i < 2 * order + 1; i++) {
        new_leaf->keys[i - split_pos] = leaf->keys[i];
    }
    new_leaf->num_keys = (2 * order + 1) - split_pos;
    leaf->num_keys = split_pos;
    
    // Atualiza os ponteiros das folhas
    new_leaf->next = leaf->next;
    leaf->next = new_leaf;
    new_leaf->parent = leaf->parent;
    
    // A chave a ser promovida é a primeira chave da nova folha
    int promoted_key = new_leaf->keys[0];
    
    // Propaga a divisão para cima
    BPlusNode *parent = leaf->parent;
    BPlusNode *child = new_leaf;
    
    while (1) {
        if (parent == NULL) {
            // Criar nova raiz
            BPlusNode *new_root = create_node(false, order);
            new_root->keys[0] = promoted_key;
            new_root->children[0] = leaf;
            new_root->children[1] = child;
            new_root->num_keys = 1;
            leaf->parent = new_root;
            child->parent = new_root;
            return new_root;
        }
        
        // Encontra posição para inserir no pai
        int pos = find_key_position(parent, promoted_key);
        
        // Abre espaço para a nova chave e ponteiro
        for (int i = parent->num_keys; i > pos; i--) {
            parent->keys[i] = parent->keys[i-1];
        }
        for (int i = parent->num_keys + 1; i > pos + 1; i--) {
            parent->children[i] = parent->children[i-1];
        }
        
        // Insere a chave e o ponteiro
        parent->keys[pos] = promoted_key;
        parent->children[pos+1] = child;
        parent->num_keys++;
        
        // Verifica se o pai estourou
        if (parent->num_keys <= 2 * order) {
            break;
        }
        
        // Pai estourou - divide o nó interno
        BPlusNode *new_internal = create_node(false, order);
        int split_pos = order;
        
        // A chave do meio sobe para o próximo nível
        promoted_key = parent->keys[split_pos];
        
        // Copia metade das chaves e ponteiros para o novo nó
        for (int i = split_pos + 1; i < 2 * order + 1; i++) {
            new_internal->keys[i - split_pos - 1] = parent->keys[i];
        }
        for (int i = split_pos + 1; i < 2 * order + 2; i++) {
            new_internal->children[i - split_pos - 1] = parent->children[i];
            parent->children[i]->parent = new_internal;
        }
        
        new_internal->num_keys = (2 * order) - split_pos - 1;
        parent->num_keys = split_pos;
        
        // Prepara para próxima iteração
        child = new_internal;
        new_internal->parent = parent->parent;
        parent = parent->parent;
    }
    
    return root;
}

// Remove um valor da árvore B+
BPlusNode* delete(BPlusNode *root, int order, int key) {
    if (root == NULL) return NULL;
    
    // Encontra a folha onde a chave está (ou deveria estar)
    BPlusNode *leaf = search(root, key);
    
    // Verifica se a chave existe
    int pos = find_key_position(leaf, key);
    if (pos >= leaf->num_keys || leaf->keys[pos] != key) {
        // Chave não encontrada - nada a fazer
        return root;
    }
    
    // Remove a chave da folha
    for (int i = pos; i < leaf->num_keys - 1; i++) {
        leaf->keys[i] = leaf->keys[i+1];
    }
    leaf->num_keys--;
    
    // Se a folha não ficou com menos chaves que o mínimo ou é a raiz, terminamos
    if (leaf == root || leaf->num_keys >= order) {
        return root;
    }
    
    // Folha ficou com menos chaves que o mínimo - precisa tratar underflow
    
    // Tenta redistribuir com irmão esquerdo
    BPlusNode *parent = leaf->parent;
    int leaf_pos = -1;
    for (int i = 0; i <= parent->num_keys; i++) {
        if (parent->children[i] == leaf) {
            leaf_pos = i;
            break;
        }
    }
    
    if (leaf_pos > 0) { // Tem irmão esquerdo
        BPlusNode *left_sibling = parent->children[leaf_pos - 1];
        if (left_sibling->num_keys > order) { // Pode redistribuir
            // Move a última chave do irmão esquerdo para esta folha
            for (int i = leaf->num_keys; i > 0; i--) {
                leaf->keys[i] = leaf->keys[i-1];
            }
            leaf->keys[0] = left_sibling->keys[left_sibling->num_keys - 1];
            leaf->num_keys++;
            left_sibling->num_keys--;
            
            // Atualiza a chave de separação no pai
            parent->keys[leaf_pos - 1] = leaf->keys[0];
            return root;
        }
    }
    
    // Tenta redistribuir com irmão direito
    if (leaf_pos < parent->num_keys) { // Tem irmão direito
        BPlusNode *right_sibling = parent->children[leaf_pos + 1];
        if (right_sibling->num_keys > order) { // Pode redistribuir
            // Move a primeira chave do irmão direito para esta folha
            leaf->keys[leaf->num_keys] = right_sibling->keys[0];
            leaf->num_keys++;
            
            for (int i = 0; i < right_sibling->num_keys - 1; i++) {
                right_sibling->keys[i] = right_sibling->keys[i+1];
            }
            right_sibling->num_keys--;
            
            // Atualiza a chave de separação no pai
            parent->keys[leaf_pos] = right_sibling->keys[0];
            return root;
        }
    }
    
    // Não foi possível redistribuir - precisa concatenar
    if (leaf_pos > 0) { // Concatena com irmão esquerdo
        BPlusNode *left_sibling = parent->children[leaf_pos - 1];
        
        // Move todas as chaves para o irmão esquerdo
        for (int i = 0; i < leaf->num_keys; i++) {
            left_sibling->keys[left_sibling->num_keys + i] = leaf->keys[i];
        }
        left_sibling->num_keys += leaf->num_keys;
        left_sibling->next = leaf->next;
        
        // Remove a chave de separação do pai
        for (int i = leaf_pos - 1; i < parent->num_keys - 1; i++) {
            parent->keys[i] = parent->keys[i+1];
        }
        for (int i = leaf_pos; i < parent->num_keys; i++) {
            parent->children[i] = parent->children[i+1];
        }
        parent->num_keys--;
        
        free(leaf->keys);
        free(leaf->children);
        free(leaf);
        
        // Se o pai ficou com menos chaves que o mínimo, propaga
        if (parent->num_keys < order && parent != root) {
            // Implementação similar para nós internos (omitida por brevidade)
            // ...
        }
        
        // Se o pai é a raiz e ficou sem chaves
        if (parent == root && parent->num_keys == 0) {
            free(parent->keys);
            free(parent->children);
            BPlusNode *new_root = parent->children[0];
            new_root->parent = NULL;
            free(parent);
            return new_root;
        }
    } else { // Concatena com irmão direito
        BPlusNode *right_sibling = parent->children[leaf_pos + 1];
        
        // Move todas as chaves do irmão direito para esta folha
        for (int i = 0; i < right_sibling->num_keys; i++) {
            leaf->keys[leaf->num_keys + i] = right_sibling->keys[i];
        }
        leaf->num_keys += right_sibling->num_keys;
        leaf->next = right_sibling->next;
        
        // Remove a chave de separação do pai
        for (int i = leaf_pos; i < parent->num_keys - 1; i++) {
            parent->keys[i] = parent->keys[i+1];
        }
        for (int i = leaf_pos + 1; i < parent->num_keys; i++) {
            parent->children[i] = parent->children[i+1];
        }
        parent->num_keys--;
        
        free(right_sibling->keys);
        free(right_sibling->children);
        free(right_sibling);
        
        // Se o pai ficou com menos chaves que o mínimo, propaga
        if (parent->num_keys < order && parent != root) {
            // Implementação similar para nós internos (omitida por brevidade)
            // ...
        }
        
        // Se o pai é a raiz e ficou sem chaves
        if (parent == root && parent->num_keys == 0) {
            free(parent->keys);
            free(parent->children);
            BPlusNode *new_root = parent->children[0];
            new_root->parent = NULL;
            free(parent);
            return new_root;
        }
    }
    
    return root;
}

// Função auxiliar para imprimir a árvore
void print_tree(BPlusNode *node, int level) {
    if (node == NULL) return;
    
    printf("Nível %d: ", level);
    for (int i = 0; i < node->num_keys; i++) {
        printf("%d ", node->keys[i]);
    }
    printf("\n");
    
    if (!node->is_leaf) {
        for (int i = 0; i <= node->num_keys; i++) {
            print_tree(node->children[i], level + 1);
        }
    }
}

// Função para imprimir todas as folhas em sequência
void print_leaves(BPlusNode *root) {
    if (root == NULL) return;
    
    // Encontra a primeira folha
    BPlusNode *current = root;
    while (!current->is_leaf) {
        current = current->children[0];
    }
    
    // Imprime todas as folhas em sequência
    printf("Folhas: ");
    while (current != NULL) {
        for (int i = 0; i < current->num_keys; i++) {
            printf("%d ", current->keys[i]);
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    BPlusNode *root = NULL;
    int order = 2; // Ordem da árvore (d=2)
    
    // Exemplo de inserção
    int keys[] = {1, 2, 3, 8, 15, 35, 36, 38, 39, 41, 43, 45, 51, 59};
    int num_keys = sizeof(keys) / sizeof(keys[0]);
    
    for (int i = 0; i < num_keys; i++) {
        root = insert(root, order, keys[i]);
        printf("Inserindo %d:\n", keys[i]);
        print_tree(root, 0);
        print_leaves(root);
        printf("\n");
    }
    
    // Exemplo de remoção
    int keys_to_delete[] = {3, 38, 1, 41};
    int num_keys_to_delete = sizeof(keys_to_delete) / sizeof(keys_to_delete[0]);
    
    for (int i = 0; i < num_keys_to_delete; i++) {
        root = delete(root, order, keys_to_delete[i]);
        printf("Removendo %d:\n", keys_to_delete[i]);
        print_tree(root, 0);
        print_leaves(root);
        printf("\n");
    }
    
    // Libera a memória
    free_tree(root);
    
    return 0;
}