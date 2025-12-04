#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPJ.h"
#include "processosPF.h"
#include "clientePF.h"
#include "clientePJ.h"
#include "advogado.h"
#include "validacao.h"
#include "utilidades.h"

#define MAX_ID_LEN 20

char* gerarID_PJ(){
    FILE *arq_processoPJ = NULL;
    ProcessoPJ *idProcPJ = NULL;
    char *idString = NULL;
    int ultimoID = 0;
    int novoID;

    idProcPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    if(idProcPJ == NULL){
        return NULL;
    }


    arq_processoPJ = fopen("processoPJ.dat","rb");
    
    if(arq_processoPJ != NULL){
        while(fread(idProcPJ, sizeof(ProcessoPJ), 1, arq_processoPJ)){
            ultimoID = idProcPJ->id;
        }
        fclose(arq_processoPJ);
    }

    free(idProcPJ);
    novoID = ultimoID + 1;

    idString = (char*) malloc(MAX_ID_LEN * sizeof(char));

    if(idString == NULL){
        return NULL;
    }

    snprintf(idString, MAX_ID_LEN, "%d", novoID);
    return idString;
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
        case 5:
            lixeiraProcessoPJ();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 6:
            relatorioProcessosPJ();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 7:
            listaProcessosPJ();
            printf("Pressione ENTER ... \n");
            getchar();
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
    printf("|                          1 - Cadastra processo PJ                                           |\n");
    printf("|                          2 - Mostra processo PJ                                             |\n");
    printf("|                          3 - Edita processo PJ                                              |\n");
    printf("|                          4 - Exclui processo PJ                                             |\n");
    printf("|                          5 - Lixeira Processo PJ                                            |\n");
    printf("|                          6 - Relatório Processo PJ                                          |\n");
    printf("|                          7 - Lista processos PJ                                             |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    if (scanf("%d", &procPjOpcao) != 1) {
        procPjOpcao = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        int c = getchar(); (void)c;
    }
    return procPjOpcao;
}


