#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientePF.h"

void moduloClientePF(void){
    int cliPfOpcao;
    do {
        cliPfOpcao = menuClientePF();
        switch (cliPfOpcao){
        case 0:
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 1:
            cadastraClientePF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 2:
            mostraClientePF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 3:
            editaClientePF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 4:
            excluiClientePF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        default:
            printf("Voce digitou uma opcao invalida\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    } while (cliPfOpcao != 0);
}

int menuClientePF(void) {
    system("clear");
    int cliPfOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                               Menu do Cliente - Pessoa Física                               |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra cliente                                               |\n");
    printf("|                          2 - Mostra cliente                                                 |\n");
    printf("|                          3 - Edita cliente                                                  |\n");
    printf("|                          4 - Exclui cliente                                                 |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&cliPfOpcao);
    getchar();
    return cliPfOpcao;
}


void cadastraClientePF(void) {
    system("clear");
    char cpf[15];
    char nome[50];
    char dataNasc[13];
    char endereco[100];
    char email[100];
    char telefone[20];
    int tam;    
    FILE *arq_cliente;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Cliente                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do cliente:                                                         |\n");

    printf("|   ===> CPF: ");
    fgets(cpf, sizeof(cpf), stdin);
    tam = strlen(cpf);
    cpf[tam-1] = '\0';
    printf("|   ===> Nome: ");
    fgets(nome, sizeof(nome), stdin);
    tam = strlen(nome);
    nome[tam-1] = '\0';
    printf("|   ===> Data de Nascimento (dd/nn/aaaa): ");
    fgets(dataNasc, sizeof(dataNasc), stdin);
    tam = strlen(dataNasc);
    dataNasc[tam-1] = '\0';
    printf("|   ===> Endereço: ");
    fgets(endereco, sizeof(endereco), stdin);
    tam = strlen(endereco);
    endereco[tam-1] = '\0';
    printf("|   ===> Email: ");
    fgets(email, sizeof(email), stdin);
    tam = strlen(email);
    email[tam-1] = '\0';
    printf("|   ===> Telefone: ");
    fgets(telefone, sizeof(telefone), stdin);
    tam = strlen(telefone);
    telefone[tam-1] = '\0';

    printf("|                                                                                             |\n");
    printf("|        Cliente cadastrado com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_cliente = fopen("clientePF.csv","at");
    fprintf(arq_cliente, "%s;", cpf);
    fprintf(arq_cliente, "%s;", nome);
    fprintf(arq_cliente, "%s;", dataNasc);
    fprintf(arq_cliente, "%s;", endereco);
    fprintf(arq_cliente, "%s;", email);
    fprintf(arq_cliente, "%s\n", telefone);
    fclose(arq_cliente);
}


void mostraClientePF(void) {
    system("clear");
    char pesquisar_cpf[15];
    char cpf[15];
    char nome[50];
    char dataNasc[13];
    char endereco[100];
    char email[100];
    char telefone[20];
    int tam;
    FILE *arq_cliente;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Mostrar Cliente                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do cliente: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';
    arq_cliente = fopen("clientePF.csv", "rt");
    while (!feof(arq_cliente)){
        fscanf(arq_cliente, "%[^;]", cpf);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]", nome);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]", dataNasc);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]", endereco);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]", email);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^\n]", telefone);
        fgetc(arq_cliente);
        if (strcmp(cpf, pesquisar_cpf) == 0){
            printf("|\t\tCPF: %s\n", cpf);
            printf("|\t\tNome: %s\n", nome);
            printf("|\t\tData de Nascimento: %s\n", dataNasc);
            printf("|\t\tEndereço: %s\n", endereco);
            printf("|\t\tEmail: %s\n", email);
            printf("|\t\tTelefone: %s\n", telefone);
        }
    }
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaClientePF(void) {
    system("clear");
    char cpf[15];
    char nome[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Editar Cliente                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do cliente: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|                                                                                             |\n");
    printf("|        Digite os novos dados:                                                               |\n");
    printf("|        Nome: ");
    fgets(nome, sizeof(nome), stdin);  
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiClientePF(void) {
    system("clear");
    char cpf[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                        Excluir Cliente                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do cliente: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|                                                                                             |\n");
    printf("|        Cliente excluido com sucesso!                                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}