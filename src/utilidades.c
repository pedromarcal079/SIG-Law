#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "advogado.h"
#include "processosPF.h"

void input(char *variavel, int tam, char *mensagem){

    int len;
    printf("%s", mensagem);
    fgets(variavel, tam, stdin);
    len = strlen(variavel);
    if(len > 0 && variavel[len-1] == '\n'){
        variavel[len-1] = '\0';
    }
}

Advogado* gerarLista_adv(void){
    Advogado* lista = NULL;
    Advogado* ultimo = NULL;
    Advogado* advogado = (Advogado*) malloc(sizeof(Advogado));
    
    FILE *arq_advogado = fopen("advogado.dat", "rb");
    if (arq_advogado == NULL){
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Erro ao abrir o arquivo!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            fclose(arq_advogado);
            free(advogado);
            return NULL;
        }

    while (fread(advogado, sizeof(Advogado), 1, arq_advogado)) {
        if (advogado->atividade) {
            advogado->prox = NULL;
            if (lista == NULL) {
                lista = advogado;
            } 
            else {
                ultimo->prox = advogado;
            }
            ultimo = advogado;
            advogado = (Advogado*) malloc(sizeof(Advogado));
        }
    }
    free(advogado);
    fclose(arq_advogado);

    return lista;
}

int compararNomesAdvogado(const void *a, const void *b) {
    Advogado *advA = *(Advogado**)a;
    Advogado *advB = *(Advogado**)b;
    
    return strcasecmp(advA->nome, advB->nome);
}

ProcessoPF* gerarLista_ProcPF(void){
    ProcessoPF* lista = NULL;
    ProcessoPF* ultimo = NULL;
    ProcessoPF* processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    
    FILE *arq_processoPF = fopen("processoPF.dat", "rb");
    if (arq_processoPF == NULL){
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Erro ao abrir o arquivo!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            fclose(arq_processoPF);
            free(processoPF);
            return NULL;
        }

    while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF)) {
        if (processoPF->atividade) {
            processoPF->prox = NULL;
            if (lista == NULL) {
                lista = processoPF;
            } 
            else {
                ultimo->prox = processoPF;
            }
            ultimo = processoPF;
            processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
        }
    }
    free(processoPF);
    fclose(arq_processoPF);

    return lista;
}

void** gerarVetorOrdenado(void* lista, GetProximoFunc getProximo, CompararFunc comparar, int* qtdOut) {
    *qtdOut = 0;
    if (lista == NULL) return NULL;

    int contador = 0;
    void* atual = lista;
    while (atual != NULL) {
        contador++;
        atual = getProximo(atual);
    }
    if (contador == 0) return NULL;

    void** vetor = (void**) malloc(contador * sizeof(void*));
    if (vetor == NULL) return NULL;

    atual = lista;
    for (int i = 0; i < contador; i++) {
        vetor[i] = atual;
        atual = getProximo(atual);
    }

    if (comparar != NULL) {
        qsort(vetor, contador, sizeof(void*), comparar);
    }

    *qtdOut = contador;
    return vetor;
}