#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendaProc.h"

#include "processosPF.h"
#include "processosPJ.h"

void moduloAgendaProc(void) {
    int agenProc;
    do {
        agenProc = menuAgendaProc();
        switch (agenProc) {
            case 0:
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 1:
                agendaProces();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 2:
                mostraAgendaProces();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 3:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Módulo em Andamento             |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 4:
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Módulo em Andamento             |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
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
    } while (agenProc != 0);
}

int menuAgendaProc(void) {
    system("clear");
    int menuAgendProc;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                              Menu do Agendamento de Processos                               |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Agenda processo                                                |\n");
    printf("|                          2 - Mostra processo agendado                                       |\n");
    printf("|                          3 - Edita processo agendado                                        |\n");
    printf("|                          4 - Exclui processo agendado                                       |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&menuAgendProc);
    getchar();
    return menuAgendProc;
}

int gerarID_Agenda(){
    Agendamento *idAgenda;
    idAgenda = (Agendamento*) malloc(sizeof(Agendamento));

    FILE *arq_agenda;

    int ultimoID = 0;

    arq_agenda = fopen("agenda.dat","rb");
    if (arq_agenda == NULL){
        return 1;
    }

    while (fread(idAgenda, sizeof(Agendamento), 1, arq_agenda))
    {
        ultimoID = idAgenda->idAgend;
    }

    return ultimoID + 1;
    free(idAgenda);
}


void agendaProces(void) {
    system("clear");
    FILE *arq_agenda;

    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    agendamento->idAgend = gerarID_Agenda();
    
    int tam;    
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Agendar Processo                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do Processo:                                                        |\n");
    printf("|   ===> ID do Processo que Deseja Agendar: ");
    fgets(agendamento->idProc, sizeof(agendamento->idProc), stdin);
    tam = strlen(agendamento->idProc);
    agendamento->idProc[tam-1] = '\0';
    printf("|   ===> Tipo de Cliente: \n");
    printf("|        1 - Pessoa Física\n");
    printf("|        2 - Pessoa Jurídica\n");
    printf("|   ===> ");
    fgets(agendamento->tipoCliente, sizeof(agendamento->tipoCliente), stdin);
    tam = strlen(agendamento->tipoCliente);
    agendamento->tipoCliente[tam-1] = '\0';
    printf("|   ===> Horário: ");
    fgets(agendamento->hora, sizeof(agendamento->hora), stdin);
    tam = strlen(agendamento->hora);
    agendamento->hora[tam-1] = '\0';
    printf("|   ===> Data: ");
    fgets(agendamento->data, sizeof(agendamento->data), stdin);
    tam = strlen(agendamento->data);
    agendamento->data[tam-1] = '\0';
    printf("|   ===> Tipo de Compromisso (audiência, reunião, consulta): ");
    fgets(agendamento->tipo, sizeof(agendamento->tipo), stdin);
    tam = strlen(agendamento->tipo);
    agendamento->tipo[tam-1] = '\0';
    printf("|   ===> Local (online, tribunal): ");
    fgets(agendamento->local, sizeof(agendamento->local), stdin);
    tam = strlen(agendamento->local);
    agendamento->local[tam-1] = '\0';
    printf("|   ===> Descrição: ");
    fgets(agendamento->observacao, sizeof(agendamento->observacao), stdin);
    tam = strlen(agendamento->observacao);
    agendamento->observacao[tam-1] = '\0';
    strcpy(agendamento->status, "Em Andamento");

    arq_agenda = fopen("agenda.dat","ab");
    if (arq_agenda == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(agendamento);
        return;
    }
    fwrite(agendamento, sizeof(Agendamento),1,arq_agenda);
    fclose(arq_agenda);

    printf("|                                                                                             |\n");
    printf("|        Processo Agendado com sucesso!                                                       |\n");
    printf("|        O ID desse agendamento é: %d\n", agendamento->idAgend);
    free(agendamento);
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}

void mostraAgendaProces(void) {
    system("clear");

    FILE *arq_agenda, *arq_processoPF, *arq_processoPJ;
    Agendamento *agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    ProcessoPF *processoPF = (ProcessoPF*) malloc(sizeof(ProcessoPF));
    ProcessoPJ *processoPJ = (ProcessoPJ*) malloc(sizeof(ProcessoPJ));

    char pesquisar_id[5];
    int tam, encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                   Mostrar Agendamento                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|   ===> Digite o ID do agendamento: ");
    fgets(pesquisar_id, sizeof(pesquisar_id), stdin);
    tam = strlen(pesquisar_id);
    pesquisar_id[tam-1] = '\0';

    arq_agenda = fopen("agenda.dat","rb");
    arq_processoPF = fopen("processoPF.dat","rb");
    arq_processoPJ = fopen("processoPJ.dat","rb");

    if (arq_agenda == NULL) {
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(agendamento, sizeof(Agendamento), 1, arq_agenda)) {
        int pesqID = atoi(pesquisar_id);
        if (agendamento->idAgend == pesqID) {
            encontrado = 1;
            // verifica se é processo PF ou PJ
            if (strcmp(agendamento->tipoCliente, "1") == 0) {
                while (fread(processoPF, sizeof(ProcessoPF), 1, arq_processoPF)) {
                    int idProcPF = atoi(agendamento->idProc);
                    if (processoPF->id == idProcPF) {
                        printf("|\t\tProcesso (PF): %s - CPF do Autor: %s\n", processoPF->tipo, processoPF->autor);
                        printf("|\t\tDescrição do Processo: %s\n", processoPF->descricao);
                        break;
                    }
                }
            } else if (strcmp(agendamento->tipoCliente, "2") == 0) {
                while (fread(processoPJ, sizeof(ProcessoPJ), 1, arq_processoPJ)) {
                    int idProcPJ = atoi(agendamento->idProc);
                    if (processoPJ->id == idProcPJ) {
                        printf("|\t\tProcesso (PJ): %s - CNPJ do Autor: %s\n", processoPJ->tipo, processoPJ->autor);
                        printf("|\t\tDescrição do Processo: %s\n", processoPJ->descricao);
                        break;
                    }
                }
            } else {
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|          Tipo de Processo Inválido           |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
            }

            printf("|\t\tData: %s\n", agendamento->data);
            printf("|\t\tHora: %s\n", agendamento->hora);
            printf("|\t\tObservações: %s\n", agendamento->observacao);
            printf("|\t\tTipo de Compromisso: %s\n", agendamento->tipo);
            printf("|\t\tLocal: %s\n", agendamento->local);
            printf("|\t\tStatus do agendamento: %s\n", agendamento->status);
            break;
        }
    }
    fclose(arq_agenda);
    fclose(arq_processoPF);
    fclose(arq_processoPJ);

    free(agendamento);
    free(processoPF);
    free(processoPJ);

    if (!encontrado) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|          Agendamento não encontrado!         |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}