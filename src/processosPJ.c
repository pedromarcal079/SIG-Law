#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPJ.h"
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


    arq_processoPJ = fopen("processoPF.dat","rb");
    
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
            lixeiraAdvogado();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 6:
            relatorioProcessosPJ();
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
    scanf("%d",&procPjOpcao);
    getchar();
    return procPjOpcao;
}


void cadastraProcessoPJ(void) {
    system("clear");
    ProcessoPJ *processoPJ = NULL;
    ClientePJ *clientePJ = NULL;
    Advogado *advogado = NULL;
    char *novoID_str = NULL;
    FILE *arq_processoPJ = NULL;
    FILE *arq_cliente = NULL;
    FILE *temp_cliente = NULL;
    FILE *arq_advogado = NULL;
    FILE *temp_advogado = NULL;
    

    int tam;

    processoPJ = (ProcessoPJ*)malloc(sizeof(ProcessoPJ));
    if(processoPJ == NULL){
        printf("\nERRO: Falha na alocacao de memoria para o processo. \n");
        getchar();
        return;
    }
    processoPJ->atividade = 1;

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
    printf("|   ===> Autor (CNPJ): ");                                 // quando eu vou cadastrar um clientePJ eu colocoo cnpj sendo alguns números + J
    fgets(processoPJ->autor, sizeof(processoPJ->autor), stdin);        // Ex.: 12345J, para não dar conflito na função de achar cpf ou cnpj
    tam = strlen(processoPJ->autor);                                   // já que as vezes eu coloco os mesmos números fáceis de lembrar como teste para ambos
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

    processoPJ->id = atoi(novoID_str);

    arq_advogado = fopen("advogado.dat", "rb");
    if(arq_advogado == NULL){
        printf("\nERRO: Nao foi possivel abrir o arquivo de advogados (advogado.dat)!");
        fclose(arq_cliente);
        fclose(temp_cliente);
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
        fclose(arq_cliente);
        fclose(temp_cliente);
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
        printf("\nERRO: Nao foi possivel abrir o arquivo de processos (processosPF.dat)!");
        fclose(arq_cliente);
        fclose(temp_cliente);
        free(processoPJ);
        free(clientePJ);
        free(novoID_str);
        getchar();
        return;
    }

    rewind(arq_advogado);

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
    fclose(arq_processoPJ);
    fclose(arq_advogado);
    fclose(temp_advogado);

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

    char pesquisar_id[5];
    int tam;
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|   ===> Digite o ID do processo: ");
    fgets(pesquisar_id, sizeof(pesquisar_id), stdin);
    tam = strlen(pesquisar_id);
    pesquisar_id[tam-1] = '\0';

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

                if (encontraClientePJ(clientePJ, processoPJ->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else if (encontraClientePF(clientePF, processoPJ->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }

                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPJ->advOAB) == 0) {
                        printf("|\t\tAdvogado Responsável: %s\n", advogado->nome);
                        break;
                    }
                }

                printf("|\t\tTipo: %s\n", processoPJ->tipo);
                printf("|\t\tData de abertura: %s\n", processoPJ->data);
                printf("|\t\tDescrição: %s\n", processoPJ->descricao);
                printf("|\t\tStatus: %s\n", processoPJ->status);
                break;
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

    free(processoPJ);
    free(clientePJ);
    free(clientePF);
    free(advogado);

    fclose(arq_processoPJ);
    fclose(arq_clientePJ);
    fclose(arq_clientePF);
    fclose(arq_advogado);
}



