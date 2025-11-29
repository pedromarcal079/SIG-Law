#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statusPJ.h"

#include "processosPJ.h"

void moduloStatusPJ(void){
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
    printf("|                               Menu de Status - Pessoa Juridica                               |\n");
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
    scanf("%d",&menuProOpcao);
    getchar();
    return menuProOpcao;
}







void listarStatus(void){
    system("clear");
    FILE *arq_processoPJ;
    ProcessoPJ *processoPJ;
    processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    int opcao;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Qual status deseja vizualizar?                                                       |\n");
    printf("|        1 - Em Andamento                                                                     |\n");
    printf("|        2 - Concluído                                                                        |\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite sua opcao: ");
    scanf("%d", &opcao);
    getchar();

    printf("\n");
    switch(opcao){
        case 1:
            arq_processoPJ = fopen("processoPJ.dat", "rb");
            if (arq_processoPJ == NULL){
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
            while(fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1){
                if(strcmp(processoPJ->status, "Em Andamento") == 0){
                    if(processoPJ->atividade){
                        printf("|%-15d %-30s %-30s %-30s %-25s %-25s %-25s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                    }
                }
                printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            }
            fclose(arq_processoPJ);
            break;
        case 2:
            arq_processoPJ = fopen("processoPJ.dat", "rb");
            if (arq_processoPJ == NULL){
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
            while(fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1){
                if(strcmp(processoPJ->status, "Concluído") == 0){
                    if(processoPJ->atividade){
                        printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                    }
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
            }
            fclose(arq_processoPJ);
            break;
    }
}