void cadastraProcessoPJ(void) {
    system("clear");
    ProcessoPJ *processoPJ = NULL;
    ClientePJ *clientePJ = NULL;
    Advogado *advogado = NULL;
    char *novoID_str = NULL;
    FILE *arq_processoPJ = NULL;
    FILE *arq_clientePJ = NULL;
    FILE *temp_clientePJ = NULL;
    FILE *arq_advogado = NULL;
    FILE *temp_advogado = NULL;
    int tipo;

    processoPJ = (ProcessoPJ*)malloc(sizeof(ProcessoPJ));
    if(processoPJ == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o processo. \n");
        getchar();
        return;
    }

    clientePJ = (ClientePJ*)malloc(sizeof(ClientePJ));
    if(clientePJ == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o Cliente.\n");
        free(processoPJ);
        getchar();
        return;
    }

    advogado = (Advogado*)malloc(sizeof(Advogado));
    if(advogado == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o Advogado.\n");
        free(processoPJ);
        free(clientePJ);
        getchar();
        return;
    }

    novoID_str = gerarID_PJ();
    if(novoID_str == NULL){
        printf("\nERRO: Falha ao gerar o novo ID do Processo.\n");
        free(processoPJ);
        free(clientePJ);
        getchar();
        return;
    }

    processoPJ->atividade = 1;


    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PJ                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|   ===> Tipo de processo: ");
    printf("| 1-Civil  2-Penal  3-Do Trabalho  4-Tributário  5-Empresarial |\n");
    printf("Digite a opção desejada:");
    scanf("%d", &tipo);
    getchar();
    switch (tipo){
        case 1: (strcpy(processoPJ->tipo, "Civil")); break;
        case 2: (strcpy(processoPJ->tipo, "Penal")); break;
        case 3: (strcpy(processoPJ->tipo, "Do Trabalho")); break;
        case 4: (strcpy(processoPJ->tipo, "Tributário")); break;
        case 5: (strcpy(processoPJ->tipo, "Empresarial")); break;
    }
    input(processoPJ->autor, sizeof(processoPJ->autor), "|   ===> Autor (CNPJ): ");                            
    input(processoPJ->reu, sizeof(processoPJ->reu), "|   ===> Réu (CNPJ ou CPF): ");
    input(processoPJ->advOAB, sizeof(processoPJ->advOAB), "|   ===> Advogado Responsável (OAB): ");
    input(processoPJ->descricao, sizeof(processoPJ->descricao), "|   ===> Descrição do processo: ");
    do {
        input(processoPJ->data, sizeof(processoPJ->data), "|   ===> Data de agendamento: ");
    } while (!vali_data(processoPJ->data));
    strcpy(processoPJ->status, "Em Andamento");

    processoPJ->id = atoi(novoID_str);

    arq_advogado = fopen("advogado.dat", "rb");
    if(arq_advogado == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de advogados (advogado.dat)!");
        free(processoPJ);
        free(clientePJ);
        free(advogado);
        free(novoID_str);
        getchar();
        return;
    }

    temp_advogado = fopen("temp_advogado.dat", "wb");
    if(temp_advogado == NULL){
        printf("\nERRO: Nao foi possivel criar o arquivo temporario (temp_advogado.dat)!");
        fclose(arq_advogado);
        free(processoPJ);
        free(clientePJ);
        free(advogado);
        free(novoID_str);
        getchar();
        return;
    }

    arq_processoPJ = fopen("processoPJ.dat","ab");
    if (arq_processoPJ == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de processos (processosPJ.dat)!");
        fclose(arq_advogado);
        fclose(temp_advogado);
        free(processoPJ);
        free(clientePJ);
        free(advogado);
        free(novoID_str);
        getchar();
        return;
    }

    arq_clientePJ = fopen("clientePJ.dat", "rb");
    if(arq_clientePJ == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de clientes (clientePJ.dat)!");
        fclose(arq_processoPJ);
        fclose(arq_advogado);
        fclose(temp_advogado);
        free(processoPJ);
        free(clientePJ);
        free(advogado);
        free(novoID_str);
        getchar();
        return;
    }

    temp_clientePJ = fopen("temp_clientePJ.dat", "wb");
    if(temp_clientePJ == NULL){
        printf("\nERRO: Nao foi possivel criar o arquivo temporario (temp_clientePJ.dat)!");
        fclose(arq_clientePJ);
        fclose(arq_processoPJ);
        fclose(arq_advogado);
        fclose(temp_advogado);
        free(processoPJ);
        free(clientePJ);
        free(advogado);
        free(novoID_str);
        getchar();
        return;
    }

    rewind(arq_advogado);
    rewind(arq_clientePJ);

    while(fread(clientePJ, sizeof(ClientePJ), 1, arq_clientePJ) == 1){
        if(strcmp(processoPJ->autor, clientePJ->cnpj) == 0){
            strcpy(clientePJ->idProcesso, novoID_str);
            fwrite(clientePJ, sizeof(ClientePJ), 1, temp_clientePJ);
        }
        else if(strcmp(processoPJ->reu, clientePJ->cnpj) == 0){
            strcpy(clientePJ->idProcesso, novoID_str);
            fwrite(clientePJ, sizeof(ClientePJ), 1, temp_clientePJ);
        }else{
            fwrite(clientePJ, sizeof(ClientePJ), 1, temp_clientePJ);
        }
    }

    while(fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
        if(strcmp(processoPJ->advOAB, advogado->carteiraOAB) == 0){
            strcpy(advogado->idProcessoPJ, novoID_str);
            fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
        }
        else{
            fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
        }
    }

    fwrite(processoPJ, sizeof(ProcessoPJ),1,arq_processoPJ);

    fclose(arq_clientePJ);
    fclose(temp_clientePJ);
    fclose(arq_advogado);
    fclose(arq_processoPJ);
    fclose(temp_advogado);

    remove("clientePJ.dat");
    if(rename("temp_clientePJ.dat", "clientePJ.dat") != 0){
        perror("ERRO CRITICO AO RENOMEAR O ARQUIVO DE CLIENTE");
        printf("\n*** AVISO: Os dados do cliente foram salvos em temp_cliente.dat! ***");
        getchar();
    }

    remove("advogado.dat");
    if(rename("temp_advogado.dat", "advogado.dat") != 0){
        perror("ERRO CRITICO AO RENOMEAR O ARQUIVO DE ADVOGADO");
        printf("\n*** AVISO: Os dados do advogado foram salvos em temp_advogado.dat! ***");
        getchar();
    }
    rename("temp_advogado.dat", "advogado.dat");

    printf("|                                                                                             |\n");
    printf("|        Processo cadastrado com sucesso!                                                     |\n");
    printf("|        O ID desse processo é: %d\n", processoPJ->id);
    free(processoPJ);
    free(clientePJ);
    free(advogado);
    free(novoID_str);
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}



