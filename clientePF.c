#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientePF.h"

typedef struct clientePF{
    char cpf[15];
    char nome[50];
    char dataNasc[13];
    char endereco[100];
    char email[100];
    char telefone[20];
} ClientePF;

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
    ClientePF clientePF;
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
    fgets(clientePF.cpf, sizeof(clientePF.cpf), stdin);
    tam = strlen(clientePF.cpf);
    clientePF.cpf[tam-1] = '\0';
    printf("|   ===> Nome: ");
    fgets(clientePF.nome, sizeof(clientePF.nome), stdin);
    tam = strlen(clientePF.nome);
    clientePF.nome[tam-1] = '\0';
    printf("|   ===> Data de Nascimento (dd/nn/aaaa): ");
    fgets(clientePF.dataNasc, sizeof(clientePF.dataNasc), stdin);
    tam = strlen(clientePF.dataNasc);
    clientePF.dataNasc[tam-1] = '\0';
    printf("|   ===> Endereço: ");
    fgets(clientePF.endereco, sizeof(clientePF.endereco), stdin);
    tam = strlen(clientePF.endereco);
    clientePF.endereco[tam-1] = '\0';
    printf("|   ===> Email: ");
    fgets(clientePF.email, sizeof(clientePF.email), stdin);
    tam = strlen(clientePF.email);
    clientePF.email[tam-1] = '\0';
    printf("|   ===> Telefone: ");
    fgets(clientePF.telefone, sizeof(clientePF.telefone), stdin);
    tam = strlen(clientePF.telefone);
    clientePF.telefone[tam-1] = '\0';

    printf("|                                                                                             |\n");
    printf("|        Cliente cadastrado com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_cliente = fopen("clientePF.csv","at");
    fprintf(arq_cliente, "%s;", clientePF.cpf);
    fprintf(arq_cliente, "%s;", clientePF.nome);
    fprintf(arq_cliente, "%s;", clientePF.dataNasc);
    fprintf(arq_cliente, "%s;", clientePF.endereco);
    fprintf(arq_cliente, "%s;", clientePF.email);
    fprintf(arq_cliente, "%s\n", clientePF.telefone);
    fclose(arq_cliente);
}


void mostraClientePF(void) {
    system("clear");
    ClientePF clientePF;
    char pesquisar_cpf[15];
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
    while (fscanf(arq_cliente,"%[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]", 
        clientePF.cpf,
        clientePF.nome,
        clientePF.dataNasc,
        clientePF.endereco,
        clientePF.email,
        clientePF.telefone
    )){
        if (strcmp(clientePF.cpf, pesquisar_cpf) == 0){
            printf("|\t\tCPF: %s\n", clientePF.cpf);
            printf("|\t\tNome: %s\n", clientePF.nome);
            printf("|\t\tData de Nascimento: %s\n", clientePF.dataNasc);
            printf("|\t\tEndereço: %s\n", clientePF.endereco);
            printf("|\t\tEmail: %s\n", clientePF.email);
            printf("|\t\tTelefone: %s", clientePF.telefone);
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            return;
        }
    }
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