void editaProcessoPJ(void) {
    system("clear");
    FILE *arq_processoPJ, *temp_processoPJ, *arq_clientePJ, *arq_clientePF, *arq_advogado;

    ProcessoPJ *processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

    char pesquisar_id[5];
    int tam, dado;
    int encontrado = 0;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PJ                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o ID do processo: ");
    fgets(pesquisar_id, sizeof(pesquisar_id), stdin);
    tam = strlen(pesquisar_id);
    pesquisar_id[tam-1] = '\0';

    arq_processoPJ = fopen("processoPJ.dat", "rb");
    temp_processoPJ = fopen("temp_processoPJ.dat", "wb");

    arq_clientePJ = fopen("clientePJ.dat","rb");
    arq_clientePF = fopen("clientePF.dat","rb");
    arq_advogado = fopen("advogado.dat","rb");
    if (arq_processoPJ == NULL || temp_processoPJ == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
    rewind(arq_processoPJ);
    while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
        int pesqID = atoi(pesquisar_id);
        if (processoPJ->id == pesqID) {
            encontrado = 1;
            if (processoPJ->atividade == 1) {
                if (encontraClientePJ(clientePJ, processoPJ->autor, arq_clientePJ)) {
                    printf("|\t\tAutor: %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else {
                    printf("|\t\tAutor: Não encontrado!\n");
                }

                if (encontraClientePJ(clientePJ, processoPJ->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
                } else if (encontraClientePF(clientePF, processoPJ->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPJ->advOAB) == 0) {
                        printf("|\t\tAdvogado Responsável: %s", advogado->nome);
                        printf(" (OAB: %s\n", advogado->carteiraOAB);
                    }
                }
                printf("|\t\tTipo: %s\n", processoPJ->tipo);
                printf("|\t\tData de abertura: %s\n", processoPJ->data);
                printf("|\t\tDescrição: %s\n", processoPJ->descricao);
                printf("|\t\tStatus: %s\n", processoPJ->status);
                printf("|                                                                                             |\n");

                printf("+---------------------------------------------------------------------------------------------+\n");
                printf("|                                                                                             |\n");
                printf("|   ===> Qual dado você deseja editar?                                                        |\n");
                printf("|        1 - Autor (CNPJ)                                                                     |\n");
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
                        case 1: strcpy(processoPJ->autor, edicao); break;
                        case 2: strcpy(processoPJ->reu, edicao); break;
                        case 3: strcpy(processoPJ->advOAB, edicao); break;
                        case 4: strcpy(processoPJ->tipo, edicao); break;
                        case 5: strcpy(processoPJ->data, edicao); break;
                        case 6: strcpy(processoPJ->descricao, edicao); break;
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
        remove("temp_processoPJ.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Processo não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    }
}


void excluiProcessoPJ(void) {
    system("clear");

    FILE *arq_processoPJ;
    FILE *temp_processoPJ;
    FILE *arq_clientePJ;
    FILE *arq_clientePF;
    FILE *arq_advogado;

    ProcessoPJ *processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
    ClientePJ *clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));
    ClientePF *clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    Advogado *advogado = (Advogado*) malloc(sizeof(Advogado));

    char pesquisar_id[5];
    int tam, confi;

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

    arq_processoPJ = fopen("processoPJ.dat", "rb");
    temp_processoPJ = fopen("temp_processoPJ.dat", "wb");

    arq_clientePJ = fopen("clientePJ.dat", "rb");
    arq_clientePF = fopen("clientePF.dat", "rb");
    arq_advogado = fopen("advogado.dat", "rb");

    if (arq_processoPJ == NULL || temp_processoPJ == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
        int idBusca = atoi(pesquisar_id);

        if (processoPJ->id != idBusca) {
            fwrite(processoPJ, sizeof(ProcessoPJ), 1, temp_processoPJ);
        } else {
            if (encontraClientePJ(clientePJ, processoPJ->autor, arq_clientePJ)) {
                printf("|\t\tAutor: %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
            } else {
                printf("|\t\tAutor: Não encontrado!\n");
            }

            if (encontraClientePJ(clientePJ, processoPJ->reu, arq_clientePJ)) {
                printf("|\t\tRéu (PJ): %s (CNPJ: %s)\n", clientePJ->razaoSocial, clientePJ->cnpj);
            } else if (encontraClientePF(clientePF, processoPJ->reu, arq_clientePF)) {
                printf("|\t\tRéu (PF): %s (CPF: %s)\n", clientePF->nome, clientePF->cpf);
            } else {
                printf("|\t\tRéu: Não encontrado!\n");
            }

            rewind(arq_advogado);
            while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                if (strcmp(advogado->carteiraOAB, processoPJ->advOAB) == 0) {
                    printf("|\t\tAdvogado: %s (OAB: %s)\n", advogado->nome, advogado->carteiraOAB);
                }
            }

            printf("|\t\tTipo: %s\n", processoPJ->tipo);
            printf("|\t\tData de abertura: %s\n", processoPJ->data);
            printf("|\t\tDescrição: %s\n", processoPJ->descricao);
            printf("|\t\tStatus: %s\n", processoPJ->status);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o processo que deseja excluir? 1 = Sim, 2 = Não: ");
            scanf("%d", &confi);
            getchar();

            if (confi == 1) {
                processoPJ->atividade = 0;
                fwrite(processoPJ, sizeof(ProcessoPJ), 1, temp_processoPJ);
                printf("|                                                                                             |\n");
                printf("|        Processo excluído com sucesso!                                                       |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
            } else if (confi == 2) {
                fwrite(processoPJ, sizeof(ProcessoPJ), 1, temp_processoPJ);
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
                fclose(arq_processoPJ);
                fclose(temp_processoPJ);
                remove("temp_processoPJ.dat");
                return;
            }
        }
    }
}

void lixeiraProcessoPJ(void) {
    system("clear");
    FILE *arq_processoPJ;
    FILE *temp_processoPJ;
    ProcessoPJ *processoPJ;
    processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
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
    arq_processoPJ = fopen("processoPJ.dat", "rb");
    temp_processoPJ = fopen("temp_processoPJ.dat","wb");

    if (arq_processoPJ == NULL || temp_processoPJ == NULL) {
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
        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1){
            int idBusca = atoi(pesquisar_id);
            if ((processoPJ->id == idBusca) && (processoPJ->atividade == 0)){
                processoPJ->atividade = 1;
                fwrite(processoPJ, sizeof(ProcessoPJ), 1, temp_processoPJ);
                printf("|                                                                                             |\n");
                printf("|        Processo restaurado com sucesso!                                                     |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(temp_processoPJ);
                fclose(arq_processoPJ);
                remove("processoPJ.dat");
                rename("temp_processoPJ.dat", "processoPJ.dat");
                return;
            }  
            else {
                system("clear");
                printf("+-------------------------------------------------------+\n");
                printf("|                                                       |\n");
                printf("|  Não há Processo com esse Id que esteja na lixeira!  |\n");
                printf("|                                                       |\n");
                printf("+-------------------------------------------------------+\n");
                fclose(temp_processoPJ);
                fclose(arq_processoPJ);
                remove("temp_processoPJ.dat");
                return;
            }
        }
    } 
    else if (opcao == 2) {
        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1){
            if (processoPJ->atividade == 1){
                fwrite(processoPJ, sizeof(ProcessoPJ), 1, temp_processoPJ);
            }
        }
        fclose(arq_processoPJ);
        fclose(temp_processoPJ);
        remove("processoPJ.dat");
        rename("temp_processoPJ.dat", "processoPJ.dat");
        return;
    } 
    else {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|       Você digitou uma opção inválida!       |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        fclose(temp_processoPJ);
        fclose(arq_processoPJ);
        remove("temp_processoPJ.dat");
        return;
    }
}


void relatorioProcessosPJ(void) {
    FILE *arq_processoPJ;
    ProcessoPJ *processoPJ;
    processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
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
        arq_processoPJ = fopen ("processoPJ.dat", "rb");
        if (arq_processoPJ == NULL){
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
        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
            if (processoPJ->atividade){
                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
            }
            printf("+------------------------------------------------------------------------------------------------------+\n");
        }
        fclose(arq_processoPJ);
        free(processoPJ);
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
                        arq_processoPJ = fopen ("processoPJ.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                            if (processoPJ->atividade && strcmp(processoPJ->tipo, "Civil") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPJ);
                    }; break;
                    case 2: {
                        arq_processoPJ = fopen ("processoPJ.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                            if (processoPJ->atividade && strcmp(processoPJ->tipo, "Penal") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPJ);
                    }; break;
                    case 3: {
                        arq_processoPJ = fopen ("processoPJ.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                            if (processoPJ->atividade && strcmp(processoPJ->tipo, "Trabalhista") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPJ);
                    }; break;
                    case 4: {
                        arq_processoPJ = fopen ("processoPJ.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                            if (processoPJ->atividade && strcmp(processoPJ->tipo, "Tributário") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPJ);
                    }; break;
                    case 5: {
                        arq_processoPJ = fopen ("processoPJ.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                            if (processoPJ->atividade && strcmp(processoPJ->tipo, "Empresarial") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPJ);
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
                        arq_processoPJ = fopen ("processoPJ.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                            if (processoPJ->atividade && strcmp(processoPJ->status, "Em andamento") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPJ);
                    }; break;
                    case 2: {
                        arq_processoPJ = fopen ("processoPJ.dat", "rb");
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "ID", "Tipo", "Autor", "Réu", "Cart. OAB", "descrição", "Data", "Status");
                        printf("+------------------------------------------------------------------------------------------------------+\n");
                        while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
                            if (processoPJ->atividade && strcmp(processoPJ->status, "Concluído") == 0){
                                printf("|%-15d %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", processoPJ->id, processoPJ->tipo, processoPJ->autor, processoPJ->reu, processoPJ->advOAB, processoPJ->descricao, processoPJ->data, processoPJ->status);
                            }
                            printf("+------------------------------------------------------------------------------------------------------+\n");
                        }
                        fclose(arq_processoPJ);
                    }; break;
                }
            }; break;
        }
    }
}