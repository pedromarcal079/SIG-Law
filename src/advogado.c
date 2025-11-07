#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "advogado.h"
#include "validacao.h"


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
    printf("|                               5 - Lista Advogados                                           |\n");
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
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Advogado                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do advogado:                                                        |\n");
    do{
        printf("|   ===> CPF: ");
        fgets(advogado->cpf, sizeof(advogado->cpf), stdin);
        tam = strlen(advogado->cpf);
        advogado->cpf[tam-1] = '\0';
    } while(!vali_cpf(advogado->cpf));

    do{
        printf("|   ===> Nome: ");
        fgets(advogado->nome, sizeof(advogado->nome), stdin);
        tam = strlen(advogado->nome);
        advogado->nome[tam-1] = '\0';
    } while(!vali_nome(advogado->nome));

    do{
        printf("|   ===> Carteira OAB: ");
        fgets(advogado->carteiraOAB, sizeof(advogado->carteiraOAB), stdin);
        tam = strlen(advogado->carteiraOAB);
        advogado->carteiraOAB[tam-1] = '\0';
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
        printf("|   ===> Data de Nascimento (dd/mm/aaaa): ");
        fgets(advogado->dataNasc, sizeof(advogado->dataNasc), stdin);
        tam = strlen(advogado->dataNasc);
        advogado->dataNasc[tam-1] = '\0';
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
        printf("|   ===> Telefone: ");
        fgets(advogado->telefone, sizeof(advogado->telefone), stdin);
        tam = strlen(advogado->telefone);
        advogado->telefone[tam-1] = '\0';
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


void relatorioAdvogado(void) {
    system("clear");
    FILE *arq_advogado;
    Advogado *advogado;
    advogado = (Advogado*) malloc(sizeof(Advogado));
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Relatório de Advogados                                   |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    arq_advogado = fopen ("advogado.dat", "rb");
    if (arq_advogado == NULL){
        system("clear");
        printf("+----------------------------------------------+\n");
        printf("|                                              |\n");
        printf("|           Erro ao abrir o arquivo!           |\n");
        printf("|                                              |\n");
        printf("+----------------------------------------------+\n");
        return;
    }
    while (fread(advogado, sizeof(Advogado), 1, arq_advogado) == 1) {
        if (advogado->atividade){
            printf("|CPF: %s / ", advogado->cpf);
            printf("Nome: %s / ", advogado->nome);
            printf("Carteira OAB: %s / ", advogado->carteiraOAB);
            printf("Especialidade: %s / ", advogado->especialidade);
            printf("Data de Nascimento: %s / ", advogado->dataNasc);
            printf("Endereço: %s / ", advogado->endereco);
            printf("Email: %s / ", advogado->email);
            printf("Telefone: %s\n", advogado->telefone);
            printf("+---------------------------------------------------------------------------------------------+\n");
        }
    }
    fclose(arq_advogado);
    free(advogado);
}