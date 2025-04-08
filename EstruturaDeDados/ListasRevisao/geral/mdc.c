#include <stdio.h>

int mdc(N1,N2){
    int maior, menor, div;
    if (N1 == N2)
        return N1;
    if (N1 < N2)
        menor = N1;
    else
        menor = N2;
    for (div=1;div<=menor;div++){
        if (N1 % div == 0 && N2 % div == 0)
            maior = div;
    }
    return maior;
}

int main(void){
    int N, F1, F2, i, m;
    scanf("%d", &N);
    for (i = 0;i<N;i++){
        scanf("%d %d", &F1, &F2);
        m = mdc(F1,F2);
        printf("%d\n",m);
    }
    return 1;
}