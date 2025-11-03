#include <stdio.h>
#include <stdlib.h>
#include "menuAgendamento.h"
#include "processoMenu.h"
#include "agendaProc.h"


void moduloAgendamento(void) {
    int menuAgend;
    do {
        menuAgend = agendamentoMenu();
        switch (menuAgend) {
            case 0:
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 1:
                moduloMenuProcesso();
                break;
            case 2:
                moduloAgendaProc();
                break;
            case 3:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|         Módulo de Status em Andamento        |\n");
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
    } while (menuAgend != 0);
}


int agendamentoMenu(void) {
    system("clear");
    int menuAgend;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Módulo de Agendamento                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                         +++++ Qual módulo você deseja acessar? +++++                        |\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastrar Processos                                            |\n");
    printf("|                          2 - Agendar Processos                                              |\n");
    printf("|                          3 - Atualizar Status do Processo                                   |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuAgend);
    getchar();
    return menuAgend;
}