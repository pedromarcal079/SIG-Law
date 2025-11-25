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
    printf("|                               5 - Lixeira Advogado                                         |\n");
    printf("|                               6 - Lista Advogados                                           |\n");
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
    int tam, espec;
    FILE *arq_advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
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

    printf("|   ===> Endereço: ");
    fgets(advogado->endereco, sizeof(advogado->endereco), stdin);
    tam = strlen(advogado->endereco);
    advogado->endereco[tam-1] = '\0';

    printf("|   ===> Email: ");
    fgets(advogado->email, sizeof(advogado->email), stdin);
    tam = strlen(advogado->email);
    advogado->email[tam-1] = '\0';

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
    int tam;
    int encontrado = 0;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|   ===> Digite o CPF do advogado: ");
    fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
    tam = strlen(pesquisar_cpf);
    pesquisar_cpf[tam-1] = '\0';
    arq_advogado = fopen("advogado.dat", "rb");
    if (arq_advogado == NULL) {
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
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
            return;
        }
    }
    fclose(arq_advogado);
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
    int tam, dado;
    int encontrado = 0;
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

    arq_advogado = fopen("advogado.dat", "rb");
    temp_advogado = fopen("temp_advogado.dat", "wb");
    if (arq_advogado == NULL || temp_advogado == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
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
                    case 1: strcpy(advogado->cpf, edicao); break;
                    case 2: strcpy(advogado->nome, edicao); break;
                    case 3: strcpy(advogado->carteiraOAB, edicao); break;
                    case 4: strcpy(advogado->especialidade, edicao); break;
                    case 5: strcpy(advogado->dataNasc, edicao); break;
                    case 6: strcpy(advogado->endereco, edicao); break;
                    case 7: strcpy(advogado->email, edicao); break;
                    case 8: strcpy(advogado->telefone, edicao); break;
                }
            }
        }
        fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
    }
    fclose(arq_advogado);
    fclose(temp_advogado);

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
    FILE *temp_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    char pesquisar_cpf[15];
    int tam, confi;
    int encontrado = 0;
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

    arq_advogado = fopen("advogado.dat", "rb");
    temp_advogado = fopen("temp_advogado.dat","wb");

    while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
        if (strcmp(advogado->cpf, pesquisar_cpf) == 0){
            fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
        } else {
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
                fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
                printf("|                                                                                             |\n");
                printf("|        Advogado excluido com sucesso!                                                       |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
            } else if (confi == 2) {
                fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
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
                fclose(temp_advogado);
                fclose(arq_advogado);
                remove("temp_advogado.dat");
                return;
            }
        }
    }
    fclose(arq_advogado);
    fclose(temp_advogado);
    
    if (!encontrado){
        remove("temp_advogado.dat");
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Advogado não encontrado!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n"); 
    } else {
        remove("advogado.dat");
        rename("temp_advogado.dat", "advogado.dat");
    }
    
}


void lixeiraAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    FILE *temp_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    int opcao;
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
    arq_advogado = fopen("advogado.dat", "rb");
    temp_advogado = fopen("temp_advogado.dat","wb");
    if (opcao == 1) {
        printf("Digite o CPF do advogado que deseja restaurar: ");
        fgets(pesquisar_cpf, sizeof(pesquisar_cpf), stdin);
        int tam = strlen(pesquisar_cpf);
        pesquisar_cpf[tam-1] = '\0';
        while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
            if ((advogado->atividade == 0) && (strcmp(advogado->cpf, pesquisar_cpf) == 0)){
                advogado->atividade = 1;
                fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
                printf("|                                                                                             |\n");
                printf("|        Advogado restaurado com sucesso!                                                     |\n");
                printf("|                                                                                             |\n");
                printf("+---------------------------------------------------------------------------------------------+\n");
                fclose(temp_advogado);
                fclose(arq_advogado);
                remove("advogado.dat");
                rename("temp_advogado.dat", "advogado.dat");
                return;
            } else {
                system("clear");
                printf("+-------------------------------------------------------+\n");
                printf("|                                                       |\n");
                printf("|  Não há advogado com esse CPF que esteja na lixeira!  |\n");
                printf("|                                                       |\n");
                printf("+-------------------------------------------------------+\n");
                fclose(temp_advogado);
                fclose(arq_advogado);
                remove("temp_advogado.dat");
                return;
            }
        }
    } 
    else if (opcao == 2) {
        while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
            if (advogado->atividade == 1){
                fwrite(advogado, sizeof(Advogado), 1, temp_advogado);
            }
        }
        fclose(arq_advogado);
        fclose(temp_advogado);
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
        fclose(temp_advogado);
        fclose(arq_advogado);
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
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Relatório de Advogados                                   |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("| gostaria de filtrar algum dado? (1- Sim / 2- Não):                                          |\n");
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
            fclose(arq_advogado);
            free(advogado);
            return;
        }
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
        printf("+------------------------------------------------------------------------------------------------------+\n");
        while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1){
            if (advogado->atividade){
                printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", advogado->cpf, advogado->nome, advogado->carteiraOAB, advogado->especialidade, advogado->dataNasc, advogado->endereco, advogado->email, advogado->telefone, advogado->idProcessoPF, advogado->idProcessoPJ);
            }
            printf("+------------------------------------------------------------------------------------------------------+\n");
        }
        fclose(arq_advogado);
        free(advogado);
    }
    else if (opcao == 1){
        arq_advogado = fopen ("advogado.dat", "rb");
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
                printf("|  ===> Digite o nome que você deseja filtrar:             |\n");
                fgets(pesq_nome, sizeof(pesq_nome), stdin);
                int tam = strlen(pesq_nome);
                pesq_nome[tam-1] = '\0';
                printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
                printf("+------------------------------------------------------------------------------------------------------+\n");
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if ((strcmp(advogado->nome, pesq_nome) == 0) && (advogado->atividade)){
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", advogado->cpf, advogado->nome, advogado->carteiraOAB, advogado->especialidade, advogado->dataNasc, advogado->endereco, advogado->email, advogado->telefone, advogado->idProcessoPF, advogado->idProcessoPJ);
                    }
                    printf("+------------------------------------------------------------------------------------------------------+\n");
                }
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
                printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "CPF", "Nome", "Carteira OAB", "Especialidade", "Data Nasc.","Endereço", "Email", "Telefone", "ID PPF", "ID PPJ");
                printf("+------------------------------------------------------------------------------------------------------+\n");
                while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
                    if ((strcmp(advogado->especialidade, especialidade) == 0) && (advogado->atividade)){
                        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", advogado->cpf, advogado->nome, advogado->carteiraOAB, advogado->especialidade, advogado->dataNasc, advogado->endereco, advogado->email, advogado->telefone, advogado->idProcessoPF, advogado->idProcessoPJ);
                    }
                    printf("+------------------------------------------------------------------------------------------------------+\n");
                }
                fclose(arq_advogado);
                free(advogado);
            }
        }
    }
}