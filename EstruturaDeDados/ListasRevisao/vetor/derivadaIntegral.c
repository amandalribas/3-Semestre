#include <stdio.h>
#include <stdlib.h>

void deriva(int **derivada, int grau, int *coeficientes){
    int i;
    (*derivada) = (int *)malloc(grau * sizeof(int));
    for (i=1;i<=grau;i++)
        (*derivada)[i-1] = i * coeficientes[i];
}

void integra(int **integral, int grau, int *coeficientes){
    int i;
    (*integral) = (int *)malloc((grau+2) * sizeof(int));
    (*integral)[0] = 0;
    for (i=0;i<=(grau);i++){
        (*integral)[i+1] = (coeficientes[i])/(i+1);
    }
}   

void printa(int *vetor, int grau){
    printf("\nVETOR: { ");
    for (int i = 0;i<=grau;i++){
        printf("%d ", vetor[i]);
    }
    printf("}");
}

int main (void){
    int *coeficientes;
    int *derivada;
    int *integral;
    int grau, i;

    printf("Grau: ");
    scanf("%d", &grau);

    while (grau > 0){
        coeficientes = (int*)malloc((grau+1) * sizeof(int));

        for (i = grau; i>=0;i--){
            printf("Grau %d: ", i);
            scanf("%d", &coeficientes[i]);
        }
        printa(coeficientes,grau);

        deriva(&derivada, grau, coeficientes);
        printa(derivada,grau-1);

        integra(&integral, grau, coeficientes);
        printa(integral,grau+1);
        
        printf("\nGrau: ");
        scanf("%d", &grau);
        
        free(coeficientes);
        free(derivada);
        free(integral);
    }
   
    return 1;
}

/* Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x2 + 2x + 12 terá um vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x 3 + x 2 + 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve, infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b) calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.*/