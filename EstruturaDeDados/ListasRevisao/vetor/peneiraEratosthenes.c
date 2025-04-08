#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, i, *peneira;
    scanf("%d", &n);
    peneira = malloc(n * sizeof(int));
    for (i=2;i<=n;i++)
        peneira[i-2] = i;
    n-= 2;
    for (i=0;i<=n;i++)
        for (int j = i+1;j<=n;j++)
            if (peneira[j]%peneira[i] == 0){
                for (int k=j;k<=n;k++)
                    peneira[k] = peneira[k+1];    
                n--;
            }
    for (i=0;i<=n;i++)
        printf(" %d ", peneira[i]);

    free(peneira);
    return 1;
}

/*
Q1) Uma forma simples e eficiente de calcular todos os números primos até um certo valor n é o método da Peneira de Eratosthenes. O processo é simples: escrevem-se todos os valores entre 2 e n (limite máximo). Em seguida, faz-se um círculo em volta do 2, marcando como primo e riscamse todos os seus múltiplos. Continua-se a fazer círculos em volta do menor inteiro que se encontra, eliminando todos os seus múltiplos. Quando não restarem números sem terem círculos à volta ou traços por cima, os números com círculos à volta representam todos os primos até n. A figura seguinte apresenta o método para n = 40.
Escreva um programa que implemente a Peneira de Eratosthenes. Você deve ler o valor n e mostrar todos os números primos encontrados.
*/
