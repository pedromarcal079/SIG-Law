#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "advogado.h"


typedef struct advogado{
    char cpf[15];
    char nome[50];
    char carteiraOAB[12];       // Ex: 123456/SP , 78910-RJ , 98765 RN     
    char especialidade[50];
    char dataNasc[13];
    char endereco[100];
    char email[100];
    char telefone[20];
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
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
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
    Advogado *advogado;
    int tam;
    FILE *arq_advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Advogado                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do advogado:                                                        |\n");
    printf("|   ===> CPF: ");
    fgets(advogado->cpf, sizeof(advogado->cpf), stdin);
    tam = strlen(advogado->cpf);
    advogado->cpf[tam-1] = '\0';
    printf("|   ===> Nome: ");
    fgets(advogado->nome, sizeof(advogado->nome), stdin);
    tam = strlen(advogado->nome);
    advogado->nome[tam-1] = '\0';
    printf("|   ===> Carteira OAB: ");
    fgets(advogado->carteiraOAB, sizeof(advogado->carteiraOAB), stdin);
    tam = strlen(advogado->carteiraOAB);
    advogado->carteiraOAB[tam-1] = '\0';
    printf("|   ===> Especialidade: ");
    fgets(advogado->especialidade, sizeof(advogado->especialidade), stdin);
    tam = strlen(advogado->especialidade);
    advogado->especialidade[tam-1] = '\0';
    printf("|   ===> Data de Nascimento (dd/nn/aaaa): ");
    fgets(advogado->dataNasc, sizeof(advogado->dataNasc), stdin);
    tam = strlen(advogado->dataNasc);
    advogado->dataNasc[tam-1] = '\0';
    printf("|   ===> Endereço: ");
    fgets(advogado->endereco, sizeof(advogado->endereco), stdin);
    tam = strlen(advogado->endereco);
    advogado->endereco[tam-1] = '\0';
    printf("|   ===> Email: ");
    fgets(advogado->email, sizeof(advogado->email), stdin);
    tam = strlen(advogado->email);
    advogado->email[tam-1] = '\0';
    printf("|   ===> Telefone: ");
    fgets(advogado->telefone, sizeof(advogado->telefone), stdin);
    tam = strlen(advogado->telefone);
    advogado->telefone[tam-1] = '\0';
    printf("|                                                                                             |\n");
    printf("|        Advogado cadastrado com sucesso!                                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_advogado = fopen("advogado.dat","ab");
    if (arq_advogado == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        free(advogado);
        return;
    }
    fwrite(advogado, sizeof(advogado), 1, arq_advogado);
    fclose(arq_advogado);
    free(advogado);
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
    printf("|   ===> Digite o CPF do advogado: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';
    arq_advogado = fopen("advogado.csv", "rt");
    while (fscanf(arq_advogado,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
        advogado.cpf,
        advogado.nome,
        advogado.carteiraOAB, 
        advogado.especialidade,
        advogado.dataNasc,
        advogado.endereco,
        advogado.email,
        advogado.telefone
    )){
        if (strcmp(advogado.cpf, pesquisar_cpf) == 0){
            printf("|\t\tCPF: %s\n", advogado.cpf);
            printf("|\t\tNome: %s\n", advogado.nome);
            printf("|\t\tCarteira OAB: %s\n", advogado.carteiraOAB);
            printf("|\t\tEspecialidade: %s\n", advogado.especialidade);
            printf("|\t\tData de Nascimento: %s\n", advogado.dataNasc);
            printf("|\t\tEndereço: %s\n", advogado.endereco);
            printf("|\t\tEmail: %s\n", advogado.email);
            printf("|\t\tTelefone: %s\n", advogado.telefone);
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            return;
        }
    }
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    FILE *temp_advogado;
    Advogado advogado;
    char pesquisar_cpf[15];
    int tam;
    int dado;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CPF do advogado: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';

    arq_advogado = fopen("advogado.csv", "rt");
    temp_advogado = fopen("temp_advogado.csv", "wt");

    while (fscanf(arq_advogado,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", 
        advogado.cpf,
        advogado.nome,
        advogado.carteiraOAB,
        advogado.especialidade,
        advogado.dataNasc,
        advogado.endereco,
        advogado.email,
        advogado.telefone) == 8){
        
        if (strcmp(advogado.cpf, pesquisar_cpf) == 0){

            printf("|\t\tCPF: %s\n", advogado.cpf);
            printf("|\t\tNome: %s\n", advogado.nome);
            printf("|\t\tCarteira OAB: %s\n", advogado.carteiraOAB);
            printf("|\t\tEspecialidade: %s\n", advogado.especialidade);
            printf("|\t\tData de Nascimento: %s\n", advogado.dataNasc);
            printf("|\t\tEndereço: %s\n", advogado.endereco);
            printf("|\t\tEmail: %s\n", advogado.email);
            printf("|\t\tTelefone: %s\n", advogado.telefone);
            printf("|                                                                                             |\n");
            
            printf("+---------------------------------------------------------------------------------------------+\n");
            printf("|                                                                                             |\n");
            printf("|   ===> Qual dado você deseja editar?                                                        |\n");
            printf("|        1 - CPF                                                                              |\n");
            printf("|        2 - Nome                                                                             |\n");
            printf("|        3 - Carteira OAB                                                                     |\n");
            printf("|        4 - Especialidade                                                                    |\n");
            printf("|        5 - Data de Nascimento                                                               |\n");
            printf("|        6 - Endereço                                                                         |\n");
            printf("|        7 - Email                                                                            |\n");
            printf("|        8 - Telefone                                                                         |\n");
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

            switch(dado) {
                case 1: strcpy(advogado.cpf, edicao); break; //esse strcpy faz uma cópia do novo valor para o campo correto da struct
                case 2: strcpy(advogado.nome, edicao); break;
                case 3: strcpy(advogado.carteiraOAB, edicao); break;
                case 4: strcpy(advogado.especialidade, edicao); break;
                case 5: strcpy(advogado.dataNasc, edicao); break;
                case 6: strcpy(advogado.endereco, edicao); break;
                case 7: strcpy(advogado.email, edicao); break;
                case 8: strcpy(advogado.telefone, edicao); break;
            }
        }
        fprintf(temp_advogado, "%s;%s;%s;%s;%s;%s;%s;%s\n",
            advogado.cpf,
            advogado.nome,
            advogado.carteiraOAB,
            advogado.especialidade,
            advogado.dataNasc,
            advogado.endereco,
            advogado.email,
            advogado.telefone
        );
    }

    fclose(arq_advogado);
    fclose(temp_advogado);
    remove("advogado.csv");
    rename("temp_advogado.csv", "advogado.csv");
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    FILE *temp_advogado;
    Advogado advogado;
    char pesquisar_cpf[15];
    int tam;
    int confi;

    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do advogado: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';

    arq_advogado = fopen("advogado.csv", "rt");
    temp_advogado = fopen("temp_advogado.csv","wt");

    while (fscanf(arq_advogado,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
        advogado.cpf,
        advogado.nome,
        advogado.carteiraOAB,
        advogado.especialidade,
        advogado.dataNasc,
        advogado.endereco,
        advogado.email,
        advogado.telefone) == 8){

        if (strcmp(advogado.cpf, pesquisar_cpf) != 0){
            fprintf(temp_advogado, "%s;%s;%s;%s;%s;%s;%s:%s\n",
            advogado.cpf,
            advogado.nome,
            advogado.carteiraOAB,
            advogado.especialidade,
            advogado.dataNasc,
            advogado.endereco,
            advogado.email,
            advogado.telefone);
        } else {
            printf("|\t\tCPF: %s\n", advogado.cpf);
            printf("|\t\tNome: %s\n", advogado.nome);
            printf("|\t\tCarteira OAB: %s\n", advogado.carteiraOAB);
            printf("|\t\tEspecialidade: %s\n", advogado.especialidade);
            printf("|\t\tData de Nascimento: %s\n", advogado.dataNasc);
            printf("|\t\tEndereço: %s\n", advogado.endereco);
            printf("|\t\tEmail: %s\n", advogado.email);
            printf("|\t\tTelefone: %s\n", advogado.telefone);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o cliente que deseja excluir? 1 = Sim, 2 = Não: ");
            scanf("%d", &confi);
            getchar();

            if (confi == 2) {
                fprintf(temp_advogado, "%s;%s;%s;%s;%s;%s;%s;%s\n",
                    advogado.cpf,
                    advogado.nome,
                    advogado.carteiraOAB,
                    advogado.especialidade,
                    advogado.dataNasc,
                    advogado.endereco,
                    advogado.email,
                    advogado.telefone);
            }
        }
    }
    fclose(arq_advogado);
    fclose(temp_advogado);
    remove("advogado.csv");
    rename("temp_advogado.csv", "advogado.csv");

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