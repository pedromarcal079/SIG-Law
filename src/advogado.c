#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "advogado.h"
#include "processosPF.h"
#include "processosPJ.h"
#include "validacao.h"
#include "utilidades.h"


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
            case 5:
                lixeiraAdvogado();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 6:
                relatorioAdvogado();
                printf("Pressione ENTER ... \n");
                getchar();
                break;
            case 7:
                listaAdvogado();
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
    printf("|                               4 - Exclui Advogado                                           |\n");
    printf("|                               5 - Lixeira Advogado                                          |\n");
    printf("|                               6 - Relatorio Advogados                                       |\n");
    printf("|                               7 - Listar Advogados                                          |\n");
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
    int espec;
    FILE *arq_advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    if (advogado == NULL) {
        printf("\nERRO: Falha na alocacao de memoria para o advogado. \n");
        return;
    }
    advogado->atividade = 1;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Advogado                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do advogado:                                                        |\n");
    do{
        input(advogado->cpf, sizeof(advogado->cpf), "|   ===> CPF: ");
    } while(!vali_cpf(advogado->cpf));

    do{
        input(advogado->nome, sizeof(advogado->nome), "|   ===> Nome: ");
    } while(!vali_nome(advogado->nome));

    do{
        input(advogado->carteiraOAB, sizeof(advogado->carteiraOAB), "|   ===> Carteira OAB: ");
    } while(!vali_carteiraOAB(advogado->carteiraOAB));

    printf("              |   ===> Especialidade <===   |                   \n");
    printf("| 1-Civil  2-Penal  3-Do Trabalho  4-Tributário  5-Empresarial |\n");
    printf("Digite a opção desejada:");
    scanf("%d", &espec);
    getchar();
    switch (espec){
        case 1: (strcpy(advogado->especialidade, "Civil")); break;
        case 2: (strcpy(advogado->especialidade, "Penal")); break;
        case 3: (strcpy(advogado->especialidade, "Do Trabalho")); break;
        case 4: (strcpy(advogado->especialidade, "Tributário")); break;
        case 5: (strcpy(advogado->especialidade, "Empresarial")); break;
    }


    do{
        input(advogado->dataNasc, sizeof(advogado->dataNasc), "|   ===> Data de Nascimento: ");
    } while(!vali_dataNasc(advogado->dataNasc));

    input(advogado->endereco, sizeof(advogado->endereco), "|   ===> Endereço: ");

    input(advogado->email, sizeof(advogado->email), "|   ===> Email: ");

    do{
       input(advogado->telefone, sizeof(advogado->telefone), "|   ===> telefone: ");
    } while(!vali_telefone(advogado->telefone));
    
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
    fwrite(advogado, sizeof(Advogado), 1, arq_advogado);
    fclose(arq_advogado);
    free(advogado);

    printf("|                                                                                             |\n");
    printf("|        Advogado cadastrado com sucesso!                                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void mostraAdvogado(void){
    system("clear");
    FILE *arq_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    char pesquisar_cpf[15];
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    input(pesquisar_cpf, sizeof(pesquisar_cpf), "|   ===> Digite o CPF do advogado: ");
    arq_advogado = fopen("advogado.dat", "rb");
    if (arq_advogado == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        if (advogado) free(advogado);
        return;
    }
    while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
        if (strcmp(advogado->cpf, pesquisar_cpf) == 0){
            encontrado = 1;
            printf("|\n");
            printf("|\t\tCPF: %s\n", advogado->cpf);
            printf("|\t\tNome: %s\n", advogado->nome);
            printf("|\t\tCarteira OAB: %s\n", advogado->carteiraOAB);
            printf("|\t\tEspecialidade: %s\n", advogado->especialidade);
            printf("|\t\tData de Nascimento: %s\n", advogado->dataNasc);
            printf("|\t\tEndereço: %s\n", advogado->endereco);
            printf("|\t\tEmail: %s\n", advogado->email);
            printf("|\t\tTelefone: %s\n", advogado->telefone);
            printf("|                                                                                             |\n");
            printf("+---------------------------------------------------------------------------------------------+\n");
            fclose(arq_advogado);
            free(advogado);
            return;
        }
    }
    fclose(arq_advogado);
    free(advogado);
    if(!encontrado){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Advogado não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    FILE *temp_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    char pesquisar_cpf[15];
    int dado, espec;
    int encontrado = 0;
    char edicao[100];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    input(pesquisar_cpf, sizeof(pesquisar_cpf), "|   ===> Digite o cpf do advogado: ");

    arq_advogado = fopen("advogado.dat", "rb");
    temp_advogado = fopen("temp_advogado.dat", "wb");
    if (arq_advogado == NULL || temp_advogado == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        if (arq_advogado) fclose(arq_advogado);
        if (temp_advogado) fclose(temp_advogado);
        if (advogado) free(advogado);
        return;
    }

    while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
        if (strcmp(advogado->cpf, pesquisar_cpf) == 0){
            encontrado = 1;
            printf("|\t\tCPF: %s\n", advogado->cpf);
            printf("|\t\tNome: %s\n", advogado->nome);
            printf("|\t\tCarteira OAB: %s\n", advogado->carteiraOAB);
            printf("|\t\tEspecialidade: %s\n", advogado->especialidade);
            printf("|\t\tData de Nascimento: %s\n", advogado->dataNasc);
            printf("|\t\tEndereço: %s\n", advogado->endereco);
            printf("|\t\tEmail: %s\n", advogado->email);
            printf("|\t\tTelefone: %s\n", advogado->telefone);
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

            if (dado < 1 || dado > 8) {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                return;
            } else {
                switch (dado) {
                    case 1: { 
                        input(edicao, sizeof(edicao), "Digite o novo CPF: ");
                        strcpy(advogado->cpf, edicao);
                    }; break;
                    case 2: { 
                        input(edicao, sizeof(edicao), "Digite o novo nome: ");
                        strcpy(advogado->nome, edicao);
                    }; break;
                    case 3: { 
                        input(edicao, sizeof(edicao), "Digite a nova carteira OAB: ");
                        strcpy(advogado->carteiraOAB, edicao);
                    }; break;
                    case 4: {
                        printf("              |   ===> Especialidade <===   |                   \n");
                        printf("| 1-Civil  2-Penal  3-Do Trabalho  4-Tributário  5-Empresarial |\n");
                        printf("Digite a opção desejada:");
                        scanf("%d", &espec);
                        getchar();
                        switch (espec){
                            case 1: (strcpy(advogado->especialidade, "Civil")); break;
                            case 2: (strcpy(advogado->especialidade, "Penal")); break;
                            case 3: (strcpy(advogado->especialidade, "Do Trabalho")); break;
                            case 4: (strcpy(advogado->especialidade, "Tributário")); break;
                            case 5: (strcpy(advogado->especialidade, "Empresarial")); break;
                        }
                    }; break;
                    case 5: { 
                        input(edicao, sizeof(edicao), "Digite a nova data de nascimento: ");
                        strcpy(advogado->dataNasc, edicao);
                    }; break;
                    case 6: { 
                        input(edicao, sizeof(edicao), "Digite o novo endereço: ");
                        strcpy(advogado->endereco, edicao);
                    }; break;
                    case 7: { 
                        input(edicao, sizeof(edicao), "Digite o novo email: ");
                        strcpy(advogado->email, edicao);
                    }; break;
                    case 8: { 
                        input(edicao, sizeof(edicao), "Digite o novo telefone: ");
                        strcpy(advogado->telefone, edicao);
                    }; break;
                }
            }
        }
        fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
    }
    fclose(arq_advogado);
    fclose(temp_advogado);
    free(advogado);

    if(encontrado) {
        remove("advogado.dat");
        rename("temp_advogado.dat", "advogado.dat");

        printf("|                                                                                             |\n");
        printf("|        Dados atualizados com sucesso!                                                       |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
    } else {
        remove("temp_advogado.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Advogado não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
    }
}


void excluiAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    char pesquisar_cpf[15];
    int confi;
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    input(pesquisar_cpf, sizeof(pesquisar_cpf), "|   ===> Digite o cpf do advogado: ");

    arq_advogado = fopen("advogado.dat", "r+b");
    if (arq_advogado == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        if (advogado) free(advogado);
        return;
    }

    while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
        if (strcmp(advogado->cpf, pesquisar_cpf) == 0){
            encontrado = 1;
            printf("|\t\tCPF: %s\n", advogado->cpf);
            printf("|\t\tNome: %s\n", advogado->nome);
            printf("|\t\tCarteira OAB: %s\n", advogado->carteiraOAB);
            printf("|\t\tEspecialidade: %s\n", advogado->especialidade);
            printf("|\t\tData de Nascimento: %s\n", advogado->dataNasc);
            printf("|\t\tEndereço: %s\n", advogado->endereco);
            printf("|\t\tEmail: %s\n", advogado->email);
            printf("|\t\tTelefone: %s\n", advogado->telefone);
            printf("|                                                                                             |\n");
            printf("|   ===> Esse é o advogado que deseja excluir? 1 = Sim, 2 = Não: ");
            scanf("%d", &confi);
            getchar();

            if (confi == 1) {
                advogado->atividade = 0;
                fseek(arq_advogado, -sizeof(Advogado), SEEK_CUR);
                fwrite(advogado, sizeof(Advogado), 1, arq_advogado);
                printf("|                                                                                             |\n");
                printf("|        Advogado excluido com sucesso!                                                       |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(arq_advogado);
                free(advogado);
                return;
            } else if (confi == 2) {
                /* não sobrescrever o registro se a exclusão foi cancelada */
                printf("|                                                                                             |\n");
                printf("|        Exclusão cancelada!                                                                  |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(arq_advogado);
                free(advogado);
                return;
            } else {
                system("clear");
                printf("+----------------------------------------------+\n");
                printf("|                                              |\n");
                printf("|       Você digitou uma opção inválida!       |\n");
                printf("|                                              |\n");
                printf("+----------------------------------------------+\n");
                fclose(arq_advogado);
                free(advogado);
                return;
            }
        }
    }
    fclose(arq_advogado);
    free(advogado);
    
    if (!encontrado){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Advogado não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n"); 
    }
}


void lixeiraAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    FILE *temp_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    int opcao;
    int encontrado = 0;
    char pesquisar_cpf[15];
    
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Lixeira Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Você deseja restaurar um advogado ou esvaziar a lixeira? (1- Restaurar / 2- esvaziar)|\n");
    scanf("%d", &opcao);
    getchar();
    if (opcao == 1) {
        arq_advogado = fopen("advogado.dat", "r+b");
        if (arq_advogado == NULL) {
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Erro ao abrir o arquivo!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            if (advogado) free(advogado);
            return;
        }
        input(pesquisar_cpf, sizeof(pesquisar_cpf), "Digite o CPF do advogado que deseja restaurar: ");
        while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
            if ((advogado->atividade == 0) && (strcmp(advogado->cpf, pesquisar_cpf) == 0)){
                encontrado = 1;
                advogado->atividade = 1;
                fseek(arq_advogado, -sizeof(Advogado), SEEK_CUR);
                fwrite(advogado, sizeof(Advogado), 1, arq_advogado);
                printf("|                                                                                             |\n");
                printf("|        Advogado restaurado com sucesso!                                                     |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(arq_advogado);
                free(advogado);
                return;
            }
        }
        if (!encontrado){
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Advogado não encontrado!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            fclose(arq_advogado);
            free(advogado);
            return;
        }
    } 
    else if (opcao == 2) {
        arq_advogado = fopen("advogado.dat", "rb");
        temp_advogado = fopen("temp_advogado.dat","wb");
        if (arq_advogado == NULL || temp_advogado == NULL) {
            if (arq_advogado) fclose(arq_advogado);
            if (temp_advogado) fclose(temp_advogado);
            if (advogado) free(advogado);
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Erro ao abrir o arquivo!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            return;
        }
        while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
            if (advogado->atividade == 1){
                fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
            }
        }
        fclose(arq_advogado);
        fclose(temp_advogado);
        free(advogado);
        remove("advogado.dat");
        rename("temp_advogado.dat", "advogado.dat");
        return;
    } 
    else {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|       Você digitou uma opção inválida!       |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        remove("temp_advogado.dat");
        return;
    }
}

void relatorioAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    int opcao, filtro, pesq_espec;
    char pesq_nome[50];
    char *especialidade;
    int i = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Relatório de Advogados                                   |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("| gostaria de filtrar algum dado? (1- Sim / 2- Não): ");
    scanf("%d", &opcao);
    getchar();
    if (opcao == 2){
        arq_advogado = fopen ("advogado.dat", "rb");
        if (arq_advogado == NULL){
            system("clear");
            printf("+----------------------------------------------+\n");
            printf("|                                              |\n");
            printf("|           Erro ao abrir o arquivo!           |\n");
            printf("|                                              |\n");
            printf("+----------------------------------------------+\n");
            free(advogado);
            return;
        }
        printf("\n%-20s %-20s %-20s %-20s %-15s %-26s %-20s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
        printf("+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
        while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
            if (advogado->atividade){
                printf("%-20s %-20s %-20s %-20s %-15s %-25s %-20s %-15s %-15s %-15s\n",
                    advogado->cpf,
                    advogado->nome,
                    advogado->carteiraOAB,
                    advogado->especialidade,
                    advogado->dataNasc,
                    advogado->endereco,
                    advogado->email,
                    advogado->telefone,
                    advogado->idProcessoPF,
                    advogado->idProcessoPJ);
                    i++;
                    printf("+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            }
        }
        printf("\n+------------------------------------------------------------------------------------------------------+\n");
        printf("|   Total de advogados ativos: %d                                                                       |\n", i);
        printf("+------------------------------------------------------------------------------------------------------+\n");
        fclose(arq_advogado);
        free(advogado);
    }

    else if (opcao == 1){
        arq_advogado = fopen ("advogado.dat", "rb");
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
        printf("+---------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                             |\n");
        printf("|   ===> Qual dado você deseja filtrar?                                                       |\n");
        printf("|        1 - Nome                                                                             |\n");
        printf("|        2 - Especialidade                                                                    |\n");
        printf("|                                                                                             |\n");
        printf("+---------------------------------------------------------------------------------------------+\n");
        scanf("%d", &filtro);
        getchar();
        switch(filtro) {
            case 1: {
                input(pesq_nome, sizeof(pesq_nome), "|  ===> Digite o nome que você deseja filtrar:             |\n");
                printf("\n%-20s %-20s %-20s %-20s %-15s %-26s %-20s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
                printf("+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if ((strcmp(advogado->nome, pesq_nome) == 0) && (advogado->atividade)){
                        printf("%-20s %-20s %-20s %-20s %-15s %-25s %-20s %-15s %-15s %-15s\n",
                            advogado->cpf,
                            advogado->nome,
                            advogado->carteiraOAB,
                            advogado->especialidade,
                            advogado->dataNasc,
                            advogado->endereco,
                            advogado->email,
                            advogado->telefone,
                            advogado->idProcessoPF,
                            advogado->idProcessoPJ);
                            printf("+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                            i++;
                    }
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
                printf("|   Total de advogados Com este nome: %d                                                               |\n", i);
                printf("+------------------------------------------------------------------------------------------------------+\n");
                fclose(arq_advogado);
                free(advogado);
            }; break; 
            case 2: {
                printf("|     ===> Qual especiaçidade você deseja filtrar:             |\n");
                printf("| 1-Civil  2-Penal  3-Do Trabalho  4-Tributário  5-Empresarial |\n");
                scanf("%d", &pesq_espec);
                getchar();
                switch (pesq_espec){
                    case 1: (especialidade = "Civil"); break;
                    case 2: (especialidade = "Penal"); break;
                    case 3: (especialidade = "Do Trabalho"); break;
                    case 4: (especialidade = "Tributário"); break;
                    case 5: (especialidade = "Empresarial"); break;
                }
                printf("\n%-20s %-20s %-20s %-20s %-15s %-26s %-20s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
                printf("+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if ((strcmp(advogado->especialidade, especialidade) == 0) && (advogado->atividade)){
                        printf("%-20s %-20s %-20s %-20s %-15s %-25s %-20s %-15s %-15s %-15s\n",
                            advogado->cpf,
                            advogado->nome,
                            advogado->carteiraOAB,
                            advogado->especialidade,
                            advogado->dataNasc,
                            advogado->endereco,
                            advogado->email,
                            advogado->telefone,
                            advogado->idProcessoPF,
                            advogado->idProcessoPJ);
                            i++;
                        printf("+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
                    }
                }
                printf("+------------------------------------------------------------------------------------------------------+\n");
                printf("|   Total de advogados com esta especialidade: %d                                                      |\n", i);
                printf("+------------------------------------------------------------------------------------------------------+\n");
                fclose(arq_advogado);
                free(advogado);
            }
        }
    }
}

void listaAdvogado(void){
    system("clear");
    Advogado *lista = gerarLista_adv();
    Advogado *advogado = lista;
    int quantidade = 0;
    Advogado *aux = lista;
    int opcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Listagem Advogado                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                           1 - listar por ordem de cadastro                                  |\n");
    printf("|                           2 - listar por Ordem alfabética                                   |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcao);
    getchar();
    switch(opcao){
        case 1: {
            printf("\n%-20s %-15s %-20s %-25s %-20s %-33s %-25s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
            printf("+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            while(lista != NULL){
                if (lista->atividade){
                    printf("%-20s %-15s %-20s %-25s %-20s %-30s %-27s %-15s %-15s %-15s\n",
                    lista->cpf,
                    lista->nome,
                    lista->carteiraOAB,
                    lista->especialidade,
                    lista->dataNasc,
                    lista->endereco,
                    lista->email,
                    lista->telefone,
                    lista->idProcessoPF,
                    lista->idProcessoPJ);
                }
                lista = lista->prox;
                printf("+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            }
            /* liberar toda a lista ligada */
            while (advogado != NULL) {
                Advogado *tmp = advogado->prox;
                free(advogado);
                advogado = tmp;
            }
            /*free(aux);*/
        }; break;

        case 2: {
            //saber quantos advogados existem na lista.
            while (aux != NULL) {
                if (aux->atividade) {
                    quantidade++;
                }
                aux = aux->prox;
            }

            if (quantidade == 0) {
                printf("Nenhum advogado ativo.\n");
                /* liberar toda a lista ligada antes de sair */
                while (lista != NULL) {
                    Advogado *tmp = lista->prox;
                    free(lista);
                    lista = tmp;
                }
                return;
            }
            Advogado **vetor = (Advogado**) malloc(quantidade * sizeof(Advogado*)); //cria uma lista de "atalhos" ou "links" para os advogados que já estão na memória.
            aux = lista;
            int i = 0;
            while (aux != NULL) {
                if (aux->atividade) {
                    vetor[i] = aux;
                    i++;
                }
                aux = aux->prox;
            }
            qsort(vetor, quantidade, sizeof(Advogado*), compararNomesAdvogado);
            printf("\n%-20s %-15s %-20s %-25s %-20s %-33s %-25s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
            printf("+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            for (int j = 0; j < quantidade; j++) {
                Advogado *adv = vetor[j]; 
                printf("%-20s %-15s %-20s %-25s %-20s %-30s %-27s %-15s %-15s %-15s\n", 
                    adv->cpf, 
                    adv->nome, 
                    adv->carteiraOAB,
                    adv->especialidade,
                    adv->dataNasc,
                    adv->endereco,
                    adv->email,
                    adv->telefone,
                    adv->idProcessoPF,
                    adv->idProcessoPJ
                );
                printf("+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
            }
            free(vetor);
            /* liberar toda a lista ligada */
            while (lista != NULL) {
                Advogado *tmp = lista->prox;
                free(lista);
                lista = tmp;
            }
        }; break;
    }
}
