#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utilidades.h>
#include "validacao.h"
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
        case 5:
            relatorioClientePF();
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
    printf("|                          5 - Lista clientes                                                 |\n");
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
    FILE *arq_cliente;

    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));

    clientePF->atividade = 1;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Cliente                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do cliente:                                                         |\n");
    printf("|\n");
    do{
        input(clientePF->cpf, sizeof(clientePF->cpf), "|   ===> CPF: ");
    }while(!vali_cpf(clientePF->cpf));

    do{
        input(clientePF->nome, sizeof(clientePF->nome), "|   ===> Nome: ");
    }while(!vali_nome(clientePF->nome));
     
    input(clientePF->sexo, sizeof(clientePF->sexo), "|   ===> Qual genero (Masculino = M) ou (Feminino = F): ");
    
    do{
        input(clientePF->dataNasc, sizeof(clientePF->dataNasc), "|   ===> Data de Nascimento (dd/nn/aaaa): ");
    }while(!vali_dataNasc(clientePF->dataNasc));

    input(clientePF->endereco, sizeof(clientePF->endereco), "|   ===> Endereço: ");
    
    input(clientePF->email, sizeof(clientePF->email), "|   ===> Email: ");
    
    do{
        input(clientePF->telefone, sizeof(clientePF->telefone), "|   ===> Telefone: ");
    }while(!vali_telefone(clientePF->telefone));


    arq_cliente = fopen("clientePF.dat","ab");
    if (arq_cliente == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(clientePF);
        return;
    }

    if(clientePF->sexo[0] == 'm' || clientePF->sexo[0] == 'M'){
        strcpy(clientePF->sexo,"Masculino");
    }else{
        strcpy(clientePF->sexo,"Feminino");
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
    FILE *arq_cliente;

    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));

    char cpf_lido[16];
    /*int tam;*/
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Mostrar Cliente                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    input(cpf_lido, sizeof(cpf_lido), "|   ===> Digite o CPF do cliente: ");

    arq_cliente = fopen("clientePF.dat", "rb");
    if (arq_cliente == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1) {
        if (strcmp(clientePF->cpf, cpf_lido) == 0){
            encontrado = 1;
            if (clientePF->atividade == 1){
                printf("|\t\tCPF: %s\n", clientePF->cpf);
                printf("|\t\tNome: %s\n", clientePF->nome);
                printf("|\t\tSexo: %s\n", clientePF->sexo);
                printf("|\t\tData de Nascimento: %s\n", clientePF->dataNasc);
                printf("|\t\tEndereço: %s\n", clientePF->endereco);
                printf("|\t\tEmail: %s\n", clientePF->email);
                printf("|\t\tTelefone: %s\n", clientePF->telefone);
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                return;
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|               Cliente Inativo!               |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                return;
            }
        }
    }
    fclose(arq_cliente);
    if(!encontrado){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Cliente não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
}


