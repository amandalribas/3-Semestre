
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define D 2


// Estrutura do registro
typedef struct tRegistro {
    long long int cpf;  // CPF completo (11 dígitos)
    char nome[50];
    int nota;
} TRegistro;

// Função para gerar chave a partir do CPF (9 primeiros dígitos)
int geraChaveCPF(long long int cpf) {
    return cpf / 100;  // Remove os 2 últimos dígitos
}


// Estrutura de um nó da árvore B+
typedef struct bplus_node {
    int is_leaf;           // Indica se é folha
    int *keys;              // Array de chaves (9 primeiros dígitos do CPF)
    TRegistro **registros;  // Array de ponteiros para registros (só em folhas)
    int num_keys;           // Número atual de chaves
    struct bplus_node **children;  // Ponteiros para filhos (nós internos)
    struct bplus_node *next;       // Ponteiro para próxima folha
    struct bplus_node *parent;     // Ponteiro para o pai
} BPlusNode;


BPlusNode* create_node(int is_leaf) {
    BPlusNode *node = (BPlusNode*)malloc(sizeof(BPlusNode));
    node->is_leaf = is_leaf;
    node->keys = (int*)malloc(sizeof(int) * (2 * D));
    node->num_keys = 0;
    node->children = (BPlusNode**)malloc(sizeof(BPlusNode*) * (2 * D + 1));
    
    if (is_leaf) {
        node->registros = (TRegistro**)malloc(sizeof(TRegistro*) * (2 * D));
        for (int i = 0; i < 2 * D; i++) {
            node->registros[i] = NULL;
        }
    } else {
        node->registros = NULL;
    }
    
    for (int i = 0; i < 2 * D + 1; i++) {
        node->children[i] = NULL;
    }
    
    node->next = NULL;
    node->parent = NULL;
    return node;
}

void free_tree(BPlusNode *root) {
    if (root == NULL) return;
    
    if (root->is_leaf) {
        for (int i = 0; i < root->num_keys; i++) {
            if (root->registros[i] != NULL) {
                free(root->registros[i]);
            }
        }
        free(root->registros);
    } else {
        for (int i = 0; i <= root->num_keys; i++) {
            free_tree(root->children[i]);
        }
    }
    
    free(root->keys);
    free(root->children);
    free(root);
}

int find_key_position(BPlusNode *node, int key) {
    int pos = 0;
    while (pos < node->num_keys && key >= node->keys[pos]) {
        pos++;
    }
    return pos;
}

TRegistro* search(BPlusNode *root, long long int cpf) {
    if (root == NULL) return NULL;
    
    int key = geraChaveCPF(cpf);
    BPlusNode *current = root;
    
    while (!current->is_leaf) {
        int pos = find_key_position(current, key);
        current = current->children[pos];
    }
    
    int pos = find_key_position(current, key);
    if (pos > 0 && current->keys[pos-1] == key) {
        pos--;
    }
    
    for (int i = pos; i < current->num_keys && current->keys[i] == key; i++) {
        if (current->registros[i] != NULL && current->registros[i]->cpf == cpf) {
            return current->registros[i];
        }
    }
    
    return NULL;
}

