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
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|       Você digitou uma opção inválida!       |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
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

    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));

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
    fgets(clientePF->cpf, sizeof(clientePF->cpf), stdin);
    tam = strlen(clientePF->cpf);
    clientePF->cpf[tam-1] = '\0';
    printf("|   ===> Nome: ");
    fgets(clientePF->nome, sizeof(clientePF->nome), stdin);
    tam = strlen(clientePF->nome);
    clientePF->nome[tam-1] = '\0';
    printf("|   ===> Data de Nascimento (dd/nn/aaaa): ");
    fgets(clientePF->dataNasc, sizeof(clientePF->dataNasc), stdin);
    tam = strlen(clientePF->dataNasc);
    clientePF->dataNasc[tam-1] = '\0';
    printf("|   ===> Endereço: ");
    fgets(clientePF->endereco, sizeof(clientePF->endereco), stdin);
    tam = strlen(clientePF->endereco);
    clientePF->endereco[tam-1] = '\0';
    printf("|   ===> Email: ");
    fgets(clientePF->email, sizeof(clientePF->email), stdin);
    tam = strlen(clientePF->email);
    clientePF->email[tam-1] = '\0';
    printf("|   ===> Telefone: ");
    fgets(clientePF->telefone, sizeof(clientePF->telefone), stdin);
    tam = strlen(clientePF->telefone);
    clientePF->telefone[tam-1] = '\0';

    arq_cliente = fopen("clientePF.dat","ab");
    if (arq_cliente == NULL) {
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(clientePF);
        return;
    }
    fwrite(clientePF, sizeof(ClientePF), 1, arq_cliente);
    fclose(arq_cliente);
    free(clientePF);

    printf("|                                                                                             |\n");
    printf("|        Cliente cadastrado com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");

}


void mostraClientePF(void) {
    system("clear");

    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));

    char pesquisar_cpf[15];
    int tam;
    FILE *arq_cliente;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Mostrar Cliente                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CPF do cliente: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';

    arq_cliente = fopen("clientePF.dat", "rb");
    if (arq_cliente == NULL) {
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1) {
        if (strcmp(clientePF->cpf, pesquisar_cpf) == 0){
            printf("|\t\tCPF: %s\n", clientePF->cpf);
            printf("|\t\tNome: %s\n", clientePF->nome);
            printf("|\t\tData de Nascimento: %s\n", clientePF->dataNasc);
            printf("|\t\tEndereço: %s\n", clientePF->endereco);
            printf("|\t\tEmail: %s\n", clientePF->email);
            printf("|\t\tTelefone: %s\n", clientePF->telefone);
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            return;
        } else {
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Cliente não encontrado!            |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
        }
    }
    fclose(arq_cliente);
}


