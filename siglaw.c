#include <stdio.h>
#include <stdlib.h>

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
    return opcao;
    
}



int main() {
    int opcao = 1;
    while (opcao != 0) {
        opcao = menu();
        switch (opcao) {
        case 0:
            printf("Voce saiu do programa! Ate logo!\n");
            printf("Pressione ENTER ... \n");
            getchar();
            getchar();
            break;
        case 1:
            printf("Modulo de Clientes\n");
            printf("Pressione ENTER ... \n");
            getchar();
            getchar();
            break;
        case 2:
            printf("Modulo de Advogados\n");
            printf("Pressione ENTER ... \n");
            getchar();
            getchar();
            break;
        case 3:
            printf("Modulo de processos\n");
            printf("Pressione ENTER ... \n");
            getchar();
            getchar();
            break;
        default:
            printf("Voce digitou uma opcao invalida\n");
            printf("Pressione ENTER ... \n");
            getchar();
            getchar();
            break;
        }
    }
    return 0;
}