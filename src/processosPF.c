#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPF.h"
#include "processosPJ.h"
#include "clientePF.h"
#include "clientePJ.h"
#include "advogado.h"
#include "validacao.h"
#include "utilidades.h"

#define MAX_ID_LEN 20


void* proc_getProximo(void* item) {
    return ((ProcessoPF*)item)->prox;
}

int proc_compararData(const void* a, const void* b) {
    ProcessoPF* pA = *(ProcessoPF**)a;
    ProcessoPF* pB = *(ProcessoPF**)b;
    int d1, m1, y1;
    int d2, m2, y2;
    
    sscanf(pA->data, "%d/%d/%d", &d1, &m1, &y1);
    sscanf(pB->data, "%d/%d/%d", &d2, &m2, &y2);
    if (y1 != y2) return y1 - y2;
    if (m1 != m2) return m1 - m2;

    return d1 - d2;
}


char* gerarID_PF(){
    FILE *arq_processoPF = NULL;
    ProcessoPF *idProcPF = NULL;
    char *idString = NULL;
    int ultimoID = 0;
    int novoID;

    idProcPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    if(idProcPF == NULL){
        return NULL;
    }


    arq_processoPF = fopen("processoPF.dat","rb");
    
    if(arq_processoPF != NULL){
        while(fread(idProcPF, sizeof(ProcessoPF), 1, arq_processoPF)){
            ultimoID = idProcPF->id;
        }
        fclose(arq_processoPF);
    }

    free(idProcPF);
    novoID = ultimoID + 1;

    idString = (char*) malloc(MAX_ID_LEN * sizeof(char));

    if(idString == NULL){
        return NULL;
    }

    snprintf(idString, MAX_ID_LEN, "%d", novoID);
    return idString;
}

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
        case 5:
            lixeiraProcessoPF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 6:
            relatorioProcessosPF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 7:
            listaProcessoPF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        default:
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|       Você digitou uma opção inválida!       |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            printf("Pressione ENTER... \n");
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
    printf("|                          1 - Cadastra processo PF                                           |\n");
    printf("|                          2 - Mostra processo PF                                              |\n");
    printf("|                          3 - Edita processo PF                                               |\n");
    printf("|                          4 - Exclui processo PF                                             |\n");
    printf("|                          5 - Lixeira PF                                                     |\n");
    printf("|                          6 - Relatório PF                                                   |\n");
    printf("|                          7 - Lista processos PF                                             |\n");
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
    ProcessoPF *processoPF = NULL;
    ClientePF *clientePF = NULL;
    Advogado *advogado = NULL;
    char *novoID_str = NULL;
    FILE *arq_processoPF = NULL;
    FILE *arq_cliente = NULL;
    FILE *temp_cliente = NULL;
    FILE *arq_advogado = NULL;
    FILE *temp_advogado = NULL;
    int tipo;
    
    processoPF = (ProcessoPF*)malloc(sizeof(ProcessoPF));
    if(processoPF == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o processo. \n");
        getchar();
        free(processoPF);
        return;
    }

    advogado = (Advogado*)malloc(sizeof(Advogado));
    if(advogado == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o Advogado.\n");
        free(processoPF);
        free(advogado);
        getchar();
        return;
    }

    
    clientePF = (ClientePF*)malloc(sizeof(ClientePF));
    if(clientePF == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o Cliente.\n");
        free(processoPF);
        free(advogado);
        free(clientePF);
        getchar();
        return;
    }

    novoID_str = gerarID_PF();
    if(novoID_str == NULL){
        printf("\nERRO: Falha ao gerar o novo ID do Processo.\n");
        free(processoPF);
        free(advogado);
        free(clientePF);
        free(novoID_str);
        getchar();
        return;
    }

    processoPF->atividade = 1;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PF                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|        ===> Tipo de processo:                                                               |\n");
    printf("| 1-Civil  2-Penal  3-Do Trabalho  4-Tributário  5-Empresarial |\n");
    printf("Digite a opção desejada:");
    scanf("%d", &tipo);
    getchar();
    switch (tipo){
        case 1: (strcpy(processoPF->tipo, "Civil")); break;
        case 2: (strcpy(processoPF->tipo, "Penal")); break;
        case 3: (strcpy(processoPF->tipo, "Do Trabalho")); break;
        case 4: (strcpy(processoPF->tipo, "Tributário")); break;
        case 5: (strcpy(processoPF->tipo, "Empresarial")); break;
    }
    input(processoPF->autor, sizeof(processoPF->autor), "|   ===> Autor (CPF): ");                            
    input(processoPF->reu, sizeof(processoPF->reu), "|   ===> Réu (CNPJ ou CPF): ");
    input(processoPF->advOAB, sizeof(processoPF->advOAB), "|   ===> Advogado Responsável (OAB): ");
    input(processoPF->descricao, sizeof(processoPF->descricao), "|   ===> Descrição do processo: ");
    do {
        input(processoPF->data, sizeof(processoPF->data), "|   ===> Data de agendamento: ");
    } while (!vali_data(processoPF->data));
    strcpy(processoPF->status, "Em Andamento");

    processoPF->id = atoi(novoID_str);

    arq_cliente = fopen("clientePF.dat", "rb");
    if(arq_cliente == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de clientes (clientePF.dat)!");
        fclose(arq_cliente);
        free(processoPF);
        free(advogado);
        free(clientePF);
        free(novoID_str);
        getchar();
        return;
    }

    temp_cliente = fopen("temp_cliente.dat", "wb");
    if(temp_cliente == NULL){
        printf("\nERRO: Nao foi possivel criar o arquivo temporario (temp_cliente.dat)!");
        fclose(arq_cliente);
        fclose(temp_cliente);
        free(processoPF);
        free(clientePF);
        free(novoID_str);
        free(advogado);
        getchar();
        return;
    }

    arq_advogado = fopen("advogado.dat", "rb");
    if(arq_advogado == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de advogados (advogado.dat)!");
        fclose(arq_cliente);
        fclose(temp_cliente);
        fclose(arq_advogado);
        free(processoPF);
        free(clientePF);
        free(advogado);
        free(novoID_str);
        getchar();
        return;
    }

    temp_advogado = fopen("temp_advogado.dat", "wb");
    if(temp_advogado == NULL){
        printf("\nERRO: Nao foi possivel criar o arquivo temporario (temp_advogado.dat)!");
        fclose(arq_cliente);
        fclose(temp_cliente);
        fclose(arq_advogado);
        fclose(temp_advogado);
        free(processoPF);
        free(clientePF);
        free(advogado);
        free(novoID_str);
        getchar();
        return;
    }

    arq_processoPF = fopen("processoPF.dat","ab");
    if (arq_processoPF == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de processos (processosPF.dat)!");
        fclose(arq_cliente);
        fclose(temp_cliente);
        fclose(arq_advogado);
        fclose(arq_processoPF);
        fclose(temp_advogado);
        free(advogado);
        free(processoPF);
        free(clientePF);
        free(novoID_str);
        getchar();
        return;
    }

    rewind(arq_cliente); // Volta para o inicio do arquivo de clientes
    rewind(arq_advogado);

    while(fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1){
        if(strcmp(processoPF->autor, clientePF->cpf) == 0){
            strcpy(clientePF->idProcesso, novoID_str);
            fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
        }
        else if(strcmp(processoPF->reu, clientePF->cpf) == 0){
            strcpy(clientePF->idProcesso, novoID_str);
            fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
        }else{
            fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
        }
    }

    while(fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
        if(strcmp(processoPF->advOAB, advogado->carteiraOAB) == 0){
            strcpy(advogado->idProcessoPF, novoID_str);
            fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
        }
        else{
            fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
        }
    }

    fwrite(processoPF, sizeof(ProcessoPF),1,arq_processoPF);

    fclose(arq_cliente);
    fclose(temp_cliente);
    fclose(arq_advogado);
    fclose(arq_processoPF);
    fclose(temp_advogado);

    remove("clientePF.dat");
    if(rename("temp_cliente.dat", "clientePF.dat") != 0){
        perror("ERRO CRITICO AO RENOMEAR O ARQUIVO DE CLIENTE");
        printf("\n*** AVISO: Os dados do cliente foram salvos em temp_cliente.dat! ***");
        getchar();
    }
    rename("temp_clientePF.dat", "clientePF.dat");

    remove("advogado.dat");
    if(rename("temp_advogado.dat", "advogado.dat") != 0){
        perror("ERRO CRITICO AO RENOMEAR O ARQUIVO DE ADVOGADO");
        printf("\n*** AVISO: Os dados do advogado foram salvos em temp_advogado.dat! ***");
        getchar();
    }
    rename("temp_advogado.dat", "advogado.dat");

    printf("|                                                                                             |\n");
    printf("|        Processo cadastrado com sucesso!                                                     |\n");
    printf("|        O ID desse processo é: %d\n", processoPF->id);
    free(processoPF);
    free(clientePF);
    free(advogado);
    free(novoID_str);
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}

