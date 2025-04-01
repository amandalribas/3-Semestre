/*
Q1) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e retorne os n primeiros números primos existentes. Seu programa para quando n for menor ou igual a zero.

*/

#include <stdio.h>
#include <math.h>

int numPrimo(int num){
    int i = 3;
    if(num == 2 || num == 3)
        return 1;
    if (num % 2 == 1){
        for (i;i<(sqrt(num)+1);i+= 2){
            if (num%i == 0)
                return 0;
        }
        return 1;

    }
    return 0;
}


int main(void){
    int n, contador, testaPrimo;
    printf("Quantidade de N primeiros Numeros Primos: ");
    scanf("%d", &n);
    while (n>0){
        contador = 0;
        testaPrimo = 1;
        while(contador < n){
            testaPrimo++;
            if (numPrimo(testaPrimo)){
                printf("  %d  ", testaPrimo);
                contador++;
            }
        }
        
        printf("\nQuantidade de N primeiros Numeros Primos: ");
        scanf("%d", &n);
    }
    printf("Fim da Execucao do Programa...");
    return 0;
}