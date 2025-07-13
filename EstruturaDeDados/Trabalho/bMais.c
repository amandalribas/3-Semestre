#include "bMais.h"


BPlusNode* criaNoBM(int folha) {
    BPlusNode *node = (BPlusNode*)malloc(sizeof(BPlusNode));
    node->folha = folha;
    node->chaves = (int*)malloc(sizeof(int) * (2 * D));
    node->numChaves = 0;
    node->filhos = (BPlusNode**)malloc(sizeof(BPlusNode*) * (2 * D + 1));
    
    if (folha) {
        node->registros = (TRegistro**)malloc(sizeof(TRegistro*) * (2 * D));
        for (int i = 0; i < 2 * D; i++) {
            node->registros[i] = NULL;
        }
    } else {
        node->registros = NULL;
    }
    
    for (int i = 0; i < 2 * D + 1; i++) {
        node->filhos[i] = NULL;
    }
    
    node->prox = NULL;
    node->pai = NULL;
    return node;
}

void liberaBM(BPlusNode *root) {
    if (root == NULL) return;
    
    if (root->folha) {
        for (int i = 0; i < root->numChaves; i++) {
            if (root->registros[i] != NULL) {
                free(root->registros[i]);
            }
        }
        free(root->registros);
    } else {
        for (int i = 0; i <= root->numChaves; i++) {
            liberaBM(root->filhos[i]);
        }
    }
    
    free(root->chaves);
    free(root->filhos);
    free(root);
}

int buscaPosChave(BPlusNode *node, int key) {
    int pos = 0;
    while (pos < node->numChaves && key >= node->chaves[pos]) {
        pos++;
    }
    return pos;
}

TRegistro* buscaBM(BPlusNode *root, long long int cpf) {
    if (root == NULL) return NULL;
    
    int key = geraChaveCPF(cpf);
    BPlusNode *current = root;
    
    while (!current->folha) {
        int pos = buscaPosChave(current, key);
        current = current->filhos[pos];
    }
    
    int pos = buscaPosChave(current, key);
    if (pos > 0 && current->chaves[pos-1] == key) {
        pos--;
    }
    
    for (int i = pos; i < current->numChaves && current->chaves[i] == key; i++) {
        if (current->registros[i] != NULL && current->registros[i]->cpf == cpf) {
            return current->registros[i];
        }
    }
    
    return NULL;
}

BPlusNode* insereBM(BPlusNode *root, TRegistro *registro) {
    int key = geraChaveCPF(registro->cpf);
    
    if (root == NULL) {
        BPlusNode *new_root = criaNoBM(1);
        new_root->chaves[0] = key;
        new_root->registros[0] = registro;
        new_root->numChaves = 1;
        return new_root;
    }
    
    BPlusNode *leaf = root;
    while (!leaf->folha) {
        int pos = buscaPosChave(leaf, key);
        leaf = leaf->filhos[pos];
    }
    
    // Verifica se o CPF já existe
    if (buscaBM(root, registro->cpf) != NULL) {
        printf("CPF %lld já existe!\n", registro->cpf);
        free(registro);
        return root;
    }
    
    int pos = buscaPosChave(leaf, key);
    
    // Abre espaço para inserção
    for (int i = leaf->numChaves; i > pos; i--) {
        leaf->chaves[i] = leaf->chaves[i-1];
        leaf->registros[i] = leaf->registros[i-1];
    }
    
    leaf->chaves[pos] = key;
    leaf->registros[pos] = registro;
    leaf->numChaves++;
    
    if (leaf->numChaves <= 2 * D) {
        return root;
    }
    
    // Divisão da folha
    BPlusNode *new_leaf = criaNoBM(1);
    int split_pos = leaf->numChaves / 2;
    
    // Copia metade para nova folha
    for (int i = split_pos; i < leaf->numChaves; i++) {
        new_leaf->chaves[i-split_pos] = leaf->chaves[i];
        new_leaf->registros[i-split_pos] = leaf->registros[i];
    }
    
    new_leaf->numChaves = leaf->numChaves - split_pos;
    leaf->numChaves = split_pos;
    
    // Atualiza encadeamento
    new_leaf->prox = leaf->prox;
    leaf->prox = new_leaf;
    new_leaf->pai = leaf->pai;
    
    // Chave a ser promovida
    int promoted_key = new_leaf->chaves[0];
    
    // Propaga a divisão
    BPlusNode *pai = leaf->pai;
    BPlusNode *child = new_leaf;
    
    while (1) {
        if (pai == NULL) {
            BPlusNode *new_root = criaNoBM(0);
            new_root->chaves[0] = promoted_key;
            new_root->filhos[0] = leaf;
            new_root->filhos[1] = child;
            new_root->numChaves = 1;
            leaf->pai = new_root;
            child->pai = new_root;
            return new_root;
        }
        
        int pos = buscaPosChave(pai, promoted_key);
        
        // Abre espaço no pai
        for (int i = pai->numChaves; i > pos; i--) {
            pai->chaves[i] = pai->chaves[i-1];
        }
        for (int i = pai->numChaves + 1; i > pos + 1; i--) {
            pai->filhos[i] = pai->filhos[i-1];
        }
        
        pai->chaves[pos] = promoted_key;
        pai->filhos[pos+1] = child;
        pai->numChaves++;
        
        if (pai->numChaves <= 2 * D) {
            break;
        }
        
        // Divisão do nó interno
        BPlusNode *new_internal = criaNoBM(0);
        split_pos = pai->numChaves / 2;
        promoted_key = pai->chaves[split_pos];
        
        // Copia metade para novo nó
        for (int i = split_pos + 1; i < pai->numChaves; i++) {
            new_internal->chaves[i-split_pos-1] = pai->chaves[i];
        }
        for (int i = split_pos + 1; i <= pai->numChaves; i++) {
            new_internal->filhos[i-split_pos-1] = pai->filhos[i];
            pai->filhos[i]->pai = new_internal;
        }
        
        new_internal->numChaves = pai->numChaves - split_pos - 1;
        pai->numChaves = split_pos;
        
        child = new_internal;
        new_internal->pai = pai->pai;
        pai = pai->pai;
    }
    
    return root;
}

