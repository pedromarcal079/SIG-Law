#include <stdio.h>
#include <stdlib.h>

int menu(void);
void telaSobre(void);
void telaEquipe(void);
void telaSair(void);

int menuAdvogado(void);
void cadastraAdvogado(void);
void editaAdvogado(void);
void excluiAdvogado(void);
void mostraAdvogado(void);

int menuCliente(void);
void cadastraCliente(void);
void editaCliente(void);
void excluiCliente(void);
void mostraCliente(void);

int menuProcessosPF(void);

int menuEmpresa(void);
void cadastraEmpresa(void);
void editaEmpresa(void);
void excluiEmpresa(void);
void mostraEmpresa(void);


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
                    editaCliente();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    mostraCliente();
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
        case 2:
            int opcaoAdvogado=1;
            while (opcaoAdvogado != 0) {
                opcaoAdvogado = menuAdvogado();
                switch (opcaoAdvogado)
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
                    editaAdvogado();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    mostraAdvogado();
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
        case 3:
            menuProcessosPF();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 4:
            int opcaoEmpresa=1;
            while (opcaoEmpresa != 0) {
                opcaoEmpresa = menuEmpresa();
                switch (opcaoEmpresa){
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
                    editaEmpresa();
                    printf("Pressione ENTER ... \n");
                    getchar();
                    break;
                case 3:
                    mostraEmpresa();
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
            printf("Modulo de processos PJ\n");
            printf("Pressione ENTER ... \n");
            getchar();
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
    printf("|                          1 - Módulo de Clientes                                                     |\n");
    printf("|                          2 - Módulo de Advogados                                                    |\n");
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
    printf("|                               2 - Edita Advogado                                            |\n");
    printf("|                               3 - Mostra Advogado                                           |\n");
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
    printf("|                          2 - Edita cliente                                                  |\n");
    printf("|                          3 - Mostra cliente                                                 |\n");
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
    char nome[30];
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
    char nome[30];
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

int menuProcessosPF(void) {
    system("clear");
    int proPfOpcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Menu de Processos PF                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra processo                                              |\n");
    printf("|                          2 - Edita processo                                                 |\n");
    printf("|                          3 - Mostra processo                                                |\n");
    printf("|                          4 - Exclui processo                                                |\n");
    printf("|                          0 - Voltar                                                         |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&proPfOpcao);
    getchar();
    // return proPfOpcao;
}

// Empresa

int menuEmpresa(void) {
    system("clear");
    int opcaoEmpresa;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Modulo de Empresa                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                          1 - Cadastra empresa                                               |\n");
    printf("|                          2 - Edita empresa                                                  |\n");
    printf("|                          3 - Mostra empresa                                                 |\n");
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
    char nome[30];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                       Cadastrar Empresa                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("\n");
    printf("===> Digite o cnpj da empresa: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("===> Digite o nome da empresa: ");
    fgets(nome, sizeof(nome), stdin);
}


void editaEmpresa(void) {
    system("clear");
    char cnpj[15];
    char nome[30];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Editar Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("\n");
    printf("===> Digite o cnpj da empresa: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("===> Digite o novo nome da empresa: ");
    fgets(nome, sizeof(nome), stdin);
}


void mostraEmpresa(void){
    system("clear");
    char cnpj[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Mostra Empresa                                           |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("\n");
    printf("===> Digite o cnpj da empresa que deseja pesquisar: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("\nNome: Empresa Legal\n");
}


void excluiEmpresa(void) {
    system("clear");
    char cnpj[15];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                    Excluir Empresa                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("\n");
    printf("===> Digite o cnpj da empresa que deseja excluir: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    printf("\n===> Empresa excluida com sucesso!\n");
}
