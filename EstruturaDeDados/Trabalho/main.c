#include "geraRegistros.h"
#include "heap.h"
#include "hash.h"


int main(void){
    srand(time(NULL));
    
    //geraRegistros();
    //imprimeArqBin(ARQ_REGISTROS);

    //printf("\n\nREGISTROS INICIAIS: \n\n");
    
    geraRegistros();
    
    imprimeArqBin(ARQ_REG);

    geraHeap();
    
    geraHash();
    
    return 0;


}