void mostraProcessoPJ(void) {
    system("clear");

    FILE *arq_processoPJ, *arq_clientePJ, *arq_clientePF, *arq_advogado;

    ProcessoPJ *processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));
    
    if (!processoPJ || !clientePJ || !clientePF || !advogado) {
        printf("Erro: Falha na alocacao de memoria.\n");
        if (processoPJ) free(processoPJ);
        if (clientePJ) free(clientePJ);
        if (clientePF) free(clientePF);
        if (advogado) free(advogado);
        return;
    }

    char pesquisar_id[5];
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|   ===> Digite o ID do processo: ");
    input(pesquisar_id, sizeof(pesquisar_id), "|   ===> Digite o ID do Processo: ");

    arq_processoPJ = fopen("processoPJ.dat","rb");
    arq_clientePJ = fopen("clientePJ.dat","rb");
    arq_clientePF = fopen("clientePF.dat","rb");
    arq_advogado = fopen("advogado.dat","rb");

       if (arq_processoPJ == NULL || arq_clientePJ == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        if (arq_clientePF) fclose(arq_clientePF);
        if (arq_advogado) fclose(arq_advogado);
        if (arq_processoPJ) fclose(arq_processoPJ);
        if (arq_clientePJ) fclose(arq_clientePJ);
        free(clientePJ);
        free(advogado);
        free(processoPJ);
        free(clientePF);
        return;
    }

    while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
        int pesqID = atoi(pesquisar_id);
        if (processoPJ->id == pesqID) {
            encontrado = 1;
            if (processoPJ->atividade == 1){
                if (encontraClientePJ(clientePJ, processoPJ->autor, arq_clientePJ)) {
                    printf("|\t\tAutor: %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else {
                    printf("|\t\tAutor: Não encontrado!\n");
                }

                if (encontraClientePF(clientePF, processoPJ->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else if (encontraClientePJ(clientePJ, processoPJ->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }
                if (arq_advogado) {
                    rewind(arq_advogado);
                    while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                        if (strcmp(advogado->carteiraOAB, processoPJ->advOAB) == 0) {
                            printf("|\t\tAdvogado Responsável: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                        }
                    }
                } else {
                    printf("|\t\tAdvogado Responsável: Arquivo de advogados indisponível.\n");
                }

                printf("|\t\tTipo: %s\n", processoPJ->tipo);
                printf("|\t\tData de abertura: %s\n", processoPJ->data);
                printf("|\t\tDescrição: %s\n", processoPJ->descricao);
                printf("|\t\tStatus: %s\n", processoPJ->status);
                if (arq_processoPJ) fclose(arq_processoPJ);
                if (arq_clientePJ) fclose(arq_clientePJ);
                if (arq_clientePF) fclose(arq_clientePF);
                if (arq_advogado) fclose(arq_advogado);
                free(processoPJ);
                free(clientePJ);
                free(clientePF);
                free(advogado);
                return;
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Processo Inativo!               |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                if (arq_processoPJ) fclose(arq_processoPJ);
                if (arq_clientePJ) fclose(arq_clientePJ);
                if (arq_clientePF) fclose(arq_clientePF);
                if (arq_advogado) fclose(arq_advogado);
                free(processoPJ);
                free(clientePJ);
                free(clientePF);
                free(advogado);
                return;
            }
        }
    }

    if (arq_processoPJ) fclose(arq_processoPJ);
    if (arq_clientePJ) fclose(arq_clientePJ);
    if (arq_clientePF) fclose(arq_clientePF);
    if (arq_advogado) fclose(arq_advogado);

    if (!encontrado) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Processo não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    }
    
    free(processoPJ);
    free(clientePJ);
    free(clientePF);
    free(advogado);
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}



void editaProcessoPJ(void) {
    system("clear");
    FILE *arq_processoPJ, *temp_processoPJ, *arq_clientePJ, *arq_clientePF, *arq_advogado;

    ProcessoPJ *processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));
    
    if (!processoPJ || !clientePJ || !clientePF || !advogado) {
        printf("\nERRO: Falha na alocacao de memoria.\n");
        if (processoPJ) free(processoPJ);
        if (clientePJ) free(clientePJ);
        if (clientePF) free(clientePF);
        if (advogado) free(advogado);
        return;
    }

    char pesquisar_id[5];
    int dado;
    int encontrado = 0;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PJ                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o ID do processo: ");
    input(pesquisar_id, sizeof(pesquisar_id), "|   ===> Digite o ID do Processo: ");

    arq_processoPJ = fopen("processoPJ.dat", "rb");
    arq_clientePF = fopen("clientePF.dat","rb");
    arq_clientePJ = fopen("clientePJ.dat","rb");
    arq_advogado = fopen("advogado.dat","rb");
    temp_processoPJ = fopen("temp_processoPJ.dat", "wb");
    if (arq_processoPJ == NULL || temp_processoPJ == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        if (arq_clientePF) fclose(arq_clientePF);
        if (arq_clientePJ) fclose(arq_clientePJ);
        if (arq_advogado) fclose(arq_advogado);
        if (arq_processoPJ) fclose(arq_processoPJ);
        if (temp_processoPJ) fclose(temp_processoPJ);
        free(processoPJ);
        free(clientePF);
        free(clientePJ);
        free(advogado);
        return;
    }

    while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
        int pesqID = atoi(pesquisar_id);
        if (processoPJ->id == pesqID) {
            encontrado = 1;
            if (processoPJ->atividade == 1) {
                if (encontraClientePJ(clientePJ, processoPJ->autor, arq_clientePJ)) {
                    printf("|\t\tAutor: %s (CNPJ): %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else {
                    printf("|\t\tAutor: Não encontrado!\n");
                }

                if (encontraClientePF(clientePF, processoPJ->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else if (encontraClientePJ(clientePJ, processoPJ->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }
                if (arq_advogado) {
                    rewind(arq_advogado);
                    while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                        if (strcmp(advogado->carteiraOAB, processoPJ->advOAB) == 0) {
                            printf("|\t\tAdvogado Responsável: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                        }
                    }
                } else {
                    printf("|\t\tAdvogado Responsável: Arquivo de advogados indisponível.\n");
                }
                printf("|\t\tTipo: %s\n", processoPJ->tipo);
                printf("|\t\tData de abertura: %s\n", processoPJ->data);
                printf("|\t\tDescrição: %s\n", processoPJ->descricao);
                printf("|\t\tStatus: %s\n", processoPJ->status);
                printf("|                                                                                             |\n");

                printf("+---------------------------------------------------------------------------------------------+\n");
                printf("|                                                                                             |\n");
                printf("|   ===> Qual dado você deseja editar?                                                        |\n");
                printf("|        1 - Autor (CNPJ)                                                                      |\n");
                printf("|        2 - Réu (CNPJ ou CPF)                                                                |\n");
                printf("|        3 - Advogado Responsável (OAB)                                                       |\n");
                printf("|        4 - Tipo                                                                             |\n");
                printf("|        5 - Data de agendamento                                                              |\n");
                printf("|        6 - Descrição                                                                        |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                printf("===> Digite sua opcao: ");
                if (scanf("%d", &dado) != 1) {
                    dado = -1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) { }
                } else {
                    int c = getchar(); (void)c;
                }

                if (dado < 1 || dado > 6) {
                    system("clear");
                    printf("+----------------------------------------------+\n");
                    printf("|                                              |\n");
                    printf("|       Você digitou uma opção inválida!       |\n");
                    printf("|                                              |\n");
                    printf("+----------------------------------------------+\n");
                    // cleanup before returning
                    if (arq_processoPJ) fclose(arq_processoPJ);
                    if (arq_advogado) fclose(arq_advogado);
                    if (arq_clientePF) fclose(arq_clientePF);
                    if (arq_clientePJ) fclose(arq_clientePJ);
                    if (temp_processoPJ) fclose(temp_processoPJ);
                    free(processoPJ);
                    free(clientePF);
                    free(clientePJ);
                    free(advogado);
                    return;
                } else {
                    switch (dado) {
                        case 1: {
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Autor (CNPJ): "); 
                            strcpy(processoPJ->autor, edicao);
                        }; break;
                        case 2:{
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Réu (CNPJ ou CPF): "); 
                            strcpy(processoPJ->reu, edicao);
                        }; break;
                        case 3: {
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Advogado Responsável (OAB): "); 
                            strcpy(processoPJ->advOAB, edicao);
                        }; break;
                        case 4: {
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Tipo: "); 
                            strcpy(processoPJ->tipo, edicao);
                        }; break;
                        case 5: {
                            input(edicao, sizeof(edicao), "|   ===> Digite a nova Data de Abertura: "); 
                            strcpy(processoPJ->data, edicao);
                        }; break;
                        case 6: {
                            input(edicao, sizeof(edicao), "|   ===> Digite a nova Descrição: "); 
                            strcpy(processoPJ->descricao, edicao);
                        }; break;
                    }
                }
            } else{
                system("clear");
                printf("+---------------------------------------------+\n");
                printf("|                                             |\n");
                printf("|              Processo Inativo!              |\n");
                printf("|                                             |\n");
                printf("+---------------------------------------------+\n");
                if (temp_processoPJ) fclose(temp_processoPJ);
                if (arq_processoPJ) fclose(arq_processoPJ);
                if (arq_advogado) fclose(arq_advogado);
                if (arq_clientePF) fclose(arq_clientePF);
                if (arq_clientePJ) fclose(arq_clientePJ);
                remove("temp_processoPJ.dat");
                free(processoPJ);
                free(clientePF);
                free(clientePJ);
                free(advogado);
                return;
            }
        }
        fwrite(processoPJ, sizeof(ProcessoPJ), 1, temp_processoPJ);
    }
    fclose(arq_processoPJ);
    fclose(temp_processoPJ);
    fclose(arq_advogado);
    fclose(arq_clientePF);
    fclose(arq_clientePJ);

    
    if (encontrado) {
        remove("processoPJ.dat");
        rename("temp_processoPJ.dat", "processoPJ.dat");
        printf("|                                                                                             |\n");
        printf("|        Dados atualizados com sucesso!                                                       |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    } else {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Processo não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        remove("temp_processoPJ.dat");
    }
    free(processoPJ);
    free(clientePF);
    free(clientePJ);
    free(advogado);
}


void excluiProcessoPJ(void) {
    system("clear");

    FILE *arq_processoPJ;
    FILE *arq_clientePJ;
    FILE *arq_clientePF;
    FILE *arq_advogado;

    ProcessoPJ *processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

    if (!processoPJ || !clientePJ || !clientePF || !advogado) {
        printf("Erro: Falha na alocacao de memoria.\n");
        if (processoPJ) free(processoPJ);
        if (clientePJ) free(clientePJ);
        if (clientePF) free(clientePF);
        if (advogado) free(advogado);
        return;
    }

    char pesquisar_id[5];
    int confi;
    int encontrado = 0;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    input(pesquisar_id, sizeof(pesquisar_id), "|   ===> Digite o ID do Processo: ");

    arq_processoPJ = fopen("processoPJ.dat", "r+b");
    arq_clientePJ = fopen("clientePJ.dat", "rb");
    arq_clientePF = fopen("clientePF.dat", "rb");
    arq_advogado = fopen("advogado.dat", "rb");

    if (arq_processoPJ == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        if (arq_clientePJ) fclose(arq_clientePJ);
        if (arq_clientePF) fclose(arq_clientePF);
        if (arq_advogado) fclose(arq_advogado);
        free(processoPJ);
        free(clientePF);
        free(clientePJ);
        free(advogado);
        return;
    }

    while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
        int idBusca = atoi(pesquisar_id);

        if (processoPJ->id == idBusca) {
            encontrado = 1;
            if (encontraClientePJ(clientePJ, processoPJ->autor, arq_clientePJ)) {
                printf("|\t\tAutor: %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
            } else {
                printf("|\t\tAutor: Não encontrado!\n");
            }

            if (encontraClientePF(clientePF, processoPJ->reu, arq_clientePF)) {
                printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
            } else if (encontraClientePJ(clientePJ, processoPJ->reu, arq_clientePJ)) {
                printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
            } else {
                printf("|\t\tRéu: Não encontrado!\n");
            }

            if (arq_advogado) {
                rewind(arq_advogado);
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPJ->advOAB) == 0) {
                        printf("|\t\tAdvogado: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                    }
                }
            } else {
                printf("|\t\tAdvogado: Arquivo de advogados indisponível.\n");
            }

            printf("|\t\tTipo: %s\n", processoPJ->tipo);
            printf("|\t\tData de abertura: %s\n", processoPJ->data);
            printf("|\t\tDescrição: %s\n", processoPJ->descricao);
            printf("|\t\tStatus: %s\n", processoPJ->status);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o processo que deseja excluir? 1 = Sim, 2 = Não: ");
            if (scanf("%d", &confi) != 1) {
                confi = -1;
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
            } else {
                int c = getchar(); (void)c;
            }

            if (confi == 1) {
                processoPJ->atividade = 0;
                fseek(arq_processoPJ, -sizeof(ProcessoPJ), SEEK_CUR);
                fwrite(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ);
                printf("|                                                                                             |\n");
                printf("|        Processo excluído com sucesso!                                                       |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                if (arq_processoPJ) fclose(arq_processoPJ);
                if (arq_clientePJ) fclose(arq_clientePJ);
                if (arq_clientePF) fclose(arq_clientePF);
                if (arq_advogado) fclose(arq_advogado);
                free(processoPJ);
                free(clientePF);
                free(clientePJ);
                free(advogado);
                return;
            } else if (confi == 2) {
                printf("|                                                                                             |\n");
                printf("|        Exclusão cancelada!                                                                  |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                if (arq_processoPJ) fclose(arq_processoPJ);
                if (arq_clientePJ) fclose(arq_clientePJ);
                if (arq_clientePF) fclose(arq_clientePF);
                if (arq_advogado) fclose(arq_advogado);
                free(processoPJ);
                free(clientePF);
                free(clientePJ);
                free(advogado);
                return;
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                fclose(arq_processoPJ);
                fclose(arq_clientePJ);
                fclose(arq_clientePF);
                fclose(arq_advogado);
                free(processoPJ);
                free(clientePF);
                free(clientePJ);
                free(advogado);
                return;
            }
        }
    }

    if (arq_processoPJ) fclose(arq_processoPJ);
    if (arq_clientePJ) fclose(arq_clientePJ);
    if (arq_clientePF) fclose(arq_clientePF);
    if (arq_advogado) fclose(arq_advogado);

    if (!encontrado) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|          Processo não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    }
    free(processoPJ);
    free(clientePF);
    free(clientePJ);
    free(advogado); 
}

void lixeiraProcessoPJ(void) {
    system("clear");
    FILE *arq_processoPJ;
    FILE *temp_processoPJ;
    ProcessoPJ *processoPJ;
    processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    if (processoPJ == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        free(processoPJ);
        return;
    }
    int opcao;
    int encontrado = 0;
    char pesquisar_id[5];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Lixeira Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Você deseja restaurar um processo ou esvaziar a lixeira? (1- Restaurar / 2- esvaziar)|\n");
    if (scanf("%d", &opcao) != 1) {
        opcao = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        int c = getchar(); (void)c;
    }
    if (opcao == 1) {
        arq_processoPJ = fopen("processoPJ.dat", "r+b");
        if (arq_processoPJ == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(processoPJ);
        return;
    }
        input(pesquisar_id, sizeof(pesquisar_id), "|   ===> Digite o ID do Processo que deseja restaurar: ");
        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1){
            int idBusca = atoi(pesquisar_id);
            if ((processoPJ->id == idBusca) && (processoPJ->atividade == 0)){
                processoPJ->atividade = 1;
                encontrado = 1;
                fseek(arq_processoPJ, -sizeof(ProcessoPJ), SEEK_CUR);
                fwrite(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ);
                printf("|                                                                                             |\n");
                printf("|        Processo restaurado com sucesso!                                                     |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                if (arq_processoPJ) fclose(arq_processoPJ);
                free(processoPJ);
                return;
            }  
        }
            if(!encontrado){
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|          Processo não encontrado!            |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            if (arq_processoPJ) fclose(arq_processoPJ);
            free(processoPJ);
            return;
        }
    } 
    else if (opcao == 2) {
        arq_processoPJ = fopen("processoPJ.dat", "rb");
        temp_processoPJ = fopen("temp_processoPJ.dat", "wb");
        if (arq_processoPJ == NULL || temp_processoPJ == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        if (arq_processoPJ) fclose(arq_processoPJ);
        if (temp_processoPJ) fclose(temp_processoPJ);
        free(processoPJ);
        return;
    }
        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1){
            if (processoPJ->atividade == 1){
                fwrite(processoPJ, sizeof(ProcessoPJ), 1, temp_processoPJ);
            }
        }
        if (arq_processoPJ) fclose(arq_processoPJ);
        if (temp_processoPJ) fclose(temp_processoPJ);
        remove("processoPJ.dat");
        rename("temp_processoPJ.dat", "processoPJ.dat");
        printf("|                                                                                             |\n");
        printf("|        Lixeira esvaziada com sucesso!                                                       |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
        free(processoPJ);
        return;
    } 
    else {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|       Você digitou uma opção inválida!       |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        remove("temp_processoPJ.dat");
        free(processoPJ);
        return;
    }
}


void relatorioProcessosPJ(void) {
    system("clear");
    FILE *arq_processoPJ;
    ProcessoPJ *processoPJ;
    processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    if (!processoPJ) {
        printf("Erro: Falha na alocacao de memoria.\n");
        free(processoPJ);
        return;
    }
    
    int opcao, filtro, pesq_filtro;
    char *tipo;
    int i = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                   Relatório de Processo PJ                                  |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("| gostaria de filtrar algum dado? (1- Sim / 2- Não): ");
    if (scanf("%d", &opcao) != 1) {
        opcao = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        int c = getchar(); (void)c;
    }
    if(opcao == 2){
        arq_processoPJ = fopen ("processoPJ.dat", "rb");
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
        printf("\n %-15s %-15s %-25s %-26s %-20s %-27s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "Descrição", "Data", "Status");
        printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
            if (processoPJ->atividade){
                printf("|%-15d %-15s %-25s %-25s %-20s %-25s %-15s %-15s\n",
                processoPJ->id,
                processoPJ->tipo, 
                processoPJ->autor, 
                processoPJ->reu, 
                processoPJ->advOAB, 
                processoPJ->descricao, 
                processoPJ->data, 
                processoPJ->status);
                i++;
            }
            printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
        }
        printf("\n\n+------------------------------------------------------------------------------------------------------+\n");
        printf("|   Total de Processos ativos: %d                                                                       |\n", i);
        printf("+------------------------------------------------------------------------------------------------------+\n");
        fclose(arq_processoPJ);
    }
    else if (opcao == 1){
        printf("+---------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                             |\n");
        printf("|   ===> Qual dado você deseja filtrar?                                                       |\n");
        printf("|        1 - Tipo                                                                             |\n");
        printf("|        2 - Status                                                                           |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
        if (scanf("%d", &filtro) != 1) {
            filtro = -1;
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        } else {
            int c = getchar(); (void)c;
        }
        switch(filtro){
            case 1: {
                printf("|     ===> Digite o tipo de processo que deseja filtrar:      |\n");
                printf("| 1-Civil  2-Penal  3-Trabalista  4-Tributário  5-Empresarial |\n");
                if (scanf("%d", &pesq_filtro) != 1) {
                    pesq_filtro = -1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) { }
                } else {
                    int c = getchar(); (void)c;
                }
                switch(pesq_filtro){
                    case 1: (tipo = "Civil"); break;
                    case 2: (tipo = "Penal"); break;
                    case 3: (tipo = "Trabalhista"); break;
                    case 4: (tipo = "Tributário"); break;
                    case 5: (tipo = "Empresarial"); break;
                    default: (tipo = ""); break;
                }
                arq_processoPJ = fopen ("processoPJ.dat", "rb");
                if (arq_processoPJ == NULL) {
                    system("clear");
                    printf("+----------------------------------------------+\n");
                    printf("|                                              |\n");
                    printf("|           Erro ao abrir o arquivo!           |\n");
                    printf("|                                              |\n");
                    printf("+----------------------------------------------+\n");
                    free(processoPJ);
                    return;
                }
                printf("\n %-15s %-15s %-25s %-26s %-20s %-27s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "Descrição", "Data", "Status");
                printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                    if (processoPJ->atividade && strcmp(processoPJ->tipo, tipo) == 0){
                        printf("|%-15d %-15s %-25s %-25s %-20s %-25s %-15s %-15s\n",
                        processoPJ->id,
                        processoPJ->tipo, 
                        processoPJ->autor, 
                        processoPJ->reu, 
                        processoPJ->advOAB, 
                        processoPJ->descricao, 
                        processoPJ->data, 
                        processoPJ->status);
                        i++;
                    }
                    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
                printf("|   Total de processos ativos: %d                                                                      |\n", i);
                printf("+------------------------------------------------------------------------------------------------------+\n");
                fclose(arq_processoPJ);
            }; break;
            case 2: {
                printf("|     ===> Digite o status do processo que deseja filtrar:      |\n");
                printf("|                1-Em Andamento  2-Concluído                    |\n");
                if (scanf("%d", &pesq_filtro) != 1) {
                    pesq_filtro = -1;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) { }
                } else {
                    int c = getchar(); (void)c;
                }
                switch(pesq_filtro){
                    case 1: (tipo = "Em Andamento"); break;
                    case 2: (tipo = "Concluído"); break;
                    default: (tipo = ""); break;
                }
                arq_processoPJ = fopen ("processoPJ.dat", "rb");
                if (arq_processoPJ == NULL) {
                    system("clear");
                    printf("+----------------------------------------------+\n");
                    printf("|                                              |\n");
                    printf("|           Erro ao abrir o arquivo!           |\n");
                    printf("|                                              |\n");
                    printf("+----------------------------------------------+\n");
                    free(processoPJ);
                    return;
                }
                printf("\n %-15s %-15s %-25s %-26s %-20s %-27s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "Descrição", "Data", "Status");
                printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                    if (processoPJ->atividade && strcmp(processoPJ->status, tipo) == 0){
                        printf("|%-15d %-15s %-25s %-25s %-20s %-25s %-15s %-15s\n",
                        processoPJ->id,
                        processoPJ->tipo, 
                        processoPJ->autor, 
                        processoPJ->reu, 
                        processoPJ->advOAB, 
                        processoPJ->descricao, 
                        processoPJ->data, 
                        processoPJ->status);
                        i++;
                    }
                    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
                printf("|   Total de processos ativos: %d                                                                      |\n", i);
                printf("+------------------------------------------------------------------------------------------------------+\n");
                fclose(arq_processoPJ);
            }; break;
        }
    }
    free(processoPJ);
}

void listaProcessosPJ(void){
    system("clear");
    ProcessoPJ *lista = gerarLista_ProcPJ(); 
    ProcessoPJ *listaTemp = lista;
    ProcessoPJ **vetorProc = NULL;
    ProcessoPJ *processoPJ = NULL;
    int total = 0;
    int i = 0;
    int opcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Listagem Processo                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                           1 - listar por ordem de cadastro                                  |\n");
    printf("|                           2 - listar por Data                                               |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    if (scanf("%d", &opcao) != 1) {
        opcao = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        int c = getchar(); (void)c;
    }
    switch(opcao){
        case 1: {
            printf("\n %-15s %-15s %-25s %-26s %-20s %-27s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "Descrição", "Data", "Status");
            printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            while(listaTemp != NULL){
                if (listaTemp->atividade){
                    printf("|%-15d %-15s %-25s %-25s %-20s %-25s %-15s %-15s\n",
                    listaTemp->id,
                    listaTemp->tipo, 
                    listaTemp->autor, 
                    listaTemp->reu, 
                    listaTemp->advOAB, 
                    listaTemp->descricao, 
                    listaTemp->data, 
                    listaTemp->status);
                    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                }
                listaTemp = listaTemp->prox;
            }
        }; break;

        case 2: {
            vetorProc = (ProcessoPJ**) gerarVetorOrdenado(lista, procPJ_getProximo, procPJ_compararData, &total);
            
            if (vetorProc == NULL || total == 0) {
                printf("\nNenhum processo encontrado.\n");
            } else {
                printf("\n=== RELATORIO POR DATA ===\n");
                printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Advogado", "DATA", "Status");
                printf("+---------------------------------------------------------------------------------------------------+\n");

                i = 0;
                while(i < total) {
                    processoPJ = vetorProc[i];
                    printf("%-15d %-15s %-15s %-15s %-15s %-15s %-15s \n", 
                        processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->data, processoPJ->status);
                    printf("+---------------------------------------------------------------------------------------------------+\n");
                    i++;
                }
                free(vetorProc);
            }
            
        }; break;
    }
    
    // Liberar a lista ligada criada por gerarLista_ProcPF
    listaTemp = lista;
    while(listaTemp != NULL) {
        ProcessoPJ *temp = listaTemp;
        listaTemp = listaTemp->prox;
        free(temp);
    }
}