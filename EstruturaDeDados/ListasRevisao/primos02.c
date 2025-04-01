/*
Q2) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa para quando n for menor ou igual a zero.
*/

#include <stdio.h>
#include <math.h>

int numPrimo(num){
    int i;
    if (num == 2 || num == 3)
        return 1;
    if (num % 2 == 1){
        for (i = 3;i<(sqrt(num)+1);i+= 2){
            if (num%i == 0)
                return 0;
        }
        return 1;
    }
    return 0;
}

int main(void){
    int n, contador, testaPrimo;
    printf("Val. de N: ");
    scanf("%d", &n);
    while (n>0){
        contador = 0;
        testaPrimo = n + 1;
        while (contador < n){
            if (numPrimo(testaPrimo)){
                printf("  %d  ", testaPrimo);
                contador++;
            }
            testaPrimo++;
        }
    

        printf("\nVal. de N: ");
        scanf("%d", &n);
    }
    printf("Fim da Execucacao do Programa...");
    return 1;
}