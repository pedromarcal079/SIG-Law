#include <stdio.h>
#include <stdlib.h>

// Projeto Versão 0.1.0-beta1

int menu(void);
void telaSobre(void);
void telaEquipe(void);
void telaSair(void);

int menuAdvogado(void);
void cadastraAdvogado(void);
void mostraAdvogado(void);
void editaAdvogado(void);
void excluiAdvogado(void);

int menuCliente(void);
void cadastraCliente(void);
void mostraCliente(void);
void editaCliente(void);
void excluiCliente(void);

int menuProcessoPF(void);
void cadastraProcessoPF(void);
void mostraProcessoPF(void);
void editaProcessoPF(void);
void excluiProcessoPF(void);

int menuEmpresa(void);
void cadastraEmpresa(void);
void mostraEmpresa(void);
void editaEmpresa(void);
void excluiEmpresa(void);

int menuProcessoPJ(void);
void cadastraProcessoPJ(void);
void mostraProcessoPJ(void);
void editaProcessoPJ(void);
void excluiProcessoPJ(void);


int main(void) {
    int opcao = 1;
    while (opcao != 0) {
        opcao = menu();
        switch (opcao) {
        case 0:
            telaSair();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 1:
            int advOpcao = 1;
            while (advOpcao != 0) {
                advOpcao = menuAdvogado();
                switch (advOpcao)
                {
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
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            }
            break;
        case 2:
            int cliOpcao = 1;
            while (cliOpcao != 0) {
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
            }
            break;
        case 3:
            int procPfOpcao = 1;
            while (procPfOpcao != 0) {
                procPfOpcao = menuProcessoPF();
                switch (procPfOpcao){
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiProcessoPF();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            } 
            break;
        case 4:
            int empOpcao=1;
            while (empOpcao != 0) {
                empOpcao = menuEmpresa();
                switch (empOpcao){
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            }
            break;
        case 5:
            int procPjOpcao = 1;
            while (procPjOpcao != 0) {
                procPjOpcao = menuProcessoPJ();
                switch (procPjOpcao){
                case 0:
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 1:
                    cadastraProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 2:
                    mostraProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    editaProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 4:
                    excluiProcessoPJ();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                default:
                    printf("Voce digitou uma opcao invalida\n");
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                }
            } 
            break;
        case 6:
            printf("Relatorios\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 7:
            telaSobre();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 8:
            telaEquipe();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        default:
            printf("Voce digitou uma opcao invalida\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        }
    }
    return 0;
}



int menu(void) {

    system("clear");
    int opcao;
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                     |\n");
    printf("|                                                                                                     |\n");                                                                                              
    printf("|     d888888o.    8 8888     ,o888888o.    8 8888                  .8. `8.`888b                 ,8'  |\n");
    printf("|   .`8888:' `88.  8 8888    8888     `88.  8 8888                 .888. `8.`888b               ,8'   |\n");
    printf("|   8.`8888.   Y8  8 8888 ,8 8888       `8. 8 8888                :88888. `8.`888b             ,8'    |\n");
    printf("|   `8.`8888.      8 8888 88 8888           8 8888               . `88888. `8.`888b     .b    ,8'     |\n");
    printf("|    `8.`8888.     8 8888 88 8888           8 8888              .8. `88888. `8.`888b    88b  ,8'      |\n");
    printf("|     `8.`8888.    8 8888 88 8888           8 8888             .8`8. `88888. `8.`888b .`888b,8'       |\n");
    printf("|      `8.`8888.   8 8888 88 8888   8888888 8 8888            .8' `8. `88888. `8.`888b8.`8888'        |\n");       
    printf("|  8b   `8.`8888.  8 8888 `8 8888       .8' 8 8888           .8'   `8. `88888. `8.`888`8.`88'         |\n");
    printf("|  `8b.  ;8.`8888  8 8888    8888     ,88'  8 8888          .888888888. `88888. `8.`8' `8,`'          |\n");
    printf("|   `Y8888P ,88P'  8 8888     `8888888P'    8 888888888888 .8'       `8. `88888. `8.`   `8'           |\n");
    printf("|                                                                                                     |\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                                     |\n");
    printf("|                          1 - Módulo de Advogados                                                    |\n");
    printf("|                          2 - Módulo de Clientes                                                     |\n");
    printf("|                          3 - Módulo de Processos PF                                                 |\n");
    printf("|                          4 - Módulo de Empresas                                                     |\n");
    printf("|                          5 - Módulo de Processos PJ                                                 |\n");
    printf("|                          6 - Relatorios                                                             |\n");
    printf("|                          7 - Sobre                                                                  |\n");
    printf("|                          8 - Equipe                                                                 |\n");
    printf("|                          0 - Sair                                                                   |\n");
    printf("|                                                                                                     |\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcao);
    getchar();
    return opcao;
    
}

void telaSobre(void) {
    
    system("clear");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                         Universidade Federal do Rio Grande do Norte                         |\n");
    printf("|                             Centro de Ensino Superior do Seridó                             |\n");
    printf("|                            Bacharelado em Sistemas de Informacao                            |\n");
    printf("|                               Disciplina DCT1106 - Programacao                              |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Projeto desenvolvido para a disciplina DCT1106 - Programação, como parte da          |\n");
    printf("|         avaliação da matéria. O sistema implementa um modelo de agendamento para            |\n");
    printf("|        escritórios de advocacia, reunindo os principais modulos e funcionalidades           |\n");
    printf("|      estudadas ao longo do curso. O objetivo é aplicar na prática os conhecimentos          |\n");
    printf("|     adquiridos e demonstrar as habilidades desenvolvidas por nós durante a disciplina       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");

}

void telaEquipe(void) {
    
    system("clear");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                         Universidade Federal do Rio Grande do Norte                         |\n");
    printf("|                             Centro de Ensino Superior do Seridó                             |\n");
    printf("|                            Bacharelado em Sistemas de Informacao                            |\n");
    printf("|                               Disciplina DCT1106 - Programacao                              |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|               +++++ Sig-Law: Agendamentos para Escritórios de Advocacia +++++               |\n");
    printf("|                                                                                             |\n");
    printf("|               Este projeto exemplo foi desenvolvido por:                                    |\n");
    printf("|                                                                                             |\n");
    printf("|               Vanesca Héllen dos Santos Silva                                               |\n");
    printf("|               E-mail: vanesca.santos.115@ufrn.edu.br                                        |\n");
    printf("|                                                                                             |\n");
    printf("|               Pedro William Azevedo                                                         |\n");
    printf("|               E-mail: pedro.marcal.079@ufrn.edu.br                                          |\n");
    printf("|                                                                                             |\n");
    printf("|               Git: https://github.com/pedromarcal079/SIG-Law.git                            |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    
}

void telaSair(void) {

    system("clear");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                         Universidade Federal do Rio Grande do Norte                         |\n");
    printf("|                             Centro de Ensino Superior do Seridó                             |\n");
    printf("|                            Bacharelado em Sistemas de Informacao                            |\n");
    printf("|                               Disciplina DCT1106 - Programacao                              |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                  Voce encerrou o programa!                                  |\n");
    printf("|                                         Até Logo!                                           |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    
}

// Advogado

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
    char cpf[15];
    char nome[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Advogado                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do advogado:                                                        |\n");
    printf("|   ===> CPF: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|   ===> Nome: ");
    fgets(nome, sizeof(nome), stdin);
    printf("|                                                                                             |\n");
    printf("|        Advogado cadastrado com sucesso!                                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void mostraAdvogado(void){
    system("clear");
    char cpf[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do advogado: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|                                                                                             |\n");
    printf("|        Nome: Advogado Fulano de Town                                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaAdvogado(void) {
    system("clear");
    char cpf[15];
    char nome[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do advogado: ");
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


void excluiAdvogado(void) {
    system("clear");
    char cpf[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Advogado                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o cpf do advogado: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|                                                                                             |\n");
    printf("|        Advogado excluido com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}

// Cliente

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
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Cliente                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do cliente:                                                         |\n");
    printf("|   ===> CPF: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("|   ===> Nome: ");
    fgets(nome, sizeof(nome), stdin);
    printf("|                                                                                             |\n");
    printf("|        Cliente cadastrado com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
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

// Processos PF 

int menuProcessoPF(void) {
    system("clear");
    int procPfOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Menu de Processos PF                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra processo                                              |\n");
    printf("|                          2 - Mostra processo                                                |\n");
    printf("|                          3 - Edita processo                                                 |\n");
    printf("|                          4 - Exclui processo                                                |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&procPfOpcao);
    getchar();
    return procPfOpcao;
}


void cadastraProcessoPF(void) {
    system("clear");
    char tipo[50];
    char data[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PF                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|   ===> Tipo de processo: ");
    fgets(tipo, sizeof(tipo), stdin);
    printf("|   ===> Data de abertura: ");
    fgets(data, sizeof(data), stdin);
    printf("|                                                                                             |\n");
    printf("|        Processo cadastrado com sucesso!                                                     |\n");
    printf("|        O número desse processo é: 00000                                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void mostraProcessoPF(void) {
    system("clear");
    char procNum[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                  Mostrar Processo PF                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Tipo de processo: Civil                                                              |\n");
    printf("|        Data de abertura: 31/08/2025                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaProcessoPF(void) {
    system("clear");
    char procNum[15];
    char tipo[50];
    char data[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PF                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Digite os novos dados:                                                               |\n");
    printf("|        Tipo: ");
    fgets(tipo, sizeof(tipo), stdin);  
    printf("|        Data: ");
    fgets(data, sizeof(data), stdin);  
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiProcessoPF(void) {
    system("clear");
    char procNum[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                  Excluir Processo PF                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Processo excluido com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}

// Empresa

int menuEmpresa(void) {
    system("clear");
    int opcaoEmpresa;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                      Modulo de Empresa                                      |\n");
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


void cadastraEmpresa(void) {
    system("clear");
    char cnpj[15];
    char nome[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Empresa                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados da empresa:                                                         |\n");
    printf("|   ===> CNPJ: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("|   ===> Nome: ");
    fgets(nome, sizeof(nome), stdin);
    printf("|                                                                                             |\n");
    printf("|        Empresa cadastrada com sucesso!                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void mostraEmpresa(void){
    system("clear");
    char cnpj[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("|                                                                                             |\n");
    printf("|        Nome: Empresa Legal                                                                  |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaEmpresa(void) {
    system("clear");
    char cnpj[15];
    char nome[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("|                                                                                             |\n");
    printf("|        Digite os novos dados:                                                               |\n");
    printf("|        Nome: ");
    fgets(nome, sizeof(nome), stdin);  
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiEmpresa(void) {
    system("clear");
    char cnpj[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o CNPJ da empresa: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("|                                                                                             |\n");
    printf("|        Empresa excluida com sucesso!                                                        |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}

// Processos PJ 

int menuProcessoPJ(void) {
    system("clear");
    int procPjOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Menu de Processos PJ                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra processo                                              |\n");
    printf("|                          2 - Mostra processo                                                |\n");
    printf("|                          3 - Edita processo                                                 |\n");
    printf("|                          4 - Exclui processo                                                |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&procPjOpcao);
    getchar();
    return procPjOpcao;
}


void cadastraProcessoPJ(void) {
    system("clear");
    char tipo[50];
    char data[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Cadastrar Processo PJ                                    |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|        Informe os dados do processo:                                                        |\n");
    printf("|   ===> Tipo de processo: ");
    fgets(tipo, sizeof(tipo), stdin);
    printf("|   ===> Data de abertura: ");
    fgets(data, sizeof(data), stdin);
    printf("|                                                                                             |\n");
    printf("|        Processo cadastrado com sucesso!                                                     |\n");
    printf("|        O número desse processo é: 00000                                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void mostraProcessoPJ(void) {
    system("clear");
    char procNum[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostrar Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Tipo de processo: Civil                                                              |\n");
    printf("|        Data de abertura: 31/08/2025                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void editaProcessoPJ(void) {
    system("clear");
    char procNum[15];
    char tipo[50];
    char data[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Editar Processo PJ                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Digite os novos dados:                                                               |\n");
    printf("|        Tipo: ");
    fgets(tipo, sizeof(tipo), stdin);  
    printf("|        Data: ");
    fgets(data, sizeof(data), stdin);  
    printf("|                                                                                             |\n");
    printf("|        Dados atualizados com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}


void excluiProcessoPJ(void) {
    system("clear");
    char procNum[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Processo PJ                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|   ===> Digite o número do processo: ");
    fgets(procNum, sizeof(procNum), stdin);
    printf("|                                                                                             |\n");
    printf("|        Processo excluido com sucesso!                                                       |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
}
