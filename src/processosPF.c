#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPF.h"

#include "processosPJ.h"
#include "clientePF.h"
#include "clientePJ.h"
#include "advogado.h"

#define MAX_ID_LEN 20

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
            lixeiraAdvogado();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 6:
            relatorioProcessosPF();
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
    printf("|                          5 - Lixeira                                                        |\n");
    printf("|                          6 - Relatório                                                       |\n");
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

    int tam;
    
    processoPF = (ProcessoPF*)malloc(sizeof(ProcessoPF));
    if(processoPF == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o processo. \n");
        getchar();
        return;
    }

    advogado = (Advogado*)malloc(sizeof(Advogado));
    if(advogado == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o Advogado.\n");
        free(processoPF);
        free(clientePF);
        getchar();
        return;
    }

    
    clientePF = (ClientePF*)malloc(sizeof(ClientePF));
    if(clientePF == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o Cliente.\n");
        free(processoPF);
        getchar();
        return;
    }

    novoID_str = gerarID_PF();
    if(novoID_str == NULL){
        printf("\nERRO: Falha ao gerar o novo ID do Processo.\n");
        free(processoPF);
        free(clientePF);
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
    printf("|   ===> Tipo de processo: ");
    fgets(processoPF->tipo, sizeof(processoPF->tipo), stdin);
    tam = strlen(processoPF->tipo);
    processoPF->tipo[tam-1] = '\0';
    printf("|   ===> Autor (CPF): ");                                 
    fgets(processoPF->autor, sizeof(processoPF->autor), stdin);        
    tam = strlen(processoPF->autor);                                   
    processoPF->autor[tam-1] = '\0';
    printf("|   ===> Réu (CNPJ ou CPF): ");
    fgets(processoPF->reu, sizeof(processoPF->reu), stdin);
    tam = strlen(processoPF->reu);
    processoPF->reu[tam-1] = '\0';
    printf("|   ===> Advogado Responsável (OAB): ");
    fgets(processoPF->advOAB, sizeof(processoPF->advOAB), stdin);
    tam = strlen(processoPF->advOAB);
    processoPF->advOAB[tam-1] = '\0';
    printf("|   ===> Descrição: ");
    fgets(processoPF->descricao, sizeof(processoPF->descricao), stdin);
    tam = strlen(processoPF->descricao);
    processoPF->descricao[tam-1] = '\0';
    printf("|   ===> Data de Cadastro: ");
    fgets(processoPF->data, sizeof(processoPF->data), stdin);
    tam = strlen(processoPF->data);
    processoPF->data[tam-1] = '\0';
    strcpy(processoPF->status, "Em Andamento");

    processoPF->id = atoi(novoID_str);

    arq_cliente = fopen("clientePF.dat", "rb");
    if(arq_cliente == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de clientes (clientePF.dat)!");
        free(processoPF);
        free(clientePF);
        free(novoID_str);
        getchar();
        return;
    }

    temp_cliente = fopen("temp_cliente.dat", "wb");
    if(temp_cliente == NULL){
        printf("\nERRO: Nao foi possivel criar o arquivo temporario (temp_cliente.dat)!");
        fclose(arq_cliente);
        free(processoPF);
        free(clientePF);
        free(novoID_str);
        getchar();
        return;
    }

    arq_advogado = fopen("advogado.dat", "rb");
    if(arq_advogado == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de advogados (advogado.dat)!");
        fclose(arq_cliente);
        fclose(temp_cliente);
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
    fclose(arq_processoPF);
    fclose(arq_advogado);
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
    int tam;
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Processo PF                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|   ===> Digite o ID do processo: ");
    fgets(pesquisar_id, sizeof(pesquisar_id), stdin);
    tam = strlen(pesquisar_id);
    pesquisar_id[tam-1] = '\0';

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
            return;
        }

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

                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPF->advOAB) == 0) {
                        printf("|\t\tAdvogado Responsável: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                    }
                }

                printf("|\t\tTipo: %s\n", processoPF->tipo);
                printf("|\t\tData de abertura: %s\n", processoPF->data);
                printf("|\t\tDescrição: %s\n", processoPF->descricao);
                printf("|\t\tStatus: %s\n", processoPF->status);
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
    FILE *arq_processoPF, *temp_processoPF, *arq_clientePF, *arq_clientePJ, *arq_advogado;

    ProcessoPF *processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

    char pesquisar_id[5];
    int tam, dado;
    int encontrado = 0;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PF                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o ID do processo: ");
    fgets(pesquisar_id, sizeof(pesquisar_id), stdin);
    tam = strlen(pesquisar_id);
    pesquisar_id[tam-1] = '\0';

    arq_processoPF = fopen("processoPF.dat", "rb");
    temp_processoPF = fopen("temp_processoPF.dat", "wb");

    arq_clientePF = fopen("clientePF.dat","rb");
    arq_clientePJ = fopen("clientePJ.dat","rb");
    arq_advogado = fopen("advogado.dat","rb");
    if (arq_processoPF == NULL || temp_processoPF == NULL) {
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
                printf("|        5 - Data de Abertura                                                                 |\n");
                printf("|        6 - Descrição                                                                        |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                printf("===> Digite sua opcao: ");
                scanf("%d", &dado);  
                getchar();

                if (dado < 1 || dado > 9) {
                    system("clear");
                    printf("+----------------------------------------------+\n");
                    printf("|                                              |\n");
                    printf("|       Você digitou uma opção inválida!       |\n");
                    printf("|                                              |\n");
                    printf("+----------------------------------------------+\n");
                    return;
                } else {
                    printf("|                                                                                             |\n");
                    printf("|   ===> Digite o novo dado: ");
                    fgets(edicao, sizeof(edicao), stdin);
                    tam = strlen(edicao);
                    edicao[tam-1] = '\0';

                    switch (dado) {
                        case 1: strcpy(processoPF->autor, edicao); break;
                        case 2: strcpy(processoPF->reu, edicao); break;
                        case 3: strcpy(processoPF->advOAB, edicao); break;
                        case 4: strcpy(processoPF->tipo, edicao); break;
                        case 5: strcpy(processoPF->data, edicao); break;
                        case 6: strcpy(processoPF->descricao, edicao); break;
                    }
                }
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
        fwrite(processoPF, sizeof(ProcessoPF), 1, temp_processoPF);
    }
    fclose(arq_processoPF);
    fclose(temp_processoPF);
    fclose(arq_advogado);
    fclose(arq_clientePF);
    fclose(arq_clientePJ);

    
    if (encontrado) {
        remove("processoPF.dat");
        rename("temp_processoPF.dat", "processoPF.dat");

        printf("|                                                                                             |\n");
        printf("|        Dados atualizados com sucesso!                                                       |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    } else {
        remove("temp_processoPF.dat");
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
    FILE *temp_processoPF;
    FILE *arq_clientePJ;
    FILE *arq_clientePF;
    FILE *arq_advogado;

    ProcessoPF *processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

    char pesquisar_id[5];
    int tam, confi;
    int encontrado = 0;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o ID do processo: ");
    fgets(pesquisar_id, sizeof(pesquisar_id), stdin);
    tam = strlen(pesquisar_id);
    pesquisar_id[tam - 1] = '\0';

    arq_processoPF = fopen("processoPF.dat", "rb");
    temp_processoPF = fopen("temp_processoPF.dat", "wb");

    arq_clientePJ = fopen("clientePJ.dat", "rb");
    arq_clientePF = fopen("clientePF.dat", "rb");
    arq_advogado = fopen("advogado.dat", "rb");

    if (arq_processoPF == NULL || temp_processoPF == NULL) {
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

        if (processoPF->id != idBusca) {
            fwrite(processoPF, sizeof(ProcessoPF), 1, temp_processoPF);
        } else {
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
                fwrite(processoPF, sizeof(ProcessoPF), 1, temp_processoPF);
                printf("|                                                                                             |\n");
                printf("|        Processo excluído com sucesso!                                                       |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
            } else if (confi == 2) {
                fwrite(processoPF, sizeof(ProcessoPF), 1, temp_processoPF);
                printf("|                                                                                             |\n");
                printf("|        Exclusão cancelada!                                                                  |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                fclose(arq_processoPF);
                fclose(temp_processoPF);
                remove("temp_processoPF.dat");
                return;
            }
        }
    }

    fclose(arq_processoPF);
    fclose(temp_processoPF);
    fclose(arq_clientePJ);
    fclose(arq_clientePF);
    fclose(arq_advogado);

    if (!encontrado) {
        remove("temp_processoPF.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|          Processo não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    } else {
        remove("processoPF.dat");
        rename("temp_processoPF.dat", "processoPF.dat");
    }
}


void lixeiraProcessoPF(void) {
    system("clear");
    FILE *arq_processoPF;
    FILE *temp_processoPF;
    ProcessoPF *processoPF;
    processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    int opcao;
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
    arq_processoPF = fopen("processoPF.dat", "rb");
    temp_processoPF = fopen("temp_processoPF.dat","wb");

    if (arq_processoPF == NULL || temp_processoPF == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
    if (opcao == 1) {
        printf("Digite o ID do processo que deseja restaurar: ");
        fgets(pesquisar_id, sizeof(pesquisar_id), stdin);
        int tam = strlen(pesquisar_id);
        pesquisar_id[tam-1] = '\0';
        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1){
            int idBusca = atoi(pesquisar_id);
            if ((processoPF->id == idBusca) && (processoPF->atividade == 0)){
                processoPF->atividade = 1;
                fwrite(processoPF, sizeof(ProcessoPF), 1, temp_processoPF);
                printf("|                                                                                             |\n");
                printf("|        Processo restaurado com sucesso!                                                     |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(temp_processoPF);
                fclose(arq_processoPF);
                remove("processoPF.dat");
                rename("temp_processoPF.dat", "processoPF.dat");
                return;
            }  
            else {
                system("clear");
                printf("+-------------------------------------------------------+\n");
                printf("|                                                       |\n");
                printf("|  Não há Processo com esse Id que esteja na lixeira!  |\n");
                printf("|                                                       |\n");
                printf("+-------------------------------------------------------+\n");
                fclose(temp_processoPF);
                fclose(arq_processoPF);
                remove("temp_processoPF.dat");
                return;
            }
        }
    } 
    else if (opcao == 2) {
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
        fclose(temp_processoPF);
        fclose(arq_processoPF);
        remove("temp_processoPF.dat");
        return;
    }
}


void relatorioProcessosPF(void) {
    FILE *arq_processoPF;
    ProcessoPF *processoPF;
    processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    int opcao, filtro, pesq_filtro;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Relatório de Advogados                                   |\n");
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
                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
            }
            printf("+------------------------------------------------------------------------------------------------------+\n");
        }
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
                    case 1: {
                        arq_processoPF = fopen ("processoPF.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                            if (processoPF->atividade && strcmp(processoPF->tipo, "Civil") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPF);
                    }; break;
                    case 2: {
                        arq_processoPF = fopen ("processoPF.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                            if (processoPF->atividade && strcmp(processoPF->tipo, "Penal") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPF);
                    }; break;
                    case 3: {
                        arq_processoPF = fopen ("processoPF.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                            if (processoPF->atividade && strcmp(processoPF->tipo, "Trabalhista") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPF);
                    }; break;
                    case 4: {
                        arq_processoPF = fopen ("processoPF.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                            if (processoPF->atividade && strcmp(processoPF->tipo, "Tributário") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPF);
                    }; break;
                    case 5: {
                        arq_processoPF = fopen ("processoPF.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                            if (processoPF->atividade && strcmp(processoPF->tipo, "Empresarial") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPF);
                    }; break;
                }
            }; break;
            case 2: {
                printf("|     ===> Digite o status do processo que deseja filtrar:      |\n");
                printf("|                1-Em andamento  2-Concluído                    |\n");
                scanf("%d", &pesq_filtro);
                getchar();
                switch(pesq_filtro){
                    case 1: {
                        arq_processoPF = fopen ("processoPF.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                            if (processoPF->atividade && strcmp(processoPF->status, "Em andamento") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPF);
                    }; break;
                    case 2: {
                        arq_processoPF = fopen ("processoPF.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF) == 1) {
                            if (processoPF->atividade && strcmp(processoPF->status, "Concluído") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPF->id, processoPF->tipo, processoPF->autor, processoPF->reu, processoPF->advOAB, processoPF->descricao, processoPF->data, processoPF->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPF);
                    }; break;
                }
            }; break;
        }
    }
}