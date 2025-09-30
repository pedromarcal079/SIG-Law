#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"

void moduloEmpresa(void) {
    int empOpcao;
    do {
        empOpcao = menuEmpresa();
        switch (empOpcao){
        case 0:
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 1:
            cadastraEmpresa();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 2:
            mostraEmpresa();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 3:
            editaEmpresa();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 4:
            excluiEmpresa();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        default:
            printf("Voce digitou uma opcao invalida\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    } while (empOpcao != 0);
}

int menuEmpresa(void) {
    system("clear");
    int opcaoEmpresa;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                      Modulo de Empresa                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra empresa                                               |\n");
    printf("|                          2 - Mostra empresa                                                 |\n");
    printf("|                          3 - Edita empresa                                                  |\n");
    printf("|                          4 - Exclui empresa                                                 |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcaoEmpresa);
    getchar();
    return opcaoEmpresa;
}


void cadastraEmpresa(void) {
    system("clear");
    char cnpj[15];
    char nome[50];
    int tam;
    FILE *arq_empresa;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Empresa                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados da empresa:                                                         |\n");
    printf("|   ===> CNPJ: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    tam = strlen(cnpj);
    cnpj[tam-1] = '\0';
    printf("|   ===> Nome: ");
    fgets(nome, sizeof(nome), stdin);
    tam = strlen(nome);
    nome[tam-1] = '\0';
    printf("|                                                                                             |\n");
    printf("|        Empresa cadastrada com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_empresa = fopen("empresa.csv","at");
    fprintf(arq_empresa, "%s;", cnpj);
    fprintf(arq_empresa, "%s\n", nome);
    fclose(arq_empresa);
}


void mostraEmpresa(void){
    system("clear");
    char cnpj[15];
    char pesquisar_cnpj[15];
    char nome[50];
    int tam;
    FILE *arq_empresa;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(pesquisar_cnpj, sizeof(pesquisar_cnpj), stdin);
    tam = strlen(pesquisar_cnpj);
    pesquisar_cnpj[tam-1] = '\0';
    arq_empresa = fopen("empresa.csv", "rt");
    while (!feof(arq_empresa)){
        fscanf(arq_empresa, "%[^;]", cnpj);
        fgetc(arq_empresa);
        fscanf(arq_empresa, "%[^\n]", nome);
        fgetc(arq_empresa);
        if (strcmp(cnpj, pesquisar_cnpj) == 0){
            printf("|\t\tCPF: %s\n", cnpj);
            printf("|\t\tNome: %s\n", nome);
        }
    }
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaEmpresa(void) {
    system("clear");
    char cnpj[15];
    char nome[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("|                                                                                             |\n");
    printf("|        Digite os novos dados:                                                               |\n");
    printf("|        Nome: ");
    fgets(nome, sizeof(nome), stdin);  
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiEmpresa(void) {
    system("clear");
    char cnpj[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("|                                                                                             |\n");
    printf("|        Empresa excluida com sucesso!                                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}