#include <stdio.h>
#include <stdlib.h>
#include "processoMenu.h"
#include "processosPF.h"
#include "processosPJ.h"

void moduloMenuProcesso(void) {
    int menuProOpcao;
    do {
        menuProOpcao = processoMenu();
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


int processoMenu(void) {
    system("clear");
    int menuProOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Módulo de Processos                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                         +++++ Qual módulo você deseja acessar? +++++                        |\n");
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