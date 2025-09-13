#include <stdio.h>
#include <stdlib.h>

#include "advogado.h"
#include "cliente.h"
#include "processosPF.h"
#include "empresa.h"
#include "processosPJ.h"
#include "sobre.h"
#include "equipe.h"

// Projeto Versão 0.1.0-rc1

int menu(void);
void telaSair(void);


int main(void) {
    int opcao = 1;
    while (opcao != 0) {
        opcao = menu();
        switch (opcao) {
        case 0:
            telaSair();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 1:
            int advOpcao = 1;
            while (advOpcao != 0) {
                advOpcao = menuAdvogado();
                switch (advOpcao)
                {
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraAdvogado();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraAdvogado();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaAdvogado();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiAdvogado();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            }
            break;
        case 2:
            int cliOpcao = 1;
            while (cliOpcao != 0) {
                cliOpcao = menuCliente();
                switch (cliOpcao){
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraCliente();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraCliente();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaCliente();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiCliente();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            }
            break;
        case 3:
            int procPfOpcao = 1;
            while (procPfOpcao != 0) {
                procPfOpcao = menuProcessoPF();
                switch (procPfOpcao){
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            } 
            break;
        case 4:
            int empOpcao=1;
            while (empOpcao != 0) {
                empOpcao = menuEmpresa();
                switch (empOpcao){
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            }
            break;
        case 5:
            int procPjOpcao = 1;
            while (procPjOpcao != 0) {
                procPjOpcao = menuProcessoPJ();
                switch (procPjOpcao){
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            } 
            break;
        case 6:
            printf("Relatorios\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 7:
            telaSobre();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 8:
            telaEquipe();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        default:
            printf("Voce digitou uma opcao invalida\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    }
    return 0;
}



int menu(void) {

    system("clear");
    int opcao;
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                     |\n");
    printf("|                                                                                                     |\n");                                                                                              
    printf("|     d888888o.    8 8888     ,o888888o.    8 8888                  .8. `8.`888b                 ,8'  |\n");
    printf("|   .`8888:' `88.  8 8888    8888     `88.  8 8888                 .888. `8.`888b               ,8'   |\n");
    printf("|   8.`8888.   Y8  8 8888 ,8 8888       `8. 8 8888                :88888. `8.`888b             ,8'    |\n");
    printf("|   `8.`8888.      8 8888 88 8888           8 8888               . `88888. `8.`888b     .b    ,8'     |\n");
    printf("|    `8.`8888.     8 8888 88 8888           8 8888              .8. `88888. `8.`888b    88b  ,8'      |\n");
    printf("|     `8.`8888.    8 8888 88 8888           8 8888             .8`8. `88888. `8.`888b .`888b,8'       |\n");
    printf("|      `8.`8888.   8 8888 88 8888   8888888 8 8888            .8' `8. `88888. `8.`888b8.`8888'        |\n");       
    printf("|  8b   `8.`8888.  8 8888 `8 8888       .8' 8 8888           .8'   `8. `88888. `8.`888`8.`88'         |\n");
    printf("|  `8b.  ;8.`8888  8 8888    8888     ,88'  8 8888          .888888888. `88888. `8.`8' `8,`'          |\n");
    printf("|   `Y8888P ,88P'  8 8888     `8888888P'    8 888888888888 .8'       `8. `88888. `8.`   `8'           |\n");
    printf("|                                                                                                     |\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                     |\n");
    printf("|                          1 - Módulo de Advogados                                                    |\n");
    printf("|                          2 - Módulo de Clientes                                                     |\n");
    printf("|                          3 - Módulo de Processos PF                                                 |\n");
    printf("|                          4 - Módulo de Empresas                                                     |\n");
    printf("|                          5 - Módulo de Processos PJ                                                 |\n");
    printf("|                          6 - Relatorios                                                             |\n");
    printf("|                          7 - Sobre                                                                  |\n");
    printf("|                          8 - Equipe                                                                 |\n");
    printf("|                          0 - Sair                                                                   |\n");
    printf("|                                                                                                     |\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcao);
    getchar();
    return opcao;
    
}



void telaSair(void) {

    system("clear");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                         Universidade Federal do Rio Grande do Norte                         |\n");
    printf("|                             Centro de Ensino Superior do Seridó                             |\n");
    printf("|                            Bacharelado em Sistemas de Informacao                            |\n");
    printf("|                               Disciplina DCT1106 - Programacao                              |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                  Voce encerrou o programa!                                  |\n");
    printf("|                                         Até Logo!                                           |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");

}