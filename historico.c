#include <stdio.h>
#include <stdlib.h>
#include "historico.h"

void moduloHistorico(void){

}

int menuHistorico(void) {
    system("clear");
    int opcaoHistorico;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                      Modulo de Histórico                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra histórico                                             |\n");
    printf("|                          2 - Mostra histórico                                               |\n");
    printf("|                          3 - Edita histórico                                                |\n");
    printf("|                          4 - Exclui histórico                                               |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcaoHistorico);
    getchar();
    return opcaoHistorico;
}

void cadastraHistorico(void) {
    system("clear");
    int idProcesso;
    char status[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Histórico                                   |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do histórico:                                                       |\n");
    printf("|   ===> ID do processo: ");
    scanf("%d",&idProcesso);
    getchar();
    printf("|   ===> Status do Processo: ");
    fgets(status, sizeof(status), stdin);
    printf("|                                                                                             |\n");
    printf("|        Histórico cadastrada com sucesso!                                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
} 

void mostraHistorico(void){
    system("clear");
    int id;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Historico                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Insira o ID do histórico: ");
    scanf("%d",&id);
    getchar();
    printf("|                                                                                             |\n");
    printf("|        ID do processo: 0001                                                                 |\n");
    printf("|        Status: Em andamento                                                                 |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}

void editaHistorico(void){

}

void excluiHistorico(void){

}