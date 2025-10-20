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