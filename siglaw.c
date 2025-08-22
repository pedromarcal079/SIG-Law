#include <stdio.h>
#include <stdlib.h>

int menu(void);
void telaSobre(void);
void telaEquipe(void);
void telaSair(void);
int menuAdvogado(void);
void criaAdvogado(void);
void editaAdvogado(void);
void excluiAdvogado(void);
void listaAdvogado(void);

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
            printf("Modulo de Clientes\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 2:
            printf("Modulo de Advogados\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 3:
            printf("Modulo de processos\n");
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 4:
            telaSobre();
            printf("Pressione ENTER ... \n");
            getchar();
            break;
        case 5:
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
    printf("|                          3 - Módulo de Processos                                                    |\n");
    printf("|                          4 - Sobre                                                                  |\n");
    printf("|                          5 - Equipe                                                                 |\n");
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


int menuAdvogado(void) {
    system("clear");
    int opcao;
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Modulo de Advogados                                     |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                               1 - Cria Advogado                                             |\n");
    printf("|                               2 - Edita Advogado                                            |\n");
    printf("|                               3 - Exclui Processo                                           |\n");
    printf("|                               4 - Lista Advogado                                            |\n");
    printf("|                               0 - Sair                                                      |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("===> Digite sua opcao: ");
    scanf("%d",&opcao);
    getchar();
    return opcao;
}


void criaAdvogado(void) {
    system("clear");
    char cpf[15];
    char nome[50];
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                             |\n");
    printf("|                                     Criar Advogado                                          |\n");
    printf("|                                                                                             |\n");
    printf("+---------------------------------------------------------------------------------------------+\n");
    printf("\n");
    printf("===> Digite o cpf do advogado: ");
    fgets(cpf, sizeof(cpf), stdin);
    getchar();
    printf("===> Digite o nome do advogado: ");
    fgets(nome, sizeof(nome), stdin);
    getchar();
}


void editaAdvogado(void) {
    printf("Edita Advogado\n");
}


void excluiAdvogado(void) {
    printf("Exclui Advogado\n");
}


void listaAdvogado(void){
    printf("Lista Advogado\n");
}