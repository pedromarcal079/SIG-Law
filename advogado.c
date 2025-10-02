#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "advogado.h"


typedef struct advogado{
    char cpf[15];
    char nome[50];
} Advogado;


void moduloAdvogado(void) {
    int advOpcao;
    do {
        advOpcao = menuAdvogado();
        switch (advOpcao) {
            case 0:
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 1:
                cadastraAdvogado();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 2:
                mostraAdvogado();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 3:
                editaAdvogado();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 4:
                excluiAdvogado();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            default:
                printf("Voce digitou uma opcao invalida\n");
                printf("Pressione ENTER ... \n");
                getchar();
                break;
        }
    } while (advOpcao != 0);
}

int menuAdvogado(void) {
    system("clear");
    int opcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Modulo de Advogados                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                               1 - Cadastra Advogado                                         |\n");
    printf("|                               2 - Mostra Advogado                                           |\n");
    printf("|                               3 - Edita Advogado                                            |\n");
    printf("|                               4 - Exclui Processo                                           |\n");
    printf("|                               0 - Sair                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcao);
    getchar();
    return opcao;
}


void cadastraAdvogado(void) {
    system("clear");
    Advogado advogado;
    int tam;
    FILE *arq_advogado;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Advogado                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do advogado:                                                        |\n");
    printf("|   ===> CPF: ");
    fgets(advogado.cpf, sizeof(advogado.cpf), stdin);
    tam = strlen(advogado.cpf);
    advogado.cpf[tam-1] = '\0';
    printf("|   ===> Nome: ");
    fgets(advogado.nome, sizeof(advogado.nome), stdin);
    tam = strlen(advogado.nome);
    advogado.nome[tam-1] = '\0';
    printf("|                                                                                             |\n");
    printf("|        Advogado cadastrado com sucesso!                                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_advogado = fopen("advogado.csv","at");
    fprintf(arq_advogado, "%s;", advogado.cpf);
    fprintf(arq_advogado, "%s\n", advogado.nome);
    fclose(arq_advogado);
}


void mostraAdvogado(void){
    system("clear");
    Advogado advogado;
    char pesquisar_cpf[15];
    int tam;
    FILE *arq_advogado;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do advogado:                                                            |\n");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';
    arq_advogado = fopen("advogado.csv", "rt");
    while (fscanf(arq_advogado,"%[^;]; %[^;]", advogado.cpf,advogado.nome)){
        if (strcmp(advogado.cpf, pesquisar_cpf) == 0){
            printf("|\t\tCPF: %s\n", advogado.cpf);
            printf("|\t\tNOME: %s\n", advogado.nome);
            getchar();
            return;
        }
    }
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    
}


void editaAdvogado(void) {
    system("clear");
    char pesquisar_cpf[15];
    int tam;
    int dado;
    char edicao[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do advogado: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';
    printf("|   ===> Qual dado Você deseja editar?                                                        |\n"); //0=cpf,1=nome//         
    scanf("%d", &dado);                                       
    printf("|                                                                                             |\n");
    printf("|        Digite os novos dados:                                                               |\n");
    fgets(edicao, sizeof(edicao), stdin);
    tam = strlen(edicao);
    edicao[tam-1] = '\0';
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiAdvogado(void) {
    system("clear");
    char cpf[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do advogado: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|                                                                                             |\n");
    printf("|        Advogado excluido com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}