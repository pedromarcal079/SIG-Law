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

} 

void mostraHistorico(void){

}

void editaHistorico(void){

}

void excluiHistorico(void){

}