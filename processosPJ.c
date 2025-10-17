#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPJ.h"

    // typedef struct processoPJ{
    //     int id;
    //     char tipo[30];              // cível, trabalhista, penal, tributário, família, etc.
    //     char autor[21];             // CNPJ
    //     char reu[21];               // CPF ou CNPJ
    //     char advogadoOAB[20];          // carteira oab do advogado
    //     char descricao[200];
    //     char status[20];
    //     char data[13];
    //     char observacoes[200];
    //     char tipoPessoa[3];         // "PF" ou "PJ"
    // } ProcessoPJ;

void moduloProcPJ(void) {
    int procPjOpcao;
    do {
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
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|       Você digitou uma opção inválida!       |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    } while (procPjOpcao != 0);
}

int menuProcessoPJ(void) {
    system("clear");
    int procPjOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Menu de Processos PJ                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra processo                                              |\n");
    printf("|                          2 - Mostra processo                                                |\n");
    printf("|                          3 - Edita processo                                                 |\n");
    printf("|                          4 - Exclui processo                                                |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&procPjOpcao);
    getchar();
    return procPjOpcao;
}


void cadastraProcessoPJ(void) {
    system("clear");
    char tipo[50];
    char data[50];
    int tam;
    FILE *arq_processoPJ;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PJ                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|   ===> Tipo de processo: ");
    fgets(tipo, sizeof(tipo), stdin);
    tam = strlen(tipo);
    tipo[tam-1] = '\0';
    printf("|   ===> Data de abertura: ");
    fgets(data, sizeof(data), stdin);
    tam = strlen(tipo);
    tipo[tam-1] = '\0';
    printf("|                                                                                             |\n");
    printf("|        Processo cadastrado com sucesso!                                                     |\n");
    printf("|        O número desse processo é: 00000                                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_processoPJ = fopen("processoPF.csv","at");
    fprintf(arq_processoPJ, "%s;", tipo);
    fprintf(arq_processoPJ, "%s\n", data);
    fclose(arq_processoPJ);
}


void mostraProcessoPJ(void) {
    system("clear");
    char procNum[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Tipo de processo: Civil                                                              |\n");
    printf("|        Data de abertura: 31/08/2025                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaProcessoPJ(void) {
    system("clear");
    char procNum[15];
    char tipo[50];
    char data[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PJ                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Digite os novos dados:                                                               |\n");
    printf("|        Tipo: ");
    fgets(tipo, sizeof(tipo), stdin);  
    printf("|        Data: ");
    fgets(data, sizeof(data), stdin);  
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiProcessoPJ(void) {
    system("clear");
    char procNum[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Processo excluido com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}