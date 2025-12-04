#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "advogado.h"
#include "processosPF.h"
#include "processosPJ.h"
#include "clientePF.h"
#include "clientePJ.h"

void input(char *variavel, int tam, char *mensagem){

    int len;
    printf("%s", mensagem);
    fgets(variavel, tam, stdin);
    len = strlen(variavel);
    if(len > 0 && variavel[len-1] == '\n'){
        variavel[len-1] = '\0';
    }
}

int encontraClientePJ(ClientePJ *clientePJ, const char *cnpj, FILE *arq_clientePJ) {
    if (arq_clientePJ == NULL) return 0;
    rewind(arq_clientePJ);
    while (fread(clientePJ, sizeof(ClientePJ), 1, arq_clientePJ) == 1) {
        if (strcmp(clientePJ->cnpj, cnpj) == 0) {
            return 1; // encontrado
        }
    }
    return 0; // não encontrado
}

int encontraClientePF(ClientePF *clientePF, const char *cpf, FILE *arq_clientePF) {
    if (arq_clientePF == NULL) return 0;
    rewind(arq_clientePF);
    while (fread(clientePF, sizeof(ClientePF), 1, arq_clientePF) == 1) {
        if (strcmp(clientePF->cpf, cpf) == 0) {
            return 1; // encontrado
        }
    }
    return 0; // não encontrado
}




 //toda função de gerar lista ou comparação que estiver abaixo desse comentario foi feito com a ajuda do Gemini.//
Advogado* gerarLista_adv(void){
    Advogado* lista = NULL;
    Advogado* ultimo = NULL;
    FILE *arq_advogado = fopen("advogado.dat", "rb");
    if (arq_advogado == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return NULL;
    }

    Advogado buffer;
    while (fread(&buffer, sizeof(Advogado), 1, arq_advogado) == 1) {
        if (buffer.atividade) {
            Advogado* node = (Advogado*) malloc(sizeof(Advogado));
            if (!node) {
                // em caso de falha, liberar lista já criada e sair
                Advogado* t = lista;
                while (t) {
                    Advogado* nxt = t->prox;
                    free(t);
                    t = nxt;
                }
                fclose(arq_advogado);
                printf("\nERRO: Falha na alocacao de memoria.\n");
                return NULL;
            }
            memcpy(node, &buffer, sizeof(Advogado)); //copia um número especificado de bytes de uma área de memória (fonte) para outra (destino)//
            node->prox = NULL;
            if (lista == NULL) {
                lista = node;
            } else {
                ultimo->prox = node;
            }
            ultimo = node;
        }
    }
    fclose(arq_advogado);
    return lista;
}

ClientePJ* gerarLista_cliPJ(void){
    ClientePJ* lista = NULL;
    ClientePJ* ultimo = NULL;
    FILE *arq_clientePJ = fopen("clientePJ.dat", "rb");
    if (arq_clientePJ == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return NULL;
    }

    ClientePJ buffer;
    while (fread(&buffer, sizeof(ClientePJ), 1, arq_clientePJ) == 1) {
        if (buffer.atividade) {
            ClientePJ* node = (ClientePJ*) malloc(sizeof(ClientePJ));
            if (!node) {
                // em caso de falha, liberar lista já criada e sair
                ClientePJ* t = lista;
                while (t) {
                    ClientePJ* nxt = t->prox;
                    free(t);
                    t = nxt;
                }
                fclose(arq_clientePJ);
                printf("\nERRO: Falha na alocacao de memoria.\n");
                return NULL;
            }
            memcpy(node, &buffer, sizeof(ClientePJ));
            node->prox = NULL;
            if (lista == NULL) {
                lista = node;
            } else {
                ultimo->prox = node;
            }
            ultimo = node;
        }
    }
    fclose(arq_clientePJ);
    return lista;
}

int compararNomesClientePJ(const void *a, const void *b) {
    ClientePJ *cliPJA = *(ClientePJ**)a;
    ClientePJ *cliPJB = *(ClientePJ**)b;
    
    return strcasecmp(cliPJA->nomeFantasia, cliPJB->nomeFantasia);
}

ClientePF* gerarLista_cliPF(void){
    ClientePF* lista = NULL;
    ClientePF* ultimo = NULL;
    FILE *arq_cliente = fopen("clientePF.dat", "rb");
    if (arq_cliente == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return NULL;
    }

    ClientePF buffer;
    while (fread(&buffer, sizeof(ClientePF), 1, arq_cliente) == 1) {
        if (buffer.atividade) {
            ClientePF* node = (ClientePF*) malloc(sizeof(ClientePF));
            if (!node) {
                // em caso de falha, liberar lista já criada e sair
                ClientePF* t = lista;
                while (t) {
                    ClientePF* nxt = t->prox;
                    free(t);
                    t = nxt;
                }
                fclose(arq_cliente);
                printf("\nERRO: Falha na alocacao de memoria.\n");
                return NULL;
            }
            memcpy(node, &buffer, sizeof(ClientePF));
            node->prox = NULL;
            if (lista == NULL) {
                lista = node;
            } else {
                ultimo->prox = node;
            }
            ultimo = node;
        }
    }
    fclose(arq_cliente);
    return lista;
}

