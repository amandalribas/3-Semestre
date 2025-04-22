#include <stdio.h>

int fibSemRecursao(int n){
    if (n == 0) return n;
    if (n == 1) return 1;
    int n1 = 0, n2 = 1;
    int aux;
    for (int i = 1; i < n; i++){
        aux = n2;
        n2 = n1 + n2;
        n1 = aux;
    }return n2;
}

int fibRecursao(int n){
    if (n == 0)
        return n;
    if (n == 1)
        return n;
    return fibRecursao(n-1) + fibRecursao(n-2);
}
int main(void){
    int n = fibSemRecursao(6);
    printf("%d", n);
    n = fibRecursao(6);
    printf("\n%d", n);
    return 1;
}