void editaClientePF(void) {
    system("clear");
    FILE *arq_cliente;
    FILE *temp_cliente;

    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));

    char cpf_lido[16];
    int tam, dado;   // tam nao esta sendo usado!
    int encontrado = 0;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Editar Cliente                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    input(cpf_lido, sizeof(cpf_lido), "|   ===> Digite o CPF do cliente: ");

    arq_cliente = fopen("clientePF.dat", "rb");
    temp_cliente = fopen("temp_clientePF.dat","wb");
    if (arq_cliente == NULL || temp_cliente == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }

    while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1) {
        if (strcmp(clientePF->cpf, cpf_lido) == 0){
            encontrado = 1;
            if (clientePF->atividade == 1){
                printf("|\t\tCPF: %s\n", clientePF->cpf);
                printf("|\t\tNome: %s\n", clientePF->nome);
                printf("|\t\tData de Nascimento: %s\n", clientePF->dataNasc);
                printf("|\t\tEndereço: %s\n", clientePF->endereco);
                printf("|\t\tEmail: %s\n", clientePF->email);
                printf("|\t\tTelefone: %s\n", clientePF->telefone);
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

                if (dado < 1 || dado > 6) {
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
                    edicao[tam - 1] = '\0';

                    switch (dado) {
                        case 1: strcpy(clientePF->cpf, edicao); break;
                        case 2: strcpy(clientePF->nome, edicao); break;
                        case 3: strcpy(clientePF->dataNasc, edicao); break;
                        case 4: strcpy(clientePF->endereco, edicao); break;
                        case 5: strcpy(clientePF->email, edicao); break;
                        case 6: strcpy(clientePF->telefone, edicao); break;
                    }
                }
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|               Cliente Inativo!               |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                remove("temp_clientePF.dat");
                return;
            }
        }
        fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
    }
    fclose(arq_cliente);
    fclose(temp_cliente);

    if(encontrado) {
        remove("clientePF.dat");
        rename("temp_clientePF.dat", "clientePF.dat");

        printf("|                                                                                             |\n");
        printf("|        Dados atualizados com sucesso!                                                       |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    } else {
        remove("temp_clientePF.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Cliente não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    }
}


void excluiClientePF(void) {
    system("clear");
    FILE *arq_cliente;
    FILE *temp_cliente;

    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));

    char cpf_lido[16];
    int confi; // tam nao esta sendo usado!
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                        Excluir Cliente                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    input(cpf_lido, sizeof(cpf_lido), "|   ===> Digite o CPF do cliente");

    arq_cliente = fopen("clientePF.dat","rb");
    temp_cliente = fopen("temp_clientePF.dat","wb");

    while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1){
        if (strcmp(clientePF->cpf, cpf_lido) != 0){
            fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
        } else {
            encontrado = 1;
            printf("|\t\tCPF: %s\n", clientePF->cpf);
            printf("|\t\tNome: %s\n", clientePF->nome);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o cliente que deseja excluir? 1 = Sim, 2 = Não: ");
            scanf("%d", &confi);
            getchar();

            if (confi == 1) {
                clientePF->atividade = 0;
                fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
                printf("|                                                                                             |\n");
                printf("|        Cliente excluido com sucesso!                                                        |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
            } else if (confi == 2) {
                fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
                printf("|                                                                                             |\n");
                printf("|        Exclusão cancelada!                                                                  |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                fclose(arq_cliente);
                fclose(temp_cliente);
                remove("temp_clientePF.dat");
                return;
            }
        }
    }
    fclose(arq_cliente);
    fclose(temp_cliente);
    
    if (!encontrado){
        remove("temp_clientePF.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Cliente não encontrado!            |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n"); 
    } else {
        remove("clientePF.dat");
        rename("temp_clientePF.dat", "clientePF.dat");
    }
    
}

void relatorioClientePF(void) {
    system("clear");
    FILE *arq_cliente;
    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    char op_sexo[3];
    char filtro_sexo[15];
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                                                                 |\n");
    printf("|                                                              Relatório de Clientes                                                              |\n");
    printf("|                                                                                                                                                 |\n");
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    arq_cliente = fopen ("clientePF.dat", "rb");
    if (arq_cliente == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(clientePF);
        return;
    }
    printf("Qual genero quero mostrar? (M = Masculino) ou (F = Feminino): ");
    scanf("%c", op_sexo);
    getchar();

    if(op_sexo[0] == 'm' || op_sexo[0] == 'M'){
        strcpy(filtro_sexo, "Masculino");
    }else{
        strcpy(filtro_sexo, "Feminino");
    }

    printf("%-20s %-20s %-30s %-30s %-30s %-30s\n", "CPF", "Nome", "Data de Nascimento", "Endereço", "Email", "Telefone");
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1) {
        if(strcmp(filtro_sexo, clientePF->sexo) == 0){
            if (clientePF->atividade == 1){
                printf("%-20s %-20s %-30s %-30s %-30s %-30s\n", clientePF->cpf, clientePF->nome, clientePF->dataNasc, clientePF->endereco, clientePF->email, clientePF->telefone);
            }
            printf("+-------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            
        }
    }
    fclose(arq_cliente);
    free(clientePF);
}