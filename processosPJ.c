#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPJ.h"

    typedef struct processoPJ{
        int id;
        char tipo[30];              // cível, trabalhista, penal, tributário, família, etc.
        char autor[21];             // CNPJ
        char reu[21];               // CPF ou CNPJ
        char advOAB[20];          // carteira oab do advogado
        char descricao[200];
        char status[20];
        char data[13];
    } ProcessoPJ;

int gerarID(){
    ProcessoPJ *idProcPJ;
    idProcPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));

    FILE *arq_processoPJ;

    int ultimoID = 0;

    arq_processoPJ = fopen("processoPJ.dat","rb");
    if (arq_processoPJ == NULL){
        return 1;
    }

    while (fread(idProcPJ, sizeof(ProcessoPJ), 1, arq_processoPJ)) {
        ultimoID = idProcPJ->id;
    }
    fclose(arq_processoPJ);

    return ultimoID + 1;
    free(idProcPJ);
}

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
    FILE *arq_processoPJ;

    ProcessoPJ *processoPJ;
    processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));

    processoPJ->id = gerarID();

    int tam;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PJ                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|   ===> Tipo de processo: ");
    fgets(processoPJ->tipo, sizeof(processoPJ->tipo), stdin);
    tam = strlen(processoPJ->tipo);
    processoPJ->tipo[tam-1] = '\0';
    printf("|   ===> Autor (CNPJ): ");
    fgets(processoPJ->autor, sizeof(processoPJ->autor), stdin);
    tam = strlen(processoPJ->autor);
    processoPJ->autor[tam-1] = '\0';
    printf("|   ===> Réu (CNPJ ou CPF): ");
    fgets(processoPJ->reu, sizeof(processoPJ->reu), stdin);
    tam = strlen(processoPJ->reu);
    processoPJ->reu[tam-1] = '\0';
    printf("|   ===> Advogado Responsável (OAB): ");
    fgets(processoPJ->advOAB, sizeof(processoPJ->advOAB), stdin);
    tam = strlen(processoPJ->advOAB);
    processoPJ->advOAB[tam-1] = '\0';
    printf("|   ===> Descrição: ");
    fgets(processoPJ->descricao, sizeof(processoPJ->descricao), stdin);
    tam = strlen(processoPJ->descricao);
    processoPJ->descricao[tam-1] = '\0';
    printf("|   ===> Data de Cadastro: ");
    fgets(processoPJ->data, sizeof(processoPJ->data), stdin);
    tam = strlen(processoPJ->data);
    processoPJ->data[tam-1] = '\0';
    strcpy(processoPJ->status, "Em Andamento");

    arq_processoPJ = fopen("processoPJ.dat","ab");
    if (arq_processoPJ == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(processoPJ);
        return;
    }
    fwrite(processoPJ, sizeof(ProcessoPJ),1,arq_processoPJ);
    fclose(arq_processoPJ);

    printf("|                                                                                             |\n");
    printf("|        Processo cadastrado com sucesso!                                                     |\n");
    printf("|        O ID desse processo é: %d\n", processoPJ->id);
    free(processoPJ);
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
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