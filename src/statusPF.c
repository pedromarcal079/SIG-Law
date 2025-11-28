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
                editarStatus();
                break;
            case 2:
                listarStatus();
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
    printf("|                           1 - Atualizar Status                                               |\n");
    printf("|                           2 - Listar Status                                                  |\n");
    printf("|                           0 - Voltar                                                         |\n");
    printf("|                                                                                              |\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuProOpcao);
    getchar();
    return menuProOpcao;
}



void editarStatus(void){

}



void listarStatus(void){
    FILE *arq_processoPF;
    ProcessoPF *processoPF;
    processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    int opcao;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Qual status deseja vizualizar?                                                       |\n");
    printf("|        1 - Em andamento                                                                     |\n");
    printf("|        2 - Concluído                                                                        |\n");
    scanf("%d", &opcao);
    getchar();

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
            printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
            printf("+------------------------------------------------------------------------------------------------------+\n");
            while(fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1){
                if(processoPF->atividade && strcmp(processoPF->status, "Em andamento") == 0){
                    printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
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
                if(processoPF->atividade && strcmp(processoPF->status, "Concluído") == 0){
                    printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
            }
            fclose(arq_processoPF);
            break;
    }
}

