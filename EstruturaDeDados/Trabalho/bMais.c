#include "bMais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TNoBM *criaBM() {
    TNoBM* novo = (TNoBM*)malloc(sizeof(TNoBM));
    novo->nChaves = 0;
    novo->chave = (long long int*)malloc(sizeof(long long int)*((D*2)-1));
    novo->folha = 1;
    novo->filho = (TNoBM**)malloc(sizeof(TNoBM*)*D*2);
    novo->prox = NULL;
    for(int i=0; i<(D*2); i++) 
        novo->filho[i] = NULL;
    return novo;
}

TNoBM *inicializaBM(void) {
    return NULL;
}

void liberaBM(TNoBM *raiz) {
    if(raiz) {
        if(!raiz->folha) {
            for(int i = 0; i <= raiz->nChaves; i++) 
                liberaBM(raiz->filho[i]);
        }
        free(raiz->filho);
        free(raiz->chave);
        free(raiz);
    }
}

TNoBM *buscaBM(TNoBM *raiz, TRegistro *reg) {
    if (!raiz) return NULL;
    
    long long int chave = reg->cpf;
    int i = 0;
    
    while (i < raiz->nChaves && chave > raiz->chave[i]) 
        i++;
    
    if (i < raiz->nChaves && raiz->folha && chave == raiz->chave[i]) 
        return raiz;
    
    if (raiz->folha) 
        return NULL;
    
    if (i < raiz->nChaves && raiz->chave[i] == chave) 
        i++;
    
    return buscaBM(raiz->filho[i], reg);
}

void imprimeChavesBM(TNoBM *raiz) {
    if(!raiz) return;
    
    TNoBM *p = raiz;
    while(p->filho[0]) 
        p = p->filho[0];
    
    while(p) {
        for(int i = 0; i < p->nChaves; i++) 
            printf("%lld ", p->chave[i]);
        p = p->prox;
    }
    printf("\n");
}

void imp(TNoBM *raiz, int nivel) {
    if(raiz) {
        for(int i = 0; i <= raiz->nChaves-1; i++) {
            imp(raiz->filho[i], nivel+1);
            for(int j = 0; j <= nivel; j++) 
                printf("\t");
            printf("%lld\n", raiz->chave[i]);
        }
        imp(raiz->filho[raiz->nChaves], nivel+1);
    }
}

void imprimeBM(TNoBM *raiz) {
    imp(raiz, 0);
}

TNoBM *divisao(TNoBM *x, int pos, TNoBM* y) {
    TNoBM *z = criaBM();
    z->folha = y->folha;
    
    if(!y->folha) {
        z->nChaves = D-1;
        for(int j = 0; j < D-1; j++) 
            z->chave[j] = y->chave[j+D];
        
        for(int j = 0; j < D; j++) {
            z->filho[j] = y->filho[j+D];
            y->filho[j+D] = NULL;
        }
    } else {
        z->nChaves = D;
        for(int j = 0; j < D; j++) 
            z->chave[j] = y->chave[j+D-1];
        z->prox = y->prox;
        y->prox = z;
    }
    
    y->nChaves = D-1;
    
    for(int j = x->nChaves; j >= pos; j--) 
        x->filho[j+1] = x->filho[j];
    x->filho[pos] = z;
    
    for(int j = x->nChaves; j >= pos; j--) 
        x->chave[j] = x->chave[j-1];
    
    x->chave[pos-1] = y->chave[D-1];
    x->nChaves++;
    
    return x;
}

TNoBM *insereNaoCompletoBM(TNoBM *x, TRegistro *reg) {
    int i = x->nChaves-1;
    long long int chave = reg->cpf;
    
    if(x->folha) {
        while(i >= 0 && chave < x->chave[i]) {
            x->chave[i+1] = x->chave[i];
            i--;
        }
        x->chave[i+1] = chave;
        x->nChaves++;
        return x;
    }
    
    while(i >= 0 && chave < x->chave[i]) 
        i--;
    i++;
    
    if(x->filho[i]->nChaves == (2*D-1)) {
        x = divisao(x, i+1, x->filho[i]);
        if(chave > x->chave[i]) 
            i++;
    }
    
    x->filho[i] = insereNaoCompletoBM(x->filho[i], reg);
    return x;
}

