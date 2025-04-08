#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverte(char *palavra){
    int tam = strlen(palavra);
    char *novaPalavra = malloc(tam * sizeof(char));
    for (int i=0;i<tam;i++){
        novaPalavra[i] = palavra[tam-i-1];
    }
    novaPalavra[tam] = '\0';
    return novaPalavra;
}



int main (void){
    char palindromo[100];
    char *invertida = NULL;
    printf("Digite um Valor:");
    scanf("%s", palindromo);
    while (atoi(palindromo) > 0){
        invertida = inverte(palindromo);
        if (strcmp(palindromo,invertida) == 0)
            printf("VERDADEIRO");
        else
            printf("FALSO");
        free(invertida);

        printf("Digite um Valor:");
        scanf("%s", palindromo);
    }
 
    return 0;
}

/*Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou “FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o número for negativo. */