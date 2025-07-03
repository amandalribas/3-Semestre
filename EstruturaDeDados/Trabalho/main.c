#include "geraRegistros.h"
#include "heap.h"


int main(void){
    srand(time(NULL));
    
    geraRegistros();
    
    printf("\n\nREGISTROS INICIAIS: \n\n");
    imprimeArqBin(ARQ_REG);

    geraHeap();
    
    return 0;


}