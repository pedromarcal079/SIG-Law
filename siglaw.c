#include <stdio.h>
#include <stdlib.h>

#include "advogado.h"
#include "clienteMenu.h"
#include "agendamento.h"
#include "historico.h"
#include "sobre.h"
#include "equipe.h"

// Projeto Versão 0.1.0-rc1

int menu(void);
void telaSair(void);


int main(void) {
    int opcao;
    do {
        opcao = menu();
        switch (opcao) {
        case 0:
            telaSair();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 1:
            moduloAdvogado();
            break;
        case 2:
            moduloMenuCliente();
            break;
        case 3:
            moduloAgendamento();
            break;
        case 4:
            moduloHistorico();
            break;
        case 5:
            printf("Relatorios\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 6:
            telaSobre();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 7:
            telaEquipe();
            printf("Pressione ENTER ... \n");
            getchar();
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
    } while (opcao != 0);
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
    printf("|                          3 - Módulo de Agendamento                                                  |\n");
    printf("|                          5 - Módulo de Historico                                                    |\n");
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