void editaClientePF(void) {
    system("clear");
    FILE *arq_cliente;
    FILE *temp_cliente;
    ClientePF clientePF;
    char pesquisar_cpf[15];
    int tam;
    int dado;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Editar Cliente                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CPF do cliente: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';

    arq_cliente = fopen("clientePF.csv", "rt");
    temp_cliente = fopen("temp_clientePF.csv","wt");

    while (fscanf(arq_cliente,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
        clientePF.cpf,
        clientePF.nome,
        clientePF.dataNasc,
        clientePF.endereco,
        clientePF.email,
        clientePF.telefone) == 6){
        
        if (strcmp(clientePF.cpf, pesquisar_cpf) == 0){
            printf("|\t\tCPF: %s\n", clientePF.cpf);
            printf("|\t\tNome: %s\n", clientePF.nome);
            printf("|\t\tData de Nascimento: %s\n", clientePF.dataNasc);
            printf("|\t\tEndereço: %s\n", clientePF.endereco);
            printf("|\t\tEmail: %s\n", clientePF.email);
            printf("|\t\tTelefone: %s\n", clientePF.telefone);
            printf("|                                                                                             |\n");
            
            printf("+---------------------------------------------------------------------------------------------+\n");
            printf("|                                                                                             |\n");
            printf("|   ===> Qual dado você deseja editar?                                                        |\n");
            printf("|        1 - CPF                                                                              |\n");
            printf("|        2 - Nome                                                                             |\n");
            printf("|        3 - Data de Nascimento                                                               |\n");
            printf("|        4 - Endereço                                                                         |\n");
            printf("|        5 - Email                                                                            |\n");
            printf("|        6 - Telefone                                                                         |\n");
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            printf("===> Digite sua opcao: ");
            scanf("%d", &dado);  
            getchar();                                     
            printf("|                                                                                             |\n");
            printf("|   ===> Digite o novo dado: ");
            fgets(edicao, sizeof(edicao), stdin);
            tam = strlen(edicao);
            edicao[tam-1] = '\0';

            switch (dado) {
                case 1: strcpy(clientePF.cpf, edicao); break;
                case 2: strcpy(clientePF.nome, edicao); break;
                case 3: strcpy(clientePF.dataNasc, edicao); break;
                case 4: strcpy(clientePF.endereco, edicao); break;
                case 5: strcpy(clientePF.email, edicao); break;
                case 6: strcpy(clientePF.telefone, edicao); break;
            }
        }
        fprintf(temp_cliente, "%s;%s;%s;%s;%s;%s\n",
            clientePF.cpf,
            clientePF.nome,
            clientePF.dataNasc,
            clientePF.endereco,
            clientePF.email,
            clientePF.telefone
        );
    }
    
    fclose(arq_cliente);
    fclose(temp_cliente);
    remove("clientePF.csv");
    rename("temp_clientePF.csv", "clientePF.csv");
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiClientePF(void) {
    system("clear");
    FILE *arq_cliente;
    FILE *temp_cliente;
    ClientePF clientePF;
    char pesquisar_cpf[15];
    int tam;
    int confi;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                        Excluir Cliente                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CPF do cliente: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';

    arq_cliente = fopen("clientePF.csv", "rt");
    temp_cliente = fopen("temp_clientePF.csv","wt");

    while (fscanf(arq_cliente,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
        clientePF.cpf,
        clientePF.nome,
        clientePF.dataNasc,
        clientePF.endereco,
        clientePF.email,
        clientePF.telefone) == 6){
            
        if (strcmp(clientePF.cpf, pesquisar_cpf) != 0){
            fprintf(temp_cliente, "%s;%s;%s;%s;%s;%s\n",
                clientePF.cpf,
                clientePF.nome,
                clientePF.dataNasc,
                clientePF.endereco,
                clientePF.email,
                clientePF.telefone
            );
        } else {
            printf("|\t\tCPF: %s\n", clientePF.cpf);
            printf("|\t\tNome: %s\n", clientePF.nome);
            printf("|\t\tData de Nascimento: %s\n", clientePF.dataNasc);
            printf("|\t\tEndereço: %s\n", clientePF.endereco);
            printf("|\t\tEmail: %s\n", clientePF.email);
            printf("|\t\tTelefone: %s\n", clientePF.telefone);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o cliente que deseja excluir? 1 = Sim, 2 = Não: ");
            scanf("%d", &confi);
            getchar();

            if (confi == 2) {
                fprintf(temp_cliente, "%s;%s;%s;%s;%s;%s\n",
                    clientePF.cpf,
                    clientePF.nome,
                    clientePF.dataNasc,
                    clientePF.endereco,
                    clientePF.email,
                    clientePF.telefone
                );
            }
        }
    }
    fclose(arq_cliente);
    fclose(temp_cliente);
    remove("clientePF.csv");
    rename("temp_clientePF.csv", "clientePF.csv");

    if (confi == 1){
        printf("|                                                                                             |\n");
        printf("|        Cliente excluido com sucesso!                                                        |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    } else {
        printf("|                                                                                             |\n");
        printf("|        Exclusão cancelada!                                                                  |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    }
    
}