BPlusNode* insert(BPlusNode *root, TRegistro *registro) {
    int key = geraChaveCPF(registro->cpf);
    
    if (root == NULL) {
        BPlusNode *new_root = create_node(1);
        new_root->keys[0] = key;
        new_root->registros[0] = registro;
        new_root->num_keys = 1;
        return new_root;
    }
    
    BPlusNode *leaf = root;
    while (!leaf->is_leaf) {
        int pos = find_key_position(leaf, key);
        leaf = leaf->children[pos];
    }
    
    // Verifica se o CPF já existe
    if (search(root, registro->cpf) != NULL) {
        printf("CPF %lld já existe!\n", registro->cpf);
        free(registro);
        return root;
    }
    
    int pos = find_key_position(leaf, key);
    
    // Abre espaço para inserção
    for (int i = leaf->num_keys; i > pos; i--) {
        leaf->keys[i] = leaf->keys[i-1];
        leaf->registros[i] = leaf->registros[i-1];
    }
    
    leaf->keys[pos] = key;
    leaf->registros[pos] = registro;
    leaf->num_keys++;
    
    if (leaf->num_keys <= 2 * D) {
        return root;
    }
    
    // Divisão da folha
    BPlusNode *new_leaf = create_node(1);
    int split_pos = leaf->num_keys / 2;
    
    // Copia metade para nova folha
    for (int i = split_pos; i < leaf->num_keys; i++) {
        new_leaf->keys[i-split_pos] = leaf->keys[i];
        new_leaf->registros[i-split_pos] = leaf->registros[i];
    }
    
    new_leaf->num_keys = leaf->num_keys - split_pos;
    leaf->num_keys = split_pos;
    
    // Atualiza encadeamento
    new_leaf->next = leaf->next;
    leaf->next = new_leaf;
    new_leaf->parent = leaf->parent;
    
    // Chave a ser promovida
    int promoted_key = new_leaf->keys[0];
    
    // Propaga a divisão
    BPlusNode *parent = leaf->parent;
    BPlusNode *child = new_leaf;
    
    while (1) {
        if (parent == NULL) {
            BPlusNode *new_root = create_node(0);
            new_root->keys[0] = promoted_key;
            new_root->children[0] = leaf;
            new_root->children[1] = child;
            new_root->num_keys = 1;
            leaf->parent = new_root;
            child->parent = new_root;
            return new_root;
        }
        
        int pos = find_key_position(parent, promoted_key);
        
        // Abre espaço no pai
        for (int i = parent->num_keys; i > pos; i--) {
            parent->keys[i] = parent->keys[i-1];
        }
        for (int i = parent->num_keys + 1; i > pos + 1; i--) {
            parent->children[i] = parent->children[i-1];
        }
        
        parent->keys[pos] = promoted_key;
        parent->children[pos+1] = child;
        parent->num_keys++;
        
        if (parent->num_keys <= 2 * D) {
            break;
        }
        
        // Divisão do nó interno
        BPlusNode *new_internal = create_node(0);
        split_pos = parent->num_keys / 2;
        promoted_key = parent->keys[split_pos];
        
        // Copia metade para novo nó
        for (int i = split_pos + 1; i < parent->num_keys; i++) {
            new_internal->keys[i-split_pos-1] = parent->keys[i];
        }
        for (int i = split_pos + 1; i <= parent->num_keys; i++) {
            new_internal->children[i-split_pos-1] = parent->children[i];
            parent->children[i]->parent = new_internal;
        }
        
        new_internal->num_keys = parent->num_keys - split_pos - 1;
        parent->num_keys = split_pos;
        
        child = new_internal;
        new_internal->parent = parent->parent;
        parent = parent->parent;
    }
    
    return root;
}

BPlusNode* remove_registro(BPlusNode *root, long long int cpf) {
    if (root == NULL) return NULL;
    
    int key = geraChaveCPF(cpf);
    BPlusNode *leaf = root;
    
    // Encontra a folha
    while (!leaf->is_leaf) {
        int pos = find_key_position(leaf, key);
        leaf = leaf->children[pos];
    }
    
    // Encontra o registro
    int pos = -1;
    for (int i = 0; i < leaf->num_keys; i++) {
        if (leaf->keys[i] == key && leaf->registros[i] != NULL && 
            leaf->registros[i]->cpf == cpf) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        printf("Registro não encontrado!\n");
        return root;
    }
    
    // Remove o registro
    free(leaf->registros[pos]);
    for (int i = pos; i < leaf->num_keys - 1; i++) {
        leaf->keys[i] = leaf->keys[i+1];
        leaf->registros[i] = leaf->registros[i+1];
    }
    leaf->num_keys--;
    
    // Verifica underflow
    if (leaf == root || leaf->num_keys >= D) {
        if (root->num_keys == 0 && root->is_leaf) {
            free(root);
            return NULL;
        }
        return root;
    }
    
    // Trata underflow
    BPlusNode *parent = leaf->parent;
    int leaf_pos = 0;
    while (parent->children[leaf_pos] != leaf) leaf_pos++;
    
    // Tenta redistribuir com irmão esquerdo
    if (leaf_pos > 0) {
        BPlusNode *left = parent->children[leaf_pos-1];
        if (left->num_keys > D) {
            // Move o último elemento do irmão esquerdo
            for (int i = leaf->num_keys; i > 0; i--) {
                leaf->keys[i] = leaf->keys[i-1];
                leaf->registros[i] = leaf->registros[i-1];
            }
            leaf->keys[0] = left->keys[left->num_keys-1];
            leaf->registros[0] = left->registros[left->num_keys-1];
            leaf->num_keys++;
            left->num_keys--;
            
            parent->keys[leaf_pos-1] = leaf->keys[0];
            return root;
        }
    }
    
    // Tenta redistribuir com irmão direito
    if (leaf_pos < parent->num_keys) {
        BPlusNode *right = parent->children[leaf_pos+1];
        if (right->num_keys > D) {
            // Move o primeiro elemento do irmão direito
            leaf->keys[leaf->num_keys] = right->keys[0];
            leaf->registros[leaf->num_keys] = right->registros[0];
            leaf->num_keys++;
            
            for (int i = 0; i < right->num_keys - 1; i++) {
                right->keys[i] = right->keys[i+1];
                right->registros[i] = right->registros[i+1];
            }
            right->num_keys--;
            
            parent->keys[leaf_pos] = right->keys[0];
            return root;
        }
    }
    
    // Concatenação necessária
    if (leaf_pos > 0) {
        // Concatena com irmão esquerdo
        BPlusNode *left = parent->children[leaf_pos-1];
        
        for (int i = 0; i < leaf->num_keys; i++) {
            left->keys[left->num_keys + i] = leaf->keys[i];
            left->registros[left->num_keys + i] = leaf->registros[i];
        }
        left->num_keys += leaf->num_keys;
        left->next = leaf->next;
        
        // Remove a chave de separação
        for (int i = leaf_pos - 1; i < parent->num_keys - 1; i++) {
            parent->keys[i] = parent->keys[i+1];
        }
        for (int i = leaf_pos; i < parent->num_keys; i++) {
            parent->children[i] = parent->children[i+1];
        }
        parent->num_keys--;
        
        free(leaf);
        
        // Propaga se necessário
        if (parent->num_keys < D && parent != root) {
            // Lógica similar para nós internos
        }
        
        if (parent == root && parent->num_keys == 0) {
            BPlusNode *new_root = parent->children[0];
            free(parent);
            new_root->parent = NULL;
            return new_root;
        }
    } else {
        // Concatena com irmão direito
        BPlusNode *right = parent->children[leaf_pos+1];
        
        for (int i = 0; i < right->num_keys; i++) {
            leaf->keys[leaf->num_keys + i] = right->keys[i];
            leaf->registros[leaf->num_keys + i] = right->registros[i];
        }
        leaf->num_keys += right->num_keys;
        leaf->next = right->next;
        
        // Remove a chave de separação
        for (int i = leaf_pos; i < parent->num_keys - 1; i++) {
            parent->keys[i] = parent->keys[i+1];
        }
        for (int i = leaf_pos + 1; i < parent->num_keys; i++) {
            parent->children[i] = parent->children[i+1];
        }
        parent->num_keys--;
        
        free(right);
        
        // Propaga se necessário
        if (parent->num_keys < D && parent != root) {
            // Lógica similar para nós internos
        }
        
        if (parent == root && parent->num_keys == 0) {
            BPlusNode *new_root = parent->children[0];
            free(parent);
            new_root->parent = NULL;
            return new_root;
        }
    }
    
    return root;
}

