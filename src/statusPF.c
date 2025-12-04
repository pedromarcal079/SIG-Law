#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statusPF.h"

#include "processosPF.h"

void moduloStatusPF(void){
    int menuProOpcao;
    do {
        menuProOpcao = menuStatus();
        switch(menuProOpcao){
            case 0:
                printf("Pressione ENTER ... \n");
                break;
            case 1:
                listarStatus();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
        }

    } while(menuProOpcao != 0);
}

int menuStatus(void){
    system("clear");
    int menuProOpcao;
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                              |\n");
    printf("|                                Menu de Status - Pessoa Física                                |\n");
    printf("|                                                                                              |\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                              |\n");
    printf("|                          +++++ Qual módulo você deseja acessar? +++++                        |\n");
    printf("|                                                                                              |\n");
    printf("|                           1 - Listar Status                                                  |\n");
    printf("|                           0 - Voltar                                                         |\n");
    printf("|                                                                                              |\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    if (scanf("%d", &menuProOpcao) != 1) {
        menuProOpcao = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        int c = getchar(); (void)c;
    }
    return menuProOpcao;
}







void listarStatus(void){
    system("clear");
    FILE *arq_processoPF;
    ProcessoPF *processoPF;
    processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    if (!processoPF) {
        printf("\nERRO: Falha na alocacao de memoria.\n");
        return;
    }
    int opcao;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Qual status deseja vizualizar?                                                       |\n");
    printf("|        1 - Em Andamento                                                                     |\n");
    printf("|        2 - Concluído                                                                        |\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite sua opcao: ");
    if (scanf("%d", &opcao) != 1) {
        opcao = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        int c = getchar(); (void)c;
    }

    printf("\n");
    switch(opcao){
        case 1:
            arq_processoPF = fopen("processoPF.dat", "rb");
            if (arq_processoPF == NULL){
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|           Erro ao abrir o arquivo!           |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                return;
            }
            printf(" %-15s %-35s %-30s %-27s %-22s %-30s %-25s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "Descrição", "Data", "Status");
            printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            while(fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1){
                if(strcmp(processoPF->status, "Em Andamento") == 0){
                    if(processoPF->atividade){
                        printf("|%-15d %-30s %-30s %-30s %-25s %-25s %-25s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                    }
                }
                printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            }
            fclose(arq_processoPF);
            break;
        case 2:
            arq_processoPF = fopen("processoPF.dat", "rb");
            if (arq_processoPF == NULL){
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|           Erro ao abrir o arquivo!           |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                return;
            }
            printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
            printf("+------------------------------------------------------------------------------------------------------+\n");
            while(fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1){
                if(strcmp(processoPF->status, "Concluído") == 0){
                    if(processoPF->atividade){
                        printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                    }
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
            }
            fclose(arq_processoPF);
            break;
    }
    free(processoPF);
}

