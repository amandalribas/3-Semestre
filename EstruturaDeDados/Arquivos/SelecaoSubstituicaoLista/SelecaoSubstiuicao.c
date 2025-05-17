#include <stdio.h>
#include <stdlib.h>

#define M 20
#define MAX 999999999999LL

typedef struct dado {
    long long int info;
    int congelado;
    struct dado *anterior;
    struct dado *proximo;
} TDado;

TDado *novoNo(long long int valor, TDado *anterior, TDado *proximo);
TDado *menorChave(TDado *cabeca);
TDado *busca(long long int valor, TDado *cabeca);

TDado *novoNo(long long int valor, TDado *anterior, TDado *proximo) {
    TDado *no = (TDado *)malloc(sizeof(TDado));
    no->info = valor;
    no->anterior = anterior;
    no->proximo = proximo;
    no->congelado = 0;
    return no;
}

TDado *menorChave(TDado *cabeca) {
    if (!cabeca) return NULL;
    TDado *atual = cabeca;
    TDado *menor = NULL;
    while (atual) {
        if (!atual->congelado && (menor == NULL || atual->info < menor->info)) {
            menor = atual;
        }
        atual = atual->proximo;
    }
    return menor;
}

TDado *busca(long long int valor, TDado *cabeca) {
    TDado *atual = cabeca;
    while (atual) {
        if (atual->info == valor) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int SelecaoSubstituicao(char *nomeArquivo) {
    int contadorParticoes = 0;
    char nomeNovoArquivo[40];
    FILE *arquivo = fopen(nomeArquivo, "r"); //Abre o Arquivo
    
    FILE *novoArquivo;
    long long int valorAtual;
    TDado *atual, *cabeca = NULL, *menor;

    if (arquivo) {
        //1. Ler M Registros na memoria;
        if (fscanf(arquivo, "%lld", &valorAtual) == 1) {
            cabeca = novoNo(valorAtual, NULL, NULL);
            atual = cabeca;

            for (int i = 1; i < M && fscanf(arquivo, "%lld", &valorAtual) == 1; i++) {
                atual->proximo = novoNo(valorAtual, atual, NULL);
                atual = atual->proximo;
            }

            while (!feof(arquivo)) {
                contadorParticoes++; //Nomeando Arquivo...
                sprintf(nomeNovoArquivo, "registro%d.txt", contadorParticoes);
                novoArquivo = fopen(nomeNovoArquivo, "w");

                do { //2.  Selecionar, no Array em memoria, o registro r com menor chave;
                    menor = menorChave(cabeca);
                    if (menor && menor->info != MAX) {
                        fprintf(novoArquivo, "%lld\n", menor->info); //3. Gravar o registro r na particao de saida;

                        if (fscanf(arquivo, "%lld", &valorAtual) == 1) {
                            if (valorAtual < menor->info) { //5. Caso a chave deste ultimo seja menor do que a chave recém gravada, considerá-lo congelado e ignorá-lo no restante do processamento;
                                menor->congelado = 1;
                            }
                            menor->info = valorAtual;
                        } else {
                            menor->info = MAX;
                        }
                    }
                } while (menor && menor->info != MAX);

                fclose(novoArquivo);

                atual = cabeca;
                while (atual) {
                    atual->congelado = 0;
                    atual = atual->proximo;
                }
            }

            fclose(arquivo);

            atual = cabeca;
            TDado *tmp;
            while (atual) {
                tmp = atual;
                atual = atual->proximo;
                free(tmp);
            }
        }
    }
    return contadorParticoes;
}

int main(void) {
    int particoes = SelecaoSubstituicao("registro.txt");
    printf("%d Particoes Realizadas.", particoes);
    return 0;
}


/*
1. Ler M registros do arquivo para a memória
2. Selecionar, no array em memória, o registro r com menor chave
3. Gravar o registro r na partição de saída
4. Substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
5. Caso a chave deste último seja menor do que a chave recém gravada, considerá-lo congelado
e ignorá-lo no restante do processamento
6. Caso existam em memória registros não congelados, voltar ao passo 2
7. Caso contrário:
    fechar a partição de saída
    descongelar os registros congelados
    abrir nova partição de saída
    voltar ao passo 2

Em média, o tamanho das partições obtidas pelo processo de seleção com substituição é de 2 * M
    */
