#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*bool teste(char *palavra, int indice){
    
    if (teste(palavra,indice)){

    }
}
*/


int busca(char *vetor, char valor){
    int i;
    int tam = strlen(vetor);
    for (i=0;i<tam;i++){
        if (valor == vetor[i]){
            (vetor[i]) = '0';
            return 1;
        }
           
    }
    return 0; //Nao Encontrou o Num
}

int compara(char *vetor1, char *vetor2){
    int i;
    int tam = strlen(vetor2);
    for (i=0;i<tam;i++){
        if (!(busca(vetor1, vetor2[i])))
            return 0; //Nao Encontrou, nao eh Permutacao.
    }
    return 1;
}

int main(void){
    char a[100];
    char b[100];

    printf("Digite um valor Inicial: ");
    scanf("%s", a);
    printf("Digite um outro valor: ");
    scanf("%s", b);
    //;
    if (compara(a,b))
        printf("PERMUTACAO!");
    else
        printf("NAO PERMUTACAO!");


    return 0;
}

/*) Um número a é dito permutação de um número b se os dígitos de a formam uma permutação dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.: Considere que o dígito 0 (zero) não deve aparecer nos números.*/