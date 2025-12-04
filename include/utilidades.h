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
ClientePF* gerarLista_cliPF(void);
ClientePJ* gerarLista_cliPJ(void);
int compararNomesAdvogado(const void *a, const void *b);
int compararNomesClientePF(const void *a, const void *b);
int compararNomesClientePJ(const void *a, const void *b);
typedef void* (*GetProximoFunc)(void* atual);
typedef int   (*CompararFunc)(const void* a, const void* b);
void** gerarVetorOrdenado(void* lista, GetProximoFunc getProximo, CompararFunc comparar, int* qtdOut);
int encontraClientePJ(ClientePJ *clientePJ, const char *cnpj, FILE *arq_clientePJ);
int encontraClientePF(ClientePF *clientePF, const char *cpf, FILE *arq_clientePF);


#define True 1;
#define False 0;

#endif