TRegistro* create_registro(long long int cpf, const char *nome, int nota) {
    TRegistro *reg = (TRegistro*)malloc(sizeof(TRegistro));
    reg->cpf = cpf;
    strncpy(reg->nome, nome, 49);
    reg->nome[49] = '\0';
    reg->nota = nota;
    return reg;
}

void print_tree(BPlusNode *node, int level) {
    if (node == NULL) return;
    
    for (int i = 0; i < level; i++) printf("  ");
    printf("Nó %s: ", node->is_leaf ? "folha" : "interno");
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

void print_all_registros(BPlusNode *root) {
    if (root == NULL) {
        printf("Árvore vazia!\n");
        return;
    }
    
    BPlusNode *current = root;
    while (!current->is_leaf) {
        current = current->children[0];
    }
    
    printf("Registros ordenados:\n");
    while (current != NULL) {
        for (int i = 0; i < current->num_keys; i++) {
            printf("CPF: %011lld, Nome: %s, Nota: %d\n",
                   current->registros[i]->cpf,
                   current->registros[i]->nome,
                   current->registros[i]->nota);
        }
        current = current->next;
    }
}

int main() {
    BPlusNode *root = NULL;
    //int D = 4; // Ordem da árvore (d=2)
    
    // Exemplo de inserção de registros
    root = insert(root, create_registro(12345678901, "João Silva", 85));
    root = insert(root, create_registro(98765432109, "Maria Souza", 92));
    root = insert(root, create_registro(45678912345, "Carlos Oliveira", 78));
    root = insert(root, create_registro(12345678902, "Ana Pereira", 88)); // Mesmos 9 primeiros dígitos que João
    root = insert(root, create_registro(32165498700, "Pedro Santos", 95));
    
    // Tentativa de inserir CPF duplicado
    root = insert(root, create_registro(12345678901, "João Silva Duplicado", 85));
    
    // Imprime a estrutura da árvore
    printf("\nEstrutura da Árvore B+:\n");
    print_tree(root, 0);
    
    // Imprime todos os registros em ordem
    printf("\nTodos os Registros:\n");
    print_all_registros(root);
    
    // Busca por um registro específico
    long long int cpf_busca = 98765432109;
    TRegistro *reg = search(root, cpf_busca);
    if (reg != NULL) {
        printf("\nRegistro encontrado para CPF %lld:\n", cpf_busca);
        printf("Nome: %s, Nota: %d\n", reg->nome, reg->nota);
    } else {
        printf("\nRegistro com CPF %lld não encontrado!\n", cpf_busca);
    }
    
    // Libera a memória
    free_tree(root);
    
    return 0;
}