#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float recebeValor(){
    float num;
    printf("Digite um Valor:");
    scanf("%f", &num);
    return num;
}


void binario(float num){
    int tam = log2(num) + 1;
    int val = (int)num;
    int *binario = malloc( tam * sizeof(int));
    for (int i = 0;i<tam;i++){
        binario[i] = val % 2;
        val /= 2;
    }
    for (int i = tam-1; i>= 0;i--)
        printf("%d ", binario[i]);
    printf("\n");
}


int main(void){
    float num = recebeValor();
    while (num>0){
        binario(num);
        num=recebeValor();
    }
    return 0;
}
/*) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste programa deve ser “1100”. Seu programa para quando n for menor que zero. */