#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include "processoMenu.h"
#include "atualizaStatus.h"


void moduloAgendamento(void) {
    int menuProOpcao;
    do {
        menuProOpcao = agendamentoMenu();
        switch (menuProOpcao) {
            case 0:
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 1:
                moduloMenuProcesso();
                break;
            case 2:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|      Módulo de Agendamento em Andamento      |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 3:
                printf("irei fazer");
                break;
            case 4:
                moduloStatus();
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
    } while (menuProOpcao != 0);
}


int agendamentoMenu(void) {
    system("clear");
    int menuProOpcao;
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
    printf("|                          4 - Listar Processos                                               |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuProOpcao);
    getchar();
    return menuProOpcao;
}

