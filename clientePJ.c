#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientePJ.h"


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
    FILE *arq_empresa;

    ClientePJ *clientePJ;
    clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));

    int tam;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Empresa                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados da empresa:                                                         |\n");
    printf("|   ===> CNPJ: ");                                                 // quando eu vou cadastrar um clientePJ eu colocoo cnpj sendo alguns números + J
    fgets(clientePJ->cnpj, sizeof(clientePJ->cnpj), stdin);                    // Ex.: 12345J, para não dar conflito na função de achar cpf ou cnpj no módulo de processos,
    tam = strlen(clientePJ->cnpj);                                             // já que as vezes eu coloco os mesmos números fáceis de lembrar como teste para ambos
    clientePJ->cnpj[tam-1] = '\0';
    printf("|   ===> Razão Social: ");
    fgets(clientePJ->razaoSocial, sizeof(clientePJ->razaoSocial), stdin);
    tam = strlen(clientePJ->razaoSocial);
    clientePJ->razaoSocial[tam-1] = '\0';
    printf("|   ===> Nome Fantasia: ");
    fgets(clientePJ->nomeFantasia, sizeof(clientePJ->nomeFantasia), stdin);
    tam = strlen(clientePJ->nomeFantasia);
    clientePJ->nomeFantasia[tam-1] = '\0';
    printf("|   ===> Nome do Representante: ");
    fgets(clientePJ->repres, sizeof(clientePJ->repres), stdin);
    tam = strlen(clientePJ->repres);
    clientePJ->repres[tam-1] = '\0';
    printf("|   ===> CPF do Representante: ");
    fgets(clientePJ->cpfRepres, sizeof(clientePJ->cpfRepres), stdin);
    tam = strlen(clientePJ->cpfRepres);
    clientePJ->cpfRepres[tam-1] = '\0';
    printf("|   ===> Área de Atuação: ");
    fgets(clientePJ->areaAtuacao, sizeof(clientePJ->areaAtuacao), stdin);
    tam = strlen(clientePJ->areaAtuacao);
    clientePJ->areaAtuacao[tam-1] = '\0';
    printf("|   ===> Endereço: ");
    fgets(clientePJ->endereco, sizeof(clientePJ->endereco), stdin);
    tam = strlen(clientePJ->endereco);
    clientePJ->endereco[tam-1] = '\0';
    printf("|   ===> Email: ");
    fgets(clientePJ->email, sizeof(clientePJ->email), stdin);
    tam = strlen(clientePJ->email);
    clientePJ->email[tam-1] = '\0';
    printf("|   ===> Telefone: ");
    fgets(clientePJ->telefone, sizeof(clientePJ->telefone), stdin);
    tam = strlen(clientePJ->telefone);
    clientePJ->telefone[tam-1] = '\0';

    arq_empresa = fopen("clientePJ.dat","ab");
    if (arq_empresa == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(clientePJ);
        return;
    }
    fwrite(clientePJ, sizeof(ClientePJ), 1, arq_empresa);
    fclose(arq_empresa);
    free(clientePJ);

    printf("|                                                                                             |\n");
    printf("|        Empresa cadastrada com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void mostraClientePJ(void){
    system("clear");
    FILE *arq_empresa;

    ClientePJ *clientePJ;
    clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));

    char pesquisar_cnpj[21];
    int tam;
    int encontrado = 0;
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

    arq_empresa = fopen("clientePJ.dat", "rb");
    if (arq_empresa == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(clientePJ);
        return;
    }

    while (fread(clientePJ, sizeof(ClientePJ), 1, arq_empresa) == 1){
        if (strcmp(clientePJ->cnpj, pesquisar_cnpj) == 0){
            encontrado = 1;
            printf("|\t\tCNPJ: %s\n", clientePJ->cnpj);
            printf("|\t\tRazão Social: %s\n", clientePJ->razaoSocial);
            printf("|\t\tNome Fantasia: %s\n", clientePJ->nomeFantasia);
            printf("|\t\tRepresentante: %s\n", clientePJ->repres);
            printf("|\t\tCPF do Representante: %s\n", clientePJ->cpfRepres);
            printf("|\t\tÁrea de Atuação: %s\n", clientePJ->areaAtuacao);
            printf("|\t\tEndereço: %s\n", clientePJ->endereco);
            printf("|\t\tEmail: %s\n", clientePJ->email);
            printf("|\t\tTelefone: %s\n", clientePJ->telefone);
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            return;
        }
    }
    fclose(arq_empresa);
    if (!encontrado) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Cliente não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n"); 
        return;
    }
}


