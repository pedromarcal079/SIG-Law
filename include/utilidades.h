#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "advogado.h"
#include "processosPF.h"
#include "processosPJ.h"
#include "clientePF.h"
#include "clientePJ.h"

void input(char *, int, char *);
Advogado* gerarLista_adv(void);
ProcessoPF* gerarLista_ProcPF(void);
int compararNomesAdvogado(const void *a, const void *b);
typedef void* (*GetProximoFunc)(void* atual);
typedef int   (*CompararFunc)(const void* a, const void* b);
typedef const char* (*GetDataFunc)(void* item);
void** gerarVetorOrdenado(void* lista, GetProximoFunc getProximo, CompararFunc comparar, int* qtdOut);
void* proc_getProximo(void* item);
int proc_compararData(const void* a, const void* b);
int encontraClientePJ(ClientePJ *clientePJ, const char *cnpj, FILE *arq_clientePJ);
int encontraClientePF(ClientePF *clientePF, const char *cpf, FILE *arq_clientePF);
void* procPJ_getProximo(void* item);
int procPJ_compararData(const void* a, const void* b);



#define True 1;
#define False 0;

#endif