TNoBM *insereBM(TNoBM *T, TRegistro *reg) {
    long long int chave = reg->cpf;
    
    if(buscaBM(T, reg)) 
        return T;
    
    if(!T) {
        T = criaBM();
        T->chave[0] = chave;
        T->nChaves = 1;
        return T;
    }
    
    if(T->nChaves == (2*D-1)) {
        TNoBM *S = criaBM();
        S->folha = 0;
        S->filho[0] = T;
        S = divisao(S, 1, T);
        S = insereNaoCompletoBM(S, reg);
        return S;
    }
    
    return insereNaoCompletoBM(T, reg);
}

TNoBM* excluiBM(TNoBM* arv, TRegistro *reg) {
    if(!arv) return arv;
    
    long long int ch = reg->cpf;
    int i = 0;
    
    while(i < arv->nChaves && arv->chave[i] < ch) 
        i++;
    
    if(i < arv->nChaves && arv->chave[i] == ch && arv->folha) {
        for(int j = i; j < arv->nChaves-1; j++) 
            arv->chave[j] = arv->chave[j+1];
        
        arv->nChaves--;
        
        if(!arv->nChaves) {
            liberaBM(arv);
            return NULL;
        }
        return arv;
    }
    
    if(i < arv->nChaves && arv->chave[i] == ch) 
        i++;
    
    TNoBM *y = arv->filho[i];
    
    if(y->nChaves == D-1) {
        
    }
    
    arv->filho[i] = excluiBM(arv->filho[i], reg);
    return arv;
}

TNoBM* retiraBM(TNoBM* arv, TRegistro *reg) {
    if(!arv || !buscaBM(arv, reg)) 
        return arv;
    return excluiBM(arv, reg);
}

void imprimeRegistrosBM(TNoBM *raiz, FILE *arq) {
    if (!raiz) return;
    
    TNoBM *p = raiz;
    while (p && !p->folha) {
        p = p->filho[0];
    }
    
    int i = 0;
    while (p) {
        for (int j = 0; j < p->nChaves; j++) {
            fseek(arq, 0, SEEK_SET);
            TRegistro *reg = NULL;
            
            while ((reg = leRegistroBin(arq)) != NULL) {
                if (reg->cpf == p->chave[j]) {
                    printf("\nRegistro %d = { CPF= %lld, NOME= %s, NOTA= %d }", 
                           i++, reg->cpf, reg->nome, reg->nota);
                    free(reg);
                    break;
                }
                free(reg);
            }
        }
        p = p->prox;
    }
}

void geraBM() {
    FILE *arq = fopen(ARQ_REG, "rb");
    if (!arq) {
        printf("Erro ao abrir arquivo de registros\n");
        return;
    }

    TRegistro *reg = NULL;
    TNoBM *arvore = inicializaBM();

    for (int i = 0; i < QUANT_REG; i++) {
        reg = leRegistroBin(arq);
        if (reg) {
            arvore = insereBM(arvore, reg);
            free(reg);
        }
    }
    
    //printf("\nEstrutura da Arvore B+:\n");
    //imprimeBM(arvore);
    
    printf("\nARVORE B+ GERADA:\n");
    rewind(arq); 
    imprimeRegistrosBM(arvore, arq);
    
    liberaBM(arvore);
    fclose(arq);
    
}

void geraBuscaBM() {
    FILE *arq = fopen(ARQ_REG, "rb");
    if (!arq) {
        printf("Erro ao abrir arquivo de registros\n");
        return;
    }

    TRegistro *reg = NULL;
    TNoBM *arvore = inicializaBM();

    for (int i = 0; i < QUANT_REG; i++) {
        reg = leRegistroBin(arq);
        if (reg) {
            arvore = insereBM(arvore, reg);
            free(reg);
        }
    }
    
    long long int cpf;
    printf("\nDigite o CPF a ser Procurado: ");
    scanf("%lld", &cpf);
    
    TRegistro regBusca;
    regBusca.cpf = cpf;
    
    TNoBM *no = buscaBM(arvore, &regBusca);
    
    if (no) {
        // Se encontrou, procurar o registro completo no arquivo
        rewind(arq);
        TRegistro *regEncontrado = NULL;
        while ((regEncontrado = leRegistroBin(arq)) != NULL) {
            if (regEncontrado->cpf == cpf) {
                printf("\nRegistro encontrado = { CPF= %lld, NOME= %s, NOTA= %d }", 
                       regEncontrado->cpf, regEncontrado->nome, regEncontrado->nota);
                free(regEncontrado);
                break;
            }
            free(regEncontrado);
        }
    } else {
        printf("\nRegistro com CPF %lld não encontrado.", cpf);
    }
    
    liberaBM(arvore);
    fclose(arq);
}