BPlusNode* excluiBM(BPlusNode *root, long long int cpf) {
    if (root == NULL) return NULL;
    
    int key = geraChaveCPF(cpf);
    BPlusNode *leaf = root;
    
    // Encontra a folha
    while (!leaf->folha) {
        int pos = buscaPosChave(leaf, key);
        leaf = leaf->filhos[pos];
    }
    
    // Encontra o registro
    int pos = -1;
    for (int i = 0; i < leaf->numChaves; i++) {
        if (leaf->chaves[i] == key && leaf->registros[i] != NULL && 
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
    for (int i = pos; i < leaf->numChaves - 1; i++) {
        leaf->chaves[i] = leaf->chaves[i+1];
        leaf->registros[i] = leaf->registros[i+1];
    }
    leaf->numChaves--;
    
    // Verifica underflow
    if (leaf == root || leaf->numChaves >= D) {
        if (root->numChaves == 0 && root->folha) {
            free(root);
            return NULL;
        }
        return root;
    }
    
    // Trata underflow
    BPlusNode *pai = leaf->pai;
    int leaf_pos = 0;
    while (pai->filhos[leaf_pos] != leaf) leaf_pos++;
    
    // Tenta redistribuir com irmão esquerdo
    if (leaf_pos > 0) {
        BPlusNode *left = pai->filhos[leaf_pos-1];
        if (left->numChaves > D) {
            // Move o último elemento do irmão esquerdo
            for (int i = leaf->numChaves; i > 0; i--) {
                leaf->chaves[i] = leaf->chaves[i-1];
                leaf->registros[i] = leaf->registros[i-1];
            }
            leaf->chaves[0] = left->chaves[left->numChaves-1];
            leaf->registros[0] = left->registros[left->numChaves-1];
            leaf->numChaves++;
            left->numChaves--;
            
            pai->chaves[leaf_pos-1] = leaf->chaves[0];
            return root;
        }
    }
    
    // Tenta redistribuir com irmão direito
    if (leaf_pos < pai->numChaves) {
        BPlusNode *right = pai->filhos[leaf_pos+1];
        if (right->numChaves > D) {
            // Move o primeiro elemento do irmão direito
            leaf->chaves[leaf->numChaves] = right->chaves[0];
            leaf->registros[leaf->numChaves] = right->registros[0];
            leaf->numChaves++;
            
            for (int i = 0; i < right->numChaves - 1; i++) {
                right->chaves[i] = right->chaves[i+1];
                right->registros[i] = right->registros[i+1];
            }
            right->numChaves--;
            
            pai->chaves[leaf_pos] = right->chaves[0];
            return root;
        }
    }
    
    // Concatenação necessária
    if (leaf_pos > 0) {
        // Concatena com irmão esquerdo
        BPlusNode *left = pai->filhos[leaf_pos-1];
        
        for (int i = 0; i < leaf->numChaves; i++) {
            left->chaves[left->numChaves + i] = leaf->chaves[i];
            left->registros[left->numChaves + i] = leaf->registros[i];
        }
        left->numChaves += leaf->numChaves;
        left->prox = leaf->prox;
        
        // Remove a chave de separação
        for (int i = leaf_pos - 1; i < pai->numChaves - 1; i++) {
            pai->chaves[i] = pai->chaves[i+1];
        }
        for (int i = leaf_pos; i < pai->numChaves; i++) {
            pai->filhos[i] = pai->filhos[i+1];
        }
        pai->numChaves--;
        
        free(leaf);
        
        // Propaga se necessário
        if (pai->numChaves < D && pai != root) {
            // Lógica similar para nós internos
        }
        
        if (pai == root && pai->numChaves == 0) {
            BPlusNode *new_root = pai->filhos[0];
            free(pai);
            new_root->pai = NULL;
            return new_root;
        }
    } else {
        // Concatena com irmão direito
        BPlusNode *right = pai->filhos[leaf_pos+1];
        
        for (int i = 0; i < right->numChaves; i++) {
            leaf->chaves[leaf->numChaves + i] = right->chaves[i];
            leaf->registros[leaf->numChaves + i] = right->registros[i];
        }
        leaf->numChaves += right->numChaves;
        leaf->prox = right->prox;
        
        // Remove a chave de separação
        for (int i = leaf_pos; i < pai->numChaves - 1; i++) {
            pai->chaves[i] = pai->chaves[i+1];
        }
        for (int i = leaf_pos + 1; i < pai->numChaves; i++) {
            pai->filhos[i] = pai->filhos[i+1];
        }
        pai->numChaves--;
        
        free(right);
        
        // Propaga se necessário
        if (pai->numChaves < D && pai != root) {
            // Lógica similar para nós internos
        }
        
        if (pai == root && pai->numChaves == 0) {
            BPlusNode *new_root = pai->filhos[0];
            free(pai);
            new_root->pai = NULL;
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
    printf("Nó %s: ", node->folha ? "folha" : "interno");
    for (int i = 0; i < node->numChaves; i++) {
        printf("%d ", node->chaves[i]);
    }
    printf("\n");
    
    if (!node->folha) {
        for (int i = 0; i <= node->numChaves; i++) {
            print_tree(node->filhos[i], level + 1);
        }
    }
}

void print_all_registros(BPlusNode *root) {
    if (root == NULL) {
        printf("ARVORE VAZIA!\n");
        return;
    }
    
    BPlusNode *current = root;
    while (!current->folha) {
        current = current->filhos[0];
    }
    
    printf("Registros ordenados:\n");
    while (current != NULL) {
        for (int i = 0; i < current->numChaves; i++) {
            printf("CPF: %011lld, Nome: %s, Nota: %d\n",
                   current->registros[i]->cpf,
                   current->registros[i]->nome,
                   current->registros[i]->nota);
        }
        current = current->prox;
    }
}

int main() {
    BPlusNode *root = NULL;
    //int D = 4; // Ordem da árvore (d=2)
    
    // Exemplo de inserção de registros
    root = insereBM(root, create_registro(12345678901, "João Silva", 85));
    root = insereBM(root, create_registro(98765432109, "Maria Souza", 92));
    root = insereBM(root, create_registro(45678912345, "Carlos Oliveira", 78));
    root = insereBM(root, create_registro(12345678902, "Ana Pereira", 88)); // Mesmos 9 primeiros dígitos que João
    root = insereBM(root, create_registro(32165498700, "Pedro Santos", 95));
    
    // Tentativa de inserir CPF duplicado
    root = insereBM(root, create_registro(12345678901, "João Silva Duplicado", 85));
    
    // Imprime a estrutura da árvore
    printf("\nEstrutura da Árvore B+:\n");
    print_tree(root, 0);
    
    // Imprime todos os registros em ordem
    printf("\nTodos os Registros:\n");
    print_all_registros(root);
    
    // Busca por um registro específico
    long long int cpf_busca = 98765432109;
    TRegistro *reg = buscaBM(root, cpf_busca);
    if (reg != NULL) {
        printf("\nRegistro encontrado para CPF %lld:\n", cpf_busca);
        printf("Nome: %s, Nota: %d\n", reg->nome, reg->nota);
    } else {
        printf("\nRegistro com CPF %lld não encontrado!\n", cpf_busca);
    }
    
    // Libera a memória
    liberaBM(root);
    
    return 0;
}