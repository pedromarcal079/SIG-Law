#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientePJ.h"

typedef struct clientePJ{
    char cnpj[20];      
    char razaoSocial[100];      // Nome legal da empresa (Ex.: The Coca-Cola Company)
    char nomeFantasia[100];     // Nome comercial da empresa (Ex.: Coca-Cola)
    char repres[50];     // Nome do representante da empresa
    char cpfRepres[15];  // CPF do Representante
    char areaAtuacao[50];     // Área de atuação da empresa
    char endereco[100];         
    char email[100];         
    char telefone[20];   
} ClientePJ;

void moduloClientePJ(void) {
    int cliPjOpcao;
    do {
        cliPjOpcao = menuClientePJ();
        switch (cliPjOpcao){
        case 0:
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 1:
            cadastraClientePJ();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 2:
            mostraClientePJ();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 3:
            editaClientePJ();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 4:
            excluiClientePJ();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        default:
            printf("Voce digitou uma opcao invalida\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    } while (cliPjOpcao != 0);
}

int menuClientePJ(void) {
    system("clear");
    int opcaoEmpresa;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                             Menu do Cliente - Pessoa Jurídica                               |\n");
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


void cadastraClientePJ(void) {
    system("clear");
    ClientePJ clientePJ;
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
    fgets(clientePJ.cnpj, sizeof(clientePJ.cnpj), stdin);
    tam = strlen(clientePJ.cnpj);
    clientePJ.cnpj[tam-1] = '\0';
    printf("|   ===> Razão Social: ");
    fgets(clientePJ.razaoSocial, sizeof(clientePJ.razaoSocial), stdin);
    tam = strlen(clientePJ.razaoSocial);
    clientePJ.razaoSocial[tam-1] = '\0';
    printf("|   ===> Nome Fantasia: ");
    fgets(clientePJ.nomeFantasia, sizeof(clientePJ.nomeFantasia), stdin);
    tam = strlen(clientePJ.nomeFantasia);
    clientePJ.nomeFantasia[tam-1] = '\0';
    printf("|   ===> Nome do Representante: ");
    fgets(clientePJ.repres, sizeof(clientePJ.repres), stdin);
    tam = strlen(clientePJ.repres);
    clientePJ.repres[tam-1] = '\0';
    printf("|   ===> CPF do Representante: ");
    fgets(clientePJ.cpfRepres, sizeof(clientePJ.cpfRepres), stdin);
    tam = strlen(clientePJ.cpfRepres);
    clientePJ.cpfRepres[tam-1] = '\0';
    printf("|   ===> Área de Atuação: ");
    fgets(clientePJ.areaAtuacao, sizeof(clientePJ.areaAtuacao), stdin);
    tam = strlen(clientePJ.areaAtuacao);
    clientePJ.areaAtuacao[tam-1] = '\0';
    printf("|   ===> Endereço: ");
    fgets(clientePJ.endereco, sizeof(clientePJ.endereco), stdin);
    tam = strlen(clientePJ.endereco);
    clientePJ.endereco[tam-1] = '\0';
    printf("|   ===> Email: ");
    fgets(clientePJ.email, sizeof(clientePJ.email), stdin);
    tam = strlen(clientePJ.email);
    clientePJ.email[tam-1] = '\0';
    printf("|   ===> Telefone: ");
    fgets(clientePJ.telefone, sizeof(clientePJ.telefone), stdin);
    tam = strlen(clientePJ.telefone);
    clientePJ.telefone[tam-1] = '\0';
    printf("|                                                                                             |\n");
    printf("|        Empresa cadastrada com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_empresa = fopen("clientePJ.csv","at");
    fprintf(arq_empresa, "%s;", clientePJ.cnpj);
    fprintf(arq_empresa, "%s;", clientePJ.razaoSocial);
    fprintf(arq_empresa, "%s;", clientePJ.nomeFantasia);
    fprintf(arq_empresa, "%s;", clientePJ.repres);
    fprintf(arq_empresa, "%s;", clientePJ.cpfRepres);
    fprintf(arq_empresa, "%s;", clientePJ.areaAtuacao);
    fprintf(arq_empresa, "%s;", clientePJ.endereco);
    fprintf(arq_empresa, "%s;", clientePJ.email);
    fprintf(arq_empresa, "%s;", clientePJ.telefone);
    fclose(arq_empresa);
}


void mostraClientePJ(void){
    system("clear");
    ClientePJ clientePJ;
    char pesquisar_cnpj[20];
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
    arq_empresa = fopen("clientePJ.csv", "rt");
    while (fscanf(arq_empresa,"%[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]",
    clientePJ.cnpj,
    clientePJ.razaoSocial,
    clientePJ.nomeFantasia,
    clientePJ.repres,
    clientePJ.cpfRepres,
    clientePJ.areaAtuacao,
    clientePJ.endereco,
    clientePJ.email,
    clientePJ.telefone
    )){
        if (strcmp(clientePJ.cnpj, pesquisar_cnpj) == 0){
            printf("|\t\tCNPJ: %s\n", clientePJ.cnpj);
            printf("|\t\tRazão Social: %s\n", clientePJ.razaoSocial);
            printf("|\t\tNome Fantasia: %s\n", clientePJ.nomeFantasia);
            printf("|\t\tRepresentante: %s\n", clientePJ.repres);
            printf("|\t\tCPF do Representante: %s\n", clientePJ.cpfRepres);
            printf("|\t\tÁrea de Atuação: %s\n", clientePJ.areaAtuacao);
            printf("|\t\tEndereço: %s\n", clientePJ.endereco);
            printf("|\t\tEmail: %s\n", clientePJ.email);
            printf("|\t\tTelefone: %s\n", clientePJ.telefone);
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            return;
        }
    }
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaClientePJ(void) {
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


void excluiClientePJ(void) {
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