void mostraProcessoPF(void) {
    system("clear");

    FILE *arq_processoPF, *arq_clientePJ, *arq_clientePF, *arq_advogado;

    ProcessoPF *processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

    char pesquisar_id[5];
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Processo PF                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    input(pesquisar_id, sizeof(pesquisar_id), "|   ===> Digite o ID do Processo: ");

    arq_processoPF = fopen("processoPF.dat","rb");
    arq_clientePJ = fopen("clientePJ.dat","rb");
    arq_clientePF = fopen("clientePF.dat","rb");
    arq_advogado = fopen("advogado.dat","rb");

    if (arq_processoPF == NULL || arq_clientePF == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        fclose(arq_clientePF);
        fclose(arq_advogado);
        fclose(arq_processoPF);
        fclose(arq_clientePJ);
        free(clientePJ);
        free(advogado);
        free(processoPF);
        free(clientePF);
        return;
    }
    rewind(arq_processoPF);
    while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
        int pesqID = atoi(pesquisar_id);
        if (processoPF->id == pesqID) {
            encontrado = 1;
            if (processoPF->atividade == 1){
                if (encontraClientePF(clientePF, processoPF->autor, arq_clientePF)) {
                    printf("|\t\tAutor: %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else {
                    printf("|\t\tAutor: Não encontrado!\n");
                }

                if (encontraClientePF(clientePF, processoPF->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else if (encontraClientePJ(clientePJ, processoPF->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }
                rewind(arq_advogado);
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPF->advOAB) == 0) {
                        printf("|\t\tAdvogado Responsável: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                    }
                }

                printf("|\t\tTipo: %s\n", processoPF->tipo);
                printf("|\t\tData de abertura: %s\n", processoPF->data);
                printf("|\t\tDescrição: %s\n", processoPF->descricao);
                printf("|\t\tStatus: %s\n", processoPF->status);
                return;
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Processo Inativo!               |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                return;
            }
        }
    }

    if (!encontrado) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Processo não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");

    free(processoPF);
    free(clientePJ);
    free(clientePF);
    free(advogado);

    fclose(arq_processoPF);
    fclose(arq_clientePJ);
    fclose(arq_clientePF);
    fclose(arq_advogado);
}


void editaProcessoPF(void) {
    system("clear");
    FILE *arq_processoPF, *arq_clientePF, *arq_clientePJ, *arq_advogado;

    ProcessoPF *processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

    char pesquisar_id[5];
    int dado;
    int encontrado = 0;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PF                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    input(pesquisar_id, sizeof(pesquisar_id), "|   ===> Digite o ID do Processo: ");

    arq_processoPF = fopen("processoPF.dat", "r+b");
    arq_clientePF = fopen("clientePF.dat","rb");
    arq_clientePJ = fopen("clientePJ.dat","rb");
    arq_advogado = fopen("advogado.dat","rb");
    if (arq_processoPF == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
        int pesqID = atoi(pesquisar_id);
        if (processoPF->id == pesqID) {
            encontrado = 1;
            if (processoPF->atividade == 1) {
                if (encontraClientePF(clientePF, processoPF->autor, arq_clientePF)) {
                    printf("|\t\tAutor: %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else {
                    printf("|\t\tAutor: Não encontrado!\n");
                }

                if (encontraClientePF(clientePF, processoPF->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else if (encontraClientePJ(clientePJ, processoPF->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPF->advOAB) == 0) {
                        printf("|\t\tAdvogado Responsável: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                    }
                }
                printf("|\t\tTipo: %s\n", processoPF->tipo);
                printf("|\t\tData de abertura: %s\n", processoPF->data);
                printf("|\t\tDescrição: %s\n", processoPF->descricao);
                printf("|\t\tStatus: %s\n", processoPF->status);
                printf("|                                                                                             |\n");

                printf("+---------------------------------------------------------------------------------------------+\n");
                printf("|                                                                                             |\n");
                printf("|   ===> Qual dado você deseja editar?                                                        |\n");
                printf("|        1 - Autor (CPF)                                                                      |\n");
                printf("|        2 - Réu (CNPJ ou CPF)                                                                |\n");
                printf("|        3 - Advogado Responsável (OAB)                                                       |\n");
                printf("|        4 - Tipo                                                                             |\n");
                printf("|        5 - Data de agendamento                                                                 |\n");
                printf("|        6 - Descrição                                                                        |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                printf("===> Digite sua opcao: ");
                scanf("%d", &dado);  
                getchar();

                if (dado < 1 || dado > 6) {
                    system("clear");
                    printf("+----------------------------------------------+\n");
                    printf("|                                              |\n");
                    printf("|       Você digitou uma opção inválida!       |\n");
                    printf("|                                              |\n");
                    printf("+----------------------------------------------+\n");
                    return;
                } else {
                    switch (dado) {
                        case 1: {
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Autor (CPF): "); 
                            strcpy(processoPF->autor, edicao);
                        }; break;
                        case 2:{
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Réu (CNPJ ou CPF): "); 
                            strcpy(processoPF->reu, edicao);
                        }; break;
                        case 3: {
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Advogado Responsável (OAB): "); 
                            strcpy(processoPF->advOAB, edicao);
                        }; break;
                        case 4: {
                            input(edicao, sizeof(edicao), "|   ===> Digite o novo Tipo: "); 
                            strcpy(processoPF->tipo, edicao);
                        }; break;
                        case 5: {
                            input(edicao, sizeof(edicao), "|   ===> Digite a nova Data de Abertura: "); 
                            strcpy(processoPF->data, edicao);
                        }; break;
                        case 6: {
                            input(edicao, sizeof(edicao), "|   ===> Digite a nova Descrição: "); 
                            strcpy(processoPF->descricao, edicao);  
                        }; break;
                    }
                }
            }
        }
    }
    fclose(arq_processoPF);
    fclose(arq_advogado);
    fclose(arq_clientePF);
    fclose(arq_clientePJ);

    
    if (encontrado) {
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
    }
}


void excluiProcessoPF(void) {
    system("clear");

    FILE *arq_processoPF;
    FILE *arq_clientePJ;
    FILE *arq_clientePF;
    FILE *arq_advogado;

    ProcessoPF *processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

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

    arq_processoPF = fopen("processoPF.dat", "r+b");
    arq_clientePJ = fopen("clientePJ.dat", "rb");
    arq_clientePF = fopen("clientePF.dat", "rb");
    arq_advogado = fopen("advogado.dat", "rb");

    if (arq_processoPF == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
        int idBusca = atoi(pesquisar_id);

        if (processoPF->id == idBusca) {
            encontrado = 1;
            if (encontraClientePF(clientePF, processoPF->autor, arq_clientePF)) {
                printf("|\t\tAutor: %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
            } else {
                printf("|\t\tAutor: Não encontrado!\n");
            }

            if (encontraClientePF(clientePF, processoPF->reu, arq_clientePF)) {
                printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
            } else if (encontraClientePJ(clientePJ, processoPF->reu, arq_clientePJ)) {
                printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
            } else {
                printf("|\t\tRéu: Não encontrado!\n");
            }

            rewind(arq_advogado);
            while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                if (strcmp(advogado->carteiraOAB, processoPF->advOAB) == 0) {
                    printf("|\t\tAdvogado: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                }
            }

            printf("|\t\tTipo: %s\n", processoPF->tipo);
            printf("|\t\tData de abertura: %s\n", processoPF->data);
            printf("|\t\tDescrição: %s\n", processoPF->descricao);
            printf("|\t\tStatus: %s\n", processoPF->status);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o processo que deseja excluir? 1 = Sim, 2 = Não: ");
            scanf("%d", &confi);
            getchar();

            if (confi == 1) {
                processoPF->atividade = 0;
                fseek(arq_processoPF, -sizeof(ProcessoPF), SEEK_CUR);
                fwrite(processoPF, sizeof(ProcessoPF), 1, arq_processoPF);
                printf("|                                                                                             |\n");
                printf("|        Processo excluído com sucesso!                                                       |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(arq_processoPF);
                return;
            } else if (confi == 2) {
                fwrite(processoPF, sizeof(ProcessoPF), 1, arq_processoPF);
                printf("|                                                                                             |\n");
                printf("|        Exclusão cancelada!                                                                  |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(arq_processoPF);
                return;
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                fclose(arq_processoPF);
                return;
            }
        }
    }

    fclose(arq_processoPF);
    fclose(arq_clientePJ);
    fclose(arq_clientePF);
    fclose(arq_advogado);

    if (!encontrado) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|          Processo não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    } 
}


void lixeiraProcessoPF(void) {
    system("clear");
    FILE *arq_processoPF;
    FILE *temp_processoPF;
    ProcessoPF *processoPF;
    processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    int opcao;
    int encontrado = 0;
    char pesquisar_id[5];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Lixeira Processo PF                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Você deseja restaurar um processo ou esvaziar a lixeira? (1- Restaurar / 2- esvaziar)|\n");
    scanf("%d", &opcao);
    getchar();
    if (opcao == 1) {
        arq_processoPF = fopen("processoPF.dat", "r+b");
        if (arq_processoPF == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
        input(pesquisar_id, sizeof(pesquisar_id), "|   ===> Digite o ID do Processo que deseja restaurar: ");
        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1){
            int idBusca = atoi(pesquisar_id);
            if ((processoPF->id == idBusca) && (processoPF->atividade == 0)){
                processoPF->atividade = 1;
                encontrado = 1;
                fseek(arq_processoPF, -sizeof(ProcessoPF), SEEK_CUR);
                fwrite(processoPF, sizeof(ProcessoPF), 1, arq_processoPF);
                printf("|                                                                                             |\n");
                printf("|        Processo restaurado com sucesso!                                                     |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(arq_processoPF);
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
            fclose(arq_processoPF);
            return;
        }
    } 
    else if (opcao == 2) {
        arq_processoPF = fopen("processoPF.dat", "rb");
        temp_processoPF = fopen("temp_processoPF.dat", "wb");
        if (arq_processoPF == NULL || temp_processoPF == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1){
            if (processoPF->atividade == 1){
                fwrite(processoPF, sizeof(ProcessoPF), 1, temp_processoPF);
            }
        }
        fclose(arq_processoPF);
        fclose(temp_processoPF);
        remove("processoPF.dat");
        rename("temp_processoPF.dat", "processoPF.dat");
        return;
    } 
    else {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|       Você digitou uma opção inválida!       |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        remove("temp_processoPF.dat");
        return;
    }
}


void relatorioProcessosPF(void) {
    FILE *arq_processoPF;
    ProcessoPF *processoPF;
    processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    int opcao, filtro, pesq_filtro;
    char *tipo;
    int i = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                   Relatório de Processo PF                                  |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("| gostaria de filtrar algum dado? (1- Sim / 2- Não):                                          |\n");
    scanf("%d", &opcao);
    getchar();
    if(opcao == 2){
        arq_processoPF = fopen ("processoPF.dat", "rb");
        if (arq_processoPF == NULL){
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Erro ao abrir o arquivo!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            return;
        }
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
        printf("+------------------------------------------------------------------------------------------------------+\n");
        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
            if (processoPF->atividade){
                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
                processoPF->id,
                processoPF->tipo, 
                processoPF->autor, 
                processoPF->reu, 
                processoPF->advOAB, 
                processoPF->descricao, 
                processoPF->data, 
                processoPF->status);
                i++;
            }
            printf("+------------------------------------------------------------------------------------------------------+\n");
        }
        printf("+------------------------------------------------------------------------------------------------------+\n");
        printf("|   Total de Processos ativos: %d                                                                      |\n", i);
        printf("+------------------------------------------------------------------------------------------------------+\n");
        fclose(arq_processoPF);
        free(processoPF);
    }
    else if (opcao == 1){
        printf("+---------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                             |\n");
        printf("|   ===> Qual dado você deseja filtrar?                                                       |\n");
        printf("|        1 - Tipo                                                                             |\n");
        printf("|        2 - Status                                                                           |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
        scanf("%d", &filtro);
        getchar();
        switch(filtro){
            case 1: {
                printf("|     ===> Digite o tipo de processo que deseja filtrar:      |\n");
                printf("| 1-Civil  2-Penal  3-Trabalista  4-Tributário  5-Empresarial |\n");
                scanf("%d", &pesq_filtro);
                getchar();
                switch(pesq_filtro){
                    case 1: (tipo = "Civil"); break;
                    case 2: (tipo = "Penal"); break;
                    case 3: (tipo = "Trabalhista"); break;
                    case 4: (tipo = "Tributário"); break;
                    case 5: (tipo = "Empresarial"); break;
                }
                arq_processoPF = fopen ("processoPF.dat", "rb");
                printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Advogado", "Data", "Status");
                printf("+--------------------------------------------------------------------------------------------------+\n");
                while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                    if (processoPF->atividade && strcmp(processoPF->tipo, tipo) == 0){
                        printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
                        processoPF->id,
                        processoPF->tipo, 
                        processoPF->autor, 
                        processoPF->reu, 
                        processoPF->advOAB, 
                        processoPF->descricao, 
                        processoPF->data, 
                        processoPF->status);
                        i++;
                    }
                    printf("+--------------------------------------------------------------------------------------------------+\n");
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
                printf("|   Total de processos ativos: %d                                                                      |\n", i);
                printf("+------------------------------------------------------------------------------------------------------+\n");
                fclose(arq_processoPF);
                free(processoPF);
            }; break;
            case 2: {
                printf("|     ===> Digite o status do processo que deseja filtrar:      |\n");
                printf("|                1-Em andamento  2-Concluído                    |\n");
                scanf("%d", &pesq_filtro);
                getchar();
                switch(pesq_filtro){
                    case 1: (tipo = "Em andamento"); break;
                    case 2: (tipo = "Concluído"); break;
                }
                arq_processoPF = fopen ("processoPF.dat", "rb");
                printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Advogado", "Data", "Status");
                printf("+--------------------------------------------------------------------------------------------------+\n");
                while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                    if (processoPF->atividade && strcmp(processoPF->status, tipo) == 0){
                        printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
                        processoPF->id,
                        processoPF->tipo, 
                        processoPF->autor, 
                        processoPF->reu, 
                        processoPF->advOAB, 
                        processoPF->descricao, 
                        processoPF->data, 
                        processoPF->status);
                        i++;
                    }
                    printf("+--------------------------------------------------------------------------------------------------+\n");
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
                printf("|   Total de processos ativos: %d                                                                      |\n", i);
                printf("+------------------------------------------------------------------------------------------------------+\n");
                fclose(arq_processoPF);
                free(processoPF);
            }; break;
        }
    }
}

void listaProcessoPF(void){
    system("clear");
    ProcessoPF *lista = gerarLista_ProcPF(); 
    ProcessoPF **vetorProc = NULL;
    ProcessoPF *processoPF = NULL;
    int total = 0;
    int i = 0;
    int opcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Listagem Advogado                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                           1 - listar por ordem de cadastro                                  |\n");
    printf("|                           2 - listar por Data                                               |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcao);
    getchar();
    switch(opcao){
        case 1: {
            printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Advogado", "Data", "Status");
            printf("+--------------------------------------------------------------------------------------------------+\n");
            while(lista != NULL){
                if (lista->atividade){
                    printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
                    lista->id,
                    lista->tipo, 
                    lista->autor, 
                    lista->reu, 
                    lista->advOAB, 
                    lista->descricao, 
                    lista->data, 
                    lista->status);
                    printf("+--------------------------------------------------------------------------------------------------+\n");
                }
                lista = lista->prox;
            }
            free(processoPF);
        }; break;

        case 2: {
            vetorProc = (ProcessoPF**) gerarVetorOrdenado(lista, proc_getProximo, proc_compararData, &total);
            
            if (vetorProc == NULL || total == 0) {
                printf("\nNenhum processo encontrado.\n");
            } else {
                printf("\n=== RELATORIO POR DATA ===\n");
                printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Advogado", "DATA", "Status");
                printf("+---------------------------------------------------------------------------------------------------+\n");

                i = 0;
                while(i < total) {
                    processoPF = vetorProc[i];
                    printf("%-15d %-15s %-15s %-15s %-15s %-15s %-15s \n", 
                        processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->data, processoPF->status);
                    printf("+---------------------------------------------------------------------------------------------------+\n");
                    i++;
                }
                free(vetorProc);
            }
            
        }; break;
    }
}