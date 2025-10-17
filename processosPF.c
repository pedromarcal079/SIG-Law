#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPF.h"

    typedef struct processoPF{
        // int id;
        char tipo[30];              // cível, trabalhista, penal, tributário, família, etc.
        // char autor[16];             // CPF
        // char reu[21];               // CPF ou CNPJ
        // char advogadoOAB[20];          // carteira oab do advogado
        // char descricao[200];
        // char status[20];
        char data[13];
        // char observacoes[200];
        // char tipoPessoa[3];         // "PF" ou "PJ"
    } ProcessoPF;

void moduloProcPF(void) {
    int procPfOpcao;
    do {
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
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|       Você digitou uma opção inválida!       |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    } while (procPfOpcao != 0);
}

int menuProcessoPF(void) {
    system("clear");
    int procPfOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Menu de Processos PF                                     |\n");
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
    scanf("%d",&procPfOpcao);
    getchar();
    return procPfOpcao;
}


void cadastraProcessoPF(void) {
    system("clear");
    ProcessoPF processoPF;
    int tam;
    FILE *arq_processoPF;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PF                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|   ===> Tipo de processo: ");
    fgets(processoPF.tipo, sizeof(processoPF.tipo), stdin);
    tam = strlen(processoPF.tipo);
    processoPF.tipo[tam-1] = '\0';
    printf("|   ===> Data de abertura: ");
    fgets(processoPF.data, sizeof(processoPF.data), stdin);
    tam = strlen(processoPF.data);
    processoPF.data[tam-1] = '\0';
    printf("|                                                                                             |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_processoPF = fopen("processoPF.csv","at");
    fscanf(arq_processoPF, "%s;%s\n", processoPF.tipo, processoPF.data);
    fprintf(arq_processoPF, "%s;", processoPF.tipo);
    fprintf(arq_processoPF, "%s\n", processoPF.data);
    fclose(arq_processoPF);
}


void mostraProcessoPF(void) {
    system("clear");
    FILE* arq_processoPF;
    ProcessoPF processoPF;
    char procNum[15];
    int tam;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                  Mostrar Processo PF                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    tam = strlen(procNum);
    procNum[tam-1] = '\0';
    arq_processoPF = fopen("processoPF.csv", "rt");
    while (fscanf(arq_processoPF,"%[^;];%[^\n]\n",processoPF.tipo, processoPF.data)){
        printf("|\t\tEmail: %s\n", processoPF.tipo);
        printf("|\t\tTelefone: %s\n", processoPF.data);
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
        return;
    }
    printf("|                                                                                             |\n");
    printf("|        Tipo de processo: Civil                                                              |\n");
    printf("|        Data de abertura: 31/08/2025                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaProcessoPF(void) {
    system("clear");
    char procNum[15];
    char tipo[50];
    char data[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PF                                       |\n");
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


void excluiProcessoPF(void) {
    system("clear");
    char procNum[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                  Excluir Processo PF                                        |\n");
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