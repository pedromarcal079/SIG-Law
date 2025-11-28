#include <stdio.h>
#include <stdlib.h>
#include "atualizaStatus.h"
#include "statusPF.h"


void moduloStatus(void){
    int menuProOpcao;
    do {
        menuProOpcao = statusPro();
        switch (menuProOpcao){
            case 0:
                printf("Pressione ENTER ... \n");
                break;
            case 1:
                moduloStatusPF();
                break;
            case 2:
                //moduloStatusPJ();
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



int statusPro(void){
    system("clear");
    int menuProOpcao;
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                              |\n");
    printf("|                                       Módulo de Status                                       |\n");
    printf("|                                                                                              |\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                              |\n");
    printf("|                          +++++ Qual módulo você deseja acessar? +++++                        |\n");
    printf("|                                                                                              |\n");
    printf("|                           1 - Status Pessoa Física                                           |\n");
    printf("|                           2 - Status Pessoa Jurídica                                         |\n");
    printf("|                           0 - Voltar                                                         |\n");
    printf("|                                                                                              |\n");
    printf("+----------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuProOpcao);
    getchar();
    return menuProOpcao;
}