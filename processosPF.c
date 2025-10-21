#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPF.h"

#include "clientePF.h"
#include "clientePJ.h"
#include "advogado.h"

int gerarID_PF(){
    ProcessoPF *idProcPF;
    idProcPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));

    FILE *arq_processoPF;

    int ultimoID = 0;

    arq_processoPF = fopen("processoPF.dat","rb");
    if (arq_processoPF == NULL){
        return 1;
    }

    while (fread(idProcPF, sizeof(ProcessoPF), 1, arq_processoPF))
    {
        ultimoID = idProcPF->id;
    }

    return ultimoID + 1;
    free(idProcPF);
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
    FILE *arq_processoPF;

    ProcessoPF *processoPF;
    processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));

    processoPF->id = gerarID_PF();
    processoPF->atividade = 1;

    int tam;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PJ                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|   ===> Tipo de processo: ");
    fgets(processoPF->tipo, sizeof(processoPF->tipo), stdin);
    tam = strlen(processoPF->tipo);
    processoPF->tipo[tam-1] = '\0';
    printf("|   ===> Autor (CNPJ): ");                                 // quando eu vou cadastrar um clientePJ eu colocoo cnpj sendo alguns números + J
    fgets(processoPF->autor, sizeof(processoPF->autor), stdin);        // Ex.: 12345J, para não dar conflito na função de achar cpf ou cnpj
    tam = strlen(processoPF->autor);                                   // já que as vezes eu coloco os mesmos números fáceis de lembrar como teste para ambos
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

    arq_processoPF = fopen("processoPJ.dat","ab");
    if (arq_processoPF == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(processoPF);
        return;
    }
    fwrite(processoPF, sizeof(ProcessoPF),1,arq_processoPF);
    fclose(arq_processoPF);

    printf("|                                                                                             |\n");
    printf("|        Processo cadastrado com sucesso!                                                     |\n");
    printf("|        O ID desse processo é: %d\n", processoPF->id);
    free(processoPF);
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}

int encontraClientePJ_PF(ClientePJ *clientePJ, const char *cnpj, FILE *arq_clientePJ) {
    rewind(arq_clientePJ);
    while (fread(clientePJ, sizeof(ClientePJ), 1, arq_clientePJ) == 1) {
        if (strcmp(clientePJ->cnpj, cnpj) == 0) {
            return 1; // encontrado
        }
    }
    return 0; // não encontrado
}

int encontraClientePF_PF(ClientePF *clientePF, const char *cpf, FILE *arq_clientePF) {
    rewind(arq_clientePF);
    while (fread(clientePF, sizeof(ClientePF), 1, arq_clientePF) == 1) {
        if (strcmp(clientePF->cpf, cpf) == 0) {
            return 1; // encontrado
        }
    }
    return 0; // não encontrado
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
    printf("|                                    Mostrar Processo PJ                                      |\n");
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
                if (encontraClientePF_PF(clientePF, processoPF->autor, arq_clientePF)) {
                printf("|\t\tAutor: %s\n", clientePF->nome);
                } else {
                    printf("|\t\tAutor: Não encontrado!\n");
                }

                if (encontraClientePF_PF(clientePF, processoPF->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PJ): %s\n", clientePF->nome);
                } else if (encontraClientePJ_PF(clientePJ, processoPF->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PF): %s\n", clientePJ->razaoSocial);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }

                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPF->advOAB) == 0) {
                        printf("|\t\tAdvogado Responsável: %s\n", advogado->nome);
                        break;
                    }
                }

                printf("|\t\tTipo: %s\n", processoPF->tipo);
                printf("|\t\tData de abertura: %s\n", processoPF->data);
                printf("|\t\tDescrição: %s\n", processoPF->descricao);
                printf("|\t\tStatus: %s\n", processoPF->status);
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
    printf("|                                    Editar Processo PJ                                       |\n");
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
                if (encontraClientePF_PF(clientePF, processoPF->autor, arq_clientePF)) {
                printf("|\t\tAutor: %s", clientePF->nome);
                printf(" (CNPJ: %s\n", clientePF->cpf); 
                } else {
                    printf("|\t\tAutor: Não encontrado!\n");
                }

                if (encontraClientePF_PF(clientePF, processoPF->reu, arq_clientePF)) {
                    printf("|\t\tRéu (PJ): %s\n", clientePF->nome);
                    printf(" (CNPJ: %s\n", clientePF->cpf);
                } else if (encontraClientePJ_PF(clientePJ, processoPF->reu, arq_clientePJ)) {
                    printf("|\t\tRéu (PF): %s", clientePJ->razaoSocial);
                    printf(" (CPF: %s\n", clientePJ->cnpj);
                } else {
                    printf("|\t\tRéu: Não encontrado!\n");
                }
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if (strcmp(advogado->carteiraOAB, processoPF->advOAB) == 0) {
                        printf("|\t\tAdvogado Responsável: %s", advogado->nome);
                        printf(" (OAB: %s\n", advogado->carteiraOAB);
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