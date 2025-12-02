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
            lixeiraClientePF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 6:
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
    printf("|                          5 - Lixeira cliente                                                |\n");
    printf("|                          6 - Lista clientes                                                 |\n");
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

    int j, i = 0;
    char temp_dataNasc[13];
    char temp_cpf[15];

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Cliente                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do cliente:                                                         |\n");
    printf("|\n");
    do{
        printf("|   ===> CPF: ");
        scanf("%s", temp_cpf);
        getchar();
        /*input(clientePF->cpf, sizeof(clientePF->cpf), "|   ===> CPF: ");*/
    }while(!vali_cpf(temp_cpf));

    do{
        input(clientePF->nome, sizeof(clientePF->nome), "|   ===> Nome: ");
    }while(!vali_nome(clientePF->nome));

    do{
        input(clientePF->sexo, sizeof(clientePF->sexo), "|   ===> Qual genero (Masculino = M) ou (Feminino = F): ");
    }while(!vali_sexo(clientePF->sexo));
    
    do{
        printf("|   ===> Data de Nascimento (dd/nn/aaaa): ");
        scanf("%s", temp_dataNasc);
        getchar();
        /*input(clientePF->dataNasc, sizeof(clientePF->dataNasc), "|   ===> Data de Nascimento (dd/nn/aaaa): ");*/
    }while(!vali_dataNasc(temp_dataNasc));

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
        fclose(arq_cliente);
        free(clientePF);
        return;
    }

    if(clientePF->sexo[0] == 'm' || clientePF->sexo[0] == 'M'){
        strcpy(clientePF->sexo,"Masculino");
    }else if(clientePF->sexo[0] == 'f' || clientePF->sexo[0] == 'F'){
        strcpy(clientePF->sexo,"Feminino");
    }



    // PARTE QUE PEGA A DATA DE NASCIMENTO E DIVIDE COM A "/"
    for(j = 0; j < 2; j++){
        clientePF->dataNasc[i++] = temp_dataNasc[j];
    }

    clientePF->dataNasc[i++] = '/';
    

    for(j = 2; j < 4; j++){
        clientePF->dataNasc[i++] = temp_dataNasc[j];
    }

    clientePF->dataNasc[i++] = '/';

    for(j = 4; j < 8; j++){
        clientePF->dataNasc[i++] = temp_dataNasc[j];
    }

    i = 0;

    // PARTE QUE SEPARA O CPF COM OS '.' e o '-'
    for(j = 0; j < 3; j++){
        clientePF->cpf[i++] = temp_cpf[j];
    }

    clientePF->cpf[i++] = '.';

    for(j = 3; j < 6; j++){
        clientePF->cpf[i++] = temp_cpf[j];
    }

    clientePF->cpf[i++] = '.';

    for(j = 6; j < 9; j++){
        clientePF->cpf[i++] = temp_cpf[j];
    }

    clientePF->cpf[i++] = '-';

    for(j = 9; j < 11; j++){
        clientePF->cpf[i++] = temp_cpf[j];
    }

    clientePF->cpf[i] = '\0';



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
        fclose(arq_cliente);
        free(clientePF);
        return;
    }

    while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1) {
        if (strcmp(clientePF->cpf, cpf_lido) == 0){
            encontrado = 1;
            if (clientePF->atividade == 1){
                printf("|\n");
                printf("|\t\tCPF: %s\n", clientePF->cpf);
                printf("|\t\tNome: %s\n", clientePF->nome);
                printf("|\t\tSexo: %s\n", clientePF->sexo);
                printf("|\t\tData de Nascimento: %s\n", clientePF->dataNasc);
                printf("|\t\tEndereço: %s\n", clientePF->endereco);
                printf("|\t\tEmail: %s\n", clientePF->email);
                printf("|\t\tTelefone: %s\n", clientePF->telefone);
                printf("|\t\tID do Processo: %s\n", clientePF->idProcesso);
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(arq_cliente);
                free(clientePF);
                return;
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|               Cliente Inativo!               |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                fclose(arq_cliente);
                free(clientePF);
                return;
            }
        }
    }
    fclose(arq_cliente);
    free(clientePF);
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
        fclose(arq_cliente);
        fclose(temp_cliente);
        free(clientePF);
        /*free(temp_cliente);*/
        return;
    }

    while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1) {
        if (strcmp(clientePF->cpf, cpf_lido) == 0){
            encontrado = 1;
            if (clientePF->atividade == 1){
                printf("|\n");
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
    free(clientePF);
    /*free(temp_cliente);*/

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
    FILE *arq_cliente = NULL;
    FILE *temp_cliente = NULL;
    ClientePF *clientePF = NULL;
    
    char cpf_lido[20];
    int confi; // tam nao esta sendo usado!
    int encontrado = 0;

    clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    if(clientePF == NULL){
        system("clear");
        printf("\n\n\tErro: Falha na alocacao de memoria. \n\n");
        return;
    }

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                        Excluir Cliente                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CPF do cliente: ");
    scanf("%s", cpf_lido);
    getchar();

    arq_cliente = fopen("clientePF.dat","rb");
    if(arq_cliente == NULL){
        printf("\n\tErro: Arquivo de cliente nao encontrado.\n");
        free(clientePF);
        return;;
    }

    temp_cliente = fopen("temp_clientePF.dat","wb");
    if(temp_cliente == NULL){
        printf("\n\tErro: Nao foi possivel criar arquivo temporario.\n");
        fclose(temp_cliente);
        free(clientePF);
        return;
    }

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
                /*fclose(arq_cliente);
                fclose(temp_cliente);
                free(clientePF);*/
            } else if (confi == 2) {
                fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
                printf("|                                                                                             |\n");
                printf("|        Exclusão cancelada!                                                                  |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                /*fclose(arq_cliente);
                fclose(temp_cliente);
                free(clientePF);*/
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                /*fclose(arq_cliente);
                fclose(temp_cliente);
                free(clientePF);*/
                remove("temp_clientePF.dat");
                /*return;*/
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
    free(clientePF);
}

void relatorioClientePF(void) {
    system("clear");
    FILE *arq_cliente;
    ClientePF *clientePF;
    clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    int opcao;
    char op_sexo[3];
    char filtro_sexo[15];
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                                                                 |\n");
    printf("|                                                              Relatório de Clientes                                                              |\n");
    printf("|                                                                                                                                                 |\n");
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| gostaria de filtrar algum dado? (1- Sim / 2- Não): ");
    scanf("%i", &opcao);
    getchar();
    if (opcao == 2){
        arq_cliente = fopen ("clientePF.dat", "rb");
        if (arq_cliente == NULL){
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Erro ao abrir o arquivo!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            fclose(arq_cliente);
            free(clientePF);
            return;
        }
        printf("\n%-20s %-20s %-30s %-31s %-30s %-20s %-20s\n", "CPF", "Nome", "Data de Nascimento", "Endereço", "Email", "Telefone", "ID do Processo");
        printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
        while(fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1){
            if(clientePF->atividade == 1){
                printf("%-20s %-20s %-30s %-30s %-30s %-20s %-20s\n",clientePF->cpf, clientePF->nome, clientePF->dataNasc, clientePF->endereco, clientePF->email, clientePF->telefone, clientePF->idProcesso);
            }
            printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
        }
        fclose(arq_cliente);
        free(clientePF);
    }
    else if(opcao == 1){
        arq_cliente = fopen ("clientePF.dat", "rb");
        printf("|\n");
        printf("| Qual genero quero mostrar? (M = Masculino) ou (F = Feminino): ");
        scanf("%c", op_sexo);
        getchar();

        if(op_sexo[0] == 'm' || op_sexo[0] == 'M'){
            strcpy(filtro_sexo, "Masculino");
        }else{
            strcpy(filtro_sexo, "Feminino");
        }

        printf("%-20s %-20s %-30s %-30s %-30s %-20s %-20s\n", "CPF", "Nome", "Data de Nascimento", "Endereço", "Email", "Telefone", "Id do Processo");
        printf("+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
        while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1) {
            if(strcmp(filtro_sexo, clientePF->sexo) == 0){
                if (clientePF->atividade == 1){
                    printf("%-20s %-20s %-30s %-30s %-30s %-20s %-20s\n",clientePF->cpf, clientePF->nome, clientePF->dataNasc, clientePF->endereco, clientePF->email, clientePF->telefone, clientePF->idProcesso);
                }   
                printf("+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            
            }
        }
        fclose(arq_cliente);
        free(clientePF);
    }
}

void lixeiraClientePF(void) {
    system("clear");
    FILE *arq_cliente;
    FILE *temp_cliente;
    ClientePF *clientePF;

    int opcao;
    int encontrado = 0;
    char pesquisar_cpf[15];

    clientePF = (ClientePF*) malloc(sizeof(ClientePF));
    
    printf("+------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                |\n");
    printf("|                                      Lixeira Cliente                                           |\n");
    printf("|                                                                                                |\n");
    printf("+------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                |\n");
    printf("|   ===> Você deseja restaurar um advogado ou esvaziar a lixeira? (1- Restaurar / 2- esvaziar): ");
    scanf("%d", &opcao);
    getchar();
    if (opcao == 1) {
        arq_cliente = fopen("clientePF.dat", "r+b");
        input(pesquisar_cpf, sizeof(pesquisar_cpf), "Digite o CPF do cliente que deseja restaurar: ");
        while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1){
            if ((clientePF->atividade == 0) && (strcmp(clientePF->cpf, pesquisar_cpf) == 0)){
                encontrado = 1;
                clientePF->atividade = 1;
                fseek(arq_cliente, -sizeof(ClientePF), SEEK_CUR);
                fwrite(clientePF, sizeof(ClientePF), 1, arq_cliente);
                printf("|                                                                                             |\n");
                printf("|         Cliente restaurado com sucesso!                                                     |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                getchar();
                fclose(arq_cliente);
                free(clientePF);
                return;
            }
        }
        if (!encontrado){
            system("clear");
            printf("+-----------------------------------------------+\n");
            printf("|                                               |\n");
            printf("|            Cliente não encontrado!            |\n");
            printf("|                                               |\n");
            printf("+-----------------------------------------------+\n");
            fclose(arq_cliente);
            free(clientePF);
            return;
        }
    } 
    else if (opcao == 2) {
        arq_cliente = fopen("clientePF.dat", "rb");
        temp_cliente = fopen("temp_clientePF.dat","wb");
        while (fread(clientePF, sizeof(ClientePF), 1, arq_cliente) == 1){
            if (clientePF->atividade == 1){
                fwrite(clientePF, sizeof(ClientePF), 1, temp_cliente);
            }
        }
        fclose(arq_cliente);
        fclose(temp_cliente);
        free(clientePF);
        remove("clientePF.dat");
        rename("temp_clientePF.dat", "clientePF.dat");
        return;
    } 
    else {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|       Você digitou uma opção inválida!       |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        remove("temp_clientePF.dat");
        return;
    }
}