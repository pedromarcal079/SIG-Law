#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

void moduloCliente(void){
    int cliOpcao;
    do {
        cliOpcao = menuCliente();
        switch (cliOpcao){
        case 0:
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 1:
            cadastraCliente();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 2:
            mostraCliente();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 3:
            editaCliente();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 4:
            excluiCliente();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        default:
            printf("Voce digitou uma opcao invalida\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    } while (cliOpcao != 0);
}

int menuCliente(void) {
    system("clear");
    int cliOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Menu do Cliente                                       |\n");
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
    scanf("%d",&cliOpcao);
    getchar();
    return cliOpcao;
}


void cadastraCliente(void) {
    system("clear");
    char cpf[15];
    char nome[50];
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
    printf("|                                                                                             |\n");
    printf("|        Cliente cadastrado com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_cliente = fopen("cliente.csv","at");
    fprintf(arq_cliente, "%s;", cpf);
    fprintf(arq_cliente, "%s\n", nome);
    fclose(arq_cliente);
}


void mostraCliente(void) {
    system("clear");
    char cpf[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Mostrar Cliente                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do cliente: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|                                                                                             |\n");
    printf("|        Nome: Fulano de Town                                                                 |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaCliente(void) {
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


void excluiCliente(void) {
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