#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include "processosPF.h"
#include "processosPJ.h"

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
                moduloProcPF();
                break;
            case 2:
                moduloProcPJ();
                break;
            default:
                printf("Voce digitou uma opcao invalida\n");
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
    printf("|                +++++ Para qual módulo você deseja agendar um processo? +++++                |\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Processo p/ Pessoa Física                                      |\n");
    printf("|                          2 - Processo p/ Pessoa Jurídica                                    |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuProOpcao);
    getchar();
    return menuProOpcao;
}