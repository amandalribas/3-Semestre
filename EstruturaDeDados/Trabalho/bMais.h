#ifndef BMAIS_H
#define BMAIS_H

#include "geraRegistros.h"

#define D 5 //ordem
#define MAX_FILHOS (2 * D) + 1
#define MAX_PAGINA (2 * D)

#define ARQ_BM_IND "indiceBM.bin"
#define ARQ_BM_REG "registrosBM.bin"


void geraArvoreBM();


#endif