void editaClientePJ(void) {
    system("clear");
    FILE *arq_empresa;
    FILE *temp_empresa;

    ClientePJ *clientePJ;
    clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));

    char pesquisar_cnpj[21];
    int tam, dado;
    int encontrado = 0;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(pesquisar_cnpj, sizeof(pesquisar_cnpj), stdin);
    tam = strlen(pesquisar_cnpj);
    pesquisar_cnpj[tam-1] = '\0';

    arq_empresa = fopen("clientePJ.dat", "rb");
    temp_empresa = fopen("temp_clientePJ.dat", "wb");
    if (arq_empresa == NULL || temp_empresa == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(clientePJ, sizeof(ClientePJ), 1, arq_empresa) == 1){
        if (strcmp(clientePJ->cnpj, pesquisar_cnpj) == 0){
            encontrado = 1;
            printf("|\t\tCNPJ: %s\n", clientePJ->cnpj);
            printf("|\t\tRazão Social: %s\n", clientePJ->razaoSocial);
            printf("|\t\tNome Fantasia: %s\n", clientePJ->nomeFantasia);
            printf("|\t\tRepresentante: %s\n", clientePJ->repres);
            printf("|\t\tCPF do Representante: %s\n", clientePJ->cpfRepres);
            printf("|\t\tÁrea de Atuação: %s\n", clientePJ->areaAtuacao);
            printf("|\t\tEndereço: %s\n", clientePJ->endereco);
            printf("|\t\tEmail: %s\n", clientePJ->email);
            printf("|\t\tTelefone: %s\n", clientePJ->telefone);
            printf("|                                                                                             |\n");

            printf("+---------------------------------------------------------------------------------------------+\n");
            printf("|                                                                                             |\n");
            printf("|   ===> Qual dado você deseja editar?                                                        |\n");
            printf("|        1 - CNPJ                                                                             |\n");
            printf("|        2 - Razão Social                                                                     |\n");
            printf("|        3 - Nome Fantasia                                                                    |\n");
            printf("|        4 - Representante                                                                    |\n");
            printf("|        5 - CPF do Representante                                                             |\n");
            printf("|        6 - Área de Atuação                                                                  |\n");
            printf("|        7 - Endereço                                                                         |\n");
            printf("|        8 - Email                                                                            |\n");
            printf("|        9 - Telefone                                                                         |\n");
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            printf("===> Digite sua opcao: ");
            scanf("%d", &dado);  
            getchar();   
            
            if (dado < 1 || dado > 9) {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                return;
            } else {
                printf("|                                                                                             |\n");
                printf("|   ===> Digite o novo dado: ");
                fgets(edicao, sizeof(edicao), stdin);
                tam = strlen(edicao);
                edicao[tam-1] = '\0';

                switch (dado) {
                    case 1: strcpy(clientePJ->cnpj, edicao); break;
                    case 2: strcpy(clientePJ->razaoSocial, edicao); break;
                    case 3: strcpy(clientePJ->nomeFantasia, edicao); break;
                    case 4: strcpy(clientePJ->repres, edicao); break;
                    case 5: strcpy(clientePJ->cpfRepres, edicao); break;
                    case 6: strcpy(clientePJ->areaAtuacao, edicao); break;
                    case 7: strcpy(clientePJ->endereco, edicao); break;
                    case 8: strcpy(clientePJ->email, edicao); break;
                    case 9: strcpy(clientePJ->telefone, edicao); break;
                }
            }
        }
        fwrite(clientePJ, sizeof(ClientePJ), 1, temp_empresa);
    }
    fclose(arq_empresa);
    fclose(temp_empresa);

    if (encontrado) {
        remove("clientePJ.dat");
        rename("temp_clientePJ.dat", "clientePJ.dat");

        printf("|                                                                                             |\n");
        printf("|        Dados atualizados com sucesso!                                                       |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    } else {
        remove("temp_clientePJ.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Cliente não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    }
}

void excluiClientePJ(void) {
    system("clear");
    FILE *arq_empresa;
    FILE *temp_empresa;
    
    ClientePJ *clientePJ;
    clientePJ = (ClientePJ*) malloc(sizeof(ClientePJ));

    char pesquisar_cnpj[21];
    int tam, confi;
    int encontrado = 0, excluir = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(pesquisar_cnpj, sizeof(pesquisar_cnpj), stdin);
    tam = strlen(pesquisar_cnpj);
    pesquisar_cnpj[tam-1] = '\0';

    arq_empresa = fopen("clientePJ.dat", "rb");
    temp_empresa = fopen("temp_clientePJ.dat", "wb");

    while (fread(clientePJ, sizeof(ClientePJ), 1, arq_empresa) == 1){
        if (strcmp(clientePJ->cnpj, pesquisar_cnpj) != 0){
            fwrite(clientePJ, sizeof(ClientePJ), 1, temp_empresa);
        } else {
            encontrado = 1;
            printf("|\t\tCNPJ: %s\n", clientePJ->cnpj);
            printf("|\t\tRazão Social: %s\n", clientePJ->razaoSocial);
            printf("|\t\tNome Fantasia: %s\n", clientePJ->nomeFantasia);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o cliente que deseja excluir? 1 = Sim, 2 = Não: ");
            scanf("%d", &confi);
            getchar();

            if (confi == 1) {
                excluir = 1;
            } else if (confi == 2) {
                fwrite(clientePJ, sizeof(ClientePJ), 1, temp_empresa);
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                return;
            }
        }
    }
    fclose(arq_empresa);
    fclose(temp_empresa);

    if (!encontrado) {
        remove("temp_clientePJ.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Cliente não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    } else if (excluir){
        remove("clientePJ.dat");
        rename("temp_clientePJ.dat", "clientePJ.dat");

        printf("|                                                                                             |\n");
        printf("|        Cliente excluido com sucesso!                                                        |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    } else {
        remove("temp_clientePJ.dat");
        printf("|                                                                                             |\n");
        printf("|        Exclusão cancelada!                                                                  |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    }
}