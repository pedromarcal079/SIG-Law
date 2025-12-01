#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "advogado.h"
#include "processosPF.h"

void input(char *, int, char *);
Advogado* gerarLista_adv(void);
ProcessoPF* gerarLista_ProcPF(void);
int compararNomesAdvogado(const void *a, const void *b);
typedef void* (*GetProximoFunc)(void* atual);
typedef int   (*CompararFunc)(const void* a, const void* b);
void** gerarVetorOrdenado(void* lista, GetProximoFunc getProximo, CompararFunc comparar, int* qtdOut);


#define True 1;
#define False 0;

#endif