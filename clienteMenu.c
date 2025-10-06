#include <stdio.h>
#include <stdlib.h>
#include "clienteMenu.h"
#include "clientePF.h"
#include "clientePJ.h"

void moduloMenuCliente(void) {
    int menuCliOpcao;
    do {
        menuCliOpcao = clienteMenu();
        switch (menuCliOpcao) {
            case 0:
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 1:
                moduloClientePF();
                break;
            case 2:
                moduloClientePJ();
                break;
            default:
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
        }
    } while (menuCliOpcao != 0);
}


int clienteMenu(void) {
    system("clear");
    int menuCliOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                      Módulo de Cliente                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                         +++++ Qual módulo você deseja acessar? +++++                        |\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cliente Pessoa Física                                          |\n");
    printf("|                          2 - Cliente Pessoa Jurídica                                        |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuCliOpcao);
    getchar();
    return menuCliOpcao;
}