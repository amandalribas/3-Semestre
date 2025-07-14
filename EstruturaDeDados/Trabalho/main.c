#include "geraRegistros.h"
#include "heap.h"
#include "hash.h"
#include "bMais.h"

void menu(){
    int resp = -1;
    do{
        printf("\n===============================================\n\n[1] GERAR REGISTROS\n[2] GERAR B+\n[3] GERAR HASH\n[4] GERAR HEAP\n[5] BUSCA B+\n[6] BUSCA HASH\n[7] BUSCA HEAP\n[8] REMOVE B+\n[9] REMOVE HASH\n[10] REMOVE HEAP\n[11] INSERE B+\n[12] INSERE HASH\n[13] INSERE HEAP\n[0] SAIR\nOpcao Escolhida: ");
        scanf("%d", &resp);
        switch (resp){
            case 1:
                geraRegistros();
                break;
            case 2:
                geraBM();
                break;
            case 3:
                geraHash();
                break;
            case 4:
                geraHeap();
                break;
            case 5:
                geraBuscaBM();
                break;
            case 6:
                geraBuscaHash();
                break;
            case 7:
                geraBuscaHeap();
                break;
            case 8:
                geraExcluiBM();
                break;
            case 9:
                geraExcluiHash();
                break;
            case 10:
                geraExcluiHeap();
                break;
            case 11:
                geraInsereBM();
                break;
            case 12:
                geraInsereHash();
                break;
            case 13:
                geraInsereHeap();
                break;
        }
    }while(resp != 0);
    printf("\nFinalizando...");
}


int main(void){
    srand(time(NULL));
    
    menu();
    
    //imprimeArqBin(ARQ_REG);

    //geraBM();
    
    //geraHeap();
    
    //geraHash();
    
    return 0;


}