void geraExcluiBM() {
    FILE *arq = fopen(ARQ_REG, "rb+");
    if (!arq) {
        printf("Erro ao abrir arquivo de registros\n");
        return;
    }

    TRegistro *reg = NULL;
    TNoBM *arvore = inicializaBM();
    for (int i = 0; i < QUANT_REG; i++) {
        reg = leRegistroBin(arq);
        if (reg) {
            arvore = insereBM(arvore, reg);
            free(reg);
        }
    }

    long long int cpf;
    printf("\nDigite o CPF a ser removido: ");
    scanf("%lld", &cpf);

    TRegistro regBusca;
    regBusca.cpf = cpf;

    if (!buscaBM(arvore, &regBusca)) {
        printf("\nRegistro com CPF %lld não encontrado.\n", cpf);
        liberaBM(arvore);
        fclose(arq);
        return;
    }

    arvore = retiraBM(arvore, &regBusca);

    FILE *aux = fopen("temp.bin", "wb");
    rewind(arq);
    
    int removeu = 0;
    TRegistro currentReg;
    while (fread(&currentReg, sizeof(TRegistro), 1, arq)) {
        if (currentReg.cpf != cpf) {
            fwrite(&currentReg, sizeof(TRegistro), 1, aux);
        } else {
            removeu = 1;
        }
    }

    fclose(arq);
    fclose(aux);

    remove(ARQ_REG);
    rename("temp.bin", ARQ_REG);

    if (removeu) {
        printf("\nRegistro com CPF %lld removido com sucesso!\n", cpf);
        //QUANT_REG--;
    } else {
        printf("\nErro: CPF %lld NAO encontrado no arquivo.\n", cpf);
    }

    printf("\nArvore apos remocao:\n");
    imprimeRegistrosBM(arvore, arq);
    
    liberaBM(arvore);
}

void geraInsereBM() {
    FILE *arq = fopen(ARQ_REG, "ab+");  
    if (!arq) {
        printf("Erro ao abrir arquivo de registros\n");
        return;
    }

    TNoBM *arvore = inicializaBM();
    rewind(arq);
    TRegistro *reg = NULL;
    for (int i = 0; i < QUANT_REG; i++) {
        reg = leRegistroBin(arq);
        if (reg) {
            arvore = insereBM(arvore, reg);
            free(reg);
        }
    }

    
    TRegistro novoReg;
    printf("\nDigite o CPF: ");
    scanf("%lld", &novoReg.cpf);
    
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome: ");
    fgets(novoReg.nome, sizeof(novoReg.nome), stdin);
    novoReg.nome[strcspn(novoReg.nome, "\n")] = '\0';  // Remove newline
    
    printf("Digite a nota: ");
    scanf("%d", &novoReg.nota);

    TRegistro regBusca;
    regBusca.cpf = novoReg.cpf;
    if (buscaBM(arvore, &regBusca)) {
        printf("\nERRO: CPF %lld já existe na árvore!\n", novoReg.cpf);
        liberaBM(arvore);
        fclose(arq);
        return;
    }

    reg = preencheReg(novoReg.cpf, novoReg.nota, novoReg.nome);
    arvore = insereBM(arvore, reg);
    
    fseek(arq, 0, SEEK_END);
    escreveRegBin(arq, reg);
    //QUANT_REG++;
    
    printf("\nRegistro inserido com sucesso!");
    printf("\n\nÁrvore B+ atualizada:\n");
    rewind(arq);
    imprimeRegistrosBM(arvore, arq);
    
    free(reg);
    liberaBM(arvore);
    fclose(arq);
}