int compararNomesClientePF(const void *a, const void *b) {
    ClientePF *cliPFA = *(ClientePF**)a;
    ClientePF *cliPFB = *(ClientePF**)b;
    
    return strcasecmp(cliPFA->nome, cliPFB->nome);
}

int compararNomesAdvogado(const void *a, const void *b) {
    Advogado *advA = *(Advogado**)a;
    Advogado *advB = *(Advogado**)b;
    
    return strcasecmp(advA->nome, advB->nome); //função que compara duas strings sem diferenciar maiúsculas de minúsculas
}

ProcessoPF* gerarLista_ProcPF(void){
    ProcessoPF* lista = NULL;
    ProcessoPF* ultimo = NULL;
    FILE *arq_processoPF = fopen("processoPF.dat", "rb");
    if (arq_processoPF == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return NULL;
    }

    ProcessoPF buffer;
    while (fread(&buffer, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
        if (buffer.atividade) {
            ProcessoPF* node = (ProcessoPF*) malloc(sizeof(ProcessoPF));
            if (!node) {
                ProcessoPF* t = lista;
                while (t) {
                    ProcessoPF* nxt = t->prox;
                    free(t);
                    t = nxt;
                }
                fclose(arq_processoPF);
                printf("\nERRO: Falha na alocacao de memoria.\n");
                return NULL;
            }
            memcpy(node, &buffer, sizeof(ProcessoPF));
            node->prox = NULL;
            if (lista == NULL) {
                lista = node;
            } else {
                ultimo->prox = node;
            }
            ultimo = node;
        }
    }
    fclose(arq_processoPF);
    return lista;
}

ProcessoPJ* gerarLista_ProcPJ(void){
    ProcessoPJ* lista = NULL;
    ProcessoPJ* ultimo = NULL;
    FILE *arq_processoPJ = fopen("processoPJ.dat", "rb");
    if (arq_processoPJ == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return NULL;
    }

    ProcessoPJ buffer;
    while (fread(&buffer, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
        if (buffer.atividade) {
            ProcessoPJ* node = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
            if (!node) {
                ProcessoPJ* t = lista;
                while (t) {
                    ProcessoPJ* nxt = t->prox;
                    free(t);
                    t = nxt;
                }
                fclose(arq_processoPJ);
                printf("\nERRO: Falha na alocacao de memoria.\n");
                return NULL;
            }
            memcpy(node, &buffer, sizeof(ProcessoPJ));
            node->prox = NULL;
            if (lista == NULL) {
                lista = node;
            } else {
                ultimo->prox = node;
            }
            ultimo = node;
        }
    }
    fclose(arq_processoPJ);
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

void* proc_getProximo(void* item) {
    return ((ProcessoPF*)item)->prox;  //Essa função serve para ensinar o computador a caminhar na lista. Ela diz: Pegue esse item genérico, trate-o como um ProcessoPF e me dê o endereço do próximo item.  //como dar um mapa para a função genérica navegar pela sua lista encadeada.
}                                      //como dar um mapa para a função genérica navegar pela sua lista encadeada.

int proc_compararData(const void* a, const void* b) {
    ProcessoPF* pA = *(ProcessoPF**)a;
    ProcessoPF* pB = *(ProcessoPF**)b;
    int d1, m1, y1;
    int d2, m2, y2;
    
    sscanf(pA->data, "%d/%d/%d", &d1, &m1, &y1);
    sscanf(pB->data, "%d/%d/%d", &d2, &m2, &y2);
    if (y1 != y2) return y1 - y2;
    if (m1 != m2) return m1 - m2;

    return d1 - d2;
}


void* procPJ_getProximo(void* item) {
    return ((ProcessoPJ*)item)->prox;
}

int procPJ_compararData(const void* a, const void* b) {
    ProcessoPJ* pA = *(ProcessoPJ**)a;
    ProcessoPJ* pB = *(ProcessoPJ**)b;
    int d1, m1, y1;
    int d2, m2, y2;
    
    sscanf(pA->data, "%d/%d/%d", &d1, &m1, &y1);
    sscanf(pB->data, "%d/%d/%d", &d2, &m2, &y2);
    if (y1 != y2) return y1 - y2;
    if (m1 != m2) return m1 - m2;

    return d1 - d2;
}
