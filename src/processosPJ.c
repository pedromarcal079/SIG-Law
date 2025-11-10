#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processosPJ.h"

#include "clientePF.h"
#include "clientePJ.h"
#include "advogado.h"

int gerarID_PJ(){
    ProcessoPJ *idProcPJ;
    idProcPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));

    FILE *arq_processoPJ;

    int ultimoID = 0;

    arq_processoPJ = fopen("processoPJ.dat","rb");
    if (arq_processoPJ == NULL){
        return 1;
    }

    while (fread(idProcPJ, sizeof(ProcessoPJ), 1, arq_processoPJ))
    {
        ultimoID = idProcPJ->id;
    }

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
        case 5:
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
    printf("|                          5 - Listar processos                                               |\n");
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

    processoPJ->id = gerarID_PJ();
    processoPJ->atividade = 1;

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


int encontraClientePJ(ClientePJ *clientePJ, const char *cnpj, FILE *arq_clientePJ) {
    rewind(arq_clientePJ);
    while (fread(clientePJ, sizeof(ClientePJ), 1, arq_clientePJ) == 1) {
        if (strcmp(clientePJ->cnpj, cnpj) == 0) {
            return 1; // encontrado
        }
    }
    return 0; // não encontrado
}

int encontraClientePF(ClientePF *clientePF, const char *cpf, FILE *arq_clientePF) {
    rewind(arq_clientePF);
    while (fread(clientePF, sizeof(ClientePF), 1, arq_clientePF) == 1) {
        if (strcmp(clientePF->cpf, cpf) == 0) {
            return 1; // encontrado
        }
    }
    return 0; // não encontrado
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
            encontrado = 1;
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

    fclose(arq_processoPJ);
    fclose(temp_processoPJ);
    fclose(arq_clientePJ);
    fclose(arq_clientePF);
    fclose(arq_advogado);

    if (!encontrado) {
        remove("temp_processoPJ.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|          Processo não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    } else {
        remove("processoPJ.dat");
        rename("temp_processoPJ.dat", "processoPJ.dat");
    }
}


void relatorioProcessosPJ(void) {
    FILE *arq_processoPJ;
    ProcessoPJ *processoPJ;
    processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));
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
    while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ) == 1) {
        if (processoPJ->atividade){
            printf("|ID: %d / ", processoPJ->id);
            printf("Tipo: %s / ", processoPJ->tipo);
            printf("Autor: %s / ", processoPJ->autor);
            printf("Réu: %s / ", processoPJ->reu);
            printf("Carteira OAB: %s / ", processoPJ->advOAB);
            printf("Descrição: %s / ", processoPJ->descricao);
            printf("Data: %s / ", processoPJ->data);
            printf("Status: %s\n", processoPJ->status);
            printf("+---------------------------------------------------------------------------------------------+\n");
        }
    }
    fclose(arq_processoPJ);
    free(processoPJ);
}