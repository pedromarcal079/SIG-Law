#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendaProc.h"

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
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|              Módulo em Andamento             |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
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
    fgets(agendamento->descricao, sizeof(agendamento->descricao), stdin);
    tam = strlen(agendamento->descricao);
    agendamento->descricao[tam-1] = '\0';
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

