#include <stdio.h>
#include <stdlib.h>
#include "agendaProc.h"

void moduloAgendaProc(void) {
    int agenProc;
    do {
        agenProc = menuAgendaProc();
        switch (agenProc) {
            case 0:
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 1:
                agendaProces();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
                break;
            case 2:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Módulo em Andamento             |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 3:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Módulo em Andamento             |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 4:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Módulo em Andamento             |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            default:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
        }
    } while (agenProc != 0);
}

int menuAgendaProc(void) {
    system("clear");
    int menuAgendProc;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                              Menu do Agendamento de Processos                               |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Agenda processo                                                |\n");
    printf("|                          2 - Mostra processo agendado                                       |\n");
    printf("|                          3 - Edita processo agendado                                        |\n");
    printf("|                          4 - Exclui processo agendado                                       |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuAgendProc);
    getchar();
    return menuAgendProc;
}

int gerarID_Agenda(){
    Agendamento *idAgenda;
    idAgenda = (Agendamento*) malloc(sizeof(Agendamento));

    FILE *arq_agenda;

    int ultimoID = 0;

    arq_agenda = fopen("agendamento.dat","rb");
    if (arq_agenda == NULL){
        return 1;
    }

    while (fread(idAgenda, sizeof(Agendamento), 1, arq_agenda))
    {
        ultimoID = idAgenda->idAgend;
    }

    return ultimoID + 1;
    free(idAgenda);
}


void agendaProces(void) {
    system("clear");
    //FILE *arq_agenda;

    //Agendamento *agendamento;
    //agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    // agendamento->idAgend = gerarID_Agenda();
    
    // int tam;    
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Agendar Processo                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Módulo em Andamento:                                                                 |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


    // printf("|                                                                                             |\n");
    // printf("|        Cliente cadastrado com sucesso!                                                      |\n");
    // printf("|                                                                                             |\n");
    // printf("+---------------------------------------------------------------------------------------------+\n");