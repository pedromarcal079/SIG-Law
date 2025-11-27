#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "advogado.h"

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